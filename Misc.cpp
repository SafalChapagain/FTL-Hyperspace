#include "Global.h"
#include "CustomCrew.h"
#include "ShipUnlocks.h"
#include "EnemyShipIcons.h"
#include "CustomOptions.h"

#include <sstream>
#include <vector>
#include <map>
#include "LuaLibScript.h"
#include "InternalEvents.h"
#include "RenderEvents.h"
#include "swigluarun.h"
#include "EnumClassHash.h"
#include "TemporalSystem.h"

#include <boost/format.hpp>

// Set the global CApp variable for Lua

CApp *Global_CApp = nullptr;

HOOK_METHOD(CApp, OnInit, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnInit -> Begin (Misc.cpp)\n")
    Global_CApp = this;
    return super();
}



// Plays airlock sound when crew have been "dismissed"

HOOK_METHOD(CrewEquipBox, RemoveItem, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> CrewEquipBox::RemoveItem -> Begin (Misc.cpp)\n")
    int ret = super();
    if (!CustomOptionsManager::GetInstance()->dismissSound.currentValue.empty())
    {
        G_->GetSoundControl()->PlaySoundMix(CustomOptionsManager::GetInstance()->dismissSound.currentValue, -1.f, false);
    }
    return ret;
}



// Doesn't do anything, but I usually use this to test random stuff by changing what the numpad buttons do

static int testVal = 0;

HOOK_METHOD(CApp, OnKeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnKeyDown -> Begin (Misc.cpp)\n")
    if (key == SDLKey::SDLK_LEFTBRACKET) testVal -= 1;
    if (key == SDLKey::SDLK_RIGHTBRACKET) testVal += 1;

    if (key == SDLKey::SDLK_KP_MINUS)
    {
        testVal--;
    }
    if (key == SDLKey::SDLK_KP_PLUS)
    {
        testVal++;
    }

    super(key);
}



// Don't display low O2 warning if ship does not have an oxygen system

static bool displayWarning = true;

HOOK_METHOD(ShipStatus, RenderEvadeOxygen, (bool unk) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipStatus::RenderEvadeOxygen -> Begin (Misc.cpp)\n")
    if (!ship->HasSystem(ShipSystem::NameToSystemId("oxygen")) && ship->GetOxygenPercentage() <= 24)
    {
        displayWarning = false;
        oxygenMessage->flash = false;
    }

    super(unk);

    displayWarning = true;
    oxygenMessage->flash = true;
}

HOOK_METHOD(WarningMessage, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WarningMessage::OnRender -> Begin (Misc.cpp)\n")
    if (displayWarning)
    {
        super();
    }
}



// Bugfix for switching to the same background

HOOK_METHOD(SpaceManager, SwitchBackground, (const std::string& backgroundList) -> ImageDesc)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::SwitchBackground -> Begin (Misc.cpp)\n")
    ImageDesc ret = ImageDesc();
    auto img = G_->GetEventGenerator()->GetImageFromList(backgroundList);
    auto tex = G_->GetResources()->GetImageId(img);

    if (!tex)
    {
        return ret;
    }


    ret.tex = tex;
    ret.resId = tex->id_;
    ret.x = 0;
    ret.y = 0;
    ret.w = tex->width_;
    ret.h = tex->height_;
    ret.rot = 0;

    this->currentBack = tex;
    return ret;
}

//TODO: Move to appropriate file and cleanup a bit
static GL_Primitive* timerCircleMaxOcta = nullptr;
static GL_Primitive* timerCircleMaxRing = nullptr;
static bool initExtraPrimitive = false;

HOOK_METHOD(SystemBox, constructor, (Point pos, ShipSystem *sys, bool playerUI) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::constructor -> Begin (Misc.cpp)\n")
    if (!initExtraPrimitive)
    {
        timerCircleMaxOcta = G_->GetResources()->CreateImagePrimitiveString("icons/locking/s_octa_9+_base.png", 0, 0, 0, GL_Color(1.f, 1.f, 1.f, 1.f), 1.f, false);
        timerCircleMaxRing = G_->GetResources()->CreateImagePrimitiveString("icons/locking/s_ring_9+_base.png", 0, 0, 0, GL_Color(1.f, 1.f, 1.f, 1.f), 1.f, false);
        initExtraPrimitive = true;
    }

    super(pos, sys, playerUI);
}

