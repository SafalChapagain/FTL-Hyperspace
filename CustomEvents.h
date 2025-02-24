#pragma once
#include "Global.h"
#include "ToggleValue.h"
#include "CustomBackgroundObject.h"
#include "EventButtons.h"
#include <algorithm>
#include <memory>
#include <unordered_set>
#include <bitset>
#include <boost/format.hpp>
#include <rapidxml_print.hpp>

extern std::bitset<8> advancedCheckEquipment;
// bit 0: WorldManager::CreateChoiceBox
// bit 1: StarMap::RenderLabels
// bit 2: LoadEvent
// bit 3: CustomBackgroundObject::OnLoop and EventButton::CheckReq
// bit 4: VariableModifier::ApplyVariables
// bit 5: TriggeredEvent::Update
// bit 6: StarMap::GenerateEvents (priority events), StarMap::GenerateMap (sector quests and regenerated events)
// bit 7: lua

extern bool alreadyWonCustom;
extern bool bossDefeated;
extern TimerHelper *restartMusicTimer;

extern std::string replaceCreditsMusic;

struct CreditText
{
    std::string text;
    int font;
    int spacing;
    int horizontal;
    int lineLenght;
    float cutOff;
};
extern std::vector<CreditText> creditTextValues;

struct CreditFinishText
{
    std::string text;
    int font;
    int spacing;
    int horizontal;
    int lineLenght;
    float cutOff;
};
extern std::vector<CreditFinishText> creditFinishTextValues;

struct CreditFile
{
    std::string names;
    int spacing;
    float cutOff;
};
extern std::vector<CreditFile> creditFileNames;

extern bool needSectorQuests;
extern std::unordered_map<int, std::string> renamedBeacons;
extern std::unordered_map<int, std::pair<std::string, int>> regeneratedBeacons;
extern std::vector<bool> savedPriorityEventReq;

extern std::unordered_map<std::string, int> playerVariables;

struct JumpEvent
{
    std::string event = "";
    std::string label = "";
    bool loop = false;
    int priority = 0;
};
extern std::vector<JumpEvent> jumpEventQueue;


struct DeathEvent
{
    std::string event = "";
    std::string label = "";
    bool jumpClear = false;
    bool thisFight = false;
    int priority = 0;
};
extern std::deque<DeathEvent> deathEventQueue;
extern bool deathEventActive;

struct BeaconType
{
    std::string eventName;
    GL_Color color;
    bool global = false;
    bool persistent = false;
    bool hideVanillaLabel = false;
    TextString beaconText;
    TextString undiscoveredTooltip;
    TextString unvisitedTooltip;
    TextString visitedTooltip;
    std::string equipmentReq;
};

struct EventGameOver
{
    bool enabled = false;
    bool victory = false;
    std::string text = "";
    std::string creditsText = "";
    std::string creditsBackground = "";
    std::string creditsMusic = "";
    std::string sound = "";
    std::string ach = "";
};

struct CustomQuest
{
    ToggleValue<bool> nonNebulaBeacon;
    ToggleValue<bool> nebulaBeacon;
    ToggleValue<bool> createNebula;
    ToggleValue<std::string> nebulaEvent;
    ToggleValue<bool> currentSector;
    ToggleValue<bool> nextSector;
    ToggleValue<int> aggressive;
    ToggleValue<bool> sectorEight;
    ToggleValue<bool> lastStand;

    CustomQuest()
    {
        nonNebulaBeacon.value = true;
        nebulaBeacon.value = false;
        createNebula.value = true;
        nebulaEvent.value = "";
        currentSector.value = true;
        nextSector.value = true;
        aggressive.value = 0;
        sectorEight.value = false;
        lastStand.value = false;
    }

    void add(CustomQuest *other)
    {
        if (other->nonNebulaBeacon.enabled) nonNebulaBeacon = other->nonNebulaBeacon;
        if (other->nebulaBeacon.enabled) nebulaBeacon = other->nebulaBeacon;
        if (other->createNebula.enabled) createNebula = other->createNebula;
        if (other->nebulaEvent.enabled) nebulaEvent = other->nebulaEvent;
        if (other->currentSector.enabled) currentSector = other->currentSector;
        if (other->nextSector.enabled) nextSector = other->nextSector;
        if (other->aggressive.enabled) aggressive = other->aggressive;
        if (other->sectorEight.enabled) sectorEight = other->sectorEight;
        if (other->lastStand.enabled) lastStand = other->lastStand;
    }
};

