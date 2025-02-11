#include "Global.h"
#include "Projectile_Extend.h"
#include "CustomWeapons.h"
#include "CrewSpawn.h"
#include "ShipManager_Extend.h"
#include "Room_Extend.h"
#include <boost/lexical_cast.hpp>

CustomDamage* CustomDamageManager::currentWeaponDmg = nullptr;
Projectile* CustomDamageManager::currentProjectile = nullptr;

CustomDamageDefinition CustomDamageDefinition::defaultDef = CustomDamageDefinition();
std::vector<CustomDamageDefinition*> CustomDamageDefinition::customDamageDefs = {&CustomDamageDefinition::defaultDef};

HOOK_METHOD(ShipManager, DamageArea, (Pointf location, Damage dmg, bool forceHit) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::DamageArea -> Begin (CustomDamage.cpp)\n")

    // push everything to the lua stack: ShipManager, Projectile, location, Damage, forceHit, shipFriendlyFire
    auto context = Global::GetInstance()->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    CustomDamageManager::lua_PushCurrentProjectile(context);
    SWIG_NewPointerObj(context->GetLua(), &location, context->getLibScript()->types.pPointf, 0);
    SWIG_NewPointerObj(context->GetLua(), &dmg, context->getLibScript()->types.pDamage, 0);
    lua_pushinteger(context->GetLua(), forceHit ? Evasion::HIT : Evasion::NONE);
    lua_pushboolean(context->GetLua(), shipFriendlyFire); // if false then do not apply room/system effects on friendly ship, damage crew and apply other effects only

    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::DAMAGE_AREA, 6, 2);

    int iForceHit = Evasion::NONE;
    if (lua_isinteger(context->GetLua(), -2))
    {
        iForceHit = lua_tointeger(context->GetLua(), -2);
    }
    shipFriendlyFire = lua_toboolean(context->GetLua(), -1);

    // process preempt and iForceHit
    if (preempt)
    {
        lua_pop(context->GetLua(), 6);

        switch (iForceHit)
        {
        case Evasion::HIT:
            return true;
        case Evasion::MISS:
            return false;
        default:
            return GetDodged();
        }
    }
    else if (iForceHit == Evasion::MISS)
    {
        lua_pop(context->GetLua(), 6);

        // reproduce the miss code here
        if (!bJumping)
        {
            damMessages.push_back(new DamageMessage(1.f, location, DamageMessage::MISS));
        }
        if (IsCloaked())
        {
            damageCloaked += dmg.iDamage;
        }

        return false;
    }
    else
    {
        forceHit = iForceHit == Evasion::HIT;
    }

    bool shipFriendlyFireLocal = shipFriendlyFire;
    lua_pop(context->GetLua(), 2); // pops forceHit and shipFriendlyFire

    bool ret = super(location, dmg, forceHit);

    if (ret)
    {
        auto custom = CustomDamageManager::currentWeaponDmg;

        if (custom && custom->sourceShipId != -1)
        {
            int rng = random32() % 10;

            if (rng < custom->def->crewSpawnChance)
            {
                for (CrewSpawn *i : custom->def->crewSpawns)
                {
                    CrewSpawn::SpawnCrew(i, this, custom->sourceShipId != iShipId, location);
                }
            }

            int room = ship.GetSelectedRoomId(location.x, location.y, true);

            if (room > -1)
            {
                rng = random32() % 10;
                if (rng < custom->def->roomStatBoostChance)
                {
                    for (auto statBoostDef : custom->def->roomStatBoosts)
                    {
                        SM_EX(this)->CreateRoomStatBoost(*statBoostDef, room, 1, custom->sourceShipId);
                    }
                }

                rng = random32() % 10;
                if (rng < custom->def->erosionChance)
                {
                    auto ex = RM_EX(ship.vRoomList[room]);
                    ex->StartErosion(custom->def->erosionEffect);
                }
            }
        }

        lua_pushboolean(context->GetLua(), shipFriendlyFireLocal);

        // stack: ShipManager, Projectile, location, Damage, shipFriendlyFireLocal
        preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::DAMAGE_AREA_HIT, 5, 0);

        lua_pop(context->GetLua(), 5);

        if (preempt) return false; // pretend the projectile missed, since we don't really have something else pre-empt can do
    }
    else
    {
        lua_pop(context->GetLua(), 4);
    }

    return ret;
}