HOOK_METHOD_PRIORITY(SystemBox, OnRender, 9999, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SystemBox::OnRender -> Begin (Misc.cpp)\n")
    bool bVar1;
    bool bVar2;
    int iVar1;
    GL_Primitive *prim;
    int iVar2;
    bool bVar3;
    int iVar3;
    int iVar4;
    bool bVar4;
    TimerHelper timer;
    ShipSystem *sys;
  
    bVar2 = bShowPower;
    tapButtonOffsetY = 0;
    cooldownOffsetY = 0;
    if (!bVar2 && 0 < pSystem->iHackEffect) 
    {
        bVar2 = pSystem->bUnderAttack;
    }
    bShowPower = bVar2;
    iVar1 = pSystem->iLockCount;
    if (iVar1 < 1) 
    {
        bVar1 = bShowPower;
        bVar3 = false;
LABEL_1:
        bVar4 = false;
        if (tapped) 
        {
            bVar4 = useLargeTapIcon;
        }
        if (!bVar1) 
        {
            if (!G_->GetSettings()->colorblind) 
            {
LABEL_2:
                iVar1 = topPower;
                iVar3 = 0;
                iVar4 = 0;
            }
            else 
            {
                if (pSystem->healthState.first == 0) 
                {
                    prim = brokenIcon;
                }
                else 
                {
                    bVar2 = pSystem->GetLocked();
                    if (!bVar2) goto LABEL_2;
                    prim = lockIcon;
                }
                CSurface::GL_RenderPrimitive(prim);
                iVar1 = topPower;
                iVar3 = 12;
                iVar4 = -12;
            }
            goto LABEL_3;
        }
    }
    else 
    {
        if (!ignoreStatus) 
        {
            bVar1 = bShowPower;
            bVar3 = true;
            goto LABEL_1;
        }
        bVar1 = bShowPower;
        bVar3 = bVar1;
        if (!bVar1) goto LABEL_1;
        bVar2 = tapped;
        bVar3 = bVar1;
        bVar4 = bVar2;
        if (bVar2) 
        {
            bVar4 = useLargeTapIcon;
            bVar3 = bVar2;
        }
    }
    if (powerAlpha < 1.0) 
    {
        GL_Color tint = CSurface::GetColorTint();
        CSurface::GL_SetColorTint(tint);
    }
    if (!bSimplePower) 
    {
        iVar1 = GetHeightModifier();
        iVar1 = pSystem->RenderPowerBoxes(location.x, location.y, 16, 6, 2, iVar1, false);
        topPower = iVar1;
    }
    else 
    {
        iVar1 = pSystem->powerState.second;
        iVar1 = ShipSystem::RenderPowerBoxesPlain(location.x, location.y, 16, 6, 2, iVar1, 0, iVar1);
        topPower = iVar1;
    }
    if (powerAlpha <= 1.0 && powerAlpha != 1.0) 
    {
        CSurface::GL_RemoveColorTint();
        iVar1 = topPower;
        iVar3 = 0;
        iVar4 = 0;
    }
    else 
    {
        iVar3 = 0;
        iVar4 = 0;
    }
    LABEL_3:
    if (!warning.tracker.done && warning.tracker.running) 
    {
        bVar2 = pSystem->bOnFire;
        iVar2 = pSystem->GetId();
        
        if (iVar2 == 0) 
        {
            iVar1 = -78;
        }
        iVar2 = location.y;
        CSurface::GL_PushMatrix();
        //CSurface::GL_Translate((float)location.x, (float)(iVar1 + iVar2 + ((-(unsigned int)(!bVar2) & 0b00010100) - 53)),0.0);
        CSurface::GL_Translate((float)location.x, (float)(iVar1 + iVar2 + (bVar2 ? -53 : -33)), 0.0);
        warning.OnRender();
        CSurface::GL_PopMatrix();
        iVar1 = topPower;
    }
    iVar2 = location.x;
    hitBox.w = 15;
    hitBox.x = iVar2 + 24;
    hitBox.y = iVar1 + 16;
    hitBox.h = location.y - iVar1 + 15;
    CSurface::GL_PushMatrix();
    CSurface::GL_Translate((float)location.x, (float)location.y, 0.0);
    if (!bVar3) {
        CSurface::GL_DestroyPrimitive(timerStencil);
        timerStencil = nullptr;
        lastTimerStencilCount = -1;
        if (!bSimplePower) 
        {
            if (!bVar4) 
            {
                pSystem->RenderSystemSymbol(bPlayerUI, -1);
            }
            else 
            {
                CSurface::GL_Translate((float)(largeTapIconOffset.x - 32), (float)(largeTapIconOffset.y - 32), 0.0);
                CSurface::GL_Scale(2.0, 2.0, 1.0);
                pSystem->RenderSystemSymbol(false, -1);
            }
        }
        else 
        {
            pSystem->RenderSystemSymbol(false, 0);
        }
    }
    else 
    {
        if (bVar4) 
        {
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(19.0, -14.0, 0.0);
        }
        iVar1 = pSystem->iLockCount;
        //Fix for ion greater than 9 rendering invalid primitive
        CSurface::GL_RenderPrimitive(iVar1 <= 9 ? timerCircle[iVar1] : (ShipSystem::IsSubsystem(pSystem->GetId()) ? timerCircleMaxOcta : timerCircleMaxRing));
        
        timer = pSystem->GetLockTimer();
        iVar1 = (int)((12.0 - (timer.currTime / timer.currGoal) * 12.0) + 1.0);
        if (iVar1 != lastTimerStencilCount) 
        {
            lastTimerStencilCount = iVar1;
            CSurface::GL_DestroyPrimitive(timerStencil);
            timer.currGoal = 1.0;
            timer.maxTime = 0;
            timer.minTime = 0;
            timer.currTime = 0.0;
            prim = CSurface::GL_CreatePiePartialPrimitive(0, 0, 17.0, -85.0, (float)(iVar1 * 30 - 85), 17.0, GL_Color(0.0, 0.0, 0.0, 1.0));
            timerStencil = prim;
        }
        CSurface::GL_SetStencilMode(STENCIL_SET, 1, 1);
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(32.0, 32.0, 0.0);
        CSurface::GL_RenderPrimitive(timerStencil);
        CSurface::GL_PopMatrix();
        CSurface::GL_SetStencilMode(STENCIL_USE, 1, 1);
        CSurface::GL_RenderPrimitive(timerLines);
        CSurface::GL_SetStencilMode(STENCIL_IGNORE, 0, 0);
        if (bVar4) 
        {
            CSurface::GL_PopMatrix();
        }
    }
    CSurface::GL_PopMatrix();
    if (0 < pSystem->iHackEffect && pSystem->bUnderAttack && !bShowPower) 
    {
        CSurface::GL_Translate(0.0, (float)iVar4, 0.0);
        CSurface::GL_RenderPrimitive(hackIcon);
        CSurface::GL_Translate(0.0, (float)iVar3, 0.0);
    }
    return;
}

//Not sure what file this should be in, move to appropriate location later
//Neutral ASB text
static GL_Primitive* warningPdsAll = nullptr;

HOOK_METHOD(SpaceStatus, OnInit, (SpaceManager *space, Point pos) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceStatus::OnInit -> Begin (Misc.cpp)\n")
    super(space, pos);
    warningPdsAll = G_->GetResources()->CreateImagePrimitiveString("warnings/danger_pds_neutral.png", position.x - 30, position.y, 0, GL_Color(1.f, 1.f, 1.f, 1.f), 1.f, false);
}

HOOK_METHOD(SpaceStatus, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceStatus::OnRender -> Begin (Misc.cpp)\n")

    int idx = G_->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::SPACE_STATUS, 0);
    
    if (idx >= 0)
    {
        incomingFire->OnRender();
        if (currentEffect == 0)
        {
            G_->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SPACE_STATUS, std::abs(idx), 0);
            return;
        }
        CSurface::GL_PushMatrix();
        bool neutralAsb = (currentEffect == 6 || currentEffect == 9) && space->envTarget == 2; // Special case for neutral ASB
        CSurface::GL_RenderPrimitive(neutralAsb ? warningPdsAll : warningImages[currentEffect]);
        if (currentEffect2 != 0)
        {
            CSurface::GL_Translate(72.f, 0.f, 0.f);
            CSurface::GL_RenderPrimitive(warningImages[currentEffect2]);
        }
        CSurface::GL_PopMatrix();
        RenderWarningText(currentEffect, (currentEffect2 == 0) ? 0 : 36);
        if (touchedTooltip == 1)
        {
            int mX = hitbox.w / 2 + hitbox.x;
            int mY = hitbox.y + hitbox.h;
            MouseMove(mX, mY + -1);
            G_->GetMouseControl()->QueueStaticTooltip(Point(mX - 80, mY + 20));
        }
        if (((space->sunLevel == false) && (space->pulsarLevel == false)) && (space->bPDS == false))
        {
            G_->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SPACE_STATUS, std::abs(idx), 0);
            return;
        }
        warningMessage->OnRender();
    }

    G_->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SPACE_STATUS, std::abs(idx), 0);
}

