%module Hyperspace
%include "stl.i"
%include "constraints.i"
%include "typemaps.i"
%include "stdint.i"
%{
#include "Global.h"
#include "HSVersion.h"
#include "CustomAchievements.h"
#include "CustomAugments.h"
#include "CustomCrew.h"
#include "CustomEvents.h"
#include "CustomScoreKeeper.h"
#include "CustomShipGenerator.h"
#include "CustomShipSelect.h"
#include "CrewMember_Extend.h"
#include "Projectile_Extend.h"
#include "ShipManager_Extend.h"
#include "System_Extend.h"
#include "Room_Extend.h"
#include "ToggleValue.h"
#include "CommandConsole.h"
#include "StatBoost.h"
#include "ShipUnlocks.h"
#include "CustomShips.h"
%}

%feature("flatnested");

namespace std {
    // shamelessly copied from the SWIG library and modified (the SWIG library code is unrestricted)
    template<class K, class T, class H = std::hash<K>, class E = std::equal_to<K> > class unordered_map {
        // add typemaps here
    public:
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef K key_type;
        typedef T mapped_type;
        typedef std::pair< const K, T > value_type;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef value_type& reference;
        typedef const value_type& const_reference;

        unordered_map();
        unordered_map(const unordered_map& other);

        unsigned int size() const;
        bool empty() const;
        void clear();
        %extend {
            const T& get(const K& key) throw (std::out_of_range) {
                std::unordered_map< K, T, H, E >::iterator i = self->find(key);
                if (i != self->end())
                    return i->second;
                else
                    throw std::out_of_range("key not found");
            }
            void set(const K& key, const T& x) {
                (*self)[key] = x;
            }
            void del(const K& key) throw (std::out_of_range) {
                std::unordered_map< K, T, H, E >::iterator i = self->find(key);
                if (i != self->end())
                    self->erase(i);
                else
                    throw std::out_of_range("key not found");
            }
            bool has_key(const K& key) {
                std::unordered_map< K, T, H, E >::iterator i = self->find(key);
                return i != self->end();
            }
            // more stuff
			const T& __getitem__(const K& key) throw (std::out_of_range)
			{
				std::unordered_map< K, T, H, E >::iterator i = self->find(key);
                if (i != self->end())
                    return i->second;
                else
                    throw std::out_of_range("key not found");
			}
			void __setitem__(const K& key, const T& x)
			{
				(*self)[key] = x;
			}
        }
    };

    // extend the map as well
    %extend map {
        const T& __getitem__(const K& key) throw (std::out_of_range) {
            std::map< K, T, C >::iterator i = self->find(key);
            if (i != self->end())
                return i->second;
            else
                throw std::out_of_range("key not found");
        }
        void __setitem__(const K& key, const T& x) {
            (*self)[key] = x;
        }
    }

    // todo: add std::array

    %template(vector_int) vector<int>;
    %template(vector_float) vector<float>;
    %template(vector_ArtillerySystem) vector<ArtillerySystem*>;
    %template(vector_ProjectileFactory) vector<ProjectileFactory*>;
    %template(vector_CrewMember) vector<CrewMember*>;
    %template(vector_ShipSystem) vector<ShipSystem*>;
    %template(vector_Drone) vector<Drone*>;
    %template(vector_SpaceDrone) vector<SpaceDrone*>;
    %template(vector_Room) vector<Room*>;
	%template(vector_Door) vector<Door*>;
	%template(vector_OuterHull) vector<OuterHull*>;
	%template(vector_WeaponMount) vector<WeaponMount>;
	%template(vector_DamageMessage) vector<DamageMessage*>;
	%template(vector_Projectile) vector<Projectile*>;
	%template(vector_MiniProjectile) vector<WeaponBlueprint::MiniProjectile>;
//	%template(vector_ShieldAnimation) vector<ShieldAnimation>;
    %template(pair_int_int) pair<int, int>;
    %template(pair_float_float) pair<float, float>;
    %template(vector_Pointf) vector<Pointf>;
    %template(vector_Point) vector<Point>;
    %template(map_int_SystemTemplate) map<int,ShipBlueprint::SystemTemplate>;
    %template(unordered_map_string_int) unordered_map<string,int>;
    %template(vector_ActivatedPower) vector<ActivatedPower*>;
    %template(vector_ActivatedPowerResource) vector<ActivatedPowerResource*>;
    %template(unordered_map_unsigned_int_ActivatedPowerResource) unordered_map<unsigned int,ActivatedPowerResource*>;
    %template(pair_CrewExtraCondition_bool) pair<CrewExtraCondition,bool>;
    %template(vector_pair_CrewExtraCondition_bool) vector<pair<CrewExtraCondition,bool>>;
    %template(vector_CrewBlueprint) vector<CrewBlueprint>;
    %template(vector_DroneBlueprint) vector<DroneBlueprint*>;
    %template(vector_WeaponBlueprint) vector<WeaponBlueprint*>;
    %template(vector_pair_int_int) vector<pair<int, int>>;
    %template(vector_TextString) vector<TextString>;
    %template(vector_GL_Color) vector<GL_Color>;
    %template(vector_vector_GL_Color) vector<vector<GL_Color>>;
    %template(vector_CrewDesc) vector<CrewDesc>;
    %template(vector_Fire) vector<Fire>;
    %template(vector_vector_Fire) vector<vector<Fire>>;
    %template(vector_CrewPlacementDefinition) vector<CrewPlacementDefinition>;
    %template(vector_string) vector<string>;
    %template(vector_StatBoostDefinition) vector<StatBoostDefinition*>;
    %template(pair_Animation_int8_t) pair<Animation, int8_t>;
    %template(vector_pair_Animation_int8_t) vector<pair<Animation, int8_t>>;
}

%rename("%s") Get_Drone_Subclass; // Get derived class of a SpaceDrone with Hyperspace.Get_Drone_Subclass(spaceDrone)
%native(Get_Drone_Subclass)  static int Get_Drone_Subclass(lua_State* L);
%{
    static int Get_Drone_Subclass(lua_State* L) {
        int SWIG_arg = 0;
        SpaceDrone* arg1 = nullptr;


        SWIG_check_num_args("Get_Drone_Subclass",1,1)
        if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("Get_Drone_Subclass",1,"SpaceDrone *");
        
        if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p_SpaceDrone,0))){
            SWIG_fail_ptr("Get_Drone_Subclass",1,SWIGTYPE_p_SpaceDrone);
        }
        

        SWIG_NewPointerObj(L, arg1, Global::GetInstance()->getLuaContext()->getLibScript()->types.pSpaceDroneTypes[arg1->type], 0); SWIG_arg++; 
        return SWIG_arg;
        
        if(0) SWIG_fail;
        
        fail:
        lua_error(L);
        return SWIG_arg;
    }
%}

// Automatically get the derived class of a SpaceDrone when retriving it from a vector
%luacode {
    local indexFn = getmetatable(Hyperspace.vector_SpaceDrone)[".instance"].__index
    getmetatable(Hyperspace.vector_SpaceDrone)[".instance"].__index = function(vector, index)
        local ret = indexFn(vector, index)
        if type(ret) == "function" then return ret end
        return Hyperspace.Get_Drone_Subclass(ret)
    end
}

%include "ToggleValue.h"
%template(ToggleValue_int) ToggleValue<int>;
%template(ToggleValue_float) ToggleValue<float>;
%template(ToggleValue_bool) ToggleValue<bool>;
%rename("%s") ToggleValue::value;
%immutable ToggleValue::value;
%rename("%s") ToggleValue::enabled;
%immutable ToggleValue::enabled;
%rename("%s") ToggleValue::ToggleValue;
%rename("%s") ToggleValue::operator=;

%apply const std::string& {std::string* GetName()};

%rename("Blueprints") Global_BlueprintManager_Blueprints; 
%rename("Sounds") Global_SoundControl_Sounds;
%rename("Animations") Global_AnimationControl_Animations;
%rename("CrewFactory") Global_CrewMemberFactory_Factory;
%rename("FPS") Global_CFPS_FPSControl;
%rename("Score") Global_ScoreKeeper_Keeper;
%rename("Resources") Global_ResourceControl_GlobalResources;
%rename("Settings") Global_Settings_Settings;
%rename("Mouse") Global_MouseControl_Mouse;

%immutable Global_BlueprintManager_Blueprints;
%immutable Global_SoundControl_Sounds;
%immutable Global_AnimationControl_Animations;
%immutable Global_CrewMemberFactory_Factory;
%immutable Global_CFPS_FPSControl;
%immutable Global_ScoreKeeper_Keeper;
%immutable Global_ResourceControl_GlobalResources;
%immutable Global_Settings_Settings;
%immutable Global_MouseControl_Mouse;

%rename("setRandomSeed") srandom32;

float font_text_width(freetype::font_data &fontData, const char *str, float size);
float getSkillBonus(int skill, int level);
int random32();
void srandom32(unsigned int seed);

%rename("version") HS_Version;
%extend HyperspaceVersion {
    const char* __str__() const {
        static std::string ret;
        ret = $self->toVersionString();
        return ret.c_str();
    }
};
%include "HSVersion.h"

/*
 TODO: We may want to hide CApp in the metatable so it looks like just a getter/global variable of the Hyperspace module
 TODO: We may want to hide Global::GetShipManager(0) as `ships.player` in the metatable so it looks like a getter global variable
 TODO: We may want to do the same with Global::GetShipManager(1) as `ships.enemy`
 ^^^^ Note all of the above require doing this with the Lua C API (Rather than some SWIG shortcut) although it may be simnpler to just do it in Lua while still having it secretly accessible under another path
 Maybe at some point we make most of the `Hyperspace` module internal and just pull out various functions & expose them to a different table in Lua so we can control the final naming of everything, and then we can hide the `Hyperspace` table after our rewrite code has run.
*/
/* We didn't import Global.h but we could have and just renamed just these specific functions.
   Although Global.h has a couple C++ variable argument functions SWIG can't handle unless the syntax was changed as it can't handle the `const char *str...` style of varargs
*/
%nodefaultctor Global;
class Global
{
public:
    static Global* GetInstance();
    ShipManager* GetShipManager(int iShipId);
    CApp* GetCApp();
    BlueprintManager* GetBlueprints();
    SoundControl* GetSoundControl();
    AnimationControl *GetAnimationControl();
    CrewMemberFactory *GetCrewFactory();
    MouseControl *GetMouseControl();

    static bool IsSeededRun();
    %immutable;
    static unsigned int currentSeed;
};

void ErrorMessage(const char* msg);

/* Create Hyperspace.ships metatable that contains:
    Hyperspace.ships.player (ShipManager)
    Hyperspace.ships.enemy (ShipManager)

    Note this might need to extend the table returned by player & enemy so it has access to the contents of `CompleteShip` or `BossShip`? Since those are two completely flipping unrelated classes that have to be gotten via a completely different path of CApp->World->playerShip (CompleteShip) and CApp->World->bossShip (BossShip) and can't be retreived from the damn ShipManager?
    That is assuming we actually need to expose anything from those... like CompleteShip:KillRandomCrew() or maybe we make some new table and just bring in methods from both.
    We could totally return another metatable so that things like `ships.player:KillRandomCrew()` could access `CompleteShip` while `ships.player:DamageHull()` could route to `ShipManager`'s function internally (kinda a manual multiple inheritance)
*/
%luacode {
    Hyperspace.ships = setmetatable({}, {
        __index = function(ships, key)
            if key == "player" then
                return Hyperspace.Global.GetInstance():GetShipManager(0)
            elseif key == "enemy" then
                return Hyperspace.Global.GetInstance():GetShipManager(1)
            else
                error("Unknown ship " .. key, 2)
            end
        end,
        __newindex = function(ships, key, value)
            error("ships is immutable", 2)
        end,
        __call = function(ships, shipId)
            if shipId ~= 0 and shipId ~= 1 then 
                error("Invalid shipId!", 2)
            else
                return Hyperspace.Global.GetInstance():GetShipManager(shipId)
            end
        end
    })
}

%nodefaultctor;
%nodefaultdtor;
struct CFPS
{
    %immutable;
    float RunningTime;
    double OldTime;
    double LastTime;
    float SpeedFactor;
    int NumFrames;
    int Frames;
    %mutable;
    /*** Game simulation speed
    @tparam int speedLevel
    This adjusts the game's simulation rate, a value of 0 is normal speed. Higher values will cause the game to speedup so that 1 in-game second is faster than 1 real-world second.
    the console `SPEED` command sets this value and the speed hotkey just toggles this between 0 and whatever value was set.
    */
    int speedLevel;
};
%clearnodefaultctor;
%clearnodefaultdtor;

//Add setter/getter members such that Hyperspace.FPS.speedEnabled appears to be a valid member.
%init %{
        SWIG_Lua_get_class_metatable(L, "CFPS"); //Get CFPS metatable.
        SWIG_Lua_get_table(L, ".get");
        SWIG_Lua_add_function(L, "speedEnabled", 
        [](lua_State* L) -> int
        {
            lua_pushboolean(L, speedEnabled);
            return 1;
        });
        lua_pop(L, 1);             //Remove .get table
        SWIG_Lua_get_table(L, ".set");
        SWIG_Lua_add_function(L, "speedEnabled", 
        [](lua_State* L) -> int
        {
            SWIG_check_num_args("CFPS::speedEnabled", 2, 2)
            if (!lua_isboolean(L, 2)) SWIG_fail_arg("CFPS::speedEnabled", 2, "bool");
            speedEnabled = (lua_toboolean(L, 2) != 0 );
            return 0;
            fail:
                lua_error(L);
                return 0;
        });
        lua_pop(L, 2); //Remove .set table and metatable

%}


// make player variables and metavariables look like a different class
%{
typedef std::unordered_map<std::string,int> playerVariableType;
%}

class playerVariableType {
    // add typemaps here
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef std::string key_type;
    typedef int mapped_type;
    typedef std::pair< const std::string, int > value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;

    playerVariableType();
    playerVariableType(const playerVariableType& other);

    unsigned int size() const;
    bool empty() const;
    void clear();
    %extend {
        int get(const std::string& key) {
            playerVariableType::iterator i = self->find(key);
            if (i != self->end())
                return i->second;
            else
                return 0;
        }
        void set(const std::string& key, int x) {
            (*self)[key] = x;
            CustomAchievementTracker::instance->UpdateVariableAchievements(key, x, G_->GetWorld()->bStartedGame);
        }
        void del(const std::string& key) {
            playerVariableType::iterator i = self->find(key);
            if (i != self->end())
                self->erase(i);
        }
        bool has_key(const std::string& key) {
            playerVariableType::iterator i = self->find(key);
            return i != self->end();
        }
        // more stuff
        int __getitem__(const std::string& key)
        {
            playerVariableType::iterator i = self->find(key);
            if (i != self->end())
                return i->second;
            else
                return 0;
        }
        void __setitem__(const std::string& key, int x)
        {
            (*self)[key] = x;
            CustomAchievementTracker::instance->UpdateVariableAchievements(key, x, G_->GetWorld()->bStartedGame);
        }
    }
};

playerVariableType metaVariables;
playerVariableType playerVariables;

%rename("%s") metaVariables;
%rename("%s") playerVariables;

%rename("%s") useAugmentReq;

%nodefaultctor CustomAchievementTracker;
%rename("%s") CustomAchievementTracker;
%immutable CustomAchievementTracker::instance;
%rename("%s") CustomAchievementTracker::instance;
%rename("%s") CustomAchievementTracker::UpdateVariableAchievements;
%rename("%s") CustomAchievementTracker::GetAchievementStatus;
%rename("%s") CustomAchievementTracker::SetAchievement; // used to award achievements (CheckShipAchievement is automatically called if needed)


%nodefaultctor CustomEventsParser;
%nodefaultdtor CustomEventsParser;

%rename("%s") CustomEventsParser;
%rename("%s") CustomEventsParser::GetInstance;
%rename("%s") CustomEventsParser::LoadEvent;
%luacode {
    print "Hyperspace SWIG Lua loaded"
    _G["mods"] = {}
}

%contract ShipSystem::AddLock(int lock) {
    require:
        lock >= -1;
        lock < 6;
}

%ignore "";
%rename("%(regex:/^(.*::~.*)$/\\1/)s", regextarget=1, fullname=1) ".*::~.*"; // don't ignore destructors

%rename("setWindowTitle") sys_graphics_set_window_title;

/* %rename("%s") ScoreKeeper; */
/* %rename("%s") ScoreKeeper::AddScrapCollected; */
/* %rename("%s") ScoreKeeper::gamesPlayed; */
/* %rename("%(regex:/^ScoreKeeper::(.*)$/\\1/)s", regextarget=1, fullname=1) "ScoreKeeper::.*"; */

%nodefaultctor CApp;
//%rename("%s") CEvent::TextEvent;
//%rename("%s") CEvent::OnEvent;
%rename("%s") CApp;
// TODO: Maybe the CApp input functions become like `input.keyDown` etc... so it makes sense for people to call them and maybe `input.onKeyDown(callback)` is a function for registering handlers?
// TODO: We could even use metatables to set __call of `input.onKeyDown` table to be the register function and `__getitem__` & `__setitem__` to allow `input.onKeyDown[index]` to access & delete registered handlers and then repeat the pattern for other event handlers? Or maybe just the __index & __newindex of it for named event handlers although representing the ordered nature of it might be harder that way.
%rename("%s") CApp::OnExit; // close game, autosave profile and settings but not current run (current run will be on previous autosave)
%rename("%s") CApp::OnRequestExit; // close game, autosave run, profile, and settings
/*
%rename("%s") CApp::OnKeyDown;
%rename("%s") CApp::OnKeyUp;
%rename("%s") CApp::OnLButtonDown;
%rename("%s") CApp::OnLButtonUp;
%rename("%s") CApp::OnMButtonDown;
//%rename("%s") CApp::OnMButtonUp; // OnMButtonUp only exists in CEvent and is referenced in the vtable, maybe it could be extended and made available if needed, same with OnMouseWheel & OnWindowResize
%rename("%s") CApp::OnMouseMove;
%rename("%s") CApp::OnRButtonDown;
%rename("%s") CApp::OnRButtonUp;
//%rename("%s") CApp::OnRequestExit; // Maybe use this for game cleanup? Not sure if this is called right before exiting the game
%rename("%s") CApp::OnTextEvent;
%rename("%s") CApp::OnTextInput;
%rename("%s") CApp::TranslateMouse;
*/
%rename("%s") CApp::gui; // Maybe we only allow access to the command gui via WorldManager and just hide the CApp implementation by something that gives us access to WorldManager like below?
%rename("%s") CApp::world;
%immutable CApp::menu;
%rename("%s") CApp::menu;
// TODO: It might be nice to hide away CApp entirely for access to global things like `CommandGui` or `WorldManager` and hide other functions to do clicks & button presses & stuff under `input` as described above
/* Potential example for a Hyperspace.world
%luacode {
    Hyperspace.world = setmetatable({}, {
        __index = function(world, key)
            return Hyperspace.Global.GetInstance():GetCApp().world[key]
        end,
        __newindex = function(world, key, value)
            Hyperspace.Global.GetInstance():GetCApp().world[key] = value
        end
    })
}
*/

%nodefaultctor MainMenu;
%nodefaultdtor MainMenu;

%rename("%s") MainMenu;
%immutable MainMenu::bOpen;
%rename("%s") MainMenu::bOpen;
%immutable MainMenu::shipBuilder;
%rename("%s") MainMenu::shipBuilder;

%nodefaultctor ShipBuilder;
%nodefaultdtor ShipBuilder;

%rename("%s") ShipBuilder;
%immutable ShipBuilder::bOpen;
%rename("%s") ShipBuilder::bOpen;

%nodefaultctor CommandGui;
%nodefaultdtor CommandGui;
%rename("%s") CommandGui;
////%rename("%s") CommandGui::AddEnemyShip;
////%rename("%s") CommandGui::CreateNewStore;
////%newobject CommandGui::CreateNewStore;
////%rename("%s") CommandGui::GetWorldCoordinates;
////%rename("%s") CommandGui::NewLocation;
%rename("%s") CommandGui::shipStatus;
%rename("%s") CommandGui::crewControl;
%rename("%s") CommandGui::sysControl;
%rename("%s") CommandGui::combatControl;
%rename("%s") CommandGui::ftlButton;
%rename("%s") CommandGui::spaceStatus;
////%rename("%s") CommandGui::starMap // Part of WorldManager's actual object rather than using a reference ideally don't expose this one in CommandGui
////%rename("%s") CommandGui::shipComplete; // Part of WorldManager also, maybe use that one?
%rename("%s") CommandGui::pauseTextLoc;
%rename("%s") CommandGui::shipPosition;
//%rename("%s") CommandGui::locationText; // Not sure if this is allowed to be updated/what this will cause yet
//%rename("%s") CommandGui::loadEvent; // Not sure what this will cause yet or if it's immutable
//%rename("%s") CommandGui::loadSector; // Not sure what this will cause yet or if it's immutable
%rename("%s") CommandGui::outOfFuel;
%immutable CommandGui::outOfFuel;
%rename("%s") CommandGui::bPaused;
%immutable CommandGui::bPaused;
%rename("%s") CommandGui::bAutoPaused;
%immutable CommandGui::bAutoPaused;
%rename("%s") CommandGui::menu_pause;
%immutable CommandGui::menu_pause;
%rename("%s") CommandGui::event_pause;
%immutable CommandGui::event_pause;
%rename("%s") CommandGui::upgradeButton;
%immutable CommandGui::upgradeButton;
%rename("%s") CommandGui::dangerLocation;
%immutable CommandGui::dangerLocation;