HOOK_METHOD(ShipManager, DamageBeam, (Pointf location1, Pointf location2, Damage dmg) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::DamageBeam -> Begin (CustomDamage.cpp)\n")

    int beamHitType;

    Point grid1 = ShipGraph::TranslateToGrid(location1.x, location1.y);
    Point grid2 = ShipGraph::TranslateToGrid(location2.x, location2.y);
    int room1 = ship.GetSelectedRoomId(location1.x, location1.y, true);
    int room2 = ship.GetSelectedRoomId(location2.x, location2.y, true);

    bool realNewTile = grid1 != grid2;
    if (room1 != room2)
    {
        beamHitType = BeamHit::NEW_ROOM;
    }
    else if (realNewTile)
    {
        beamHitType = BeamHit::NEW_TILE;
    }
    else
    {
        beamHitType = BeamHit::SAME_TILE;
    }
    int oldBeamHitType = beamHitType;

    // push everything to the lua stack: ShipManager, Projectile, location, Damage, realNewTile, beamHitType
    auto context = Global::GetInstance()->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    CustomDamageManager::lua_PushCurrentProjectile(context);
    SWIG_NewPointerObj(context->GetLua(), &location1, context->getLibScript()->types.pPointf, 0);
    SWIG_NewPointerObj(context->GetLua(), &dmg, context->getLibScript()->types.pDamage, 0);
    lua_pushboolean(context->GetLua(), realNewTile);
    lua_pushinteger(context->GetLua(), beamHitType);

    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::DAMAGE_BEAM, 6, 1);

    if (lua_isinteger(context->GetLua(), -1))
    {
        beamHitType = lua_tointeger(context->GetLua(), -1);
    }

    // process preempt and beamHitType
    if (preempt)
    {
        lua_pop(context->GetLua(), 6);

        switch (beamHitType)
        {
        case BeamHit::NEW_ROOM:
            return true;
        default:
            return false;
        }
    }
    else if (beamHitType != oldBeamHitType)
    {
        switch (beamHitType)
        {
        case BeamHit::NEW_ROOM:
            location2 = {-2147483648.f, -2147483648.f};
            break;
        case BeamHit::NEW_TILE:
            if (room1 > -1)
            {
                Room *room = ship.vRoomList[room1];
                Point dummyLocation = {grid1.x*35, grid1.y*35};
                if (dummyLocation.x == room->rect.x && dummyLocation.y == room->rect.y) // location1 is first tile
                {
                    if (room->rect.w > 35) // find a tile to the right
                    {
                        location2 = {dummyLocation.x+52.f, dummyLocation.y+17.f};
                    }
                    else if (room->rect.h > 35) // find a tile below
                    {
                        location2 = {dummyLocation.x+17.f, dummyLocation.y+52.f};
                    }
                    else // 1 tile room, fall back to SAME_TILE
                    {
                        location2 = location1;
                    }
                }
                else // location1 is not first tile, set location2 to first tile
                {
                    location2 = {dummyLocation.x+17.f, dummyLocation.y+17.f};
                }
            }
            break;
        case BeamHit::SAME_TILE:
            location2 = location1;
            break;
        default:
            beamHitType = oldBeamHitType;
            break;
        }
    }

    lua_pop(context->GetLua(), 6);

    bool ret = super(location1, location2, dmg);

    auto custom = CustomDamageManager::currentWeaponDmg;

    if (custom)
    {
        if (beamHitType != BeamHit::SAME_TILE)
        {
            if (custom->sourceShipId != -1 && custom->def->crewSpawnChance > 0)
            {
                int rng = random32() % 10;

                if (rng < custom->def->crewSpawnChance)
                {
                    Pointf spawnLoc = {grid1.x * 35.f + 17.5f, grid1.y * 35.f + 17.5f};

                    for (CrewSpawn *i : custom->def->crewSpawns)
                    {
                        CrewSpawn::SpawnCrew(i, this, custom->sourceShipId != iShipId, spawnLoc, true);
                    }
                }
            }
        }

        if (room1 > -1 && beamHitType == BeamHit::NEW_ROOM)
        {
            int rng = random32() % 10;

            if (rng < custom->def->roomStatBoostChance)
            {
                for (auto statBoostDef : custom->def->roomStatBoosts)
                {
                    SM_EX(this)->CreateRoomStatBoost(*statBoostDef, room1, 1, custom->sourceShipId);
                }
            }

            rng = random32() % 10;
            if (rng < custom->def->erosionChance)
            {
                auto ex = RM_EX(ship.vRoomList[room1]);
                ex->StartErosion(custom->def->erosionEffect);
            }
        }
    }

    return ret;
}

HOOK_METHOD(ShipManager, GetDodgeFactor, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetDodgeFactor -> Begin (CustomDamage.cpp)\n")
    int ret = super();

    if (CustomDamageManager::currentWeaponDmg != nullptr)
    {
        ret -= CustomDamageManager::currentWeaponDmg->accuracyMod;
    }

    return ret;
}

HOOK_METHOD_PRIORITY(ShipManager, DamageSystem, -100, (int roomId, Damage dmg) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::DamageSystem -> Begin (CustomDamage.cpp)\n")

    // push everything to the lua stack: ShipManager, Projectile, room ID, Damage
    auto context = Global::GetInstance()->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    CustomDamageManager::lua_PushCurrentProjectile(context);
    lua_pushinteger(context->GetLua(), roomId);
    SWIG_NewPointerObj(context->GetLua(), &dmg, context->getLibScript()->types.pDamage, 0);

    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::DAMAGE_SYSTEM, 4, 0);

    if (!preempt)
    {
        // noSysDamage modifier
        if (CustomDamageManager::currentWeaponDmg != nullptr && CustomDamageManager::currentWeaponDmg->def->noSysDamage)
        {
            dmg.iSystemDamage -= dmg.iDamage;
        }

        super(roomId, dmg);
    }

    lua_pop(context->GetLua(), 4);
}

