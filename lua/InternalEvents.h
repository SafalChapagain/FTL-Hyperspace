#ifndef INTERNALEVENTS_H
#define INTERNALEVENTS_H

/**
    Internal Event enumerations
    Used for specifying a name to Lua that Lua can access via `Defines.InternalEvents.ON_TICK` (or other name in the Defines.InternalEvents table)
    And for specifying a name to C in our hooks (defined in InternalEvents.cpp right now but they could technically be called from anywhere)
    Eventually will include argument data for Lua to specify what we expect to send to and receive from Lua hooks

    You can have more than one actual C ZHL hook calling the same identifier (such as we would do for START_RUN, although currently that is handled by `scripts.on_init(` but maybe we accomplish that with an internal event instead and clean it up)
*/
struct InternalEvents
{
    enum Identifiers {
        UNKNOWN, // Must always be first, used to check for bounds of enum input value

        // function on_tick()
        ON_TICK, // We'll use CApp::OnLoop for this ticking
        // function main_menu()
        MAIN_MENU, // We'll use MainMenu::Open for this

        // function get_run_seed(bool isCustomSeed, int seed) return isCustomSeed, seed
        GET_RUN_SEED,
        
        // function on_key_down(SDLKey key) return Chain
        ON_KEY_DOWN,
        // function on_key_up(SDLKey key) return Chain
        ON_KEY_UP,
        // function on_mouse_move(int x, int y, int xdiff, int ydiff, bool holdingLMB, bool holdingRMB, bool holdingMMB) return Chain
        ON_MOUSE_MOVE,
        // function on_mouse_l_button_down(int x, int y) return Chain
        ON_MOUSE_L_BUTTON_DOWN,
        // function on_mouse_l_button_up(int x, int y) return Chain
        ON_MOUSE_L_BUTTON_UP,
        // function on_mouse_r_button_down(int x, int y) return Chain
        ON_MOUSE_R_BUTTON_DOWN,
        // function on_mouse_r_button_up(int x, int y) return Chain
        ON_MOUSE_R_BUTTON_UP,
        // function on_mouse_m_button_down(int x, int y) return Chain
        ON_MOUSE_M_BUTTON_DOWN,
        // function gui_move_move(int x, int y) return Chain
        GUI_MOUSE_MOVE,
        
        // function crew_loop(CrewMember& crew)
        CREW_LOOP,
        // function ship_loop(ShipManager& ship)
        SHIP_LOOP,

        // function has_equipment(ShipManager& ship, char* equipment, int value) return Chain, value
        HAS_EQUIPMENT,
        // function has_augmentation(ShipManager& ship, char* augment, int value) return Chain, value
        HAS_AUGMENTATION,
        // function get_augmentation_value(ShipManager& ship, char* augment, float value) return Chain, value
        GET_AUGMENTATION_VALUE,

        // function get_dodge_factor(ShipManager& ship, int value) return Chain, value
        GET_DODGE_FACTOR,

        // function set_bonus_power(ShipSystem& system, int amount) return Chain, amount
        SET_BONUS_POWER,

        // function set_armament_pre(uint armamentSlot) return Chain, armamentSlot
        SELECT_ARMAMENT_PRE,
        // function set_armament_post(uint armamentSlot)
        SELECT_ARMAMENT_POST,

        // function projectile_initialize(Projectile& projectile, WeaponBlueprint &bp)
        PROJECTILE_INITIALIZE,
        // function projectile_fire(Projectile& projectile, ProjectileFactory &weapon)
        PROJECTILE_FIRE,
        // function projectile_pre(Projectile& projectile) return Chain
        PROJECTILE_PRE, // SpaceManager::UpdateProjectile
        // function projectile_post(Projectile& projectile, bool preempted) return Chain
        PROJECTILE_POST, // SpaceManager::UpdateProjectile
        // function projectile_update_pre(Projectile& projectile) return Chain
        PROJECTILE_UPDATE_PRE, // Projectile::Update
        // function projectile_update_post(Projectile& projectile, bool preempted) return Chain
        PROJECTILE_UPDATE_POST, // Projectile::Update

        // function weapon_statbox(WeaponBlueprint& bp, char* stats) return stats
        WEAPON_STATBOX,
        // function weapon_descbox(WeaponBlueprint& bp, char* desc) return desc
        WEAPON_DESCBOX,
        // function weapon_renderbox(ProjectileFactory& weapon, int cooldown, int maxCooldown, char* firstLine, char* secondLine) return Chain, firstLine, secondLine
        WEAPON_RENDERBOX,

        //function drone_fire(Projectile& projectile, SpaceDrone& spacedrone) return Chain
        DRONE_FIRE,

