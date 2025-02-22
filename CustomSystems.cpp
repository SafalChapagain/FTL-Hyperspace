#include "CustomSystems.h"
#include "FTLGame.h"
#include "TemporalSystem.h"
#include "CustomOptions.h"
#include "CustomShipSelect.h"
#include "CustomShips.h"
#include "SystemBox_Extend.h"
#include <boost/lexical_cast.hpp>

#include <cmath>

void ParseSystemsNode(rapidxml::xml_node<char>* node)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();
        std::string val = child->value();

        if (name == "system" && child->first_attribute("id"))
        {
            std::string sysName = child->first_attribute("id")->value();

            if (sysName == "temporal")
            {
                TemporalSystemParser::ParseSystemNode(child);
            }
            else if (sysName == "mind")
            {
                CustomMindSystem::ParseSystemNode(child);
            }
            else if (sysName == "clone")
            {
                CustomCloneSystem::ParseSystemNode(child);
            }
        }
    }
}
void CustomUserSystems::ParseSystemNode(rapidxml::xml_node<char>* node)
{
    //TODO: Possibly add control over ordering later.
    if (node->first_attribute("id"))
    {
        std::string sysName = node->first_attribute("id")->value();
        if (ShipSystem::NameToSystemId(sysName) != SYS_INVALID)
        {
            std::string error = "Attempted to register custom system: " + sysName + " when the name is already taken!";
            throw std::invalid_argument(error);
        }
        AddSystemName(sysName);
    }
}
std::vector<std::string> CustomUserSystems::systemNames;
std::unordered_map<std::string, int> CustomUserSystems::systemIds;
void CustomUserSystems::AddSystemName(const std::string& systemName)
{
    systemNames.emplace_back(systemName);
    //If order of nodes can change upon reload under reasonable circumstances, we may need to sort alphabetically or something so the order is well defined
    std::sort(systemNames.begin(), systemNames.end());
    //Remap IDS
    for (int idx = 0; idx < systemNames.size(); ++idx)
    {
        systemIds[systemNames[idx]] = idx + SYS_CUSTOM_FIRST;
    }    
}
int CustomUserSystems::NameToSystemId(const std::string& systemName)
{
    auto it = systemIds.find(systemName);
    if (it != systemIds.end()) return it->second;
    return SYS_INVALID;
}
std::string CustomUserSystems::SystemIdToName(int systemId)
{   
    int idx = systemId - SYS_CUSTOM_FIRST;
    if (idx >=0 && idx < systemNames.size()) return systemNames[idx];
    return "invalid system id";
}
int CustomUserSystems::GetLastSystemId()
{
    return SYS_CUSTOM_FIRST + systemNames.size() - 1;
}

int CustomUserSystems::currentExclusivityIndex = 0;
std::unordered_map<int, int> CustomUserSystems::exclusivityGroups;
void CustomUserSystems::ParseExclusivityNode(rapidxml::xml_node<char>* node)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        int systemId = ShipSystem::NameToSystemId(child->name());
        exclusivityGroups[systemId] = currentExclusivityIndex;
    }    
    ++currentExclusivityIndex;
}

bool CustomUserSystems::AreSystemsExclusive(int sysId_1, int sysId_2)
{
    if (exclusivityGroups.find(sysId_1) == exclusivityGroups.end()) return false;
    if (exclusivityGroups.find(sysId_2) == exclusivityGroups.end()) return false;

    return exclusivityGroups[sysId_1] == exclusivityGroups[sysId_2];
}

//TODO: Get addresses of arrays in native game code and implement using that, values restated here for now.
static float DAMAGE_BOOST[4] = {1.0, 1.0, 1.25, 2.0};
static float HEALTH_BOOST[4] = {0.0, 0.0, 15.0, 30.0};
static int MIND_CONTROL_COUNT[4] = {0, 1, 1, 1};
static int MIND_CONTROL_LOCK[4] = {4, 4, 4, 4};
static float MIND_CONTROL_TIMER[4] = {14.0, 14.0, 20.0, 28.0};
//Automatically initialize vector with 4 MindLevels using the game's native arrays
std::vector<CustomMindSystem::MindLevel> CustomMindSystem::levels = {
    {DAMAGE_BOOST[0], HEALTH_BOOST[0], MIND_CONTROL_TIMER[0], MIND_CONTROL_LOCK[0], MIND_CONTROL_COUNT[0]},
    {DAMAGE_BOOST[1], HEALTH_BOOST[1], MIND_CONTROL_TIMER[1], MIND_CONTROL_LOCK[1], MIND_CONTROL_COUNT[1]},
    {DAMAGE_BOOST[2], HEALTH_BOOST[2], MIND_CONTROL_TIMER[2], MIND_CONTROL_LOCK[2], MIND_CONTROL_COUNT[2]},
    {DAMAGE_BOOST[3], HEALTH_BOOST[3], MIND_CONTROL_TIMER[3], MIND_CONTROL_LOCK[3], MIND_CONTROL_COUNT[3]}
}; 
//Define default MindLevel values
CustomMindSystem::MindLevel CustomMindSystem::defaultLevel{3.f, 50.f, 30.f, 4, 1};
void CustomMindSystem::ParseSystemNode(rapidxml::xml_node<char>* node)
{
    unsigned int level = 0;
    for (auto levelNode = node->first_node(); levelNode; levelNode = levelNode->next_sibling())
    {
        //Modify vanilla levels, keeping unspecified attributes as their default values
        if (level < 4) 
        {
            CustomMindSystem::MindLevel& mindLevel = levels[level];
            if (levelNode->first_attribute("damageBoost")) mindLevel.damageBoost = boost::lexical_cast<float>(levelNode->first_attribute("damageBoost")->value());
            if (levelNode->first_attribute("healthBoost")) mindLevel.healthBoost = boost::lexical_cast<float>(levelNode->first_attribute("healthBoost")->value());
            if (levelNode->first_attribute("duration")) mindLevel.duration = boost::lexical_cast<float>(levelNode->first_attribute("duration")->value());
            if (levelNode->first_attribute("lock")) mindLevel.lock = boost::lexical_cast<int>(levelNode->first_attribute("lock")->value());
            if (levelNode->first_attribute("count")) mindLevel.count = boost::lexical_cast<int>(levelNode->first_attribute("count")->value());
        }
        else //Construct new levels, using DefaultLevel to substitute unspecified values
        {
            CustomMindSystem::MindLevel mindLevel {
                levelNode->first_attribute("damageBoost") ? boost::lexical_cast<float>(levelNode->first_attribute("damageBoost")->value()) : defaultLevel.damageBoost,
                levelNode->first_attribute("healthBoost") ? boost::lexical_cast<float>(levelNode->first_attribute("healthBoost")->value()) : defaultLevel.healthBoost,
                levelNode->first_attribute("duration") ? boost::lexical_cast<float>(levelNode->first_attribute("duration")->value()) : defaultLevel.duration,
                levelNode->first_attribute("lock") ? boost::lexical_cast<int>(levelNode->first_attribute("lock")->value()) : defaultLevel.lock,
                levelNode->first_attribute("count") ? mindLevel.count = boost::lexical_cast<int>(levelNode->first_attribute("count")->value()) : defaultLevel.count
            };
            levels.push_back(mindLevel);
        }
        level++;
    }
}

CustomMindSystem::MindLevel& CustomMindSystem::GetLevel(MindSystem* sys)
{
    bool hacked = sys->iHackEffect >= 2 && sys->bUnderAttack;
    int power = hacked ? sys->healthState.first : sys->GetEffectivePower();
    return (power > 0 && power - 1 < levels.size()) ? levels[power - 1] : defaultLevel;
}

// TODO, get the real value for those
static int JUMP_HP[4] = {8, 16, 25, 36};
static int JUMP_HP_PERCENT[4] = {0, 0, 0, 0};
static int CLONE_HP_PERCENT[4] = {100, 100, 100, 100};
static int SKILL_LOSS[4] = {10, 10, 10, 10};
static float CLONE_SPEED[4] = {12.0, 9.0, 7.0, 0.0};
static float CLONE_DEATH_SPEED[4] = {3.0, 3.0, 3.0, 3.0};
static int CLONE_AMOUNT[4] = {1, 1, 1, 1};