//%rename("%s") CommandGui::equipScreen;
//%immutable CommandGui::equipScreen;
//
//%rename("%s") Equipment::AddAugment;
//%rename("%s") Equipment::AddDrone;
//%rename("%s") Equipment::AddToCargo;
//%rename("%s") Equipment::AddWeapon;
//%rename("%s") Equipment::GetCargoHold;

%rename("%s") CommandGui::bHideUI; // Not sure if we should disallow setting this
%rename("%s") CommandGui::jumpComplete;
%immutable CommandGui::jumpComplete;
%rename("%s") CommandGui::mapId;
%immutable CommandGui::mapId;
%rename("%s") CommandGui::secretSector;
%immutable CommandGui::secretSector;
%rename("%s") CommandGui::choiceBoxOpen;
%immutable CommandGui::choiceBoxOpen;

%nodefaultctor CombatControl;
%nodefaultdtor CombatControl;
%rename("%s") CombatControl;
%rename("%s") CombatControl::targetPosition;
%rename("%s") CombatControl::boss_visual;
%immutable CombatControl::boss_visual;

%rename("%s") Button;
%rename("%s") Button::OnInit;
%rename("%s") Button::OnRender;
%rename("%s") Button::SetActiveImage;
%rename("%s") Button::SetImageBase;
%rename("%s") Button::SetInactiveImage;
%rename("%s") Button::SetLocation;

%rename("%s") Button::images;
%rename("%s") Button::primitives;
%rename("%s") Button::imageSize;
%rename("%s") Button::bMirror;

%nodefaultctor GenericButton;
%nodefaultdtor GenericButton;
%rename("%s") GenericButton;
%rename("%s") GenericButton::Reset;
%rename("%s") GenericButton::SetLocation;
%rename("%s") GenericButton::SetHitBox;
%rename("%s") GenericButton::SetActive;
%rename("%s") GenericButton::OnLoop;
%rename("%s") GenericButton::OnRender;
%rename("%s") GenericButton::MouseMove;
%rename("%s") GenericButton::OnClick;
%rename("%s") GenericButton::OnRightClick;
%rename("%s") GenericButton::OnTouch;
%rename("%s") GenericButton::ResetPrimitives;

%immutable GenericButton::position;
%rename("%s") GenericButton::position;
%immutable GenericButton::hitbox;
%rename("%s") GenericButton::hitbox;
%rename("%s") GenericButton::allowAnyTouch;
%rename("%s") GenericButton::touchSelectable;
%rename("%s") GenericButton::bRenderOff;
%rename("%s") GenericButton::bRenderSelected;
%rename("%s") GenericButton::bFlashing;
%rename("%s") GenericButton::flashing;
%rename("%s") GenericButton::bActive;
%rename("%s") GenericButton::bHover;
%rename("%s") GenericButton::bActivated;
%rename("%s") GenericButton::bSelected;
%rename("%s") GenericButton::activeTouch;

%nodefaultctor MouseControl;
%nodefaultdtor MouseControl;
%rename("%s") MouseControl;
%rename("%s") MouseControl::InstantTooltip;
%rename("%s") MouseControl::MeasureTooltip;
%rename("%s") MouseControl::OnLoop;
%rename("%s") MouseControl::OnRender;
%rename("%s") MouseControl::QueueStaticTooltip;
%rename("%s") MouseControl::RenderTooltip;
%rename("%s") MouseControl::Reset;
%rename("%s") MouseControl::ResetArmed;
%rename("%s") MouseControl::SetDoor;
%rename("%s") MouseControl::SetTooltip;
%rename("%s") MouseControl::SetTooltipTitle;
	
%rename("%s") MouseControl::position;
%rename("%s") MouseControl::lastPosition;
%rename("%s") MouseControl::aiming_required;
%rename("%s") MouseControl::iTeleporting;
%rename("%s") MouseControl::iMindControlling;
%rename("%s") MouseControl::bSellingStuff;
%rename("%s") MouseControl::valid;
%rename("%s") MouseControl::newHover;
%rename("%s") MouseControl::lastValid;
%rename("%s") MouseControl::animateDoor;
%rename("%s") MouseControl::validPointer;
%rename("%s") MouseControl::invalidPointer;
%rename("%s") MouseControl::cselling;
%rename("%s") MouseControl::openDoor;
%rename("%s") MouseControl::tooltip;
%rename("%s") MouseControl::tooltipTimer;
%rename("%s") MouseControl::bMoving;
%rename("%s") MouseControl::bHideMouse;
%rename("%s") MouseControl::lastIcon;
%rename("%s") MouseControl::lastAddition;
%rename("%s") MouseControl::bForceTooltip;
%rename("%s") MouseControl::tooltipTitle;
%rename("%s") MouseControl::lastTooltipText;
%rename("%s") MouseControl::iHacking;
%rename("%s") MouseControl::overrideTooltipWidth;
%rename("%s") MouseControl::staticTooltip;

%nodefaultctor WorldManager;
%rename("%s") WorldManager;
%rename("%s") WorldManager::AddBoarders; // Might make more sense under the player's ship or something?
////%rename("%s") WorldManager::ModifyEnvironment;
////%rename("%s") WorldManager::HostileEnvironment;
////%rename("%s") WorldManager::ModifyStatusEffect;
//%rename("%s") WorldManager::playerShip; // TODO: See above, maybe want to extract functionality of this into proxied calls from `ships.player`?
//%rename("%s") WorldManager::bossShip; // TODO: Same as above except proxied calls from `ships.enemy` maybe and only if the boss ship is available?
%rename("%s") WorldManager::space;
%immutable WorldManager::space;

%rename("%s") WorldManager::currentDifficulty;
%immutable WorldManager::currentDifficulty;

%rename("%s") WorldManager::starMap;
%immutable WorldManager::starMap;

////%rename("%s") WorldManager::commandGui;
////%rename("%s") WorldManager::currentShipEvent; // Not sure if this should be writeable
////%rename("%s") WorldManager::currentEffects; // Vector of StatusEffect, maybe allow? Not sure if it should be writeable
////%rename("%s") WorldManager::newLocation; // Setting will cause a switch to a new location on the next frame/run of WorldManager::OnLoop, but we probably want people loading events and not location objects directly.
%rename("%s") WorldManager::bStartedGame;
%immutable WorldManager::bStartedGame;
%rename("%s") WorldManager::bLoadingGame; // Indicates game is reloading from a save file rather than an initial encounter, the on_game_event hook uses this internally (but it doesn't need to be exposed to lua for that function as that's in C)
%immutable WorldManager::bLoadingGame;
////%rename("%s") WorldManager::choiceHistory;
////%rename("%s") WorldManager::generatedEvent;
%rename("%s") WorldManager::playerCrewCount; // statistic for game over screen I think
%rename("%s") WorldManager::killedCrew; // statistic for game over screen I think
%rename("%s") WorldManager::playerHull; // statistic for game over screen I think

%nodefaultctor SpaceManager;
%rename("%s") SpaceManager;
//%rename("%s") SpaceManager::AddProjectile; // Could be useful for simulating new projectile types on screen?
////%rename("%s") SpaceManager::ClearEnvironment;
////%rename("%s") SpaceManager::ClearProjectiles; // Could be useful to test what happens if we call this right after an event's completion or enemy ship's death?
%rename("%s") SpaceManager::DangerousEnvironment; // Kinda annoying that HostileEnvironment is part of WorldManager but DangerousEnvironment is SpaceManager? WTF subset, these classes are all over the place.
////%rename("%s") SpaceManager::GetSelectedDrone; // TODO: Check if this creates a new object and if we need %newobject to clean it up.
%rename("%s") SpaceManager::SwitchBackground; // Could be useful for rendering background/starfield animations
//%rename("%s") SpaceManager::SwitchImages;
%rename("%s") SpaceManager::SwitchPlanet; // Could be useful for rendering planet animations
%rename("%s") SpaceManager::UpdatePlanetImage; // Maybe needed if planet texture is messed with directly and then this updates the cached image?
%rename("%s") SpaceManager::UpdateProjectile;

// hyperspace projectile creation methods
%rename("%s") SpaceManager::CreateLaserBlast;
%rename("%s") SpaceManager::CreateAsteroid;
%rename("%s") SpaceManager::CreateMissile;
%rename("%s") SpaceManager::CreateBomb;
%rename("%s") SpaceManager::CreateBeam;
%rename("%s") SpaceManager::CreateBurstProjectile;
%rename("%s") SpaceManager::CreatePDSFire;

%rename("%s") SpaceManager::projectiles;
%immutable SpaceManager::projectiles;
%rename("%s") SpaceManager::currentBack;
%rename("%s") SpaceManager::currentPlanet; // might be able to set .rot on this and then call UpdatePlanetImage to spin the planet
%rename("%s") SpaceManager::bNebula;
%immutable SpaceManager::bNebula;
%rename("%s") SpaceManager::bStorm;
%immutable SpaceManager::bStorm;
//%nodefaultctor SpaceManager::FleetShip;
//%rename("%s") SpaceManager::FleetShip;
//%rename("%s") SpaceManager::FleetShip::location;
//%rename("%s") SpaceManager::fleetShips; // Might be able to move the positions around of the various 9 fleet ships and allow for some cool animations?
//%rename("%s") SpaceManager::shipPosition; // Not sure what will happen if we mess with this, worth exploring.
////%rename("%s") SpaceManager::nebulaClouds; // Could maybe allow messing with the nebula clouds for some cool animations & movements of them, at least in high graphics mode.
////%rename("%s") SpaceManager::shipHealth; // Not sure if this is player health or WHY THE HELL IT'S HERE (or possibly duplicated) and not part of the SHIP.
%rename("%s") SpaceManager::gamePaused; // Not sure how this differs from CommandGui's pause information.
%immutable SpaceManager::gamePaused;

//%rename("%s") ImageDesc;
//%rename("%s") ImageDesc:rot;

// TODO: Maybe draggable windows could be implemented if we allowed updating of FocusWindow's position?

%nodefaultctor StarMap;
%rename("%s") StarMap;
////%rename("%s") StarMap::ConnectLocations; // Could be interesting to allow like a direct connection/wormhole between points.
////%rename("%s") StarMap::Dijkstra; // Could be interesting to allow computing how many jumps away a quest is, and maybe adding a wormhole or something if it's too far away that it would be always consumed by the fleet before exiting.
////%rename("%s") StarMap::AtBeacon; // Are we at an exit beacon, true/false.
////%rename("%s") StarMap::ForceBossJump;
////%rename("%s") StarMap::ForceExitBeacon;
////%rename("%s") StarMap::GetLocationText; // Not sure what this does, maybe it could be used to allow exploring nodes we haven't jumped to yet? Not sure
////%rename("%s") StarMap::GetNewLocation; // Not sure what this does, maybe this allows generating a new location event if waiting?
////%rename("%s") StarMap::GetWaitLocation; // Not sure
////%rename("%s") StarMap::LocationsConnected; // Might be useful with Dijkstra or ConnectLocations to make sure it's not already connected
%rename("%s") StarMap::ModifyPursuit; // We can also allow them to directly modify StarMap.pursuitDelay, all this function does is add it to the existing pursuitDelay but setting it directly could be funny or simpler than this call.
%rename("%s") StarMap::PointToGrid;
////%rename("%s") StarMap::PopClosestLoc; // Not sure if this would be useful or safe
////%rename("%s") StarMap::SelectNewSector; // Not sure if safe
//%rename("%s") StarMap::TurnIntoFleetLocation; // Could be interesting to allow something like 1. Delaying the pursuit for many many turns, 2. having every node you jump out of (or random nodes you've already visited or that do not line up with the path to the exit) convert to a fleet location as if they were chasing your path rather than the whole sector.

//%rename("%s") StarMap::visual_size; // Not sure
%rename("%s") StarMap::currentLoc; // Current location always, even after load, this is the gold source for location after a load best I can figure out. Oh and in the base game it doesn't load backgrounds properly but does load the planet texture so then `WorldManager::CreateLocation` doesn't bother to update the texture because not both are null.
////%rename("%s") StarMap::position; // umm... FocusWindow has a position too, which position is this going to map to?
// TODO: Maybe one of the members in StarMap (that are not exposed) could help to determine how many free event locations are left so an event can be chosen to spawn in the current sector or next sector?
////%rename("%s") StarMap::dangerZone; // Messing with this might be interesting, imagine if the fleet didn't proceed directly from the left? lol
////%rename("%s") StarMap::dangerZoneRadius;
//%rename("%s") StarMap::bMapRevealed; // Not sure if setting this is okay
%rename("%s") StarMap::pursuitDelay;
//%rename("%s") StarMap::outOfFuel;
//%immutable StarMap::outOfFuel;
// TODO: We might be able to allow access to the `sectors` vector and maybe allow rendering secret sectors onto the map but instead just jumping to them when they're clicked?
////%rename("%s") StarMap::sectors; // also there is lastSectors, not sure what they're for yet
// TODO: Not sure what scrapCollected, dronesCollected, fuelCollected, weaponFound, droneFound maps do, does the game record what was found at each node? Can't find calls to it internally.
%rename("%s") StarMap::ship;
%rename("%s") StarMap::shipNoFuel;
%immutable StarMap::worldLevel; //Sector number (Sector 1 has worldLevel = 0, Sector 2 has worldLevel = 1, etc.)
%rename("%s") StarMap::worldLevel;

/*
////%rename("%s") StarMap::ReverseBossPath;
////%rename("%s") StarMap::UpdateBoss; // Could be interesting for allowing the boss to move manually *although* maybe this is dangerous on non-boss levels, maybe UpdateDangerZone is safer to call?
////%rename("%s") StarMap::UpdateDangerZone;
%rename("%s") StarMap::bossLoc;
%rename("%s") StarMap::arrivedAtBase;
%rename("%s") StarMap::reversedPath;
%rename("%s") StarMap::bossJumping;
%rename("%s") StarMap::boss_path;
%rename("%s") StarMap::bossLevel;
%rename("%s") StarMap::boss_wait;
%rename("%s") StarMap::bossPosition;
%rename("%s") StarMap::waitedLast;
%rename("%s") StarMap::bossStage;
*/
/* Could be cool data to expose for statistics or run purposes.
%rename("%s") StarMap::sectorMapSeed;
%immutable StarMap::sectorMapSeed;
%rename("%s") StarMap::currentSectorSeed;
%immutable StarMap::currentSectorSeed;
%rename("%s") StarMap::fuelEventSeed;
%immutable StarMap::fuelEventSeed;
*/
////%rename("%s") StarMap::foundMap; // Not sure what this map of location/bool does but maybe this is for marking what nodes have information, like if you find the sector map & scan???

/*
%nodefaultctor ShipEvent;
%rename("%s") ShipEvent;
%rename("%s") ShipEvent::present;
%rename("%s") ShipEvent::name;
%rename("%s") ShipEvent::blueprint;
%rename("%s") ShipEvent::auto_blueprint;
%rename("%s") ShipEvent::blueprintList;
%rename("%s") ShipEvent::actualBlueprint;
%rename("%s") ShipEvent::hostile;
%rename("%s") ShipEvent::surrender;
%rename("%s") ShipEvent::escape;
%rename("%s") ShipEvent::destroyed;
%rename("%s") ShipEvent::deadCrew;
%rename("%s") ShipEvent::gotaway;
%rename("%s") ShipEvent::escapeTimer;
%rename("%s") ShipEvent::surrenderThreshold;
%rename("%s") ShipEvent::escapeThreshold;
%rename("%s") ShipEvent::crewOverride;
%rename("%s") ShipEvent::weaponOverride;
%rename("%s") ShipEvent::weaponOverCount;
%rename("%s") ShipEvent::droneOverride;
%rename("%s") ShipEvent::droneOverCount;
%rename("%s") ShipEvent::shipSeed;
*/

%rename("%s") CrewDesc;
%rename("%s") CrewDesc::type;
%rename("%s") CrewDesc::prop;
%rename("%s") CrewDesc::amount;

/*
//%nodefaultctor RandomAmount;
%rename("%s") RandomAmount;
%rename("%s") RandomAmount::min;
%rename("%s") RandomAmount::max;
%rename("%s") RandomAmount::chanceNone;
*/

/*
%nodefaultctor StatusEffect;
%rename("%s") StatusEffect;
%rename("%s") StatusEffect::type;
%rename("%s") StatusEffect::system;
%rename("%s") StatusEffect::amount;
%rename("%s") StatusEffect::target;
*/

/*
%nodefaultctor NebulaCloud;
%rename("%s") NebulaCloud;
%rename("%s") NebulaCloud::pos;
%rename("%s") NebulaCloud::currAlpha;
%rename("%s") NebulaCloud::currScale;
%rename("%s") NebulaCloud::deltaAlpha;
%rename("%s") NebulaCloud::deltaScale;
%rename("%s") NebulaCloud::newTrigger;
%rename("%s") NebulaCloud::newCloud;
%rename("%s") NebulaCloud::bLightning;
%rename("%s") NebulaCloud::flashTimer;
%rename("%s") NebulaCloud::lightningRotation;
*/

%rename("%s") Globals;
%nodefaultctor Globals;
%nodefaultdtor Globals;
%rename("%s") Ellipse;
%rename("%s") Globals::Ellipse;
%rename("%s") Globals::Ellipse::center;
%rename("%s") Globals::Ellipse::a;
%rename("%s") Globals::Ellipse::b;
%rename("%s") Rect;
%rename("%s") Globals::Rect;
%rename("%s") Globals::Rect::x;
%rename("%s") Globals::Rect::y;
%rename("%s") Globals::Rect::w;
%rename("%s") Globals::Rect::h;


%rename("%s") ImageDesc;
%nodefaultctor ImageDesc;
%nodefaultdtor ImageDesc;
%rename("%s") ImageDesc::tex;
%rename("%s") ImageDesc::resId;
%rename("%s") ImageDesc::w;
%rename("%s") ImageDesc::h;
%rename("%s") ImageDesc::x;
%rename("%s") ImageDesc::y;
%rename("%s") ImageDesc::rot;

%nodefaultctor Location;
%rename("%s") Location;
%rename("%s") Location::space;
%rename("%s") Location::spaceImage;
//%rename("%s") Location::planet;
%rename("%s") Location::planetImage;


%rename("%s") BoardingEvent;
%rename("%s") BoardingEvent::type;
%rename("%s") BoardingEvent::min;
%rename("%s") BoardingEvent::max;
%rename("%s") BoardingEvent::amount;
%rename("%s") BoardingEvent::breach;

%nodefaultctor CustomShipUnlocks;
%nodefaultdtor CustomShipUnlocks;
%rename("%s") CustomShipUnlocks;
%rename("%s") CustomShipUnlocks::instance;
%immutable CustomShipUnlocks::instance;
%rename("%s") CustomShipUnlocks::UnlockShip;
%rename("%s") CustomShipUnlocks::GetCustomShipUnlocked;

%rename("%s") ShipObject;
%nodefaultctor ShipObject;
%nodefaultdtor ShipObject;
%rename("%s") ShipObject::AddAugmentation;
%rename("%s") ShipObject::ClearShipInfo;
%rename("%s") ShipObject::GetAugmentationCount;
%rename("%s") ShipObject::GetAugmentationList;
%rename("%s") ShipObject::GetAugmentationValue;
%rename("%s") ShipObject::HasAugmentation;
%rename("HasEquipment") ShipObject::HS_HasEquipment;
%rename("%s") ShipObject::RemoveAugmentation;
%immutable ShipObject::iShipId;
%rename("%s") ShipObject::iShipId;