HOOK_METHOD_PRIORITY(ShipSystem, AddDamage, -100, (int amount) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipSystem::AddDamage -> Begin (CustomDamage.cpp)\n")

    // ShipSystem::AddDamage occurs after all things that could prevent damage (resists, etc.), but it is also used when loading the game, so skip callbacks in that case
    if (loadingGame) return super(amount);

    // push everything to the lua stack: ShipSystem, Projectile, amount
    auto context = Global::GetInstance()->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->GetShipSystemType(iSystemType), 0);
    CustomDamageManager::lua_PushCurrentProjectile(context);
    lua_pushinteger(context->GetLua(), amount);

    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SYSTEM_ADD_DAMAGE, 3, 1);

    if (!preempt)
    {
        if (lua_isinteger(context->GetLua(), -1))
        {
            amount = lua_tointeger(context->GetLua(), -1);
        }

        super(amount);
    }

    lua_pop(context->GetLua(), 3);
}

HOOK_METHOD_PRIORITY(ShipManager, DamageCrew, -100, (CrewMember *crew, Damage dmg) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::DamageCrew -> Begin (CustomDamage.cpp)\n")
    if (CustomDamageManager::currentWeaponDmg != nullptr)
    {
        if (CustomDamageManager::currentWeaponDmg->def->noPersDamage)
        {
            dmg.iPersDamage -= dmg.iDamage;
        }

        int rng = random32() % 10;

        if (rng < CustomDamageManager::currentWeaponDmg->def->statBoostChance)
        {
            for (auto statBoostDef : CustomDamageManager::currentWeaponDmg->def->statBoosts)
            {
                StatBoost statBoost(statBoostDef);
                statBoost.sourceShipId = CustomDamageManager::currentWeaponDmg->sourceShipId;
                StatBoostManager::GetInstance()->CreateTimedAugmentBoost(statBoost, crew);
            }
        }
    }

    return super(crew, dmg);
}

HOOK_METHOD(ProjectileFactory, Update, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::Update -> Begin (CustomDamage.cpp)\n")
    // This only works if every weapon has a definition, if that changes then replace with the commented code below.
    CustomWeaponManager::currentWeapon = CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name);
    //CustomDamageManager::currentWeaponDmg = &CustomWeaponManager::currentWeapon->customDamage;

    //auto def = CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name)
    //if (def) CustomDamageManager::currentWeaponDmg = &def->customDamage;

    super();

    CustomWeaponManager::currentWeapon = nullptr;
    //CustomDamageManager::currentWeaponDmg = nullptr;
}

HOOK_METHOD(ShipManager, CollisionMoving, (Pointf start, Pointf finish, Damage damage, bool raytrace) -> CollisionResponse)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CollisionMoving -> Begin (CustomDamage.cpp)\n")
    if (CustomDamageManager::currentWeaponDmg && CustomDamageManager::currentWeaponDmg->def->ionBeamFix && CustomDamageManager::currentProjectile)
    {
        BeamWeapon *proj = (BeamWeapon*) CustomDamageManager::currentProjectile; // ionBeamFix should only be used for beams
        if (proj->bDamageSuperShield)
        {
            return super(start, finish, damage, raytrace);
        }
        damage.iIonDamage = 0;
    }
    return super(start, finish, damage, raytrace);
}

HOOK_STATIC(ProjectileFactory, LoadProjectile, (int fh) -> Projectile*)
{
    LOG_HOOK("HOOK_STATIC -> ProjectileFactory::LoadProjectile -> Begin (CustomDamage.cpp)\n")
    Projectile *ret = super(fh);

    if (!ret)
    {
        hs_log_file("ProjectileFactory::LoadProjectile failed!");
        return ret;
    }

    Projectile_Extend *ex = PR_EX(ret);

    ex->customDamage.sourceShipId = ret->ownerId;

    ex->name = FileHelper::readString(fh);

    ex->customDamage.def = CustomDamageDefinition::customDamageDefs.at(FileHelper::readInteger(fh));
    ex->customDamage.accuracyMod = FileHelper::readInteger(fh);
    ex->customDamage.droneAccuracyMod = FileHelper::readInteger(fh);

    int n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        ex->missedDrones.push_back(FileHelper::readInteger(fh));
    }

    return ret;
}

HOOK_STATIC(ProjectileFactory, SaveProjectile, (Projectile *p, int fh) -> void)
{
    LOG_HOOK("HOOK_STATIC -> ProjectileFactory::SaveProjectile -> Begin (CustomDamage.cpp)\n")
    super(p, fh);

    Projectile_Extend *ex = PR_EX(p);

    FileHelper::writeString(fh, ex->name);

    FileHelper::writeInt(fh, ex->customDamage.def->idx);
    FileHelper::writeInt(fh, ex->customDamage.accuracyMod);
    FileHelper::writeInt(fh, ex->customDamage.droneAccuracyMod);

    FileHelper::writeInt(fh, ex->missedDrones.size());
    for (int i : ex->missedDrones)
    {
        FileHelper::writeInt(fh, i);
    }
}

