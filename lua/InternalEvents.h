#ifndef INTERNALEVENTS_H
#define INTERNALEVENTS_H

#include "EventEnums.h"
/**
    Internal Event enumerations
    Used for specifying a name to Lua that Lua can access via `Defines.InternalEvents.ON_TICK` (or other name in the Defines.InternalEvents table)
    And for specifying a name to C in our hooks (defined in InternalEvents.cpp right now but they could technically be called from anywhere)
    Eventually will include argument data for Lua to specify what we expect to send to and receive from Lua hooks

    You can have more than one actual C ZHL hook calling the same identifier (such as we would do for START_RUN, although currently that is handled by `scripts.on_init(` but maybe we accomplish that with an internal event instead and clean it up)
*/
struct InternalEvents
{
    NAMED_ENUM(Identifiers,
        UNKNOWN,
        ON_TICK,
        MAIN_MENU,
        GET_RUN_SEED,
        ON_KEY_DOWN,
        ON_KEY_UP,
        ON_MOUSE_MOVE,
        ON_MOUSE_L_BUTTON_DOWN,
        ON_MOUSE_L_BUTTON_UP,
        ON_MOUSE_R_BUTTON_DOWN,
        ON_MOUSE_R_BUTTON_UP,
        ON_MOUSE_M_BUTTON_DOWN,
        GUI_MOUSE_MOVE,
        CREW_LOOP,
        SHIP_LOOP,
        HAS_EQUIPMENT,
        HAS_AUGMENTATION,
        GET_AUGMENTATION_VALUE,
        GET_DODGE_FACTOR,
        SET_BONUS_POWER,
        SELECT_ARMAMENT_PRE,
        SELECT_ARMAMENT_POST,
        PROJECTILE_INITIALIZE,
        PROJECTILE_FIRE,
        PROJECTILE_PRE,
        PROJECTILE_POST,
        PROJECTILE_UPDATE_PRE,
        PROJECTILE_UPDATE_POST,
        WEAPON_STATBOX,
        WEAPON_DESCBOX,
        WEAPON_RENDERBOX,
        DRONE_FIRE,
        DRONE_COLLISION,
        PROJECTILE_COLLISION,
        SHIELD_COLLISION_PRE,
        SHIELD_COLLISION,
        DAMAGE_AREA,
        DAMAGE_AREA_HIT,
        DAMAGE_BEAM,
        DAMAGE_SYSTEM,
        SYSTEM_ADD_DAMAGE,
        ACTIVATE_POWER,
        PREPARE_POWER,
        CANCEL_POWER,
        POWER_ON_UPDATE,
        POWER_RESOURCE_ON_UPDATE,
        POWER_ENABLE_INIT,
        POWER_RESOURCE_ENABLE_INIT,
        POWER_REQ,
        POWER_READY,
        POWER_TOOLTIP,
        GENERATOR_CREATE_SHIP,
        GENERATOR_CREATE_SHIP_POST,
        PRE_CREATE_CHOICEBOX,
        POST_CREATE_CHOICEBOX,
        JUMP_ARRIVE,
        JUMP_LEAVE,
        ON_WAIT,
        CONSTRUCT_CREWMEMBER,
        CONSTRUCT_SPACEDRONE,
        CONSTRUCT_PROJECTILE_FACTORY,
        CONSTRUCT_PROJECTILE,
        CONSTRUCT_ROOM,
        CONSTRUCT_SHIP_MANAGER,
        CONSTRUCT_SHIP_SYSTEM,
        UNKNOWN_MAX
    )
    struct EventInfo
    {
        const char* functionSignatureDescription;
        unsigned int argCount;
        bool isVariableArgs;
    };
    static EventInfo GetEventInfo(Identifiers event)
    {
        static EventInfo eventInfo[Identifiers::UNKNOWN_MAX + 1] = 
        {
            {"n/a", 0, false}, //Must always be first, used to check for bounds of enum input value
            {"function on_tick()", 0, false}, 
            {"function main_menu()", 0, false}, 
            {"function get_run_seed(bool isCustomSeed, int seed) return isCustomSeed, seed", 2, false}, 
            {"function on_key_down(SDLKey key) return Chain", 1, false}, 
            {"function on_key_up(SDLKey key) return Chain", 1, false}, 
            {"function on_mouse_move(int x, int y, int xdiff, int ydiff, bool holdingLMB, bool holdingRMB, bool holdingMMB) return Chain", 7, false}, 
            {"function on_mouse_l_button_down(int x, int y) return Chain", 2, false}, 
            {"function on_mouse_l_button_up(int x, int y) return Chain", 2, false},
            {"function on_mouse_r_button_down(int x, int y) return Chain", 2, false},
            {"function on_mouse_r_button_up(int x, int y) return Chain", 2, false},
            {"function on_mouse_m_button_down(int x, int y) return Chain", 2, false},
            {"function gui_move_move(int x, int y) return Chain", 2, false},
            {"function crew_loop(CrewMember& crew)", 1, false},
            {"function ship_loop(ShipManager& ship)", 1, false},
            {"function has_equipment(ShipManager& ship, char* equipment, int value) return Chain, value", 3, false},
            {"function has_augmentation(ShipManager& ship, char* augment, int value) return Chain, value", 3, false},
            {"function get_augmentation_value(ShipManager& ship, char* augment, float value) return Chain, value", 3, false},
            {"function get_dodge_factor(ShipManager& ship, int value) return Chain, value", 2, false},
            {"function set_bonus_power(ShipSystem& system, int amount) return Chain, amount", 2, false},
            {"function set_armament_pre(uint armamentSlot) return Chain, armamentSlot", 2, false},
            {"function set_armament_post(uint armamentSlot)", 1, false},
            {"function projectile_initialize(Projectile& projectile, WeaponBlueprint &bp)", 2, false},
            {"function projectile_fire(Projectile& projectile, ProjectileFactory &weapon)", 2, false},
            {"function projectile_pre(Projectile& projectile) return Chain", 1, false},
            {"function projectile_post(Projectile& projectile, bool preempted) return Chain", 2, false},
            {"function projectile_update_pre(Projectile& projectile) return Chain", 1, false},
            {"function projectile_update_post(Projectile& projectile, bool preempted) return Chain", 2, false},
            {"function weapon_statbox(WeaponBlueprint& bp, char* stats) return stats", 2, false},
            {"function weapon_descbox(WeaponBlueprint& bp, char* desc) return desc", 2, false},
            {"function weapon_renderbox(ProjectileFactory& weapon, int cooldown, int maxCooldown, char* firstLine, char* secondLine) return Chain, firstLine, secondLine", 4, false},
            {"function drone_fire(Projectile& projectile, SpaceDrone& spacedrone) return Chain", 2, false},
            {"function drone_collision(SpaceDrone& drone, Projectile& projectile, Damage& damage, CollisionResponse& response) return Chain", 4, false},
            {"function projectile_collision(Projectile& thisProjectile, Projectile& otherProjectile, Damage& damage, CollisionResponse& response) return Chain", 4, false},
            {"function shield_collision_pre(ShipManager& ship, Projectile& projectile, Damage& damage, CollisionResponse& response) return Chain", 4, false},
            {"function shield_collision(ShipManager& ship, Projectile& projectile, Damage& damage, CollisionResponse& response) return Chain", 4, false},
            {"function damage_area(ShipManager& ship, Projectile& projectile, Pointf& location, Damage& damage, Evasion forceHit, bool shipFriendlyFire) return Chain, forceHit, shipFriendlyFire", 6, false},
            {"function damage_area_hit(ShipManager& ship, Projectile& projectile, Pointf& location, Damage& damage, bool shipFriendlyFire) return Chain", 5, false},
            {"function damage_beam(ShipManager& ship, Projectile& projectile, Pointf& location, Damage& damage, bool newTile, BeamHit beamHit) return Chain, beamHit", 6, false},
            {"function damage_system(ShipManager& ship, Projectile& projectile, int roomId, Damage& damage) return Chain", 4, false},
            {"function system_add_damage(ShipSystem& sys, Projectile& projectile, int amount) return Chain, amount", 3, false},
            {"function activate_power(ActivatedPower& power, ShipManager& ship) return Chain", 2, false},
            {"function prepare_power(ActivatedPower& power) return Chain", 1, false},
            {"function cancel_power(ActivatedPower& power, bool clearAnim) return Chain", 2, false},
            {"function power_on_update(ActivatedPower& power) return Chain", 1, false},
            {"function power_resource_on_update(ActivatedPowerResource& power) return Chain", 1, false},
            {"function power_enable_init(ActivatedPower& power) return Chain", 1, false},
            {"function power_resource_enable_init(ActivatedPowerResource& power) return Chain", 1, false},
            {"function power_req(ActivatedPower& power, ActivatedPowerRequirements& req, PowerReadyState result) return Chain, result", 3, false},
            {"function power_ready(ActivatedPower& power, PowerReadyState result) return Chain, result", 2, false},
            {"function power_tooltip(ActivatedPower& power, PowerReadyState state) return tooltip, skipAppend", 2, false},
            {"function generator_create_ship(char* name, int sector, ShipEvent &event, ShipBlueprint &bp, ShipManager *ret) return Chain, sector, event, bp, ret", 5, false},
            {"function generator_create_ship_post(char* name, int sector, ShipEvent &event, ShipBlueprint &bp, ShipManager *ret) return Chain", 5, false},
            {"function pre_create_choicebox(LocationEvent &event)", 1, false},
            {"function post_create_choicebox(choiceBox &choiceBox, LocationEvent &event)", 2, false},
            {"function jump_arrive(ShipManager& ship)", 1, false},
            {"function jump_leave(ShipManager& ship)", 1, false},
            {"function on_wait(ShipManager& ship)", 1, false},
            {"function construct_crewmember(CrewMember& crew) return Chain", 1, false},
            {"function construct_spacedrone(SpaceDrone& drone) return Chain", 1, false},
            {"function construct_projectile_factory(ProjectileFactory& weapon) return Chain", 1, false},
            {"function construct_projectile(Projectile& projectile) return Chain", 1, false},
            {"function construct_room(Room& room) return Chain", 1, false},
            {"function construct_ship_manager(ShipManager& ship) return Chain", 1, false},
            {"function construct_ship_system(ShipSystem& system) return Chain", 1, false},
            {"n/a", 0, false}, //Must always be last, used to check for bounds of enum input value
        };
        
        return eventInfo[event];
    }; 
};

struct Chain
{
    enum ChainValues {
        CONTINUE, // call the next callback in the sequence if there is one
        HALT,     // halt the callback loop, but still run subsequent C++ code
        PREEMPT   // halt the callback loop and skip subsequent C++ code (implementation specific per internal event)
    };
};

struct Evasion
{
    enum EvasionValues {
        NONE, // indicates evasion still needs to be checked
        HIT,  // force projectile to hit
        MISS  // force projectile to miss
    };
};

struct BeamHit
{
    enum BeamHitValues {
        SAME_TILE, // treat beam hit as same tile as last frame
        NEW_TILE,  // treat beam hit as new tile but same room as last frame
        NEW_ROOM   // treat beam hit as new room from last frame
    };
};
#endif // INTERNALEVENTS_H