// TODO: Expose ShipManager
%rename("%s") ShipManager;
%nodefaultctor ShipManager;
%nodefaultdtor ShipManager;
%rename("%s") ShipManager::ShipManager;
//%rename("%s") ShipManager::AddAugmentation; // Might prefer this be done via an event? Not sure.
//%rename("%s") ShipManager::ClearShipInfo;
//%rename("%s") ShipManager::GetAugmentationCount;
//%rename("%s") ShipManager::GetAugmentationList;
//%rename("%s") ShipManager::GetAugmentationValue;
//%rename("%s") ShipManager::HasAugmentation;
//%rename("%s") ShipManager::HasEquipment;
//%rename("%s") ShipManager::RemoveAugmentation; // Might prefer this be done via an event? Not sure.
%immutable ShipManager::iShipId;
%rename("%s") ShipManager::iShipId;
%rename("%s") ShipManager::GetRandomRoomCenter;
%rename("%s") ShipManager::GetRoomCenter;
%rename("%s") ShipManager::GetAvailablePower;
//%rename("%s") ShipManager::AddCrewMemberFromBlueprint; // Might prefer via event. Might need to specify that this creates a new object for cleanup?
//%rename("%s") ShipManager::AddCrewMemberFromString; // Might prefer via event. Might need to specify that this creates a new object for cleanup?
%rename("%s") ShipManager::AddDrone;
//%rename("%s") ShipManager::AddEquipmentFromList; // Might prefer via event?
%rename("%s") ShipManager::AddInitialCrew;
%rename("%s") ShipManager::AddSystem;
%rename("%s") ShipManager::AddWeapon;
%rename("%s") ShipManager::CanFitSubsystem;
%rename("%s") ShipManager::CanFitSystem;
%rename("%s") ShipManager::CanUpgrade;
%rename("%s") ShipManager::ClearStatusAll;
%rename("%s") ShipManager::ClearStatusSystem;
//%rename("%s") ShipManager::CollisionMoving; // TODO: Expose CollisionResponse
//%rename("%s") ShipManager::CommandCrewMoveRoom; // TODO: Needs CrewMember first maybe?
%rename("%s") ShipManager::CountCrew; // Count crew on this ship, true for boarders false for regular crewmembers.
%rename("%s") ShipManager::CountCrewShipId; // Count crew on the specific ship & room
//%rename("%s") ShipManager::CreateCrewDrone; // Use Events
%rename("%s") ShipManager::CreateSpaceDrone;
%rename("%s") ShipManager::DamageArea;
%rename("%s") ShipManager::DamageBeam;
//%rename("%s") ShipManager::DamageCrew;
%rename("%s") ShipManager::DamageHull;
%rename("%s") ShipManager::DamageSystem;
%rename("%s") ShipManager::DoSensorsProvide;
%rename("%s") ShipManager::DoorsFunction;
%rename("%s") ShipManager::FindCrew;
%rename("%s") ShipManager::ForceDecreaseSystemPower;
%rename("%s") ShipManager::GetCrewmember;
%rename("%s") ShipManager::GetDodgeFactor;
%rename("%s") ShipManager::GetDodged; // Don't know what this represents
%rename("%s") ShipManager::GetDroneCount;
%rename("%s") ShipManager::GetMissileCount;
%rename("%s") ShipManager::GetDroneList;
%rename("%s") ShipManager::GetFireCount; // Get number of fires in a room, could be quite useful for computing damage
%rename("%s") ShipManager::GetOxygenPercentage; // Ship's oxygen (not per-room)
%rename("%s") ShipManager::GetSelectedCrewPoint;
%rename("%s") ShipManager::GetShieldPower;
%rename("%s") ShipManager::GetSystem; // Get a system by its id
%rename("%s") ShipManager::GetSystemInRoom;
%rename("%s") ShipManager::GetSystemPower;
%rename("%s") ShipManager::GetSystemPowerMax;
%rename("%s") ShipManager::GetSystemRoom;
%rename("%s") ShipManager::GetTooltip;
%rename("%s") ShipManager::GetWeaponList;
%rename("%s") ShipManager::HasSystem;
%rename("%s") ShipManager::OnInit;
%rename("%s") ShipManager::InstantPowerShields;
%rename("%s") ShipManager::IsCrewFull;
%rename("%s") ShipManager::IsCrewOverFull;
%rename("%s") ShipManager::IsSystemHacked;
%rename("%s") ShipManager::ModifyDroneCount;
%rename("%s") ShipManager::ModifyMissileCount;
%rename("%s") ShipManager::ModifyScrapCount;
%rename("%s") ShipManager::PrepareSuperBarrage;
%rename("%s") ShipManager::PrepareSuperDrones;
%rename("%s") ShipManager::RemoveItem;
%rename("%s") ShipManager::ResetScrapLevel;
%rename("%s") ShipManager::RestoreCrewPositions;
%rename("%s") ShipManager::SelectRandomCrew;
%rename("%s") ShipManager::SetDestroyed;
%rename("%s") ShipManager::SetSystemPowerLoss;
%rename("%s") ShipManager::StartFire; // TODO: add this to examples for fun Hyperspace.ships.player:StartFire(1)
%rename("%s") ShipManager::SystemFunctions;
%rename("%s") ShipManager::TeleportCrew; // Teleport crew & get back the list of CrewMembers.
%immutable ShipManager::vSystemList;
%rename("%s") ShipManager::vSystemList;
%immutable ShipManager::oxygenSystem;
%rename("%s") ShipManager::oxygenSystem;
%immutable ShipManager::teleportSystem;
%rename("%s") ShipManager::teleportSystem;
%immutable ShipManager::cloakSystem;
%rename("%s") ShipManager::cloakSystem;
%immutable ShipManager::batterySystem;
%rename("%s") ShipManager::batterySystem;
%immutable ShipManager::mindSystem;
%rename("%s") ShipManager::mindSystem;
%immutable ShipManager::cloneSystem;
%rename("%s") ShipManager::cloneSystem;
%immutable ShipManager::hackingSystem;
%rename("%s") ShipManager::hackingSystem;
//%rename("%s") ShipManager::showNetwork;
//%rename("%s") ShipManager::addedSystem;
%immutable ShipManager::shieldSystem;
%rename("%s") ShipManager::shieldSystem;
%immutable ShipManager::weaponSystem;
%rename("%s") ShipManager::weaponSystem;
%immutable ShipManager::droneSystem;
%rename("%s") ShipManager::droneSystem;
%immutable ShipManager::engineSystem;
%rename("%s") ShipManager::engineSystem;
%immutable ShipManager::medbaySystem;
%rename("%s") ShipManager::medbaySystem;
%immutable ShipManager::artillerySystems;
%rename("%s") ShipManager::artillerySystems;
%immutable ShipManager::vCrewList;
%rename("%s") ShipManager::vCrewList;
%rename("%s") ShipManager::fireSpreader;
%rename("%s") ShipManager::ship;
%immutable ShipManager::ship;
//%rename("%s") ShipManager::statusMessages;
//%rename("%s") ShipManager::bGameOver;
%immutable ShipManager::current_target;
%rename("%s") ShipManager::current_target; 
%immutable ShipManager::jump_timer;
%rename("%s") ShipManager::jump_timer;
//%immutable ShipManager::fuel_count;
%rename("%s") ShipManager::fuel_count;
//%immutable ShipManager::hostile_ship;
//%rename("%s") ShipManager::hostile_ship;
%immutable ShipManager::bDestroyed;
%rename("%s") ShipManager::bDestroyed;
%immutable ShipManager::iLastDamage;
%rename("%s") ShipManager::iLastDamage;
//%rename("%s") ShipManager::damMessages;
//%rename("%s") ShipManager::systemKey;
%immutable ShipManager::currentScrap;
%rename("%s") ShipManager::currentScrap;
%immutable ShipManager::bJumping;
%rename("%s") ShipManager::bJumping;
//%immutable ShipManager::bAutomated;
%rename("%s") ShipManager::bAutomated;
%immutable ShipManager::shipLevel;
%rename("%s") ShipManager::shipLevel;
%immutable ShipManager::myBlueprint;
%rename("%s") ShipManager::myBlueprint;
%immutable ShipManager::lastEngineStatus;
%rename("%s") ShipManager::lastEngineStatus;
%immutable ShipManager::lastJumpReady;
%rename("%s") ShipManager::lastJumpReady;
%immutable ShipManager::bContainsPlayerCrew;
%rename("%s") ShipManager::bContainsPlayerCrew;
%immutable ShipManager::iIntruderCount;
%rename("%s") ShipManager::iIntruderCount;
%immutable ShipManager::crewCounts;
%rename("%s") ShipManager::crewCounts;
%immutable ShipManager::tempDroneCount;
%rename("%s") ShipManager::tempDroneCount;
%immutable ShipManager::tempMissileCount;
%rename("%s") ShipManager::tempMissileCount;
%immutable ShipManager::tempVision;
%rename("%s") ShipManager::tempVision;
%rename("%s") ShipManager::bHighlightCrew;
%rename("%s") ShipManager::spaceDrones;
%rename("%s") ShipManager::bShowRoom;
%rename("%s") ShipManager::superBarrage;
%rename("%s") ShipManager::bInvincible;
%rename("%s") ShipManager::superDrones;
%rename("%s") ShipManager::failedDodgeCounter;
%immutable ShipManager::iCustomizeMode;
%rename("%s") ShipManager::iCustomizeMode;
//%immutable ShipManager::hitByBeam;
//%rename("%s") ShipManager::hitByBeam;
%rename("%s") ShipManager::enemyDamagedUncloaked;
%rename("%s") ShipManager::damageCloaked;
//%immutable ShipManager::killedByBeam;
//%rename("%s") ShipManager::killedByBeam;
//%rename("%s") ShipManager::minBeaconHealth;
//%immutable ShipManager::fireExtinguishers;
//%rename("%s") ShipManager::fireExtinguishers;
//%rename("%s") ShipManager::bWasSafe;
%immutable ShipManager::_targetable;
%rename("%s") ShipManager::_targetable;

%immutable ShipManager::extend;
%rename("%s") ShipManager::extend;

%extend ShipManager {
    ShipManager_Extend* extend;
}
%wrapper %{
    static ShipManager_Extend *ShipManager_extend_get(ShipManager* shipManager)
    {
        return Get_ShipManager_Extend(shipManager);
    };
%}

%nodefaultctor ShipManager_Extend;
%rename("%s") ShipManager_Extend;
//Potential fix for fireSpreader indexing issue
%rename("%s") ShipManager::GetFireAtPoint;
%rename("%s") ShipManager::GetFire;
%extend ShipManager {
    //Or some similar helper method, because indexing the fireSpreader grid in lua returns vectors and fires by value and not by reference, meaning the relevant Fire objects cannot be edited

    //Possible Methods

    //Get fire at spacial coordinates
    Fire& GetFireAtPoint(float x, float y)
    {
        Point fireCoordinates = ShipGraph::TranslateToGrid(x, y);
        return $self->fireSpreader.grid[fireCoordinates.x][fireCoordinates.y];
    }

    //Get fire at spacial coordintes (Point form)
    Fire& GetFireAtPoint(Point p)
    {
        Point fireCoordinates = ShipGraph::TranslateToGrid(p.x, p.y);
        return $self->fireSpreader.grid[fireCoordinates.x][fireCoordinates.y];
    }

    //Get fire at spacial coordinates (Pointf form)
    Fire& GetFireAtPoint(Pointf p)
    {
        Point fireCoordinates = ShipGraph::TranslateToGrid(p.x, p.y);
        return $self->fireSpreader.grid[fireCoordinates.x][fireCoordinates.y];
    }

    //Indexing function, grid coordinates
    Fire& GetFire(int x, int y)
    {
        return $self->fireSpreader.grid[x][y];
    }
}


%rename("%s") Spreader_Fire;
%rename("%s") Spreader_Fire::count;
%rename("%s") Spreader_Fire::roomCount;
%rename("%s") Spreader_Fire::grid;

%nodefaultctor Selectable;
%nodefaultdtor Selectable;
%rename("%s") Selectable;
%rename("%s") Selectable::selectedState;

%nodefaultctor Repairable;
%nodefaultdtor Repairable;
%rename("%s") Repairable;
%rename("%s") Repairable::shipObj;
%rename("%s") Repairable::fDamage;
%rename("%s") Repairable::pLoc;
%rename("%s") Repairable::fMaxDamage;
%rename("%s") Repairable::name;
%rename("%s") Repairable::roomId;
%rename("%s") Repairable::iRepairCount;


%nodefaultctor Spreadable;
%nodefaultdtor Spreadable;
%rename("%s") Spreadable;
%rename("%s") Spreadable::soundName;

%nodefaultctor Fire;
%nodefaultdtor Fire;
%rename("%s") Fire;
%rename("%s") Fire::OnLoop;
%rename("%s") Fire::UpdateDeathTimer;
%rename("%s") Fire::UpdateStartTimer;

%rename("%s") Fire::fDeathTimer;
%rename("%s") Fire::fStartTimer;
%rename("%s") Fire::fOxygen;
%rename("%s") Fire::fireAnimation;
%rename("%s") Fire::smokeAnimation;
%rename("%s") Fire::bWasOnFire;

%nodefaultctor OuterHull;
%nodefaultdtor OuterHull;
%rename("%s") OuterHull;
%rename("%s") OuterHull::breach;
%rename("%s") OuterHull::heal;

%nodefaultctor PowerManager;
%nodefaultdtor PowerManager;
%rename("%s") PowerManager;
%rename("%s") PowerManager::GetAvailablePower;
%rename("%s") PowerManager::GetMaxPower;
%rename("%s") PowerManager::GetPowerManager;
%rename("%s") PowerManager::currentPower;
%rename("%s") PowerManager::over_powered;
%rename("%s") PowerManager::fFuel;
%rename("%s") PowerManager::failedPowerup;
%rename("%s") PowerManager::iTempPowerCap;
%rename("%s") PowerManager::iTempPowerLoss;
%rename("%s") PowerManager::iTempDividePower;
%rename("%s") PowerManager::iHacked;
%rename("%s") PowerManager::batteryPower;

%nodefaultctor OxygenSystem;
%nodefaultdtor OxygenSystem;
%rename("%s") OxygenSystem;
%rename("%s") OxygenSystem::EmptyOxygen;
%rename("%s") OxygenSystem::GetRefillSpeed;
%rename("%s") OxygenSystem::ModifyRoomOxygen;
%rename("%s") OxygenSystem::max_oxygen;
%rename("%s") OxygenSystem::oxygenLevels;
%rename("%s") OxygenSystem::fTotalOxygen;
%immutable OxygenSystem::bLeakingO2;
%rename("%s") OxygenSystem::bLeakingO2;

%nodefaultctor TeleportSystem;
%nodefaultdtor TeleportSystem;
%rename("%s") TeleportSystem;
%rename("%s") TeleportSystem::CanReceive;
%rename("%s") TeleportSystem::CanSend;
%rename("%s") TeleportSystem::Charged;
%rename("%s") TeleportSystem::ForceReady;
%rename("%s") TeleportSystem::GetChargedPercent;
%rename("%s") TeleportSystem::InitiateTeleport;
%rename("%s") TeleportSystem::SetArmed;
%rename("%s") TeleportSystem::SetHackingLevel;
%rename("%s") TeleportSystem::chargeLevel;
%rename("%s") TeleportSystem::bCanSend;
%rename("%s") TeleportSystem::bCanReceive;
%rename("%s") TeleportSystem::iArmed;
%rename("%s") TeleportSystem::crewSlots;
%rename("%s") TeleportSystem::iPreparedCrew;
%rename("%s") TeleportSystem::iNumSlots;
%rename("%s") TeleportSystem::bSuperShields;

%nodefaultctor CloakingSystem;
%nodefaultdtor CloakingSystem;
%rename("%s") CloakingSystem;
%rename("%s") CloakingSystem::bTurnedOn;
%rename("%s") CloakingSystem::timer;
%rename("%s") CloakingSystem::soundeffect;

%nodefaultctor BatterySystem;
%nodefaultdtor BatterySystem;
%rename("%s") BatterySystem;
%rename("%s") BatterySystem::bTurnedOn;
%rename("%s") BatterySystem::soundeffect;

%nodefaultctor MindSystem;
%nodefaultdtor MindSystem;
%rename("%s") MindSystem;
%rename("%s") MindSystem::SetArmed;
%rename("%s") MindSystem::controlTimer;
%rename("%s") MindSystem::bCanUse;
%rename("%s") MindSystem::iArmed;
%rename("%s") MindSystem::controlledCrew;
%rename("%s") MindSystem::bSuperShields;
%rename("%s") MindSystem::bBlocked;
%rename("%s") MindSystem::iQueuedTarget;
%rename("%s") MindSystem::iQueuedShip;
%rename("%s") MindSystem::queuedCrew;

%nodefaultctor CloneSystem;
%nodefaultdtor CloneSystem;
%rename("%s") CloneSystem;
%rename("%s") CloneSystem::fTimeToClone;
%rename("%s") CloneSystem::clone;
%rename("%s") CloneSystem::fTimeGoal;
%rename("%s") CloneSystem::fDeathTime;
%rename("%s") CloneSystem::slot;
%rename("%s") CloneSystem::bottom;
%rename("%s") CloneSystem::top;
%rename("%s") CloneSystem::gas;

%nodefaultctor HackingSystem;
%nodefaultdtor HackingSystem;
%rename("%s") HackingSystem;
%rename("%s") HackingSystem::BlowHackingDrone;
%rename("%s") HackingSystem::bHacking;
%rename("%s") HackingSystem::drone;
%rename("%s") HackingSystem::bBlocked;
%rename("%s") HackingSystem::bArmed;
%rename("%s") HackingSystem::currentSystem;
%rename("%s") HackingSystem::effectTimer;
%rename("%s") HackingSystem::bCanHack;
%rename("%s") HackingSystem::queuedSystem;
%rename("%s") HackingSystem::spendDrone;

%nodefaultctor Shields;
%nodefaultdtor Shields;
%rename("%s") Shields;

%nodefaultctor Shields::Shield;
%nodefaultdtor Shields::Shield;
%rename("%s") Shields::Shield;
%rename("%s") Shields::Shield::charger;
%rename("%s") Shields::Shield::power;
%rename("%s") Shields::Shield::superTimer;

/*
%nodefaultctor Shields::ShieldAnimation;
%nodefaultdtor Shields::ShieldAnimation;
%rename("%s") Shields::ShieldAnimation;
%rename("%s") Shields::ShieldAnimation::location;
%rename("%s") Shields::ShieldAnimation::current_size;
%rename("%s") Shields::ShieldAnimation::end_size;
%rename("%s") Shields::ShieldAnimation::current_thickness;
%rename("%s") Shields::ShieldAnimation::end_thickness;
%rename("%s") Shields::ShieldAnimation::length;
%rename("%s") Shields::ShieldAnimation::dx;
%rename("%s") Shields::ShieldAnimation::side;
%rename("%s") Shields::ShieldAnimation::ownerId;
%rename("%s") Shields::ShieldAnimation::damage;
*/
%rename("%s") Shields::AddSuperShield;
%rename("%s") Shields::CollisionReal;
%rename("%s") Shields::InstantCharge;
%rename("%s") Shields::SetBaseEllipse;
%rename("%s") Shields::ellipseRatio;
%rename("%s") Shields::center;
%rename("%s") Shields::baseShield;
%rename("%s") Shields::iHighlightedSide;
%rename("%s") Shields::shields;
%rename("%s") Shields::shields_shutdown;
%rename("%s") Shields::shieldHits;
%rename("%s") Shields::shieldsDown;
%rename("%s") Shields::superShieldDown;
%rename("%s") Shields::shieldsDownPoint;
%rename("%s") Shields::shieldsUp;
%rename("%s") Shields::shieldImage;
%rename("%s") Shields::shieldPrimitive;
%rename("%s") Shields::shieldImageName;
%rename("%s") Shields::bEnemyPresent;
//%rename("%s") Shields::damMessages;
%rename("%s") Shields::bBarrierMode;
%rename("%s") Shields::lastHitTimer;
%rename("%s") Shields::chargeTime;
%rename("%s") Shields::lastHitShieldLevel;
%rename("%s") Shields::superShieldUp;
%rename("%s") Shields::superUpLoc;
%rename("%s") Shields::bExcessChargeHack;

%nodefaultctor WeaponSystem;
%nodefaultdtor WeaponSystem;
%rename("%s") WeaponSystem;
%rename("%s") WeaponSystem::RemoveWeapon;
%rename("%s") WeaponSystem::SetBonusPower;
%rename("%s") WeaponSystem::target;
%rename("%s") WeaponSystem::weapons;
%rename("%s") WeaponSystem::weaponsTrashList;
%rename("%s") WeaponSystem::shot_timer;
%rename("%s") WeaponSystem::shot_count;
%rename("%s") WeaponSystem::missile_count;
%rename("%s") WeaponSystem::missile_start;
%rename("%s") WeaponSystem::userPowered;
%rename("%s") WeaponSystem::slot_count;
%rename("%s") WeaponSystem::iStartingBatteryPower;
%rename("%s") WeaponSystem::repowerList;

%nodefaultctor DroneSystem;
%nodefaultdtor DroneSystem;
%rename("%s") DroneSystem;
%rename("%s") DroneSystem::DePowerDrone;
%rename("%s") DroneSystem::RemoveDrone;
%rename("%s") DroneSystem::SetBonusPower;
%rename("%s") DroneSystem::drones;
%rename("%s") DroneSystem::drone_count;
%rename("%s") DroneSystem::drone_start;
%rename("%s") DroneSystem::targetShip;
%rename("%s") DroneSystem::userPowered;
%rename("%s") DroneSystem::slot_count;
%rename("%s") DroneSystem::iStartingBatteryPower;
%rename("%s") DroneSystem::repowerList;

%nodefaultctor EngineSystem;
%nodefaultdtor EngineSystem;
%rename("%s") EngineSystem;
%nodefaultctor MedbaySystem;
%nodefaultdtor MedbaySystem;
%rename("%s") MedbaySystem;

%nodefaultctor ArtillerySystem;
%nodefaultdtor ArtillerySystem;
%rename("%s") ArtillerySystem;
%rename("%s") ArtillerySystem::projectileFactory;
%rename("%s") ArtillerySystem::target;
%rename("%s") ArtillerySystem::bCloaked;