HOOK_METHOD_PRIORITY(ProjectileFactory, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ProjectileFactory::SaveState -> Begin (CustomDamage.cpp)\n")

    // Reverse engineered Vanilla code
    FileHelper::writeFloat(fd, cooldown.first);
    FileHelper::writeFloat(fd, cooldown.second);
    FileHelper::writeFloat(fd, subCooldown.first);
    FileHelper::writeFloat(fd, subCooldown.second);
    FileHelper::writeInt(fd, boostLevel);
    FileHelper::writeInt(fd, chargeLevel);
    FileHelper::writeInt(fd, targets.size());
    for (auto pointf : targets)
    {
        FileHelper::writeInt(fd, (int)(pointf.x));
        FileHelper::writeInt(fd, (int)(pointf.y));
    }
    FileHelper::writeInt(fd, lastTargets.size());
    for (auto pointf : lastTargets)
    {
        FileHelper::writeInt(fd, (int)(pointf.x));
        FileHelper::writeInt(fd, (int)(pointf.y));
    }
    FileHelper::writeInt(fd, (unsigned int)autoFiring);
    FileHelper::writeInt(fd, (unsigned int)fireWhenReady);
    FileHelper::writeInt(fd, targetId);
    weaponVisual.SaveState(fd);
    FileHelper::writeInt(fd, lastProjectileId);
    FileHelper::writeInt(fd, queuedProjectiles.size());
    for (auto *projectile : queuedProjectiles)
    {
        /* what the vanilla code does here is exactly what ProjectileFactory::SaveProjectile does

        vanilla code start

        // int8_t projectileType = projectile->GetType();
        // FileHelper::writeInt(fd, projectileType);
        // if (projectileType != 0)
        // {
        //     projectile->SaveProjectile(fd);
        // }

        vanilla code end

        */
        ProjectileFactory::SaveProjectile(projectile, fd);
    }
}

HOOK_METHOD(Projectile, Initialize, (WeaponBlueprint& bp) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Projectile::Initialize -> Begin (CustomDamage.cpp)\n")
    super(bp);

    Projectile_Extend *ex = PR_EX(this);
    ex->name = bp.name;

    auto customWeapon = CustomWeaponManager::instance->GetWeaponDefinition(bp.name);
    if (customWeapon)
    {
        CustomDamage &customDamage = ex->customDamage;
        customDamage.def = customWeapon->customDamage;
        customDamage.accuracyMod = customWeapon->customDamage->accuracyMod;
        customDamage.droneAccuracyMod = customWeapon->customDamage->droneAccuracyMod;
    }

    // Callback with Projectile and WeaponBlueprint
    auto context = Global::GetInstance()->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pProjectile[this->GetType()], 0);
    SWIG_NewPointerObj(context->GetLua(), &bp, context->getLibScript()->types.pWeaponBlueprint, 0);
    context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_INITIALIZE, 2, 0);
    lua_pop(context->GetLua(), 2);
}

HOOK_METHOD(SpaceManager, UpdateProjectile, (Projectile *projectile) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::UpdateProjectile -> Begin (CustomDamage.cpp)\n")
    // set temporary values (needed in case lua calls this from somewhere arbitrary)
    CustomDamage *currentWeaponDmg = CustomDamageManager::currentWeaponDmg;
    Projectile *currentProjectile = CustomDamageManager::currentProjectile;

    // set the custom projectile damage pointers
    CustomDamageManager::currentWeaponDmg = &PR_EX(projectile)->customDamage;
    CustomDamageManager::currentWeaponDmg->sourceShipId = projectile->ownerId;
    CustomDamageManager::currentProjectile = projectile;

    // push projectile onto lua stack
    auto context = Global::GetInstance()->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), projectile, context->getLibScript()->types.pProjectile[projectile->GetType()], 0);

    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_PRE, 1, 0);

    // Primary method for updating projectile
    // First calls the projectile's Update method to update the projectile location
    // Then loop over all potential collideable objects (both ships, all spacedrones, all projectiles), calling the projectile's CollisionCheck method against that object
    if (!preempt) super(projectile);

    // Push pre-empt onto the stack
    lua_pushboolean(context->GetLua(), preempt);

    context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_POST, 2, 0);

    // pop projectile and pre-empt from the stack
    lua_pop(context->GetLua(), 2);

    // revert to temporary values
    CustomDamageManager::currentWeaponDmg = currentWeaponDmg;
    CustomDamageManager::currentProjectile = currentProjectile;
}

