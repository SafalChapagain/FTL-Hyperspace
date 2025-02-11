#include "Global.h"

#pragma GCC push_options
#pragma GCC optimize ("O1")
#include "CustomCrew.h"
#include "PALMemoryProtection.h"
#include "CustomAugments.h"

int requiresFullControl = 0;
bool isTelepathicMindControl = false;

bool CrewMember::_HS_ValidTarget(int shipId)
{
    if (this->CrewMember::bDead || crewAnim->status == 3 || currentShipId != shipId) return false;

    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret;
    ex->CalculateStat(CrewStat::VALID_TARGET, def, &ret);
    return ret;
}

bool CrewMember::_HS_GetControllable()
{
    if (this->CrewMember::bDead) return false;

    bool ret = this->CrewMember::iShipId == 0 && !this->CrewMember::bMindControlled;

    if (!ret && this->CrewMember::iShipId == 1 && this->CrewMember::bMindControlled)
    {
        ShipManager *ship = G_->GetShipManager(0);
        if (ship) ret = ship->HasAugmentation("MIND_ORDER");
    }

    CrewMember_Extend *ex = nullptr;
    CrewDefinition *def;

    if (ret)
    {
        ex = CM_EX(this);
        def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
        ex->CalculateStat(CrewStat::CONTROLLABLE, def, &ret);
        if (ret)
        {
            if (requiresFullControl == 1)
            {
                ex->CalculateStat(CrewStat::CAN_MOVE, def, &ret);
                return ret;
            }
        }
        else if (!requiresFullControl)
        {
            ret = def->selectable;
        }
    }

    if (!ret && requiresFullControl == -1) // for AI with NO_AI, make AI think crew is player-controlled to prevent AI from controlling
    {
        if (!ex)
        {
            ex = CM_EX(this);
            def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
        }
        ex->CalculateStat(CrewStat::NO_AI, def, &ret);
        if (!ret)
        {
            ex->CalculateStat(CrewStat::CAN_MOVE, def, &ret);
            return !ret;
        }
    }

    return ret;
}

bool CrewMember_Extend::IsController(bool ai)
{
    bool ret = !orig->bDead && orig->Functional();

    if (ret)
    {
        ret = orig->iShipId == 0 && !orig->bMindControlled;

        if (!ret && orig->iShipId == 1 && orig->bMindControlled)
        {
            ShipManager *ship = G_->GetShipManager(0);
            if (ship) ret = ship->HasAugmentation("MIND_ORDER");
        }
    }

    CrewDefinition *def = GetDefinition();

    if (ret)
    {
        CalculateStat(CrewStat::CONTROLLABLE, def, &ret);
    }

    if (ai)
    {
        if (ret) return false;
        CalculateStat(CrewStat::NO_AI, def, &ret);
        return !ret;
    }
    else
    {
        return ret;
    }

    return ret;
}

bool CrewMember::_HS_CanSuffocate()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::CAN_SUFFOCATE, def, &ret);
    return ret;
}

bool CrewMember::_HS_CanFight()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::CAN_FIGHT, def, &ret);
    return ret;
}

bool CrewMember::_HS_CanRepair()
{
    bool req = !this->intruder && !this->bDead && this->crewAnim->status != 3;
    if (!req)
    {
        return false;
    }
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::CAN_REPAIR, def, &ret);
    return ret && req;
}

bool CrewMember::_HS_CanSabotage()
{
    bool req = this->intruder;
    if (!req)
    {
        return false;
    }
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::CAN_SABOTAGE, def, &ret);
    return ret && req;
}

bool CrewMember::_HS_CanMan()
{
    bool req = !this->intruder && this->fStunTime == 0.f && this->crewAnim->status != 3;
    if (!req)
    {
        return false;
    }
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::CAN_MAN, def, &ret);
    return ret && req;
}

bool CrewMember::_HS_CanTeleport()
{
    bool ret = this->CrewMember::CanTeleport(); //vanilla method
    if (!ret) return ret;

    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    ex->CalculateStat(CrewStat::CAN_TELEPORT, def, &ret);
    return ret;
}

bool CrewMember::_HS_CanBurn()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::CAN_BURN, def, &ret);
    return ret;
}

int CrewMember::_HS_GetMaxHealth()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    return ex->CalculateMaxHealth(def);
}

float CrewMember::_HS_GetMoveSpeedMultiplier()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    return ex->CalculateStat(CrewStat::MOVE_SPEED_MULTIPLIER, def);
}