class TriggeredEventBoxDefinition
{
public:
    enum class BoxPosition
    {
        DEFAULT,
        SCRAP,
        TOPRIGHT,
        COMBAT
    };

    enum class TextType
    {
        TIME_AUTO,
        TIME_CLOCK,
        TIME_SECONDS,
        JUMPS,
        REQ,
        REQ_PROGRESS
    };

    BoxPosition boxPosition = BoxPosition::DEFAULT;
    int priority = 0;

    std::string image = "";
    GL_Color imageColor = GL_Color(1.f, 1.f, 1.f, 1.f);
    std::string image2 = "";
    GL_Color imageColor2 = GL_Color(1.f, 1.f, 1.f, 1.f);
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;

    int left = 0;
    int right = 0;
    int top = 0;
    int bottom = 0;

    std::string imageFront = "";
    GL_Color imageColorFront = GL_Color(1.f, 1.f, 1.f, 1.f);
    int front_x;
    int front_y;

    TextType textType = TextType::TIME_AUTO;
    GL_Color textColor = GL_Color(1.f, 1.f, 1.f, 1.f);
    GL_Color textColor2 = GL_Color(1.f, 1.f, 1.f, 1.f);
    int text_x = 0;
    int text_y = 0;

    TextString tooltip = TextString();

    float warningTime = -999.f;
    int warningJumps = -999;
    bool flash = false;
};

struct TriggeredEventWarningDefinition
{
    std::string image = "";
    TextString text;
    Point position = Point(0,0);
    float time = 5.0;
    bool centerText = true;
    bool flash = false;
    GL_Color textColor = GL_Color(253.f, 84.f, 70.f, 1.f);
    std::string sound = "";
    bool useWarningLine = false;
};

class TriggeredEventDefinition
{
public:
    static std::vector<TriggeredEventDefinition> defs;
    static std::unordered_map<std::string,std::vector<std::pair<float,std::string>>> timerSoundDefs;
    static unsigned int PushDef(TriggeredEventDefinition& def);
public:
    TriggeredEventBoxDefinition* box = nullptr;
    std::vector<char>* loadBox = nullptr;

    std::vector<std::pair<float,std::string>> timerSounds;
    std::string loadTimerSounds = "";

    TriggeredEventWarningDefinition* warning = nullptr;
    std::vector<char>* loadWarning = nullptr;

    unsigned int idx = -1;

    std::string name = "";
    std::string event = "";
    bool seeded = true;
    bool clearOnJump = false;
    bool thisFight = false;
    uint8_t jumpType = 0;
    int minLoops = 1;
    int maxLoops = 1;
    float triggerMinTime = -1.f;
    float triggerMaxTime = -1.f;
    int triggerMinJumps = -1;
    int triggerMaxJumps = -1;
    int minPlayerHull = -1;
    int maxPlayerHull = -1;
    int minPlayerDamage = -1;
    int maxPlayerDamage = -1;
    int minEnemyHull = -1;
    int maxEnemyHull = -1;
    int minEnemyDamage = -1;
    int maxEnemyDamage = -1;
    float enemyHullScaling = 0.f;
    float enemyDamageScaling = 0.f;
    int minPlayerCrew = -1;
    int maxPlayerCrew = -1;
    int minPlayerDeaths = -1;
    int maxPlayerDeaths = -1;
    int minEnemyCrew = -1;
    int maxEnemyCrew = -1;
    int minEnemyDeaths = -1;
    int maxEnemyDeaths = -1;
    bool playerCountRepairs = true;
    bool playerCountNewCrew = true;
    bool enemyCountRepairs = true;
    bool enemyCountNewCrew = true;
    bool playerCrewCountClonebay = true;
    bool enemyCrewCountClonebay = true;
    bool playerDeathsCountClonebay = true;
    bool enemyDeathsCountClonebay = true;
    std::string req = "";
    std::pair<int, int> reqMinLvl = {1,1};
    std::pair<int, int> reqMaxLvl = {2147483647,2147483647};
    bool inverseReq = false;
};