HOOK_METHOD_PRIORITY(SpaceStatus, RenderWarningText, 9999, (int effect, int textOffset) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SpaceStatus::RenderWarningText -> Begin (Misc.cpp)\n")
    GL_Texture *tex;
    GL_Color color;
    std::string text;
  
    color.g = 1.0;
    color.a = 1.0;
    if ((effect == 6 || effect == 9) && space->envTarget == 2) // ASB and targeting both ships
    {
        color.b = 90.f / 255.f;
        color.g = 255.f / 255.f;
        color.r = 255.f / 255.f;

        tex = G_->GetResources()->GetImageId("warnings/backglow_warning_yellow.png");
        text = G_->GetTextLibrary()->GetText("warning_pds_all");
    }
    else if (effect == 9) 
    {
        color.r = 0.4705882;
        color.b = 0.4705882;
        tex = G_->GetResources()->GetImageId("warnings/backglow_warning_green.png");
        text = G_->GetTextLibrary()->GetText("warning_pds_allies");
    }
    else 
    {
        //TODO: Hook Global COLOR_RED_WARNING
        /*
        color.b = COLOR_RED_WARNING.b / 255.0;
        color.g = COLOR_RED_WARNING.g / 255.0;
        color.r = COLOR_RED_WARNING.r / 255.0;
        */
        color.b = 50.f / 255.f;
        color.g = 50.f / 255.f;
        color.r = 255.f / 255.f;

        tex = G_->GetResources()->GetImageId("warnings/backglow_warning_red.png");
        text = G_->GetTextLibrary()->GetText("warning_environment_danger");
    }

    Point textPos = Point(textOffset + position.x, position.y + 51);
    Pointf textSize = freetype::easy_measurePrintLines(52, 0.0, 0.0, 999, text);
    CSurface::GL_BlitImage(tex, textPos.x - (int)textSize.x / 2, textPos.y - 1, (int)textSize.x, (int)textSize.y, 0.0, GL_Color(1.0, 1.0, 1.0, 1.0), false);
    CSurface::GL_SetColor(color);
    freetype::easy_printCenter(52, textPos.x, textPos.y, text);
    CSurface::GL_SetColor(GL_Color(1.0, 1.0, 1.0, 1.0));
    return;
}

HOOK_METHOD_PRIORITY(SpaceStatus, MouseMove, 9999, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SpaceStatus::MouseMove -> Begin (Misc.cpp)\n")
    std::string tip;

    if (mX <= hitbox.x || hitbox.x + hitbox.w <= mX || mY <= hitbox.y || hitbox.y + hitbox.h <= mY)
    {
        goto LABEL_TWO;
    }
  
    if (currentEffect == 2) 
    {
        tip = "sun";
    }
    else if (currentEffect == 6 || currentEffect == 9) 
    {
        bool inFleet = space->dangerZone;    
        if (space->envTarget == 0) 
        {
            tip = inFleet ? "PDS_FLEET" : "PDS_PLAYER";
        }
        else if (space->envTarget == 1)
        { 
            tip = inFleet ? "PDS_FLEET_ENEMY" : "PDS_ENEMY";
        }
        else
        {
            tip = inFleet ? "PDS_FLEET_ALL" : "PDS_ALL";
        }
    }
    else 
    {
        if (currentEffect == 5) 
        {
            tip = "pulsar";
        }
        else 
        {
            if (currentEffect == 1) 
            {
                tip = "asteroids";
                goto LABEL_ONE;
            }
            if (currentEffect != 3) goto LABEL_TWO;
            tip = "nebula";
        }
    }
LABEL_ONE:
    G_->GetMouseControl()->LoadTooltip(tip);
LABEL_TWO:
    if (hitbox2.x < mX && mX < hitbox2.x + hitbox2.w && hitbox2.y < mY && mY < hitbox2.y + hitbox2.h && currentEffect2 == 4)
    {
        tip = "storm";
        G_->GetMouseControl()->LoadTooltip(tip);
    }
    return;
}

// Everything from here onward was originally in the lua folder and needed
// to be moved in order to compile properly on Linux.

//////////////////////////////////////////////////
//////////////// LuaLibScript.cpp ////////////////
//////////////////////////////////////////////////

static std::vector<LuaFunctionRef> m_on_load_callbacks;
static std::vector<LuaFunctionRef> m_on_init_callbacks;
static std::multimap<std::string, LuaFunctionRef> m_on_game_event_callbacks;
static std::multimap<std::string, LuaFunctionRef> m_on_game_event_loading_callbacks;
static std::unordered_map<InternalEvents::Identifiers, std::vector<std::pair<LuaFunctionRef, int>>, EnumClassHash> m_on_internal_event_callbacks;
static std::unordered_map<RenderEvents::Identifiers, std::vector<std::pair<std::pair<LuaFunctionRef, LuaFunctionRef>, int>>, EnumClassHash> m_on_render_event_callbacks; // Holds before & after function ref in the pair

void LuaLibScript::LoadTypeInfo()
{
    types.pActivatedPower = SWIG_TypeQuery(this->m_Lua, "ActivatedPower *");
    types.pActivatedPowerRequirements = SWIG_TypeQuery(this->m_Lua, "ActivatedPowerRequirements *");
    types.pActivatedPowerResource = SWIG_TypeQuery(this->m_Lua, "ActivatedPowerResource *");
    types.pCollideable = SWIG_TypeQuery(this->m_Lua, "Collideable *");
    types.pCollisionResponse = SWIG_TypeQuery(this->m_Lua, "CollisionResponse *");
    types.pCrewMember = SWIG_TypeQuery(this->m_Lua, "CrewMember *");
    types.pDamage = SWIG_TypeQuery(this->m_Lua, "Damage *");
    types.pPointf = SWIG_TypeQuery(this->m_Lua, "Pointf *");
    types.pProjectile[0] = SWIG_TypeQuery(this->m_Lua, "Projectile *");
    types.pProjectile[1] = SWIG_TypeQuery(this->m_Lua, "LaserBlast *");
    types.pProjectile[2] = SWIG_TypeQuery(this->m_Lua, "Asteroid *");
    types.pProjectile[3] = SWIG_TypeQuery(this->m_Lua, "Missile *");
    types.pProjectile[4] = SWIG_TypeQuery(this->m_Lua, "BombProjectile *");
    types.pProjectile[5] = SWIG_TypeQuery(this->m_Lua, "BeamWeapon *");
    types.pProjectile[6] = SWIG_TypeQuery(this->m_Lua, "PDSFire *");
    types.pProjectileFactory = SWIG_TypeQuery(this->m_Lua, "ProjectileFactory *");
    types.pShip = SWIG_TypeQuery(this->m_Lua, "Ship *");
    types.pShipBlueprint = SWIG_TypeQuery(this->m_Lua, "ShipBlueprint *");
    types.pShipEvent = SWIG_TypeQuery(this->m_Lua, "ShipEvent *");
    types.pShipManager = SWIG_TypeQuery(this->m_Lua, "ShipManager *");
    types.pShipSystem = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pWeaponSystem = SWIG_TypeQuery(this->m_Lua, "WeaponSystem *");
    types.pDroneSystem = SWIG_TypeQuery(this->m_Lua, "DroneSystem *");
    types.pWeaponBlueprint = SWIG_TypeQuery(this->m_Lua, "WeaponBlueprint *");
    types.pRoom = SWIG_TypeQuery(this->m_Lua, "Room *");
    types.pChoiceBox = SWIG_TypeQuery(this->m_Lua, "ChoiceBox *");
    types.pLocationEvent = SWIG_TypeQuery(this->m_Lua, "LocationEvent *");

    types.pSpaceDrone = SWIG_TypeQuery(this->m_Lua, "SpaceDrone *");
    // todo: fix the derived types to make them work (probably need to expose them in hyperspace.i)
    types.pSpaceDroneTypes[0] = SWIG_TypeQuery(this->m_Lua, "DefenseDrone *");
    types.pSpaceDroneTypes[1] = SWIG_TypeQuery(this->m_Lua, "CombatDrone *");
    types.pSpaceDroneTypes[2] = nullptr;
    types.pSpaceDroneTypes[3] = nullptr;
    types.pSpaceDroneTypes[4] = SWIG_TypeQuery(this->m_Lua, "BoarderPodDrone *");
    types.pSpaceDroneTypes[5] = SWIG_TypeQuery(this->m_Lua, "ShipRepairDrone *");
    types.pSpaceDroneTypes[6] = SWIG_TypeQuery(this->m_Lua, "HackingDrone *");
    types.pSpaceDroneTypes[7] = SWIG_TypeQuery(this->m_Lua, "SuperShieldDrone *");

    types.pShipSystemTypes[SYS_SHIELDS] = SWIG_TypeQuery(this->m_Lua, "Shields *");
    types.pShipSystemTypes[SYS_ENGINES] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *"); // todo: add EngineSystem struct and expose in lua
    types.pShipSystemTypes[SYS_OXYGEN] = SWIG_TypeQuery(this->m_Lua, "OxygenSystem *");
    types.pShipSystemTypes[SYS_WEAPONS] = SWIG_TypeQuery(this->m_Lua, "WeaponSystem *");
    types.pShipSystemTypes[SYS_DRONES] = SWIG_TypeQuery(this->m_Lua, "DroneSystem *");
    types.pShipSystemTypes[SYS_MEDBAY] = SWIG_TypeQuery(this->m_Lua, "MedbaySystem *");
    types.pShipSystemTypes[SYS_PILOT] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pShipSystemTypes[SYS_SENSORS] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pShipSystemTypes[SYS_DOORS] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pShipSystemTypes[SYS_TELEPORTER] = SWIG_TypeQuery(this->m_Lua, "TeleportSystem *");
    types.pShipSystemTypes[SYS_CLOAKING] = SWIG_TypeQuery(this->m_Lua, "CloakingSystem *");
    types.pShipSystemTypes[SYS_ARTILLERY] = SWIG_TypeQuery(this->m_Lua, "ArtillerySystem *");
    types.pShipSystemTypes[SYS_BATTERY] = SWIG_TypeQuery(this->m_Lua, "BatterySystem *");
    types.pShipSystemTypes[SYS_CLONEBAY] = SWIG_TypeQuery(this->m_Lua, "CloneSystem *");
    types.pShipSystemTypes[SYS_MIND] = SWIG_TypeQuery(this->m_Lua, "MindSystem *");
    types.pShipSystemTypes[SYS_HACKING] = SWIG_TypeQuery(this->m_Lua, "HackingSystem *");
    types.pShipSystemTypes[16] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pShipSystemTypes[17] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pShipSystemTypes[18] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pShipSystemTypes[19] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pShipSystemTypes[SYS_TEMPORAL] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *"); // eventually reimplement temporal as TemporalSystem class?
}