float CrewMember::_HS_GetRepairSpeed()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    return ex->CalculateStat(CrewStat::REPAIR_SPEED_MULTIPLIER, def);
}

float CrewMember::_HS_GetDamageMultiplier()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    return ex->CalculateStat(CrewStat::DAMAGE_MULTIPLIER, def);
}

CrewMember *currentCrewLoop = nullptr;
HOOK_METHOD_PRIORITY(CrewMember, OnLoop, -1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::OnLoop -> Begin (CrewVTable.cpp)\n")
    currentCrewLoop = this;
    super();
    currentCrewLoop = nullptr;
}

HOOK_METHOD(CrewMember, MoveToRoom, (int roomId, int slotId, bool bForceMove) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::MoveToRoom -> Begin (CrewVTable.cpp)\n")
    if (currentCrewLoop == this)
    {
        bool canMove;
        auto ex = CM_EX(this);
        auto def = ex->GetDefinition();
        ex->CalculateStat(CrewStat::CAN_MOVE, def, &canMove);
        if (!canMove) return false;
    }
    return super(roomId, slotId, bForceMove);
}

HOOK_METHOD(CrewAnimation, OnUpdateEffects, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::OnUpdateEffects -> Begin (CrewVTable.cpp)\n")
    if (currentCrewLoop)
    {
        float oldDamage = fDamageDone;
        super();
        if (fDamageDone != oldDamage)
        {
            auto ex = CM_EX(currentCrewLoop);
            auto def = CustomCrewManager::GetInstance()->GetDefinition(currentCrewLoop->species);
            fDamageDone = fDamageDone * ex->CalculateStat(CrewStat::RANGED_DAMAGE_MULTIPLIER, def);
        }
    }
    else
    {
        super();
    }
}

bool CrewMember::_HS_ProvidesPower()
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    return custom->GetDefinition(this->species)->providesPower;
}

float CrewMember::_HS_FireRepairMultiplier()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    return ex->CalculateStat(CrewStat::FIRE_REPAIR_MULTIPLIER, def);
}

bool CrewMember::_HS_IsTelepathic()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    if (isTelepathicMindControl)
    {
        ex->CalculateStat(CrewStat::RESISTS_MIND_CONTROL, def, &ret);
    }
    else
    {
        ex->CalculateStat(CrewStat::IS_TELEPATHIC, def, &ret);
    }
    return ret;
}

float CrewMember::_HS_GetSuffocationModifier()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    return ex->CalculateStat(CrewStat::SUFFOCATION_MODIFIER, def);
}

bool CrewMember::_HS_IsAnaerobic()
{
    auto ex = CM_EX(this);
    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    bool ret = false;
    ex->CalculateStat(CrewStat::IS_ANAEROBIC, def, &ret);
    return ret;
}

bool CrewMember::_HS_HasSpecialPower()
{
    auto ex = CM_EX(this);

    return ex->hasSpecialPower;
}

std::pair<float, float> CrewMember::_HS_GetPowerCooldown() // get the first enabled power
{
    auto ex = CM_EX(this);

    if (ex->hasSpecialPower)
    {
        return ex->GetFirstCrewPower()->powerCooldown;
    }

    return {0.f, 1.f};
}

bool CrewMember::_HS_PowerReady() // get whether the first enabled power is ready
{
    auto ex = CM_EX(this);

    if (ex->hasSpecialPower)
    {
        return ex->GetFirstCrewPower()->PowerReady() == PowerReadyState::POWER_READY;
    }

    return false;
}

void CrewMember::_HS_ResetPower() // called on FTL jump
{
    auto ex = CM_EX(this);
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(this->species);

    if (!ex->crewPowers.empty())
    {
        // Calculate modified stats from stat boosts
        ex->CalculateStat(CrewStat::POWER_CHARGES_PER_JUMP, def);

        // Update properties
        for (ActivatedPower *power : ex->crewPowers)
        {
            if (!power->enabled) continue;

            // Update cooldown
            if (power->def->jumpCooldown == ActivatedPowerDefinition::JUMP_COOLDOWN_FULL)
            {
                power->powerCooldown.first = power->powerCooldown.second;
            }
            else if (power->def->jumpCooldown == ActivatedPowerDefinition::JUMP_COOLDOWN_RESET)
            {
                power->powerCooldown.first = 0;
            }

            // Update charges
            power->powerCharges.first = std::min(power->powerCharges.second, power->powerCharges.first + (int)power->modifiedChargesPerJump);
        }
    }
}