void Projectile::HS_OnUpdate()
{
    // set temporary values
    CustomDamage *currentWeaponDmg = CustomDamageManager::currentWeaponDmg;
    Projectile *currentProjectile = CustomDamageManager::currentProjectile;

    // set the custom projectile damage pointers
    CustomDamageManager::currentWeaponDmg = &PR_EX(this)->customDamage;
    CustomDamageManager::currentWeaponDmg->sourceShipId = this->ownerId;
    CustomDamageManager::currentProjectile = this;

    // push projectile onto lua stack
    auto context = Global::GetInstance()->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pProjectile[this->GetType()], 0);

    // call the real OnUpdate (will call the virtual method)
    this->OnUpdate();

    // pop projectile from stack
    lua_pop(context->GetLua(), 1);

    // revert to temporary values
    CustomDamageManager::currentWeaponDmg = currentWeaponDmg;
    CustomDamageManager::currentProjectile = currentProjectile;
}

HOOK_METHOD(Projectile, OnUpdate, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Projectile::OnUpdate -> Begin (CustomDamage.cpp)\n")
    // when this method is called, the projectile should already be on the Lua stack

    auto context = Global::GetInstance()->getLuaContext();
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_UPDATE_PRE, 1, 0);

    if (!preempt) super();

    lua_pushboolean(context->GetLua(), preempt);
    context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_UPDATE_POST, 2, 0);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(LaserBlast, OnUpdate, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> LaserBlast::OnUpdate -> Begin (CustomDamage.cpp)\n")
    // when this method is called, the projectile should already be on the Lua stack

    auto context = Global::GetInstance()->getLuaContext();
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_UPDATE_PRE, 1, 0);

    if (!preempt) super();

    lua_pushboolean(context->GetLua(), preempt);
    context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_UPDATE_POST, 2, 0);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(Asteroid, OnUpdate, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Asteroid::OnUpdate -> Begin (CustomDamage.cpp)\n")
    // when this method is called, the projectile should already be on the Lua stack

    auto context = Global::GetInstance()->getLuaContext();
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_UPDATE_PRE, 1, 0);

    if (!preempt) super();

    lua_pushboolean(context->GetLua(), preempt);
    context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_UPDATE_POST, 2, 0);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(BombProjectile, OnUpdate, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> BombProjectile::OnUpdate -> Begin (CustomDamage.cpp)\n")
    // when this method is called, the projectile should already be on the Lua stack

    auto context = Global::GetInstance()->getLuaContext();
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_UPDATE_PRE, 1, 0);

    if (!preempt) super();

    lua_pushboolean(context->GetLua(), preempt);
    context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_UPDATE_POST, 2, 0);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(BeamWeapon, OnUpdate, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> BeamWeapon::OnUpdate -> Begin (CustomDamage.cpp)\n")
    // when this method is called, the projectile should already be on the Lua stack

    auto context = Global::GetInstance()->getLuaContext();
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_UPDATE_PRE, 1, 0);

    if (!preempt) super();

    lua_pushboolean(context->GetLua(), preempt);
    context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_UPDATE_POST, 2, 0);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(PDSFire, OnUpdate, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> PDSFire::OnUpdate -> Begin (CustomDamage.cpp)\n")
    // when this method is called, the projectile should already be on the Lua stack

    auto context = Global::GetInstance()->getLuaContext();
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_UPDATE_PRE, 1, 0);

    if (!preempt) super();

    lua_pushboolean(context->GetLua(), preempt);
    context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_UPDATE_POST, 2, 0);
    lua_pop(context->GetLua(), 1);
}

// Collision check performs the following actions:
// 1. Checks if the projectile should be able to collide with the target object.
// 2. Calls CollisionMoving using the last and current position, damage, and raytrace flag.
// 3. Perform actions based on the collision response (inflict damage to the ship, play sounds, kill projectile, etc.).
// Note: The actual check of hitting the target point is in CollisionCheck itself, not CollisionMoving

// CollisionMoving performs the following actions:
// 1. Determines the collision response.
// 2. Other effects occur (destroy a hit projectile, stun or destroy a drone, shield system damage through shield (ion damage/stun)).
// 3. Misses against a cloaked ship will have damage tallied for the cloaking achievement.
// 4. When against the ship, CollisionShield is used for checking the shield collision. Shield damage also happens in this method.
// CollisionResponse has a type (0 = no collision, 1 = solid collision, 2 = shield collision, 3 = missed ship), point (where the collision happened), damage (how many shields, determine whether to pierce) and superDamage (for zoltan shield)

void Projectile::HS_CollisionCheck(Collideable *other)
{
    // set temporary values
    CustomDamage *currentWeaponDmg = CustomDamageManager::currentWeaponDmg;
    Projectile *currentProjectile = CustomDamageManager::currentProjectile;

    // set the custom projectile damage pointers
    CustomDamageManager::currentWeaponDmg = &PR_EX(this)->customDamage;
    CustomDamageManager::currentWeaponDmg->sourceShipId = this->ownerId;
    CustomDamageManager::currentProjectile = this;

    // call the real CollisionCheck (will call the virtual method)
    this->CollisionCheck(other);

    // revert to temporary values
    CustomDamageManager::currentWeaponDmg = currentWeaponDmg;
    CustomDamageManager::currentProjectile = currentProjectile;
}