int LuaLibScript::l_on_load(lua_State* lua)
{
    luaL_argcheck(lua, lua_isfunction(lua, 1), 1, "function expected!");
    LuaFunctionRef callbackReference = luaL_ref(lua, LUA_REGISTRYINDEX);
    m_on_load_callbacks.push_back(callbackReference);
    return 0;
}

void LuaLibScript::call_on_load_callbacks()
{
    lua_State* lua = this->m_Lua;
    // Load the callback by reference number
    printf("Fetching %u on_load callbacks\n", m_on_load_callbacks.size());
    for(auto i = m_on_load_callbacks.cbegin(); i != m_on_load_callbacks.cend(); ++i)
    {
        LuaFunctionRef refL = *i;
        lua_rawgeti(lua, LUA_REGISTRYINDEX, refL);
        if(lua_pcall(lua, 0, 0, 0) != 0) {
            hs_log_file("Failed to call the callback!\n %s\n", lua_tostring(lua, -1));
            lua_pop(lua, 1);
            return;
        }
    }
}

int LuaLibScript::l_on_init(lua_State* lua)
{
    luaL_argcheck(lua, lua_isfunction(lua, 1), 1, "function expected!");
    LuaFunctionRef callbackReference = luaL_ref(lua, LUA_REGISTRYINDEX);
    m_on_init_callbacks.push_back(callbackReference);
    return 0;
}

void LuaLibScript::call_on_init_callbacks(bool newGame)
{
    lua_State* lua = this->m_Lua;
    // Load the callback by reference number
    printf("Fetching %u on_init callbacks\n", m_on_init_callbacks.size());
    for(auto i = m_on_init_callbacks.cbegin(); i != m_on_init_callbacks.cend(); ++i)
    {
        LuaFunctionRef refL = *i;
        lua_rawgeti(lua, LUA_REGISTRYINDEX, refL);
        lua_pushboolean(lua, newGame);
        if(lua_pcall(lua, 1, 0, 0) != 0) {
            hs_log_file("Failed to call the callback!\n %s\n", lua_tostring(lua, -1));
            lua_pop(lua, 1);
            return;
        }
    }
}

int LuaLibScript::l_on_game_event(lua_State* lua)
{
    luaL_argcheck(lua, lua_isstring(lua, 1), 1, "string expected!");
    luaL_argcheck(lua, lua_isboolean(lua, 2), 2, "boolean expected!");
    luaL_argcheck(lua, lua_isfunction(lua, 3), 3, "function expected!");
    const std::string eventName = std::string(lua_tostring(lua, 1));
    const bool onLoad = lua_toboolean(lua, 2);
    lua_pushvalue(lua, 3);
    LuaFunctionRef callbackReference = luaL_ref(lua, LUA_REGISTRYINDEX); // Not sure if maybe we can move this above the tostring & toboolean? Since it pops off the Lua stack anyways rather than doing the pushvalue above this.
    if(onLoad)
        m_on_game_event_loading_callbacks.emplace(eventName, callbackReference);
    else
        m_on_game_event_callbacks.emplace(eventName, callbackReference);

    return 0;
}

// TODO: Maybe tell the compiler to always inline this
void call_all_functions_from_multimap(lua_State* lua, std::multimap<std::string, LuaFunctionRef> mmap, std::string key)
{
//    if(mmap.count(key) == 0)
//        return; // No registered callbacks

    printf("Fetching %u on_game_event callbacks for %s\n", mmap.count(key), key.c_str()); // TODO: Remove or add to debugging logs?
    for(std::pair<std::multimap<std::string, LuaFunctionRef>::iterator, std::multimap<std::string, LuaFunctionRef>::iterator> range(mmap.equal_range(key)); range.first != range.second; ++range.first)
    {
        LuaFunctionRef refL = range.first->second;
        lua_rawgeti(lua, LUA_REGISTRYINDEX, refL);
        if(lua_pcall(lua, 0, 0, 0) != 0) {
            hs_log_file("Failed to call the callback for %s!\n %s\n", key.c_str(), lua_tostring(lua, -1));
            lua_pop(lua, 1);
            return;
        }
    }
}

void LuaLibScript::call_on_game_event_callbacks(std::string eventName, bool isLoading)
{
    call_all_functions_from_multimap(this->m_Lua, isLoading ? m_on_game_event_loading_callbacks : m_on_game_event_callbacks, eventName);
}