//%nodefaultctor ShipSystem;
//%nodefaultdtor ShipSystem;
%rename("%s") ShipSystem;
%rename("%s") ShipSystem::SetSelected;
%rename("%s") ShipSystem::GetSelected;
%rename("%s") ShipSystem::CompletelyDestroyed;
//%rename("%s") ShipSystem::GetName; // crashes the game, use SystemIdToName instead
%rename("%s") ShipSystem::SetName;
%rename("%s") ShipSystem::Repair;
%rename("%s") ShipSystem::PartialRepair;
%rename("%s") ShipSystem::PartialDamage;
%rename("%s") ShipSystem::NeedsRepairing;
%rename("%s") ShipSystem::Functioning;
%rename("%s") ShipSystem::CanBeSabotaged;
%rename("%s") ShipSystem::GetDamage;
//%rename("%s") ShipSystem::GetLocation; // TODO: Is this a new object?
//%rename("%s") ShipSystem::GetGridLocation; // TODO: Is this a new object?
%rename("%s") ShipSystem::SetDamage;
%rename("%s") ShipSystem::SetMaxDamage;
%rename("%s") ShipSystem::SetLocation;
%rename("%s") ShipSystem::GetId;
%rename("%s") ShipSystem::IsRoomBased;
%rename("%s") ShipSystem::GetRoomId;
%rename("%s") ShipSystem::Ioned;
%rename("%s") ShipSystem::SetRoomId;
%rename("%s") ShipSystem::SetHackingLevel;
%rename("%s") ShipSystem::ForceBatteryPower;
%rename("%s") ShipSystem::RemoveBatteryPower;
//%rename("%s") ShipSystem::GetWeaponInfo; // New object needs cleanup?
//%rename("%s") ShipSystem::GetOverrideTooltip; // New object needs cleanup?
%rename("%s") ShipSystem::CheckMaxPower;
%rename("%s") ShipSystem::CheckForRepower;
%rename("%s") ShipSystem::SetBonusPower;
%rename("%s") ShipSystem::AddDamage;
%rename("%s") ShipSystem::ForceDecreasePower;
%rename("%s") ShipSystem::ForceIncreasePower;
%rename("%s") ShipSystem::StopHacking;
%rename("%s") ShipSystem::GetNeedsPower;
%rename("%s") ShipSystem::Clickable;
%rename("%s") ShipSystem::Powered;
%rename("%s") ShipSystem::AddLock;
%rename("%s") ShipSystem::ClearStatus;
%rename("%s") ShipSystem::DamageOverTime;
%rename("%s") ShipSystem::DecreasePower;
%rename("%s") ShipSystem::GetEffectivePower;
%rename("%s") ShipSystem::GetLevelDescription;
%rename("%s") ShipSystem::GetLocked;
%rename("%s") ShipSystem::GetMaxPower;
%rename("%s") ShipSystem::GetPowerCap;
%rename("%s") ShipSystem::IncreasePower;
%rename("%s") ShipSystem::IsMannedBoost;
%rename("%s") ShipSystem::IsSubsystem;
%rename("%s") ShipSystem::LockSystem;
%rename("%s") ShipSystem::NameToSystemId;
%rename("%s") ShipSystem::SetPowerCap;
%rename("%s") ShipSystem::SetPowerLoss;
%rename("%s") ShipSystem::SystemIdToName;
%rename("%s") ShipSystem::UpgradeSystem;
//%rename("%s") ShipSystem::selectedState;
//%rename("%s") ShipSystem::_shipObj;
%rename("%s") ShipSystem::fDamage;
%rename("%s") ShipSystem::pLoc;
%rename("%s") ShipSystem::fMaxDamage;
%rename("%s") ShipSystem::name;
%rename("%s") ShipSystem::roomId;
%rename("%s") ShipSystem::iRepairCount;
%rename("%s") ShipSystem::iSystemType;
%rename("%s") ShipSystem::bNeedsManned;
%rename("%s") ShipSystem::bManned;
%rename("%s") ShipSystem::iActiveManned;
%rename("%s") ShipSystem::bBoostable;
%rename("%s") ShipSystem::powerState;
%rename("%s") ShipSystem::iRequiredPower;
//%rename("%s") ShipSystem::imageIcon;
//%rename("%s") ShipSystem::iconPrimitive;
//%rename("%s") ShipSystem::iconBorderPrimitive;
//%rename("%s") ShipSystem::iconPrimitives;
//%rename("%s") ShipSystem::partialDamageRect;
//%rename("%s") ShipSystem::lockOutline;
//%rename("%s") ShipSystem::roomShape;
%rename("%s") ShipSystem::bOnFire;
%rename("%s") ShipSystem::bBreached;
%rename("%s") ShipSystem::healthState;
%rename("%s") ShipSystem::fDamageOverTime;
%rename("%s") ShipSystem::fRepairOverTime;
%rename("%s") ShipSystem::damagedLastFrame;
%rename("%s") ShipSystem::repairedLastFrame;
%rename("%s") ShipSystem::originalPower;
%rename("%s") ShipSystem::bNeedsPower;
%rename("%s") ShipSystem::iTempPowerCap;
%rename("%s") ShipSystem::iTempPowerLoss;
%rename("%s") ShipSystem::iTempDividePower;
%rename("%s") ShipSystem::iLockCount;
%rename("%s") ShipSystem::lockTimer;
%rename("%s") ShipSystem::bExploded;
%rename("%s") ShipSystem::bOccupied;
%rename("%s") ShipSystem::bFriendlies;
%rename("%s") ShipSystem::interiorImageName;
%rename("%s") ShipSystem::interiorImage;
%rename("%s") ShipSystem::interiorImageOn;
%rename("%s") ShipSystem::interiorImageManned;
%rename("%s") ShipSystem::interiorImageMannedFancy;
%rename("%s") ShipSystem::lastUserPower;
%rename("%s") ShipSystem::iBonusPower;
%rename("%s") ShipSystem::iLastBonusPower;
%rename("%s") ShipSystem::location;
%rename("%s") ShipSystem::bpCost;
%rename("%s") ShipSystem::flashTracker;
%rename("%s") ShipSystem::maxLevel;
%rename("%s") ShipSystem::iBatteryPower;
%rename("%s") ShipSystem::iHackEffect;
%rename("%s") ShipSystem::bUnderAttack;
%rename("%s") ShipSystem::bLevelBoostable;
%rename("%s") ShipSystem::bTriggerIon;
//%rename("%s") ShipSystem::damagingEffects;
%rename("%s") ShipSystem::computerLevel;

%immutable ShipSystem::extend;
%rename("%s") ShipSystem::extend;

%extend ShipSystem {
    ShipSystem_Extend* extend;
}
%wrapper %{
    static ShipSystem_Extend *ShipSystem_extend_get(ShipSystem* shipSystem)
    {
        return Get_ShipSystem_Extend(shipSystem);
    };
%}

%nodefaultctor ShipSystem_Extend;
%rename("%s") ShipSystem_Extend;
%rename("%s") ShipSystem_Extend::additionalPowerLoss;

%nodefaultctor ProjectileFactory;
%nodefaultdtor ProjectileFactory;
%rename("%s") ProjectileFactory;
%rename("%s") ProjectileFactory::Fire;
%rename("%s") ProjectileFactory::FireNextShot;
%rename("%s") ProjectileFactory::ForceCoolup;
%rename("%s") ProjectileFactory::GetProjectile;
%rename("%s") ProjectileFactory::IsChargedGoal;
%rename("%s") ProjectileFactory::NumTargetsRequired;
%rename("%s") ProjectileFactory::SetCooldownModifier;
%rename("%s") ProjectileFactory::SetCurrentShip;
%rename("%s") ProjectileFactory::SetHacked;
//%rename("%s") ProjectileFactory::SpendMissiles;
//%rename("%s") ProjectileFactory::StringToWeapon;
%rename("%s") ProjectileFactory::cooldown;
%rename("%s") ProjectileFactory::subCooldown;
%rename("%s") ProjectileFactory::baseCooldown;
%rename("%s") ProjectileFactory::blueprint;
%rename("%s") ProjectileFactory::localPosition;
%rename("%s") ProjectileFactory::flight_animation;
%rename("%s") ProjectileFactory::autoFiring;
%rename("%s") ProjectileFactory::fireWhenReady;
%rename("%s") ProjectileFactory::powered;
%rename("%s") ProjectileFactory::requiredPower;
%rename("%s") ProjectileFactory::targets;
%rename("%s") ProjectileFactory::lastTargets;
%rename("%s") ProjectileFactory::targetId;
%rename("%s") ProjectileFactory::iAmmo;
%rename("%s") ProjectileFactory::name;
%rename("%s") ProjectileFactory::numShots;
%rename("%s") ProjectileFactory::currentFiringAngle;
%rename("%s") ProjectileFactory::currentEntryAngle;
%rename("%s") ProjectileFactory::currentShipTarget;
%rename("%s") ProjectileFactory::weaponVisual;
%rename("%s") ProjectileFactory::mount;
%rename("%s") ProjectileFactory::queuedProjectiles;
%rename("%s") ProjectileFactory::iBonusPower;
%rename("%s") ProjectileFactory::bFiredOnce;
%rename("%s") ProjectileFactory::iSpendMissile;
%rename("%s") ProjectileFactory::cooldownModifier;
%rename("%s") ProjectileFactory::shotsFiredAtTarget;
%rename("%s") ProjectileFactory::radius;
%rename("%s") ProjectileFactory::boostLevel;
%rename("%s") ProjectileFactory::lastProjectileId;
%rename("%s") ProjectileFactory::chargeLevel;
%rename("%s") ProjectileFactory::iHackLevel;
%rename("%s") ProjectileFactory::goalChargeLevel;
%rename("%s") ProjectileFactory::isArtillery;

%nodefaultctor WeaponMount;
%nodefaultdtor WeaponMount;
%rename("%s") WeaponMount;
%rename("%s") WeaponMount::position;
%rename("%s") WeaponMount::mirror;
%rename("%s") WeaponMount::rotate;
%rename("%s") WeaponMount::slide;
%rename("%s") WeaponMount::gib;

%nodefaultctor AnimationControl;
%nodefaultdtor AnimationControl;
%rename("%s") AnimationControl;
%rename("%s") AnimationControl::GetAnimation;

%nodefaultctor AnimationDescriptor;
%nodefaultdtor AnimationDescriptor;
%rename("%s") AnimationDescriptor;
%rename("%s") AnimationDescriptor::numFrames;
%rename("%s") AnimationDescriptor::imageWidth;
%rename("%s") AnimationDescriptor::imageHeight;
%rename("%s") AnimationDescriptor::stripStartY;
%rename("%s") AnimationDescriptor::stripStartX;
%rename("%s") AnimationDescriptor::frameWidth;
%rename("%s") AnimationDescriptor::frameHeight;

%nodefaultctor WeaponAnimation;
%nodefaultdtor WeaponAnimation;
%rename("%s") WeaponAnimation;
%rename("%s") WeaponAnimation::GetSlide;
%rename("%s") WeaponAnimation::SetFireTime;
%rename("%s") WeaponAnimation::anim;
%rename("%s") WeaponAnimation::bFireShot;
%rename("%s") WeaponAnimation::bFiring;
%rename("%s") WeaponAnimation::fChargeLevel;
%rename("%s") WeaponAnimation::iChargedFrame;
%rename("%s") WeaponAnimation::iFireFrame;
%rename("%s") WeaponAnimation::bMirrored;
%rename("%s") WeaponAnimation::bRotation;
%rename("%s") WeaponAnimation::fireLocation;
%rename("%s") WeaponAnimation::bPowered;
%rename("%s") WeaponAnimation::mountPoint;
%rename("%s") WeaponAnimation::renderPoint;
%rename("%s") WeaponAnimation::fireMountVector;
%rename("%s") WeaponAnimation::slideTracker;
%rename("%s") WeaponAnimation::slideDirection;
//%rename("%s") WeaponAnimation::iChargeImage;
%rename("%s") WeaponAnimation::explosionAnim;
%rename("%s") WeaponAnimation::mount;
%rename("%s") WeaponAnimation::fDelayChargeTime;
%rename("%s") WeaponAnimation::boostAnim;
%rename("%s") WeaponAnimation::boostLevel;
%rename("%s") WeaponAnimation::bShowCharge;
%rename("%s") WeaponAnimation::fActualChargeLevel;
%rename("%s") WeaponAnimation::iChargeOffset;
%rename("%s") WeaponAnimation::iChargeLevels;
%rename("%s") WeaponAnimation::currentOffset;
//%rename("%s") WeaponAnimation::chargeBox;
//%rename("%s") WeaponAnimation::chargeBar;
%rename("%s") WeaponAnimation::iHackLevel;
%rename("%s") WeaponAnimation::hackSparks;
%rename("%s") WeaponAnimation::playerShip;

%nodefaultctor Animation;
%nodefaultdtor Animation;
%rename("%s") Animation;
%rename("%s") Animation::AddSoundQueue;
%rename("%s") Animation::Done;
%rename("%s") Animation::LoadState;
%rename("%s") Animation::OnRender;
%rename("%s") Animation::RandomStart;
%rename("%s") Animation::SaveState;
%rename("%s") Animation::SetAnimationId;
%rename("%s") Animation::SetCurrentFrame;
%rename("%s") Animation::SetProgress;
%rename("%s") Animation::Start;
%rename("%s") Animation::StartReverse;
%rename("%s") Animation::Update;
%rename("%s") Animation::animationStrip;
%rename("%s") Animation::info;
%rename("%s") Animation::tracker;
%rename("%s") Animation::position;
%rename("%s") Animation::soundForward;
%rename("%s") Animation::soundReverse;
%rename("%s") Animation::randomizeFrames;
%rename("%s") Animation::fScale;
%rename("%s") Animation::fYStretch;
%rename("%s") Animation::currentFrame;
%rename("%s") Animation::bAlwaysMirror;
%rename("%s") Animation::soundQueue;
%rename("%s") Animation::fadeOut;
%rename("%s") Animation::startFadeOut;
%rename("%s") Animation::animName;
%rename("%s") Animation::mask_x_pos;
%rename("%s") Animation::mask_x_size;
%rename("%s") Animation::mask_y_pos;
%rename("%s") Animation::mask_y_size;
%rename("%s") Animation::primitive;
%rename("%s") Animation::mirroredPrimitive;

%nodefaultctor Ship;
%nodefaultdtor Ship;
%rename("%s") Ship;
%rename("%s") Ship::DoorStateType;
%rename("%s") Ship::GetRoomCenter;
/*
%nodefaultctor Ship::DoorState;
%nodefaultdtor Ship::DoorState;
%rename("%s") Ship::DoorState;
%rename("%s") Ship::DoorState::state;
%rename("%s") Ship::DoorState::hacked;
%rename("%s") Ship::DoorState::level;
*/
%rename("%s") Ship::BreachRandomHull;
%rename("%s") Ship::EmptySlots;
%rename("%s") Ship::FullRoom;
%rename("%s") Ship::GetAvailableRoomSlot;
%rename("%s") Ship::GetBaseEllipse;
%rename("%s") Ship::GetSelectedRoomId;
%rename("%s") Ship::LockdownRoom;
%rename("%s") Ship::RoomLocked;
%rename("%s") Ship::SetRoomBlackout;
%rename("%s") Ship::SetSelectedRoom;
%rename("%s") Ship::iShipId; // just in case
%rename("%s") Ship::vRoomList; // TODO: Expose Room
%rename("%s") Ship::vDoorList;
%rename("%s") Ship::vOuterWalls; 
%rename("%s") Ship::vOuterAirlocks;
%rename("%s") Ship::hullIntegrity;
%rename("%s") Ship::weaponMounts;
%rename("%s") Ship::floorImageName;
%rename("%s") Ship::shipFloor;
%rename("%s") Ship::floorPrimitive;
%rename("%s") Ship::shipImageName;
%rename("%s") Ship::shipImage;
%rename("%s") Ship::glowOffset;
%rename("%s") Ship::shipImagePrimitive;
%rename("%s") Ship::cloakImageName;
%rename("%s") Ship::shipImageCloak;
%rename("%s") Ship::cloakPrimitive;
%rename("%s") Ship::gridPrimitive;
%rename("%s") Ship::wallsPrimitive;
%rename("%s") Ship::doorsPrimitive;
%rename("%s") Ship::doorState;
%rename("%s") Ship::lastDoorControlMode;
%rename("%s") Ship::thrustersImage;
%rename("%s") Ship::jumpGlare;
%rename("%s") Ship::vertical_shift;
%rename("%s") Ship::horizontal_shift;
%rename("%s") Ship::shipName;
//%rename("%s") Ship::explosion; // TODO: Expose ExplosionAnimation
%rename("%s") Ship::bDestroyed;
%rename("%s") Ship::baseEllipse;
%rename("%s") Ship::engineAnim;
%rename("%s") Ship::cloakingTracker;
%rename("%s") Ship::bCloaked;
%rename("%s") Ship::bExperiment;
%rename("%s") Ship::bShowEngines;
//%rename("%s") Ship::lockdowns; // TODO: Expose LockdownShard


//Expose Hyperspace engine anims as a member variable
//Note: Pairs are returned by value rather than by reference, change if there is a need for mutability via lua
%immutable Ship::extraEngineAnim;
%rename("%s") Ship::extraEngineAnim;

%extend Ship {
   std::vector<std::pair<Animation,int8_t>> extraEngineAnim;
}
%wrapper %{
    static std::vector<std::pair<Animation,int8_t>>* Ship_extraEngineAnim_get(Ship* ship)
    {
        return &extraEngineAnim[ship->iShipId];
    };
%}


%nodefaultctor Room;
%nodefaultdtor Room;
%rename("%s") Room;

%rename("%s") Room::bBlackedOut;
%immutable Room::rect;
%rename("%s") Room::rect;
%immutable Room::iRoomId;
%rename("%s") Room::iRoomId;

%immutable Room::extend;
%rename("%s") Room::extend;


%extend Room {
    Room_Extend* extend;
}
%wrapper %{
    static Room_Extend *Room_extend_get(Room* room)
    {
        return Get_Room_Extend(room);
    };
%}

%nodefaultctor Room_Extend;
%rename("%s") Room_Extend;
%rename("%s") Room_Extend::sysDamageResistChance;
%rename("%s") Room_Extend::ionDamageResistChance;
%rename("%s") Room_Extend::timeDilation;

%nodefaultctor Door;
%nodefaultdtor Door;
%rename("%s") Door;

%rename("%s") Door::ApplyDamage;

%rename("%s") Door::iRoom1;
%immutable Door::iRoom1;
%rename("%s") Door::iRoom2;
%immutable Door::iRoom2;
%rename("%s") Door::bOpen;
%rename("%s") Door::iBlast;
%rename("%s") Door::bFakeOpen;
%rename("%s") Door::width;
%immutable Door::width;
%rename("%s") Door::height;
%immutable Door::height;
%rename("%s") Door::outlinePrimitive;
%rename("%s") Door::highlightPrimitive;
%rename("%s") Door::doorAnim;
%rename("%s") Door::doorAnimLarge;
%rename("%s") Door::iDoorId;
%immutable Door::iDoorId;
%rename("%s") Door::baseHealth;
%rename("%s") Door::health;
%rename("%s") Door::forcedOpen;
%rename("%s") Door::gotHit;
%rename("%s") Door::doorLevel;
%rename("%s") Door::bIoned;
%rename("%s") Door::fakeOpenTimer;
%rename("%s") Door::lockedDown;
%rename("%s") Door::lastbase;
%rename("%s") Door::iHacked;
%rename("%s") Door::x;
%immutable Door::x;
%rename("%s") Door::y;
%immutable Door::y;
%rename("%s") Door::bVertical;
%immutable Door::bVertical;

%nodefaultctor BlueprintManager;
%nodefaultdtor BlueprintManager;
%rename("%s") BlueprintManager;
%rename("%s") BlueprintManager::GetAugmentBlueprint;
%rename("%s") BlueprintManager::GetCrewBlueprint;
%rename("%s") BlueprintManager::GetDroneBlueprint;
%rename("%s") BlueprintManager::GetShipBlueprint;
%rename("%s") BlueprintManager::GetWeaponBlueprint;
%rename("%s") BlueprintManager::GetBlueprintList;

%nodefaultctor WeaponBlueprint;
%nodefaultdtor WeaponBlueprint;
%rename("%s") WeaponBlueprint;
%rename("%s") WeaponBlueprint::BoostPower;
%rename("%s") WeaponBlueprint::BoostPower::type;
%rename("%s") WeaponBlueprint::BoostPower::amount;
%rename("%s") WeaponBlueprint::BoostPower::count;
%rename("%s") WeaponBlueprint::MiniProjectile;
%rename("%s") WeaponBlueprint::MiniProjectile::image;
%rename("%s") WeaponBlueprint::MiniProjectile::fake;
%rename("%s") WeaponBlueprint::typeName;
%rename("%s") WeaponBlueprint::damage;
%rename("%s") WeaponBlueprint::shots;
%rename("%s") WeaponBlueprint::missiles;
%rename("%s") WeaponBlueprint::cooldown;
%rename("%s") WeaponBlueprint::power;
%rename("%s") WeaponBlueprint::length;
%rename("%s") WeaponBlueprint::speed;
%rename("%s") WeaponBlueprint::miniCount;
%rename("%s") WeaponBlueprint::effects;
%rename("%s") WeaponBlueprint::weaponArt;
%rename("%s") WeaponBlueprint::combatIcon;
%rename("%s") WeaponBlueprint::explosion;
%rename("%s") WeaponBlueprint::radius;
%rename("%s") WeaponBlueprint::miniProjectiles;
%rename("%s") WeaponBlueprint::boostPower;
%rename("%s") WeaponBlueprint::drone_targetable;
%rename("%s") WeaponBlueprint::spin;
%rename("%s") WeaponBlueprint::chargeLevels;
%rename("%s") WeaponBlueprint::flavorType;
%rename("%s") WeaponBlueprint::color;

%nodefaultctor EffectsBlueprint;
%nodefaultdtor EffectsBlueprint;
%rename("%s") EffectsBlueprint;
%rename("%s") EffectsBlueprint::launchSounds;
%rename("%s") EffectsBlueprint::hitShipSounds;
%rename("%s") EffectsBlueprint::hitShieldSounds;
%rename("%s") EffectsBlueprint::missSounds;
%rename("%s") EffectsBlueprint::image;

// TODO: Make most if not all of ShipBlueprint immutable
// Note: Making ShipBlueprint immutable would make it more difficult to create custom blueprints on the fly
//%nodefaultctor ShipBlueprint;
//%nodefaultdtor ShipBlueprint;
%rename("%s") ShipBlueprint;
%copyctor ShipBlueprint;

