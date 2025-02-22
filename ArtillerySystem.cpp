#include "ArtillerySystem.h"
#include "CustomOptions.h"
#include "SystemBox_Extend.h"
#include <boost/lexical_cast.hpp>

HOOK_METHOD(ArtillerySystem, Jump, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ArtillerySystem::Jump -> Begin (ArtillerySystem.cpp)\n")
    super();

    // fixes exploits and potential crash bugs with artillery when jumping while firing
    projectileFactory->ClearAiming();
    projectileFactory->ClearProjectiles();
}

static Point baseOffset(22, -5);
static bool g_YPosIsFixed = false;

void ParseTargetableArtilleryNode(rapidxml::xml_node<char>* node)
{
    CustomOptionsManager* customOptions = CustomOptionsManager::GetInstance();

    if (node->first_attribute("enabled"))
    {
        auto enabled = node->first_attribute("enabled")->value();
        customOptions->targetableArtillery.defaultValue = EventsParser::ParseBoolean(enabled);
        customOptions->targetableArtillery.currentValue = EventsParser::ParseBoolean(enabled);
    }

    if (node->first_attribute("xOffset")) baseOffset.x += boost::lexical_cast<int>(node->first_attribute("xOffset")->value());
    if (node->first_attribute("yOffset")) baseOffset.y += boost::lexical_cast<int>(node->first_attribute("yOffset")->value());
    if (node->first_attribute("fixedYPos")) g_YPosIsFixed = EventsParser::ParseBoolean(node->first_attribute("fixedYPos")->value());
}

HOOK_METHOD(ArtilleryBox, constructor, (Point pos, ArtillerySystem* sys) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ArtilleryBox::constructor -> Begin (ArtillerySystem.cpp)\n")
    super(pos, sys);

    SystemBox_Extend* extend = SB_EX(this);
    extend->artilleryButton.OnInit("systemUI/artilleryButton", location);
    extend->artilleryButton.hitbox.w = 17;
    extend->artilleryButton.hitbox.h = 19;
    extend->isArtillery = true;
    extend->offset = baseOffset;
}

static int g_ShipSystem__RenderPowerBoxes_return;

HOOK_METHOD(ShipSystem, RenderPowerBoxes, (int x, int y, int width, int height, int gap, int heightMod, bool flash) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::RenderPowerBoxes -> Begin (ArtillerySystem.cpp)\n")
    int ret = super(x, y, width, height, gap, heightMod, flash);
    g_ShipSystem__RenderPowerBoxes_return = ret;
    return ret;
}

HOOK_METHOD(ArtilleryBox, OnRender, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ArtilleryBox::OnRender -> Begin (ArtillerySystem.cpp)\n")
    super(ignoreStatus);
    if (CustomOptionsManager::GetInstance()->targetableArtillery.currentValue || pSystem->_shipObj.HasAugmentation("ARTILLERY_ORDER"))
    {
        SystemBox_Extend* extend = SB_EX(this);
        extend->artilleryButton.bActive = artSystem->Functioning();
        ProjectileFactory* armedWeapon = G_->GetCApp()->gui->combatControl.weapControl.armedWeapon;
        extend->artilleryButton.bRenderSelected = armedWeapon == artSystem->projectileFactory;
        extend->offset.y = g_YPosIsFixed ? baseOffset.y : baseOffset.y + g_ShipSystem__RenderPowerBoxes_return - 265;

        CSurface::GL_Translate(extend->offset.x, extend->offset.y);
        extend->artilleryButton.OnRender();
        CSurface::GL_Translate(-extend->offset.x, -extend->offset.y);
        if (extend->artilleryButton.Hovering())
        {
            //TODO: Use GetOverrideTooltip (Not working)
            TextString tooltip = artSystem->projectileFactory->blueprint->desc.tooltip; 
            G_->GetMouseControl()->SetTooltip(tooltip.GetText());
        }
    }
}

HOOK_METHOD(SystemBox, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::MouseMove -> Begin (ArtillerySystem.cpp)\n")
    super(x, y);
    if (CustomOptionsManager::GetInstance()->targetableArtillery.currentValue || pSystem->_shipObj.HasAugmentation("ARTILLERY_ORDER"))
    {
        SystemBox_Extend* extend = SB_EX(this);
        if (extend->isArtillery) extend->artilleryButton.MouseMove(x - extend->offset.x, y - extend->offset.y, false);
    }
}