//Automatically initialize vector with 4 CloneLevels using the game's native arrays
std::vector<CustomCloneSystem::CloneLevel> CustomCloneSystem::levels = {
    {JUMP_HP[0], JUMP_HP_PERCENT[0], CLONE_HP_PERCENT[0], SKILL_LOSS[0], CLONE_SPEED[0], CLONE_DEATH_SPEED[0], CLONE_AMOUNT[0]},
    {JUMP_HP[1], JUMP_HP_PERCENT[1], CLONE_HP_PERCENT[1], SKILL_LOSS[1], CLONE_SPEED[1], CLONE_DEATH_SPEED[1], CLONE_AMOUNT[1]},
    {JUMP_HP[2], JUMP_HP_PERCENT[2], CLONE_HP_PERCENT[2], SKILL_LOSS[2], CLONE_SPEED[2], CLONE_DEATH_SPEED[2], CLONE_AMOUNT[2]},
    {JUMP_HP[3], JUMP_HP_PERCENT[3], CLONE_HP_PERCENT[3], SKILL_LOSS[3], CLONE_SPEED[3], CLONE_DEATH_SPEED[3], CLONE_AMOUNT[3]}
}; 
//Define default CloneLevel values
CustomCloneSystem::CloneLevel CustomCloneSystem::defaultLevel{0, 0, 100, 10, 5.f, 3.f, 1};
void CustomCloneSystem::ParseSystemNode(rapidxml::xml_node<char>* node)
{
    unsigned int level = 0;
    for (auto levelNode = node->first_node(); levelNode; levelNode = levelNode->next_sibling())
    {
        //Modify vanilla levels, keeping unspecified attributes as their default values
        if (level < 4) 
        {
            CustomCloneSystem::CloneLevel& mindLevel = levels[level];
            if (levelNode->first_attribute("jumpHP")) mindLevel.jumpHP = boost::lexical_cast<int>(levelNode->first_attribute("jumpHP")->value());
            if (levelNode->first_attribute("jumpHPPercent")) mindLevel.jumpHPPercent = boost::lexical_cast<int>(levelNode->first_attribute("jumpHPPercent")->value());
            if (levelNode->first_attribute("cloneHPPercent")) mindLevel.cloneHPPercent = boost::lexical_cast<int>(levelNode->first_attribute("cloneHPPercent")->value());
            if (levelNode->first_attribute("skillLossPercent")) mindLevel.skillLossPercent = boost::lexical_cast<int>(levelNode->first_attribute("skillLossPercent")->value());
            if (levelNode->first_attribute("cloneSpeed")) mindLevel.cloneSpeed = boost::lexical_cast<float>(levelNode->first_attribute("cloneSpeed")->value());
            if (levelNode->first_attribute("deathSpeed")) mindLevel.deathSpeed = boost::lexical_cast<float>(levelNode->first_attribute("deathSpeed")->value());
            if (levelNode->first_attribute("count")) mindLevel.count = boost::lexical_cast<int>(levelNode->first_attribute("count")->value());
        }
        else //Construct new levels, using DefaultLevel to substitute unspecified values
        {
            CustomCloneSystem::CloneLevel mindLevel {
                levelNode->first_attribute("jumpHP") ? boost::lexical_cast<int>(levelNode->first_attribute("jumpHP")->value()) : defaultLevel.jumpHP,
                levelNode->first_attribute("jumpHPPercent") ? boost::lexical_cast<int>(levelNode->first_attribute("jumpHPPercent")->value()) : defaultLevel.jumpHPPercent,
                levelNode->first_attribute("cloneHPPercent") ? boost::lexical_cast<int>(levelNode->first_attribute("cloneHPPercent")->value()) : defaultLevel.cloneHPPercent,
                levelNode->first_attribute("skillLossPercent") ? boost::lexical_cast<int>(levelNode->first_attribute("skillLossPercent")->value()) : defaultLevel.skillLossPercent,
                levelNode->first_attribute("cloneSpeed") ? boost::lexical_cast<float>(levelNode->first_attribute("cloneSpeed")->value()) : defaultLevel.cloneSpeed,
                levelNode->first_attribute("deathSpeed") ? boost::lexical_cast<float>(levelNode->first_attribute("deathSpeed")->value()) : defaultLevel.deathSpeed,
                levelNode->first_attribute("count") ? boost::lexical_cast<int>(levelNode->first_attribute("count")->value()) : defaultLevel.count
            };
            levels.push_back(mindLevel);
        }
        level++;
    }
}

CustomCloneSystem::CloneLevel& CustomCloneSystem::GetLevel(int power)
{
    return (power > 0 && power - 1 < levels.size()) ? levels[power - 1] : defaultLevel;
}

CustomCloneSystem::CloneLevel& CustomCloneSystem::GetLevel(CloneSystem* sys, bool passive)
{
    int power;
    if (passive) // Some clonebay effect do not require power
    {
        power = sys->healthState.first;
    }
    else
    {
        bool hacked = sys->iHackEffect >= 2 && sys->bUnderAttack;
        power = hacked ? sys->healthState.first : sys->GetEffectivePower();
    }
    return GetLevel(power);
}

HOOK_STATIC(ShipSystem, NameToSystemId, (std::string& name) -> int)
{
    LOG_HOOK("HOOK_STATIC -> ShipSystem::NameToSystemId -> Begin (CustomSystems.cpp)\n")
    if (name == "temporal")
    {
        return 20;
    }
    int customId = CustomUserSystems::NameToSystemId(name);
    if (customId != SYS_INVALID)
    {
        return customId;
    }
    return super(name);
}

HOOK_STATIC(ShipSystem, SystemIdToName, (int systemId) -> std::string)
{
    LOG_HOOK("HOOK_STATIC -> ShipSystem::SystemIdToName -> Begin (CustomSystems.cpp)\n")
    std::string ret = super(systemId);
    if (systemId == 20)
    {
        ret.assign("temporal");
    }
    if (systemId >= SYS_CUSTOM_FIRST)
    {
        ret.assign(CustomUserSystems::SystemIdToName(systemId));
    }

    return ret;
}



HOOK_METHOD_PRIORITY(WorldManager, ModifyResources, 1000, (LocationEvent *event) -> LocationEvent*)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WorldManager::ModifyResources -> Begin (CustomSystems.cpp)\n")

    LocationEvent *ret = super(event);

    if (event->stuff.upgradeAmount > 0)
    {
        if (event->stuff.upgradeId == 16) // upgrade everything
        {
            playerShip->shipManager->UpgradeSystem(SYS_TEMPORAL, event->stuff.upgradeAmount);
            for (int systemId = SYS_CUSTOM_FIRST; systemId <= CustomUserSystems::GetLastSystemId(); ++systemId)
            {
                playerShip->shipManager->UpgradeSystem(systemId, event->stuff.upgradeAmount);
            }
        }
        else if (event->stuff.upgradeId >= 20) // new IDs
        {
            playerShip->shipManager->UpgradeSystem(event->stuff.upgradeId, event->stuff.upgradeAmount);
        }
    }

    return ret;
}



HOOK_METHOD(ShipSystem, constructor, (int systemId, int roomId, int shipId, int startingPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::constructor -> Begin (CustomSystems.cpp)\n")
    super(systemId, roomId, shipId, startingPower);

    if (systemId == 20)
    {
        bNeedsPower = true;
        bBoostable = false;
        bNeedsManned = false;
        bLevelBoostable = false;
    }
}

HOOK_METHOD(ShipManager, CreateSystems, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CreateSystems -> Begin (CustomSystems.cpp)\n")
    if (myBlueprint.systemInfo.find(0) != myBlueprint.systemInfo.end())
    {
        auto shieldInfo = myBlueprint.systemInfo[0];


        auto sys = new Shields(shieldInfo.location[0], iShipId, 0, myBlueprint.shieldFile);
        shieldSystem = sys;
        sys->SetBaseEllipse(ship.GetBaseEllipse());
    }
    else
    {
        shieldSystem = nullptr;
    }

    systemKey.clear();
    for (int i = 0; i <= CustomUserSystems::GetLastSystemId(); i++)
    {
        systemKey.push_back(-1);
    }

    ShipBlueprint *realBp = nullptr;
    if (!revisitingShip) realBp = G_->GetBlueprints()->GetShipBlueprint(myBlueprint.blueprintName, -1);

    int ret = 0;

    if (realBp)
    {
        for (auto i : realBp->systems)
        {
            ret += AddSystem(i);
        }
    }
    else
    {
        for (auto i : myBlueprint.systems)
        {
            ret += AddSystem(i);
        }
    }
    return ret;
}

HOOK_METHOD(ShipManager, SaveToBlueprint, (bool overwrite) -> ShipBlueprint)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::SaveToBlueprint -> Begin (CustomSystems.cpp)\n")
    ShipBlueprint ret = super(overwrite);
    if (this->systemKey[SYS_ARTILLERY] != -1) // Fix for saving multiple artillery blueprint
    {
        int numArtillery = this->artillerySystems.size();
        for (auto i : ret.systems)
        {
            if (i == SYS_ARTILLERY)
            {
                numArtillery--;
            }
        }
        if (numArtillery > 0)
        {
            for (int i=0; i<numArtillery; ++i)
            {
                ret.systems.push_back(SYS_ARTILLERY);
            }
            if (overwrite)
            {
                this->myBlueprint.systems = ret.systems;
            }
        }
    }
    return ret;
}