class TriggeredEvent
{
public:
    static std::unordered_map<std::string, TriggeredEvent> eventList;

    static void NewEvent(TriggeredEventDefinition* def);
    static void DestroyEvent(const std::string& name);
    static void UpdateAll();
    static void RenderAll();
    static void JumpAll(uint8_t jumpType);
    static void TriggerCheck();
    static void SaveAll(int file);
    static void LoadAll(int file);

    static int playerCloneCount;

public:
    TriggeredEventDefinition* def;

    int seed = -1;
    int loops;
    TimerHelper* triggerTimer = nullptr;
    int timerSoundIndex = 0;
    int triggerJumps;
    int triggerPlayerHull;
    int triggerEnemyHull;
    int triggerPlayerCrew;
    int triggerEnemyCrew;

    int triggerPlayerDamage;
    int triggerEnemyDamage;
    int triggerPlayerDeaths;
    int triggerEnemyDeaths;

    int currentPlayerHull;
    int currentEnemyHull;
    int currentPlayerCrew;
    int currentEnemyCrew;

    int reqMinLvl;
    int reqMaxLvl;
    int reqLvl;

    bool triggered = false;

    WarningMessage* warning = nullptr;
    float warningTime = -1.f;

    TriggeredEvent(TriggeredEventDefinition* newDef) : def{newDef}
    {
        if (def->seeded) seed = random32();

        if (def->maxLoops > def->minLoops)
        {
            loops = def->minLoops + random32()%(def->maxLoops-def->minLoops+1);
        }
        else
        {
            loops = def->minLoops;
        }

        if (def->triggerMinTime != -1.f)
        {
            triggerTimer = new TimerHelper();
        }

        if (def->warning != nullptr)
        {
            warning = new WarningMessage();
            if (!def->warning->image.empty())
            {
                warning->InitImage(def->warning->image, def->warning->position, def->warning->time, def->warning->flash);
            }
            else
            {
                warning->InitText(def->warning->text, def->warning->position, def->warning->time, def->warning->textColor, def->warning->centerText, def->warning->flash);
            }
            if (!def->warning->sound.empty()) warning->SetSound(def->warning->sound);
            warning->useWarningLine = def->warning->useWarningLine;
            warning->SetLoop(true);
            warningTime = def->warning->time;
        }

        currentPlayerHull = 0;
        currentEnemyHull = 0;
        currentPlayerCrew = 0;
        currentEnemyCrew = 0;

        if (!def->req.empty())
        {
            ShipManager *ship = G_->GetShipManager(0);
            if (ship != nullptr)
            {
                advancedCheckEquipment[5] = true;
                reqLvl = ship->HasEquipment(def->req);
                advancedCheckEquipment[5] = false;
            }
        }

        Reset();
    }

    ~TriggeredEvent()
    {
        delete triggerTimer;
        delete warning;
    }

    float GetTimeLeft()
    {
        if (triggerTimer == nullptr) return 0.0;
        if (triggerTimer->currTime >= triggerTimer->currGoal) return 0.0;
        return triggerTimer->currGoal - triggerTimer->currTime;
    }

    int GetPlayerCrew(bool clones)
    {
        int ret = G_->GetCrewFactory()->playerCrew;
        if (!clones) ret -= playerCloneCount;
        return ret;
    }
    int GetEnemyCrew(bool clones)
    {
        int ret = G_->GetCrewFactory()->enemyCrew;
        if (!clones) ret -= G_->GetCrewFactory()->enemyCloneCount;
        return ret;
    }

    void Reset();
    void Update();
    void OnRender();
    void Jump(uint8_t jumpType);
    void Save(int file);
    void Load(int file);
};

class TriggeredEventModifier
{
public:
    std::string name = "";
    float minTime = 0.f;
    float maxTime = 0.f;
    int minJumps = 0;
    int maxJumps = 0;