int LuaLibScript::l_on_render_event(lua_State* lua)
{
    luaL_argcheck(lua, lua_isinteger(lua, 1), 1, "integer expected!");
    luaL_argcheck(lua, lua_isfunction(lua, 2), 2, "function expected!"); // TODO: Allow one or both functions to be nil
    luaL_argcheck(lua, lua_isfunction(lua, 3), 3, "function expected!");
    const int callbackHookId = lua_tointeger(lua, 1);
    luaL_argcheck(lua, callbackHookId > RenderEvents::UNKNOWN && callbackHookId < RenderEvents::UNKNOWN_MAX, 1, "Unknown RenderEvent!");
    // TODO: Print a nice pretty message to the logs maybe if event was not a known value?
    lua_pushvalue(lua, 2);
    LuaFunctionRef callbackBeforeRef = luaL_ref(lua, LUA_REGISTRYINDEX);
    lua_pushvalue(lua, 3);
    LuaFunctionRef callbackAfterRef = luaL_ref(lua, LUA_REGISTRYINDEX);

    int priority = 0;
    if (lua_gettop(lua) >= 4)
    {
        luaL_argcheck(lua, lua_isinteger(lua, 4), 4, "integer expected!");
        priority = lua_tointeger(lua, 4);
    }

    RenderEvents::Identifiers id = static_cast<RenderEvents::Identifiers>(callbackHookId);

    std::vector<std::pair<std::pair<LuaFunctionRef, LuaFunctionRef>, int>> &vec = m_on_render_event_callbacks[id];
    vec.emplace_back(std::make_pair(callbackBeforeRef,callbackAfterRef), priority);
    std::stable_sort(vec.begin(), vec.end(),
        [](const std::pair<std::pair<LuaFunctionRef, LuaFunctionRef>, int> &a, const std::pair<std::pair<LuaFunctionRef, LuaFunctionRef>, int> &b) -> bool
        {
            return a.second > b.second; // higher priority first
        }
    );

    return 0;
}

// Pre callback calls from highest priority to lowest priority, can return chain to stop the loop, returns index of last callback called plus 1.
// If pre-empt is signalled then returns a negative index.
// Absolute value of the pre_callbacks return is passed to the post_callbacks method.
int LuaLibScript::call_on_render_event_pre_callbacks(RenderEvents::Identifiers id, int nArg)
{
    assert(id > RenderEvents::UNKNOWN);
    assert(id < RenderEvents::UNKNOWN_MAX);

    auto vecIt = m_on_render_event_callbacks.find(id);
    if (vecIt == m_on_render_event_callbacks.end()) return 0;

    std::vector<std::pair<std::pair<LuaFunctionRef, LuaFunctionRef>, int>> &vec = vecIt->second;

    unsigned int idx;
    for (idx = 0; idx < vec.size(); ++idx)
    {
        LuaFunctionRef refL = vec[idx].first.first;
        lua_rawgeti(this->m_Lua, LUA_REGISTRYINDEX, refL);
        for (int i=0; i<nArg; ++i)
        {
            lua_pushvalue(this->m_Lua, -1-nArg);
        }
        if(lua_pcall(this->m_Lua, nArg, 1, 0) != 0) {
            hs_log_file("Failed to call the before callback for RenderEvent %s!\n %s\n", RenderEvents::GetName(id), lua_tostring(this->m_Lua, -1));
            lua_pop(this->m_Lua, 1);
            continue;
        }
        int chain;
        if (lua_isinteger(this->m_Lua, -1))
        {
            chain = lua_tointeger(this->m_Lua, -1);
        }
        else
        {
            chain = Chain::CONTINUE;
        }
        lua_pop(this->m_Lua, 1);

        if (chain != Chain::CONTINUE)
        {
            int ret = idx+1;
            return chain == Chain::PREEMPT ? -ret : ret;
        }
    }

    return idx;
}
void LuaLibScript::call_on_render_event_post_callbacks(RenderEvents::Identifiers id, int idx, int nArg)
{
    assert(id > RenderEvents::UNKNOWN);
    assert(id < RenderEvents::UNKNOWN_MAX);

    auto vecIt = m_on_render_event_callbacks.find(id);
    if (vecIt == m_on_render_event_callbacks.end()) return;

    std::vector<std::pair<std::pair<LuaFunctionRef, LuaFunctionRef>, int>> &vec = vecIt->second;

    for (--idx; idx >= 0; --idx)
    {
        LuaFunctionRef refL = vec[idx].first.second;
        lua_rawgeti(this->m_Lua, LUA_REGISTRYINDEX, refL);
        for (int i=0; i<nArg; ++i)
        {
            lua_pushvalue(this->m_Lua, -1-nArg);
        }
        if(lua_pcall(this->m_Lua, nArg, 0, 0) != 0) {
            hs_log_file("Failed to call the after callback for RenderEvent %s!\n %s\n", RenderEvents::GetName(id), lua_tostring(this->m_Lua, -1));
            lua_pop(this->m_Lua, 1);
            continue;
        }
    }
}

int LuaLibScript::l_on_internal_event(lua_State* lua)
{
    luaL_argcheck(lua, lua_isinteger(lua, 1), 1, "integer expected!");
    luaL_argcheck(lua, lua_isfunction(lua, 2), 2, "function expected!");
    const int callbackHookId = lua_tointeger(lua, 1);
    luaL_argcheck(lua, callbackHookId > InternalEvents::UNKNOWN && callbackHookId < InternalEvents::UNKNOWN_MAX, 1, "Unknown InternalEvent!"); 
    // TODO: Print a nice pretty message to the logs maybe if event was not a known value?
    lua_pushvalue(lua, 2);
    LuaFunctionRef callbackReference = luaL_ref(lua, LUA_REGISTRYINDEX);

    int priority = 0;
    if (lua_gettop(lua) >= 3)
    {
        luaL_argcheck(lua, lua_isinteger(lua, 3), 3, "integer expected!");
        priority = lua_tointeger(lua, 3);
    }
    
    
    //* NOTE! This may break previously valid constructs, such as script.on_internal_event(Defines.InternalEvents.SOME_EVENT_THAT_TAKES_ARGS, function() print("This function ignores its arguments!") end)
    lua_Debug ar;
    lua_rawgeti(lua, LUA_REGISTRYINDEX, callbackReference);
    lua_getinfo(lua, ">u", &ar);
    
    InternalEvents::Identifiers id = static_cast<InternalEvents::Identifiers>(callbackHookId);
    InternalEvents::EventInfo info = InternalEvents::GetEventInfo(id);
    const char* eventName = InternalEvents::GetName(id);
    if (ar.nparams != info.argCount)
    {  
        std::string error = (boost::format("Error: Callback function for InternalEvent %s has the wrong number of arguments! Expected %u, got %u\nExpected function of the form: %s\n")
                        % eventName
                        % info.argCount
                        % static_cast<unsigned int>(ar.nparams)
                        % info.functionSignatureDescription).str();
        hs_log_file(error);
        luaL_error(lua, error.c_str()); 
        return 0;
    }
    else if (ar.isvararg != info.isVariableArgs)
    {
        std::string error = (boost::format("Error: Provided function for InternalEvent %s %s!\nExpected function of the form: %s\n")
                        % eventName
                        % (info.isVariableArgs ? "Should be a variable argument function" : "Should not be a variable argument function")
                        % info.functionSignatureDescription).str();
        hs_log_file(error);
        luaL_error(lua, error.c_str());
        return 0;
    }
    //*/

    std::vector<std::pair<LuaFunctionRef, int>> &vec = m_on_internal_event_callbacks[id];
    vec.emplace_back(callbackReference, priority);
    std::stable_sort(vec.begin(), vec.end(),
        [](const std::pair<LuaFunctionRef, int> &a, const std::pair<LuaFunctionRef, int> &b) -> bool
        {
            return a.second > b.second; // higher priority first
        }
    );

    return 0;
}