HOOK_METHOD(SystemControl, CreateSystemBoxes, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemControl::CreateSystemBoxes -> Begin (CustomSystems.cpp)\n")
    *Global::weaponPosition = Point(0, 0);
    *Global::dronePosition = Point(0, 0);

    for (auto i : sysBoxes)
    {
        delete i;
    }

    sysBoxes.clear();

    SystemPower.x = 0;
    SystemPower.y = 0;

    int xPos = 22;

    std::vector<int> systemOrder = { 0, 1, 5, 13, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 14, 15, 20 };

    for (auto sysId : systemOrder)
    {
        auto sys = shipManager->GetSystem(sysId);
        if (!sys || !sys->bNeedsPower) continue;

        switch (sysId)
        {
        case SYS_MIND:
            {
                auto box = new MindBox(Point(xPos + 36, 269), shipManager->mindSystem);
                sysBoxes.push_back(box);
                xPos += 54;
                break;
            }
        case SYS_CLONEBAY:
            {
                auto box = new CloneBox(Point(xPos + 36, 269), shipManager->cloneSystem);
                sysBoxes.push_back(box);
                xPos += 36;
                break;
            }
        case SYS_HACKING:
            {
                auto box = new HackBox(Point(xPos + 36, 269), shipManager->hackingSystem, shipManager);
                sysBoxes.push_back(box);
                xPos += 54;
                break;
            }
        case SYS_TELEPORTER:
            {
                auto box = new TeleportBox(Point(xPos + 36, 269), shipManager->teleportSystem);
                sysBoxes.push_back(box);
                xPos += 54;
                break;
            }
        case SYS_CLOAKING:
            {
                auto box = new CloakingBox(Point(xPos + 36, 269), shipManager->cloakSystem);
                sysBoxes.push_back(box);
                xPos += 54;
                break;
            }
        case SYS_ARTILLERY:
            {
                for (auto i : shipManager->artillerySystems)
                {
                    auto box = new ArtilleryBox(Point(xPos + 36, 269), i);
                    sysBoxes.push_back(box);
                    xPos += 36;
                }

                /*
                if (shipManager->artillerySystems.size() > 0)
                {
                    auto artillerySys = shipManager->artillerySystems[0];
                    auto box = new ArtilleryBox(Point(xPos + 36, 269), artillerySys);
                    sysBoxes.push_back(box);
                    xPos += 36;
                }
                */
            }
            break;
        case SYS_WEAPONS:
            break;
        case SYS_DRONES:
            break;

        //Temporal system and fallback
        case SYS_TEMPORAL:
            {
                auto box = new TemporalBox(Point(xPos + 36, 269), sys, shipManager);
                sysBoxes.push_back(box);
                xPos += 54;
                break;
            }
        default:
            auto box = new SystemBox(Point(xPos + 36, 269), sys, true);
            sysBoxes.push_back(box);
            xPos += 36;
        }
    }
    //Custom systems
    //TODO: Allow full user control over systemBox ordering?
    for (int systemId = SYS_CUSTOM_FIRST; systemId <= CustomUserSystems::GetLastSystemId(); ++systemId)
    {
        auto sys = shipManager->GetSystem(systemId);
        if (!sys || !sys->bNeedsPower) continue;
        auto box = new SystemBox(Point(xPos + 36, 269), sys, true);
        sysBoxes.push_back(box);
        xPos += SB_EX(box)->xOffset;
    }


    if (shipManager->HasSystem(3))
    {
        *Global::weaponPosition = Point(position.x + xPos + 36, position.y + 269);
        auto box = new WeaponSystemBox(Point(xPos + 36, 269), shipManager->GetSystem(3), &combatControl->weapControl);

        sysBoxes.push_back(box);

        xPos += 48 + 97 * shipManager->myBlueprint.weaponSlots;
    }
    if (shipManager->HasSystem(4))
    {
        *Global::dronePosition = Point(position.x + xPos + 36, position.y + 269);
        auto box = new SystemBox(Point(xPos + 36, 269), shipManager->GetSystem(4), true);

        sysBoxes.push_back(box);
    }

    int subSystemOrder[4] = { 6, 7, 8, 12 };

    int subXPos = subSystemPosition.x;
    int subYPos = subSystemPosition.y;

    for (int i = 0; i < 4; i++)
    {
        int sysId = subSystemOrder[i];

        auto sys = shipManager->GetSystem(sysId);
        switch (sysId)
        {
        case SYS_DOORS:
            if (sys)
            {
                auto box = new DoorBox(Point(subXPos, subYPos), sys, shipManager);
                sysBoxes.push_back(box);
            }

            subXPos += 15;
            break;
        case SYS_BATTERY:
            if (sys)
            {
                auto box = new BatteryBox(Point(subXPos, subYPos), shipManager->batterySystem);
                sysBoxes.push_back(box);
            }
            subXPos += 18;
            break;
        default:
            if (sys)
            {
                auto box = new SystemBox(Point(subXPos, subYPos), sys, true);
                sysBoxes.push_back(box);
            }
            break;
        }
        subXPos += sub_spacing + 36;
    }
    //Custom subsystems
    //TODO: Allow full user control over systemBox ordering?
    for (int systemId = SYS_CUSTOM_FIRST; systemId <= CustomUserSystems::GetLastSystemId(); ++systemId)
    {
        auto sys = shipManager->GetSystem(systemId);
        if (!sys || sys->bNeedsPower) continue;
        auto box = new SystemBox(Point(subXPos, subYPos), sys, true);
        sysBoxes.push_back(box);
        subXPos += sub_spacing + SB_EX(box)->xOffset;
    }
}


HOOK_METHOD(ShipBuilder, CreateSystemBoxes, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::CreateSystemBoxes -> Begin (CustomSystems.cpp)\n")
    for (auto i : sysBoxes)
    {
        delete i;
    }

    sysBoxes.clear();

    int xPos = 360;

    std::vector<int> systemIds = { 0, 1, 2, 3, 4, 5, 9, 10, 11, 13, 14, 15, 20, 6, 7, 8, 12 };
    //TODO: Check if user needs to control offsets in ShipBuilder menu too. Might be necessary if they want to do something weird with the UI
    for (auto i : systemIds)
    {
        if (i == SYS_ARTILLERY)
        {
            for (auto sys : currentShip->artillerySystems)
            {
                auto box = new SystemCustomBox(Point(xPos, 425), sys, currentShip);

                sysBoxes.push_back(box);

                box->bShowPower = true;
                box->bSimplePower = true;

                xPos += 38;
            }
        }
        else
        {
            if (currentShip->HasSystem(i))
            {
                auto sys = currentShip->GetSystem(i);
                auto box = new SystemCustomBox(Point(xPos, 425), sys, currentShip);

                sysBoxes.push_back(box);

                box->bShowPower = true;
                box->bSimplePower = true;

                xPos += 38;
            }
        }
    }
    //Custom system boxes
    for (int systemId = SYS_CUSTOM_FIRST; systemId <= CustomUserSystems::GetLastSystemId(); ++systemId)
    {
        if (currentShip->HasSystem(systemId))
        {
            auto sys = currentShip->GetSystem(systemId);
            auto box = new SystemCustomBox(Point(xPos, 425), sys, currentShip);

            sysBoxes.push_back(box);

            box->bShowPower = true;
            box->bSimplePower = true;

            xPos += 38;
        }
    }
}


void ShipSystem::CompleteSave(int fd)
{
    FileHelper::writeInt(fd, powerState.second);
    FileHelper::writeInt(fd, powerState.first);
    FileHelper::writeInt(fd, healthState.second - healthState.first);

    FileHelper::writeInt(fd, iLockCount);
    FileHelper::writeInt(fd, std::floor(lockTimer.currTime * 5000));
    FileHelper::writeInt(fd, std::floor(fRepairOverTime));
    FileHelper::writeInt(fd, std::floor(fDamageOverTime));
    FileHelper::writeInt(fd, iBatteryPower);
    FileHelper::writeInt(fd, bUnderAttack ? iHackEffect : 0);
    FileHelper::writeInt(fd, iHackEffect > 0 ? bUnderAttack : 0);
    SaveState(fd);
};

void ShipSystem::CompleteLoad(int fd)
{
    bool canDecrease = DecreasePower(false);
    while (canDecrease)
    {
        canDecrease = DecreasePower(false);
    }

    int maxPower = FileHelper::readInteger(fd);
    while (powerState.second < maxPower)
    {
        UpgradeSystem(1);
    }

    SetBonusPower(0, 0);

    int setPower = FileHelper::readInteger(fd);

    while (powerState.first != setPower)
    {
        if (!IncreasePower(1, true)) break;
    }

    AddDamage(FileHelper::readInteger(fd));
    AddLock(FileHelper::readInteger(fd));
    lockTimer.currTime = ((float)FileHelper::readInteger(fd)) / 5000.f;

    repairedLastFrame = true;
    fRepairOverTime = FileHelper::readInteger(fd);

    damagedLastFrame = true;
    fDamageOverTime = FileHelper::readInteger(fd);

    ForceBatteryPower(FileHelper::readInteger(fd));
    SetHackingLevel(FileHelper::readInteger(fd));
    bUnderAttack = FileHelper::readInteger(fd);

    LoadState(fd);
}

//Custom System Saving
HOOK_METHOD(ShipManager, ExportShip, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ExportShip -> Begin (CustomSystems.cpp)\n")
    super(file);

    for (int systemId = SYS_CUSTOM_FIRST; systemId <= CustomUserSystems::GetLastSystemId(); ++systemId)
    {
        FileHelper::writeInt(file, HasSystem(systemId));
        if (HasSystem(systemId))
        {
            ShipSystem* sys = GetSystem(systemId);
            sys->CompleteSave(file);
        }
    } 
}

HOOK_METHOD(ShipManager, ImportShip, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ImportShip -> Begin (CustomSystems.cpp)\n")
    super(file);

    for (int systemId = SYS_CUSTOM_FIRST; systemId <= CustomUserSystems::GetLastSystemId(); ++systemId)
    {
        
        bool hasSystem = FileHelper::readInteger(file);
        if (hasSystem)
        {
            if (!HasSystem(systemId)) AddSystem(systemId);
            ShipSystem* sys = GetSystem(systemId);
            sys->CompleteLoad(file);
        }
    }
}


HOOK_METHOD(CombatControl, KeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::KeyDown -> Begin (CustomSystems.cpp)\n")
    bool isWeaponKey = weapControl.KeyDown(key);
    if (isWeaponKey || droneControl.KeyDown(key))
    {
        if (shipManager->HasSystem(SYS_MIND))
        {
            shipManager->mindSystem->SetArmed(0);
        }
        if (shipManager->HasSystem(SYS_HACKING))
        {
            shipManager->hackingSystem->bArmed = false;
        }
        if (shipManager->HasSystem(SYS_TEMPORAL))
        {
            auto temporalSys = SYS_EX(shipManager->GetSystem(SYS_TEMPORAL))->temporalSystem;

            temporalSys->SetArmed(TemporalArmState::TEMPORAL_ARM_NONE);
        }

        shipManager->ship.SetSelectedRoom(-1);
        if (currentTarget)
        {
            currentTarget->shipManager->ship.SetSelectedRoom(-1);
        }
    }
    if (isWeaponKey)
    {
        aimingPoints.clear();
    }
}