    void ApplyModifier()
    {
        auto it = TriggeredEvent::eventList.find(name);
        if (it != TriggeredEvent::eventList.end())
        {
            TriggeredEvent& event = it->second;
            if (event.triggerTimer != nullptr)
            {
                float modTime = minTime;
                if (maxTime > minTime)
                {
                    int minTime_ = minTime * 1000.f;
                    int maxTime_ = maxTime * 1000.f;
                    modTime = (minTime_ + random32()%(maxTime_-minTime_+1)) / 1000.f;
                }
                event.triggerTimer->currGoal += modTime;
                if (event.triggerTimer->currGoal < event.triggerTimer->currTime) event.triggerTimer->currGoal = event.triggerTimer->currTime;
            }
            if (event.triggerJumps >= 0)
            {
                int modJumps = minJumps;
                if (maxJumps > minJumps) modJumps = minJumps + random32()%(maxJumps-minJumps+1);
                event.triggerJumps = std::max(0, event.triggerJumps + modJumps);
            }
        }
    }
};

struct GL_Primitive_Deleter {
    void operator()(GL_Primitive* p) {
        CSurface::GL_DestroyPrimitive(p);
    }
};

class TriggeredEventBox
{
public:
    TriggeredEvent* event;
    TriggeredEventBoxDefinition* boxDef;

    std::unique_ptr<GL_Primitive, GL_Primitive_Deleter> backgroundIcon;
    std::unique_ptr<GL_Primitive, GL_Primitive_Deleter> backgroundIcon2;
    std::unique_ptr<GL_Primitive, GL_Primitive_Deleter> foregroundIcon;

    int x;
    int y;
    int width;
    int height;
    int text_x;
    int text_y;

    ~TriggeredEventBox() noexcept = default;
    TriggeredEventBox(const TriggeredEventBox&) = delete;
    TriggeredEventBox(TriggeredEventBox&& other) noexcept = default;
    TriggeredEventBox& operator=(const TriggeredEventBox&) = delete;
    TriggeredEventBox& operator=(TriggeredEventBox&&) noexcept = default;

    TriggeredEventBox(TriggeredEvent* e, int x_, int y_) :
        event{e},
        x{x_},
        y{y_}
    {
        boxDef = e->def->box;
        if (!boxDef->image.empty()) backgroundIcon.reset(G_->GetResources()->CreateImagePrimitiveString(boxDef->image, x - boxDef->x, y - boxDef->y, 0, boxDef->imageColor, 1.f, false));
        if (!boxDef->image2.empty()) backgroundIcon2.reset(G_->GetResources()->CreateImagePrimitiveString(boxDef->image2, x - boxDef->x, y - boxDef->y, 0, boxDef->imageColor2, 1.f, false));
        if (!boxDef->imageFront.empty()) foregroundIcon.reset(G_->GetResources()->CreateImagePrimitiveString(boxDef->imageFront, x + boxDef->front_x, y + boxDef->front_y, 0, boxDef->imageColorFront, 1.f, false));
        width = boxDef->w;
        height = boxDef->h;
        text_x = x + boxDef->text_x;
        text_y = y + boxDef->text_y;
    }

    static std::string GetTimeTextClock(int t);
    static std::string GetTimeTextSeconds(float t);
    void OnRender(bool flash);
    void MouseMove(int mx, int my);
};

class TriggeredEventGui
{
public:
    Point normalBoxPos = Point(1259, 110);
    Point bossBoxPos = Point(1266, 72);

    std::unordered_map<std::string, TriggeredEventBoxDefinition> boxDefs;
    std::unordered_map<std::string, TriggeredEventWarningDefinition> warningDefs;

    std::vector<TriggeredEventBox> boxes;
    TriggeredEventBox* scrapBox = nullptr;
    std::vector<TriggeredEventBox> topRightBoxes;
    std::vector<TriggeredEventBox> combatBoxes;

    AnimationTracker flashTracker;

    bool reset = true;

    TriggeredEventGui()
    {
        flashTracker.time = 1.f;
        flashTracker.loop = true;
        flashTracker.current_time = 0.f;
        flashTracker.running = true;
        flashTracker.reverse = false;
        flashTracker.done = false;
        flashTracker.loopDelay = 0.f;
        flashTracker.currentDelay = 0.f;
    }