// TODO: This might need to be a varargs in the future to allow calling with the arguments from the hook & also passing that infromation via the enum so we can check at registration time above if the function has the correct number of arguments and if the correct number were passed here.
int LuaLibScript::call_on_internal_event_callbacks(InternalEvents::Identifiers id, int nArg, int nRet)
{
    assert(id > InternalEvents::UNKNOWN);
    assert(id < InternalEvents::UNKNOWN_MAX);

    auto vecIt = m_on_internal_event_callbacks.find(id);
    if (vecIt == m_on_internal_event_callbacks.end()) return 0;

    std::vector<std::pair<LuaFunctionRef, int>> &vec = vecIt->second;

    for (unsigned int idx = 0; idx < vec.size(); ++idx)
    {
        LuaFunctionRef refL = vec[idx].first;
        lua_rawgeti(this->m_Lua, LUA_REGISTRYINDEX, refL);
        for (int i=0; i<nArg; ++i)
        {
            lua_pushvalue(this->m_Lua, -1-nArg);
        }
        if(lua_pcall(this->m_Lua, nArg, nRet, 0) != 0) {
            hs_log_file("Failed to call the callback for InternalEvent %s!\n %s\n", InternalEvents::GetName(id), lua_tostring(this->m_Lua, -1));
            lua_pop(this->m_Lua, 1);
            continue;
        }
        if (nRet > 0)
        {
            if (!lua_isnil(this->m_Lua, -nRet))
            {
                return nRet;
            }
            // If the return value is nil then we pop them before trying the next callback function
            lua_pop(this->m_Lua, nRet);
        }
    }
    return 0;
}

// version of internal event for chaining
// calling function is expected to push nArg values onto the stack
// first return value from lua function controls program flow
// Chain::CONTINUE will run the next callback
// Chain::HALT or Chain::PREEMPT will break out of the callback loop
// Remaining nRet return values will overwrite the last nRet arguments from nArg (unless nil is returned)
// bool return true if pre-empt requested
// The lua stack will be in the same configuration as when this function was called, except with argument values potentially replaced
bool LuaLibScript::call_on_internal_chain_event_callbacks(InternalEvents::Identifiers id, int nArg, int nRet)
{
    assert(id > InternalEvents::UNKNOWN);
    assert(id < InternalEvents::UNKNOWN_MAX);

    auto vecIt = m_on_internal_event_callbacks.find(id);
    if (vecIt == m_on_internal_event_callbacks.end()) return false;

    std::vector<std::pair<LuaFunctionRef, int>> &vec = vecIt->second;

    for (unsigned int idx = 0; idx < vec.size(); ++idx)
    {
        LuaFunctionRef refL = vec[idx].first;
        lua_rawgeti(this->m_Lua, LUA_REGISTRYINDEX, refL);
        for (int i=0; i<nArg; ++i)
        {
            lua_pushvalue(this->m_Lua, -1-nArg);
        }
        if(lua_pcall(this->m_Lua, nArg, nRet+1, 0) != 0) {
            // if the pcall fails then we just continue
            hs_log_file("Failed to call the callback for InternalEvent %s!\n %s\n", InternalEvents::GetName(id), lua_tostring(this->m_Lua, -1));
            lua_pop(this->m_Lua, 1);
            continue;
        }
        if (nRet > 0)
        {
            for (int i=0; i<nRet; ++i)
            {
                // replace the last nRet arguments from nArg with non-nil values from nRet
                if (!lua_isnil(this->m_Lua, -1))
                {
                    lua_replace(this->m_Lua, -nRet-2);
                }
                else
                {
                    lua_pop(this->m_Lua, 1);
                }
            }
        }

        int chain;
        if (lua_isinteger(this->m_Lua, -1))
        {
            chain = lua_tointeger(this->m_Lua, -1);
        }
        else
        {
            chain = Chain::CONTINUE;
            // maybe add error handling code here? For now just silently use Chain::CONTINUE
        }
        lua_pop(this->m_Lua, 1);

        if (chain != Chain::CONTINUE)
        {
            return chain == Chain::PREEMPT;
        }
    }
    return false;
}


// TODO: This hook to kick it off, could potentially move if needed? Or maybe we should of done a singleton pattern initialized by LuaScriptInit instead of passing the object back to LuaScriptInit and getting it from the global context there?
HOOK_METHOD(AchievementTracker, LoadAchievementDescriptions, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::LoadAchievementDescriptions -> Begin (Misc.cpp)\n")
    super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_load_callbacks();
}

//On selecting Continue and loading up a run.
HOOK_METHOD(ScoreKeeper, LoadGame, (int fh) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::LoadGame -> Begin (Misc.cpp)\n")
    super(fh);
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_init_callbacks(false);
}
//On restarting run or starting a new run from the hanger
HOOK_METHOD(WorldManager, CreateNewGame, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateNewGame -> Begin (Misc.cpp)\n")
    super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_init_callbacks(true);
}

HOOK_METHOD(WorldManager, UpdateLocation, (LocationEvent* locationEvent) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::UpdateLocation -> Begin (Misc.cpp)\n")
    printf("UpdateLocation - LocationEvent Seen, name: %s\n", locationEvent->eventName.c_str());
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_game_event_callbacks(locationEvent->eventName.c_str(), false);
    super(locationEvent);
}

HOOK_METHOD(WorldManager, CreateLocation, (Location* location) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateLocation -> Begin (Misc.cpp)\n")

    std::string eventName;

    if (location->boss)
    {
        std::stringstream s;
        s << "BOSS_TEXT_" << bossShip->nextStage;

        eventName = s.str();
    }
    else
    {
        eventName = location->event->eventName;
    }

    printf("CreateLocation - LocationEvent Seen, name: %s\n", eventName.c_str());
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_game_event_callbacks(eventName.c_str(), bLoadingGame);
    super(location);
   // TODO: Also call lua scripting for entering a location? (In addition to when the event is loaded) Maybe this is like Events.OnLocation and the other is the special LocationEvent that takes a name to hook to.
}

static const struct luaL_Reg slib_funcs[] = {
   { "on_load", LuaLibScript::l_on_load },
   { "on_init", LuaLibScript::l_on_init },
   { "on_game_event", LuaLibScript::l_on_game_event },
   { "on_render_event", LuaLibScript::l_on_render_event },
   { "on_internal_event", LuaLibScript::l_on_internal_event },
   { NULL, NULL }
};

