#ifndef RENDEREVENTS_H
#define RENDEREVENTS_H

struct RenderEvents
{
    // DO NOT FORGET TO UPDATE RenderEventNames as well
    enum Identifiers {
        UNKNOWN, // Must always be first, used to check for bounds of enum input value

        ////LANGUAGE_CHOOSER, // LanguageChooser::OnRender
        MAIN_MENU, // MainMenu::OnRender
        GUI_CONTAINER, // CommandGui::RenderStatic
        LAYER_BACKGROUND, // SpaceManager::OnRenderBackground
        LAYER_FOREGROUND, // SpaceManager::OnRenderForeground
        LAYER_ASTEROIDS, // SpaceManager::OnRenderAsteroids with Layer 3
        LAYER_PLAYER, // CommandGui::RenderPlayerShip (before)
        SHIP, // CompleteShip::OnRenderShip (affects enemy too), NOTE: We probably want a ENEMY_SHIP render instead of just SHIP, Might be able to trigger from the hook in `CombatControl::RenderTarget` or `CombatControl::OnRenderCombat`?
        ////PLAYER_SHIP_PROJECTILES_BACKGROUND, // SpaceManager::OnRenderProjectiles with Layer 2 (before ship), NOTE: We may wish to split this out into PLAYER_SHIP_PROJECTILES_BACKGROUND & ENEMY_SHIP_PROJECTILES_BACKGROUND
        ////PLAYER_SHIP_PROJECTILES_FOREGROUND, // SpaceManager::OnRenderProjectiles with Lyaer 1 (after ship), NOTE: We may wish to split this out into PLAYER_SHIP_PROJECTILES_FOREGROUND & ENEMY_SHIP_PROJECTILES_FOREGROUND
        SHIP_MANAGER, // ShipManager::OnRender (note, has some details about showInterior & doorControlMode that might be important)
        ////PROJECTILE, // Projectile::OnRender
        ////SHIP_MANAGER_WEAPONS, // ShipManager::RenderWeapons
        SHIP_JUMP, // Ship::OnRenderJump
        ////SHEILDS_BASE, // Shields::OnRenderBaseShield
        ////SHIP_BASE, // Ship::OnRenderBase
        SHIP_HULL, // Inside Ship::OnRenderBase
        SHIP_ENGINES, //Inside Ship::OnRenderBase (Engine animation)
        SHIP_FLOOR, // Ship::OnRenderFloor
        ////SHIP_FLOOR_EFFECTS, // Ship::OnRenderFloorEffects
        ////SHIP_SYSTEM, // Ship::OnRenderSystem, might need to do a separate PLAYER & ENEMY version or pass that info maybe
        SHIP_BREACHES, // Ship::OnRenderBreaches
        ////FIRE_SPREADER, // Spreader<Fire>::OnRender
        ////PARTICLE_EMITTER, // ParticleEmitter::OnRender
        ////SHIP_BLACKOUT, // Ship::OnRenderBlackout
        ////CREW_MEMBER_PATH, // CrewMember::OnRenderPath
        ////SHIP_HIGHLIGHT, // Ship::OnRenderHighlight
        ////SHIP_WALLS, // Ship::OnRenderWalls
        SHIP_SPARKS, // Ship::OnRenderSparks
        CREW_MEMBER_HEALTH, // CrewMember::OnRenderHealth
        ////ANIMATION, // Animation::OnRender, we'll definetly have to pass something or make completely different events for this one to allow hooking animations where important, maybe we don't allow this one at all?
        ////DAMAGE_MESSAGE, // DamageMessage::OnRender
        ////SHIELDS_DAMAGE_MESSAGES, // Shields::OnRenderDamageMessages
        ////SHIP_EXPLOSION, // Ship::OnRenderExplosion
        //SELF_AIMING, // CombatControl::OnRenderSelfAiming
        //////LAYER_PLAYERFRONT, // CommandGui::RenderPlayerShip (after) (You can just use the after method of LAYER_PLAYER for now)
        LAYER_FRONT, // SpaceManager::OnRenderAsteroids with Layer 1 (after player ship is rendered)
        FTL_BUTTON, // FTLButton::OnRender
        ////BUTTON, // Button::OnRender
        ////WARNING_MESSAGE, // WarningMessage::OnRender
        ////TEXT_BUTTON, // TextButton::OnRender
        //COMBAT_CONTROL_COMBAT, // CombatControl::OnRenderCombat could be used with SHIP to determine we're rendering an enemy ship (or to provide a ENEMY_SHIP) render method
        //CREW_CONTROL, // CrewControl::OnRender
        //SYSTEM_CONTROL, // SystemControl::OnRender
        //COMBAT_CONTROL_INTERFACE, // CombatControl::OnRenderInterface
        ////PAUSE, // CommandGui::RenderPause (not hooked yet)
        SPACE_STATUS, // SpaceStatus::OnRender
        //SHIP_STATUS, // ShipStatus::OnRender
        ////CONFIRM_WINDOW, // ConfirmWindow::OnRender, TODO: Might need to pass which window it is
        ////CHOICE_BOX, // ChoiceBox::OnRender, TODO: Might need to pass which choice it is
        
        ////ACHIEVEMENT_TRACKER, // AchievementTracker::OnRender (not hooked yet)
        MOUSE_CONTROL, // MouseControl::OnRender
        ////FPS, // CFPS::OnRender (not hooked yet)
        
        ////SHIELD_BASE, // Shields::RenderBase

        UNKNOWN_MAX // Must always be last, used to check for bounds of enum input value
    };
};

// You update RenderEvents and not this with a code change and YOU_WILL_BE_FIRED
constexpr const char* RenderEventNames[] = {
    "UNKNOWN",
    "MAIN_MENU",
    "GUI_CONTAINER",
    "LAYER_BACKGROUND",
    "LAYER_FOREGROUND",
    "LAYER_ASTEROIDS",
    "LAYER_PLAYER",
    "SHIP",
    "SHIP_MANAGER",
    "SHIP_JUMP",
    "SHIP_HULL",
    "SHIP_ENGINES",
    "SHIP_FLOOR",
    "SHIP_BREACHES",
    "SHIP_SPARKS",
    "CREW_MEMBER_HEALTH",
    "LAYER_FRONT",
    "FTL_BUTTON",
    "SPACE_STATUS",
    "MOUSE_CONTROL",
    "UNKNOWN_MAX",
}

#endif // RENDEREVENTS_H