    void CreateBoxes();
    void OnRender();
    void OnRenderCombat(CombatControl* this2);
    void MouseMove(int x, int y);

    static TriggeredEventGui *GetInstance()
    {
        return instance;
    }

private:
    static TriggeredEventGui *instance;
};

struct EventFleet
{
    std::string fleetDefName;
    bool firing;
    bool autoDarkening;
};

struct EventLoadListEvent
{
    std::string event = "";
    std::string req = "";
    int lvl = 1;
    int max_lvl = 2147483647;
    int max_group = -1;
};

struct EventLoadList
{
    std::vector<EventLoadListEvent> events;
    bool seeded = true;
    bool useFirst = false;
    bool onGenerate = false;
    bool ignoreUnique = false;
    std::string defaultEvent = "";
};

struct EventAlias
{
    std::string event;
    bool jumpClear = false;
    bool once = false;
};

struct EventQueueEvent
{
    std::string event;
    std::string label;
    int seed = 0;
};
extern std::deque<EventQueueEvent> eventQueue;

struct SectorReplace
{
    std::string targetSector = "";
    std::string sectorList = "";
};

struct VariableModifier
{
    enum class VarType
    {
        VAR,
        METAVAR,
        TEMP
    };

    enum class OP
    {
        SET,
        ADD,
        MUL,
        DIV,
        MIN,
        MAX
    };

    VarType vType = VarType::VAR;
    std::string name = "";
    OP op = OP::SET;
    int minVal = 0;
    int maxVal = 0;
    std::string var = "";

    bool force = false;

    void ParseVariableModifierNode(rapidxml::xml_node<char> *node);
    static void ApplyVariables(std::vector<VariableModifier> &variables, ShipManager *ship);
};

extern std::unordered_map<std::string, EventAlias> eventAliases;

struct CustomEvent
{
    std::string eventName;
    std::string unlockShip = "";
    bool unlockShipSilent = false;
    std::string unlockShipReq = "";
    BeaconType *beacon = nullptr;
    std::string loadBeacon = "";
    bool checkCargo = false;
    bool recursive = true;
    bool preventQuest = false;
    bool noQuestText = false;
    std::vector<unsigned int> triggeredEvents;
    std::vector<std::string> clearTriggeredEvents;
    std::vector<TriggeredEventModifier> triggeredEventModifiers;
    bool preventFleet = false;
    int preventBossFleet = 0;
    int runFromFleet = 0;
    bool removeHazards = false;
    bool removeNebula = false;
    std::string secretSectorWarp = "";
    bool recallBoarders = false;
    int recallBoardersShip = 0;
    bool recallBoardersForce = false;
    std::string eventLoad = "";
    bool eventLoadSeeded = true;
    bool eventLoadIgnoreUnique = false;
    EventLoadList *eventLoadList = nullptr;
    std::string eventRevisit = "";
    bool eventRevisitSeeded = true;
    bool eventRevisitIgnoreUnique = false;
    std::vector<std::pair<std::string, EventAlias>> eventAlias;
    std::vector<EventQueueEvent> queueEvents;
    std::vector<std::string> clearQueueEvents;
    bool restartEvent = false;
    std::string renameBeacon = "";
    EventGameOver gameOver = EventGameOver();
    std::string achievement = "";
    bool achievementSilent = false;
    bool disableScrapScore = false;
    bool disableScrapAugments = false;
    bool removeStore = false;
    std::string customStore = "";
    std::vector<JumpEvent> jumpEvents;
    std::vector<std::string> clearJumpEvents;
    std::vector<DeathEvent> deathEvents;
    std::vector<std::string> clearDeathEvents;
    SectorReplace replaceSector;
    bool resetFtl = false;
    bool instantEscape = false;
    bool escape = false;
    bool surrender = false;
    bool loadEscape = false;
    bool loadSurrender = false;
    bool loadEscapeForced = false;
    bool loadSurrenderForced = false;
    bool disableEscape = false;
    bool disableSurrender = false;
    bool disableEscapeForced = false;
    bool disableSurrenderForced = false;
    bool goToFlagship = false;
    bool goToFlagshipBase = false;
    bool goToFlagshipFleet = false;
    bool noASBPlanet = false;
    bool repairAllSystems = false;
    bool killEnemyBoarders = false;