//%nodefaultctor ShipBlueprint::SystemTemplate;
//%nodefaultdtor ShipBlueprint::SystemTemplate;
%rename("%s") ShipBlueprint::SystemTemplate;
%rename("%s") ShipBlueprint::SystemTemplate::systemId;
%rename("%s") ShipBlueprint::SystemTemplate::powerLevel;
%rename("%s") ShipBlueprint::SystemTemplate::location;
%rename("%s") ShipBlueprint::SystemTemplate::bp;
%rename("%s") ShipBlueprint::SystemTemplate::maxPower;
%rename("%s") ShipBlueprint::SystemTemplate::image;
%rename("%s") ShipBlueprint::SystemTemplate::slot;
%rename("%s") ShipBlueprint::SystemTemplate::direction;
%rename("%s") ShipBlueprint::SystemTemplate::weapon;

%rename("%s") ShipBlueprint::desc; // TODO: Expose Description
%rename("%s") ShipBlueprint::blueprintName;
%rename("%s") ShipBlueprint::name;
%rename("%s") ShipBlueprint::shipClass;
%rename("%s") ShipBlueprint::layoutFile;
%rename("%s") ShipBlueprint::imgFile;
%rename("%s") ShipBlueprint::cloakFile;
%rename("%s") ShipBlueprint::shieldFile;
%rename("%s") ShipBlueprint::floorFile;
%rename("%s") ShipBlueprint::systemInfo;
%rename("%s") ShipBlueprint::systems;
%rename("%s") ShipBlueprint::droneCount;
%rename("%s") ShipBlueprint::originalDroneCount;
%rename("%s") ShipBlueprint::droneSlots;
%rename("%s") ShipBlueprint::loadDrones;
%rename("%s") ShipBlueprint::drones;
%rename("%s") ShipBlueprint::augments;
%rename("%s") ShipBlueprint::weaponCount;
%rename("%s") ShipBlueprint::originalWeaponCount;
%rename("%s") ShipBlueprint::weaponSlots;
%rename("%s") ShipBlueprint::loadWeapons;
%rename("%s") ShipBlueprint::weapons;
%rename("%s") ShipBlueprint::missiles;
%rename("%s") ShipBlueprint::drone_count;
%rename("%s") ShipBlueprint::health;
%rename("%s") ShipBlueprint::originalCrewCount;
%rename("%s") ShipBlueprint::defaultCrew;
%rename("%s") ShipBlueprint::customCrew;
%rename("%s") ShipBlueprint::maxPower;
%rename("%s") ShipBlueprint::boardingAI;
%rename("%s") ShipBlueprint::bp_count;
%rename("%s") ShipBlueprint::maxCrew;
%rename("%s") ShipBlueprint::maxSector;
%rename("%s") ShipBlueprint::minSector;
%rename("%s") ShipBlueprint::unlock;

%rename("%s") ShipBlueprint::ShipBlueprint;

%rename("%s") CustomShipSelect;
%rename("%s") CustomShipSelect::GetInstance;
%rename("%s") CustomShipSelect::GetDefinition;

%rename("%s") CustomShipDefinition;
%rename("%s") CustomShipDefinition::name;
%rename("%s") CustomShipDefinition::hiddenAugs;
%rename("%s") CustomShipDefinition::crewList;
%rename("%s") CustomShipDefinition::noJump;
%rename("%s") CustomShipDefinition::noFuelStalemate;
%rename("%s") CustomShipDefinition::hpCap;
%rename("%s") CustomShipDefinition::startingFuel;
%rename("%s") CustomShipDefinition::startingScrap;
%rename("%s") CustomShipDefinition::roomDefs;
%rename("%s") CustomShipDefinition::shipIcons;
%rename("%s") CustomShipDefinition::forceAutomated;
%rename("%s") CustomShipDefinition::crewLimit;
%rename("%s") CustomShipDefinition::systemLimit;
%rename("%s") CustomShipDefinition::subsystemLimit;
%rename("%s") CustomShipDefinition::reactorPrices;
%rename("%s") CustomShipDefinition::reactorPriceIncrement;
%rename("%s") CustomShipDefinition::maxReactorLevel;
%rename("%s") CustomShipDefinition::shipGenerator;

%rename("%s") CrewPlacementDefinition;
%rename("%s") CrewPlacementDefinition::species;
%rename("%s") CrewPlacementDefinition::roomId;
%rename("%s") CrewPlacementDefinition::name;
%rename("%s") CrewPlacementDefinition::isList;

%rename("%s") CrewBlueprint;
%copyctor CrewBlueprint;
%rename("%s") CrewBlueprint::GetCurrentSkillColor;
%rename("%s") CrewBlueprint::GetNameShort;
%rename("%s") CrewBlueprint::RandomSkills;
%rename("%s") CrewBlueprint::RenderIcon;
%rename("%s") CrewBlueprint::RenderSkill;
%rename("%s") CrewBlueprint::crewNameLong;
%rename("%s") CrewBlueprint::powers;
%rename("%s") CrewBlueprint::male;
%rename("%s") CrewBlueprint::skillLevel;
%rename("%s") CrewBlueprint::colorLayers;
%rename("%s") CrewBlueprint::colorChoices;

//%nodefaultctor Blueprint;
//%nodefaultdtor Blueprint;
%rename("%s") Blueprint;
%rename("%s") Blueprint::GetNameLong;
%rename("%s") Blueprint::GetNameShort;
%rename("%s") Blueprint::GetType;
%rename("%s") Blueprint::name;
%rename("%s") Blueprint::desc;
%rename("%s") Blueprint::type;

%rename("%s") ShipGraph;
%nodefaultctor ShipGraph;
%nodefaultdtor ShipGraph;

%rename("%s") ShipGraph::ConvertToWorldPosition;
%rename("%s") ShipGraph::ConvertToLocalPosition;
%rename("%s") ShipGraph::GetSlotRenderPosition;
%rename("%s") ShipGraph::TranslateFromGrid;
%rename("%s") ShipGraph::TranslateToGrid;
%rename("%s") ShipGraph::GetIntoRoom;
%rename("%s") ShipGraph::GetRoomCenter;

%rename("%s") ShipGraph::ComputeCenter;
%rename("%s") ShipGraph::ConnectedGridSquares;
%rename("%s") ShipGraph::ConnectedGridSquaresPoint;
%rename("%s") ShipGraph::ConnectingDoor;
%rename("%s") ShipGraph::ConnectingDoor;
%rename("%s") ShipGraph::ContainsPoint;
%rename("%s") ShipGraph::ConvertToLocalAngle;
%rename("%s") ShipGraph::ConvertToWorldAngle;
%rename("%s") ShipGraph::Dijkstra;
%rename("%s") ShipGraph::DoorCount;
%rename("%s") ShipGraph::FindPath;
%rename("%s") ShipGraph::GetClosestSlot;
%rename("%s") ShipGraph::GetDoors;
%rename("%s") ShipGraph::GetNumSlots;
%rename("%s") ShipGraph::GetRoomBlackedOut;
%rename("%s") ShipGraph::GetRoomOxygen;
%rename("%s") ShipGraph::GetRoomShape;
%rename("%s") ShipGraph::GetSelectedRoom;
%rename("%s") ShipGraph::GetShipInfo;
%rename("%s") ShipGraph::GetSlotWorldPosition;
%rename("%s") ShipGraph::IsRoomConnected;
%rename("%s") ShipGraph::PopClosestDoor;
%rename("%s") ShipGraph::RoomCount;

%rename("%s") ShipGraph::rooms;
%rename("%s") ShipGraph::doors;
%rename("%s") ShipGraph::doorCounts;
%rename("%s") ShipGraph::center;
%rename("%s") ShipGraph::worldPosition;
%rename("%s") ShipGraph::worldHeading;
%rename("%s") ShipGraph::lastWorldPosition;
%rename("%s") ShipGraph::lastWorldHeading;
%rename("%s") ShipGraph::shipBox;
%rename("%s") ShipGraph::shipName;

%nodefaultctor ShieldPower;
%rename("%s") ShieldPower;
%rename("%s") ShieldPower::first;
%rename("%s") ShieldPower::second;
%rename("%s") ShieldPower::super;

%rename("%s") Damage;
%rename("%s") Damage::iDamage;
%rename("%s") Damage::iShieldPiercing;
%rename("%s") Damage::fireChance;
%rename("%s") Damage::breachChance;
%rename("%s") Damage::stunChance;
%rename("%s") Damage::iIonDamage;
%rename("%s") Damage::iSystemDamage;
%rename("%s") Damage::iPersDamage;
%rename("%s") Damage::bHullBuster;
%rename("%s") Damage::ownerId;
%rename("%s") Damage::selfId;
%rename("%s") Damage::bLockdown;
%rename("%s") Damage::crystalShard;
%rename("%s") Damage::bFriendlyFire;
%rename("%s") Damage::iStun;

%nodefaultctor Collideable;
%rename("%s") Collideable;

%rename("%s") Collideable::CollisionMoving; // checks if a moving object collides with this object
%rename("%s") Collideable::DamageBeam; // damage from a beam swipe (two points)
%rename("%s") Collideable::DamageArea; // damage from a projectile/effect (one point)
%rename("%s") Collideable::DamageShield; // damage to the shield
%rename("%s") Collideable::GetDodged; // checks whether a projectile should miss this object
%rename("%s") Collideable::GetSuperShield;
%rename("%s") Collideable::SetTempVision;
%rename("%s") Collideable::GetSpaceId; // which space the object is in
%rename("%s") Collideable::GetSelfId; // self ID of this object
%rename("%s") Collideable::GetOwnerId; // who owns the object
%rename("%s") Collideable::ValidTargetLocation;

%nodefaultctor Targetable;
%rename("%s") Targetable;

%rename("%s") Targetable::GetWorldCenterPoint; // centre of this object
%rename("%s") Targetable::GetRandomTargettingPoint; // random point that can be targeted (e.g. random room)
%rename("%s") Targetable::GetAllTargettingPoints; // list of all points that can be targeted
%rename("%s") Targetable::GetShieldShape;
%rename("%s") Targetable::GetShieldPower;
%rename("%s") Targetable::GetSpaceId; // which space the object is in
%rename("%s") Targetable::GetSpeed;
%rename("%s") Targetable::GetOwnerId; // who owns the object
%rename("%s") Targetable::GetSelfId; // self ID of this object
%rename("%s") Targetable::IsCloaked;
%rename("%s") Targetable::DamageTarget;
%rename("%s") Targetable::GetIsDying;
%rename("%s") Targetable::GetIsJumping;
%rename("%s") Targetable::ValidTarget;
%rename("%s") Targetable::GetShape;

%rename("%s") Targetable::type;
%rename("%s") Targetable::hostile;
%rename("%s") Targetable::targeted;

%rename("%s") CollisionResponse;
%rename("%s") CollisionResponse::collision_type;
%rename("%s") CollisionResponse::point;
%rename("%s") CollisionResponse::damage;
%rename("%s") CollisionResponse::superDamage;

%nodefaultctor Projectile; // users should only construct subclasses
%rename("%s") Projectile;

%rename("%s") Projectile::CollisionMoving; // checks if a moving object collides with the projectile
%rename("%s") Projectile::GetSpaceId; // which space the projectile is in
%rename("%s") Projectile::GetSelfId; // self ID of this projectile
%rename("%s") Projectile::GetOwnerId; // who owns the projectile

%rename("%s") Projectile::SetWeaponAnimation; // does nothing except for beams, used to link weapon animation to beam progress
%rename("%s") Projectile::OnRenderSpecific; // virtual method for rendering the specific projectile
%rename("CollisionCheck") Projectile::HS_CollisionCheck; // checks if this object is colliding with other object, calls CollisionMoving
%rename("OnUpdate") Projectile::HS_OnUpdate; // updates the projectile position by one frame
%rename("%s") Projectile::GetWorldCenterPoint; // returns the position of the projectile
%rename("%s") Projectile::GetRandomTargettingPoint; // returns the position of the projectile
%rename("%s") Projectile::ComputeHeading; // calculates the correct heading to get from its current position to the target point
%rename("%s") Projectile::SetDestinationSpace; // exactly what it says on the tin
%rename("%s") Projectile::EnterDestinationSpace; // actually transfers the projectile to the destination space
%rename("%s") Projectile::Dead; // checks if the projectile is dead, if death animation is playing then advance a frame and check if it's done
%rename("%s") Projectile::ValidTarget; // can this projectile be targeted (if not destroyed)
%rename("%s") Projectile::Kill; // sets the projectile to be dead; this should skip the animation
%rename("%s") Projectile::GetSpeed; // returns the speed
%rename("%s") Projectile::SetDamage; // sets the Damage
%rename("%s") Projectile::ForceRenderLayer; // this checks if the projectile is forced to render on a certain layer (e.g. ASB rendering behind/in front)
%rename("%s") Projectile::SetSpin; // sets spin (for flak)
%rename("%s") Projectile::SaveProjectile; // saves the projectile state to file
%rename("%s") Projectile::LoadProjectile; // loads the projectile state from file
%rename("%s") Projectile::GetType; // gets projectile type: 1 = laser, 2 = asteroid, 3 = missile, 4 = bomb, 5 = beam, 6 = asb
%rename("%s") Projectile::SetMovingTarget; // sets moving target (for beams), most likely only used when loading (it saves the movingtarget's selfId)

%rename("%s") Projectile::AtTarget; // checks if we're hitting the target point (based on distance from projectile to target). Returns false if missed.
%rename("%s") Projectile::Initialize; // updates a projectile's attributes from a weapon blueprint
%rename("%s") Projectile::OnRender; // renders the projectile and also the target dot for flak
%rename("%s") Projectile::RandomSidePoint; // picks a random side point (e.g. for missed ASB) - static method
%contract Projectile::RandomSidePoint(int side) {
    require:
        side >= 0;
        side < 4;
}
%rename("%s") Projectile::SetTarget; // sets a new target point and changes the heading, in vanilla only really used when generating asteroids
%rename("%s") Projectile::StartedDeath; // checks if the projectile has started its death, but also changes it to false if it has, in vanilla only used for checking when crew lasers should do damage

%rename("%s") Projectile::_targetable; //todo: abstract away _targetable
%rename("%s") Projectile::position;
%rename("%s") Projectile::last_position;
%rename("%s") Projectile::speed_magnitude;
%rename("%s") Projectile::target;
%rename("%s") Projectile::heading;
%rename("%s") Projectile::ownerId;
%rename("%s") Projectile::selfId;
%immutable Projectile::selfId;
%rename("%s") Projectile::damage;
%rename("%s") Projectile::lifespan;
%rename("%s") Projectile::destinationSpace;
%rename("%s") Projectile::currentSpace;
%rename("%s") Projectile::targetId;
%rename("%s") Projectile::dead;
%rename("%s") Projectile::death_animation;
%rename("%s") Projectile::flight_animation;
%rename("%s") Projectile::speed;
%rename("%s") Projectile::missed;
%rename("%s") Projectile::hitTarget;
%rename("%s") Projectile::hitSolidSound;
%rename("%s") Projectile::hitShieldSound;
%rename("%s") Projectile::entryAngle;
%rename("%s") Projectile::startedDeath;
%rename("%s") Projectile::passedTarget;
%rename("%s") Projectile::bBroadcastTarget;
%rename("%s") Projectile::flashTracker;
%rename("%s") Projectile::color;

%immutable Projectile::extend;
%rename("%s") Projectile::extend;

%extend Projectile {
    Projectile_Extend* extend;
}
%wrapper %{
    static Projectile_Extend *Projectile_extend_get(Projectile* projectile)
    {
        return Get_Projectile_Extend(projectile);
    };
%}



%nodefaultctor CrewMember;
%nodefaultdtor CrewMember;
%rename("%s") CrewMember;

%immutable CrewMember::extend;
%rename("%s") CrewMember::extend;

%extend CrewMember {
    CrewMember_Extend* extend;
}
%wrapper %{
    static CrewMember_Extend *CrewMember_extend_get(CrewMember* crewMember)
    {
        return Get_CrewMember_Extend(crewMember);
    };
%}

%rename("%s") Get_CrewMember_Extend;
%nodefaultctor CrewMember_Extend;
%nodefaultdtor CrewMember_Extend;
%rename("%s") CrewMember_Extend;
%apply bool* OUTPUT {bool* boolValue};
%rename("%s") CrewMember_Extend::CalculateStat;
%rename("%s") CrewMember_Extend::InitiateTeleport;
%rename("%s") CrewMember_Extend::GetDefinition;
%rename("%s") CrewMember_Extend::orig;
%immutable CrewMember_Extend::orig;
%rename("%s") CrewMember_Extend::selfId;
%immutable CrewMember_Extend::selfId;
%rename("%s") CrewMember_Extend::lowHealthThreshold;
%rename("%s") CrewMember_Extend::canPhaseThroughDoors;
%rename("%s") CrewMember_Extend::isHealing;
%rename("%s") CrewMember_Extend::passiveHealTimer;
%rename("%s") CrewMember_Extend::deathTimer;
%rename("%s") CrewMember_Extend::lastRoom;
%rename("%s") CrewMember_Extend::lastShipId;
%rename("%s") CrewMember_Extend::exploded;
%rename("%s") CrewMember_Extend::triggerExplosion;
%rename("%s") CrewMember_Extend::crewPowers;
%immutable CrewMember_Extend::crewPowers;
%rename("%s") CrewMember_Extend::hasSpecialPower;
%rename("%s") CrewMember_Extend::powerResources;
%immutable CrewMember_Extend::powerResources;
%rename("%s") CrewMember_Extend::powerResourceMap;
%immutable CrewMember_Extend::powerResourceMap;
%rename("%s") CrewMember_Extend::powerChange;
%rename("%s") CrewMember_Extend::noSlot;
%rename("%s") CrewMember_Extend::noClone;
%rename("%s") CrewMember_Extend::CustomTeleport;
%rename("%s") CrewMember_Extend::CustomTeleport::teleporting;
%rename("%s") CrewMember_Extend::CustomTeleport::shipId;
%rename("%s") CrewMember_Extend::CustomTeleport::roomId;
%rename("%s") CrewMember_Extend::CustomTeleport::slotId;
%rename("%s") CrewMember_Extend::customTele;