void CombatControl::ArmArtillery(ArtillerySystem* artillerySystem)
{
    ProjectileFactory* artilleryWeapon = artillerySystem->projectileFactory;
    artilleryWeapon->ClearAiming();
    weapControl.armedWeapon = artilleryWeapon;
    weapControl.armedSlot = -1;
    UpdateAiming();
}

HOOK_METHOD(CombatControl, KeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::KeyDown -> Begin (ArtillerySystem.cpp)\n")
    super(key);
    const auto& artillerySystems = shipManager->artillerySystems;
    bool targetableArtillery = CustomOptionsManager::GetInstance()->targetableArtillery.currentValue || shipManager->HasAugmentation("ARTILLERY_ORDER");
    if (key == Settings::GetHotkey("artillery1") && artillerySystems.size() >= 1 && targetableArtillery)
    {
        ArmArtillery(artillerySystems[0]);
    }
    else if (key == Settings::GetHotkey("artillery2") && artillerySystems.size() >= 2 && targetableArtillery)
    {
        ArmArtillery(artillerySystems[1]);
    }
    else if (key == Settings::GetHotkey("artillery3") && artillerySystems.size() >= 3 && targetableArtillery)
    {
        ArmArtillery(artillerySystems[2]);
    }
    else if (key == Settings::GetHotkey("artillery4") && artillerySystems.size() >= 4 && targetableArtillery)
    {
        ArmArtillery(artillerySystems[3]);
    }
}

HOOK_METHOD(SystemBox, MouseClick, (bool shift) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::MouseClick -> Begin (ArtillerySystem.cpp)\n")
    bool ret = super(shift);

    bool targetableArtillery = CustomOptionsManager::GetInstance()->targetableArtillery.currentValue || pSystem->_shipObj.HasAugmentation("ARTILLERY_ORDER");
    SystemBox_Extend* extend = SB_EX(this);
    if (extend->isArtillery && targetableArtillery && extend->artilleryButton.Hovering())
    {  
        ArtillerySystem* artillerySystem = static_cast<ArtillerySystem*>(pSystem);
        G_->GetCApp()->gui->combatControl.ArmArtillery(artillerySystem);
    }
    return ret;
}

void ArtillerySystem::OnLoop_HS_ManualTarget()
{
    ShipSystem::OnLoop();
    int power = GetEffectivePower();
    projectileFactory->powered = power > 0; //TODO: Hook SetPowered
    projectileFactory->SetCooldownModifier(1.5f - 0.25f * power);
    projectileFactory->Update();
    projectileFactory->SetCurrentShip(target);
  
    /* Begin: inline int GetHackLevel(ShipSystem * this) */
    int iHacked = bUnderAttack ? iHackEffect : 0;
    projectileFactory->SetHacked(iHacked);
    projectileFactory->isArtillery = true;
    /*
    if (projectileFactory->ReadyToFire()) 
    {
        if (target->IsCloaked()) return;
        //Vanilla code would have automatic targetting and firing here, instead manual firing is handled through WeaponControl
    
    
    }
    */
}
HOOK_METHOD_PRIORITY(ArtillerySystem, OnLoop, 9998, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ArtillerySystem::OnLoop -> Begin (CustomWeapons.cpp)\n")
    if (_shipObj.iShipId == 0 && (CustomOptionsManager::GetInstance()->targetableArtillery.currentValue || _shipObj.HasAugmentation("ARTILLERY_ORDER")))
    {
        OnLoop_HS_ManualTarget();
    }
    else
    {
        super();
    }
}

HOOK_METHOD(WeaponControl, SetAutofiring, (bool on, bool simple) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::SetAutofiring -> Begin (CustomWeapons.cpp)\n")
    
    super(on, simple);

    ShipManager* ship = G_->GetShipManager(0);
    if (CustomOptionsManager::GetInstance()->targetableArtillery.currentValue || ship->HasAugmentation("ARTILLERY_ORDER"))
    {
        for (auto arti : ship->artillerySystems)
        {
            arti->projectileFactory->SetAutoFire(autoFiring);
        }
    }
}