HOOK_METHOD(ShipManager, CanFitSystem, (int systemId) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CanFitSystem -> Begin (CustomSystems.cpp)\n")
    //Mutually exclusive systems
    if (SystemWillReplace(systemId) != SYS_INVALID) return true;

    int count = 0;

    for (auto i : vSystemList)
    {
        if (i->bNeedsPower)
        {
            count++;
        }
    }

    auto custom = CustomShipSelect::GetInstance();
    int sysLimit = custom->GetDefinition(myBlueprint.blueprintName).systemLimit;

    return count < sysLimit;
}

HOOK_METHOD(ShipManager, CanFitSubsystem, (int systemId) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CanFitSubsystem -> Begin (CustomSystems.cpp)\n")

    //Mutually exclusive custom systems
    if (SystemWillReplace(systemId) != SYS_INVALID) return true;

    int count = 0;

    for (auto i : vSystemList)
    {
        if (!i->bNeedsPower)
        {
            count++;
        }
    }

    auto custom = CustomShipSelect::GetInstance();
    int sysLimit = custom->GetDefinition(myBlueprint.blueprintName).subsystemLimit;

    return count < sysLimit;
}

HOOK_METHOD(ShipManager, AddSystem, (int systemId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::AddSystem -> Begin (CustomSystems.cpp)\n")
    
    int removedSystemPower = 0;
    int replacedSystem = SystemWillReplace(systemId);
    if (replacedSystem != SYS_INVALID)
    {
        removedSystemPower = GetSystemPowerMax(replacedSystem);
        RemoveSystem(replacedSystem);
    }

    //Save medical system and remove so original AddSystem doesn't remove it
    ShipSystem* savedMedical = nullptr;
    bool restoreClonebay = false;
    bool restoreMedbay = false;
    if ((systemId == SYS_MEDBAY || systemId == SYS_CLONEBAY) && CustomOptionsManager::GetInstance()->duelMedical.currentValue)
    {
        if (systemId == SYS_MEDBAY && HasSystem(SYS_CLONEBAY))
        {
            savedMedical = cloneSystem;
            cloneSystem = nullptr;

            vSystemList.erase(vSystemList.begin() + systemKey[SYS_CLONEBAY]);
            systemKey[SYS_CLONEBAY] = -1;

            restoreClonebay = true;
        }
        else if (systemId == SYS_CLONEBAY && HasSystem(SYS_MEDBAY))
        {
            savedMedical = medbaySystem;
            medbaySystem = nullptr;

            vSystemList.erase(vSystemList.begin() + systemKey[SYS_MEDBAY]);
            systemKey[SYS_MEDBAY] = -1;

            restoreMedbay = true;
        }

        for (int idx = 0; idx < vSystemList.size(); ++idx)
        {
            ShipSystem* sys = vSystemList[idx];
            systemKey[sys->iSystemType] = idx;
        }     
    }

    int ret = super(systemId);

    //Add medical system back
    if (restoreMedbay)
    {
        medbaySystem = static_cast<MedbaySystem*>(savedMedical);
        vSystemList.push_back(savedMedical);
        systemKey[SYS_MEDBAY] = vSystemList.size() - 1;
    }
    else if (restoreClonebay)
    {
        cloneSystem = static_cast<CloneSystem*>(savedMedical);
        vSystemList.push_back(savedMedical);
        systemKey[SYS_CLONEBAY] = vSystemList.size() - 1;
    }


    while (GetSystemPowerMax(systemId) < removedSystemPower)
    {
        UpgradeSystem(systemId, 1);
    }
    
    return ret;
}

HOOK_METHOD(ShipManager, GetSystemPowerMax, (int systemId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetSystemPowerMax -> Begin (CustomSystems.cpp)\n")
    if (systemId == SYS_INVALID) return 0;
    return super(systemId);
}

/*
HOOK_METHOD(ShipManager, RenderChargeBars, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::RenderChargeBars -> Begin (CustomSystems.cpp)\n")

}
*/

/*
HOOK_METHOD(ShipSystem, SetPowerLoss, (int powerLoss) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::SetPowerLoss -> Begin (CustomSystems.cpp)\n")
    auto ex = SYS_EX(this);
    iTempPowerLoss = powerLoss + ex->additionalPowerLoss;

    int maxPower = powerState.second;
    int oldMaxHealth = healthState.second;

    if (healthState.first <= healthState.second)
    {
        oldMaxHealth = healthState.first;
    }

    if (oldMaxHealth < 0)
    {
        oldMaxHealth = 0;
    }

    int currentHealth = healthState.second;
    healthState.first = oldMaxHealth;
    int newBonusPower = maxPower - (currentHealth - oldMaxHealth) - powerLoss;

    int powerCap = 0;
    if (iTempPowerCap <= 7)
    {
        if (iTempPowerCap >= 0)
        {
            powerCap = iTempPowerCap;
        }
    }
    else
    {
        if (maxPower >= 0)
        {
            powerCap = maxPower;
        }
    }

    if (iBonusPower <= newBonusPower)
    {
        newBonusPower = iBonusPower;
    }
    if (newBonusPower > powerCap)
    {
        newBonusPower = powerCap;
    }
    iBonusPower = newBonusPower;

    CheckMaxPower();

    if (iSystemType - 3 > 1)
    {
        return CheckForRepower();
    }

    return iSystemType - 3;
}
*/

/*
HOOK_STATIC(ShipSystem, GetLevelDescription, (int systemId, int level, bool tooltip) -> std::string)
{
    LOG_HOOK("HOOK_STATIC -> ShipSystem::GetLevelDescription -> Begin (CustomSystems.cpp)\n")
    std::string ret = super(systemId, level, tooltip);

    std::string name = SystemIdToName(systemId);
    auto tLib = G_->GetTextLibrary();
    if (tooltip)
    {
        bool hacked = false; // figure out method
        if (hacked)
        {
            name += "_tooltip_hacked";
        }
        else
        {
            name += "_" + std::to_string(level) + "_tooltip";
        }
        ret.assign(tLib->GetText(name));
    }
    else
    {
        name += "_" + std::to_string(level);
        ret.assign(tLib->GetText(name));
    }
    return ret;
}
*/

HOOK_METHOD(ShipSystem, GetEffectivePower, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::GetEffectivePower -> Begin (CustomSystems.cpp)\n")
    int boostPower = 0;

    if (iActiveManned > 0 && bBoostable && healthState.first == healthState.second)
    {
        boostPower = bLevelBoostable;
    }

    return boostPower + iBatteryPower + powerState.first + iBonusPower;
}

HOOK_METHOD(PowerManager, SetHacked, (bool activated) -> void)
{
    LOG_HOOK("HOOK_METHOD -> PowerManager::SetHacked -> Begin (CustomSystems.cpp)\n")

    iHacked = activated ? std::min(currentPower.second, 2) : 0;
}

static bool initRenderPowerBoxes = false;

static GL_Color COLOR_TRUE_WHITE = {1.f, 1.f, 1.f, 1.f};
static GL_Color COLOR_GREEN = {100.f/255.f, 255.f/255.f, 100.f/255.f, 1.f};
static GL_Color COLOR_CB_WHITE = {243.f/255.f, 255.f/255.f, 238.f/255.f, 1.f};
static GL_Color COLOR_BLUE_ION = {133.f/255.f, 231.f/255.f, 237.f/255.f, 1.f};
static GL_Color COLOR_PURPLE_HACKING = {207.f/255.f, 70.f/255.f, 253.f/255.f, 1.f};
static GL_Color COLOR_BLUE_ION_OUTLINE = {40.f/255.f, 210.f/255.f, 230.f/255.f, 1.f};
static GL_Color COLOR_RED = {255.f/255.f, 50.f/255.f, 50.f/255.f, 1.f};
static GL_Color COLOR_CB_RED = {227.f/255.f, 65.f/255.f, 63.f/255.f, 1.f};
static GL_Color COLOR_BATTERY_OUTLINE = {230.f/255.f, 110.f/255.f, 30.f/255.f, 1.f};
static GL_Color COLOR_YELLOW_BONUSPOWER = {255.f/255.f, 250.f/255.f, 90.f/255.f, 1.f};
static GL_Color COLOR_REPAIR = {255.f/255.f, 255.f/255.f, 50.f/255.f, 1.f};

static GL_Primitive *ErosionTimerPrimitive;
static std::array<GL_Primitive*,10> ErosionIconPrimitive;
static GL_Primitive *ErosionTimerStencil = nullptr;
int lastErosionTimerStencilCount = -1;

HOOK_METHOD(ShipSystem, constructor, (int systemId, int roomId, int shipId, int startingPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::constructor -> Begin (CustomSystems.cpp)\n")

    if (!initRenderPowerBoxes)
    {
        ErosionTimerPrimitive = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/ring_timer.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[0] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_1.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[1] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_2.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[2] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_3.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[3] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_4.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[4] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_5.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[5] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_6.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[6] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_7.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[7] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_8.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[8] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_9.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);
        ErosionIconPrimitive[9] = G_->GetResources()->CreateImagePrimitiveString("icons/erosion/base_9p.png",16,-30,0,COLOR_TRUE_WHITE,1.f,false);

        initRenderPowerBoxes = true;
    }

    super(systemId, roomId, shipId, startingPower);
}

HOOK_METHOD_PRIORITY(ShipSystem, RenderPowerBoxes, 9999, (int x, int y, int width, int height, int gap, int heightMod, bool flash) -> int)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipSystem::RenderPowerBoxes -> Begin (CustomSystems.cpp)\n")

    //return super(x, y, width, height, gap, heightMod, flash);

    SystemControl::PowerBars *powerBars = SystemControl::GetPowerBars(width, height, gap, iSystemType == 0);

    float repairFraction = fRepairOverTime / 100.f;
    float damageFraction = fDamageOverTime / 100.f;

    float x_00 = x + (64 - width) / 2;
    float y_00 = y + 10 - gap;
    float y_01 = y_00;

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(x_00, y_00, 0.f);

    float spacing = height + gap;

    int healthPower = powerState.second + healthState.first - healthState.second;
    int maxPower = GetMaxPower();

    float erosionHealth = 1.0e30;
    int erosionTimer1 = 0;
    int erosionTimer2 = 0;

    if (roomId > -1)
    {
        ShipManager *shipManager = G_->GetShipManager(_shipObj.iShipId);
        if (shipManager && roomId < shipManager->ship.vRoomList.size())
        {
            Room *room = shipManager->ship.vRoomList[roomId];
            Room_Extend *room_ex = RM_EX(room);
            if (room_ex->erosion.timer > 0.f)
            {
                erosionHealth = healthPower + repairFraction - damageFraction - (room_ex->erosion.timer * room_ex->erosion.speed * 0.16f);

                float fErosionTimer = room_ex->erosion.timer/5.f;
                float fErosionTimer1 = ceil(fErosionTimer);
                erosionTimer1 = fErosionTimer1;
                erosionTimer2 = ceil((fErosionTimer-fErosionTimer1)*12.f)+12;
            }
        }
    }

    if (selectedState != 0 && iHackEffect < 2)
    {
        CSurface::GL_PushMatrix();
        for (int i=0; i<powerState.second; ++i)
        {
            if (i >= healthPower)
            {
                CSurface::GL_RenderPrimitive(*ShipSystem__glowRed);
            }
            else if (i >= maxPower)
            {
                CSurface::GL_RenderPrimitive(*ShipSystem__glowBlue);
            }
            else
            {
                CSurface::GL_RenderPrimitive(*ShipSystem__glowWhite);
                CSurface::GL_RenderPrimitive(*ShipSystem__glowWhite);
            }
            if (iSystemType == 0 && i+1<powerState.second && (i&1) != 0) // shields power bar gap
            {
                CSurface::GL_Translate(0.f, -gap*2, 0.f);
            }
            CSurface::GL_Translate(0.f, -spacing, 0.f);
        }
        CSurface::GL_PopMatrix();
    }

    for (int i=0; i<powerState.second; ++i)
    {
        if (flash) // flashing
        {
            CSurface::GL_RenderPrimitive(powerBars->normal[i]);
        }
        else if (i < powerState.first) // powered
        {
            GL_Color powerColor = COLOR_GREEN;
            if (G_->GetSettings()->colorblind) powerColor = COLOR_CB_WHITE;
            if (iHackEffect > 1)
            {
                powerColor = COLOR_PURPLE_HACKING;
            }
            else if (iLockCount == -1)
            {
                powerColor = COLOR_TRUE_WHITE;
            }
            else if (iLockCount > 0)
            {
                powerColor = COLOR_BLUE_ION;
            }
            CSurface::GL_RenderPrimitiveWithColor(powerBars->normal[i], powerColor);
        }
        else if (i < powerState.first + iBatteryPower)
        {
            GL_Color powerColor = COLOR_GREEN;
            if (G_->GetSettings()->colorblind) powerColor = COLOR_CB_WHITE;
            CSurface::GL_RenderPrimitiveWithColor(powerBars->tiny[i], powerColor);
            CSurface::GL_RenderPrimitiveWithColor(powerBars->empty[i], COLOR_BATTERY_OUTLINE);
        }
        else if (i < powerState.first + iBatteryPower + iBonusPower)
        {
            CSurface::GL_RenderPrimitiveWithColor(powerBars->normal[i], COLOR_YELLOW_BONUSPOWER);
        }
        else if (i >= healthPower)
        {
            GL_Color powerColor = COLOR_RED;
            if (G_->GetSettings()->colorblind) powerColor = COLOR_CB_RED;
            CSurface::GL_RenderPrimitiveWithColor(powerBars->damaged[i], powerColor);
            if (repairFraction > 0.f && i == healthPower)
            {
                CSurface::GL_DrawRect(width * (1.f-repairFraction), y_01-y_00, width * repairFraction, height, COLOR_REPAIR);
                if (erosionHealth < i+1)
                {
                    float erosionFraction = std::min(1.f, i+1-erosionHealth);
                    CSurface::GL_DrawRect(width * (1.f-repairFraction), y_01-y_00+height-2, width * (repairFraction - 1.f + erosionFraction), 2, COLOR_RED);
                }
            }
        }
        else if (i >= maxPower)
        {
            CSurface::GL_RenderPrimitiveWithColor(powerBars->damaged[i], COLOR_BLUE_ION_OUTLINE);
        }
        else
        {
            CSurface::GL_RenderPrimitive(powerBars->empty[i]);
        }

        if (i < healthPower)
        {
            if (erosionHealth < i+1)
            {
                float erosionFraction = std::min(1.f, i+1-erosionHealth);
                CSurface::GL_DrawRect(0, y_01-y_00+height-2, width * erosionFraction, 2, COLOR_RED);
            }
            if (damageFraction > 0.f && i == healthPower-1)
            {
                Globals::Rect newDamageRect;
                newDamageRect.x = 0;
                newDamageRect.y = y_01 - y_00;
                newDamageRect.w = width * damageFraction;
                newDamageRect.h = height;
                if (newDamageRect.x != partialDamageRect.x || newDamageRect.y != partialDamageRect.y || newDamageRect.w != partialDamageRect.w || newDamageRect.h != partialDamageRect.h)
                {
                    CSurface::GL_DestroyPrimitive(partialDamageRect.primitive);
                    partialDamageRect.primitive = nullptr;
                    partialDamageRect.x = newDamageRect.x;
                    partialDamageRect.y = newDamageRect.y;
                    partialDamageRect.w = newDamageRect.w;
                    partialDamageRect.h = newDamageRect.h;
                }
                partialDamageRect.OnRender(COLOR_RED);
            }
        }

        if (iSystemType == 0 && i+1<powerState.second && (i&1) != 0) // shields power bar gap
        {
            y_01 -= gap*2;
        }
        y_01 -= spacing;
    }

    y_01 += spacing;
    y_00 += height;

    CSurface::GL_Translate(0.f, height, 0.f);
    CSurface::GL_Translate(x-x_00, y_01-y_00, 0.f);

    if (bBoostable && !BlockedBoosted(!bLevelBoostable)) // can be manned
    {
        GL_Primitive *manningPrimitive;
        if (bLevelBoostable) // subsystems that can be boosted
        {
            if (iActiveManned >= 1 && bBoostable && healthState.first == healthState.second)
            {
                manningPrimitive = *ShipSystem__manningBarOn;
            }
            else if (BlockedBoosted(true))
            {
                manningPrimitive = *ShipSystem__manningBarIon;
            }
            else
            {
                manningPrimitive = *ShipSystem__manningBarOff;
            }
            CSurface::GL_RenderPrimitive(manningPrimitive);
        }
        else
        {
            if (iActiveManned < 1 || !bBoostable || healthState.first != healthState.second)
            {
                spacing = 16;
                manningPrimitive = *ShipSystem__manningOutline;
            }
            else if (iActiveManned == 1)
            {
                spacing = 16;
                manningPrimitive = *ShipSystem__manningWhite;
            }
            else if (iActiveManned == 2)
            {
                spacing = 24;
                manningPrimitive = *ShipSystem__manningGreen;
            }
            else if (iActiveManned == 3)
            {
                spacing = 24;
                manningPrimitive = *ShipSystem__manningYellow;
            }
            CSurface::GL_RenderPrimitive(manningPrimitive);
        }
        y_01 -= spacing;
        CSurface::GL_Translate(0.f, -spacing, 0.f);
    }

    if (heightMod > 0)
    {
        y_01 -= heightMod;
        CSurface::GL_Translate(0.f, -heightMod, 0.f);
    }

    GL_Primitive *lockPrimitive = nullptr;
    GL_Color lockColor;
    if (iHackEffect >= 2 && bUnderAttack)
    {
        lockPrimitive = *ShipSystem__lockHack;
        lockColor = COLOR_PURPLE_HACKING;
    }
    else if (iLockCount == -1)
    {
        lockPrimitive = *ShipSystem__lockWhite;
        lockColor = COLOR_TRUE_WHITE;
    }
    else if (iLockCount > 0)
    {
        lockPrimitive = *ShipSystem__lockBlue;
        lockColor = COLOR_BLUE_ION;
    }
    else if (iHackEffect >= 2)
    {
        lockPrimitive = *ShipSystem__lockBlue;
        lockColor = COLOR_BLUE_ION;
    }

    if (lockPrimitive)
    {
        float ionBoxGap = ((int)(gap/2))+2;

        Globals::Rect newOutline = {int((x_00-ionBoxGap)-x), int(heightMod - ionBoxGap), int(width + 2*ionBoxGap), int((y_00 + ionBoxGap) - (heightMod - ionBoxGap + y_01))};
        if (newOutline.x != lockOutline.x || newOutline.y != lockOutline.y || newOutline.w != lockOutline.w || newOutline.h != lockOutline.h)
        {
            CSurface::GL_DestroyPrimitive(lockOutline.primitive);
            lockOutline.primitive = nullptr;
            lockOutline.x = newOutline.x;
            lockOutline.y = newOutline.y;
            lockOutline.w = newOutline.w;
            lockOutline.h = newOutline.h;
            lockOutline.thickness = 2;
        }

        lockOutline.OnRender(lockColor);
        CSurface::GL_Translate(0.f, -ionBoxGap, 0.f);
        y_01 -= ionBoxGap;

        if (lockPrimitive != *ShipSystem__lockHack)
        {
            CSurface::GL_RenderPrimitive(lockPrimitive);
            CSurface::GL_Translate(0.f, -21.f, 0.f);
            y_01 -= 21.f;
        }
    }

    if (bUnderAttack && iHackEffect > 0)
    {
        CSurface::GL_RenderPrimitive(*ShipSystem__lockHack);
        CSurface::GL_Translate(0.f, -22.f, 0.f);
        y_01 -= 22.f;
    }

    if (erosionTimer1 > 0)
    {
        CSurface::GL_RenderPrimitive(ErosionIconPrimitive[std::min(erosionTimer1-1,9)]);

        if (erosionTimer2 != lastErosionTimerStencilCount)
        {
            lastErosionTimerStencilCount = erosionTimer2;
            CSurface::GL_DestroyPrimitive(ErosionTimerStencil);
            ErosionTimerStencil = CSurface::GL_CreatePiePartialPrimitive(32, -14, 17.f, -85.f, erosionTimer2*30-85, 17.f, COLOR_TRUE_WHITE);
        }

        CSurface::GL_SetStencilMode(STENCIL_SET,1,1);
        CSurface::GL_RenderPrimitive(ErosionTimerStencil);
        CSurface::GL_SetStencilMode(STENCIL_USE,1,1);
        CSurface::GL_RenderPrimitive(ErosionTimerPrimitive);
        CSurface::GL_SetStencilMode(STENCIL_IGNORE,0,0);

        CSurface::GL_Translate(0.f, -28.f, 0.f);
        y_01 -= 28.f;
    }

    if (bOccupied && fDamageOverTime != 0.f && !CompletelyDestroyed())
    {
        CSurface::GL_RenderPrimitive(*ShipSystem__sabotageImage);
        CSurface::GL_Translate(0.f, -24.f, 0.f);
        y_01 -= 24.f;
    }

    if (bOnFire)
    {
        CSurface::GL_RenderPrimitive(*ShipSystem__fireImage);
        CSurface::GL_Translate(0.f, -22.f, 0.f);
        y_01 -= 22.f;
    }

    CSurface::GL_PopMatrix();

    return y_01 - 20.f;
}

//Custom mind control rewrites

HOOK_METHOD(MindSystem, ReleaseCrew, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MindSystem::ReleaseCrew -> Begin (CustomSystems.cpp)\n")
    for (CrewMember* crew : controlledCrew)
    {
        crew->SetMindControl(false);
        G_->GetSoundControl()->PlaySoundMix("mindControlEnd", -1.0, false);
    }
    controlledCrew.clear();
    CustomMindSystem::MindLevel& level = CustomMindSystem::GetLevel(this);
    LockSystem(level.lock);
    controlTimer.first = controlTimer.second;
}

HOOK_METHOD(MindSystem, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MindSystem::OnLoop -> Begin (CustomSystems.cpp)\n")
    this->ShipSystem::OnLoop();
    if (!queuedCrew.empty())
    {
        InitiateMindControl();
    }
    float oldFirst = controlTimer.first;
    if (controlTimer.first < controlTimer.second)
    {
        controlTimer.first += G_->GetCFPS()->GetSpeedFactor() * 0.0625f;
    }
    if (oldFirst != controlTimer.second && controlTimer.second <= controlTimer.first)
    {
        ReleaseCrew();
    }
    CustomMindSystem::MindLevel& level = CustomMindSystem::GetLevel(this);
    while (level.count < controlledCrew.size())
    {
        controlledCrew.back()->SetMindControl(false);
        controlledCrew.pop_back();
        G_->GetSoundControl()->PlaySoundMix("mindControlEnd", -1.0, false);
    }
    if (GetEffectivePower() == 0 && !controlledCrew.empty())
    {
        while (!controlledCrew.empty())
        {
            controlledCrew.back()->SetMindControl(false);
            controlledCrew.pop_back();
        }
        G_->GetSoundControl()->PlaySoundMix("mindControlEnd", -1.0, false);
    }
    controlledCrew.erase(std::remove_if(controlledCrew.begin(),
                                        controlledCrew.end(),
                                        [](CrewMember* crew) { 
                                            return crew->OutOfGame() || 
                                            crew->IsDead() || 
                                            crew->crewAnim->status == 3 || 
                                            !crew->bMindControlled; }),
                                        controlledCrew.end());
                                        
    for (CrewMember* crew : controlledCrew)
    {
        crew->SetHealthBoost(level.healthBoost);
        crew->SetDamageBoost(level.damageBoost);
    }
    if (controlledCrew.empty() && controlTimer.first != controlTimer.second) ReleaseCrew();
    if (level.duration != controlTimer.second)
    {
        if (controlTimer.first == controlTimer.second)
        {
            controlTimer.first = level.duration;
        }
        controlTimer.second = level.duration;
    }
}

HOOK_METHOD(MindSystem, InitiateMindControl, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MindSystem::InitiateMindControl -> Begin (CustomSystems.cpp)\n")

    iQueuedTarget = -1;
    iQueuedShip = -1;

    for (CrewMember* crew : queuedCrew)
    {
        if (crew->IsTelepathic()) crew->SetResisted(true); //Set resisted crew
    }
    //Remove crew that are not valid targets
    bool hacked = iHackEffect >= 2 && bUnderAttack;
    int allyId = hacked ? 1 - _shipObj.iShipId : _shipObj.iShipId;
    queuedCrew.erase(std::remove_if(queuedCrew.begin(),
                                    queuedCrew.end(),
                                    [&](CrewMember* crew) { 
                                        return crew->OutOfGame() || //Out of game
                                        crew->IsDead() || //Dead
                                        crew->crewAnim->status == 3 || //Dying
                                        ((crew->iShipId == allyId) ^ crew->bMindControlled) || //Non-controlled allied crew and controlled enemy crew
                                        crew->IsTelepathic() || //Immune
                                        crew->IsDrone() || //Drone
                                        (crew->iShipId == 1 && _shipObj.iShipId == 1 && crew->bMindControlled) || //enemies can't use MC to uncontrol their crew
                                        (bSuperShields && crew->currentShipId != _shipObj.iShipId && _shipObj.HasEquipment("ZOLTAN_BYPASS") <= 0); }), //targetting other ship, with supershields and no bypass
                                    queuedCrew.end());

    CustomMindSystem::MindLevel& level = CustomMindSystem::GetLevel(this);
    unsigned int count = 0;
    while (count < level.count && !queuedCrew.empty() && GetEffectivePower() > 0)
    {
        unsigned int index = random32() % queuedCrew.size();
        CrewMember* crew = queuedCrew[index];
        queuedCrew.erase(queuedCrew.begin() + index);
        if (crew->bMindControlled)
        {
            crew->SetMindControl(false);
            G_->GetSoundControl()->PlaySoundMix("mindControlEnd", -1.f, false);
        }
        else
        {
            crew->SetMindControl(true);
            G_->GetSoundControl()->PlaySoundMix("mindControl", -1.f, false);
            controlledCrew.push_back(crew);
        }
        count++;
    }
    if (!controlledCrew.empty()) //If controlling enemy crew, activate duration
    {
        controlTimer.first = 0;
        LockSystem(-1);
    }
    else if (count > 0) //If only freeing allied crew, start cooldown
    {
        controlTimer.first = controlTimer.second;
        LockSystem(level.lock);
    }
    else //No activation
    {
        controlTimer.first = controlTimer.second;
    }
    queuedCrew.clear();
}

// Custom clonebay rewrites

bool g_jumpClone = false;
int g_checkCloneSpeed = 2;
int g_clonePercentTooltipLevel = 0;
CloneSystem* g_cloneSystem = nullptr;
std::vector<float> vanillaCloneTime = {12.0, 9.0, 7.0};

HOOK_METHOD(ShipManager, CloneHealing, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CloneHealing -> Begin (CustomSystems.cpp)\n")
    
    g_jumpClone = true;
    super();      
    g_jumpClone = false;
}

HOOK_METHOD(CrewMember, DirectModifyHealth, (float heal) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::DirectModifyHealth -> Begin (CustomSystems.cpp)\n")
    
    if (g_jumpClone)
    {
        CloneSystem* sys = G_->GetShipManager(iShipId)->cloneSystem;
        if (sys != nullptr)
        {
            CustomCloneSystem::CloneLevel& pLevel = CustomCloneSystem::GetLevel(sys->healthState.first);
            heal = 0;
            if (pLevel.jumpHPPercent > 0)
            {
                heal += (float)pLevel.jumpHPPercent/100 * health.second;
            }
            if (pLevel.jumpHP > 0)
            {
                heal += pLevel.jumpHP;
            }
            if (heal > health.second) heal = health.second;
        }
    }
    
    return super(heal);
}

HOOK_METHOD(CrewMember, Clone, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::Clone -> Begin (CustomSystems.cpp)\n")

    std::vector<int> saveSkills;
    for (int i = 0; i < 6; i++) saveSkills.push_back(blueprint.skillLevel[i].first);

    super();

    CloneSystem* sys = G_->GetShipManager(iShipId)->cloneSystem;
    if (sys != nullptr)
    {
        
        CustomCloneSystem::CloneLevel& pLevel = CustomCloneSystem::GetLevel(sys, true);
        CustomCloneSystem::CloneLevel& level = CustomCloneSystem::GetLevel(sys, false);

        if (level.cloneHPPercent > 0)
        {
            health.first = (float)level.cloneHPPercent/100.0 * health.second;
            if (health.first < 1) health.first = 1; // Small safety for our beloved crew
        }

        if (pLevel.skillLossPercent > 0)
        {
            for (int i = 0; i < 6; i++)
            {
                int newSkillProgress = std::ceil(saveSkills[i] - (blueprint.skillLevel[i].second * (float)pLevel.skillLossPercent/100.0));
                if (pLevel.skillLossPercent > 0 && newSkillProgress == saveSkills[i]) newSkillProgress--;
                if (newSkillProgress < 0) newSkillProgress = 0;
                SetSkillProgress(i, newSkillProgress);
            }
        }
    }
    saveSkills.clear();
}

HOOK_METHOD(CloneSystem, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CloneSystem::OnLoop -> Begin (CustomSystems.cpp)\n")

    g_checkCloneSpeed = iLockCount > 0 ? -1 : 0;
    g_cloneSystem = this;
    super();
    g_checkCloneSpeed = 2;
}

HOOK_METHOD(CFPS, GetSpeedFactor, () -> float)
{
    LOG_HOOK("HOOK_METHOD -> CFPS::GetSpeedFactor -> Begin (CustomSystems.cpp)\n")
    float speedFactor = super();

    if (g_checkCloneSpeed < 2 && g_cloneSystem != nullptr)
    {
        CustomCloneSystem::CloneLevel& level = CustomCloneSystem::GetLevel(g_cloneSystem, false);
        CustomCloneSystem::CloneLevel& pLevel = CustomCloneSystem::GetLevel(g_cloneSystem, true);

        float cloneTimeMultiplier = 999.f;
        if (level.cloneSpeed > 0) cloneTimeMultiplier = (g_cloneSystem->GetEffectivePower() - 1) < vanillaCloneTime.size() ? (float)vanillaCloneTime[g_cloneSystem->GetEffectivePower() - 1] / (float)level.cloneSpeed : 1.f;

        #ifdef WIN32 // OnLoop GetSpeedFactor order is inverted between windows and linux
        if (g_checkCloneSpeed == 0 && g_cloneSystem->GetEffectivePower() > 0) // For the cloning progress
        {
            speedFactor = speedFactor * cloneTimeMultiplier;
        }
        else if (g_checkCloneSpeed == 1) // For the clone death
        {
            speedFactor = speedFactor * 3.0 / pLevel.deathSpeed;
        }
        #else
        if (g_checkCloneSpeed == 1 && g_cloneSystem->GetEffectivePower() > 0) // For the cloning progress
        {
            speedFactor = speedFactor * cloneTimeMultiplier;
        }
        else if (g_checkCloneSpeed == 1) // For the clone death
        {
            speedFactor = speedFactor * 3.0 / pLevel.deathSpeed;
        }
        #endif

        g_checkCloneSpeed++;
    }   

    return speedFactor;
}

// For tooltips
HOOK_STATIC(ShipSystem, GetLevelDescription, (int systemId,int level,bool tooltip) -> std::string)
{
    LOG_HOOK("HOOK_STATIC -> ShipSystem::GetLevelDescription -> Begin (CustomSystems.cpp)\n")
    
    g_clonePercentTooltipLevel = level + 1;
    std::string ret = super(systemId, level, tooltip);
    return ret;
}

HOOK_STATIC(CloneSystem, GetCloneTime, (int level) -> int)
{
    LOG_HOOK("HOOK_STATIC -> CloneSystem::GetCloneTime -> Begin (CustomSystems.cpp)\n")

    CustomCloneSystem::CloneLevel& glevel = CustomCloneSystem::GetLevel(level);
    return (int)glevel.cloneSpeed;
}

HOOK_STATIC(CloneSystem, GetJumpHealth, (int level) -> int)
{
    LOG_HOOK("HOOK_STATIC -> CloneSystem::GetJumpHealth -> Begin (CustomSystems.cpp)\n")

    CustomCloneSystem::CloneLevel& glevel = CustomCloneSystem::GetLevel(level);
    return glevel.jumpHP;
}

HOOK_METHOD(TextLibrary, GetText, (const std::string &name, const std::string &lang) -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> TextLibrary::GetText -> Begin (CustomSystems.cpp)\n")

    std::string ret = super(name, lang);

    if (name == "clone_full")
    {
        CustomCloneSystem::CloneLevel& glevel = CustomCloneSystem::GetLevel(g_clonePercentTooltipLevel);
        if (glevel.jumpHPPercent > 0)
        {
            size_t pos = ret.find("\\2");

            if (pos != std::string::npos) ret.replace(pos, 2, glevel.jumpHP > 0 ? "\\2 + "+ std::to_string(glevel.jumpHPPercent) + "%" : "" + std::to_string(glevel.jumpHPPercent) + "%");
        }
    }
    if ((name == "clonebay_health" || name == "clonebay_damaged") && G_->GetShipManager(0)->cloneSystem != nullptr)
    {
        CustomCloneSystem::CloneLevel& glevel = CustomCloneSystem::GetLevel(G_->GetShipManager(0)->cloneSystem->healthState.first);
        if (glevel.jumpHPPercent > 0)
        {
            size_t pos = ret.find("\\1");

            if (pos != std::string::npos) ret.replace(pos, 2, glevel.jumpHP > 0 ? "\\1 + "+ std::to_string(glevel.jumpHPPercent) + "%" : "" + std::to_string(glevel.jumpHPPercent) + "%");

        }
    }

    return ret;
}

// Add the rendering of crew layer when cloning

HOOK_METHOD(CloneSystem, OnRenderFloor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CloneSystem::OnRenderFloor -> Begin (CustomSystems.cpp)\n")

    if (slot != -1) {
        Point pos = ShipGraph::GetShipInfo(_shipObj.iShipId)->GetSlotWorldPosition(slot, GetRoomId());

        G_->GetResources()->RenderImage(bottom, pos.x - 17.0, pos.y - 17.0, 0, GL_Color(1.f, 1.f, 1.f, 1.f), 1.0, false);

        if (currentCloneAnimation && currentCloneAnimation->tracker.running ) {
            currentCloneAnimation->OnRender(1.0, GL_Color(1.f, 1.f, 1.f, 1.f), false);
            std::vector<CrewMember*> crewList;
            G_->GetCrewFactory()->GetCloneReadyList(crewList, _shipObj.iShipId == 0);

            if (!crewList.empty())
            {
                CrewMember *cloningCrew = crewList[0];
                if (!cloningCrew->crewAnim->layerStrips.empty()) {
                    for (int layer = 0; layer < cloningCrew->crewAnim->layerStrips.size(); layer++) {
                        GL_Color color = cloningCrew->crewAnim->layerColors[layer];
                        GL_Texture* tex = cloningCrew->crewAnim->layerStrips[layer];
                        AnimationDescriptor info = currentCloneAnimation->info;

                        int size_x = tex->width_;
                        int size_y = tex->height_;
                        int stripStartX = info.stripStartX + info.frameWidth * currentCloneAnimation->currentFrame;
                        int stripStartY = info.imageHeight - info.stripStartY - info.frameHeight;
                        
                        CSurface::GL_BlitImagePartial(tex, pos.x - 17.0, pos.y - 9.0, 
                            (float)info.frameWidth, 
                            (float)info.frameHeight, 
                            (float)stripStartX/size_x, 
                            (float)(stripStartX + info.frameWidth)/size_x, 
                            (float)stripStartY/size_y, 
                            (float)(stripStartY + info.frameHeight)/size_y, 
                            color.a, color, false);
                    }
                }
            }
            G_->GetResources()->RenderImage(gas, pos.x - 17.0, pos.y - 17.0, 0, GL_Color(1.f, 1.f, 1.f, 1.f), 1.0, false);
        }
        G_->GetResources()->RenderImage(top, pos.x - 17.0, pos.y - 17.0, 0, GL_Color(1.f, 1.f, 1.f, 1.f), 1.0, false);
    }
}

// fix vanilla bug were replacing the clone bay by a medical one would keep the crew in the cloning process perpetually
HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnLoop -> Begin (CustomSystems.cpp)\n")

    super();
    if (cloneSystem == nullptr)
    {
        std::vector<CrewMember*> crewList;
        G_->GetCrewFactory()->GetCloneReadyList(crewList,(iShipId==0));

        if (!crewList.empty())
        {
            crewList.front()->SetCloneReady(false);
        }
    }
}