static int luaopen_scriptlib(lua_State* lua)
{
   luaL_newlib(lua, slib_funcs);
   return 1;
}

LuaLibScript::LuaLibScript(lua_State* lua)
{
   this->m_Lua = lua;
   luaL_requiref(lua, "script", luaopen_scriptlib, 1);
   lua_pop(lua, 1);
}

////////////////////////////////////////////////////
//////////////// InternalEvents.cpp ////////////////
////////////////////////////////////////////////////

/** All the hook code for the various InternalEvents belongs here **/

HOOK_METHOD(CApp, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnLoop -> Begin (Misc.cpp)\n")
    super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_internal_event_callbacks(InternalEvents::ON_TICK);
}

HOOK_METHOD(MainMenu, Open, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::Open -> Begin (Misc.cpp)\n")
    super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_internal_event_callbacks(InternalEvents::MAIN_MENU);
}

HOOK_METHOD(CApp, OnKeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnKeyDown -> Begin (Misc.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), key);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_KEY_DOWN, 1, 0);
    lua_pop(context->GetLua(), 1);

    if (!preempt) super(key);
}

HOOK_METHOD(CApp, OnKeyUp, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnKeyUp -> Begin (Misc.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), key);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_KEY_UP, 1, 0);
    lua_pop(context->GetLua(), 1);

    if (!preempt) super(key);
}

HOOK_METHOD(CApp, OnMouseMove, (int x, int y, int xdiff, int ydiff, bool holdingLMB, bool holdingRMB, bool holdingMMB) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnMouseMove -> Begin (Misc.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    lua_pushinteger(context->GetLua(), xdiff);
    lua_pushinteger(context->GetLua(), ydiff);
    lua_pushboolean(context->GetLua(), holdingLMB);
    lua_pushboolean(context->GetLua(), holdingRMB);
    lua_pushboolean(context->GetLua(), holdingMMB);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_MOVE, 7, 0);
    lua_pop(context->GetLua(), 7);

    if (!preempt) super(x, y, xdiff, ydiff, holdingLMB, holdingRMB, holdingMMB);
}

HOOK_METHOD(CApp, OnLButtonDown, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnLButtonDown -> Begin (Misc.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_L_BUTTON_DOWN, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(x, y);
}

HOOK_METHOD(CApp, OnLButtonUp, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnLButtonUp -> Begin (Misc.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_L_BUTTON_UP, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(x, y);
}

HOOK_METHOD(CApp, OnRButtonDown, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnRButtonDown -> Begin (Misc.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_R_BUTTON_DOWN, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(x, y);
}

HOOK_METHOD_PRIORITY(CApp, OnRButtonUp, -100, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnRButtonUp -> Begin (Misc.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_R_BUTTON_UP, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(x, y);
}

HOOK_METHOD(CApp, OnMButtonDown, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnMButtonDown -> Begin (Misc.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_M_BUTTON_DOWN, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(x, y);
}

HOOK_METHOD_PRIORITY(CrewMember, OnLoop, -100, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::OnLoop -> Begin (Misc.cpp)\n")

    super();

    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pCrewMember, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::CREW_LOOP, 1);
    lua_pop(context->GetLua(), 1);
}
//Priority was necessary to make this run after the hook for calculating stuff with additionalPowerLoss, so user can do stuff like modify that for weapon effects here.
HOOK_METHOD_PRIORITY(ShipManager, OnLoop, -100, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::OnLoop -> Begin (Misc.cpp)\n")
    super();

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::SHIP_LOOP, 1);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(WeaponControl, SelectArmament, (unsigned int armamentSlot) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::SelectArmament -> Begin (Misc.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), armamentSlot);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SELECT_ARMAMENT_PRE, 1, 1);
    if (lua_isnumber(context->GetLua(), -1))
    {
        armamentSlot = static_cast<unsigned int>(lua_tonumber(context->GetLua(), -1));
        if (armamentSlot >= boxes.size() || armamentSlot < 0 || boxes[armamentSlot]->Empty()) preempt = true;
    }
    lua_pop(context->GetLua(), 1);

    if (!preempt) {
        super(armamentSlot);

        lua_pushinteger(context->GetLua(), armamentSlot);
        context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SELECT_ARMAMENT_POST, 1, 0);
        lua_pop(context->GetLua(), 1);
    }
}

//Priority to run after callback in CustomDrones.cpp
HOOK_METHOD_PRIORITY(SpaceDrone, GetNextProjectile, -100, () -> Projectile*)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SpaceDrone::GetNextProjectile -> Begin (Misc.cpp)\n")
    
    Projectile* ret = super();
    if (ret != nullptr)
    {
        auto context = G_->getLuaContext();
        SWIG_NewPointerObj(context->GetLua(), ret, context->getLibScript()->types.pProjectile[ret->GetType()], 0);
        SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pSpaceDroneTypes[this->type], 0);
        bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::DRONE_FIRE, 2, 0);
        lua_pop(context->GetLua(), 2);
        //preempt prevents projectile from firing
        if (preempt)
        {
            delete ret;
            return nullptr;
        }
    }
    return ret;
}

HOOK_METHOD(ShipManager, GetDodgeFactor, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetDodgeFactor -> Begin (Misc.cpp)\n")
    int ret = super();

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    lua_pushinteger(context->GetLua(), ret);
    context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::GET_DODGE_FACTOR, 2, 1);
    if (lua_isnumber(context->GetLua(), -1)) //Round floats and account for values like 1.0
    {
        ret = static_cast<int>(lua_tonumber(context->GetLua(), -1));
    }
    lua_pop(context->GetLua(), 2);
    return ret;
}

HOOK_METHOD(ShipSystem, SetBonusPower, (int amount, int permanentPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::SetBonusPower -> Begin (Misc.cpp)\n")

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipSystem, 0);
    lua_pushinteger(context->GetLua(), amount);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SET_BONUS_POWER, 2, 1);
    if (lua_isnumber(context->GetLua(), -1)) amount = static_cast<int>(lua_tonumber(context->GetLua(), -1));
    lua_pop(context->GetLua(), 2);
    
    if (!preempt) super(amount, permanentPower);
}
HOOK_METHOD(WeaponSystem, SetBonusPower, (int amount, int permanentPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponSystem::SetBonusPower -> Begin (Misc.cpp)\n")

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pWeaponSystem, 0);
    lua_pushinteger(context->GetLua(), amount);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SET_BONUS_POWER, 2, 1);
    if (lua_isnumber(context->GetLua(), -1)) amount = static_cast<int>(lua_tonumber(context->GetLua(), -1));
    lua_pop(context->GetLua(), 2);
    
    if (!preempt) super(amount, permanentPower);
}
HOOK_METHOD(DroneSystem, SetBonusPower, (int amount, int permanentPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> DroneSystem::SetBonusPower -> Begin (Misc.cpp)\n")

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pDroneSystem, 0);
    lua_pushinteger(context->GetLua(), amount);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SET_BONUS_POWER, 2, 1);
    if (lua_isnumber(context->GetLua(), -1)) amount = static_cast<int>(lua_tonumber(context->GetLua(), -1));
    lua_pop(context->GetLua(), 2);
    
    if (!preempt) super(amount, permanentPower);
}