//rewrite, also added lua stuff
HOOK_METHOD_PRIORITY(SpaceDrone, CollisionMoving, 9999, (Pointf start, Pointf finish, Damage damage, bool raytrace) -> CollisionResponse)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SpaceDrone::CollisionMoving -> Begin (CustomDamage.cpp)\n")
	CollisionResponse ret = CollisionResponse();
    ret.collision_type = 0;
    ret.point = {-2147483648.f, -2147483648.f};
    ret.damage = 0;
    ret.superDamage = 0;

    if (!this->bDead && this->deployed && !this->explosion.tracker.running && finish.RelativeDistance(this->currentLocation) < 100.f)
    {
        Projectile_Extend *ex = nullptr;
        if (CustomDamageManager::currentProjectile)
        {
            ex = PR_EX(CustomDamageManager::currentProjectile);
            if (!ex->missedDrones.empty())
            {
                for (int missedDrone : ex->missedDrones)
                {
                    if (missedDrone == selfId)
                    {
                        return ret;
                    }
                }
            }
        }

        int dodgeFactor = this->blueprint->dodge * 10;
        if (CustomDamageManager::currentWeaponDmg != nullptr)
        {
            dodgeFactor -= CustomDamageManager::currentWeaponDmg->droneAccuracyMod;
        }

        if (random32()%100 < dodgeFactor) // miss
        {
            if (this->powered)
            {
                delete this->message;
                this->message = new DamageMessage(1.0,this->currentLocation,DamageMessage::MISS);
                if (ex) ex->missedDrones.push_back(selfId);
                return ret;
            }
            ret.collision_type = 1;
            if (damage.iIonDamage > 0)
            {
                return ret;
            }
        }
        else //hit
        {
            ret.collision_type = 1;
            if (damage.iIonDamage > 0)
            {
                if (this->powered)
                {
                    this->ionStun = damage.iIonDamage * 5;
                }
                return ret;
            }
        }
        if (damage.iDamage > 0)
        {
            this->BlowUp(false);
        }
    }

    if (ret.collision_type == 1) // hit
    {
        // push everything to the lua stack: Drone, Projectile, Damage, CollisionResponse
        auto context = Global::GetInstance()->getLuaContext();
        SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pSpaceDroneTypes[this->Drone::type], 0);
        CustomDamageManager::lua_PushCurrentProjectile(context);
        SWIG_NewPointerObj(context->GetLua(), &damage, context->getLibScript()->types.pDamage, 0);
        SWIG_NewPointerObj(context->GetLua(), &ret, context->getLibScript()->types.pCollisionResponse, 0);

        // check drone-projectile collision callbacks
        bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::DRONE_COLLISION, 4, 0);

        // pop the stack
        lua_pop(context->GetLua(), 4);

        if (preempt) // a pre-empt will block the damage effect on the drone - script can also set collision type to 0 to prevent projectile death
        {
            return ret;
        }

        if (damage.iIonDamage > 0) // if ion damage then stun the drone
        {
            if (this->powered)
            {
                this->ionStun = damage.iIonDamage * 5;
            }
            return ret;
        }
        if (damage.iDamage > 0) // if no ion damage then normal damage blows up the drone
        {
            this->BlowUp(false);
        }
    }

    return ret;
}

// rewrite, base class method was inlined
HOOK_METHOD_PRIORITY(BoarderPodDrone, CollisionMoving, 9999, (Pointf start, Pointf finish, Damage damage, bool raytrace) -> CollisionResponse)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> BoarderPodDrone::CollisionMoving -> Begin (CustomDamage.cpp)\n")
    if (bDeliveredDrone)
    {
        CollisionResponse ret = CollisionResponse();
        ret.collision_type = 0;
        ret.point = {-2147483648.f, -2147483648.f};
        ret.damage = 0;
        ret.superDamage = 0;
        return ret;
    }

    return this->SpaceDrone::CollisionMoving(start, finish, damage, raytrace);
}

// rewrite, vanilla implementation was spaghetti code
HOOK_METHOD_PRIORITY(HackingDrone, CollisionMoving, 9999, (Pointf start, Pointf finish, Damage damage, bool raytrace) -> CollisionResponse)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> HackingDrone::CollisionMoving -> Begin (CustomDamage.cpp)\n")
    CollisionResponse ret;

    if (!deployed || explosion.tracker.running || arrived)
    {
        ret = CollisionResponse();
        ret.collision_type = 0;
        ret.point = {-2147483648.f, -2147483648.f};
        ret.damage = 0;
        ret.superDamage = 0;
        return ret;
    }

    ret = this->SpaceDrone::CollisionMoving(start, finish, damage, raytrace);
    this->bDead = false; // vanilla does something like this for some reason, why do we even do this it seems like it would just break things
    return ret;
}