void ShipManager::RemoveSystem(int iSystemId)
{
    if (HasSystem(iSystemId) && iSystemId != SYS_REACTOR && iSystemId != SYS_INVALID && iSystemId != SYS_ENGINES) //TODO: Possibly fix bug with engineless player ships?
    {
        //Remove base ShipSystem
        ShipSystem* removeSys = GetSystem(iSystemId);
        while (HasSystem(iSystemId)) //Repeat removal for artillery systems
        {
            int systemRoom = GetSystemRoom(iSystemId);
            ship.EmptySlots(systemRoom);
            for (CrewMember* crew : vCrewList)
            {
                if (crew->currentSlot.roomId == systemRoom)
                {
                    crew->EmptySlot();
                    crew->SetRoom(systemRoom);
                    crew->SetCurrentSystem(nullptr);
                    crew->StopRepairing();
                }
            }
            ShipSystem* specificSys = GetSystem(iSystemId);      
            if (specificSys->bNeedsPower)
            {
                while (specificSys->RawDecreasePower()) continue;
            }
            
            vSystemList.erase(vSystemList.begin() + systemKey[iSystemId]);
            systemKey[iSystemId] = -1;
            for (int idx = 0; idx < vSystemList.size(); ++idx)
            {
                ShipSystem* sys = vSystemList[idx];
                systemKey[sys->iSystemType] = idx;
            }
            RemoveEquipment(ShipSystem::SystemIdToName(iSystemId), true);

            if (current_target && current_target->hackingSystem != nullptr)
            {
                if (current_target->hackingSystem->queuedSystem == specificSys)
                {
                    current_target->hackingSystem->queuedSystem = nullptr;
                }
                if (current_target->hackingSystem->currentSystem == specificSys)
                {
                    current_target->hackingSystem->currentSystem = nullptr;
                }
            }
        }
        CommandGui* gui = G_->GetCApp()->gui;
        ShipBuilder& shipBuilder = G_->GetCApp()->menu.shipBuilder;
        //Special handling per system for derived classes
        switch (iSystemId)
        {
            case SYS_SHIELDS: 
            {
                //shieldSystem is present even for ships without shields installed
                break;
            };    
            case SYS_ENGINES: 
            {
                delete engineSystem;
                engineSystem = nullptr;
                break;
            };    
            case SYS_OXYGEN: 
            {
                std::vector<float> oxygenLevels = std::move(oxygenSystem->oxygenLevels);
                delete oxygenSystem;
                oxygenSystem = nullptr;
                if (CustomOptionsManager::GetInstance()->oxygenWithoutSystem.currentValue)
                {
                    InstallDummyOxygen();
                    oxygenSystem->oxygenLevels = std::move(oxygenLevels);
                }
                break;
            };  
            case SYS_WEAPONS: 
            {
                if (iShipId == 0)
                {
                    if (!shipBuilder.bOpen) gui->combatControl.DisarmAll();
                    for (ProjectileFactory* weapon : weaponSystem->weapons)
                    {
                        gui->equipScreen.AddToCargo(weapon->blueprint->name);   
                    }
                    
                    for (ArmamentBox* box : gui->combatControl.weapControl.boxes)
                    {
                        static_cast<WeaponBox*>(box)->pWeapon = nullptr;
                    }

                }
                for (int slot = 0; slot < myBlueprint.weaponSlots; ++slot)
                {
                    weaponSystem->RemoveWeapon(slot);
                }
                tempMissileCount = weaponSystem->missile_count;
                delete weaponSystem;
                weaponSystem = nullptr;
                gui->equipScreen.OnLoop();
                break; 
            };    
            case SYS_DRONES:
            {
                if (iShipId == 0)
                {
                    if (!shipBuilder.bOpen) gui->combatControl.DisarmAll();
                    for (Drone* drone : droneSystem->drones)
                    {
                        gui->equipScreen.AddToCargo(drone->blueprint->name);
                    }

                    for (ArmamentBox* box : gui->combatControl.weapControl.boxes)
                    {
                        static_cast<DroneBox*>(box)->pDrone = nullptr;
                    }
                } 
                Drone* removedDrone = droneSystem->RemoveDrone(0);
                while (removedDrone != nullptr)
                {
                    removedDrone->SetDestroyed(true, false);
                    removedDrone->SetPowered(false);
                    removedDrone = droneSystem->RemoveDrone(0);
                }
                
                tempDroneCount = droneSystem->drone_count;
                delete droneSystem;
                droneSystem = nullptr;
                gui->equipScreen.OnLoop();
                break; 
            };  
            case SYS_MEDBAY:
            {
                delete medbaySystem;
                medbaySystem = nullptr;
                break;
            };     
            case SYS_PILOT: 
            {
                delete removeSys;
                removeSys = nullptr;
                break;
            };      
            case SYS_SENSORS: 
            {
                delete removeSys;
                removeSys = nullptr;
                break;
            };      
            case SYS_DOORS: 
            {
                delete removeSys;
                removeSys = nullptr;
                break;
            };         
            case SYS_TELEPORTER: 
            {
                if (!shipBuilder.bOpen) gui->combatControl.DisarmAll();
                delete teleportSystem;
                teleportSystem = nullptr;
                break;
            }; 
            case SYS_CLOAKING: 
            {
                if (HasSystem(SYS_WEAPONS))
                {
                    weaponSystem->cloakingSystem = nullptr;
                }
                delete cloakSystem;
                cloakSystem = nullptr;
                break;
            };   
            case SYS_ARTILLERY: 
            {
                if (!shipBuilder.bOpen) gui->combatControl.DisarmAll();
                for (ArtillerySystem* artillery : artillerySystems)
                {
                    delete artillery;
                }
                artillerySystems.clear();

                break;
            };  
            case SYS_BATTERY: 
            {
                //TOOD: Hook and use PowerManager::SetBatteryPower
                PowerManager::GetPowerManager(iShipId)->batteryPower.first = 0;
                PowerManager::GetPowerManager(iShipId)->batteryPower.second = 0;
                delete batterySystem;
                batterySystem = nullptr;
                break;
            };    
            case SYS_CLONEBAY: 
            {
                //Check edge cases with cloned crew
                delete cloneSystem;
                cloneSystem = nullptr;
                break;
            };   
            case SYS_MIND: 
            {
                if (!shipBuilder.bOpen) gui->combatControl.DisarmAll();
                mindSystem->ReleaseCrew();
                delete mindSystem;
                mindSystem = nullptr;
                break;
            };       
            case SYS_HACKING: 
            {
                if (!shipBuilder.bOpen) gui->combatControl.DisarmAll();
                hackingSystem->BlowHackingDrone();
                delete hackingSystem;
                hackingSystem = nullptr;
                break;
            };    
            case SYS_TEMPORAL: 
            {
                if (!shipBuilder.bOpen) gui->combatControl.DisarmAll();
                SYS_EX(removeSys)->temporalSystem->StopTimeDilation();
                delete removeSys;
                removeSys = nullptr;
                break;
            };  
            default:
            {
                delete removeSys;
                removeSys = nullptr;
                break;
            };   
        }
        if (!shipBuilder.bOpen) gui->sysControl.CreateSystemBoxes();
        else shipBuilder.CreateSystemBoxes();
    }
}
//The original game code uses the starting ShipBlueprint when loading the game, and adds all starting systems by default.
//Here we block addition of systems that the ship originally starts with and that have been removed