HOOK_METHOD(ShipManager, JumpArrive, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::JumpArrive -> Begin (Misc.cpp)\n")
    super();
    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::JUMP_ARRIVE, 1);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(ShipManager, JumpLeave, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::JumpLeave -> Begin (Misc.cpp)\n")
    super();
    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::JUMP_LEAVE, 1);
    lua_pop(context->GetLua(), 1);
}
//To be used for button MouseMove functions as to create proper beep sounds and mouse pointer animation changes.
HOOK_METHOD(CommandGui, MouseMove, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::MouseMove -> Begin (Misc.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();
    lua_pushinteger(context->GetLua(), mX);
    lua_pushinteger(context->GetLua(), mY);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::GUI_MOUSE_MOVE, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(mX, mY);
}

HOOK_METHOD(ShipManager, Wait, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::Wait -> Begin (Misc.cpp)\n")
    super();
    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::ON_WAIT, 1);
    lua_pop(context->GetLua(), 1);
}

// Allow ship rename input to receive Japanese letters
HOOK_METHOD(ShipBuilder, Open, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::Open -> Begin (Misc.cpp)\n")
    super();
    if (CustomOptionsManager::GetInstance()->allowRenameInputSpecialCharacters.currentValue)
    {
        nameInput.allowedChars = TextInput::ALLOW_ANY;
    }
}

// Allow crew rename input to receive Japanese letters
HOOK_METHOD(CrewEquipBox, constructor, (Point pos, ShipManager *ship, int slot) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewEquipBox::constructor -> Begin (Misc.cpp)\n")
    super(pos, ship, slot);
    if (CustomOptionsManager::GetInstance()->allowRenameInputSpecialCharacters.currentValue)
    {
        nameInput.allowedChars = TextInput::ALLOW_ANY;
    }
}

//////////////////////////////////////////////////
//////////////// RenderEvents.cpp ////////////////
//////////////////////////////////////////////////

/** All the hook code for the various RenderEvents belongs here **/

HOOK_METHOD(MainMenu, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::OnRender -> Begin (Misc.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::MAIN_MENU, 0);
    if (idx >= 0) super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::MAIN_MENU, std::abs(idx), 0);
}

HOOK_METHOD(CommandGui, RenderStatic, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::RenderStatic -> Begin (Misc.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::GUI_CONTAINER, 0);
    if (idx >= 0) super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::GUI_CONTAINER, std::abs(idx), 0);
}

HOOK_METHOD(SpaceManager, OnRenderBackground, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::OnRenderBackground -> Begin (Misc.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::LAYER_BACKGROUND, 0);
    if (idx >= 0) super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::LAYER_BACKGROUND, std::abs(idx), 0);
}

HOOK_METHOD(SpaceManager, OnRenderForeground, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::OnRenderForeground -> Begin (Misc.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::LAYER_FOREGROUND, 0);
    if (idx >= 0) super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::LAYER_FOREGROUND, std::abs(idx), 0);
}

HOOK_METHOD(SpaceManager, OnRenderAsteroids, (int layers, float alpha) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::OnRenderAsteroids -> Begin (Misc.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(layers == 3 ? RenderEvents::LAYER_ASTEROIDS : RenderEvents::LAYER_FRONT, 0);
    if (idx >= 0) super(layers, alpha);
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(layers == 3 ? RenderEvents::LAYER_ASTEROIDS : RenderEvents::LAYER_FRONT, std::abs(idx), 0);
}

HOOK_METHOD(CommandGui, RenderPlayerShip, (Point &shipCenter, float jumpScale) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::RenderPlayerShip -> Begin (Misc.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::LAYER_PLAYER, 0);
    if (idx >= 0) super(shipCenter, jumpScale);
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::LAYER_PLAYER, std::abs(idx), 0);
}
//Room anim layer 0
HOOK_METHOD(Ship, OnRenderFloor, (bool experimental) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnRenderFloor -> Begin (Misc.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShip, 0);
    lua_pushboolean(context->GetLua(), experimental);

    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::SHIP_FLOOR, 2);
    if (idx >= 0) super(experimental);
    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SHIP_FLOOR, std::abs(idx), 2);
    
    lua_pop(context->GetLua(), 2);
}

//Room anim layer 1
HOOK_METHOD(Ship, OnRenderBreaches, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnRenderBreaches -> Begin (Misc.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShip, 0);

    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::SHIP_BREACHES, 1);
    if (idx >= 0) super();
    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SHIP_BREACHES, std::abs(idx), 1);

    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(CompleteShip, OnRenderShip, (bool unk1, bool unk2) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CompleteShip::OnRenderShip -> Begin (Misc.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), &(shipManager->ship), context->getLibScript()->types.pShip, 0);
    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::SHIP, 1);
    if (idx >= 0) super(unk1, unk2);
    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SHIP, std::abs(idx), 1);
    lua_pop(context->GetLua(), 1);
}

//Room anim layer 2
HOOK_METHOD(Ship, OnRenderSparks, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnRenderSparks -> Begin (Misc.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShip, 0);

    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::SHIP_SPARKS, 1);
    if (idx >= 0) super();
    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SHIP_SPARKS, std::abs(idx), 1);

    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(CrewMember, OnRenderHealth, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::OnRenderHealth -> Begin (Misc.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pCrewMember, 0);

    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::CREW_MEMBER_HEALTH, 1);
    if (idx >= 0) super();
    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::CREW_MEMBER_HEALTH, std::abs(idx), 1);

    lua_pop(context->GetLua(), 1);
}

//Room anim layers 3 and 4
HOOK_METHOD(ShipManager, OnRender, (bool showInterior, bool doorControlMode) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnRender -> Begin (Misc.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    lua_pushboolean(context->GetLua(), showInterior);
    lua_pushboolean(context->GetLua(), doorControlMode);

    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::SHIP_MANAGER, 3);
    if (idx >= 0) super(showInterior, doorControlMode);
    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SHIP_MANAGER, std::abs(idx), 3);
    
    lua_pop(context->GetLua(), 3);
}

HOOK_METHOD(Ship, OnRenderJump, (float progress) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnRenderJump -> Begin (Misc.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShip, 0);
    lua_pushnumber(context->GetLua(), progress);

    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::SHIP_JUMP, 2);
    if (idx >= 0) super(progress);
    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SHIP_JUMP, std::abs(idx), 2);

    lua_pop(context->GetLua(), 2);
}

HOOK_METHOD(FTLButton, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> FTLButton::OnRender -> Begin (Misc.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::FTL_BUTTON, 0);
    if (idx >= 0) super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::FTL_BUTTON, std::abs(idx), 0);
}

HOOK_METHOD(MouseControl, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MouseControl::OnRender -> Begin (Misc.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::MOUSE_CONTROL, 0);
    if (idx >= 0) super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::MOUSE_CONTROL, std::abs(idx), 0);
}