        // function drone_collision(SpaceDrone& drone, Projectile& projectile, Damage& damage, CollisionResponse& response) return Chain
        DRONE_COLLISION,
        // function projectile_collision(Projectile& thisProjectile, Projectile& otherProjectile, Damage& damage, CollisionResponse& response) return Chain
        PROJECTILE_COLLISION, // thisProjectile is the projectile being collided into
        // function shield_collision_pre(ShipManager& ship, Projectile& projectile, Damage& damage, CollisionResponse& response) return Chain
        SHIELD_COLLISION_PRE,
        // function shield_collision(ShipManager& ship, Projectile& projectile, Damage& damage, CollisionResponse& response) return Chain
        SHIELD_COLLISION,
        // function damage_area(ShipManager& ship, Projectile& projectile, Pointf& location, Damage& damage, Evasion forceHit, bool shipFriendlyFire) return Chain, forceHit, shipFriendlyFire
        DAMAGE_AREA,
        // function damage_area_hit(ShipManager& ship, Projectile& projectile, Pointf& location, Damage& damage, bool shipFriendlyFire) return Chain
        DAMAGE_AREA_HIT,
        // function damage_beam(ShipManager& ship, Projectile& projectile, Pointf& location, Damage& damage, bool newTile, BeamHit beamHit) return Chain, beamHit
        DAMAGE_BEAM,
        // function damage_system(ShipManager& ship, Projectile& projectile, int roomId, Damage& damage) return Chain
        DAMAGE_SYSTEM,
        // function system_add_damage(ShipSystem& sys, Projectile& projectile, int amount) return Chain, amount
        SYSTEM_ADD_DAMAGE,

        // function activate_power(ActivatedPower& power, ShipManager& ship) return Chain
        ACTIVATE_POWER,
        // function prepare_power(ActivatedPower& power) return Chain
        PREPARE_POWER,
        // function cancel_power(ActivatedPower& power, bool clearAnim) return Chain
        CANCEL_POWER,
        // function power_on_update(ActivatedPower& power) return Chain
        POWER_ON_UPDATE,
        // function power_resource_on_update(ActivatedPowerResource& power) return Chain
        POWER_RESOURCE_ON_UPDATE,
        // function power_enable_init(ActivatedPower& power) return Chain
        POWER_ENABLE_INIT,
        // function power_resource_enable_init(ActivatedPowerResource& power) return Chain
        POWER_RESOURCE_ENABLE_INIT,
        // function power_req(ActivatedPower& power, ActivatedPowerRequirements& req, PowerReadyState result) return Chain, result
        POWER_REQ,
        // function power_ready(ActivatedPower& power, PowerReadyState result) return Chain, result
        POWER_READY,
        // function power_tooltip(ActivatedPower& power, PowerReadyState state) return tooltip, skipAppend
        POWER_TOOLTIP,

        // function generator_create_ship(char* name, int sector, ShipEvent &event, ShipBlueprint &bp, ShipManager *ret) return Chain, sector, event, bp, ret
        GENERATOR_CREATE_SHIP,
        // function generator_create_ship_post(char* name, int sector, ShipEvent &event, ShipBlueprint &bp, ShipManager *ret) return Chain
        GENERATOR_CREATE_SHIP_POST,
        // function pre_create_choicebox(LocationEvent &event)
        PRE_CREATE_CHOICEBOX,
        // function post_create_choicebox(choiceBox &choiceBox, LocationEvent &event)
        POST_CREATE_CHOICEBOX,
        // function tabbed_window_confirm(currentTab)
        TABBED_WINDOW_CONFIRM,
        // function tabbed_window_undo(currentTab)
        TABBED_WINDOW_UNDO,

        // CREW_EQUIPMENT_BOX_REMOVE_ITEM, // CrewEquipBox::RemoveItem

        /*
        Once we support return values from InternalEvents (or maybe this moves to an InternalHooks in the future)
        Called upon hull damage to the player's ship
        @tparam int shipId the ID of the ship for now...
        @tparam int damage intended hull damage, negative values infer healing
        @treturn uint value of the hull, 0 and the ship explodes.
        // PLAYERSHIP_ON_HULL_DAMAGE,
        */
        // function jump_arrive(ShipManager& ship)
        JUMP_ARRIVE,
        // function jump_leave(ShipManager& ship)
        JUMP_LEAVE,
        // function on_wait(ShipManager& ship)
        ON_WAIT,


        //Constructor Events

        //function construct_crewmember(CrewMember& crew)
        CONSTRUCT_CREWMEMBER,
        //function construct_spacedrone(SpaceDrone& drone)
        CONSTRUCT_SPACEDRONE,
        //function construct_projectile_factory(ProjectileFactory& weapon)
        CONSTRUCT_PROJECTILE_FACTORY,
        //function construct_projectile(Projectile& projectile)
        CONSTRUCT_PROJECTILE,
        //function construct_room(Room& room)
        CONSTRUCT_ROOM,
        //function construct_ship_manager(ShipManager& ship)
        CONSTRUCT_SHIP_MANAGER,
        //function construct_ship_system(ShipSystem& system)
        CONSTRUCT_SHIP_SYSTEM,

        UNKNOWN_MAX // Must always be last, used to check for bounds of enum input value
    };
};

// TODO: Maybe we store an array using the Identifiers as the index and store the additional call data in there? Like number of arguments etc...?
/* Example
// NOTE: Should exclude/ignore this from Lua (defines.i) so that the CallData is not available
struct InternalEvent_CallData {
    unsigned int argCount;
    bool isVariableArgs;
}
static InternalEvent_CallData CallData[InternalEvents::UNKNOWN_MAX - 1];
CallData[ON_TICK] = { 0, false };
};
*/

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