//Save removed starting system ids
HOOK_METHOD(ShipManager, ExportShip, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ExportShip -> Begin (CustomSystems.cpp)\n")
    ShipBlueprint* baseBlueprint = G_->GetBlueprints()->GetShipBlueprint(myBlueprint.blueprintName, -1);
    std::vector<int> removedStartingSystems;
    for (int startingSystemId : baseBlueprint->systems)
    {
        if (!HasSystem(startingSystemId))
        {
            removedStartingSystems.push_back(startingSystemId);
        }
    }
    FileHelper::writeInt(file, removedStartingSystems.size());
    for (int removedStartingSystemId : removedStartingSystems)
    {
        FileHelper::writeInt(file, removedStartingSystemId);
    }

    super(file);
}
//Block addition of removed starting systems and remove their ids from systems vector in the ShipBlueprint
static std::unordered_set<int> blockSystemAddition;
HOOK_METHOD(ShipManager, ImportShip, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ImportShip -> Begin (CustomSystems.cpp)\n")
    int numRemovedSystems = FileHelper::readInteger(file);
    for (int i = 0; i < numRemovedSystems; ++i)
    {
        int removedSystemId = FileHelper::readInteger(file);
        blockSystemAddition.insert(removedSystemId);
    }
    super(file);
    auto& systems = myBlueprint.systems;
    systems.erase(std::remove_if(systems.begin(), systems.end(), 
    [&](int value) 
    {return blockSystemAddition.find(value) != blockSystemAddition.end();}),
    systems.end());
    blockSystemAddition.clear();
}

HOOK_METHOD_PRIORITY(ShipManager, AddSystem, -100, (int systemId) -> int)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::AddSystem -> Begin (CustomSystems.cpp)\n")
    if (blockSystemAddition.find(systemId) != blockSystemAddition.end())
    {
        return 0;
    }
    return super(systemId);
}

int ShipManager::SystemWillReplace(int systemId)
{
    for (ShipSystem* sys : vSystemList)
    {
        if (CustomUserSystems::AreSystemsExclusive(systemId, sys->iSystemType))
        {
            return sys->iSystemType;
        }
    }

    if (!CustomOptionsManager::GetInstance()->duelMedical.currentValue)
    {
        if (systemId == SYS_MEDBAY && HasSystem(SYS_CLONEBAY)) return SYS_CLONEBAY;
        if (systemId == SYS_CLONEBAY && HasSystem(SYS_MEDBAY)) return SYS_MEDBAY;
    }
    
    return SYS_INVALID;   
}