HOOK_METHOD(Projectile, CollisionMoving, (Pointf start, Pointf finish, Damage damage, bool raytrace) -> CollisionResponse)
{
    LOG_HOOK("HOOK_METHOD -> Projectile::CollisionMoving -> Begin (CustomDamage.cpp)\n")
    CollisionResponse ret = super(start, finish, damage, raytrace);

    if (ret.collision_type == 1) // hit
    {
        // push everything to the lua stack: this Projectile, Projectile, Damage, CollisionResponse
        auto context = Global::GetInstance()->getLuaContext();
        SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pProjectile[this->GetType()], 0);
        CustomDamageManager::lua_PushCurrentProjectile(context);
        SWIG_NewPointerObj(context->GetLua(), &damage, context->getLibScript()->types.pDamage, 0);
        SWIG_NewPointerObj(context->GetLua(), &ret, context->getLibScript()->types.pCollisionResponse, 0);

        // check projectile-projectile collision callbacks
        bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_COLLISION, 4, 0);

        // pop the stack
        lua_pop(context->GetLua(), 4);

        if (preempt) // a pre-empt will prevent this projectile from dying, user can set collision response type to 0 to prevent other projectile from dying
        {
            death_animation.tracker.running = false;
            startedDeath = false;
        }
    }

    return ret;
}

HOOK_METHOD_PRIORITY(ShipManager, CollisionShield, 9999, (Pointf start, Pointf finish, Damage damage, bool raytrace) -> CollisionResponse)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::CollisionShield -> Begin (CustomDamage.cpp)\n")
    CollisionResponse ret;

    if (shieldSystem)
    {
        CollisionResponse c1 = shieldSystem->CollisionTest(start.x, start.y, damage);
        ret = shieldSystem->CollisionTest(finish.x, finish.y, damage);
        if (c1.collision_type == 0 && ret.collision_type != 0) // collide
        {
            // push everything to the lua stack: ShipManager, Projectile, Damage, CollisionResponse
            auto context = Global::GetInstance()->getLuaContext();
            SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
            CustomDamageManager::lua_PushCurrentProjectile(context);
            SWIG_NewPointerObj(context->GetLua(), &damage, context->getLibScript()->types.pDamage, 0);
            SWIG_NewPointerObj(context->GetLua(), &ret, context->getLibScript()->types.pCollisionResponse, 0);

            // check projectile-shield collision callbacks
            bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SHIELD_COLLISION_PRE, 4, 0);

            if (!preempt) // pre-empt will prevent the shield from being affected by the damage
            {
                if (raytrace) // beam hit
                {
                    damage.iDamage = 0;
                    shieldSystem->CollisionReal(finish.x, finish.y, damage, false); // intentionally doesn't set ret; same as vanilla code
                }
                else if (GetDodged()) // miss
                {
                    damMessages.push_back(new DamageMessage(1.f, finish, DamageMessage::MISS));
                    ret.collision_type = 3;
                    ret.point = {-2147483648.f, -2147483648.f};
                    ret.damage = 0;
                    ret.superDamage = 0;
                }
                else // hit
                {
                    ret = shieldSystem->CollisionReal(finish.x, finish.y, damage, false);
                }
            }

            if (ret.collision_type == 2)
            {
                context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SHIELD_COLLISION, 4, 0);
            }

            // pop the stack
            lua_pop(context->GetLua(), 4);

            return ret;
        }
    }

    ret.collision_type = 0;
    ret.point = {-2147483648.f, -2147483648.f};
    ret.damage = 0;
    ret.superDamage = 0;
    return ret;
}



LaserBlast* SpaceManager::CreateLaserBlast(WeaponBlueprint *weapon, Pointf position, int space, int ownerId, Pointf target, int targetSpace, float heading)
{
    LaserBlast *projectile = new LaserBlast(position, space, targetSpace, target);
    projectile->ownerId = ownerId;

    if (space == targetSpace)
    {
        projectile->ComputeHeading();
    }
    else
    {
        projectile->heading = heading;
    }

    projectile->OnInit();
    projectile->Initialize(*weapon);

    projectiles.push_back(projectile);

    return projectile;
}

Asteroid* SpaceManager::CreateAsteroid(Pointf position, int space, int ownerId, Pointf target, int targetSpace, float heading)
{
    Asteroid *projectile = new Asteroid(position, space);
    projectile->ownerId = ownerId;
    projectile->destinationSpace = targetSpace;
    projectile->target = target;

    if (space == targetSpace)
    {
        projectile->ComputeHeading();
    }
    else if (heading == -1.f)
    {
        projectile->heading = random32()%360;
    }
    else
    {
        projectile->heading = heading;
    }

    projectile->hitSolidSound = "hitHull" + std::to_string((random32()%3)+1);
    projectile->hitShieldSound = "hitShield" + std::to_string((random32()%3)+1);
    projectile->missSound = "miss";

    projectiles.push_back(projectile);

    return projectile;
}

Missile* SpaceManager::CreateMissile(WeaponBlueprint *weapon, Pointf position, int space, int ownerId, Pointf target, int targetSpace, float heading)
{
    Missile *projectile = new Missile(position, space, targetSpace, target, heading);
    projectile->ownerId = ownerId;

    projectile->Initialize(*weapon);

    projectiles.push_back(projectile);

    return projectile;
}