    EventFleet leftFleet;
    EventFleet rightFleet;
    bool clearCustomFleet = false;

    std::vector<CustomBackgroundObjectDefinition*> backgroundObjects;
    std::vector<std::string> clearBackgroundObjects;
    std::vector<std::pair<std::string,std::string>> transformBackgroundObjects;

    std::vector<EventButtonDefinition*> eventButtons;
    std::vector<std::string> clearEventButtons;

    std::vector<std::string> hiddenAugs = std::vector<std::string>();
    std::vector<std::string> removeItems = std::vector<std::string>();
    std::vector<std::pair<bool, int>> removeSystems = std::vector<std::pair<bool, int>>();
    std::vector<VariableModifier> variables = std::vector<VariableModifier>();
    std::string playSound = "";
    std::string playMusic = "";
    bool resetMusic = false;
    std::string changeBackground = "";

    std::vector<EventDamage> enemyDamage = std::vector<EventDamage>();

    std::pair<std::string,std::string> transformRace = std::pair<std::string,std::string>("","");
    bool allowNoSlot = false;
    bool blockNoSlot = false;
    bool choiceRequiresCrew = false;
    std::pair<float,float> ignoreEssential = {-HUGE_VAL, HUGE_VAL};

    int superDrones = -1;
    std::string superDronesName = "";
    int clearSuperDrones = -1;
    int superBarrage = -1;
    std::string superBarrageName = "";
    int powerSuperShields = -1;
    int powerSuperShieldsSet = -1;
    int powerSuperShieldsAdd = 0;

    CustomEvent();
};

struct CustomShipEvent
{
    std::string eventName;
    std::vector<unsigned int> triggeredEvents;
    std::vector<std::string> clearTriggeredEvents;
    std::vector<TriggeredEventModifier> triggeredEventModifiers;
    std::vector<JumpEvent> jumpEvents;
    std::vector<std::string> clearJumpEvents;
    std::vector<DeathEvent> deathEvents;
    std::vector<std::string> clearDeathEvents;

    bool invincible = false;
    bool deadCrewAuto = false;

    EventGameOver finalBoss = EventGameOver();
    int bossMusicDelay = -1;
};

struct SectorExit
{
    std::string event = "";
    std::string rebelEvent = "";
    std::string nebulaEvent = "";
};

struct SectorFleet
{
    std::string event = "";
    std::string nebulaEvent = "";
};

struct PriorityEvent
{
    std_pair_std_string_RandomAmount event;
    int priority = 0;
    std::string req = "";
    int lvl = 1;
    int max_lvl = 2147483647;
};

struct SectorQuest
{
    std::string event;
    std::string req = "";
    int lvl = 1;
    int max_lvl = 2147483647;
};

struct CustomSector
{
    std::string sectorName;
    SectorExit exitBeacons;
    SectorFleet fleetBeacons;
    bool removeFirstBeaconNebula = false;
    bool noExit = false;
    ToggleValue<bool> nebulaSector;
    int maxSector = -1;
    std::vector<PriorityEvent> priorityEventCounts;
    std::vector<SectorQuest> sectorQuests;
};

struct BossShipDefinition
{
    std::string shipId;
    int yOffset = 120;
};

class CustomReq
{
public:
    static int HasEquipment_Any(ShipObject& ship, const std::vector<std::string>& blueprintList)
    {
        int ret = 0;

        for (auto const& blueprint : blueprintList)
        {
            ret = std::max(ret, ship.HasEquipment(blueprint));
        }
        return ret;
    }

    static int HasEquipment_All(ShipObject& ship, const std::vector<std::string>& blueprintList)
    {
        int ret = 2147483647;

        for (auto const& blueprint : blueprintList)
        {
            ret = std::min(ret, ship.HasEquipment(blueprint));
        }
        return ret;
    }

    static int HasEquipment_Sum(ShipObject& ship, const std::vector<std::string>& blueprintList)
    {
        int ret = 0;

        for (auto const& blueprint : blueprintList)
        {
            ret += ship.HasEquipment(blueprint);
        }
        return ret;
    }