%rename("%s") CrewMember::GetPosition;
%rename("%s") CrewMember::PositionShift;
%rename("%s") CrewMember::InsideRoom;
%rename("%s") CrewMember::ApplyDamage;
%rename("%s") CrewMember::GetPriority;
%rename("%s") CrewMember::ValidTarget;
%rename("%s") CrewMember::MultiShots;
%rename("%s") CrewMember::ExactTarget;
%rename("%s") CrewMember::IsCrew;
%rename("%s") CrewMember::IsCloned;
%rename("%s") CrewMember::IsDrone;
%rename("%s") CrewMember::Jump;
%rename("%s") CrewMember::GetIntruder;
%rename("%s") CrewMember::SaveState;
%rename("%s") CrewMember::LoadState;
%rename("%s") CrewMember::OnLoop;
%rename("%s") CrewMember::OnRender;
%rename("%s") CrewMember::OutOfGame;
%rename("%s") CrewMember::SetOutOfGame;
%rename("%s") CrewMember::Functional;
%rename("%s") CrewMember::CountForVictory;
%rename("%s") CrewMember::GetControllable;
%rename("%s") CrewMember::ReadyToFight;
%rename("%s") CrewMember::CanFight;
%rename("%s") CrewMember::CanRepair;
%rename("%s") CrewMember::CanSabotage;
%rename("%s") CrewMember::CanMan;
%rename("%s") CrewMember::CanTeleport;
%rename("%s") CrewMember::CanHeal;
%rename("%s") CrewMember::CanSuffocate;
%rename("%s") CrewMember::CanBurn;
%rename("%s") CrewMember::GetMaxHealth;
%rename("%s") CrewMember::IsDead;
%rename("%s") CrewMember::PermanentDeath;
%rename("%s") CrewMember::ShipDamage;
%rename("%s") CrewMember::FireFightingSoundEffect;
%rename("%s") CrewMember::GetUniqueRepairing;
%rename("%s") CrewMember::ProvidesVision;
%rename("%s") CrewMember::GetMoveSpeedMultiplier;
%rename("%s") CrewMember::GetRepairSpeed;
%rename("%s") CrewMember::GetDamageMultiplier;
%rename("%s") CrewMember::ProvidesPower;
%rename("%s") CrewMember::GetSpecies;
%rename("%s") CrewMember::GetFireRepairMultiplier;
%rename("%s") CrewMember::IsTelepathic;
%rename("%s") CrewMember::GetPowerCooldown;
%rename("%s") CrewMember::PowerReady;
%rename("%s") CrewMember::ActivatePower;
%rename("%s") CrewMember::HasSpecialPower;
%rename("%s") CrewMember::ResetPower;
%rename("%s") CrewMember::GetSuffocationMultiplier;
%rename("%s") CrewMember::BlockRoom;
%rename("%s") CrewMember::GetRoomDamage;
%rename("%s") CrewMember::IsAnaerobic;
%rename("%s") CrewMember::UpdateRepair;
%rename("%s") CrewMember::CanStim;
%rename("%s") CrewMember::AtFinalGoal;
%rename("%s") CrewMember::AtGoal;
%rename("%s") CrewMember::BadAtCombat;
%rename("%s") CrewMember::CheckFighting;
%rename("%s") CrewMember::CheckForTeleport;
%rename("%s") CrewMember::CheckRoomPath;
%rename("%s") CrewMember::CheckSkills;
%rename("%s") CrewMember::Cleanup;
%rename("%s") CrewMember::ClearPath;
%rename("%s") CrewMember::ClearPosition;
%rename("%s") CrewMember::ClearTask;
%rename("%s") CrewMember::Clone;
%rename("%s") CrewMember::CloseDoorBehind;
%rename("%s") CrewMember::ContainsPoint;
%rename("%s") CrewMember::CycleColorLayer;
%rename("%s") CrewMember::DirectModifyHealth;
%rename("%s") CrewMember::EmptySlot;
%rename("%s") CrewMember::FindSlot;
%rename("%s") CrewMember::ForceMindControl;
%rename("%s") CrewMember::GetFinalGoal;
%rename("%s") CrewMember::GetIntegerHealth;
%rename("%s") CrewMember::GetLocation;
%rename("%s") CrewMember::GetLongName;
%rename("%s") CrewMember::GetMoveSpeed;
%rename("%s") CrewMember::GetName;
%rename("%s") CrewMember::GetNewGoal;
%rename("%s") CrewMember::GetNextGoal;
%rename("%s") CrewMember::GetRepairingId;
%rename("%s") CrewMember::GetResisted;
%rename("%s") CrewMember::GetSavedPosition;
%rename("%s") CrewMember::GetSkillFromSystem;
%rename("%s") CrewMember::GetSkillLevel;
%rename("%s") CrewMember::GetSkillModifier;
%rename("%s") CrewMember::GetSkillProgress;
%rename("%s") CrewMember::GetTooltip;
%rename("%s") CrewMember::IncreaseSkill;
%rename("%s") CrewMember::InitializeSkills;
%rename("%s") CrewMember::IsBusy;
%rename("%s") CrewMember::IsManningArtillery;
%rename("%s") CrewMember::Kill;
%rename("%s") CrewMember::MasterSkill;
%rename("%s") CrewMember::ModifyHealth;
%rename("%s") CrewMember::MoveToRoom;
%rename("%s") CrewMember::NeedFrozenLocation;
%rename("%s") CrewMember::NeedsSlot;
%rename("%s") CrewMember::OnInit;
%rename("%s") CrewMember::OnRenderHealth;
%rename("%s") CrewMember::OnRenderPath;
%rename("%s") CrewMember::RenderSkillUpAnimation;
%rename("%s") CrewMember::Repairing;
%rename("%s") CrewMember::RepairingFire;
%rename("%s") CrewMember::RepairingSystem;
%rename("%s") CrewMember::Restart;
%rename("%s") CrewMember::RestorePosition;
%rename("%s") CrewMember::Sabotaging;
%rename("%s") CrewMember::SavePosition;
%rename("%s") CrewMember::SelectSabotageTarget;
%rename("%s") CrewMember::SetCloneReady;
%rename("%s") CrewMember::SetCurrentShip;
%rename("%s") CrewMember::SetCurrentSystem;
%rename("%s") CrewMember::SetCurrentTarget;
%rename("%s") CrewMember::SetDamageBoost;
%rename("%s") CrewMember::SetDeathNumber;
%rename("%s") CrewMember::SetFrozen;
%rename("%s") CrewMember::SetFrozenLocation;
%rename("%s") CrewMember::SetHealthBoost;
%rename("%s") CrewMember::SetMedbay;
%rename("%s") CrewMember::SetMindControl;
%rename("%s") CrewMember::SetName;
%rename("%s") CrewMember::SetPath;
%rename("%s") CrewMember::SetPosition;
%rename("%s") CrewMember::SetResisted;
%rename("%s") CrewMember::SetRoom;
%rename("%s") CrewMember::SetRoomPath;
%rename("%s") CrewMember::SetSavePosition;
%rename("%s") CrewMember::SetSex;
%rename("%s") CrewMember::SetSkillProgress;
%rename("%s") CrewMember::SetTask;
%rename("%s") CrewMember::StartRepair;
%rename("%s") CrewMember::StartTeleport;
%rename("%s") CrewMember::StartTeleportArrive;
%rename("%s") CrewMember::StopRepairing;
%rename("%s") CrewMember::UpdateHealth;
%rename("%s") CrewMember::UpdateMovement;
%rename("%s") CrewMember::WithinRect;

%rename("%s") CrewMember::iShipId;
%rename("%s") CrewMember::x;
%immutable CrewMember::x;
%rename("%s") CrewMember::y;
%immutable CrewMember::y;
%rename("%s") CrewMember::size;
%rename("%s") CrewMember::scale;
%rename("%s") CrewMember::goal_x;
%rename("%s") CrewMember::goal_y;
%rename("%s") CrewMember::width;
%rename("%s") CrewMember::height;
%rename("%s") CrewMember::health;
%rename("%s") CrewMember::speed_x;
%rename("%s") CrewMember::speed_y;
%rename("%s") CrewMember::path;
%rename("%s") CrewMember::new_path;
%rename("%s") CrewMember::x_destination;
%rename("%s") CrewMember::y_destination;
%rename("%s") CrewMember::last_door;
%rename("%s") CrewMember::currentRepair;
%rename("%s") CrewMember::bSuffocating;
%rename("%s") CrewMember::moveGoal;
%rename("%s") CrewMember::selectionState;
%rename("%s") CrewMember::iRoomId;
%rename("%s") CrewMember::iManningId;
%rename("%s") CrewMember::iRepairId;
%rename("%s") CrewMember::iStackId;
%rename("%s") CrewMember::currentSlot;
%rename("%s") CrewMember::intruder;
%rename("%s") CrewMember::bFighting;
%rename("%s") CrewMember::bSharedSpot;
%rename("%s") CrewMember::crewAnim;
%rename("%s") CrewMember::selectionImage;
%rename("%s") CrewMember::healthBox;
%rename("%s") CrewMember::healthBoxRed;
%rename("%s") CrewMember::healthBar;
%rename("%s") CrewMember::fMedbay;
%rename("%s") CrewMember::lastDamageTimer;
%rename("%s") CrewMember::lastHealthChange;
%rename("%s") CrewMember::currentShipId;
%rename("%s") CrewMember::flashHealthTracker;
%rename("%s") CrewMember::currentTarget;
%rename("%s") CrewMember::crewTarget;
%rename("%s") CrewMember::boardingGoal;
%rename("%s") CrewMember::bFrozen;
%rename("%s") CrewMember::bFrozenLocation;
%rename("%s") CrewMember::task;
%rename("%s") CrewMember::type;
%rename("%s") CrewMember::ship;
%rename("%s") CrewMember::finalGoal;
%rename("%s") CrewMember::blockingDoor;
%rename("%s") CrewMember::bOutOfGame;
%rename("%s") CrewMember::species;
%rename("%s") CrewMember::bDead;
%rename("%s") CrewMember::iOnFire;
%rename("%s") CrewMember::bActiveManning;
%rename("%s") CrewMember::currentSystem;
%rename("%s") CrewMember::usingSkill;
%rename("%s") CrewMember::blueprint;
%rename("%s") CrewMember::healing;
%rename("%s") CrewMember::stunned;
%rename("%s") CrewMember::levelUp;
%rename("%s") CrewMember::lastLevelUp;
%rename("%s") CrewMember::stats;
%rename("%s") CrewMember::skillsEarned;
%rename("%s") CrewMember::clone_ready;
%rename("%s") CrewMember::bMindControlled;
%rename("%s") CrewMember::iDeathNumber;
%rename("%s") CrewMember::mindControlled;
%rename("%s") CrewMember::stunIcon;
%rename("%s") CrewMember::skillUp;
%rename("%s") CrewMember::healthBoost;
%rename("%s") CrewMember::fMindDamageBoost;
%rename("%s") CrewMember::fCloneDying;
%rename("%s") CrewMember::bResisted;
%rename("%s") CrewMember::savedPosition;
%rename("%s") CrewMember::fStunTime;
%rename("%s") CrewMember::movementTarget;
%rename("%s") CrewMember::bCloned;


%nodefaultctor CrewAnimation;
%nodefaultdtor CrewAnimation;
%rename("%s") CrewAnimation;

%rename("%s") CrewAnimation::OnRender;
%rename("%s") CrewAnimation::OnRenderProps;
%rename("%s") CrewAnimation::OnUpdateEffects;
%rename("%s") CrewAnimation::UpdateFiring;
%rename("%s") CrewAnimation::UpdateShooting;
%rename("%s") CrewAnimation::FireShot;
%rename("%s") CrewAnimation::GetFiringFrame;
%rename("%s") CrewAnimation::GetShootingSound;
%rename("%s") CrewAnimation::GetDeathSound;
%rename("%s") CrewAnimation::Restart;
%rename("%s") CrewAnimation::CustomDeath;
%rename("%s") CrewAnimation::OnInit;
%rename("%s") CrewAnimation::OnUpdate;
%rename("%s") CrewAnimation::RenderIcon;
%rename("%s") CrewAnimation::SetupStrips;

%rename("%s") CrewAnimation::iShipId;
%rename("%s") CrewAnimation::anims;
%rename("%s") CrewAnimation::baseStrip;
%rename("%s") CrewAnimation::colorStrip;
%rename("%s") CrewAnimation::layerStrips;
%rename("%s") CrewAnimation::lastPosition;
%rename("%s") CrewAnimation::direction;
%rename("%s") CrewAnimation::sub_direction;
%rename("%s") CrewAnimation::status;
%rename("%s") CrewAnimation::moveDirection;
%rename("%s") CrewAnimation::smokeEmitter;
%rename("%s") CrewAnimation::bSharedSpot;
//%rename("%s") CrewAnimation::shots;
%rename("%s") CrewAnimation::shootTimer;
%rename("%s") CrewAnimation::punchTimer;
%rename("%s") CrewAnimation::target;
%rename("%s") CrewAnimation::fDamageDone;
%rename("%s") CrewAnimation::bPlayer;
%rename("%s") CrewAnimation::bFrozen;
%rename("%s") CrewAnimation::bDrone;
%rename("%s") CrewAnimation::bGhost;
%rename("%s") CrewAnimation::bExactShooting;
%rename("%s") CrewAnimation::projectile;
%rename("%s") CrewAnimation::bTyping;
%rename("%s") CrewAnimation::race;
%rename("%s") CrewAnimation::currentShip;
%rename("%s") CrewAnimation::bMale;
%rename("%s") CrewAnimation::colorblind;
%rename("%s") CrewAnimation::layerColors;
%rename("%s") CrewAnimation::forcedAnimation;
%rename("%s") CrewAnimation::forcedDirection;
%rename("%s") CrewAnimation::projectileColor;
%rename("%s") CrewAnimation::bStunned;
%rename("%s") CrewAnimation::bDoorTarget;
%rename("%s") CrewAnimation::uniqueBool1;
%rename("%s") CrewAnimation::uniqueBool2;

%nodefaultctor CrewDefinition;
%nodefaultdtor CrewDefinition;
%rename("%s") CrewDefinition;
//Expose all CrewDefinition members by regex to reduce maintenance of CrewDefinition exposure
%immutable; //All members are immutable
%rename("%(regex:/^CrewDefinition::(.*)$/\\1/)s", regextarget=1, fullname=1) "CrewDefinition::.*";
%clearimmutable; //Clear global feature flag

%nodefaultctor CrewMemberFactory;
%nodefaultdtor CrewMemberFactory;
%rename("%s") CrewMemberFactory;

%rename("%s") CrewMemberFactory::GetCloneReadyList;
%extend CrewMemberFactory {
   
    //Overload for returning vector in lua, pass by reference still works but this simplifies things.
    std::vector<CrewMember*> GetCloneReadyList(bool player)
    {
        std::vector<CrewMember*> ret;
        $self->GetCloneReadyList(ret, player);
        return ret;
    }
}


%immutable CrewMemberFactory::crewMembers;
%rename("%s") CrewMemberFactory::crewMembers;

%rename("%s") Get_Projectile_Extend;
%nodefaultctor Projectile_Extend;
%nodefaultdtor Projectile_Extend;
%rename("%s") Projectile_Extend;
%rename("%s") Projectile_Extend::orig;
%immutable Projectile_Extend::orig;
%rename("%s") Projectile_Extend::name;
%rename("%s") Projectile_Extend::customDamage;
%rename("%s") Projectile_Extend::missedDrones; // list of selfId of drones that have dodged this projectile

%rename("%s") CustomDamage;
%rename("%S") CustomDamage::Clear;

%rename("%s") CustomDamage::def;
%rename("%s") CustomDamage::sourceShipId;
%immutable CustomDamage::sourceShipId;
%rename("%s") CustomDamage::accuracyMod;
%rename("%s") CustomDamage::droneAccuracyMod;

%rename("%s") CustomDamageDefinition;
%rename("%s") CustomDamageDefinition::GiveId;

%rename("%s") CustomDamageDefinition::idx;
%immutable CustomDamageDefinition::idx;
%rename("%s") CustomDamageDefinition::accuracyMod;
%rename("%s") CustomDamageDefinition::droneAccuracyMod;
%rename("%s") CustomDamageDefinition::noSysDamage;
%rename("%s") CustomDamageDefinition::noPersDamage;
%rename("%s") CustomDamageDefinition::ionBeamFix;
%rename("%s") CustomDamageDefinition::statBoostChance;
%rename("%s") CustomDamageDefinition::roomStatBoostChance;
%rename("%s") CustomDamageDefinition::statBoosts;
%immutable CustomDamageDefinition::statBoosts;
%rename("%s") CustomDamageDefinition::roomStatBoosts;
%immutable CustomDamageDefinition::roomStatBoosts;
%rename("%s") CustomDamageDefinition::erosionChance;
%rename("%s") CustomDamageDefinition::erosionEffect;
%rename("%s") CustomDamageDefinition::crewSpawnChance;
%rename("%s") CustomDamageDefinition::crewSpawns;
%immutable CustomDamageDefinition::crewSpawns;

//%rename("%s") CustomDamageDefinition::customDamageDefs;
//%immutable CustomDamageDefinition::customDamageDefs;
//%rename("%s") CustomDamageDefinition::defaultDef;
//%immutable CustomDamageDefinition::defaultDef;

%nodefaultctor LaserBlast;
%rename("%s") LaserBlast;
%rename("%s") LaserBlast::LaserBlast;
%rename("%s") LaserBlast::movingTarget;
%rename("%s") LaserBlast::spinAngle;
%rename("%s") LaserBlast::spinSpeed;

%nodefaultctor Asteroid;
%rename("%s") Asteroid;
%rename("%s") Asteroid::Asteroid;
%rename("%s") Asteroid::imageId;
%rename("%s") Asteroid::angle;

%nodefaultctor Missile;
%rename("%s") Missile;
%rename("%s") Missile::Missile;

%nodefaultctor BombProjectile;
%rename("%s") BombProjectile;
%rename("%s") BombProjectile::BombProjectile;
%rename("%s") BombProjectile::bMissed;
%rename("%s") BombProjectile::missMessage;
%rename("%s") BombProjectile::explosiveDelay;
%rename("%s") BombProjectile::bSuperShield;
%rename("%s") BombProjectile::superShieldBypass;

%nodefaultctor BeamWeapon;
%rename("%s") BeamWeapon;
%rename("%s") BeamWeapon::BeamWeapon;
%rename("%s") BeamWeapon::sub_end;
%rename("%s") BeamWeapon::sub_start;
%rename("%s") BeamWeapon::shield_end;
%rename("%s") BeamWeapon::final_end;
%rename("%s") BeamWeapon::target2;
%rename("%s") BeamWeapon::target1;
%rename("%s") BeamWeapon::lifespan;
%rename("%s") BeamWeapon::length;
%rename("%s") BeamWeapon::dh;
%rename("%s") BeamWeapon::last_collision;
%rename("%s") BeamWeapon::soundChannel;
%rename("%s") BeamWeapon::contactAnimations;
%rename("%s") BeamWeapon::animationTimer;
%rename("%s") BeamWeapon::lastDamage;
%rename("%s") BeamWeapon::movingTarget;
%rename("%s") BeamWeapon::start_heading;
%rename("%s") BeamWeapon::timer;
%rename("%s") BeamWeapon::weapAnimation;
%rename("%s") BeamWeapon::piercedShield;
%rename("%s") BeamWeapon::oneSpace;
%rename("%s") BeamWeapon::bDamageSuperShield;
%rename("%s") BeamWeapon::movingTargetId;
%rename("%s") BeamWeapon::checkedCollision;
%rename("%s") BeamWeapon::smokeAnims;
%rename("%s") BeamWeapon::lastSmokeAnim;

%nodefaultctor PDSFire;
%rename("%s") PDSFire;
%rename("%s") PDSFire::PDSFire;
%rename("%s") PDSFire::startPoint;
%rename("%s") PDSFire::passedTarget;
%rename("%s") PDSFire::currentScale;
%rename("%s") PDSFire::missed;
%rename("%s") PDSFire::explosionAnimation;


%rename("%s") Drone;
%nodefaultctor Drone;
%nodefaultdtor Drone;

%rename("%s") Drone::OnInit;
%rename("%s") Drone::OnLoop;
%rename("%s") Drone::OnDestroy;
%rename("%s") Drone::SetPowered;
%rename("%s") Drone::SetInstantPowered;
%rename("%s") Drone::GetPowered;
%rename("%s") Drone::SetCurrentShip;
%rename("%s") Drone::SetDeployed;
%rename("%s") Drone::SetDestroyed;
%rename("%s") Drone::SetHacked;
%rename("%s") Drone::GetDeployed;
%rename("%s") Drone::NeedsRoom;
%rename("%s") Drone::SetSlot;
%rename("%s") Drone::Destroyed;
%rename("%s") Drone::GetWorldLocation;
%rename("%s") Drone::SetWorldLocation;
%rename("%s") Drone::GetDroneSlot;
%rename("%s") Drone::GetDroneHealth;
%rename("%s") Drone::GetRequiredPower;
%rename("%s") Drone::RenderIcon;
%rename("%s") Drone::GetName;
%rename("%s") Drone::CanBeDeployed;
%rename("%s") Drone::RecallOnJump;
%rename("%s") Drone::CanBeRecovered;
%rename("%s") Drone::SaveState;
%rename("%s") Drone::LoadState;
%rename("%s") Drone::BlowUp;
%rename("%s") Drone::GetStunned;

%rename("%s") Drone::iShipId;
%immutable Drone::selfId;
%rename("%s") Drone::selfId;
%rename("%s") Drone::powered;
%rename("%s") Drone::powerRequired;
%rename("%s") Drone::deployed;
%rename("%s") Drone::type;
%immutable Drone::blueprint;
%rename("%s") Drone::blueprint;
%rename("%s") Drone::bDead;
%rename("%s") Drone::iBonusPower;
%rename("%s") Drone::poweredAtLocation;
%rename("%s") Drone::destroyedTimer;
%rename("%s") Drone::iHackLevel;
%rename("%s") Drone::hackTime;


%rename("%s") SpaceDrone;
%nodefaultctor SpaceDrone;
%nodefaultdtor SpaceDrone;

%rename("%s") SpaceDrone::PickDestination;
%rename("%s") SpaceDrone::PickTarget;
%rename("%s") SpaceDrone::HasTarget;
%rename("%s") SpaceDrone::ValidTarget;
%rename("%s") SpaceDrone::GetWeaponCooldown;
%rename("%s") SpaceDrone::RandomizeStartingPosition;
%rename("%s") SpaceDrone::HideUnderOwner;
%rename("%s") SpaceDrone::GetNextProjectile;
%rename("%s") SpaceDrone::SetMovementTarget;
%rename("%s") SpaceDrone::SetWeaponTarget;
%rename("%s") SpaceDrone::ValidTargetObject;
%rename("%s") SpaceDrone::OnRender;
%rename("%s") SpaceDrone::RenderDrone;
%rename("%s") SpaceDrone::GetTooltip;
%rename("%s") SpaceDrone::GetWorldCenterPoint;
%rename("%s") SpaceDrone::SetCurrentLocation;
%rename("%s") SpaceDrone::MouseMove;
%rename("%s") SpaceDrone::GetRandomTargettingPoint;
%rename("%s") SpaceDrone::GetShieldShape;
%rename("%s") SpaceDrone::GetSpaceId;
%rename("%s") SpaceDrone::GetSpeed;
%rename("%s") SpaceDrone::GetOwnerId;
%rename("%s") SpaceDrone::GetSelfId;
%rename("%s") SpaceDrone::CollisionMoving;
%rename("%s") SpaceDrone::DamageBeam;
%rename("%s") SpaceDrone::DamageArea;
%rename("%s") SpaceDrone::GetBoardingDrone;
%rename("%s") SpaceDrone::SetDeployed;
%rename("%s") SpaceDrone::UpdateAimingAngle;