BombProjectile* SpaceManager::CreateBomb(WeaponBlueprint *weapon, int ownerId, Pointf target, int targetSpace)
{
    BombProjectile *projectile = new BombProjectile({-2147483648.f, -2147483648.f}, 1-targetSpace, targetSpace, target);
    projectile->ownerId = ownerId;

    projectile->Initialize(*weapon);

    projectile->flight_animation.tracker.loop = false;
    projectiles.push_back(projectile);

    return projectile;
}

BeamWeapon* SpaceManager::CreateBeam(WeaponBlueprint *weapon, Pointf position, int space, int ownerId, Pointf target1, Pointf target2, int targetSpace, int length, float heading)
{
    Targetable *movingTarget = nullptr;
    ShipManager *targetShip = G_->GetShipManager(targetSpace);
    if (targetShip) movingTarget = &targetShip->_targetable;

    BeamWeapon *projectile = new BeamWeapon(position, space, targetSpace, target1, target2, length, movingTarget, heading);
    projectile->ownerId = ownerId;

    if (space == targetSpace)
    {
        projectile->ComputeHeading();
    }
    else if (heading == -1.f)
    {
        projectile->heading = random32()%360;
    }
    else
    {
        projectile->heading = heading;
    }

    projectile->entryAngle = random32()%360;

    float theta = heading * 0.01745329f;
    projectile->sub_end.x = position.x + 2000.f*cos(theta);
    projectile->sub_end.y = position.y + 2000.f*sin(theta);

    projectile->Initialize(*weapon);

    projectiles.push_back(projectile);

    return projectile;
}

LaserBlast* SpaceManager::CreateBurstProjectile(WeaponBlueprint *weapon, const std::string &image, bool fake, Pointf position, int space, int ownerId, Pointf target, int targetSpace, float heading)
{
    LaserBlast *projectile = new LaserBlast(position, space, targetSpace, target);
    projectile->ownerId = ownerId;

    if (space == targetSpace)
    {
        projectile->ComputeHeading();
    }
    else
    {
        projectile->heading = heading;
    }

    projectile->OnInit();
    projectile->Initialize(*weapon);

    projectile->flight_animation = G_->GetAnimationControl()->GetAnimation(image);

    if (fake)
    {
        projectile->damage.iDamage = 0;
        projectile->damage.iShieldPiercing = 0;
        projectile->damage.fireChance = 0;
        projectile->damage.breachChance = 0;
        projectile->damage.stunChance = 0;
        projectile->damage.iIonDamage = 0;
        projectile->damage.iSystemDamage = 0;
        projectile->damage.iPersDamage = 0;
        projectile->damage.bHullBuster = false;
        projectile->damage.ownerId = -1;
        projectile->damage.selfId = -1;
        projectile->damage.bLockdown = false;
        projectile->damage.crystalShard = false;
        projectile->damage.bFriendlyFire = true;
        projectile->damage.iStun = 0;
        projectile->death_animation.fScale = 0.25;
    }
    else
    {
        projectile->bBroadcastTarget = ownerId == 0;
    }

    projectiles.push_back(projectile);

    return projectile;
}

static std::vector<Animation> fakePdsSmokeAnims = {};
PDSFire* SpaceManager::CreatePDSFire(WeaponBlueprint *weapon, Point position, Pointf target, int targetSpace, bool smoke)
{
    PDSFire *projectile = new PDSFire(position, targetSpace, target);

    projectile->Initialize(*weapon);

    projectiles.push_back(projectile);

    if (smoke)
    {
        fakePdsSmokeAnims.emplace_back("effects/fire_smoke.png", 7, 1.f, Pointf(position.x-8.5f, position.y-8.5f), 238, 34, 0, -1);
        fakePdsSmokeAnims.back().Start(true);
    }

    return projectile;
}

HOOK_METHOD(SpaceManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::OnLoop -> Begin (CustomDamage.cpp)\n")

    for (auto it=fakePdsSmokeAnims.begin(); it!=fakePdsSmokeAnims.end(); )
    {
        it->Update();
        if (it->Done())
        {
            it = fakePdsSmokeAnims.erase(it);
        }
        else
        {
            ++it;
        }
    }

    super();
}

HOOK_METHOD(SpaceManager, OnRenderProjectiles, (int iShipId, int layerCommand) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::OnRenderProjectiles -> Begin (CustomDamage.cpp)\n")

    if (iShipId == 0 && layerCommand == 2)
    {
        for (Animation &anim : fakePdsSmokeAnims)
        {
            anim.OnRender(1.f, {1.f,1.f,1.f,1.f}, false);
        }
    }

    super(iShipId, layerCommand);
}

HOOK_METHOD(PDSFire, constructor, (Point pos, int destinationSpace, Pointf destination) -> void)
{
    LOG_HOOK("HOOK_METHOD -> PDSFire::constructor -> Begin (CustomDamage.cpp)\n")
    super(pos, destinationSpace, destination);

    currentScale = 1.f; // fixes uninitialized scale
}