    enum REQ_TYPE
    {
        TYPE_ANY,
        TYPE_ALL,
        TYPE_SUM
    };

    std::string name = "";
    int type = TYPE_ANY;
    std::vector<std::string> blueprints = std::vector<std::string>();
    std::vector<CustomReq> children = std::vector<CustomReq>();
    int lvl = -1;
    int max_lvl = -1;
    int mult = 1;
    int constant = 0;

    int HasEquipment(ShipObject& ship)
    {
        int ret;

        switch(type)
        {
        case TYPE_ANY:
            ret = HasEquipment_Any(ship, blueprints);
            for (auto& child : children)
            {
                ret = std::max(ret, child.HasEquipment(ship));
            }
            break;
        case TYPE_ALL:
            ret = HasEquipment_All(ship, blueprints);
            for (auto& child : children)
            {
                ret = std::min(ret, child.HasEquipment(ship));
            }
            break;
        case TYPE_SUM:
            ret = HasEquipment_Sum(ship, blueprints);
            for (auto& child : children)
            {
                ret += child.HasEquipment(ship);
            }
            break;
        }

        if (lvl > -1 || max_lvl > -1)
        {
            int counter = ret;
            ret = counter >= lvl;
            if (max_lvl > -1) ret &= counter <= max_lvl;
        }

        return ret * mult + constant;
    }
};

class CustomEventsParser
{
public:
    CustomEventsParser()
    {
        defaultVictory = new CustomEvent();
        defaultQuest = new CustomQuest();
    }

    void EarlyParseCustomEventNode(rapidxml::xml_node<char> *node);
    void ReadCustomEventFiles();
    void PostProcessCustomEvents();
    void ParseVanillaBaseNode(rapidxml::xml_node<char> *node);
    void ParseVanillaEventNode(rapidxml::xml_node<char> *node, const std::string &eventName, const std::string &baseEventName);
    void ParseVanillaShipEventNode(rapidxml::xml_node<char> *node, const std::string &eventName);
    void ParseCustomSector(rapidxml::xml_node<char> *node, CustomSector *sector, bool parsingVanilla = false);
    void ParseCustomCredits(rapidxml::xml_node<char> *node);
    void ParseCustomCreditsPause(rapidxml::xml_node<char> *node);
    void ParseCustomEventNode(rapidxml::xml_node<char> *node);
    bool ParseCustomEvent(rapidxml::xml_node<char> *node, CustomEvent *event, bool parsingVanilla = false);
    bool ParseCustomShipEvent(rapidxml::xml_node<char> *node, CustomShipEvent *event);
    bool ParseCustomQuestNode(rapidxml::xml_node<char> *node, CustomQuest *quest);
    void ParseCustomBeaconType(rapidxml::xml_node<char> *node, BeaconType *beaconType);
    void ParseCustomReqNode(rapidxml::xml_node<char> *node, CustomReq *req);
    void ParseCustomTriggeredEventNode(rapidxml::xml_node<char> *node, TriggeredEventDefinition *def);
    void ParseCustomTriggeredEventBoxNode(rapidxml::xml_node<char> *node, TriggeredEventBoxDefinition *box);
    void ParseCustomTriggeredEventSounds(rapidxml::xml_node<char> *node, std::vector<std::pair<float,std::string>> *vec);
    void ParseCustomTriggeredEventWarningNode(rapidxml::xml_node<char> *node, TriggeredEventWarningDefinition *warning);
    void ParseCustomEventLoadList(rapidxml::xml_node<char> *node, EventLoadList *eventList, std::string& eventName);

    static CustomEventsParser *GetInstance()
    {
        return instance;
    }

    BossShipDefinition *GetBossShipDefinition(const std::string& shipId)
    {
        if (bossShipIds.find(shipId) != bossShipIds.end())
        {
            return &bossShipIds[shipId];
        }

        return nullptr;
    }

    CustomEvent *GetCustomEvent(const std::string& event);
    CustomEvent *GetCustomEvent(Location *loc);
    CustomShipEvent *GetCustomShipEvent(const std::string& event);
    CustomQuest *GetCustomQuest(const std::string& event);
    CustomSector *GetCustomSector(const std::string& sectorName);
    CustomSector *GetCustomSectorPreload(const std::string& sectorName);
    CustomSector *GetCurrentCustomSector(StarMap *starMap);
    CustomReq *GetCustomReq(const std::string& blueprint);