%rename("%s") SpaceDrone::_targetable;
%rename("%s") SpaceDrone::_collideable;
%rename("%s") SpaceDrone::currentSpace;
%rename("%s") SpaceDrone::destinationSpace;
%rename("%s") SpaceDrone::currentLocation;
%rename("%s") SpaceDrone::lastLocation;
%rename("%s") SpaceDrone::destinationLocation;
%rename("%s") SpaceDrone::pointTarget;
%rename("%s") SpaceDrone::explosion;
%rename("%s") SpaceDrone::weaponTarget;
%rename("%s") SpaceDrone::targetLocation;
%rename("%s") SpaceDrone::targetSpeed;
%rename("%s") SpaceDrone::movementTarget;
%rename("%s") SpaceDrone::speedVector;
%rename("%s") SpaceDrone::poweredLastFrame;
%rename("%s") SpaceDrone::deployedLastFrame;
%rename("%s") SpaceDrone::bFire;
%rename("%s") SpaceDrone::pause;
%rename("%s") SpaceDrone::additionalPause;
%rename("%s") SpaceDrone::weaponCooldown;
%rename("%s") SpaceDrone::current_angle;
%rename("%s") SpaceDrone::aimingAngle;
%rename("%s") SpaceDrone::lastAimingAngle;
%rename("%s") SpaceDrone::desiredAimingAngle;
%rename("%s") SpaceDrone::message;
%rename("%s") SpaceDrone::weapon_animation;
%immutable SpaceDrone::weaponBlueprint;
%rename("%s") SpaceDrone::weaponBlueprint;
%rename("%s") SpaceDrone::lifespan;
%rename("%s") SpaceDrone::bLoadedPosition;
%rename("%s") SpaceDrone::bDisrupted;
%rename("%s") SpaceDrone::hackAngle;
%rename("%s") SpaceDrone::ionStun;
%rename("%s") SpaceDrone::beamCurrentTarget;
%rename("%s") SpaceDrone::beamFinalTarget;
%rename("%s") SpaceDrone::beamSpeed;
%rename("%s") SpaceDrone::hackSparks;

%rename("%s") DefenseDrone;
%rename("%s") DefenseDrone::GetTooltip;
%rename("%s") DefenseDrone::PickTarget;
%rename("%s") DefenseDrone::SetWeaponTarget;
%rename("%s") DefenseDrone::ValidTargetObject;
	
%rename("%s") DefenseDrone::currentTargetId;
%rename("%s") DefenseDrone::shotAtTargetId;
%rename("%s") DefenseDrone::currentSpeed;
%rename("%s") DefenseDrone::drone_image;
%rename("%s") DefenseDrone::gun_image_off;
%rename("%s") DefenseDrone::gun_image_charging;
%rename("%s") DefenseDrone::gun_image_on;
%rename("%s") DefenseDrone::engine_image;
%rename("%s") DefenseDrone::currentTargetType;

%rename("%s") CombatDrone;
%rename("%s") CombatDrone::SetWeaponTarget;
	
%rename("%s") CombatDrone::lastDestination;
%rename("%s") CombatDrone::progressToDestination;
%rename("%s") CombatDrone::heading;
%rename("%s") CombatDrone::oldHeading;
%rename("%s") CombatDrone::drone_image_off;
%rename("%s") CombatDrone::drone_image_charging;
%rename("%s") CombatDrone::drone_image_on;
%rename("%s") CombatDrone::engine_image;

%rename("%s") BoarderPodDrone;

%rename("%s") BoarderPodDrone::CanBeDeployed;
%rename("%s") BoarderPodDrone::CollisionMoving;
%rename("%s") BoarderPodDrone::SetDeployed;
%rename("%s") BoarderPodDrone::SetMovementTarget;
	
%rename("%s") BoarderPodDrone::baseSheet;
%rename("%s") BoarderPodDrone::colorSheet;
%rename("%s") BoarderPodDrone::startingPosition;
%rename("%s") BoarderPodDrone::droneImage;
%rename("%s") BoarderPodDrone::flame;
%rename("%s") BoarderPodDrone::boarderDrone;
%rename("%s") BoarderPodDrone::bDeliveredDrone;
%rename("%s") BoarderPodDrone::diedInSpace;

%rename("%s") ShipRepairDrone;

%rename("%s") HackingDrone;

%rename("%s") HackingDrone::CollisionMoving;
%rename("%s") HackingDrone::OnLoop;
%rename("%s") HackingDrone::SetMovementTarget;
	
%rename("%s") HackingDrone::startingPosition;
%rename("%s") HackingDrone::droneImage_on;
%rename("%s") HackingDrone::droneImage_off;
%rename("%s") HackingDrone::lightImage;
%rename("%s") HackingDrone::finalDestination;
%rename("%s") HackingDrone::arrived;
%rename("%s") HackingDrone::finishedSetup;
%rename("%s") HackingDrone::flashTracker;
%rename("%s") HackingDrone::flying;
%rename("%s") HackingDrone::extending;
%rename("%s") HackingDrone::explosion;
%rename("%s") HackingDrone::prefRoom;

%rename("%s") SuperShieldDrone;

%rename("%s") SuperShieldDrone::shieldSystem;
%rename("%s") SuperShieldDrone::drone_image_on;
%rename("%s") SuperShieldDrone::drone_image_off;
%rename("%s") SuperShieldDrone::drone_image_glow;
%rename("%s") SuperShieldDrone::glowAnimation;


%rename("%s") DroneBlueprint;
%nodefaultctor DroneBlueprint;
%nodefaultdtor DroneBlueprint;

%immutable DroneBlueprint::typeName;
%rename("%s") DroneBlueprint::typeName;
%immutable DroneBlueprint::level;
%rename("%s") DroneBlueprint::level;
%immutable DroneBlueprint::targetType;
%rename("%s") DroneBlueprint::targetType;
%immutable DroneBlueprint::power;
%rename("%s") DroneBlueprint::power;
%immutable DroneBlueprint::cooldown;
%rename("%s") DroneBlueprint::cooldown;
%immutable DroneBlueprint::speed;
%rename("%s") DroneBlueprint::speed;
%immutable DroneBlueprint::dodge;
%rename("%s") DroneBlueprint::dodge;
%immutable DroneBlueprint::weaponBlueprint;
%rename("%s") DroneBlueprint::weaponBlueprint;
%immutable DroneBlueprint::droneImage;
%rename("%s") DroneBlueprint::droneImage;
%immutable DroneBlueprint::combatIcon;
%rename("%s") DroneBlueprint::combatIcon;


%nodefaultctor ActivatedPower;
%nodefaultdtor ActivatedPower;
%rename("%s") ActivatedPower;
%rename("%s") ActivatedPower::def;
%immutable ActivatedPower::def;
%rename("%s") ActivatedPower::enabled;
%rename("%s") ActivatedPower::crew;
%immutable ActivatedPower::crew;
%rename("%s") ActivatedPower::crew_ex;
%immutable ActivatedPower::crew_ex;
%rename("%s") ActivatedPower::modifiedPowerCharges;
%rename("%s") ActivatedPower::modifiedChargesPerJump;
%rename("%s") ActivatedPower::powerCooldown;
%rename("%s") ActivatedPower::temporaryPowerDuration;
%rename("%s") ActivatedPower::powerCharges;
%rename("%s") ActivatedPower::powerResources;
%immutable ActivatedPower::powerResources;
%rename("%s") ActivatedPower::powerRoom;
%rename("%s") ActivatedPower::powerShip;
%rename("%s") ActivatedPower::powerActivated;
%rename("%s") ActivatedPower::temporaryPowerActive;
%rename("%s") ActivatedPower::powerDone;
%rename("%s") ActivatedPower::temporaryPowerDone;
%rename("%s") ActivatedPower::effectAnim;
%immutable ActivatedPower::effectAnim;
%rename("%s") ActivatedPower::tempEffectAnim;
%immutable ActivatedPower::tempEffectAnim;
%rename("%s") ActivatedPower::effectFinishAnim;
%immutable ActivatedPower::effectFinishAnim;
%rename("%s") ActivatedPower::extraAnims;
%rename("%s") ActivatedPower::tempEffectStrip;
%rename("%s") ActivatedPower::effectPos;
%rename("%s") ActivatedPower::effectWorldPos;

%rename("%s") ActivatedPower::PowerReq;
%rename("%s") ActivatedPower::PowerReady;
%rename("%s") ActivatedPower::GetPowerDamage;
%rename("%s") ActivatedPower::ActivateTemporaryPower;
%rename("%s") ActivatedPower::TemporaryPowerFinished;
%rename("%s") ActivatedPower::PrepareAnimation;
%rename("%s") ActivatedPower::PrepareTemporaryAnimation;
%rename("%s") ActivatedPower::PreparePower;
%rename("%s") ActivatedPower::ActivatePower;
%rename("%s") ActivatedPower::CancelPower;
%rename("%s") ActivatedPower::OnUpdate;
%rename("%s") ActivatedPower::ChangePowerDef;
%rename("%s") ActivatedPower::EnablePower;
%rename("%s") ActivatedPower::DisablePower;
%rename("%s") ActivatedPower::EnableInit;
%rename("%s") ActivatedPower::GetCrewBoxResourceWidth;

%nodefaultctor ActivatedPowerResource;
%nodefaultdtor ActivatedPowerResource;
%rename("%s") ActivatedPowerResource;
%rename("%s") ActivatedPowerResource::def;
%immutable ActivatedPowerResource::def;
%rename("%s") ActivatedPowerResource::enabled;
%rename("%s") ActivatedPowerResource::crew;
%immutable ActivatedPowerResource::crew;
%rename("%s") ActivatedPowerResource::crew_ex;
%immutable ActivatedPowerResource::crew_ex;
%rename("%s") ActivatedPowerResource::modifiedPowerCharges;
%rename("%s") ActivatedPowerResource::modifiedChargesPerJump;
%rename("%s") ActivatedPowerResource::powerCooldown;
%rename("%s") ActivatedPowerResource::powerCharges;

%rename("%s") ActivatedPowerResource::GetLinkedPowers;
%rename("%s") ActivatedPowerResource::PowerReq;
%rename("%s") ActivatedPowerResource::OnUpdate;
%rename("%s") ActivatedPowerResource::EnablePower;
%rename("%s") ActivatedPowerResource::DisablePower;
%rename("%s") ActivatedPowerResource::EnableInit;
%rename("%s") ActivatedPowerResource::GetCrewBoxResourceWidth;

%nodefaultctor ActivatedPowerDefinition;
%nodefaultdtor ActivatedPowerDefinition;
%rename("%s") ActivatedPowerDefinition;
%rename("%s") ActivatedPowerDefinition::name;
%immutable ActivatedPowerDefinition::name;
%rename("%s") ActivatedPowerDefinition::activateGroupIndex;
%immutable ActivatedPowerDefinition::activateGroupIndex;
%rename("%s") ActivatedPowerDefinition::replaceGroupIndex;
%immutable ActivatedPowerDefinition::replaceGroupIndex;
%rename("%s") ActivatedPowerDefinition::sortOrder;
%rename("%s") ActivatedPowerDefinition::damage;
%rename("%s") ActivatedPowerDefinition::cooldown;
%rename("%s") ActivatedPowerDefinition::shipFriendlyFire;
%rename("%s") ActivatedPowerDefinition::hasSpecialPower;
%rename("%s") ActivatedPowerDefinition::hasTemporaryPower;
%rename("%s") ActivatedPowerDefinition::jumpCooldown;
%rename("%s") ActivatedPowerDefinition::disabledCooldown;
%rename("%s") ActivatedPowerDefinition::initialCooldownFraction;
%rename("%s") ActivatedPowerDefinition::onDeath;
%rename("%s") ActivatedPowerDefinition::onHotkey;
%rename("%s") ActivatedPowerDefinition::powerCharges;
%rename("%s") ActivatedPowerDefinition::initialCharges;
%rename("%s") ActivatedPowerDefinition::chargesPerJump;
%rename("%s") ActivatedPowerDefinition::respawnCharges;
%rename("%s") ActivatedPowerDefinition::disabledCharges;
%rename("%s") ActivatedPowerDefinition::hideCooldown;
%rename("%s") ActivatedPowerDefinition::hideCharges;
%rename("%s") ActivatedPowerDefinition::hideButton;
%rename("%s") ActivatedPowerDefinition::powerResources;
%rename("%s") ActivatedPowerDefinition::respawnCharges;
%rename("%s") ActivatedPowerDefinition::sounds;
%rename("%s") ActivatedPowerDefinition::effectSounds;
%rename("%s") ActivatedPowerDefinition::soundsEnemy;
%rename("%s") ActivatedPowerDefinition::effectSoundsEnemy;
%rename("%s") ActivatedPowerDefinition::buttonLabel;
%rename("%s") ActivatedPowerDefinition::cooldownColor;
%rename("%s") ActivatedPowerDefinition::tooltip;
%rename("%s") ActivatedPowerDefinition::effectAnim;
%rename("%s") ActivatedPowerDefinition::effectPostAnim;
%rename("%s") ActivatedPowerDefinition::playerReq;
%rename("%s") ActivatedPowerDefinition::enemyReq;
%rename("%s") ActivatedPowerDefinition::chargeReq;
%rename("%s") ActivatedPowerDefinition::win;
%rename("%s") ActivatedPowerDefinition::crewHealth;
%rename("%s") ActivatedPowerDefinition::enemyHealth;
%rename("%s") ActivatedPowerDefinition::selfHealth;
%rename("%s") ActivatedPowerDefinition::animFrame;
%rename("%s") ActivatedPowerDefinition::followCrew;
%rename("%s") ActivatedPowerDefinition::activateWhenReady;
%rename("%s") ActivatedPowerDefinition::activateReadyEnemies;
%rename("%s") ActivatedPowerDefinition::transformRace;
%rename("%s") ActivatedPowerDefinition::crewSpawns;
%rename("%s") ActivatedPowerDefinition::statBoosts;
%rename("%s") ActivatedPowerDefinition::roomStatBoosts;
%rename("%s") ActivatedPowerDefinition::event;
%rename("%s") ActivatedPowerDefinition::tempPower;

%rename("%s") ActivatedPowerDefinition::JUMP_COOLDOWN;
%rename("%s") ActivatedPowerDefinition::DISABLED_COOLDOWN;
%rename("%s") ActivatedPowerDefinition::ON_DEATH;
%rename("%s") ActivatedPowerDefinition::HOTKEY_SETTING;

%rename("%s") ActivatedPowerDefinition::AssignIndex; // beware, do not create new definitions/indices on the fly, only in a predetermined order on load
%rename("%s") ActivatedPowerDefinition::AssignName;
%rename("%s") ActivatedPowerDefinition::AssignActivateGroup;
%rename("%s") ActivatedPowerDefinition::AssignReplaceGroup;
%rename("%s") ActivatedPowerDefinition::AssignGroup;

%rename("%s") ActivatedPowerDefinition::GetPowerByName;
%rename("%s") ActivatedPowerDefinition::AddNamedDefinition;

%nodefaultctor PowerResourceDefinition;
%nodefaultdtor PowerResourceDefinition;
%rename("%s") PowerResourceDefinition;
%rename("%s") PowerResourceDefinition::name;
%immutable PowerResourceDefinition::name;
%rename("%s") PowerResourceDefinition::groupIndex;
%immutable PowerResourceDefinition::groupIndex;
%rename("%s") PowerResourceDefinition::sortOrder;
%rename("%s") PowerResourceDefinition::cooldown;
%rename("%s") PowerResourceDefinition::jumpCooldown;
%rename("%s") PowerResourceDefinition::disabledCooldown;
%rename("%s") PowerResourceDefinition::initialCooldownFraction;
%rename("%s") PowerResourceDefinition::onDeath;
%rename("%s") PowerResourceDefinition::powerCharges;
%rename("%s") PowerResourceDefinition::initialCharges;
%rename("%s") PowerResourceDefinition::chargesPerJump;
%rename("%s") PowerResourceDefinition::respawnCharges;
%rename("%s") PowerResourceDefinition::disabledCharges;
%rename("%s") PowerResourceDefinition::hideCooldown;
%rename("%s") PowerResourceDefinition::hideCharges;
%rename("%s") PowerResourceDefinition::showTemporaryBars;
%rename("%s") PowerResourceDefinition::showLinkedCooldowns;
%rename("%s") PowerResourceDefinition::showLinkedCharges;
%rename("%s") PowerResourceDefinition::cooldownColor; 
%rename("%s") PowerResourceDefinition::chargeReq;

%rename("%s") PowerResourceDefinition::JUMP_COOLDOWN;
%rename("%s") PowerResourceDefinition::DISABLED_COOLDOWN;
%rename("%s") PowerResourceDefinition::ON_DEATH;

%rename("%s") PowerResourceDefinition::AssignIndex; // beware, do not create new definitions/indices on the fly, only in a predetermined order on load
%rename("%s") PowerResourceDefinition::AssignName;
%rename("%s") PowerResourceDefinition::AssignGroup;

%rename("%s") PowerResourceDefinition::GetByName;
%rename("%s") PowerResourceDefinition::AddNamedDefinition;

%nodefaultctor ActivatedPowerRequirements;
%nodefaultdtor ActivatedPowerRequirements;
%rename("%s") ActivatedPowerRequirements;
%rename("%s") ActivatedPowerRequirements::Type;
%rename("%s") ActivatedPowerRequirements::type;
%rename("%s") ActivatedPowerRequirements::playerShip;
%rename("%s") ActivatedPowerRequirements::enemyShip;
%rename("%s") ActivatedPowerRequirements::checkRoomCrew;
%rename("%s") ActivatedPowerRequirements::enemyInRoom;
%rename("%s") ActivatedPowerRequirements::friendlyInRoom;
%rename("%s") ActivatedPowerRequirements::whiteList;
%rename("%s") ActivatedPowerRequirements::friendlyWhiteList;
%rename("%s") ActivatedPowerRequirements::friendlyBlackList;
%rename("%s") ActivatedPowerRequirements::enemyWhiteList;
%rename("%s") ActivatedPowerRequirements::enemyBlackList;
%rename("%s") ActivatedPowerRequirements::systemInRoom;
%rename("%s") ActivatedPowerRequirements::systemDamaged;
%rename("%s") ActivatedPowerRequirements::hasClonebay;
%rename("%s") ActivatedPowerRequirements::aiDisabled;
%rename("%s") ActivatedPowerRequirements::outOfCombat;
%rename("%s") ActivatedPowerRequirements::inCombat;
%rename("%s") ActivatedPowerRequirements::requiredSystem;
%rename("%s") ActivatedPowerRequirements::requiredSystemFunctional;
%rename("%s") ActivatedPowerRequirements::minHealth;
%rename("%s") ActivatedPowerRequirements::maxHealth;
%rename("%s") ActivatedPowerRequirements::extraConditions;
%rename("%s") ActivatedPowerRequirements::extraOrConditions;
%rename("%s") ActivatedPowerRequirements::extraOrConditionsTooltip;

%rename("%s") PowerReadyState;
%rename("%s") GetNextPowerReadyState;

%rename("%s") CrewExtraCondition;

%nodefaultctor TemporaryPowerDefinition;
%nodefaultdtor TemporaryPowerDefinition;
%rename("%s") TemporaryPowerDefinition;
%rename("%s") TemporaryPowerDefinition::duration;
%rename("%s") TemporaryPowerDefinition::effectAnim;
%rename("%s") TemporaryPowerDefinition::effectFinishAnim;
%rename("%s") TemporaryPowerDefinition::animSheet;
%rename("%s") TemporaryPowerDefinition::baseVisible;
%rename("%s") TemporaryPowerDefinition::soundsEnemy;
%rename("%s") TemporaryPowerDefinition::sounds;
%rename("%s") TemporaryPowerDefinition::maxHealth;
%rename("%s") TemporaryPowerDefinition::stunMultiplier;
%rename("%s") TemporaryPowerDefinition::moveSpeedMultiplier;
%rename("%s") TemporaryPowerDefinition::damageMultiplier;
%rename("%s") TemporaryPowerDefinition::rangedDamageMultiplier;
%rename("%s") TemporaryPowerDefinition::doorDamageMultiplier;
%rename("%s") TemporaryPowerDefinition::repairSpeed;
%rename("%s") TemporaryPowerDefinition::fireRepairMultiplier;
%rename("%s") TemporaryPowerDefinition::controllable;
%rename("%s") TemporaryPowerDefinition::canFight;
%rename("%s") TemporaryPowerDefinition::canRepair;
%rename("%s") TemporaryPowerDefinition::canSabotage;
%rename("%s") TemporaryPowerDefinition::canMan;
%rename("%s") TemporaryPowerDefinition::canTeleport;
%rename("%s") TemporaryPowerDefinition::canSuffocate;
%rename("%s") TemporaryPowerDefinition::canBurn;
%rename("%s") TemporaryPowerDefinition::oxygenChangeSpeed;
%rename("%s") TemporaryPowerDefinition::canPhaseThroughDoors;
%rename("%s") TemporaryPowerDefinition::fireDamageMultiplier;
%rename("%s") TemporaryPowerDefinition::isTelepathic;
%rename("%s") TemporaryPowerDefinition::resistsMindControl;
%rename("%s") TemporaryPowerDefinition::isAnaerobic;
%rename("%s") TemporaryPowerDefinition::detectsLifeforms;
%rename("%s") TemporaryPowerDefinition::damageTakenMultiplier;
%rename("%s") TemporaryPowerDefinition::cloneSpeedMultiplier;
%rename("%s") TemporaryPowerDefinition::passiveHealAmount;
%rename("%s") TemporaryPowerDefinition::truePassiveHealAmount;
%rename("%s") TemporaryPowerDefinition::healAmount;
%rename("%s") TemporaryPowerDefinition::trueHealAmount;
%rename("%s") TemporaryPowerDefinition::passiveHealDelay;
%rename("%s") TemporaryPowerDefinition::sabotageSpeedMultiplier;
%rename("%s") TemporaryPowerDefinition::allDamageTakenMultiplier;
%rename("%s") TemporaryPowerDefinition::healSpeed;
%rename("%s") TemporaryPowerDefinition::suffocationModifier;
%rename("%s") TemporaryPowerDefinition::healCrewAmount;
%rename("%s") TemporaryPowerDefinition::powerDrain;
%rename("%s") TemporaryPowerDefinition::powerDrainFriendly;
%rename("%s") TemporaryPowerDefinition::bonusPower;
%rename("%s") TemporaryPowerDefinition::damageEnemiesAmount;
%rename("%s") TemporaryPowerDefinition::hackDoors;
%rename("%s") TemporaryPowerDefinition::powerRechargeMultiplier;
%rename("%s") TemporaryPowerDefinition::noClone;
%rename("%s") TemporaryPowerDefinition::noAI;
%rename("%s") TemporaryPowerDefinition::validTarget;
%rename("%s") TemporaryPowerDefinition::canMove;
%rename("%s") TemporaryPowerDefinition::teleportMove;
%rename("%s") TemporaryPowerDefinition::teleportMoveOtherShip;
%rename("%s") TemporaryPowerDefinition::silenced;
%rename("%s") TemporaryPowerDefinition::lowHealthThreshold;
%rename("%s") TemporaryPowerDefinition::statBoosts;
%rename("%s") TemporaryPowerDefinition::invulnerable;
%rename("%s") TemporaryPowerDefinition::animFrame;
%rename("%s") TemporaryPowerDefinition::cooldownColor;