// To be used by AI only: vanilla activation (will activate first ability)
void CrewMember::_HS_ActivatePower()
{
    if (this->GetPowerOwner() == 1)
    {
        auto ex = CM_EX(this);

        if (ex->hasSpecialPower)
        {
            ex->GetFirstCrewPower()->PreparePower();
        }
    }
}

int CrewMember::GetPowerOwner()
{
    if (bMindControlled)
    {
        int enemyShipId = iShipId ? 0 : 1;
        auto *ship = G_->GetShipManager(enemyShipId); // ship using mind control
        if (ship && HasAugmentationById("MIND_ORDER", enemyShipId))
        {
            return ship->iShipId;
        }
    }
    return iShipId;
}

void SetupVTable(CrewMember *crew)
{
    void** vtable = *(void***)crew;

    MEMPROT_SAVE_PROT(dwOldProtect);
    MEMPROT_PAGESIZE();
    MEMPROT_UNPROTECT(&vtable[0], sizeof(void*) * 57, dwOldProtect);

    {
        auto fptr = &CrewMember::_HS_ValidTarget;
        vtable[7] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_GetControllable;
        vtable[23] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_CanFight;
        vtable[25] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_CanRepair;
        vtable[26] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_CanSabotage;
        vtable[27] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_CanMan;
        vtable[28] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_CanTeleport;
        vtable[29] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_CanSuffocate;
        vtable[31] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_CanBurn;
        vtable[32] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_GetMaxHealth;
        vtable[33] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_GetMoveSpeedMultiplier;
        vtable[40] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_GetRepairSpeed;
        vtable[41] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_GetDamageMultiplier;
        vtable[42] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_ProvidesPower;
        vtable[43] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_FireRepairMultiplier;
        vtable[45] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_IsTelepathic;
        vtable[46] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_GetPowerCooldown;
        vtable[47] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_PowerReady;
        vtable[48] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_ActivatePower;
        vtable[49] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_HasSpecialPower;
        vtable[50] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_ResetPower;
        vtable[51] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_GetSuffocationModifier;
        vtable[52] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &CrewMember::_HS_IsAnaerobic;
        vtable[55] = reinterpret_cast<void *&>(fptr);
    }

    MEMPROT_REPROTECT(&vtable[0], sizeof(void*) * 57, dwOldProtect);
}



HOOK_METHOD_PRIORITY(CrewMember, constructor, 500, (CrewBlueprint& bp, int shipId, bool intruder, CrewAnimation* animation) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::constructor -> Begin (CrewVTable.cpp)\n")

    super(bp, shipId, intruder, animation);
    iManningId = -1; // initialize to prevent crew AI crashes

    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    if (custom->IsRace(species) && !IsDrone())
    {
        SetupVTable(this);
        health.first = GetMaxHealth();
    }
}



bool CrewAnimation::_HS_CustomDeath()
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (!custom->IsRace(this->race)) return false;
    return custom->GetDefinition(this->race)->hasCustomDeathAnimation;
}

void SetupVTable(CrewAnimation *anim)
{
    void** vtable = *(void***)anim;

    MEMPROT_SAVE_PROT(dwOldProtect);
    MEMPROT_PAGESIZE();
    MEMPROT_UNPROTECT(&vtable[0], sizeof(void*) * 12, dwOldProtect);

    {
        auto fptr = &CrewAnimation::_HS_CustomDeath;
        vtable[12] = reinterpret_cast<void *&>(fptr);
    }

    MEMPROT_REPROTECT(&vtable[0], sizeof(void*) * 12, dwOldProtect);
}



HOOK_METHOD_PRIORITY(CrewAnimation, constructor, 500, (int shipId, const std::string& race, Pointf unk, bool hostile) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewAnimation::constructor -> Begin (CrewVTable.cpp)\n")
    super(shipId, race, unk, hostile);

    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (custom->IsRace(race) && !bDrone)
    {
        SetupVTable(this);
    }
}

HOOK_METHOD_PRIORITY(RockAnimation, constructor, 500, (const std::string &subRace, int iShipId, Pointf position, bool enemy) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> RockAnimation::constructor -> Begin (CrewVTable.cpp)\n")
    super(subRace, iShipId, position, enemy);

    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (custom->IsRace(subRace))
    {
        SetupVTable(this);
    }
}

RepairAnimation::RepairAnimation(int shipId, const std::string& race, Pointf position, bool enemy)
{
    this->constructor(shipId, race, position, enemy);
    *(void**)this = VTable_RepairAnimation;
    this->uniqueBool1 = true;
}

#pragma GCC pop_options