    static std::string GetBaseEventName(const std::string& event)
    {
        if (event.find(' ') == std::string::npos)
        {
            return event;
        }
        else
        {
            return event.substr(0, event.find(' '));
        }
    }

    LocationEvent* GetEvent(WorldManager *world, EventLoadList *eventList, int seed);
    LocationEvent* GetEvent(WorldManager *world, std::string eventName, bool ignoreUnique, int seed);
    void LoadEvent(WorldManager *world, EventLoadList *eventList, int seed, CustomEvent *parentEvent = nullptr);
    void LoadEvent(WorldManager *world, std::string eventName, bool ignoreUnique, int seed, CustomEvent *parentEvent = nullptr);
    static void QueueEvent(EventQueueEvent &event);
    static void QueueEvent(std::string &event, int seed);

    std::vector<std::string> eventFiles;
    CustomEvent *defaultVictory;
    CustomQuest *defaultQuest;
    std::string defaultRevisit = "";
    bool defaultRevisitSeeded = true;
    bool defaultRevisitIgnoreUnique = false;

    std::vector<VariableModifier> initialPlayerVars = std::vector<VariableModifier>();
    std::vector<VariableModifier> initialMetaVars = std::vector<VariableModifier>();

private:
    std::unordered_map<std::string, CustomSector*> customSectors;
    std::unordered_map<std::string, CustomSector*> customSectorsPreload;
    std::unordered_map<std::string, CustomEvent*> customEvents;
    std::unordered_map<std::string, CustomEvent*> customRecursiveEvents;
    std::unordered_map<std::string, std::vector<CustomEvent*>> vCustomEvents;
    std::unordered_map<std::string, CustomShipEvent*> customShipEvents;
    std::unordered_map<std::string, CustomQuest*> customQuests;
    std::unordered_map<std::string, BossShipDefinition> bossShipIds;
    std::unordered_map<std::string, BeaconType*> customBeacons;
    std::unordered_map<std::string, CustomReq*> customReqs;
    std::unordered_map<std::string, EventLoadList*> customEventLoadLists;
    static CustomEventsParser *instance;
};

class BossFleetPrevention
{
public:
    StarMap* starMap;
    std::unordered_map<Location*, int> potentialFleetLocs = std::unordered_map<Location*, int>();
    std::unordered_set<Location*> fleetBlockedLocs = std::unordered_set<Location*>();

    void Clear()
    {
        for (auto i : fleetBlockedLocs)
        {
            if (i->beacon || !i->boss)
            {
                i->dangerZone = false;
            }
        }
        potentialFleetLocs.clear();
        fleetBlockedLocs.clear();
    }

    void Set()
    {
        bool hasVulnerableLoc = false;

        for (auto i : starMap->locations)
        {
            if (!i->dangerZone && !i->fleetChanging && !i->beacon)
            {
                if (i->visited)
                {
                    potentialFleetLocs[i] = 0;
                    hasVulnerableLoc = true;
                }
                else
                {
                    auto locEvent = i->event;
                    auto customEvents = CustomEventsParser::GetInstance();
                    auto customEvent = customEvents->GetCustomEvent(locEvent->eventName);

                    if (customEvent && (customEvent->preventBossFleet || customEvent->preventFleet))
                    {
                        potentialFleetLocs[i] = customEvent->preventFleet ? 2 : customEvent->preventBossFleet;
                    }
                    else
                    {
                        potentialFleetLocs[i] = 0;
                        hasVulnerableLoc = true;
                    }
                }
            }
        }

        for (auto i : potentialFleetLocs)
        {
            if (i.second && (hasVulnerableLoc || i.second == 2))
            {
                fleetBlockedLocs.insert(i.first);
                i.first->dangerZone = true;
            }
        }
    }
};

void EventDamageEnemy(EventDamage eventDamage);
void GoToFlagship(bool atBase, bool allFleet);
void RecallBoarders(int direction, bool force);