%luacode { 
    --function to strip prefixes before adding enum to table
    local function CreateEnumTable(prefix, table, key, value)
        if key:find(prefix) then
            key = key:gsub(prefix, "")
            table[key] = value
        end
    end
}


%rename("%s") CrewStat;
%rename("%(regex:/^(w+::(.*))$/\\u\\2/)s", regextarget=1, fullname=1) "CrewStat::.*";

%luacode {
    --Create CrewStat enum table
    Hyperspace.CrewStat = {}
    for key, value in pairs(Hyperspace) do
        CreateEnumTable("CrewStat_", Hyperspace.CrewStat, key, value)
    end
}
%rename("%s") StatBoost;

%rename("%s") StatBoostDefinition;

%rename("%s") StatBoostDefinition::GiveId;
%rename("%s") StatBoostDefinition::TestRoomStatBoostSystem;
%rename("%s") StatBoostDefinition::IsTargetPower;

%rename("%s") StatBoostDefinition::BoostType;
%rename("%(regex:/^(\\w+::\\w+::(.*))$/\\u\\2/)s", regextarget=1, fullname=1) "StatBoostDefinition::BoostType::.*";
%rename("%s") StatBoostDefinition::BoostSource;
%rename("%(regex:/^(\\w+::\\w+::(.*))$/\\u\\2/)s", regextarget=1, fullname=1) "StatBoostDefinition::BoostSource::.*";
%rename("%s") StatBoostDefinition::ShipTarget;
%rename("%(regex:/^(\\w+::\\w+::(.*))$/\\u\\2/)s", regextarget=1, fullname=1) "StatBoostDefinition::ShipTarget::.*";
%rename("%s") StatBoostDefinition::SystemRoomTarget;
%rename("%(regex:/^(\\w+::\\w+::(.*))$/\\u\\2/)s", regextarget=1, fullname=1) "StatBoostDefinition::SystemRoomTarget::.*";
%rename("%s") StatBoostDefinition::CrewTarget;
%rename("%(regex:/^(\\w+::\\w+::(.*))$/\\u\\2/)s", regextarget=1, fullname=1) "StatBoostDefinition::CrewTarget::.*";
%rename("%s") StatBoostDefinition::DroneTarget;
%rename("%(regex:/^(\\w+::\\w+::(.*))$/\\u\\2/)s", regextarget=1, fullname=1) "StatBoostDefinition::DroneTarget::.*";

%luacode {
    --Create StatBoostDefinition enum tables
    Hyperspace.StatBoostDefinition.BoostType = {}
    Hyperspace.StatBoostDefinition.BoostSource = {}
    Hyperspace.StatBoostDefinition.ShipTarget = {}
    Hyperspace.StatBoostDefinition.SystemRoomTarget = {}
    Hyperspace.StatBoostDefinition.CrewTarget = {}
    Hyperspace.StatBoostDefinition.DroneTarget = {}

    for key, value in pairs(Hyperspace.StatBoostDefinition) do
        CreateEnumTable("BoostType_", Hyperspace.StatBoostDefinition.BoostType, key, value)
        CreateEnumTable("BoostSource_", Hyperspace.StatBoostDefinition.BoostSource, key, value)
        CreateEnumTable("ShipTarget_", Hyperspace.StatBoostDefinition.ShipTarget, key, value)
        CreateEnumTable("SystemRoomTarget_", Hyperspace.StatBoostDefinition.SystemRoomTarget, key, value)
        CreateEnumTable("CrewTarget_", Hyperspace.StatBoostDefinition.CrewTarget, key, value)
        CreateEnumTable("DroneTarget_", Hyperspace.StatBoostDefinition.DroneTarget, key, value)
    end
}


%rename("%s") StatBoostDefinition::stat;
%rename("%s") StatBoostDefinition::amount;
%rename("%s") StatBoostDefinition::value;
%rename("%s") StatBoostDefinition::stringValue;
%rename("%s") StatBoostDefinition::isBool;
%rename("%s") StatBoostDefinition::priority;
%rename("%s") StatBoostDefinition::duration;
%rename("%s") StatBoostDefinition::jumpClear;
%rename("%s") StatBoostDefinition::cloneClear;
%rename("%s") StatBoostDefinition::boostAnim;
%rename("%s") StatBoostDefinition::roomAnim;
%rename("%s") StatBoostDefinition::affectsSelf;
%rename("%s") StatBoostDefinition::whiteList;
%rename("%s") StatBoostDefinition::blackList;
%rename("%s") StatBoostDefinition::systemRoomReqs;
%rename("%s") StatBoostDefinition::systemList;
%rename("%s") StatBoostDefinition::providedStatBoosts;
%rename("%s") StatBoostDefinition::powerChange;
%rename("%s") StatBoostDefinition::powerWhitelist;
%rename("%s") StatBoostDefinition::powerBlacklist;
%rename("%s") StatBoostDefinition::powerResourceWhitelist;
%rename("%s") StatBoostDefinition::powerResourceBlacklist;
%rename("%s") StatBoostDefinition::powerGroupWhitelist;
%rename("%s") StatBoostDefinition::powerGroupBlacklist;
%rename("%s") StatBoostDefinition::hasPowerList;
%rename("%s") StatBoostDefinition::deathEffectChange;
%rename("%s") StatBoostDefinition::powerScaling;
%rename("%s") StatBoostDefinition::powerScalingNoSys;
%rename("%s") StatBoostDefinition::powerScalingHackedSys;
%rename("%s") StatBoostDefinition::systemPowerScaling;
%rename("%s") StatBoostDefinition::extraConditions;
%rename("%s") StatBoostDefinition::extraOrConditions;
%rename("%s") StatBoostDefinition::extraConditionsReq;
%rename("%s") StatBoostDefinition::systemRoomTarget;
%rename("%s") StatBoostDefinition::systemRoomReq;
%rename("%s") StatBoostDefinition::isRoomBased;
%rename("%s") StatBoostDefinition::boostSource;
%rename("%s") StatBoostDefinition::boostType;
%rename("%s") StatBoostDefinition::shipTarget;
%rename("%s") StatBoostDefinition::crewTarget;
%rename("%s") StatBoostDefinition::droneTarget;
%rename("%s") StatBoostDefinition::functionalTarget;
%rename("%s") StatBoostDefinition::healthReq;
%rename("%s") StatBoostDefinition::healthFractionReq;
%rename("%s") StatBoostDefinition::oxygenReq;
%rename("%s") StatBoostDefinition::fireCount;
%rename("%s") StatBoostDefinition::dangerRating;
%rename("%s") StatBoostDefinition::realBoostId;
%rename("%s") StatBoostDefinition::stackId;
%rename("%s") StatBoostDefinition::maxStacks;
%rename("%s") StatBoostDefinition::statBoostDefs;
%rename("%s") StatBoostDefinition::savedStatBoostDefs;



%nodefaultctor StatBoostManager;
%nodefaultdtor StatBoostManager;
%rename("%s") StatBoostManager;
%rename("%s") StatBoostManager::GetInstance;
%rename("%s") StatBoostManager::CreateTimedAugmentBoost;

%rename("%s") ShipGenerator;
%newobject ShipGenerator::CreateShip;
%rename("%s") ShipGenerator::CreateShip;
%rename("%s") ShipGenerator::GenerateSystemMaxes;
%rename("%s") ShipGenerator::GetPossibleCrewList;
%rename("%s") ShipGenerator::GetPossibleDroneList;
%rename("%s") ShipGenerator::GetPossibleSystemUpgrades;
%rename("%s") ShipGenerator::GetPossibleWeaponList;
%rename("%s") ShipGenerator::UpgradeSystem;

// Note to devs: CustomShipGenerator is deprecated, only minimal support is provided through lua bindings. New mods should use lua for custom ship generation.
%rename("%s") CustomShipGenerator;
%newobject CustomShipGenerator::CreateShip;
%rename("%s") CustomShipGenerator::CreateShip;
/*
%rename("%s") CustomShipGenerator::SectorScaling;
%rename("%s") CustomShipGenerator::SectorScaling::enabled;
%rename("%s") CustomShipGenerator::SectorScaling::minValue;
%rename("%s") CustomShipGenerator::SectorScaling::maxValue;
%rename("%s") CustomShipGenerator::SectorScaling::baseValue;
%rename("%s") CustomShipGenerator::SectorScaling::sectorValue;
%rename("%s") CustomShipGenerator::SectorScaling::GetValue;
%rename("%s") CustomShipGenerator::SystemLevelScaling;
%rename("%s") CustomShipGenerator::SystemLevelScaling::enabled;
%rename("%s") CustomShipGenerator::SystemLevelScaling::sectorScaling;
%rename("%s") CustomShipGenerator::SystemLevelScaling::randomScaling;
%rename("%s") CustomShipGenerator::SystemLevelScaling::GetRandomScalingValue;
%rename("%s") CustomShipGenerator::difficultyMod;
//%rename("%s") CustomShipGenerator::defaultSectorScaling;
//%rename("%s") CustomShipGenerator::systemLevelScaling;
%rename("%s") CustomShipGenerator::RemoveAugments;
%rename("%s") CustomShipGenerator::SetMaximumHull;
%rename("%s") CustomShipGenerator::InitShip;
%rename("%s") CustomShipGenerator::GenerateSystemMaxes;
%rename("%s") CustomShipGenerator::GenerateShipBudget;
%rename("%s") CustomShipGenerator::AddSystems;
%rename("%s") CustomShipGenerator::UpgradeSystems;
%rename("%s") CustomShipGenerator::GetPossibleSystemUpgrades;
%rename("%s") CustomShipGenerator::AddOverrideWeapons;
%rename("%s") CustomShipGenerator::AddOverrideDrones;
%rename("%s") CustomShipGenerator::AddWeapons;
%rename("%s") CustomShipGenerator::AddDrones;
%rename("%s") CustomShipGenerator::AddCrew;
%rename("%s") CustomShipGenerator::enabled;
%rename("%s") CustomShipGenerator::GetShipGenerator;
*/

%rename("%s") AnimationTracker;
%rename("%s") AnimationTracker::GetAlphaLevel;
%rename("%s") AnimationTracker::Progress;
%rename("%s") AnimationTracker::SetLoop;
%rename("%s") AnimationTracker::SetProgress;
%rename("%s") AnimationTracker::Start;
%rename("%s") AnimationTracker::StartReverse;
%rename("%s") AnimationTracker::Stop;
%rename("%s") AnimationTracker::time;
%rename("%s") AnimationTracker::loop;
%rename("%s") AnimationTracker::current_time;
%rename("%s") AnimationTracker::running;
%rename("%s") AnimationTracker::reverse;
%rename("%s") AnimationTracker::done;
%rename("%s") AnimationTracker::loopDelay;
%rename("%s") AnimationTracker::currentDelay;

%rename("%s") TimerHelper;
%rename("%s") TimerHelper::TimerHelper;
%rename("%s") TimerHelper::Done;
%rename("%s") TimerHelper::ResetMinMax;
%rename("%s") TimerHelper::Running;
%rename("%s") TimerHelper::SetMaxTime;
%rename("%s") TimerHelper::Start;
%rename("Start_Float") TimerHelper::Start(float);
%rename("%s") TimerHelper::Stop;
%rename("%s") TimerHelper::Update;
%rename("%s") TimerHelper::maxTime;
%rename("%s") TimerHelper::minTime;
%rename("%s") TimerHelper::currTime;
%rename("%s") TimerHelper::currGoal;
%rename("%s") TimerHelper::loop;
%rename("%s") TimerHelper::running;

%nodefaultctor SoundControl;
%nodefaultdtor SoundControl;
%rename("%s") SoundControl;
%rename("%s") SoundControl::PlaySoundMix;

%nodefaultctor SettingValues;
%nodefaultdtor SettingValues;
%rename("%s") SettingValues;
%rename("%s") SettingValues::fullscreen;
%immutable SettingValues::fullscreen;
%rename("%s") SettingValues::currentFullscreen;
%immutable SettingValues::currentFullscreen;
%rename("%s") SettingValues::lastFullscreen;
%immutable SettingValues::lastFullscreen;
%rename("%s") SettingValues::sound;
%immutable SettingValues::sound;
%rename("%s") SettingValues::music;
%immutable SettingValues::music;
%rename("%s") SettingValues::difficulty;
%immutable SettingValues::difficulty;
%rename("%s") SettingValues::commandConsole;
%immutable SettingValues::commandConsole;
%rename("%s") SettingValues::altPause;
%immutable SettingValues::altPause;
%rename("%s") SettingValues::touchAutoPause;
%immutable SettingValues::touchAutoPause;
%rename("%s") SettingValues::lowend;
%immutable SettingValues::lowend;
%rename("%s") SettingValues::fbError;
%immutable SettingValues::fbError;
%rename("%s") SettingValues::language;
%immutable SettingValues::language;
%rename("%s") SettingValues::languageSet;
%immutable SettingValues::languageSet;
%rename("%s") SettingValues::screenResolution;
%immutable SettingValues::screenResolution;
%rename("%s") SettingValues::dialogKeys;
%immutable SettingValues::dialogKeys;
%rename("%s") SettingValues::logging;
%immutable SettingValues::logging;
%rename("%s") SettingValues::bShowChangelog;
%immutable SettingValues::bShowChangelog;
%rename("%s") SettingValues::loadingSaveVersion;
%immutable SettingValues::loadingSaveVersion;
%rename("%s") SettingValues::achPopups;
%immutable SettingValues::achPopups;
%rename("%s") SettingValues::vsync;
%immutable SettingValues::vsync;
%rename("%s") SettingValues::frameLimit;
%immutable SettingValues::frameLimit;
%rename("%s") SettingValues::manualResolution;
%immutable SettingValues::manualResolution;
%rename("%s") SettingValues::manualWindowed;
%immutable SettingValues::manualWindowed;
%rename("%s") SettingValues::manualStretched;
%immutable SettingValues::manualStretched;
%rename("%s") SettingValues::showPaths;
%immutable SettingValues::showPaths;
%rename("%s") SettingValues::swapTextureType;
%immutable SettingValues::swapTextureType;
%rename("%s") SettingValues::colorblind;
%immutable SettingValues::colorblind;
%rename("%s") SettingValues::holdingModifier;
%immutable SettingValues::holdingModifier;
%rename("%s") SettingValues::bDlcEnabled;
%immutable SettingValues::bDlcEnabled;
%rename("%s") SettingValues::openedList;
%immutable SettingValues::openedList;
%rename("%s") SettingValues::beamTutorial;
%immutable SettingValues::beamTutorial;

//Access PrintHelper singleton through Hyperspace.PrintHelper.GetInstance()
%nodefaultctor PrintHelper;
%nodefaultdtor PrintHelper;
%rename("%s") PrintHelper;
%rename("%s") PrintHelper::GetInstance;
//Access settings through Hyperspace.PrintHelper.GetInstance().settingName or Hyperspace.PrintHelper.settingName
%rename("%s") PrintHelper::x; //x coordinate of messages (messages go down and to the right of this point)
%rename("%s") PrintHelper::y; //y coordinate of messages
%rename("%s") PrintHelper::font; //font that messages are rendered in
%rename("%s") PrintHelper::lineLength; //width (in pixels) before automatic newline
%rename("%s") PrintHelper::messageLimit; //how many messages may be displayed at once
%rename("%s") PrintHelper::duration; //how long each message lasts
%rename("%s") PrintHelper::useSpeed; //if the speed at which messages are cleared scales with game speed

%luacode
{
    setmetatable(Hyperspace.PrintHelper, {
        __index = function(PrintHelper, key)
            return PrintHelper.GetInstance()[key]
        end,

        __newindex = function(PrintHelper, key, value)
            PrintHelper.GetInstance()[key] = value
        end
    })
}

%nodefaultctor ResourceControl;
%nodefaultdtor ResourceControl;
%rename("%s") ResourceControl;
/*
%rename("%s") ResourceControl::ImageSwappingMode;
%rename("%s") ResourceControl::DynamicImageInfo;
%rename("%s") ResourceControl::DynamicImageInfo::name;
%rename("%s") ResourceControl::DynamicImageInfo::resid;
%rename("%s") ResourceControl::LogicalTexInfo;
%rename("%s") ResourceControl::LogicalTexInfo::physName;
%rename("%s") ResourceControl::LogicalTexInfo::x;
%rename("%s") ResourceControl::LogicalTexInfo::y;
%rename("%s") ResourceControl::LogicalTexInfo::w;
%rename("%s") ResourceControl::LogicalTexInfo::h;
*/
//%newobject ResourceControl::CreateImagePrimitive; // Not sure if needed
%rename("%s") ResourceControl::CreateImagePrimitive;
//%newobject ResourceControl::CreateImagePrimitiveString; // Not sure if needed
%rename("%s") ResourceControl::CreateImagePrimitiveString;
%rename("%s") ResourceControl::GetFontData;
//%newobject ResourceControl::GetImageId;
%rename("%s") ResourceControl::GetImageId;
%rename("%s") ResourceControl::ImageExists;
%rename("%s") ResourceControl::RenderImage;
%rename("%s") ResourceControl::RenderImageString;

%newobject ResourceControl::LoadFile;
%rename("%s") ResourceControl::LoadFile;

//%rename("%s") FileHelper;
//%rename("%s") FileHelper::deleteAllSaveFiles;

%rename("%s") Point;
%rename("%(regex:/^Point::(.*)$/\\1/)s", regextarget=1, fullname=1) "Point::.*";
%rename("%s") Pointf;
%rename("%(regex:/^Pointf::(.*)$/\\1/)s", regextarget=1, fullname=1) "Pointf::.*";

%wrapper %{

    static void script_add_native_member(lua_State *L, const char *className, const char *memberName, lua_CFunction fn)
    {
        SWIG_Lua_get_class_registry(L); /* get the registry */
        lua_pushstring(L, className);   /* get the name */
        lua_rawget(L,-2);               /* get the metatable itself */
        lua_remove(L,-2);               /* tidy up (remove registry) */

        // If the metatable is not null, add the method to the ".get" table
        if(lua_isnil(L, -1) != 1)
        {
            SWIG_Lua_get_table(L, ".get");
            SWIG_Lua_add_function(L, memberName, fn);
            lua_pop(L, 2);              /* tidy up (remove metatable and ".get" table) */
        }
        else
        {
            printf("[script_add_native_member(..)] - \"%s\" metatable is not found. Member \"%s\" will not be added\n", className, memberName);
            return;
        }
    }

%}


%{
    static int hs_Userdata_table_get(lua_State* lua)
    {
        luaL_argcheck(lua, lua_isuserdata(lua, 1), 1, "Expected argument of type 'Userdata'");
        swig_lua_userdata *usr = (swig_lua_userdata*) lua_touserdata(lua, 1);
        lua_rawgetp(lua, LUA_REGISTRYINDEX, usr->ptr);
        return 1;
    };
%}

%init %{
    script_add_native_member(L, "Projectile", "table", hs_Userdata_table_get);
    script_add_native_member(L, "ProjectileFactory", "table", hs_Userdata_table_get);
    script_add_native_member(L, "CrewMember", "table", hs_Userdata_table_get);
    script_add_native_member(L, "ShipSystem", "table", hs_Userdata_table_get);
    script_add_native_member(L, "ShipManager", "table", hs_Userdata_table_get);
    script_add_native_member(L, "Room", "table", hs_Userdata_table_get);
    script_add_native_member(L, "SpaceDrone", "table", hs_Userdata_table_get);
%}
%rename("%s") TextString;
%rename("%s") TextString::GetText;
%rename("%s") TextString::data;
%rename("%s") TextString::isLiteral;

/*
    By default in Codeblocks SWIG settings we don't get the regular preprocessor defines, ideally we should switch between which FTLGame we import.
    To avoid having to change codeblocks compiler settings (that don't save/share between our installs) we're going to just try to use the
    Linux64 file for now. Since SWIG only uses this for method & field names but not for actual access to the address (the regular headers are
    loaded at compile time) unless we want to access a field in Lua not available to the other versions there is no concern.
*/
%include "FTLGameELF64.h"
%include "CustomAchievements.h"
%include "CustomAugments.h"
%include "CustomCrew.h"
%include "CustomEvents.h"
%include "CustomScoreKeeper.h"
%include "CustomShipGenerator.h"
%include "CustomShipSelect.h"
%include "CrewMember_Extend.h"
%include "Projectile_Extend.h"
%include "ShipManager_Extend.h"
%include "System_Extend.h"
%include "Room_Extend.h"
%include "StatBoost.h"
%include "ShipUnlocks.h"
%include "CommandConsole.h"
