#include "CrewMember_Extend.h"
#include "CrewBox_Extend.h"
#include "ShipManager_Extend.h"
#include "CustomCrew.h"
#include "CustomOptions.h"
#include "Resources.h"
#include "TemporalSystem.h"
#include "CustomDamage.h"
#include "ShipUnlocks.h"
#include "CustomEvents.h"

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>

TransformColorMode g_transformColorMode = TransformColorMode::KEEP_INDICES;
bool g_resistsMindControlStat = false;

static const std::string CREW_SKILLS[6] =
{
    "piloting",
    "engines",
    "shields",
    "weapons",
    "repair",
    "combat"
};

bool g_advancedCrewTooltips = true;
bool g_showEnemyPowers = true;
bool g_showAllyPowers = false;
int g_advancedCrewTooltipRounding = 2;

CustomCrewManager CustomCrewManager::instance = CustomCrewManager();

void CustomCrewManager::AddCrewDefinition(CrewDefinition crew)
{
    blueprintNames[crew.race] = crew;
}


void CustomCrewManager::ParseCrewNode(rapidxml::xml_node<char> *node)
{
    try
    {
        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            if (child->first_attribute("name"))
            {
                std::string name = std::string(child->first_attribute("name")->value());

                CrewDefinition crew;

                crew.race = name;
                crew.deathSounds = std::vector<std::string>();
                crew.shootingSounds = std::vector<std::string>();
                crew.repairSounds = std::vector<std::string>();

                crew.repairSounds.push_back("repair");

                crew.skillsDef = SkillsDefinition();
                crew.explosionDef = ExplosionDefinition();

                crew.explosionDef.damage.iDamage = 0;
                crew.explosionDef.damage.iShieldPiercing = 0;
                crew.explosionDef.damage.fireChance = 0;
                crew.explosionDef.damage.breachChance = 0;
                crew.explosionDef.damage.stunChance = 0;
                crew.explosionDef.damage.iIonDamage = 0;
                crew.explosionDef.damage.iSystemDamage = 0;
                crew.explosionDef.damage.iPersDamage = 0;
                crew.explosionDef.damage.bHullBuster = false;
                crew.explosionDef.damage.ownerId = -1;
                crew.explosionDef.damage.selfId = -1;
                crew.explosionDef.damage.bLockdown = false;
                crew.explosionDef.damage.crystalShard = false;
                crew.explosionDef.damage.bFriendlyFire = false;
                crew.explosionDef.damage.iStun = 0;
                crew.explosionDef.shipFriendlyFire = false;

                if (child->first_attribute("drone"))
                {
                    std::string droneType = child->first_attribute("drone")->value();

                    crew.canBurn = false;
                    crew.canRepair = false;
                    crew.canSabotage = false;
                    crew.canSuffocate = false;
                    crew.controllable = false;
                    crew.canFight = false;
                    crew.canMan = false;
                    crew.canTeleport = false;
                    crew.moveSpeedMultiplier = 0.5f;

                    if (droneType == "BOARDER")
                    {
                        crew.canFight = true;
                        crew.canSabotage = true;
                        crew.damageMultiplier = 1.2f;
                        crew.maxHealth = 150;
                    }
                    if (droneType == "BATTLE")
                    {
                        crew.canFight = true;
                        crew.damageMultiplier = 1.2f;
                        crew.maxHealth = 150;
                    }
                    if (droneType == "BOARDER_ION")
                    {
                        crew.canSabotage = true;
                        crew.maxHealth = 125;
                    }
                    if (droneType == "REPAIR")
                    {
                        crew.canRepair = true;
                        crew.maxHealth = 25;
                        crew.repairSpeed = 2.f;
                        crew.animBase = "repair";
                    }
                }

                try
                {
                    for (auto stat = child->first_node(); stat; stat = stat->next_sibling())
                    {
                        std::string str = std::string(stat->name());
                        std::string val = std::string(stat->value());

                        if (str == "canFight")
                        {
                            crew.canFight = EventsParser::ParseBoolean(val);
                        }
                        if (str == "controllable")
                        {
                            crew.controllable = EventsParser::ParseBoolean(val);
                        }
                        if (str == "selectable")
                        {
                            crew.selectable = EventsParser::ParseBoolean(val);
                        }
                        if (str == "canRepair")
                        {
                            crew.canRepair = EventsParser::ParseBoolean(val);
                        }
                        if (str == "canSabotage")
                        {
                            crew.canSabotage = EventsParser::ParseBoolean(val);
                        }
                        if (str == "canMan")
                        {
                            crew.canMan = EventsParser::ParseBoolean(val);
                        }
                        if (str == "canTeleport")
                        {
                            crew.canTeleport = EventsParser::ParseBoolean(val);
                        }
                        if (str == "canSuffocate")
                        {
                            crew.canSuffocate = EventsParser::ParseBoolean(val);
                        }
                        if (str == "canBurn")
                        {
                            crew.canBurn = EventsParser::ParseBoolean(val);
                        }
                        if (str == "maxHealth")
                        {
                            crew.maxHealth = boost::lexical_cast<int>(val);
                        }
                        if (str == "stunMultiplier")
                        {
                            crew.stunMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "moveSpeedMultiplier")
                        {
                            crew.moveSpeedMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "repairSpeed")
                        {
                            crew.repairSpeed = boost::lexical_cast<float>(val);
                        }
                        if (str == "damageMultiplier")
                        {
                            crew.damageMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "rangedDamageMultiplier")
                        {
                            crew.rangedDamageMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "doorDamageMultiplier")
                        {
                            crew.doorDamageMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "fireRepairMultiplier")
                        {
                            crew.fireRepairMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "suffocationModifier")
                        {
                            crew.suffocationModifier = boost::lexical_cast<float>(val);
                        }
                        if (str == "providesPower")
                        {
                            crew.providesPower = EventsParser::ParseBoolean(val);
                        }
                        if (str == "bonusPower")
                        {
                            crew.bonusPower = boost::lexical_cast<int>(val);
                        }
                        if (str == "isTelepathic")
                        {
                            crew.isTelepathic = EventsParser::ParseBoolean(val);
                        }
                        if (str == "resistsMindControl")
                        {
                            crew.resistsMindControl = EventsParser::ParseBoolean(val);
                        }
                        if (str == "isAnaerobic")
                        {
                            crew.isAnaerobic = EventsParser::ParseBoolean(val);
                        }
                        if (str == "fireDamageMultiplier")
                        {
                            crew.fireDamageMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "canPhaseThroughDoors")
                        {
                            crew.canPhaseThroughDoors = EventsParser::ParseBoolean(val);
                        }
                        if (str == "healSpeed")
                        {
                            crew.healSpeed = boost::lexical_cast<float>(val);
                        }
                        if (str == "powerDrain")
                        {
                            crew.powerDrain = boost::lexical_cast<int>(val);
                        }
                        if (str == "powerDrainFriendly")
                        {
                            crew.powerDrainFriendly = EventsParser::ParseBoolean(val);
                        }
                        if (str == "deathSounds")
                        {
                            bool male = true;
                            bool female = true;
                            if (stat->first_attribute("male"))
                            {
                                if (EventsParser::ParseBoolean(stat->first_attribute("male")->value()))
                                {
                                    female = false;
                                }
                                else
                                {
                                    male = false;
                                }
                            }
                            if (stat->first_attribute("female"))
                            {
                                if (EventsParser::ParseBoolean(stat->first_attribute("female")->value()))
                                {
                                    male = false;
                                }
                                else
                                {
                                    female = false;
                                }
                            }
                            for (auto deathSoundNode = stat->first_node(); deathSoundNode; deathSoundNode = deathSoundNode->next_sibling())
                            {
                                if (strcmp(deathSoundNode->name(), "deathSound") == 0)
                                {
                                    if (male) crew.deathSounds.push_back(std::string(deathSoundNode->value()));
                                    if (female) crew.deathSoundsFemale.push_back(std::string(deathSoundNode->value()));
                                }
                            }
                        }
                        if (str == "shootingSounds")
                        {
                            for (auto shootingSoundNode = stat->first_node(); shootingSoundNode; shootingSoundNode = shootingSoundNode->next_sibling())
                            {
                                if (strcmp(shootingSoundNode->name(), "shootingSound") == 0)
                                {
                                    crew.shootingSounds.push_back(std::string(shootingSoundNode->value()));
                                }
                            }
                        }
                        if (str == "repairSounds")
                        {
                            crew.repairSounds.clear();

                            for (auto repairSoundNode = stat->first_node(); repairSoundNode; repairSoundNode = repairSoundNode->next_sibling())
                            {
                                if (strcmp(repairSoundNode->name(), "repairSound") == 0)
                                {
                                    crew.repairSounds.push_back(std::string(repairSoundNode->value()));
                                }
                            }

                            if (stat->first_attribute("animSoundFrame"))
                            {
                                crew.repairSoundFrame = boost::lexical_cast<int>(stat->first_attribute("animSoundFrame")->value());
                            }
                        }
                        if (str == "passiveStatBoosts")
                        {
                            for (auto statBoostNode = stat->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
                            {
                                crew.passiveStatBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, StatBoostDefinition::BoostSource::CREW, false));
                            }
                        }
                        if (str == "animBase")
                        {
                            crew.animBase = val;
                        }
                        if (str == "animSheet")
                        {
                            crew.animSheet[0] = val;
                            crew.animSheet[1] = val;
                        }
                        if (str == "animSheetFemale")
                        {
                            crew.animSheet[0] = val;
                        }
                        if (str == "shootTimer")
                        {
                            if (!val.empty())
                            {
                                crew.shootTimer.first = boost::lexical_cast<int>(val);
                                crew.shootTimer.second = boost::lexical_cast<int>(val);
                            }
                            if (stat->first_attribute("min"))
                            {
                                crew.shootTimer.first = boost::lexical_cast<int>(stat->first_attribute("min")->value());
                                if (crew.shootTimer.second == -1) crew.shootTimer.second = boost::lexical_cast<int>(stat->first_attribute("min")->value());
                            }
                            if (stat->first_attribute("max"))
                            {
                                crew.shootTimer.second = boost::lexical_cast<int>(stat->first_attribute("max")->value());
                                if (crew.shootTimer.second == -1) crew.shootTimer.first = boost::lexical_cast<int>(stat->first_attribute("max")->value());
                            }
                        }
                        if (str == "punchTimer")
                        {
                            if (!val.empty())
                            {
                                crew.punchTimer.first = boost::lexical_cast<int>(val);
                                crew.punchTimer.second = boost::lexical_cast<int>(val);
                            }
                            if (stat->first_attribute("min"))
                            {
                                crew.punchTimer.first = boost::lexical_cast<int>(stat->first_attribute("min")->value());
                                if (crew.punchTimer.second == -1) crew.punchTimer.second = boost::lexical_cast<int>(stat->first_attribute("min")->value());
                            }
                            if (stat->first_attribute("max"))
                            {
                                crew.punchTimer.second = boost::lexical_cast<int>(stat->first_attribute("max")->value());
                                if (crew.punchTimer.second == -1) crew.punchTimer.first = boost::lexical_cast<int>(stat->first_attribute("max")->value());
                            }
                        }
                        if (str == "canPunch")
                        {
                            crew.canPunch = EventsParser::ParseBoolean(val);
                        }
                        if (str == "oxygenChangeSpeed")
                        {
                            crew.oxygenChangeSpeed = boost::lexical_cast<float>(val);
                        }
                        if (str == "damageTakenMultiplier")
                        {
                            crew.damageTakenMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "passiveHealAmount")
                        {
                            crew.passiveHealAmount = boost::lexical_cast<float>(val);
                        }
                        if (str == "truePassiveHealAmount")
                        {
                            crew.truePassiveHealAmount = boost::lexical_cast<float>(val);
                        }
                        if (str == "healAmount")
                        {
                            crew.healAmount = boost::lexical_cast<float>(val);
                        }
                        if (str == "trueHealAmount")
                        {
                            crew.trueHealAmount = boost::lexical_cast<float>(val);
                        }
                        if (str == "passiveHealDelay")
                        {
                            crew.passiveHealDelay = boost::lexical_cast<int>(val);
                        }
                        if (str == "detectsLifeforms")
                        {
                            crew.detectsLifeforms = EventsParser::ParseBoolean(val);
                        }
                        if (str == "healCrewAmount")
                        {
                            crew.healCrewAmount = boost::lexical_cast<float>(val);
                        }
                        if (str == "skills")
                        {
                            for (auto skillNode = stat->first_node(); skillNode; skillNode = skillNode->next_sibling())
                            {
                                std::string skillName = std::string(skillNode->name());

                                for (auto i : CREW_SKILLS)
                                {
                                    if (skillName == i)
                                    {
                                        if (skillNode->first_attribute("req"))
                                        {
                                            crew.skillsDef.skills[i].requirement = boost::lexical_cast<int>(skillNode->first_attribute("req")->value());
                                        }
                                    }
                                }
                            }
                        }
                        if (str == "hasCustomDeathAnimation")
                        {
                            crew.hasCustomDeathAnimation = EventsParser::ParseBoolean(val);
                        }
                        if (str == "sabotageSpeedMultiplier")
                        {
                            crew.sabotageSpeedMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "defaultSkillLevel")
                        {
                            crew.defaultSkillLevel = boost::lexical_cast<int>(val);
                        }
                        if (str == "cloneLoseSkills")
                        {
                            crew.cloneLoseSkills = EventsParser::ParseBoolean(val);
                        }
                        if (str == "allDamageTakenMultiplier")
                        {
                            crew.allDamageTakenMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "damageEnemiesAmount")
                        {
                            crew.damageEnemiesAmount = boost::lexical_cast<float>(val);
                        }
                        if (str == "hackDoors")
                        {
                            crew.hackDoors = EventsParser::ParseBoolean(val);
                        }
                        if (str == "powerRechargeMultiplier")
                        {
                            crew.powerRechargeMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "nameRace")
                        {
                            crew.nameRace.push_back(stat->value());
                            if (stat->first_attribute("transformName"))
                            {
                                crew.transformName.push_back(stat->first_attribute("transformName")->value());
                            }
                            if (stat->first_attribute("changeIfSame"))
                            {
                                crew.changeIfSame = EventsParser::ParseBoolean(stat->first_attribute("changeIfSame")->value());
                            }
                        }
                        if (str == "droneAI")
                        {
                            crew.droneAI.hasCustomAI = true;
                            for (auto effectNode = stat->first_node(); effectNode; effectNode = effectNode->next_sibling())
                            {
                                std::string effectName = std::string(effectNode->name());

                                if (effectName == "fightAI")
                                {
                                    crew.droneAI.fightAI = true;
                                }
                                if (effectName == "repairAI")
                                {
                                    crew.droneAI.repairAI = true;
                                }
                                if (effectName == "manAI")
                                {
                                    crew.droneAI.manAI = true;
                                }
                                if (effectName == "batteryAI")
                                {
                                    crew.droneAI.batteryAI = true;
                                }
                                if (effectName == "returnToDroneRoom")
                                {
                                    crew.droneAI.returnToDroneRoom = true;
                                }
                            }
                        }
                        if (str == "droneMoveFromManningSlot")
                        {
                            crew.droneMoveFromManningSlot = EventsParser::ParseBoolean(val);
                        }
                        if (str == "deathEffect")
                        {
                            crew.hasDeathExplosion = true;
                            ParseDeathEffect(stat, &crew.explosionDef);
                        }
                        if (str == "powerEffect")
                        {
                            ActivatedPowerDefinition *powerDef = ParseAbilityEffect(stat);
                            crew.powerDefs.push_back(powerDef);
                        }
                        if (str == "powerResource")
                        {
                            ParseAbilityResource(stat); // doesn't get used directly for now, just allows it to be defined
                        }
                        if (str == "crewSlots")
                        {
                            crew.crewSlots = boost::lexical_cast<float>(val);
                        }
                        if (str == "noSlot")
                        {
                            crew.noSlot = EventsParser::ParseBoolean(val);
                        }
                        if (str == "noClone")
                        {
                            crew.noClone = EventsParser::ParseBoolean(val);
                        }
                        if (str == "cloneSpeedMultiplier")
                        {
                            crew.cloneSpeedMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "noAI")
                        {
                            crew.noAI = EventsParser::ParseBoolean(val);
                        }
                        if (str == "validTarget")
                        {
                            crew.validTarget = EventsParser::ParseBoolean(val);
                        }
                        if (str == "canMove")
                        {
                            crew.canMove = EventsParser::ParseBoolean(val);
                        }
                        if (str == "snapToSlot")
                        {
                            crew.snapToSlot = EventsParser::ParseBoolean(val);
                        }
                        if (str == "teleportMove")
                        {
                            crew.teleportMove = EventsParser::ParseBoolean(val);
                        }
                        if (str == "teleportMoveOtherShip")
                        {
                            crew.teleportMoveOtherShip = EventsParser::ParseBoolean(val);
                        }
                        if (str == "essential")
                        {
                            crew.essential = boost::lexical_cast<float>(val);
                        }
                        if (str == "silenced")
                        {
                            crew.silenced = EventsParser::ParseBoolean(val);
                        }
                        if (str == "lowHealthThreshold")
                        {
                            crew.lowHealthThreshold = boost::lexical_cast<float>(val);
                        }
                        if (str == "lowHealthThresholdPercentage")
                        {
                            crew.lowHealthThresholdPercentage = boost::lexical_cast<float>(val);
                        }
                        if (str == "noWarning")
                        {
                            crew.noWarning = EventsParser::ParseBoolean(val);
                        }
                    }
                }
                catch (boost::bad_lexical_cast const &e)
                {
                    ErrorMessage(std::string("Error parsing <crew> in hyperspace.xml\n") + std::string(e.what()));
                }

                AddCrewDefinition(crew);
            }
        }
    }
    catch (rapidxml::parse_error& e)
    {
        ErrorMessage(std::string("Error parsing <crew> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (std::exception &e)
    {
        ErrorMessage(std::string("Error parsing <crew> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (const char* e)
    {
        ErrorMessage(std::string("Error parsing <crew> in hyperspace.xml\n") + std::string(e));
    }
    catch (...)
    {
        ErrorMessage("Error parsing <crew> in hyperspace.xml\n");
    }
}

void CustomCrewManager::ParseDeathEffect(rapidxml::xml_node<char>* stat, ExplosionDefinition* explosionDef)
{
    ExplosionDefinition def;
    if (explosionDef != nullptr)
    {
        def = *explosionDef;
    }
    for (auto effectNode = stat->first_node(); effectNode; effectNode = effectNode->next_sibling())
    {
        std::string effectName = std::string(effectNode->name());

        if (effectName == "damage")
        {
            def.damage.iDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "fireChance")
        {
            def.damage.fireChance = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "breachChance")
        {
            def.damage.breachChance = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "ion")
        {
            def.damage.iIonDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "sysDamage")
        {
            def.damage.iSystemDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "persDamage")
        {
            def.damage.iPersDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "hullBust")
        {
            def.damage.bHullBuster = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "lockdown")
        {
            def.damage.bLockdown = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "friendlyFire")
        {
            def.damage.bFriendlyFire = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "stun")
        {
            def.damage.iStun = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "shipFriendlyFire")
        {
            def.shipFriendlyFire = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "transformRace")
        {
            def.transformRace = effectNode->value();
            def.transformRaceHealth = 0.f;
            def.transformRaceHealthFraction = 1.f;
            def.transformRaceDeathSound = false;

            if (effectNode->first_attribute("health"))
            {
                def.transformRaceHealth = boost::lexical_cast<float>(effectNode->first_attribute("health")->value());
                def.transformRaceHealthFraction = 0.f;
            }
            if (effectNode->first_attribute("healthFraction"))
            {
                def.transformRaceHealthFraction = boost::lexical_cast<float>(effectNode->first_attribute("healthFraction")->value());
            }
            if (effectNode->first_attribute("deathSound"))
            {
                def.transformRaceDeathSound = EventsParser::ParseBoolean(effectNode->first_attribute("deathSound")->value());
            }
        }
        if (effectName == "spawnCrew")
        {
            CrewSpawn* newSpawn = CrewSpawn::ParseCrewSpawn(effectNode, true);

            if (!newSpawn->race.empty())
            {
                def.crewSpawns.push_back(newSpawn);
            }
            else
            {
                delete newSpawn;
            }
        }
        if (effectName == "statBoosts")
        {
            for (auto statBoostNode = effectNode->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
            {
                if (strcmp(statBoostNode->name(), "statBoost") == 0)
                {
                    def.statBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, StatBoostDefinition::BoostSource::CREW, false));
                }
            }
        }
        if (effectName == "roomStatBoosts")
        {
            for (auto statBoostNode = effectNode->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
            {
                if (strcmp(statBoostNode->name(), "statBoost") == 0)
                {
                    def.roomStatBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, StatBoostDefinition::BoostSource::CREW, true));
                }
            }
        }
        if (effectName == "event")
        {
            def.event[0] = G_->GetEventsParser()->ProcessEvent(effectNode, "__crewDeath");
            def.event[1] = def.event[0];
        }
        if (effectName == "playerEvent")
        {
            def.event[0] = G_->GetEventsParser()->ProcessEvent(effectNode, "__crewDeath");
        }
        if (effectName == "enemyEvent")
        {
            def.event[1] = G_->GetEventsParser()->ProcessEvent(effectNode, "__crewDeath");
        }
    }
    if (!explosionDef)
    {
        explosionDef = new ExplosionDefinition();
    }
    *explosionDef = def;
}

ActivatedPowerDefinition* CustomCrewManager::ParseAbilityEffect(rapidxml::xml_node<char>* stat)
{
    ActivatedPowerDefinition* def;
    std::string name;

    if (stat->first_attribute("load"))
    {
        name = stat->first_attribute("load")->value();
        def = ActivatedPowerDefinition::GetPowerByName(name);
        if (!def)
        {
            ActivatedPowerDefinition::AddUndefinedPower(name); // allows the power to be defined later
        }
        return def;
    }

    ActivatedPowerDefinition* copyDef = nullptr;

    if (stat->first_attribute("copy"))
    {
        name = stat->first_attribute("copy")->value();
        copyDef = ActivatedPowerDefinition::GetPowerByName(name);
    }

    if (stat->first_attribute("name"))
    {
        name = stat->first_attribute("name")->value();
        def = ActivatedPowerDefinition::AddNamedDefinition(name, copyDef);
    }
    else if (copyDef)
    {
        def = new ActivatedPowerDefinition(*copyDef);
    }
    else
    {
        def = new ActivatedPowerDefinition();
    }

    def->AssignIndex();

    def->hasSpecialPower = true;

    if (!name.empty())
    {
        def->name = name;
    }

    for (auto effectNode = stat->first_node(); effectNode; effectNode = effectNode->next_sibling())
    {
        std::string effectName = std::string(effectNode->name());

        if (effectName == "groupName")
        {
            name = effectNode->value();
            def->AssignGroup(name);
        }
        if (effectName == "activateGroupName")
        {
            name = effectNode->value();
            def->AssignActivateGroup(name);
        }
        if (effectName == "replaceGroupName")
        {
            name = effectNode->value();
            def->AssignReplaceGroup(name);
        }

        if (effectName == "powerSounds")
        {
            if (effectNode->first_attribute("enemy"))
            {
                def->soundsEnemy = EventsParser::ParseBoolean(effectNode->first_attribute("enemy")->value());
            }

            for (auto soundNode = effectNode->first_node(); soundNode; soundNode = soundNode->next_sibling())
            {
                if (strcmp(soundNode->name(), "powerSound") == 0)
                {
                    def->sounds.push_back(std::string(soundNode->value()));
                }
            }
        }
        if (effectName == "powerEffectSounds")
        {
            if (effectNode->first_attribute("enemy"))
            {
                def->effectSoundsEnemy = EventsParser::ParseBoolean(effectNode->first_attribute("enemy")->value());
            }

            for (auto soundNode = effectNode->first_node(); soundNode; soundNode = soundNode->next_sibling())
            {
                if (strcmp(soundNode->name(), "powerSound") == 0)
                {
                    def->effectSounds.push_back(std::string(soundNode->value()));
                }
            }
        }
        if (effectName == "req")
        {
            auto reqDef = ActivatedPowerRequirements();

            ParsePowerRequirementsNode(effectNode, &reqDef);

            if (effectNode->first_attribute("type"))
            {
                if (strcmp(effectNode->first_attribute("type")->value(), "player") == 0)
                {
                    def->playerReq = reqDef;
                    def->playerReq.type = ActivatedPowerRequirements::Type::PLAYER;
                }
                else if (strcmp(effectNode->first_attribute("type")->value(), "enemy") == 0)
                {
                    def->enemyReq = reqDef;
                    def->enemyReq.type = ActivatedPowerRequirements::Type::ENEMY;
                }
                else
                {
                    def->enemyReq = reqDef;
                    def->enemyReq.type = ActivatedPowerRequirements::Type::ENEMY;
                    def->playerReq = reqDef;
                    def->playerReq.type = ActivatedPowerRequirements::Type::PLAYER;
                }
            }
            else
            {
                def->enemyReq = reqDef;
                def->enemyReq.type = ActivatedPowerRequirements::Type::ENEMY;
                def->playerReq = reqDef;
                def->playerReq.type = ActivatedPowerRequirements::Type::PLAYER;
            }
        }
        if (effectName == "chargeReq")
        {
            def->chargeReq = new ActivatedPowerRequirements(ActivatedPowerRequirements::Type::CHARGE);

            ParsePowerRequirementsNode(effectNode, def->chargeReq);
        }
        if (effectName == "jumpCooldown")
        {
            std::string v = effectNode->value();

            if (v == "full") def->jumpCooldown = ActivatedPowerDefinition::JUMP_COOLDOWN_FULL;
            else if (v == "reset") def->jumpCooldown = ActivatedPowerDefinition::JUMP_COOLDOWN_RESET;
            else if (v == "continue") def->jumpCooldown = ActivatedPowerDefinition::JUMP_COOLDOWN_CONTINUE;
        }
        if (effectName == "disabledCooldown")
        {
            std::string v = effectNode->value();

            if (v == "full") def->disabledCooldown = ActivatedPowerDefinition::DISABLED_COOLDOWN_FULL;
            else if (v == "reset") def->disabledCooldown = ActivatedPowerDefinition::DISABLED_COOLDOWN_RESET;
            else if (v == "continue") def->disabledCooldown = ActivatedPowerDefinition::DISABLED_COOLDOWN_CONTINUE;
            else if (v == "pause") def->disabledCooldown = ActivatedPowerDefinition::DISABLED_COOLDOWN_PAUSE;
            else if (v == "zero") def->disabledCooldown = ActivatedPowerDefinition::DISABLED_COOLDOWN_ZERO;
        }
        if (effectName == "disabledCharges")
        {
            std::string v = effectNode->value();

            if (v == "full") def->disabledCharges = ActivatedPowerDefinition::DISABLED_COOLDOWN_FULL;
            else if (v == "reset") def->disabledCharges = ActivatedPowerDefinition::DISABLED_COOLDOWN_RESET;
            else if (v == "continue") def->disabledCharges = ActivatedPowerDefinition::DISABLED_COOLDOWN_CONTINUE;
            else if (v == "pause") def->disabledCharges = ActivatedPowerDefinition::DISABLED_COOLDOWN_PAUSE;
            else if (v == "zero") def->disabledCharges = ActivatedPowerDefinition::DISABLED_COOLDOWN_ZERO;
        }
        if (effectName == "initialCooldownFraction")
        {
            def->initialCooldownFraction = boost::lexical_cast<float>(effectNode->value());
        }
        if (effectName == "onDeath")
        {
            std::string v = effectNode->value();

            if (v == "continue") def->onDeath = ActivatedPowerDefinition::ON_DEATH_CONTINUE;
            else if (v == "cancel") def->onDeath = ActivatedPowerDefinition::ON_DEATH_CANCEL;
            else if (v == "reset") def->onDeath = ActivatedPowerDefinition::ON_DEATH_RESET;
        }
        if (effectName == "onHotkey")
        {
            std::string v = effectNode->value();

            if (v == "first") def->onHotkey = ActivatedPowerDefinition::HOTKEY_FIRST;
            else if (v == "always") def->onHotkey = ActivatedPowerDefinition::HOTKEY_ALWAYS;
            else if (v == "never") def->onHotkey = ActivatedPowerDefinition::HOTKEY_NEVER;
        }
        if (effectName == "damage")
        {
            def->damage.iDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "fireChance")
        {
            def->damage.fireChance = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "breachChance")
        {
            def->damage.breachChance = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "ion")
        {
            def->damage.iIonDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "sysDamage")
        {
            def->damage.iSystemDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "persDamage")
        {
            def->damage.iPersDamage = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "hullBust")
        {
            def->damage.bHullBuster = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "lockdown")
        {
            def->damage.bLockdown = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "friendlyFire")
        {
            def->damage.bFriendlyFire = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "stun")
        {
            def->damage.iStun = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "cooldown")
        {
            def->cooldown = boost::lexical_cast<float>(effectNode->value());
        }
        if (effectName == "powerCharges")
        {
            def->powerCharges = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "initialCharges")
        {
            def->initialCharges = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "respawnCharges")
        {
            def->respawnCharges = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "chargesPerJump")
        {
            def->chargesPerJump = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "shipFriendlyFire")
        {
            def->shipFriendlyFire = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "win")
        {
            def->win = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "animFrame")
        {
            def->animFrame = boost::lexical_cast<int>(effectNode->value());
            if (effectNode->first_attribute("followCrew"))
            {
                def->followCrew = EventsParser::ParseBoolean(effectNode->first_attribute("followCrew")->value());
            }
        }
        if (effectName == "buttonText")
        {
            if (effectNode->first_attribute("id"))
            {
                def->buttonLabel.data = effectNode->first_attribute("id")->value();
                def->buttonLabel.isLiteral = false;
            }
            else
            {
                def->buttonLabel.data = effectNode->value();
                def->buttonLabel.isLiteral = true;
            }
        }
        if (effectName == "tooltip")
        {
            if (effectNode->first_attribute("id"))
            {
                def->tooltip.data = effectNode->first_attribute("id")->value();
                def->tooltip.isLiteral = false;
            }
            else
            {
                def->tooltip.data = effectNode->value();
                def->tooltip.isLiteral = true;
            }
        }
        if (effectName == "cooldownColor")
        {
            ParseColorNode(def->cooldownColor, effectNode);
        }
        if (effectName == "effectAnim")
        {
            def->effectAnim = effectNode->value();
        }
        if (effectName == "effectPostAnim")
        {
            def->effectPostAnim = effectNode->value();
        }
        if (effectName == "crewHealth")
        {
            def->crewHealth = boost::lexical_cast<float>(effectNode->value());
        }
        if (effectName == "enemyHealth")
        {
            def->enemyHealth = boost::lexical_cast<float>(effectNode->value());
        }
        if (effectName == "selfHealth")
        {
            def->selfHealth = boost::lexical_cast<float>(effectNode->value());
        }
        if (effectName == "activateWhenReady")
        {
            def->activateWhenReady = EventsParser::ParseBoolean(effectNode->value());

            if (effectNode->first_attribute("enemiesOnly"))
            {
                def->activateReadyEnemies = EventsParser::ParseBoolean(effectNode->first_attribute("enemiesOnly")->value());
            }
        }
        if (effectName == "transformRace")
        {
            def->transformRace = effectNode->value();
        }
        if (effectName == "spawnCrew")
        {
            CrewSpawn *newSpawn = CrewSpawn::ParseCrewSpawn(effectNode, true);
            if (!newSpawn->race.empty())
            {
                def->crewSpawns.push_back(newSpawn);
            }
        }
        if (effectName == "statBoosts")
        {
            for (auto statBoostNode = effectNode->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
            {
                if (strcmp(statBoostNode->name(), "statBoost") == 0)
                {
                    def->statBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, StatBoostDefinition::BoostSource::CREW, false));
                }
            }
        }
        if (effectName == "roomStatBoosts")
        {
            for (auto statBoostNode = effectNode->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
            {
                if (strcmp(statBoostNode->name(), "statBoost") == 0)
                {
                    def->roomStatBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, StatBoostDefinition::BoostSource::CREW, true));
                }
            }
        }
        if (effectName == "event")
        {
            def->event[0] = G_->GetEventsParser()->ProcessEvent(effectNode, "__crewAbility");
            def->event[1] = def->event[0];
        }
        if (effectName == "playerEvent")
        {
            def->event[0] = G_->GetEventsParser()->ProcessEvent(effectNode, "__crewAbility");
        }
        if (effectName == "enemyEvent")
        {
            def->event[1] = G_->GetEventsParser()->ProcessEvent(effectNode, "__crewAbility");
        }

        if (effectName == "sortOrder")
        {
            def->sortOrder = boost::lexical_cast<int>(effectNode->value());
        }

        if (effectName == "hideCooldown")
        {
            def->hideCooldown = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "hideCharges")
        {
            def->hideCharges = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "hideButton")
        {
            def->hideButton = EventsParser::ParseBoolean(effectNode->value());
        }

        if (effectName == "powerResource")
        {
            def->powerResources.push_back(ParseAbilityResource(effectNode));
        }

        if (effectName == "temporaryEffect")
        {
            def->hasTemporaryPower = true;

            for (auto tempEffectNode = effectNode->first_node(); tempEffectNode; tempEffectNode = tempEffectNode->next_sibling())
            {
                std::string tempEffectName = std::string(tempEffectNode->name());

                if (tempEffectName == "duration")
                {
                    def->tempPower.duration = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "cooldownColor")
                {
                    ParseColorNode(def->tempPower.cooldownColor, tempEffectNode);
                }
                if (tempEffectName == "finishSounds")
                {
                    if (tempEffectNode->first_attribute("enemy"))
                    {
                        def->tempPower.soundsEnemy = EventsParser::ParseBoolean(tempEffectNode->first_attribute("enemy")->value());
                    }

                    for (auto soundNode = tempEffectNode->first_node(); soundNode; soundNode = soundNode->next_sibling())
                    {
                        if (strcmp(soundNode->name(), "finishSound") == 0)
                        {
                            def->tempPower.sounds.push_back(std::string(soundNode->value()));
                        }
                    }
                }
                if (tempEffectName == "stunMultiplier")
                {
                    def->tempPower.stunMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "moveSpeedMultiplier")
                {
                    def->tempPower.moveSpeedMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "repairSpeed")
                {
                    def->tempPower.repairSpeed = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "damageMultiplier")
                {
                    def->tempPower.damageMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "rangedDamageMultiplier")
                {
                    def->tempPower.rangedDamageMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "doorDamageMultiplier")
                {
                    def->tempPower.doorDamageMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "bonusPower")
                {
                    def->tempPower.bonusPower = boost::lexical_cast<int>(tempEffectNode->value());
                }
                if (tempEffectName == "animSheet")
                {
                    def->tempPower.animSheet = tempEffectNode->value();
                    if (tempEffectNode->first_attribute("baseVisible"))
                    {
                        def->tempPower.baseVisible = EventsParser::ParseBoolean(tempEffectNode->first_attribute("baseVisible")->value());
                    }
                }
                if (tempEffectName == "effectAnim")
                {
                    def->tempPower.effectAnim = tempEffectNode->value();
                }
                if (tempEffectName == "invulnerable")
                {
                    def->tempPower.invulnerable = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "hackDoors")
                {
                    def->tempPower.hackDoors = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "controllable")
                {
                    def->tempPower.controllable = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "canFight")
                {
                    def->tempPower.canFight = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "canRepair")
                {
                    def->tempPower.canRepair = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "canSabotage")
                {
                    def->tempPower.canSabotage = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "canMan")
                {
                    def->tempPower.canMan = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "canTeleport")
                {
                    def->tempPower.canTeleport = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "canSuffocate")
                {
                    def->tempPower.canSuffocate = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "suffocationModifier")
                {
                    def->tempPower.suffocationModifier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "oxygenChangeSpeed")
                {
                    def->tempPower.oxygenChangeSpeed = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "canPhaseThroughDoors")
                {
                    def->tempPower.canPhaseThroughDoors = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "detectsLifeforms")
                {
                    def->tempPower.detectsLifeforms = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "isTelepathic")
                {
                    def->tempPower.isTelepathic = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "resistsMindControl")
                {
                    def->tempPower.resistsMindControl = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "fireDamageMultiplier")
                {
                    def->tempPower.fireDamageMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "damageTakenMultiplier")
                {
                    def->tempPower.damageTakenMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "allDamageTakenMultiplier")
                {
                    def->tempPower.allDamageTakenMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "sabotageSpeedMultiplier")
                {
                    def->tempPower.sabotageSpeedMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "passiveHealAmount")
                {
                    def->tempPower.passiveHealAmount = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "healAmount")
                {
                    def->tempPower.healAmount = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "truePassiveHealAmount")
                {
                    def->tempPower.truePassiveHealAmount = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "trueHealAmount")
                {
                    def->tempPower.trueHealAmount = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "damageEnemiesAmount")
                {
                    def->tempPower.damageEnemiesAmount = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "animFrame")
                {
                    def->tempPower.animFrame = boost::lexical_cast<int>(tempEffectNode->value());
                }
                if (tempEffectName == "healCrewAmount")
                {
                    def->tempPower.healCrewAmount = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "effectFinishAnim")
                {
                    def->tempPower.effectFinishAnim = tempEffectNode->value();
                }
                if (tempEffectName == "powerDrain")
                {
                    def->tempPower.powerDrain = boost::lexical_cast<int>(tempEffectNode->value());
                }
                if (tempEffectName == "powerDrainFriendly")
                {
                    def->tempPower.powerDrainFriendly = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "powerRechargeMultiplier")
                {
                    def->tempPower.powerRechargeMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "statBoosts")
                {
                    for (auto statBoostNode = tempEffectNode->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
                    {
                        def->tempPower.statBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, StatBoostDefinition::BoostSource::CREW, false));
                    }
                }
                if (tempEffectName == "noClone")
                {
                    def->tempPower.noClone = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "cloneSpeedMultiplier")
                {
                    def->tempPower.cloneSpeedMultiplier = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "noAI")
                {
                    def->tempPower.noAI = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "validTarget")
                {
                    def->tempPower.validTarget = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "canMove")
                {
                    def->tempPower.canMove = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "teleportMove")
                {
                    def->tempPower.teleportMove = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "teleportMoveOtherShip")
                {
                    def->tempPower.teleportMoveOtherShip = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "silenced")
                {
                    def->tempPower.silenced = EventsParser::ParseBoolean(tempEffectNode->value());
                }
                if (tempEffectName == "lowHealthThreshold")
                {
                    def->tempPower.lowHealthThreshold = boost::lexical_cast<float>(tempEffectNode->value());
                }
                if (tempEffectName == "noWarning")
                {
                    def->tempPower.noWarning = EventsParser::ParseBoolean(tempEffectNode->value());
                }
            }
        }
    }

    return def;
}

PowerResourceDefinition* CustomCrewManager::ParseAbilityResource(rapidxml::xml_node<char>* stat)
{
    PowerResourceDefinition* def;
    std::string name;

    if (stat->first_attribute("load"))
    {
        name = stat->first_attribute("load")->value();
        def = PowerResourceDefinition::GetByName(name);
        if (!def)
        {
            PowerResourceDefinition::AddUndefined(name); // allows the power to be defined later
        }
        return def;
    }

    PowerResourceDefinition* copyDef = nullptr;

    if (stat->first_attribute("copy"))
    {
        name = stat->first_attribute("copy")->value();
        copyDef = PowerResourceDefinition::GetByName(name);
    }

    if (stat->first_attribute("name"))
    {
        name = stat->first_attribute("name")->value();
        def = PowerResourceDefinition::AddNamedDefinition(name, copyDef);
    }
    else if (copyDef)
    {
        def = new PowerResourceDefinition(*copyDef);
    }
    else
    {
        def = new PowerResourceDefinition();
    }

    def->AssignIndex();

    if (!name.empty())
    {
        def->name = name;
    }

    for (auto effectNode = stat->first_node(); effectNode; effectNode = effectNode->next_sibling())
    {
        std::string effectName = std::string(effectNode->name());

        if (effectName == "groupName")
        {
            name = effectNode->value();
            def->AssignGroup(name);
        }

        if (effectName == "chargeReq")
        {
            def->chargeReq = new ActivatedPowerRequirements(ActivatedPowerRequirements::Type::CHARGE);

            ParsePowerRequirementsNode(effectNode, def->chargeReq);
        }
        if (effectName == "jumpCooldown")
        {
            std::string v = effectNode->value();

            if (v == "full") def->jumpCooldown = ActivatedPowerDefinition::JUMP_COOLDOWN_FULL;
            else if (v == "reset") def->jumpCooldown = ActivatedPowerDefinition::JUMP_COOLDOWN_RESET;
            else if (v == "continue") def->jumpCooldown = ActivatedPowerDefinition::JUMP_COOLDOWN_CONTINUE;
        }
        if (effectName == "disabledCooldown")
        {
            std::string v = effectNode->value();

            if (v == "full") def->disabledCooldown = ActivatedPowerDefinition::DISABLED_COOLDOWN_FULL;
            else if (v == "reset") def->disabledCooldown = ActivatedPowerDefinition::DISABLED_COOLDOWN_RESET;
            else if (v == "continue") def->disabledCooldown = ActivatedPowerDefinition::DISABLED_COOLDOWN_CONTINUE;
            else if (v == "pause") def->disabledCooldown = ActivatedPowerDefinition::DISABLED_COOLDOWN_PAUSE;
            else if (v == "zero") def->disabledCooldown = ActivatedPowerDefinition::DISABLED_COOLDOWN_ZERO;
        }
        if (effectName == "disabledCharges")
        {
            std::string v = effectNode->value();

            if (v == "full") def->disabledCharges = ActivatedPowerDefinition::DISABLED_COOLDOWN_FULL;
            else if (v == "reset") def->disabledCharges = ActivatedPowerDefinition::DISABLED_COOLDOWN_RESET;
            else if (v == "continue") def->disabledCharges = ActivatedPowerDefinition::DISABLED_COOLDOWN_CONTINUE;
            else if (v == "pause") def->disabledCharges = ActivatedPowerDefinition::DISABLED_COOLDOWN_PAUSE;
            else if (v == "zero") def->disabledCharges = ActivatedPowerDefinition::DISABLED_COOLDOWN_ZERO;
        }
        if (effectName == "initialCooldownFraction")
        {
            def->initialCooldownFraction = boost::lexical_cast<float>(effectNode->value());
        }
        if (effectName == "onDeath")
        {
            std::string v = effectNode->value();

            if (v == "continue") def->onDeath = ActivatedPowerDefinition::ON_DEATH_CONTINUE;
            else if (v == "cancel") def->onDeath = ActivatedPowerDefinition::ON_DEATH_CANCEL;
            else if (v == "reset") def->onDeath = ActivatedPowerDefinition::ON_DEATH_RESET;
        }
        if (effectName == "cooldown")
        {
            def->cooldown = boost::lexical_cast<float>(effectNode->value());
        }
        if (effectName == "powerCharges")
        {
            def->powerCharges = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "initialCharges")
        {
            def->initialCharges = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "respawnCharges")
        {
            def->respawnCharges = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "chargesPerJump")
        {
            def->chargesPerJump = boost::lexical_cast<int>(effectNode->value());
        }
        if (effectName == "cooldownColor")
        {
            ParseColorNode(def->cooldownColor, effectNode);
        }

        if (effectName == "sortOrder")
        {
            def->sortOrder = boost::lexical_cast<int>(effectNode->value());
        }

        if (effectName == "hideCooldown")
        {
            def->hideCooldown = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "hideCharges")
        {
            def->hideCharges = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "showTemporaryBars")
        {
            def->showTemporaryBars = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "showLinkedCooldowns")
        {
            def->showLinkedCooldowns = EventsParser::ParseBoolean(effectNode->value());
        }
        if (effectName == "showLinkedCharges")
        {
            def->showLinkedCharges = EventsParser::ParseBoolean(effectNode->value());
        }
    }

    return def;
}

void CustomCrewManager::ParsePowerRequirementsNode(rapidxml::xml_node<char> *node, ActivatedPowerRequirements *def)
{
    for (auto reqNode = node->first_node(); reqNode; reqNode = reqNode->next_sibling())
    {
        std::string req = reqNode->name();
        std::string reqVal = reqNode->value();

        if (req == "enemyShip")
        {
            def->enemyShip = true;
        }
        if (req == "playerShip")
        {
            def->playerShip = true;
        }
        if (req == "friendlyInRoom")
        {
            def->friendlyInRoom = true;
            def->checkRoomCrew = true;
        }
        if (req == "enemyInRoom")
        {
            def->enemyInRoom = true;
            def->checkRoomCrew = true;
        }
        if (req == "notMindControlled")
        {
            def->extraConditions.emplace_back(CrewExtraCondition::MIND_CONTROLLED, false);
        }
        if (req == "whiteList")
        {
            auto *whiteList = &def->whiteList;
            if (reqNode->first_attribute("enemy"))
            {
                whiteList = EventsParser::ParseBoolean(reqNode->first_attribute("enemy")->value()) ? &def->enemyWhiteList : &def->friendlyWhiteList;
            }
            if (reqNode->first_attribute("load"))
            {
                whiteList = new std::vector<std::string>(G_->GetBlueprints()->GetBlueprintList(reqNode->first_attribute("load")->value()));
            }
            for (auto crewChild = reqNode->first_node(); crewChild; crewChild = crewChild->next_sibling())
            {
                if (strcmp(crewChild->name(), "blueprintList") == 0 && crewChild->first_attribute("load"))
                {
                    std::vector<std::string> tempList = G_->GetBlueprints()->GetBlueprintList(crewChild->first_attribute("load")->value());
                    whiteList->insert(whiteList->end(),tempList.begin(),tempList.end());
                }
                else
                {
                    whiteList->push_back(crewChild->name());
                }
            }
            whiteList->shrink_to_fit();
            def->checkRoomCrew = true;
        }
        if (req == "blackList")
        {
            bool friendlyList = true;
            bool enemyList = true;
            if (reqNode->first_attribute("enemy"))
            {
                enemyList = EventsParser::ParseBoolean(reqNode->first_attribute("enemy")->value());
                friendlyList = !enemyList;
            }
            if (reqNode->first_attribute("load"))
            {
                if (friendlyList) def->friendlyBlackList = G_->GetBlueprints()->GetBlueprintList(reqNode->first_attribute("load")->value());
                if (enemyList) def->enemyBlackList = G_->GetBlueprints()->GetBlueprintList(reqNode->first_attribute("load")->value());
            }
            for (auto crewChild = reqNode->first_node(); crewChild; crewChild = crewChild->next_sibling())
            {
                if (strcmp(crewChild->name(), "blueprintList") == 0 && crewChild->first_attribute("load"))
                {
                    std::vector<std::string> tempList = G_->GetBlueprints()->GetBlueprintList(crewChild->first_attribute("load")->value());
                    if (friendlyList) def->friendlyBlackList.insert(def->friendlyBlackList.end(),tempList.begin(),tempList.end());
                    if (enemyList) def->enemyBlackList.insert(def->enemyBlackList.end(),tempList.begin(),tempList.end());
                }
                else
                {
                    if (friendlyList) def->friendlyBlackList.push_back(crewChild->name());
                    if (enemyList) def->enemyBlackList.push_back(crewChild->name());
                }
            }
            if (friendlyList) def->friendlyBlackList.shrink_to_fit();
            if (enemyList) def->enemyBlackList.shrink_to_fit();
            def->checkRoomCrew = true;
        }
        if (req == "systemInRoom")
        {
            def->systemInRoom = true;
            if (reqNode->first_attribute("damaged"))
            {
                def->systemDamaged = EventsParser::ParseBoolean(reqNode->first_attribute("damaged")->value());
            }
        }
        if (req == "hasClonebay")
        {
            def->hasClonebay = true;
        }
        if (req == "aiDisabled")
        {
            def->aiDisabled = true;
        }
        if (req == "outOfCombat")
        {
            def->outOfCombat = true;
        }
        if (req == "inCombat")
        {
            def->inCombat = true;
        }
        if (req == "isManning")
        {
            def->extraConditions.emplace_back(CrewExtraCondition::MANNING, true);
        }
        if (req == "requiredSystem")
        {
            def->requiredSystem = ShipSystem::NameToSystemId(reqNode->value());
            if (reqNode->first_attribute("functional"))
            {
                def->requiredSystemFunctional = EventsParser::ParseBoolean(reqNode->first_attribute("functional")->value());
            }
        }
        if (req == "minHealth")
        {
            def->minHealth = boost::lexical_cast<int>(reqVal);
        }
        if (req == "maxHealth")
        {
            def->maxHealth = boost::lexical_cast<int>(reqVal);
        }
        if (req == "extraConditions")
        {
            bool isOrCondition = reqNode->first_attribute("type") && strcmp(reqNode->first_attribute("type")->value(), "or") == 0;
            auto &extraConditions = isOrCondition ? def->extraOrConditions : def->extraConditions;
            CustomCrewManager::GetInstance()->ParseExtraConditionsNode(reqNode, extraConditions);
            if (isOrCondition)
            {
                if (reqNode->first_attribute("text"))
                {
                    def->extraOrConditionsTooltip.data = reqNode->first_attribute("text")->value();
                    def->extraOrConditionsTooltip.isLiteral = true;
                }
                else if (reqNode->first_attribute("textId"))
                {
                    def->extraOrConditionsTooltip.data = reqNode->first_attribute("textId")->value();
                    def->extraOrConditionsTooltip.isLiteral = false;
                }
                if (def->extraOrConditionsTooltip.data.empty())
                {
                    def->extraOrConditionsTooltip.data = "power_not_ready_generic";
                }
            }
        }
    }
}

void CustomCrewManager::ParseExtraConditionsNode(rapidxml::xml_node<char> *node, std::vector<std::pair<CrewExtraCondition,bool>> &extraConditions)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        if (strcmp(child->name(), "burning") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::BURNING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "suffocating") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::SUFFOCATING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "mindControlled") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::MIND_CONTROLLED, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "stunned") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::STUNNED, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "repairing") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::REPAIRING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "repairingSystem") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::REPAIRING_SYSTEM, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "repairingBreach") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::REPAIRING_BREACH, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "fighting") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::FIGHTING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "sabotaging") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::SABOTAGING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "shooting") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::SHOOTING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "moving") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::MOVING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "idle") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::IDLE, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "manning") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::MANNING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "firefighting") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::FIREFIGHTING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "dying") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::DYING, EventsParser::ParseBoolean(child->value()));
        }
        if (strcmp(child->name(), "teleporting") == 0)
        {
            extraConditions.emplace_back(CrewExtraCondition::TELEPORTING, EventsParser::ParseBoolean(child->value()));
        }
    }
}

CrewMember* CustomCrewManager::CreateCrewMember(CrewBlueprint* bp, int shipId, bool intruder)
{
    std::string race = bp->name;
    if (!IsRace(race))
        return 0;

    Pointf unk = Pointf(0.f, 0.f);
    CrewAnimation* animation = new CrewAnimation(shipId, race, unk, intruder);

    CrewDefinition* def = GetDefinition(race);

    CrewMember *crew;
    crew = new CrewMember(*bp, shipId, intruder, animation);


    return crew;
}

bool CustomCrewManager::IsRace(const std::string& race)
{
    return blueprintNames.find(race) != blueprintNames.end();
}

std::string CrewMember_Extend::GetRace()
{
    // Get effective race, including special race for ion intruder
    if (isIonDrone && CustomCrewManager::GetInstance()->IsRace("boarder_ion"))
    {
        return "boarder_ion";
    }
    return orig->species;
}

CrewDefinition *CrewMember_Extend::GetDefinition()
{
    if (isIonDrone)
    {
        if (CustomCrewManager::GetInstance()->IsRace("boarder_ion"))
        {
            return CustomCrewManager::GetInstance()->GetDefinition("boarder_ion");
        }
    }
    if (CustomCrewManager::GetInstance()->IsRace(orig->species))
    {
        return CustomCrewManager::GetInstance()->GetDefinition(orig->species);
    }
    return nullptr;
}

void CrewMember_Extend::TransformColors(CrewBlueprint& bp, CrewBlueprint *newBlueprint)
{
    int nLayers = std::min(bp.colorLayers.size(), newBlueprint->colorLayers.size());
    for (int i=0; i<nLayers; i++)
    {
        if (newBlueprint->colorLayers[i].size() == bp.colorLayers[i].size())
        {
            newBlueprint->colorChoices[i] = bp.colorChoices[i];
        }
        else if (newBlueprint->colorChoices[i] == -1)
        {
            newBlueprint->colorChoices[i] = random32() % newBlueprint->colorLayers[i].size();
        }
    }
    bp.colorLayers = newBlueprint->colorLayers;
    bp.colorChoices = newBlueprint->colorChoices;
}

bool CrewMember_Extend::TransformRace(const std::string& species)
{
    auto& equipList = G_->GetShipInfo(orig->iShipId)->equipList;

    auto it = equipList.find(orig->type);
    if (it != equipList.end())
    {
        if (it->second > 0) it->second -= 1;
    }

    auto newBlueprint = G_->GetBlueprints()->GetCrewBlueprint(species);

    orig->blueprint.powers = newBlueprint.powers;
    orig->blueprint.name = newBlueprint.name;
    orig->blueprint.desc = newBlueprint.desc;
    orig->blueprint.type = newBlueprint.type;
    orig->species = newBlueprint.name;
    orig->type = newBlueprint.name;

    if (g_transformColorMode == TransformColorMode::KEEP_INDICES)
    {
        originalColorRace = newBlueprint.name;

        TransformColors(orig->blueprint, &newBlueprint);

        orig->crewAnim->layerColors.clear();
        for (int i=0; i<orig->blueprint.colorLayers.size(); i++)
        {
            orig->crewAnim->layerColors.push_back(orig->blueprint.colorLayers[i][orig->blueprint.colorChoices[i]]);
        }
    }

    it = equipList.find(orig->type);
    if (it != equipList.end())
    {
        it->second += 1;
    }
    else
    {
        equipList[orig->type] = 1;
    }

    /*
    auto newCrewAnim = new CrewAnimation(orig->iShipId, orig->species, Pointf(0, 0), orig->iShipId == 1);

    orig->crewAnim->anims = newCrewAnim->anims;
    orig->crewAnim->baseStrip = newCrewAnim->baseStrip;
    orig->crewAnim->colorStrip = newCrewAnim->colorStrip;
    orig->crewAnim->bDrone = newCrewAnim->bDrone;
    orig->crewAnim->bGhost = newCrewAnim->bGhost;
    orig->crewAnim->race = newCrewAnim->race;

    delete newCrewAnim;
    */

    Initialize(orig->blueprint, orig->iShipId, orig->iShipId == 1, orig->crewAnim, true);

    if (orig->iShipId == 0)
    {
        G_->GetCApp()->gui->crewControl.ClearCrewBoxes();
        G_->GetCApp()->gui->crewControl.UpdateCrewBoxes();
    }

    StatBoostManager::GetInstance()->statCacheFrame++; // resets stat cache in case game is paused
    return true;
}

HOOK_METHOD(CrewMember, Restart, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::Restart -> Begin (CustomCrew.cpp)\n")
    // Occurs when a crewmember is cloned or when a crew drone is deployed/redeployed

    auto ex = CM_EX(this);

    for (ActivatedPower *power : ex->crewPowers)
    {
        if (power->def->onDeath == ActivatedPowerDefinition::ON_DEATH_CANCEL || power->def->onDeath == ActivatedPowerDefinition::ON_DEATH_RESET)
        {
            power->CancelPower(true);
        }
        if (power->enabled || power->def->disabledCharges == ActivatedPowerDefinition::DISABLED_COOLDOWN_CONTINUE)
        {
            power->powerCharges.first = std::max(0,std::min(power->powerCharges.first + power->def->respawnCharges, power->powerCharges.second));
        }
    }
    for (ActivatedPowerResource *power : ex->powerResources)
    {
        if (power->enabled || power->def->disabledCharges == PowerResourceDefinition::DISABLED_COOLDOWN_CONTINUE)
        {
            power->powerCharges.first = std::max(0,std::min(power->powerCharges.first + power->def->respawnCharges, power->powerCharges.second));
        }
    }

    super();
}

void CrewAnimation_Extend::OnInit(const std::string& name, Pointf position, bool enemy)
{
    /*
    CustomCrewManager *custom = CustomCrewManager::GetInstance();


    if (custom->IsRace(orig->race))
    {
        auto def = custom->GetDefinition(orig->race);
    }
    */
}



//=================================

static bool blockAddSoundQueue = false;

HOOK_METHOD(Animation, AddSoundQueue, (int frame, const std::string& str) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Animation::AddSoundQueue -> Begin (CustomCrew.cpp)\n")
    if (blockAddSoundQueue) return;

    super(frame, str);
}

HOOK_METHOD_PRIORITY(CrewMember, constructor, -899, (CrewBlueprint& bp, int shipId, bool enemy, CrewAnimation *animation) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::constructor -> Begin (CustomCrew.cpp)\n")
    for (unsigned int i=0; i<bp.colorLayers.size(); ++i)
    {
        if (bp.colorChoices[i] >= (int) bp.colorLayers[i].size()) bp.colorLayers[i].resize(bp.colorChoices[i]+1, GL_Color(0.0,0.0,0.0,0.0));
    }

    super(bp, shipId, enemy, animation);

    CrewMember_Extend* ex = CM_EX(this);
    if (ex->originalColorRace.empty()) ex->originalColorRace = species;
    if (ex->originalRace.empty()) ex->originalRace = species;
    ex->Initialize(bp, shipId, enemy, animation);
}

static bool g_forceNoSlot = false;

//Crew animation statuses:
// 0 - walk
// 1 - punch
// 2 - repair
// 3 - death
// 4 - fire
// 5 - ??? (unused?)
// 6 - teleport
// 7 - shoot
// 8 - type
// 9 - portrait

void CrewMember_Extend::Initialize(CrewBlueprint& bp, int shipId, bool enemy, CrewAnimation *animation, bool isTransform)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    if (custom->IsRace(orig->species))
    {
        auto def = custom->GetDefinition(orig->species);

        if (!isTransform)
        {
            // With the new crew power construct we don't want to recalculate crew abilities on transform because it might happen while looping over abilities
            // But we still want to calculate them if this is a new crewmember
            CalculatePowerDef();
        }

        auto aex = CMA_EX(orig->crewAnim);

        if (!aex->isIonDrone)
        {
            Pointf lastPosition = Pointf(0, 0);
            std::vector<GL_Color> layerColors = std::vector<GL_Color>();
            std::vector<GL_Texture*> layerStrips = std::vector<GL_Texture*>();
            bool male = false;
            bool uniqueBoolShoot = false;
            bool uniqueBoolFire = false;
            bool uniqueBoolSparked = true;

            bool replaceLayers = false;

            if (animation)
            {
                layerColors = animation->layerColors;
                layerStrips = animation->layerStrips;
                male = animation->bMale;
                replaceLayers = true;
                lastPosition = animation->lastPosition;

                if (aex->crewAnimationType == "rock")
                {
                    uniqueBoolFire = animation->uniqueBool1;
                    uniqueBoolShoot = animation->uniqueBool2;
                }
                else if (aex->crewAnimationType == "mantis")
                {
                    uniqueBoolShoot = animation->uniqueBool1;
                }
                else if (aex->crewAnimationType == "repair")
                {
                    uniqueBoolSparked = animation->uniqueBool1;
                }
            }

            std::string animSheet = def->animSheet[male?1:0];
            if (animSheet.empty()) animSheet = bp.name;

            if (def->animBase == "rock")
            {
                blockAddSoundQueue = true;
                orig->crewAnim = new RockAnimation(animSheet, shipId, lastPosition, enemy);
                aex = CMA_EX(orig->crewAnim);
                aex->crewAnimationType = "rock";
                blockAddSoundQueue = false;
            }
            else if (def->animBase == "mantis")
            {
                orig->crewAnim = new MantisAnimation;
                orig->crewAnim->constructor(shipId, animSheet, lastPosition, enemy);
                aex = CMA_EX(orig->crewAnim);
                aex->isMantisAnimation = true;
                aex->crewAnimationType = "mantis";
            }
            else if (def->animBase == "repair")
            {
                orig->crewAnim = new RepairAnimation(shipId, animSheet, lastPosition, enemy);
                aex = CMA_EX(orig->crewAnim);
                aex->crewAnimationType = "repair";
            }
            else
            {
                orig->crewAnim = new CrewAnimation(shipId, animSheet, lastPosition, enemy);
                aex = CMA_EX(orig->crewAnim);
            }

            orig->crewAnim->bMale = male;

            if (replaceLayers && !orig->crewAnim->bDrone)
            {
                orig->crewAnim->layerColors = layerColors;

                if (g_transformColorMode == TransformColorMode::KEEP_COLORS)
                {
                    auto bpM = G_->GetBlueprints();
                    auto it = bpM->crewBlueprints.find(bp.name);
                    if (it != bpM->crewBlueprints.end() && it->second.colorLayers.size() < orig->crewAnim->layerColors.size())
                    {
                        orig->crewAnim->layerColors.resize(it->second.colorLayers.size());
                    }
                    orig->crewAnim->SetupStrips();

                    orig->crewAnim->layerColors = layerColors;
                }
                else
                {
                    orig->crewAnim->SetupStrips();
                }
            }
            else if (orig->crewAnim->bDrone)
            {
                orig->crewAnim->SetupStrips();
            }

            if (animation)
            {
                orig->crewAnim->direction = animation->direction;
                orig->crewAnim->sub_direction = animation->sub_direction;
                orig->crewAnim->status = animation->status;
                orig->crewAnim->moveDirection = animation->moveDirection;
                orig->crewAnim->shots = std::move(animation->shots);
                orig->crewAnim->shootTimer.currTime = animation->shootTimer.currTime;
                orig->crewAnim->shootTimer.currGoal = animation->shootTimer.currGoal;
                orig->crewAnim->shootTimer.loop = animation->shootTimer.loop;
                orig->crewAnim->shootTimer.running = animation->shootTimer.running;
                orig->crewAnim->punchTimer.currTime = animation->punchTimer.currTime;
                orig->crewAnim->punchTimer.currGoal = animation->punchTimer.currGoal;
                orig->crewAnim->punchTimer.loop = animation->punchTimer.loop;
                orig->crewAnim->punchTimer.running = animation->punchTimer.running;
                orig->crewAnim->target = animation->target;
                orig->crewAnim->fDamageDone = animation->fDamageDone;
                orig->crewAnim->bFrozen = animation->bFrozen;
                orig->crewAnim->bTyping = animation->bTyping;
                orig->crewAnim->currentShip = animation->currentShip;
                orig->crewAnim->forcedAnimation = animation->forcedAnimation;
                orig->crewAnim->forcedDirection = animation->forcedDirection;
                orig->crewAnim->bStunned = animation->bStunned;
                orig->crewAnim->bDoorTarget = animation->bDoorTarget;

                //orig->crewAnim->anims.at(animation->direction).at(animation->status).SetProgress(animation->anims.at(animation->direction).at(animation->status).tracker.Progress(-1.f));

                if (aex->crewAnimationType == "rock")
                {
                    orig->crewAnim->uniqueBool1 = uniqueBoolFire;
                    orig->crewAnim->uniqueBool2 = uniqueBoolShoot;
                }
                else if (aex->crewAnimationType == "mantis")
                {
                    orig->crewAnim->uniqueBool1 = uniqueBoolShoot;
                }
                else if (aex->crewAnimationType == "repair")
                {
                    orig->crewAnim->uniqueBool1 = uniqueBoolSparked;
                }

                int numDirections = std::min(animation->anims.size(), orig->crewAnim->anims.size());
                for (int i=0; i<numDirections; ++i)
                {
                    int numStatus = std::min(animation->anims[i].size(), orig->crewAnim->anims[i].size());
                    for (int j=0; j<numStatus; ++j)
                    {
                        Animation &anim1 = animation->anims[i][j];
                        Animation &anim2 = orig->crewAnim->anims[i][j];
                        float animProgress = anim1.tracker.time != 0.f ? anim1.tracker.current_time/anim1.tracker.time : 0.f;

                        anim2.tracker.current_time = anim2.tracker.time * animProgress;
                        anim2.tracker.currentDelay = anim2.tracker.loopDelay * (anim1.tracker.loopDelay != 0.f ? anim1.tracker.currentDelay/anim1.tracker.loopDelay : 1.f);
                        anim2.tracker.loop = anim1.tracker.loop;
                        anim2.tracker.running = anim1.tracker.running;
                        anim2.tracker.reverse = anim1.tracker.reverse;
                        anim2.tracker.done = anim1.tracker.done;
                        anim2.tracker.running = anim1.tracker.running;

                        anim2.fadeOut = anim2.startFadeOut * (anim1.startFadeOut != 0.f ? anim1.fadeOut/anim1.startFadeOut : 1.f);

                        if (anim2.randomizeFrames)
                        {
                            if (anim2.info.numFrames != 0)
                            {
                                anim2.currentFrame = anim1.currentFrame % anim2.info.numFrames;
                            }
                        }
                        else
                        {
                            if (animProgress >= 1.f)
                            {
                                anim2.currentFrame = anim2.info.numFrames;
                            }
                            else if (animProgress < 0.f)
                            {
                                anim2.currentFrame = 0;
                            }
                            else
                            {
                                anim2.currentFrame = animProgress * anim2.info.numFrames;
                            }
                        }
                    }
                }
            }

            if (def->repairSoundFrame != -1 && def->repairSounds.size() > 0 && !enemy)
            {
                for (auto sound : def->repairSounds)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        orig->crewAnim->anims[i][2].AddSoundQueue(def->repairSoundFrame, sound);
                    }
                }
            }

            delete animation;
            animation = orig->crewAnim;
        }

        if (def->shootTimer.first != -1)
        {
            orig->crewAnim->shootTimer.minTime = def->shootTimer.first;
            orig->crewAnim->shootTimer.maxTime = def->shootTimer.second;
        }

        float limitGoal = orig->crewAnim->shootTimer.maxTime / 1000.f;
        if (orig->crewAnim->shootTimer.currGoal > limitGoal)
        {
            orig->crewAnim->shootTimer.currTime *= limitGoal/orig->crewAnim->shootTimer.currGoal;
            orig->crewAnim->shootTimer.currGoal = limitGoal;
        }
        else
        {
            limitGoal = orig->crewAnim->shootTimer.minTime / 1000.f;
            if (orig->crewAnim->shootTimer.currGoal < limitGoal)
            {
                orig->crewAnim->shootTimer.currTime *= limitGoal/orig->crewAnim->shootTimer.currGoal;
                orig->crewAnim->shootTimer.currGoal = limitGoal;
            }
        }

        if (def->punchTimer.first != -1)
        {
            orig->crewAnim->punchTimer.minTime = def->punchTimer.first;
            orig->crewAnim->punchTimer.maxTime = def->punchTimer.second;
        }

        limitGoal = orig->crewAnim->punchTimer.maxTime / 1000.f;
        if (orig->crewAnim->punchTimer.currGoal > limitGoal)
        {
            float goalMult = limitGoal/orig->crewAnim->punchTimer.currGoal;
            orig->crewAnim->punchTimer.currTime *= goalMult;
            orig->crewAnim->punchTimer.currGoal = limitGoal;
            orig->crewAnim->anims[orig->crewAnim->direction][1].tracker.time *= goalMult;
            orig->crewAnim->anims[orig->crewAnim->direction][1].tracker.current_time *= goalMult;
        }
        else
        {
            limitGoal = orig->crewAnim->punchTimer.minTime / 1000.f;
            if (orig->crewAnim->punchTimer.currGoal < limitGoal)
            {
                float goalMult = limitGoal/orig->crewAnim->punchTimer.currGoal;
                orig->crewAnim->punchTimer.currTime *= goalMult;
                orig->crewAnim->punchTimer.currGoal = limitGoal;
                orig->crewAnim->anims[orig->crewAnim->direction][1].tracker.time *= goalMult;
                orig->crewAnim->anims[orig->crewAnim->direction][1].tracker.current_time *= goalMult;
            }
        }

        aex->canPunch = def->canPunch;

        float passiveHealAmount = CalculateStat(CrewStat::PASSIVE_HEAL_AMOUNT, def);
        float truePassiveHealAmount = CalculateStat(CrewStat::TRUE_PASSIVE_HEAL_AMOUNT, def);
        if (passiveHealAmount != 0.f || truePassiveHealAmount != 0.f)
        {
            float passiveHealDelay = CalculateStat(CrewStat::PASSIVE_HEAL_DELAY, def);
            if (passiveHealDelay > 0 && passiveHealTimer == nullptr)
            {
                passiveHealTimer = new TimerHelper();
                passiveHealTimer->Start(passiveHealDelay);
            }
        }

        UpdateAbilityStatBoosts(def);

        auto skillsDef = def->skillsDef;
        noSlot = def->noSlot || g_forceNoSlot;

        std::string skillOrder[6] = {"piloting", "engines", "shields", "weapons", "repair", "combat"};

        for (int i = 0; i < orig->blueprint.skillLevel.size(); i++)
        {
            orig->blueprint.skillLevel[i].first = ((float)orig->blueprint.skillLevel[i].first / orig->blueprint.skillLevel[i].second) * (skillsDef.skills[skillOrder[i]].requirement * 2);
            orig->blueprint.skillLevel[i].second = skillsDef.skills[skillOrder[i]].requirement * 2;
            int defaultSkillLevel = CalculateStat(CrewStat::DEFAULT_SKILL_LEVEL, def);

            if (orig->blueprint.skillLevel[i].first < (defaultSkillLevel / 2.f) * orig->blueprint.skillLevel[i].second)
            {
                orig->blueprint.skillLevel[i].first = ((defaultSkillLevel / 2.f) * orig->blueprint.skillLevel[i].second);
            }
        }

        g_forceNoSlot = false;

        aex->crew = orig;
    }
}

HOOK_METHOD(CrewBlueprint, RandomSkills, (int worldLevel) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewBlueprint::RandomSkills -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();
    super(worldLevel);


    if (custom->IsRace(name))
    {
        auto skillsDef = custom->GetDefinition(name)->skillsDef;

        std::string skillOrder[6] = {"piloting", "engines", "shields", "weapons", "repair", "combat"};

        for (int i = 0; i < skillLevel.size(); i++)
        {

            skillLevel[i].first = ((float)skillLevel[i].first / skillLevel[i].second) * (skillsDef.skills[skillOrder[i]].requirement * 2);
            skillLevel[i].second = skillsDef.skills[skillOrder[i]].requirement * 2;
        }
    }
}

HOOK_METHOD_PRIORITY(CrewMember, UpdateHealth, 2000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::UpdateHealth -> Begin (CustomCrew.cpp)\n")
    if (G_->GetCApp()->menu.shipBuilder.bOpen) return;

    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto ex = CM_EX(this);

//    using std::chrono::steady_clock;
//    using std::chrono::duration_cast;
//    using std::chrono::duration;
//    using std::chrono::milliseconds;
//    auto t1 = steady_clock::now();

    auto def = custom->GetDefinition(this->species);

//    auto t2 = steady_clock::now();
//    duration<double, std::nano> ms_double = t2 - t1;
//    std::cout << "Definition time: " << ms_double.count();

    if (iOnFire && CanBurn())
    {
        float fireMultiplier = 1.f;

        if (custom->IsRace(species))
        {
            fireMultiplier = ex->CalculateStat(CrewStat::FIRE_DAMAGE_MULTIPLIER, def);
        }

        DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * (iOnFire * -0.133f * fireMultiplier));
    }

    if (bSuffocating && !IsAnaerobic())
    {
        float mod = 1.f;

        ShipObject* shipObject = GetShipObject();

        ShipInfo* shipInfo = G_->GetShipInfo(iShipId);

        if (shipObject->HasAugmentation("O2_MASKS"))
        {
            mod = shipObject->GetAugmentationValue("O2_MASKS");
        }

        float multiplier = GetSuffocationMultiplier();

        DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * -0.4f * mod * multiplier);
    }

    float mod = 1.f;
    if (IsDrone())
    {
        mod = 0.2f;
    }


    if (custom->IsRace(species))
    {
        mod = ex->CalculateStat(CrewStat::HEAL_SPEED_MULTIPLIER, def);
    }

    float medbayRate = fMedbay;
    if (medbayRate > 1.f)
    {
        medbayRate = (medbayRate - 1.f) * 1.5f;
    }

    DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * (medbayRate + ex->extraMedbay) * mod * 0.4f);

    if (custom->IsRace(species))
    {
        float passiveHealAmount = ex->CalculateStat(CrewStat::PASSIVE_HEAL_AMOUNT, def);
        float healAmount = ex->CalculateStat(CrewStat::ACTIVE_HEAL_AMOUNT, def);
        float trueHealAmount = ex->CalculateStat(CrewStat::TRUE_HEAL_AMOUNT, def);
        float truePassiveHealAmount = ex->CalculateStat(CrewStat::TRUE_PASSIVE_HEAL_AMOUNT, def);

        if (healAmount != 0.f)
        {
            if (healAmount > 0.f && health.first != health.second)
            {
                fMedbay += 0.0000000001;
            }
            DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * healAmount * mod * 0.0625f);
        }
        if (ex->isHealing && passiveHealAmount != 0.f && health.first != health.second)
        {
            if (passiveHealAmount > 0.f && health.first != health.second)
            {
                fMedbay += 0.0000000001;
            }
            DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * passiveHealAmount * mod * 0.0625f);
        }
        if (trueHealAmount != 0.f)
        {
            if (trueHealAmount > 0.f && health.first != health.second)
            {
                fMedbay += 0.0000000001;
            }
            DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * trueHealAmount * 0.0625f);
        }
        if (ex->isHealing && truePassiveHealAmount != 0.f && health.first != health.second)
        {
            if (truePassiveHealAmount > 0.f && health.first != health.second)
            {
                fMedbay += 0.0000000001;
            }
            DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * truePassiveHealAmount * 0.0625f);
        }
    }

    //super();
}

bool CrewMember_Extend::IsInvulnerable()
{
    // Determine if this crewmember has any temporary effect that makes them invulnerable
    for (ActivatedPower *power : crewPowers)
    {
        if (power->temporaryPowerActive && power->def->tempPower.invulnerable)
        {
            return true;
        }
    }
    return false;
}

// rewrite to modify lowCrewHealth behavior
HOOK_METHOD_PRIORITY(CrewMember, DirectModifyHealth, 9999, (float healthMod)->bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::DirectModifyHealth -> Begin (CustomCrew.cpp)\n")
    if (health.first > 0.f)
    {
        float newHealth = health.first + healthMod;
        if (newHealth < 0.f)
        {
            newHealth = 0.f;
        }
        else if (newHealth > health.second)
        {
            newHealth = health.second;
        }
        float originalHealth = health.first;
        health.first = newHealth;
        if (std::abs(healthMod) > 0.f && newHealth != health.second)
        {
            lastHealthChange = 2.f;
        }
        if (healthMod < 0.f)
        {
            lastDamageTimer = -2.f;
        }
        if (newHealth <= 0.f && iOnFire != 0 && bFighting && (blockingDoor != (Door*)crewTarget) && iShipId != 0 && currentShipId != 0 && IsCrew() && crewTarget && crewTarget->iShipId == 0)
        {
            G_->GetAchievementTracker()->SetAchievement("ACH_ROCK_FIRE", false, true);
        }
        if (healthMod < 0.f)
        {
            auto def = CustomCrewManager::GetInstance()->GetDefinition(species);
            float lowHealthThreshold = CM_EX(this)->CalculateStat(CrewStat::LOW_HEALTH_THRESHOLD, def);
            lowHealthThreshold = std::min(lowHealthThreshold, health.second * def->lowHealthThresholdPercentage);
            if (static_cast<int>(newHealth) <= lowHealthThreshold && static_cast<int>(originalHealth) > lowHealthThreshold && iShipId == 0 && IsCrew())
            {
                G_->GetSoundControl()->PlaySoundMix("lowCrewHealth", -1.f, false);
            }
        }
        return newHealth <= 0.f;
    }
    return false;
}

// rewrite to modify lowCrewHealth behavior
HOOK_METHOD_PRIORITY(CrewMember, OnRenderHealth, 9999, ()->void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::OnRenderHealth -> Begin (CustomCrew.cpp)\n")
    if (!bDead && crewAnim->status != 3)
    {
        crewAnim->OnRenderProps();
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(0.f, PositionShift());
        if (healing.tracker.running)
        {
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(x - std::round(scale * 17.f), y - std::round(scale * 20.f));
            CSurface::GL_Scale(scale, scale, 1.f);
            healing.OnRender(1.f, GL_Color(1.f, 1.f, 1.f, 1.f), false);
            CSurface::GL_PopMatrix();
        }
        mindControlled.position.x = stunIcon.position.x = x - 8.f;
        mindControlled.position.y = stunIcon.position.y = y - 17.f;
        GL_Color healthBarColor = iShipId == 0 ? GL_Color(0.f, 1.f, 0.f, 1.f) : (G_->GetSettings()->colorblind ? GL_Color(0.f, 147.f / 255, 224.f / 255, 1.f) : GL_Color(1.f, 0.f, 0.f, 1.f));
        auto def = CustomCrewManager::GetInstance()->GetDefinition(species);
        float lowHealthThreshold = CM_EX(this)->CalculateStat(CrewStat::LOW_HEALTH_THRESHOLD, def);
        lowHealthThreshold = std::min(lowHealthThreshold, health.second * def->lowHealthThresholdPercentage);
        if (selectionState > 0 || lastHealthChange > 0 || (health.first < health.second * 0.55f) || (health.first <= lowHealthThreshold))
        {
            flashHealthTracker.Update();
            CachedImage& healthBoxActive = (health.first <= lowHealthThreshold && flashHealthTracker.Progress(-1.f) < 0.5f) ? healthBoxRed : healthBox;
            Pointf healthBoxLoc = Pointf(x - std::round(scale * 18.f), y - 2.f - std::round(scale * 15.f));
            healthBoxActive.SetPosition(healthBoxLoc.x, healthBoxLoc.y);
            healthBoxActive.SetScale(scale, scale);
            healthBoxActive.OnRender(GL_Color(1.f, 1.f, 1.f, 1.f));
            healthBar.SetPosition(healthBoxLoc.x + std::round(scale * 5.f), healthBoxLoc.y + std::round(scale * 3.f));
            healthBar.SetSize(static_cast<int>(std::round(health.first / health.second * scale * 25.f)), static_cast<int>(std::round(scale * 3.f)));
            healthBar.OnRender(healthBarColor);
            mindControlled.position.x = stunIcon.position.x = x - 27.f;
            mindControlled.position.y = stunIcon.position.y = y - 20.f;
        }
        if (fStunTime > 0)
        {
            stunIcon.OnRender(1.f, GL_Color(1.f, 1.f, 0.f, 1.f), false);
        }
        else if (bMindControlled)
        {
            mindControlled.OnRender(1.f, healthBarColor, false);
        }
        if (levelUp.running && iShipId == 0)
        {
            GL_Texture *skillIcon = G_->GetBlueprints()->GetSkillIcon(lastLevelUp, true);
            float animProgress = levelUp.Progress(-1.f);
            GL_Color skillColorFadeOut = blueprint.GetCurrentSkillColor(lastLevelUp);
            skillColorFadeOut.a = 1.f - animProgress * 2.4f;
            CSurface::GL_BlitPixelImage(skillIcon, x - animProgress * 96.f, y - animProgress * 96.f - 14.f, animProgress * 192.f, animProgress * 192.f, 0.f, skillColorFadeOut, false);
            G_->GetResources()->RenderImage(skillIcon, x - 16.f, y - 30.f, 0.f, blueprint.GetCurrentSkillColor(lastLevelUp), animProgress * 2.4f, false);
        }
        CSurface::GL_PopMatrix();
    }
}

HOOK_METHOD_PRIORITY(CrewMember, DirectModifyHealth, 1000, (float healthMod) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::DirectModifyHealth -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();
    CrewMember_Extend* ex = CM_EX(this);
    auto def = custom->GetDefinition(this->species);

    if (custom->IsRace(species))
    {
        if (healthMod < 0.f)
        {
            if (ex->IsInvulnerable())
            {
                return false;
            }
            else
            {
                healthMod *= ex->CalculateStat(CrewStat::ALL_DAMAGE_TAKEN_MULTIPLIER, def);
            }
        }

        if (health.first > 0.f && health.first + healthMod <= 0.f) // will die
        {
            ex->CalculateStat(CrewStat::DEATH_EFFECT, def);

            if (ex->hasDeathExplosion)
            {
                ExplosionDefinition *explosionDef = &ex->deathEffectChange;
                if (!explosionDef->transformRace.empty())
                {
                    health.first = 0.f; // prevent any damage from the following effects from applying, avoids infinite loops etc.

                    // we explode as part of the transform as the crewmember won't actually die and explode normally
                    bool oldBlockDamageArea = blockDamageArea;
                    blockDamageArea = false;

                    ex->triggerExplosion = true;
                    Damage damage = this->GetRoomDamage();
                    if (damage.ownerId != -1)
                    {
                        ShipManager *crewShip = G_->GetShipManager(currentShipId);
                        if (crewShip)
                        {
                            CustomDamage* oldDamage = CustomDamageManager::currentWeaponDmg;
                            CustomDamageManager::currentWeaponDmg = nullptr; // if triggered by a projectile we don't want that projectile's CustomDamage for this effect

                            crewShip->DamageArea(Pointf(x, y), damage, true);

                            CustomDamageManager::currentWeaponDmg = oldDamage;
                        }
                    }

                    blockDamageArea = oldBlockDamageArea;

                    if (explosionDef->transformRaceDeathSound)
                    {
                        std::string deathSound = crewAnim->GetDeathSound();
                        G_->GetSoundControl()->PlaySoundMix(deathSound, -1.f, false);
                    }
                    ex->originalRace = explosionDef->transformRace;
                    ex->TransformRace(explosionDef->transformRace);
                    StatBoostManager::GetInstance()->statCacheFrame++; // resets stat cache for the death transform
                    auto newDef = custom->GetDefinition(explosionDef->transformRace); // use the new race for subsequent stat checks

                    health.first = ex->CalculateStat(CrewStat::MAX_HEALTH, newDef) * explosionDef->transformRaceHealthFraction + explosionDef->transformRaceHealth;
                    if (health.first <= 0.f) health.first = 1.0e-9f;
                    if (health.first > health.second) health.first = health.second;

                    if (ex->passiveHealTimer)
                    {
                        ex->isHealing = false;
                        ex->passiveHealTimer->Start(ex->CalculateStat(CrewStat::PASSIVE_HEAL_DELAY, newDef));
                    }

                    return false;
                }
            }
        }
    }

    bool ret = super(healthMod);

    if (custom->IsRace(species) && healthMod < 0.f && ex->passiveHealTimer)
    {
        ex->isHealing = false;
        ex->passiveHealTimer->Start(ex->CalculateStat(CrewStat::PASSIVE_HEAL_DELAY, def));
    }

	return ret;
}
HOOK_METHOD(CrewMember, SetHealthBoost, (int _healthBoost) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::SetHealthBoost -> Begin (CustomCrew.cpp)\n")
    int delta = _healthBoost - healthBoost;
    if (delta != 0)
    {
        health.second += delta;
        if (delta > 0)
        {
            health.first += delta;
        }
        else
        {
            health.first = std::min(health.first, health.second);
        }
        healthBoost = _healthBoost;
    }
    GetMaxHealth();
}
HOOK_METHOD_PRIORITY(CrewMember, OnLoop, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::OnLoop -> Begin (CustomCrew.cpp)\n")
    super();

    auto custom = CustomCrewManager::GetInstance();
    CrewMember_Extend* ex = CM_EX(this);

    // custom teleport
    if (ex->customTele.teleporting)
    {
        // end teleport
        if (crewAnim->status != 6)
        {
            ex->customTele.teleporting = false;
        }
    }

    // Death/expiration timer
    if (ex->deathTimer)
    {
        ex->deathTimer->Update();
        if (ex->deathTimer->Done())
        {
            health.first = 0.f;
        }
    }

    if (custom->IsRace(species))
    {
        auto def = custom->GetDefinition(species);

        // Passive healing
        float delay = ex->CalculateStat(CrewStat::PASSIVE_HEAL_DELAY, def);
        if (!ex->passiveHealTimer && delay != 0)
        {
            ex->passiveHealTimer = new TimerHelper();
            ex->passiveHealTimer->Start(delay);
        }
        else if (ex->passiveHealTimer && delay == 0)
        {
            delete ex->passiveHealTimer;
            ex->passiveHealTimer = nullptr;
            ex->isHealing = true;
        }
        else if (ex->passiveHealTimer)
        {
            ex->passiveHealTimer->Update();
            if (ex->passiveHealTimer->Done())
            {
                ex->isHealing = true;
            }
        }
        else
        {
            ex->isHealing = true;
        }

        // Stun modifier
        if (fStunTime != 0.f)
        {
            if (fStunTime < ex->prevStun)
            {
                float stunMultiplier = ex->CalculateStat(CrewStat::STUN_MULTIPLIER, def);

                if (stunMultiplier > 0.f)
                {
                    fStunTime = ex->prevStun - ((ex->prevStun - fStunTime) * (1.f / stunMultiplier));
                    if (fStunTime < 0.f)
                    {
                        fStunTime = 0.f;
                    }
                }
                else
                {
                    fStunTime = 0.f;
                }
            }
        }

        ex->prevStun = fStunTime;

        // CanMove/rooted effect
        bool canMove;
        ex->CalculateStat(CrewStat::CAN_MOVE, def, &canMove);
        if (!canMove)
        {
            ex->prevCanMove = false;

            if (!IsDead() && !OutOfGame())
            {
                ShipGraph* graph = ShipGraph::GetShipInfo(currentShipId);

                Slot currentLocationSlot;
                currentLocationSlot.roomId = iRoomId;
                if (iRoomId != -1)
                {
                    Room *room = graph->rooms[iRoomId];
                    currentLocationSlot.slotId = (((int)x - room->rect.x) / 35 + (room->rect.w / 35) * (((int)y - room->rect.y) / 35));
                    if (currentLocationSlot.slotId < 0 || currentLocationSlot.slotId >= (room->rect.w / 35)*(room->rect.h / 35))
                    {
                        currentLocationSlot.roomId = -1;
                    }
                    else
                    {
                        currentLocationSlot.worldLocation = graph->GetSlotWorldPosition(currentLocationSlot.slotId, currentLocationSlot.roomId);
                    }
                }

                if (currentLocationSlot.roomId != -1 && (currentLocationSlot.roomId != currentSlot.roomId || currentLocationSlot.slotId != currentSlot.slotId))
                {
                    ShipManager *ship = G_->GetShipManager(currentShipId);
                    CrewMember *moveCrew = nullptr;
                    for (CrewMember *otherCrew : ship->vCrewList)
                    {
                        if (otherCrew != this && otherCrew->currentSlot.roomId == currentLocationSlot.roomId && otherCrew->currentSlot.slotId == currentLocationSlot.slotId && otherCrew->intruder == intruder)
                        {
                            moveCrew = otherCrew;
                            break;
                        }
                    }
                    if (moveCrew)
                    {
                        bool moveCrewCanMove;
                        CM_EX(moveCrew)->CalculateStat(CrewStat::CAN_MOVE, &moveCrewCanMove);

                        if (moveCrewCanMove)
                        {
                            moveCrew->EmptySlot();
                        }
                        else
                        {
                            moveCrew = nullptr;
                        }
                    }
                    EmptySlot();

                    currentCrewLoop = nullptr; // bypass canMove to force movement
                    MoveToRoom(currentLocationSlot.roomId, currentLocationSlot.slotId, true);
                    currentCrewLoop = this;

                    if (moveCrew)
                    {
                        moveCrew->MoveToRoom(currentLocationSlot.roomId, currentLocationSlot.slotId, true);
                    }
                }

                if (currentSlot.roomId != -1)
                {
                    currentSlot.worldLocation = graph->GetSlotWorldPosition(currentSlot.slotId, currentSlot.roomId);

                    if (std::fabs(currentSlot.worldLocation.x - x) < 17.f && std::fabs(currentSlot.worldLocation.y - y) < 17.f)
                    {
                        if (def->snapToSlot)
                        {
                            x = currentSlot.worldLocation.x;
                            y = currentSlot.worldLocation.y;
                            path.finish.x = currentSlot.worldLocation.x;
                            path.finish.y = currentSlot.worldLocation.y;
                            goal_x = currentSlot.worldLocation.x;
                            goal_y = currentSlot.worldLocation.y;
                        }
                        else
                        {
                            float maxDistance;
                            if (fStunTime > 0.f)
                            {
                                maxDistance = 10000.f;
                            }
                            else
                            {
                                switch (crewAnim->status)
                                {
                                case 0: // walk/idle
                                case 2: // repair
                                case 4: // fire
                                case 7: // shoot
                                    maxDistance = 10.f;
                                    break;
                                case 1: // punch
                                case 8: // type
                                    maxDistance = 0.f;
                                    break;
                                default:
                                    maxDistance = 10000.f;
                                    break;
                                }
                            }

                            currentSlot.worldLocation.x = std::max(currentSlot.worldLocation.x-maxDistance,std::min(x,currentSlot.worldLocation.x+maxDistance));
                            currentSlot.worldLocation.y = std::max(currentSlot.worldLocation.y-maxDistance,std::min(y,currentSlot.worldLocation.y+maxDistance));

                            path.finish.x = currentSlot.worldLocation.x;
                            path.finish.y = currentSlot.worldLocation.y;
                            goal_x = currentSlot.worldLocation.x;
                            goal_y = currentSlot.worldLocation.y;
                        }
                    }
                }
            }
        }
        else if (!ex->prevCanMove)
        {
            ex->prevCanMove = true;
            if (currentSlot.roomId != -1)
            {
                ShipGraph* graph = ShipGraph::GetShipInfo(currentShipId);
                currentSlot.worldLocation = graph->GetSlotWorldPosition(currentSlot.slotId, currentSlot.roomId);
                SetRoomPath(currentSlot.slotId, currentSlot.roomId);
            }
        }

        // Crew ability loop/activation
        ex->CalculatePowerDef();
        if (!G_->GetCApp()->menu.shipBuilder.bOpen)
        {
            if (!ex->crewPowers.empty())
            {
                for (ActivatedPower *power : ex->crewPowers)
                {
                    power->OnUpdate();
                }
            }
            for (ActivatedPowerResource *power : ex->powerResources)
            {
                power->OnUpdate();
            }
        }
    }
}

HOOK_METHOD(CrewMember, SaveState, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::SaveState -> Begin (CustomCrew.cpp)\n")
    auto ex = CM_EX(this);

    FileHelper::writeFloat(file, ex->selfId);

    FileHelper::writeFloat(file, health.first);
    FileHelper::writeFloat(file, health.second);

    FileHelper::writeInt(file, ex->noSlot);

    // Passive Heal
    if (ex->passiveHealTimer != nullptr)
    {
        FileHelper::writeFloat(file, ex->passiveHealTimer->currGoal);
        FileHelper::writeFloat(file, ex->passiveHealTimer->currTime);
    }
    else
    {
        FileHelper::writeFloat(file, -1.f);
        FileHelper::writeFloat(file, -1.f);
    }

    // Death Timer
    if (ex->deathTimer != nullptr)
    {
        FileHelper::writeFloat(file, ex->deathTimer->currGoal);
        FileHelper::writeFloat(file, ex->deathTimer->currTime);
    }
    else
    {
        FileHelper::writeFloat(file, -1.f);
        FileHelper::writeFloat(file, -1.f);
    }

    // Crew ability stuff
    FileHelper::writeInt(file, ex->crewPowers.size());
    for (ActivatedPower *power : ex->crewPowers)
    {
        power->SaveState(file);
    }
    FileHelper::writeInt(file, ex->powerResources.size());
    for (ActivatedPowerResource *resource : ex->powerResources)
    {
        resource->SaveState(file);
    }

    // Original race
    FileHelper::writeString(file, ex->originalColorRace);
    FileHelper::writeString(file, ex->originalRace);

    // Custom teleport
    FileHelper::writeInt(file, ex->customTele.teleporting);
    FileHelper::writeInt(file, ex->customTele.shipId);
    FileHelper::writeInt(file, ex->customTele.roomId);
    FileHelper::writeInt(file, ex->customTele.slotId);

    // Timed augment stat boosts
    std::vector<StatBoost*> timedStatBoostsSerial;
    for (auto& vStatBoost : ex->timedStatBoosts)
    {
        for (auto& statBoost : vStatBoost.second)
        {
            timedStatBoostsSerial.push_back(&statBoost);
        }
    }

    FileHelper::writeInt(file, timedStatBoostsSerial.size());
    for (auto statBoost : timedStatBoostsSerial)
    {
        statBoost->Save(file);
    }

    super(file);

}

HOOK_METHOD(CrewMember, LoadState, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::LoadState -> Begin (CustomCrew.cpp)\n")
    auto ex = CM_EX(this);
    auto aex = CMA_EX(crewAnim);

    ex->selfId = FileHelper::readFloat(file);

    for (StatBoost &statBoost : ex->outgoingStatBoosts)
    {
        statBoost.crewSourceId = ex->selfId;
    }

    std::pair<float,float> customHealth;

    customHealth.first = FileHelper::readFloat(file);
    customHealth.second = FileHelper::readFloat(file);

    ex->noSlot = FileHelper::readInteger(file);

    // Passive Heal
    float timerGoal = FileHelper::readFloat(file);
    if (timerGoal != -1.f)
    {
        if (ex->passiveHealTimer == nullptr)
        {
            ex->passiveHealTimer = new TimerHelper(false);
        }
        ex->passiveHealTimer->Start(timerGoal);
        ex->passiveHealTimer->currTime = FileHelper::readFloat(file);
    }
    else
    {
        FileHelper::readFloat(file);
    }

    // Death Timer
    timerGoal = FileHelper::readFloat(file);
    if (timerGoal != -1.f)
    {
        if (ex->deathTimer == nullptr)
        {
            ex->deathTimer = new TimerHelper(false);
        }
        ex->deathTimer->Start(timerGoal);
        ex->deathTimer->currTime = FileHelper::readFloat(file);
    }
    else
    {
        FileHelper::readFloat(file);
    }

    // Crew ability stuff
    ex->ClearCrewPowers();
    ex->hasSpecialPower = false;
    int n = FileHelper::readInteger(file);
    for (int i=0; i<n; ++i)
    {
        ActivatedPower *power = new ActivatedPower(nullptr, this, ex);
        ex->crewPowers.push_back(power);
        power->LoadState(file);
        if (power->enabled) ex->hasSpecialPower = true;
    }
    n = FileHelper::readInteger(file);
    for (int i=0; i<n; ++i)
    {
        ActivatedPowerResource *resource = new ActivatedPowerResource(nullptr, this, ex);
        ex->powerResources.push_back(resource);
        resource->LoadState(file);
        ex->powerResourceMap[resource->def->index] = resource;
    }
    for (ActivatedPower *power : ex->crewPowers)
    {
        power->LinkPowerResources();
    }

    ex->UpdateAbilityStatBoosts();

    // Original race
    ex->originalColorRace = FileHelper::readString(file);
    ex->originalRace = FileHelper::readString(file);

    // Custom teleport
    ex->customTele.teleporting = FileHelper::readInteger(file);
    ex->customTele.shipId = FileHelper::readInteger(file);
    ex->customTele.roomId = FileHelper::readInteger(file);
    ex->customTele.slotId = FileHelper::readInteger(file);

    // Timed augment stat boosts
    int timedStatBoostsSize = FileHelper::readInteger(file);

    for (int i=0; i<timedStatBoostsSize; ++i)
    {
        StatBoost statBoost = StatBoost::LoadStatBoost(file);

        auto& vStatBoosts = ex->timedStatBoosts[statBoost.def->stat];

        vStatBoosts.push_back(statBoost);
    }

    // Transformed color choices
    if (species != ex->originalColorRace)
    {
        auto bpM = G_->GetBlueprints();
        auto it = bpM->crewBlueprints.find(ex->originalColorRace);
        if (it != bpM->crewBlueprints.end())
        {
            blueprint.colorLayers = it->second.colorLayers;
            blueprint.colorChoices.resize(blueprint.colorLayers.size(), -1);
            unsigned int n = std::min(blueprint.colorLayers.size(), crewAnim->layerColors.size());
            unsigned int i;
            for (i=0; i<n; ++i)
            {
                if (blueprint.colorChoices[i] < blueprint.colorLayers[i].size())
                {
                    crewAnim->layerColors[i] = blueprint.colorLayers[i][blueprint.colorChoices[i]];
                }
            }
            for (; i<crewAnim->layerColors.size(); ++i)
            {
                crewAnim->layerColors[i] = GL_Color(0.0, 0.0, 0.0, 0.0);
            }
        }
    }

    super(file);

    health = customHealth;
    ex->statCache[(unsigned int)CrewStat::MAX_HEALTH].first = health.second;
    ex->statCache[(unsigned int)CrewStat::MAX_HEALTH].second = StatBoostManager::statCacheFrame;
}

HOOK_METHOD_PRIORITY(CrewMember, GetNewGoal, 2000, () -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::GetNewGoal -> Begin (CustomCrew.cpp)\n")
    auto ex = CM_EX(this);
    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    auto def = CustomCrewManager::GetInstance()->GetDefinition(this->species);
    ex->CalculateStat(CrewStat::CAN_PHASE_THROUGH_DOORS, def, &ex->canPhaseThroughDoors);

    if (!ex->canPhaseThroughDoors) return super();

    if (last_door && !ex->canPhaseThroughDoors)
    {
        last_door->FakeClose();
    }


    last_door = 0;

    bool result = false;


    if (path.distance != -1.f)
    {
        Point pos = Point(std::floor(x), std::floor(y));

        int roomId = iRoomId;
        ShipGraph* shipGraph = ShipGraph::GetShipInfo(currentShipId);
        Point intoRoom = shipGraph->GetIntoRoom(roomId, pos);

        if (path.doors.size() > 0)
        {
            Door* door = path.doors.front();

            Point doorPos = door->GetCenterPoint();
            Point entryWay = door->GetEntryWay(iRoomId);

            Point gridPos = ShipGraph::TranslateToGrid(pos.x, pos.y);
            Point entryPos = ShipGraph::TranslateToGrid(entryWay.x, entryWay.y);

            if (entryPos.x != gridPos.x || entryPos.y != gridPos.y)
            {
                if (intoRoom.x == -1 || intoRoom.y == -1)
                {
                    goal_x = entryWay.x;
                    goal_y = entryWay.y;
                }
                else
                {
                    goal_x = intoRoom.x;
                    goal_y = intoRoom.y;
                }
                return true;
            }

            if (door->IsSealed(iShipId) && (!bMindControlled || door->lockedDown.running) && !ex->canPhaseThroughDoors)
            {
                bool up = false;
                bool right = false;
                bool down = false;
                bool left = false;

                if (blockingDoor)
                {
                    blockingDoor = door;
                    SetCurrentTarget(door, false);
                    return true;
                }
                else
                {
                    if (doorPos.y > entryWay.y)
                    {
                        down = true;
                    }
                    else if (doorPos.y < entryWay.y)
                    {
                        up = true;
                    }

                    if (doorPos.x > entryWay.x)
                    {
                        right = true;
                    }
                    else if (doorPos.x < entryWay.x)
                    {
                        left = true;
                    }

                    int offset = random32() % 17;
                    if (door->bVertical)
                    {
                        if (left)
                        {
                            goal_x = doorPos.x + 8;
                        }
                        else
                        {
                            goal_x = doorPos.x - 8;
                        }

                        goal_y = offset + (doorPos.y - 8);

                    }
                    else
                    {
                        if (up)
                        {
                            goal_y = doorPos.y + 8;
                        }
                        else
                        {
                            goal_y = doorPos.y - 8;
                        }

                        goal_x = offset + (doorPos.x - 8);
                    }

                    blockingDoor = door;
                    SetCurrentTarget(door, false);
                    return true;
                }
            }

            if (door->bVertical)
            {
                if (std::abs(pos.y - entryWay.y) > 0.05)
                {
                    goal_x = x;
                    goal_y = entryWay.y;
                    return true;
                }
                if (doorPos.x < entryWay.x)
                {
                    goal_x = entryWay.x - 35;
                    goal_y = y;
                }
                if (doorPos.x > entryWay.x)
                {
                    goal_x = entryWay.x + 34;
                    goal_y = y;
                }
                path.doors.erase(path.doors.begin());
            }
            else
            {
                if (std::abs(pos.x - entryWay.x) > 0.05)
                {
                    goal_y = y;
                    goal_x = entryWay.x;
                    return true;
                }
                if (doorPos.y < entryWay.y)
                {
                    goal_y = entryWay.y - 35;
                    goal_x = x;
                }
                if (doorPos.y > entryWay.y)
                {
                    goal_y = entryWay.y + 34;
                    goal_x = x;
                }



                path.doors.erase(path.doors.begin());

            }

            if (!door->bOpen && !door->forcedOpen.running)
            {
                if (!ex->canPhaseThroughDoors)
                {
                    last_door = door;
                    door->FakeOpen();
                }
                else
                {
                    G_->GetSoundControl()->PlaySoundMix("phase", -1.f, false);
                }
            }


            return true;
        }
        else
        {
            if (intoRoom.x != -1 && intoRoom.y != -1)
            {
                goal_x = intoRoom.x;
                goal_y = intoRoom.y;

                return true;
            }
            else
            {
                Point finish = path.finish;
                goal_x = finish.x;
                goal_y = finish.y;

                if ( std::abs(path.finish.x - x) > 0.5 )
                {
                    return true;
                }

                x = path.finish.x;

                if ( std::abs(path.finish.y - y) > 0.5 )
                {
                    return true;
                }

                y = path.finish.y;

                path.distance = -1.f;
            }
        }
    }

    return result;
}

HOOK_METHOD(BlueprintManager, GetCrewBlueprint, (const std::string &name) -> CrewBlueprint)
{
    LOG_HOOK("HOOK_METHOD -> BlueprintManager::GetCrewBlueprint -> Begin (CustomCrew.cpp)\n")
    std::vector<std::string> blueprintList = this->GetBlueprintList(name);
    if (blueprintList.empty())
    {
        return super(name);
    }
    else
    {
        return super(blueprintList[random32()%blueprintList.size()]);
    }
}

HOOK_METHOD(ShipManager, AddCrewMemberFromString, (const std::string& name, const std::string& race, bool intruder, int roomId, bool init, bool male) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::AddCrewMemberFromString -> Begin (CustomCrew.cpp)\n")
    std::string actualRace = race;
    std::vector<std::string> blueprintList = G_->GetBlueprints()->GetBlueprintList(actualRace);

    while (!blueprintList.empty())
    {
        actualRace = blueprintList[random32()%blueprintList.size()];
        blueprintList = G_->GetBlueprints()->GetBlueprintList(actualRace);
    }

    return super(name, actualRace, intruder, roomId, init, male);
}

HOOK_METHOD(CompleteShip, AddCrewMember1, (const std::string &race, const std::string &name, bool hostile) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD -> CompleteShip::AddCrewMember1 -> Begin (CustomCrew.cpp)\n")
    std::vector<std::string> blueprintList = G_->GetBlueprints()->GetBlueprintList(race);
    if (blueprintList.empty())
    {
        return super(race, name, hostile);
    }
    else
    {
        return AddCrewMember1(blueprintList[random32()%blueprintList.size()], name, hostile);
    }
}

HOOK_METHOD(CrewMemberFactory, CreateCrewMember, (CrewBlueprint* bp, int shipId, bool intruder) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD -> CrewMemberFactory::CreateCrewMember -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();
    CrewMember *newCrew = custom->CreateCrewMember(bp, shipId, shipId == 1);

    if (newCrew)
    {
        crewMembers.push_back(newCrew);
        OnLoop();
        return newCrew;
    }

    return super(bp, shipId, intruder);
}


HOOK_STATIC(CrewMemberFactory, IsRace, (std::string& race) -> bool)
{
    LOG_HOOK("HOOK_STATIC -> CrewMemberFactory::IsRace -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    if (custom->IsRace(race))
        return true;
    return super(race);
}

HOOK_METHOD(CrewAnimation, GetDeathSound, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::GetDeathSound -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    std::string ret = super();

    if (custom->IsRace(this->race))
    {
        auto def = custom->GetDefinition(this->race);

        std::vector<std::string>& deathSounds = this->bMale ? def->deathSounds : def->deathSoundsFemale;

        if (deathSounds.size() > 0)
        {
            int rng = random32();

            ret.assign(deathSounds[rng % deathSounds.size()]);

            return ret;
        }
    }

    return ret;
}

HOOK_METHOD(RockAnimation, GetDeathSound, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> RockAnimation::GetDeathSound -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    std::string ret = super();

    if (custom->IsRace(this->race))
    {
        auto def = custom->GetDefinition(this->race);

        std::vector<std::string>& deathSounds = this->bMale ? def->deathSounds : def->deathSoundsFemale;

        if (deathSounds.size() > 0)
        {
            int rng = random32();

            ret.assign(deathSounds[rng % deathSounds.size()]);

            return ret;
        }
    }

    return ret;
}

HOOK_METHOD(MantisAnimation, GetDeathSound, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> MantisAnimation::GetDeathSound -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    std::string ret = super();

    if (custom->IsRace(this->race))
    {
        auto def = custom->GetDefinition(this->race);

        std::vector<std::string>& deathSounds = this->bMale ? def->deathSounds : def->deathSoundsFemale;

        if (deathSounds.size() > 0)
        {
            int rng = random32();

            ret.assign(deathSounds[rng % deathSounds.size()]);

            return ret;
        }
    }

    return ret;
}

HOOK_METHOD(CrewAnimation, GetShootingSound, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::GetShootingSound -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    std::string ret = super();

    if (custom->IsRace(this->race))
    {
        auto def = custom->GetDefinition(this->race);

        if (def->shootingSounds.size() > 0)
        {
            int rng = random32();

            ret.assign(def->shootingSounds[rng % def->shootingSounds.size()]);

            return ret;
        }
    }

    return ret;
}

HOOK_METHOD(RockAnimation, GetShootingSound, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> RockAnimation::GetShootingSound -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    std::string ret = super();

    if (custom->IsRace(this->race))
    {
        auto def = custom->GetDefinition(this->race);

        if (def->shootingSounds.size() > 0)
        {
            int rng = random32();

            ret.assign(def->shootingSounds[rng % def->shootingSounds.size()]);

            return ret;
        }
    }

    return ret;
}

HOOK_METHOD(MantisAnimation, GetShootingSound, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> MantisAnimation::GetShootingSound -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    std::string ret = super();

    if (custom->IsRace(this->race))
    {
        auto def = custom->GetDefinition(this->race);

        if (def->shootingSounds.size() > 0)
        {
            int rng = random32();

            ret.assign(def->shootingSounds[rng % def->shootingSounds.size()]);

            return ret;
        }
    }

    return ret;
}

HOOK_METHOD(CrewMember, GetUniqueRepairing, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::GetUniqueRepairing -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    std::string ret = super();

    if (custom->IsRace(this->species))
    {
        auto def = custom->GetDefinition(this->species);

        if (def->repairSounds.size() > 0 && def->repairSoundFrame == -1)
        {
            int rng = random32();

            ret.assign(def->repairSounds[rng % def->repairSounds.size()]);


            return ret;
        }
        else
        {
            ret.assign("");
            return ret;
        }
    }

    return ret;
}

HOOK_METHOD(OxygenSystem, EmptyOxygen, (int roomId) -> void)
{
    LOG_HOOK("HOOK_METHOD -> OxygenSystem::EmptyOxygen -> Begin (CustomCrew.cpp)\n")
    if (!G_->GetCApp()->menu.shipBuilder.bOpen)
        return;

    return super(roomId);
}

HOOK_METHOD(ShipManager, UpdateEnvironment, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::UpdateEnvironment -> Begin (CustomCrew.cpp)\n")
    if (!G_->GetCApp()->menu.shipBuilder.bOpen && systemKey[2] != -1)
    {
        for (auto const &x: vCrewList)
        {
            auto custom = CustomCrewManager::GetInstance();

            if (custom->IsRace(x->species))
            {
                auto def = custom->GetDefinition(x->species);
                auto ex = CM_EX(x);
                float oxygenModifier = ex->CalculateStat(CrewStat::OXYGEN_CHANGE_SPEED, def);

                if (oxygenModifier != 0.f && !x->bDead)
                {
                    if (oxygenSystem->oxygenLevels[x->iRoomId] == 0.f)
                    {
                        oxygenSystem->oxygenLevels[x->iRoomId] = 0.0000001f;
                    }

                    oxygenSystem->ComputeAirLoss(x->iRoomId, -oxygenModifier, true);
                }
            }
        }
    }
    super();
}


HOOK_METHOD(CrewMember, ApplyDamage, (float damage) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::ApplyDamage -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    if (custom->IsRace(species))
    {
        auto def = custom->GetDefinition(species);
        auto ex = CM_EX(this);
        float damageTakenMultiplier = ex->CalculateStat(CrewStat::DAMAGE_TAKEN_MULTIPLIER, def);

        damage = damage * (damageTakenMultiplier);
    }

    return super(damage);
}


static bool crewDetectLifeforms = false;

HOOK_METHOD(ShipManager, OnRender, (bool unk1, bool unk2) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnRender -> Begin (CustomCrew.cpp)\n")
    crewDetectLifeforms = true;
    super(unk1, unk2);
    crewDetectLifeforms = false;
}

HOOK_METHOD(CombatControl, CanTargetSelf, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::CanTargetSelf -> Begin (CustomCrew.cpp)\n")
    crewDetectLifeforms = true;
    bool ret = super();
    crewDetectLifeforms = false;

    return ret;
}

HOOK_METHOD(CombatControl, UpdateTarget, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::UpdateTarget -> Begin (CustomCrew.cpp)\n")
    crewDetectLifeforms = true;
    bool ret = super();
    crewDetectLifeforms = false;

    return ret;
}

HOOK_METHOD(ShipObject, HasEquipment, (const std::string& name) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipObject::HasEquipment -> Begin (CustomCrew.cpp)\n")
    if (name == "slug" && crewDetectLifeforms)
    {
        auto custom = CustomCrewManager::GetInstance();

        std::vector<CrewMember*> vCrewList;

        auto world = G_->GetWorld();

        ShipManager *playerShip = world->playerShip->shipManager;
        ShipManager *enemyShip = world->playerShip->enemyShip ? world->playerShip->enemyShip->shipManager : nullptr;

        if (playerShip != nullptr)
        {
            vCrewList.insert(vCrewList.end(), playerShip->vCrewList.begin(), playerShip->vCrewList.end());
        }
        if (enemyShip != nullptr)
        {
            vCrewList.insert(vCrewList.end(), enemyShip->vCrewList.begin(), enemyShip->vCrewList.end());
        }


        for (auto i : vCrewList)
        {
            if (custom->IsRace(i->species))
            {
                auto def = custom->GetDefinition(i->species);
                auto ex = CM_EX(i);

                if (i->iShipId == iShipId)
                {
//                        if (HasAugmentation("ALL_CREW_DETECT_LIFEFORMS"))
//                        {
//                            return GetAugmentationValue("ALL_CREW_DETECT_LIFEFORMS");
//                        }
                    bool detectsLifeforms;
                    ex->CalculateStat(CrewStat::DETECTS_LIFEFORMS, def, &detectsLifeforms);
                    if (detectsLifeforms && i->Functional())
                    {
                        return 1;
                    }
                }
            }
            else if (i->species == "slug") return 1;
        }

        return 0;
    }

    return super(name);
}

HOOK_METHOD(ShipSystem, SetPowerLoss, (int powerLoss) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::SetPowerLoss -> Begin (CustomCrew.cpp)\n")
    int ret = super(powerLoss);

    SYS_EX(this)->oldPowerLoss = powerLoss;

    return ret;
}

static bool blockClearStatus = false;

HOOK_METHOD(WorldManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::OnLoop -> Begin (CustomCrew.cpp)\n")
    super();


    if (!HostileEnvironment() && ships.size() == 0)
    {
        playerShip->shipManager->ClearStatusSystem(2);
        playerShip->shipManager->ClearStatusSystem(6);
        playerShip->shipManager->ClearStatusSystem(1);
    }
}

HOOK_METHOD(ShipManager, ClearStatusSystem, (int sys) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ClearStatusSystem -> Begin (CustomCrew.cpp)\n")
    if (blockClearStatus) return;

    super(sys);
}

HOOK_METHOD(ShipSystem, ClearStatus, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::ClearStatus -> Begin (CustomCrew.cpp)\n")
    SYS_EX(this)->oldPowerLoss = 0;
    super();

    //iTempPowerLoss = SYS_EX(this)->additionalPowerLoss;
}

HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnLoop -> Begin (CustomCrew.cpp)\n")
    super();

    for (auto i : vSystemList)
    {
        ShipSystem_Extend* sys_ex = SYS_EX(i);

        sys_ex->additionalPowerLoss = 0;
    }

    auto custom = CustomCrewManager::GetInstance();

    for (auto i : vCrewList)
    {
        if (custom->IsRace(i->species))
        {
            auto def = custom->GetDefinition(i->species);
            CustomCrewManager *custom = CustomCrewManager::GetInstance();

            auto ex = CM_EX(i);
            int powerDrain = i->Functional() ? ex->CalculateStat(CrewStat::POWER_DRAIN, def) : 0;

            ShipSystem* sys = GetSystemInRoom(i->iRoomId);

            if (sys && sys->iSystemType != SYS_PILOT)
            {
                bool powerDrainFriendly = false;
                ex->CalculateStat(CrewStat::POWER_DRAIN_FRIENDLY, def, &powerDrainFriendly);
                if (i->intruder || powerDrainFriendly)
                {
                    ShipSystem_Extend* sys_ex = SYS_EX(sys);

                    sys_ex->additionalPowerLoss += powerDrain;
                }
            }

            if (def->changeIfSame)
            {
                int counter = 0;
                for (auto name : def->transformName)
                {
                    if (i->blueprint.crewNameLong.GetText() == name) // this is stupid
                    {
                        std::string newSpecies = def->nameRace.at(counter);
                        ++counter;

                        ex->originalRace = newSpecies;
                        ex->TransformRace(newSpecies);
                    }
                }
            }
            else
            {
                bool change = true;
                for (auto check : def->transformName)
                {
                    if (i->blueprint.crewNameLong.GetText() != check)
                    {
                        change = false;
                    }
                }
                if (change)
                {
                    std::string newSpecies = def->nameRace.at(0);

                    ex->originalRace = newSpecies;
                    ex->TransformRace(newSpecies);
                }
            }

            ex->CalculateStat(CrewStat::TRANSFORM_RACE, def);
            if (ex->transformRace != i->species) ex->TransformRace(ex->transformRace);
        }
    }

    for (auto i : vSystemList)
    {
        ShipSystem_Extend* sys_ex = SYS_EX(i);

        /*
        i->iTempPowerLoss = sys_ex->oldPowerLoss + sys_ex->additionalPowerLoss;
        int maxPowerLoss = i->powerState.second - (i->healthState.second - i->healthState.first);
        if (i->iTempPowerLoss >= maxPowerLoss)
        {
            i->iTempPowerLoss = maxPowerLoss;
        }
        */

        i->CheckMaxPower();
        i->CheckForRepower();
    }
}

HOOK_METHOD(ShipSystem, GetMaxPower, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::GetMaxPower -> Begin (CustomCrew.cpp)\n")
    ShipSystem_Extend* sys_ex = SYS_EX(this);
    iTempPowerLoss = sys_ex->oldPowerLoss + sys_ex->additionalPowerLoss;
    int maxPowerLoss = powerState.second - (healthState.second - healthState.first);
    if (iTempPowerLoss > maxPowerLoss) iTempPowerLoss = maxPowerLoss;
    return super();
}

HOOK_METHOD(ShipSystem, CheckMaxPower, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::CheckMaxPower -> Begin (CustomCrew.cpp)\n")
    ShipSystem_Extend* sys_ex = SYS_EX(this);
    iTempPowerLoss = sys_ex->oldPowerLoss + sys_ex->additionalPowerLoss;
    int maxPowerLoss = powerState.second - (healthState.second - healthState.first);
    if (iTempPowerLoss > maxPowerLoss) iTempPowerLoss = maxPowerLoss;
    super();
}

HOOK_METHOD(ShipSystem, CheckForRepower, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::CheckForRepower -> Begin (CustomCrew.cpp)\n")
    ShipSystem_Extend* sys_ex = SYS_EX(this);
    iTempPowerLoss = sys_ex->oldPowerLoss + sys_ex->additionalPowerLoss;
    int maxPowerLoss = powerState.second - (healthState.second - healthState.first);
    if (iTempPowerLoss > maxPowerLoss) iTempPowerLoss = maxPowerLoss;
    super();
}

HOOK_METHOD(ShipSystem, AddDamage, (int amount) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::AddDamage -> Begin (CustomCrew.cpp)\n")
    int newHealth = std::max(0, std::min(healthState.first - amount, healthState.second));

    ShipSystem_Extend* sys_ex = SYS_EX(this);
    iTempPowerLoss = sys_ex->oldPowerLoss + sys_ex->additionalPowerLoss;
    int maxPowerLoss = powerState.second - (healthState.second - newHealth);
    if (iTempPowerLoss > maxPowerLoss) iTempPowerLoss = maxPowerLoss;

    super(amount);
}

HOOK_METHOD(ShipSystem, DamageOverTime, (float speed) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::DamageOverTime -> Begin (CustomCrew.cpp)\n")
    auto ret = super(speed);
    if (ret)
    {
        int maxPowerLoss = powerState.second - (healthState.second - healthState.first);
        if (iTempPowerLoss > maxPowerLoss)
        {
            iTempPowerLoss = maxPowerLoss;
            iBonusPower = 0;
        }
    }
    return ret;
}

HOOK_METHOD(ShipSystem, PartialRepair, (float speed, bool autoRepair) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::PartialRepair -> Begin (CustomCrew.cpp)\n")
    auto ret = super(speed, autoRepair);
    if (ret)
    {
        ShipSystem_Extend* sys_ex = SYS_EX(this);
        iTempPowerLoss = sys_ex->oldPowerLoss + sys_ex->additionalPowerLoss;
        int maxPowerLoss = powerState.second - (healthState.second - healthState.first);
        if (iTempPowerLoss > maxPowerLoss) iTempPowerLoss = maxPowerLoss;
    }
    return ret;
}


HOOK_METHOD(CrewMember, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::OnLoop -> Begin (CustomCrew.cpp)\n")
    super();

    auto custom = CustomCrewManager::GetInstance();

    if (custom->IsRace(species))
    {
        auto ex = CM_EX(this);
        auto def = custom->GetDefinition(this->species);

        if (crewAnim->status == 3)
        {
            if (!ex->exploded && !ex->triggerExplosion)
            {
                ex->triggerExplosion = true;
            }
        }
        else if (!bDead)
        {
            ex->triggerExplosion = false;
            ex->exploded = false;
        }

        /*
        if (!ex->timedStatBoosts.empty())
        {
            int counter = 0;
            for (StatBoost statBoost : ex->timedStatBoosts)
            {
                if (statBoost.timerHelper)
                {
                    statBoost.timerHelper->Update();
                    if (statBoost.timerHelper->Done())
                    {
                        ex->timedStatBoosts.erase(ex->timedStatBoosts.begin() + counter);
                    }
                }
                else
                {
                    if (statBoost.duration != -1)
                    {
                        statBoost.timerHelper = new TimerHelper();
                        statBoost.timerHelper->Start(statBoost.duration);
                    }
                    else
                    {
                        // the "timed" stat boost is actually permanent
                    }
                }
            }
            ++counter;
        }
        */
    }
}

bool shipFriendlyFire = true;
bool blockDamageArea = false;

// We can't return just Damage (since it's a hidden parameter) like we could in the static variant, so reverse the logic and only return ANYTHING if we should, otherwise let the functions fall through and the stack will be unmodified.
HOOK_METHOD(IonDrone, GetRoomDamage, () -> Damage)
{
    LOG_HOOK("HOOK_METHOD -> IonDrone::GetRoomDamage -> Begin (CustomCrew.cpp)\n")
    if (!blockDamageArea)
        return super();
    return Damage();
}
HOOK_METHOD(EnergyAlien, GetRoomDamage, () -> Damage)
{
    LOG_HOOK("HOOK_METHOD -> EnergyAlien::GetRoomDamage -> Begin (CustomCrew.cpp)\n")
    if (!blockDamageArea)
        return super();
    return Damage();
}

HOOK_METHOD(CrewMember, GetRoomDamage, () -> Damage)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::GetRoomDamage -> Begin (CustomCrew.cpp)\n")
    Damage ret = super();

    auto custom = CustomCrewManager::GetInstance();
    if (!blockDamageArea)
    {
        if (custom->IsRace(this->species))
        {
            auto ex = CM_EX(this);

            if (ex->triggerExplosion && !ex->exploded)
            {
                ex->exploded = true;

                auto def = custom->GetDefinition(this->species);
                ex->CalculateStat(CrewStat::DEATH_EFFECT, def);

                if (ex->hasDeathExplosion)
                {
                    ExplosionDefinition *explosionDef = &ex->deathEffectChange;
                    Damage *customDamage = &explosionDef->damage;

                    ret.iDamage = customDamage->iDamage;
                    ret.fireChance = customDamage->fireChance;
                    ret.breachChance = customDamage->breachChance;
                    ret.stunChance = customDamage->stunChance;
                    ret.iIonDamage = customDamage->iIonDamage;
                    ret.iSystemDamage = customDamage->iSystemDamage;
                    ret.iPersDamage = customDamage->iPersDamage;
                    ret.bHullBuster = customDamage->bHullBuster;
                    ret.ownerId = this->GetPowerOwner();
                    ret.selfId = ex->selfId;
                    ret.bLockdown = customDamage->bLockdown;
                    ret.crystalShard = customDamage->crystalShard;
                    ret.bFriendlyFire = customDamage->bFriendlyFire;
                    ret.iStun = customDamage->iStun;
                    shipFriendlyFire = explosionDef->shipFriendlyFire;

                    if (!explosionDef->statBoosts.empty())
                    {
                        for (auto i=0; i<2; ++i)
                        {
                            ShipManager *crewShip = G_->GetShipManager(i);
                            if (crewShip)
                            {
                                for (auto otherCrew : crewShip->vCrewList)
                                {
                                    for (auto statBoostDef : explosionDef->statBoosts)
                                    {
                                        StatBoost statBoost(statBoostDef);
                                        statBoost.crewSource = this;
                                        statBoost.crewSourceId = ex->selfId;
                                        statBoost.sourceShipId = this->iShipId;
                                        StatBoostManager::GetInstance()->CreateTimedAugmentBoost(statBoost, otherCrew);
                                    }
                                }
                            }
                        }
                    }
                    if (!explosionDef->roomStatBoosts.empty())
                    {
                        ShipManager *crewShip = G_->GetShipManager(currentShipId);
                        if (crewShip)
                        {
                            for (auto statBoostDef : explosionDef->roomStatBoosts)
                            {
                                SM_EX(crewShip)->CreateRoomStatBoost(*statBoostDef, iRoomId, 1, this);
                            }
                        }
                    }
                    if (!explosionDef->crewSpawns.empty())
                    {
                        ShipManager *crewShip = G_->GetShipManager(this->currentShipId);
                        if (crewShip)
                        {
                            for (CrewSpawn* i : explosionDef->crewSpawns)
                            {
                                CrewSpawn::SpawnCrew(i, crewShip, this->currentShipId != this->iShipId, Pointf(this->x, this->y));
                            }
                        }
                    }
                    if (!explosionDef->event[this->iShipId].empty())
                    {
                        CustomEventsParser::QueueEvent(explosionDef->event[this->iShipId], -1);
                    }
                }
            }
        }
        else
        {
            // WARNING: Potential bug during migration to non-static methods!
            if (this->species == "energy")
            {
                ret = ((EnergyAlien*) this)->GetRoomDamage(); // TODO: Problematic, TODO: Should this just be super, but we already ran super?
            }
        }


        // WARNING: Potential bug during migration to non-static methods!
        if (CM_EX(this)->isIonDrone)
        {
            ret = ((IonDrone*) this)->GetRoomDamage(); // TODO: Problematic, TODO: Should this just be super, but we already ran super?
        }
    }

    return ret;
}

HOOK_METHOD(ShipManager, UpdateCrewMembers, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::UpdateCrewMembers -> Begin (CustomCrew.cpp)\n")
    blockDamageArea = true;
    super();
    blockDamageArea = false;


    CustomCrewManager *custom = CustomCrewManager::GetInstance();

    for (int i=0; i<vCrewList.size(); ++i)
    {
        CrewMember *crew = vCrewList[i];

        Damage dmgI = crew->GetRoomDamage();

        if (dmgI.ownerId != -1) DamageArea(Pointf(crew->x, crew->y), dmgI, true);

        if (custom->IsRace(crew->species))
        {
            int ownerShip = crew->GetPowerOwner();
            auto def = custom->GetDefinition(crew->species);

            auto ex = CM_EX(crew);
            if (crew->iRoomId != -1)
            {
                // damageEnemiesAmount/healEnemiesAmount time dilation/temporal system
                // Didn't want to do this here but I don't think I have a choice
                float timeDilation = TemporalSystemParser::GetDilationStrength(RM_EX(ship.vRoomList[crew->iRoomId])->timeDilation);

                float damageEnemies = ex->CalculateStat(CrewStat::DAMAGE_ENEMIES_AMOUNT, def) * G_->GetCFPS()->GetSpeedFactor() * 0.0625f * timeDilation;

                if (crew->Functional() && damageEnemies != 0.f)
                {
                    for (int j=0; j<vCrewList.size(); ++j)
                    {
                        CrewMember *otherCrew = vCrewList[j];
                        if (otherCrew->iRoomId == crew->iRoomId && otherCrew->iShipId != ownerShip && otherCrew != crew)
                        {
                            otherCrew->DirectModifyHealth(-damageEnemies);
                        }
                    }
                }
                float healCrewAmount = ex->CalculateStat(CrewStat::HEAL_CREW_AMOUNT, def);

                if (crew->Functional() && healCrewAmount != 0.f)
                {
                    float healCrew = G_->GetCFPS()->GetSpeedFactor() * healCrewAmount * 0.0625f * timeDilation;

                    for (int j=0; j<vCrewList.size(); ++j)
                    {
                        CrewMember *otherCrew = vCrewList[j];
                        if (otherCrew->iRoomId == crew->iRoomId && otherCrew->iShipId == ownerShip && otherCrew != crew)
                        {
                            CrewMember_Extend *ex2 = CM_EX(otherCrew);
                            CrewDefinition *def2 = ex2->GetDefinition();
                            float mod;
                            if (def2)
                            {
                                mod = ex2->CalculateStat(CrewStat::HEAL_SPEED_MULTIPLIER, def2);
                            }
                            else
                            {
                                mod = 1.f;
                            }

                            if (healCrew*mod > 0.f && otherCrew->health.first != otherCrew->health.second)
                            {
                                otherCrew->fMedbay += 0.0000000001;
                            }
                            otherCrew->DirectModifyHealth(healCrew*mod);
                        }
                    }
                }
            }

            for (ActivatedPower *power : ex->crewPowers)
            {
                // apply the activated power damage effect
                if (power->powerActivated)
                {
                    ShipManager* actualShip = this;
                    if (power->powerShip != iShipId)
                    {
                        actualShip = current_target;
                        if (actualShip == nullptr)
                        {
                            actualShip = power->powerShip ? (G_->GetWorld()->playerShip->enemyShip ? G_->GetWorld()->playerShip->enemyShip->shipManager : nullptr) : G_->GetWorld()->playerShip->shipManager;
                        }
                    }

                    if (actualShip)
                    {
                        Damage dmg = power->GetPowerDamage();

                        shipFriendlyFire = power->def->shipFriendlyFire;
                        actualShip->DamageArea(power->effectWorldPos, dmg, true);
                    }
                    power->powerActivated = false;
                }
            }
        }
    }
}


HOOK_METHOD(ShipManager, DamageCrew, (CrewMember *crew, Damage dmg) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::DamageCrew -> Begin (CustomCrew.cpp)\n")
    if (dmg.selfId == CM_EX(crew)->selfId)
    {
        return false;
    }

    return super(crew, dmg);
}

HOOK_METHOD_PRIORITY(ShipManager, DamageArea, -1000, (Pointf location, Damage dmg, bool forceHit) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::DamageArea -> Begin (CustomCrew.cpp)\n")
    if (blockDamageArea) return false;

    return super(location, dmg, forceHit);
}

HOOK_METHOD_PRIORITY(ShipManager, DamageArea, 200, (Pointf location, Damage dmg, bool forceHit) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::DamageArea -> Begin (CustomCrew.cpp)\n")

    if (!shipFriendlyFire) // todo, make this possible to miss if forceHit is false
    {
        shipFriendlyFire = true;

        if (dmg.ownerId == iShipId)
        {
            int roomId = ship.GetSelectedRoomId(location.x, location.y, true);

            if (roomId == -1)
                return false;

            if (!bJumping)
            {
                for (auto i : vCrewList)
                {
                    if (i->iRoomId == roomId)
                    {
                        DamageCrew(i, dmg);
                    }
                }
            }

            return true;
        }
    }

    return super(location, dmg, forceHit);
}

static std::array<int,5> maxCooldownWidth = {12,18,18,22,999};

HOOK_METHOD(CrewBox, constructor, (Point pos, CrewMember *crew, int number) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewBox::constructor -> Begin (CustomCrew.cpp)\n")
    super(pos, crew, number);

    auto bex = CBOX_EX(this);
    bex->crewPos = {15,15};
    bex->skillOffset = 0;

    auto custom = CustomCrewManager::GetInstance();
    if (custom->IsRace(crew->species))
    {
        auto ex = CM_EX(crew);

        if (ex->hasSpecialPower)
        {
            // Loop over powers for buttons
            for (ActivatedPower* power : ex->crewPowers)
            {
                if (!power->enabled) continue;

                // power button
                if (!power->def->hideButton)
                {
                    bex->powerButtons.emplace_back(powerButton); // copy the default powerButton
                    ActivatedPowerButton &pButton = bex->powerButtons.back();
                    pButton.power = power;
                    pButton.button.SetLocation(Point(box.x+box.w+11, box.y+7+bex->skillOffset));
                    if (!power->def->buttonLabel.data.empty()) pButton.button.label = power->def->buttonLabel;

                    // offset to make room for ability buttons
                    bex->skillOffset += 24;
                }
            }

            int mode;
            int cooldownsWidth;
            std::vector<int> cooldownBorders;

            // update tempLinkedPowers for resources
            for (ActivatedPowerResource* resource : ex->powerResources)
            {
                if (resource->enabled && (resource->def->showTemporaryBars || resource->def->showLinkedCooldowns || resource->def->showLinkedCharges))
                {
                    resource->GetLinkedPowers();
                }
            }

            for (mode=0; mode<5; mode++)
            {
                cooldownsWidth = bex->GetTotalCooldownWidth(mode, ex);
                if (cooldownsWidth <= maxCooldownWidth[mode]) break;
            }

            auto iter1 = ex->crewPowers.begin();
            auto end1 = ex->crewPowers.end();
            auto iter2 = ex->powerResources.begin();
            auto end2 = ex->powerResources.end();

            int startX = std::max(-13, cooldownsWidth>10 ? 5-cooldownsWidth : -cooldownsWidth/2);
            bex->crewPos.x += std::min(startX+cooldownsWidth,std::max(2,startX+cooldownsWidth-3));
            int offset = startX;

            while (true)
            {
                if (iter1 != end1)
                {
                    if (iter2 == end2 || (*iter1)->def->sortOrder <= (*iter2)->def->sortOrder)
                    {
                        bex->EmplacePower(*iter1, mode, offset, cooldownBorders);
                        iter1++;
                    }
                    else
                    {
                        bex->EmplacePower(*iter2, mode, offset, cooldownBorders);
                        iter2++;
                    }
                }
                else if (iter2 != end2)
                {
                    bex->EmplacePower(*iter2, mode, offset, cooldownBorders);
                    iter2++;
                }
                else
                {
                    break;
                }
            }

            skillBox.h = 146 + bex->skillOffset;

            // draw the crew box

            GL_Color boxColor = GL_Color();
            boxColor.r = 1.0f;
            boxColor.g = 1.0f;
            boxColor.b = 1.0f;
            boxColor.a = 1.0f;

            CSurface::GL_DestroyPrimitive(boxBackground);
            boxBackground = CSurface::GL_CreateRectPrimitive(box.x+startX, box.y, box.w-startX-1, box.h, boxColor);

            CSurface::GL_DestroyPrimitive(skillBoxBackground);

            std::vector<Globals::Rect> boxRects = std::vector<Globals::Rect>();
            boxRects.push_back({box.x+startX, box.y, box.w-startX+82, box.h});
            boxRects.push_back({box.x+box.w+3, box.y+box.h, 80, skillBox.h-box.h});

            skillBoxBackground = CSurface::GL_CreateMultiRectPrimitive(boxRects, boxColor);

            boxColor.a = 1.0f;

            CSurface::GL_DestroyPrimitive(boxOutline);

            std::vector<GL_Line> boxLines = std::vector<GL_Line>();
            boxLines.emplace_back(Pointf(box.x+startX, box.y+1), Pointf(box.x+box.w, box.y+1)); //top
            boxLines.emplace_back(Pointf(box.x+startX, box.y+box.h-1), Pointf(box.x+box.w, box.y+box.h-1)); //bottom
            boxLines.emplace_back(Pointf(box.x+startX+1, box.y), Pointf(box.x+startX+1, box.y+box.h)); //left
            for (int linePos : cooldownBorders) boxLines.emplace_back(Pointf(box.x+linePos, box.y), Pointf(box.x+linePos, box.y+box.h)); //right of ability bar
            boxLines.emplace_back(Pointf(box.x+box.w-1, box.y), Pointf(box.x+box.w-1, box.y+box.h)); //right

            boxOutline = CSurface::GL_CreateMultiLinePrimitive(boxLines, boxColor, 2);

            CSurface::GL_DestroyPrimitive(skillBoxOutline);

            boxLines = std::vector<GL_Line>();
            boxLines.emplace_back(Pointf(box.x+startX, box.y+1), Pointf(skillBox.x+skillBox.w-1, box.y+1)); //top
            boxLines.emplace_back(Pointf(box.x+startX, box.y+box.h-1), Pointf(box.x+box.w+5, box.y+box.h-1)); //bottom of box
            boxLines.emplace_back(Pointf(box.x+startX+1, box.y), Pointf(box.x+startX+1, box.y+box.h)); //left
            for (int linePos : cooldownBorders) boxLines.emplace_back(Pointf(box.x+linePos, box.y), Pointf(box.x+linePos, box.y+box.h)); //right of ability bar
            boxLines.emplace_back(Pointf(box.x+box.w+4, box.y+box.h), Pointf(box.x+box.w+4, skillBox.y+skillBox.h)); //left of skillBox
            boxLines.emplace_back(Pointf(box.x+box.w+3, box.y+skillBox.h-1), Pointf(skillBox.x+skillBox.w, box.y+skillBox.h-1)); //bottom of skillBox
            boxLines.emplace_back(Pointf(skillBox.x+skillBox.w-1, skillBox.y), Pointf(skillBox.x+skillBox.w-1, skillBox.y+skillBox.h)); //right of skillBox

            skillBoxOutline = CSurface::GL_CreateMultiLinePrimitive(boxLines, boxColor, 2);

            // done drawing the crew box
        }
    }
}

HOOK_METHOD(CrewBox, OnLoop, (bool selected) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewBox::OnLoop -> Begin (CustomCrew.cpp)\n")
    super(selected);

    auto bex = CBOX_EX(this);
    for (ActivatedPowerButton &pButton : bex->powerButtons)
    {
        pButton.button.SetActive(pCrew->GetPowerOwner() == 0 && pButton.power->PowerReady() == PowerReadyState::POWER_READY && !pCrew->bDead);
    }
}

HOOK_METHOD_PRIORITY(CrewBox, OnRender, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewBox::OnRender -> Begin (CustomCrew.cpp)\n")
    //return super();
    mindControlled.Update();
    stunned.Update();

    auto crew = pCrew;
    auto health = crew->health;
    if (health.first > 25.f || health.first == 0.f || std::floor(health.first) == std::floor(health.second))
    {
        flashHealthTracker.Stop(false);
    }

    if (number < 0)
    {
        return;
    }

    GL_Color boxColor = GL_Color();
    GL_Color boxOutlineColor;
    if (!crew->bMindControlled)
    {
        if (!bSelectable)
        {
            boxColor.r = 0.494f;
            boxColor.g = 0.858f;
            boxColor.b = 0.882f;
        }
        else
        {
            auto selectionState = crew->selectionState;
            if (selectionState == 1)
            {
                boxColor.r = 0.47f;
                boxColor.g = 1.f;
                boxColor.b = 0.47f;
            }
            else if (crew->fStunTime > 0.f)
            {
                boxColor.r = 1.f;
                boxColor.g = 1.f;
                boxColor.b = 0.392f;
            }
            else if (selectionState == 2)
            {
                boxColor.r = 0.921f;
                boxColor.g = 0.921f;
                boxColor.b = 0.921f;
            }
            else if (flashHealthTracker.running && flashHealthTracker.Progress(-1.f) < 0.5f)
            {
                boxColor.r = 1.f;
                boxColor.g = 0.392f;
                boxColor.b = 0.392f;
            }
            else
            {
                boxColor.r = 0.392f;
                boxColor.g = 0.392f;
                boxColor.b = 0.392f;
            }
        }

        boxOutlineColor = boxColor;
    }
    else
    {
        if (crew->iShipId == 0)
        {
            if (!bSelectable)
            {
                boxColor.r = 0.494f;
                boxColor.g = 0.858f;
                boxColor.b = 0.882f;
            }
            else
            {
                boxColor.r = 1.f;
                boxColor.g = 0.f;
                boxColor.b = 1.f;
            }
            boxOutlineColor = boxColor;
        }
        else
        {
            if (!bSelectable)
            {
                boxColor.r = 1.f;
                boxColor.g = 0.f;
                boxColor.b = 0.f;
                boxOutlineColor.r = 0.494f;
                boxOutlineColor.g = 0.858f;
                boxOutlineColor.b = 0.882f;
            }
            else
            {
                auto selectionState = crew->selectionState;
                if (selectionState == 1)
                {
                    boxColor.r = 1.f;
                    boxColor.g = 0.47f;
                    boxColor.b = 0.47f;
                    boxOutlineColor.r = 0.47f;
                    boxOutlineColor.g = 1.f;
                    boxOutlineColor.b = 0.47f;
                }
                else if (crew->fStunTime > 0.f)
                {
                    boxColor.r = 1.f;
                    boxColor.g = 0.f;
                    boxColor.b = 0.f;
                    boxOutlineColor.r = 1.f;
                    boxOutlineColor.g = 1.f;
                    boxOutlineColor.b = 0.392f;
                }
                else if (selectionState == 2)
                {
                    boxColor.r = 1.f;
                    boxColor.g = 0.8f;
                    boxColor.b = 0.8f;
                    boxOutlineColor.r = 1.f;
                    boxOutlineColor.g = 0.8f;
                    boxOutlineColor.b = 0.8f;
                }
                else
                {
                    boxColor.r = 1.f;
                    boxColor.g = 0.f;
                    boxColor.b = 0.f;
                    boxOutlineColor.r = 0.6f;
                    boxOutlineColor.g = 0.3f;
                    boxOutlineColor.b = 0.3f;
                }
            }
        }
    }

    boxColor.a = 0.25f;
    boxOutlineColor.a = 1.f;

    if (!mouseHover)
    {
        CSurface::GL_RenderPrimitiveWithColor(boxBackground, boxColor);
        CSurface::GL_RenderPrimitiveWithColor(boxOutline, boxOutlineColor);
    }
    else
    {
        CSurface::GL_RenderPrimitiveWithColor(skillBoxBackground, boxColor);
        CSurface::GL_RenderPrimitiveWithColor(skillBoxOutline, boxOutlineColor);
    }

    auto ex = CM_EX(crew);
    auto bex = CBOX_EX(this);

    for (CrewAbilityCooldownBar &bar : bex->cooldownBars)
    {
        bar.OnRender();
    }
    for (CrewAbilityChargesBar &bar : bex->chargesBars)
    {
        bar.OnRender();
    }

    int healthMaxWidth = box.w - 37;
    int healthWidth = std::floor((health.first / health.second) * healthMaxWidth);

    if (health.first != 0 && healthWidth == 0)
    {
        healthWidth = 1;
    }

    if (healthWidth == lastHealthWidth)
    {
        CSurface::GL_RenderPrimitive(healthBar);
    }
    else
    {
        CSurface::GL_DestroyPrimitive(healthBar);

        lastHealthWidth = healthWidth;
        GL_Primitive *prim = nullptr;
        if (health.first <= 0)
        {
            healthBar = nullptr;
        }
        else
        {
            GL_Color healthColor = GL_Color(0.f, 1.f, 0.f, 1.f);

            if (health.first < health.second)
            {
                if (healthWidth < healthMaxWidth / 2)
                {
                    healthColor.g = ((float)healthWidth) / ((float)healthMaxWidth / 2);
                }
                else
                {
                    healthColor.g = 1.f;
                }

                healthColor.r = 1.f;
            }

            if (healthColor.g >= 1.f)
            {
                healthColor.g = 1.f;
            }

            prim = CSurface::GL_CreateRectPrimitive(box.x + 33, box.y + box.h - 8, healthWidth, 4, healthColor);
            healthBar = prim;
        }

        if (prim)
        {
            CSurface::GL_RenderPrimitive(prim);
        }
    }

    if (mouseHover)
    {
        for (ActivatedPowerButton &pButton : bex->powerButtons)
        {
            pButton.button.OnRender();
        }

        int skillNumber = 0;

        for (auto i : crew->blueprint.skillLevel)
        {
            crew->blueprint.RenderSkill(box.x + box.w + 7, (box.y + bex->skillOffset) + 24 * skillNumber, 40, 8, skillNumber);

            skillNumber++;
        }

        if (!sTooltip.empty())
        {
            Point tooltipPosition = Point(box.x + box.w + 95, box.y);
            auto mouse = G_->GetMouseControl();

            mouse->SetTooltip(sTooltip);
            mouse->QueueStaticTooltip(tooltipPosition);
            mouse->InstantTooltip();
        }
    }
}

HOOK_METHOD_PRIORITY(CrewBox, RenderIcon, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewBox::RenderIcon -> Begin (CustomCrew.cpp)\n")
    auto bex = CBOX_EX(this);

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(box.x+bex->crewPos.x, box.y+bex->crewPos.y, 0.f);

    pCrew->crewAnim->RenderIcon(true);

    if (pCrew->bMindControlled)
    {
        // Render mind controlled animation in magenta
        mindControlled.OnRender(1.f,GL_Color(1.f,0.f,1.f,1.f),false);
    }
    else if (pCrew->fStunTime > 0.f)
    {
        // Render stunned animation in yellow
        stunned.OnRender(1.f,GL_Color(1.f,1.f,0.f,1.f),false);
    }

    CSurface::GL_PopMatrix();
}

HOOK_METHOD(CrewBox, GetSelected, (int mouseX, int mouseY) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD -> CrewBox::GetSelected -> Begin (CustomCrew.cpp)\n")
    auto ret = super(mouseX, mouseY);

    bool appendHotkey = false;

    if (CustomCrewManager::GetInstance()->IsRace(pCrew->species))
    {
        auto ex = CM_EX(pCrew);
        auto bex = CBOX_EX(this);

        bool found = !mouseHover; // if !mouseHover then don't hover any power buttons, just set them all to false
        for (ActivatedPowerButton &pButton: bex->powerButtons)
        {
            if (!found)
            {
                // find the button that the mouse is over
                pButton.button.MouseMove(mouseX, mouseY, true);
                if (pButton.button.bHover) // todo: move the stuff in here into its own function
                {
                    found = true;
                    bool skipAppend = false;

                    std::string tooltip = "";
                    if (pCrew->GetPowerOwner() != 0)
                    {
                        tooltip = G_->GetTextLibrary()->GetText("power_not_ready_mind_enemy");
                    }
                    else
                    {
                        PowerReadyState state = pButton.power->PowerReady();

                        if (state == PowerReadyState::POWER_READY)
                        {
                            appendHotkey = true;

                            // run callback
                            auto context = Global::GetInstance()->getLuaContext();
                            SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pActivatedPower, 0);
                            lua_pushinteger(context->GetLua(), state);
                            int nRet = context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::POWER_TOOLTIP, 2, 2);
                            if (nRet == 2)
                            {
                                tooltip = lua_tostring(context->GetLua(), -nRet);
                                bool skipAppend = lua_toboolean(context->GetLua(), -nRet+1);
                                lua_pop(context->GetLua(), nRet+2);
                            }
                            else // no return from callback
                            {
                                lua_pop(context->GetLua(), 2);
                                if (!pButton.power->def->tooltip.data.empty())
                                {
                                    tooltip = pButton.power->def->tooltip.GetText();
                                }
                            }
                        }
                        else
                        {
                            auto ex = CM_EX(pCrew);
                            auto powerReq = &pButton.power->def->playerReq;
                            if (state == POWER_NOT_READY_COOLDOWN && pButton.power->def->chargeReq != nullptr)
                            {
                                powerReq = pButton.power->def->chargeReq;
                                state = pButton.power->PowerReq(powerReq);
                                if (state == POWER_READY) state = POWER_NOT_READY_COOLDOWN;
                            }

                            // run callback
                            auto context = Global::GetInstance()->getLuaContext();
                            SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pActivatedPower, 0);
                            lua_pushinteger(context->GetLua(), state);
                            int nRet = context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::POWER_TOOLTIP, 2, 2);
                            if (nRet == 2)
                            {
                                tooltip = lua_tostring(context->GetLua(), -nRet);
                                bool skipAppend = lua_toboolean(context->GetLua(), -nRet+1);
                                lua_pop(context->GetLua(), nRet+2);
                            }
                            else // no return from callback
                            {
                                lua_pop(context->GetLua(), 2);

                                std::string tooltipName = "";
                                std::string replaceValue = "";


                                switch (state)
                                {
                                case POWER_NOT_READY_COOLDOWN:
                                    tooltipName = "power_not_ready";
                                    break;
                                case POWER_NOT_READY_ACTIVATED:
                                    tooltipName = "power_not_ready_activated";
                                    break;
                                case POWER_NOT_READY_PLAYER_SHIP:
                                    tooltipName = "power_not_ready_player_ship";
                                    break;
                                case POWER_NOT_READY_ENEMY_SHIP:
                                    tooltipName = "power_not_ready_enemy_ship";
                                    break;
                                case POWER_NOT_READY_ENEMY_IN_ROOM:
                                    tooltipName = "power_not_ready_enemy_in_room";
                                    break;
                                case POWER_NOT_READY_FRIENDLY_IN_ROOM:
                                    tooltipName = "power_not_ready_friendly_in_room";
                                    break;
                                case POWER_NOT_READY_WHITELIST:
                                    tooltipName = "power_not_ready_whitelist";
                                    break;
                                case POWER_NOT_READY_ENEMY_WHITELIST:
                                    tooltipName = "power_not_ready_enemy_whitelist";
                                    break;
                                case POWER_NOT_READY_FRIENDLY_WHITELIST:
                                    tooltipName = "power_not_ready_friendly_whitelist";
                                    break;
                                case POWER_NOT_READY_ENEMY_BLACKLIST:
                                    tooltipName = "power_not_ready_enemy_blacklist";
                                    break;
                                case POWER_NOT_READY_FRIENDLY_BLACKLIST:
                                    tooltipName = "power_not_ready_friendly_blacklist";
                                    break;
                                case POWER_NOT_READY_SYSTEM_IN_ROOM:
                                    tooltipName = "power_not_ready_system_in_room";
                                    break;
                                case POWER_NOT_READY_SYSTEM_DAMAGED:
                                    tooltipName = "power_not_ready_system_damaged";
                                    break;
                                case POWER_NOT_READY_AI_DISABLED:
                                    tooltipName = "power_not_ready_ai_disabled";
                                    break;
                                case POWER_NOT_READY_HAS_CLONEBAY:
                                    tooltipName = "power_not_ready_has_clonebay";
                                    break;
                                case POWER_NOT_READY_OUT_OF_COMBAT:
                                    tooltipName = "power_not_ready_out_of_combat";
                                    break;
                                case POWER_NOT_READY_IN_COMBAT:
                                    tooltipName = "power_not_ready_in_combat";
                                    break;
                                case POWER_NOT_READY_SYSTEM:
                                    tooltipName = "power_not_ready_system";
                                    {
                                        SystemBlueprint* bp = G_->GetBlueprints()->GetSystemBlueprint(ShipSystem::SystemIdToName(powerReq->requiredSystem));
                                        if (bp != nullptr) replaceValue = bp->desc.title.GetText();
                                    }
                                    break;
                                case POWER_NOT_READY_SYSTEM_FUNCTIONAL:
                                    tooltipName = "power_not_ready_system_functional";
                                    {
                                        SystemBlueprint* bp = G_->GetBlueprints()->GetSystemBlueprint(ShipSystem::SystemIdToName(powerReq->requiredSystem));
                                        if (bp != nullptr) replaceValue = bp->desc.title.GetText();
                                    }
                                    break;
                                case POWER_NOT_READY_MIN_HEALTH:
                                    tooltipName = "power_not_ready_min_health";
                                    replaceValue = boost::lexical_cast<std::string>(powerReq->minHealth.value);
                                    break;
                                case POWER_NOT_READY_MAX_HEALTH:
                                    tooltipName = "power_not_ready_max_health";
                                    replaceValue = boost::lexical_cast<std::string>(powerReq->maxHealth.value);
                                    break;
                                case POWER_NOT_READY_CHARGES:
                                    tooltipName = "power_not_ready_charges";
                                    break;
                                case POWER_NOT_READY_SILENCED:
                                    tooltipName = "power_not_ready_silenced";
                                    break;
                                case POWER_NOT_READY_EXTRACONDITION_OR:
                                    tooltip = powerReq->extraOrConditionsTooltip.GetText();
                                    break;
                                default:
                                    if (state >= POWER_NOT_READY_EXTRACONDITION_FALSE)
                                    {
                                        tooltipName = powerReadyStateExtraTextFalse[state - POWER_NOT_READY_EXTRACONDITION_FALSE];
                                    }
                                    else if (state >= POWER_NOT_READY_EXTRACONDITION_TRUE)
                                    {
                                        tooltipName = powerReadyStateExtraTextTrue[state - POWER_NOT_READY_EXTRACONDITION_TRUE];
                                    }
                                    break;
                                }

                                if (!tooltipName.empty())
                                {
                                    tooltip = G_->GetTextLibrary()->GetText(tooltipName);
                                    if (!replaceValue.empty())
                                    {
                                        boost::algorithm::replace_all(tooltip, "\\1", replaceValue);
                                    }
                                }
                            }
                        }
                    }

                    if (!tooltip.empty())
                    {
                        sTooltip = tooltip;
                    }

                    if (!skipAppend) // if callback sets skipAppend then do not append extra info such as charges or hotkey
                    {
                        if (pButton.power->def->powerCharges > -1)
                        {
                            std::string tooltip = G_->GetTextLibrary()->GetText("power_number_charges");
                            boost::algorithm::replace_all(tooltip, "\\1", boost::lexical_cast<std::string>(pButton.power->powerCharges.first));
                            boost::algorithm::replace_all(tooltip, "\\2", boost::lexical_cast<std::string>(pButton.power->powerCharges.second));
                            sTooltip = sTooltip + "\n" + tooltip;
                        }

                        if (appendHotkey)
                        {
                            std::string tooltip = G_->GetTextLibrary()->GetText("hotkey");
                            std::string replaceWith = Settings::GetHotkeyName("lockdown");
                            boost::algorithm::replace_all(tooltip, "\\1", replaceWith);
                            sTooltip = sTooltip + "\n" + tooltip;
                        }
                    }
                }
            }
            else
            {
                pButton.button.bHover = false;
            }
        }

        // If hovered button not found then check skills
        if (!found && mouseX > skillBox.x && mouseX < skillBox.x+skillBox.w && mouseY > skillBox.y && mouseY < skillBox.y+skillBox.h)
        {
            sTooltip = "";
            for (int i=0; i<6; ++i)
            {
                int skillY = box.y + 24*i + bex->skillOffset;
                if (mouseY > skillY + 3 && mouseY < skillY + 21)
                {
                    sTooltip = CrewMember::GetSkillTooltip(i,pCrew->GetSkillLevel(i),pCrew->GetSkillProgress(i),false);
                    break;
                }
            }
        }
    }

    return ret;
}

HOOK_METHOD(CrewMember, OnRender, (bool outlineOnly) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::OnRender -> Begin (CustomCrew.cpp)\n")
    super(outlineOnly);

    if (bDead) return;
    if (outlineOnly) return;

    CrewMember_Extend *ex = CM_EX(this);
    CrewAnimation_Extend *aex = CMA_EX(crewAnim);

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(x, y);

    // Render ability temporary effect animations
    for (ActivatedPower *power : ex->crewPowers)
    {
        if (power->tempEffectAnim && !power->tempEffectAnim->tracker.done && power->tempEffectAnim->tracker.running)
        {
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(-power->tempEffectAnim->info.frameWidth / 2, -power->tempEffectAnim->info.frameHeight / 2);
            CSurface::GL_Translate(0, PositionShift());
            power->tempEffectAnim->OnRender(1.f, COLOR_WHITE, false);
            CSurface::GL_PopMatrix();
        }
    }

    // Render stat boost animations
    for (auto boostAnim : aex->boostAnim)
    {
        if (boostAnim.second != nullptr && !boostAnim.second->tracker.done && boostAnim.second->tracker.running)
        {
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(-boostAnim.second->info.frameWidth / 2, -boostAnim.second->info.frameHeight / 2);
            CSurface::GL_Translate(0, PositionShift());
            boostAnim.second->OnRender(1.f, COLOR_WHITE, false);
            CSurface::GL_PopMatrix();
        }
    }

    CSurface::GL_PopMatrix();
}

HOOK_METHOD(CrewMember, OnRenderHealth, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::OnRenderHealth -> Begin (CustomCrew.cpp)\n")

    CrewMember_Extend *ex = CM_EX(this);
    CrewAnimation_Extend *aex = CMA_EX(crewAnim);

    // Render ability animations
    for (ActivatedPower *power : ex->crewPowers)
    {
        if (power->effectAnim && !power->effectAnim->tracker.done && power->effectAnim->tracker.running)
        {
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(power->effectPos.x, power->effectPos.y);
            power->effectAnim->OnRender(1.f, COLOR_WHITE, false);
            CSurface::GL_PopMatrix();
        }

        if (power->effectFinishAnim && !power->effectFinishAnim->tracker.done && power->effectFinishAnim->tracker.running)
        {
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(x, y);
            CSurface::GL_Translate(-power->effectFinishAnim->info.frameWidth / 2, -power->effectFinishAnim->info.frameHeight / 2);
            power->effectFinishAnim->OnRender(1.f, COLOR_WHITE, false);
            CSurface::GL_PopMatrix();
        }

        for (Animation& anim : power->extraAnims)
        {
            anim.OnRender(1.f, COLOR_WHITE, false);
        }
    }

    super();
}

HOOK_METHOD(CrewAnimation, OnRender, (float scale, int selectedState, bool outlineOnly) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::OnRender -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    if (outlineOnly) return super(scale, selectedState, outlineOnly);

    auto aex = CMA_EX(this);
    CrewMember_Extend *ex = aex->crew ? CM_EX(aex->crew) : nullptr;

    if (ex)
    {
        bool baseVisible = true;
        std::vector<GL_Texture*> strips = {};

        for (auto powerIt = ex->crewPowers.rbegin(); powerIt != ex->crewPowers.rend(); powerIt++)
        {
            ActivatedPower *power = *powerIt;
            if (power->temporaryPowerActive)
            {
                if (!power->def->tempPower.baseVisible)
                {
                    baseVisible = false;
                    strips.clear();
                }
                if (power->tempEffectStrip) strips.push_back(power->tempEffectStrip);
            }
        }

        if (baseVisible)
        {
            super(scale, selectedState, outlineOnly);
        }

        if (!strips.empty())
        {
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(lastPosition.x - 17.f, lastPosition.y - 17.f);

            for (GL_Texture *strip : strips)
            {
                anims[direction][status].SetAnimationId(strip);
                anims[direction][status].OnRender(1.f, COLOR_WHITE, false);
            }

            CSurface::GL_PopMatrix();
        }
    }
    else
    {
        super(scale, selectedState, outlineOnly);
    }
}

HOOK_METHOD(CrewBlueprint, RenderIcon, (float scale) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewBlueprint::RenderIcon -> Begin (CustomCrew.cpp)\n")

    std::string race; // race to render

    CustomCrewManager* customCrew = CustomCrewManager::GetInstance();

    // check if crewmember is a custom race
    if (customCrew->IsRace(name))
    {
        // get definition and check if animSheet is defined
        auto def = customCrew->GetDefinition(name);
        if (!def->animSheet[male].empty())
        {
            // set race to render
            race = def->animSheet[male];

            // load the animation frame and set the position and scaling
            CSurface::GL_PushMatrix();
            Animation walkDown = G_->GetAnimationControl()->GetAnimation(race + "_walk_down");
            walkDown.SetCurrentFrame(0);
            CSurface::GL_Translate(std::floor(std::floor((-scale * walkDown.info.frameWidth)) * 0.5f) + 1, std::floor(std::floor((-scale * walkDown.info.frameHeight)) * 0.5f) + 1);
            CSurface::GL_Scale(scale, scale, 0.f);

            // load and render base image
            auto base = G_->GetResources()->GetImageId("people/" + race + "_base.png");
            walkDown.SetAnimationId(base);
            walkDown.OnRender(1.f, COLOR_WHITE, false);

            // load and render layer images
            for (int i=0; i<colorChoices.size(); ++i)
            {
                std::stringstream layerImage;
                layerImage << "people/" << race << "_layer" << i+1 << ".png";

                int colorChoice = colorChoices[i];
                if (colorChoice == -1) colorChoice = 0;

                auto layer = G_->GetResources()->GetImageId(layerImage.str());
                walkDown.SetAnimationId(layer);
                walkDown.OnRender(1.f, colorLayers[i][colorChoice], false);
            }

            // pop the position/scale transformation
            CSurface::GL_PopMatrix();

            // don't call super
            return;
        }
    }

    super(scale);
}

static bool blockSetBonusPower = false;

HOOK_METHOD(ShipSystem, SetBonusPower, (int amount, int permanentPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::SetBonusPower -> Begin (CustomCrew.cpp)\n")
    if (blockSetBonusPower) return;

    super(amount, permanentPower);
}

HOOK_METHOD(WeaponSystem, SetBonusPower, (int amount, int permanentPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponSystem::SetBonusPower -> Begin (CustomCrew.cpp)\n")
    if (blockSetBonusPower) return;

    super(amount, permanentPower);
}

HOOK_METHOD(DroneSystem, SetBonusPower, (int amount, int permanentPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> DroneSystem::SetBonusPower -> Begin (CustomCrew.cpp)\n")
    if (blockSetBonusPower) return;

    super(amount, permanentPower);
}



HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnLoop -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();

    for (auto i : vSystemList)
    {
        int bonusPowerCounter = 0;
        int permanentPowerCounter = 0;

        for (auto j : vCrewList)
        {
            if (i->roomId == j->iRoomId && j->iShipId == iShipId && j->Functional())
            {
                if (custom->IsRace(j->species))
                {
                    auto def = custom->GetDefinition(j->species);

                    auto ex = CM_EX(j);

                    int bonusPower = ex->CalculateStat(CrewStat::BONUS_POWER, def);

                    bonusPowerCounter += bonusPower;

                    if (j->AtFinalGoal() && !j->IsDrone())
                    {
                        permanentPowerCounter += bonusPower;
                    }
                }

                if (j->ProvidesPower())
                {
                    bonusPowerCounter++;
                    if (j->AtFinalGoal() && !j->IsDrone())
                    {
                        permanentPowerCounter++;
                    }
                }
            }
        }

        i->SetBonusPower(bonusPowerCounter, permanentPowerCounter);
    }

    blockSetBonusPower = true;
    super();
    blockSetBonusPower = false;
}

static float sabotageMultiplier = 1.f;



HOOK_METHOD(ShipSystem, PartialDamage, (float amount) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::PartialDamage -> Begin (CustomCrew.cpp)\n")
    return super(amount * sabotageMultiplier);
}


HOOK_METHOD(CrewMember, UpdateRepair, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::UpdateRepair -> Begin (CustomCrew.cpp)\n")
    auto custom = CustomCrewManager::GetInstance();
    auto ex = CM_EX(this);
    auto def = custom->GetDefinition(this->species);
    if (custom->IsRace(species))
    {
        sabotageMultiplier = ex->CalculateStat(CrewStat::SABOTAGE_SPEED_MULTIPLIER, def);
    }

    super();

    sabotageMultiplier = 1.f;
}

static bool windowFrameCheck = false;
static int windowFrameHeight = 0;

HOOK_METHOD(WindowFrame, constructor, (int x, int y, int w, int h) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WindowFrame::constructor -> Begin (CustomCrew.cpp)\n")
    if (windowFrameCheck)
    {
        h = windowFrameHeight;
        windowFrameCheck = false;
    }

    super(x, y, w, h);
}

bool blockAnimationUpdate = false;

HOOK_METHOD(AnimationTracker, Update, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> AnimationTracker::Update -> Begin (CustomCrew.cpp)\n")
    if (blockAnimationUpdate) return;

    super();
}

HOOK_METHOD_PRIORITY(CrewMember, OnRenderHealth, 2000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::OnRenderHealth -> Begin (CustomCrew.cpp)\n")
    bool fullHealth = std::floor(health.first) == std::floor(health.second);

    if (fullHealth)
    {
        flashHealthTracker.SetProgress(0.5f);
        blockAnimationUpdate = true;
    }

    super();

    blockAnimationUpdate = false;

    if (fullHealth)
    {
        flashHealthTracker.Start(0.5f);
    }
}

HOOK_METHOD(CrewAI, PrioritizeIntruderRoom, (CrewMember *crew, int roomId, int target) -> int)
{
    LOG_HOOK("HOOK_METHOD -> CrewAI::PrioritizeIntruderRoom -> Begin (CustomCrew.cpp)\n")
    if (!crew->CanSabotage() && !CM_EX(crew)->isIonDrone)
    {
        if (ship->CountCrewShipId(roomId, !crew->iShipId) == 0)
        {
            return 1000;
        }
    }

    return super(crew, roomId, target);
}

HOOK_METHOD(CrewMember, Clone, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::Clone -> Begin (CustomCrew.cpp)\n")
    bool cloneLoseSkills = false;
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(this->species);

    auto ex = CM_EX(this);
    ex->CalculateStat(CrewStat::CLONE_LOSE_SKILLS, def, &cloneLoseSkills);
    if (!CustomCrewManager::GetInstance()->IsRace(species) || cloneLoseSkills) return super();

    bOutOfGame = false;
    bDead = false;
    fStunTime = 0.f;
    Restart();

    crewAnim->status = 6;
    crewAnim->direction = 0;
    crewAnim->anims[0][6].tracker.SetLoop(false, 0.f);
    crewAnim->anims[0][6].Start(true);
    crewAnim->anims[0][6].StartReverse(true);
    G_->GetSoundControl()->PlaySoundMix("cloneArrive", -1.f, false);
}

static bool needsIntruderControllable = false;

HOOK_METHOD(CrewMember, GetIntruder, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::GetIntruder -> Begin (CustomCrew.cpp)\n")
    if (needsIntruderControllable)
    {
        switch (currentShipId)
        {
        case 0:
            // Player ship version - neither intruders nor MC'd enemies will go heal, nor will controllable crew nor noAI crew.
            return (iShipId != 0) || bMindControlled || GetControllable();
        case 1:
            // Enemy ship version - intruders won't go heal, nor will controllable crew nor noAI crew. MC'd player crew will go heal.
            return super() || GetControllable();
        }
    }
    // Anywhere outside CheckForHealing
    return super();
}

HOOK_METHOD(CrewAI, CheckForHealing, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAI::CheckForHealing -> Begin (CustomCrew.cpp)\n")
    needsIntruderControllable = true;
    super();
    needsIntruderControllable = false;
}

HOOK_METHOD(CrewAI, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAI::OnLoop -> Begin (CustomCrew.cpp)\n")
    super();
    if (ship->iShipId == 0)
    {
        bool wasCalm = bCalmShip;

        // Health threshold for crew to run to medbay is 25% when bCalmShip is false and 99% when bCalmShip is true
        bCalmShip = false;
        CheckForHealing();
        bCalmShip = wasCalm;
    }
}

HOOK_METHOD(CrewAI, UpdateCrewMember, (int crewId) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAI::UpdateCrewMember -> Begin (CustomCrew.cpp)\n")
    auto crewMember = crewList[crewId];

    if (!crewMember->GetControllable() && !crewMember->bMindControlled && !crewMember->IsDead() && crewMember->iShipId == 0 && !crewMember->IsDrone())
    {
        super(crewId);
    }
    else
    {
        return super(crewId);
    }
}

HOOK_METHOD(CrewAI, PrioritizeTask, (CrewTask task, int crewId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> CrewAI::PrioritizeTask -> Begin (CustomCrew.cpp)\n")
    if (task.taskId == 0 && !crewList[crewId]->CanMan())
    {
        return 1001;
    }

    return super(task, crewId);
}

HOOK_METHOD(CrewMember, GetSavedPosition, () -> Slot)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::GetSavedPosition -> Begin (CustomCrew.cpp)\n")
    // WARNING: Logic change, potential bug introduced during transition from static to member.
    Slot ret = super();

    if (!this->GetControllable())
    {
        ret.roomId = this->finalGoal.roomId;
        ret.slotId = this->finalGoal.slotId;
        ret.worldLocation = this->finalGoal.worldLocation;

        return ret;
    }

    return ret;
}

HOOK_METHOD(ShipManager, GetSelectedCrewPoint, (int mX, int mY, bool intruder) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetSelectedCrewPoint -> Begin (CustomCrew.cpp)\n")
    if (vCrewList.empty())
    {
        return nullptr;
    }

    for (auto i : vCrewList)
    {
        if (i->ContainsPoint(mX, mY))
        {
            if (i->IsDead())
            {
                continue;
            }
            if (intruder != i->GetIntruder())
            {
                continue;
            }
            if (!i->GetControllable() && !intruder)
            {
                continue;
            }

            if (Point(i->x, i->y).Distance(Point(mX, mY)) <= 14)
            {
                return i;
            }
        }
    }

    return nullptr;
}

HOOK_METHOD(CrewControl, MouseMove, (int mX, int mY, int wX, int wY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewControl::MouseMove -> Begin (CustomCrew.cpp)\n")
    super(mX, mY, wX, wY);

    if (selectedDoor) return;

    for (auto i : shipManager->vCrewList)
    {
        if (i->Functional() && i->selectionState != 1 && std::find(potentialSelectedCrew.begin(), potentialSelectedCrew.end(), i) == potentialSelectedCrew.end())
        {
            Pointf pos = Pointf(i->x, i->y) - Pointf(17.f, 17.f);

            if (wX - pos.x < 35.f && wX - pos.x > 0.f && wY - pos.y < 35.f && wY - pos.y > 0.f)
            {
                potentialSelectedCrew.push_back(i);
                i->selectionState = 2;
            }
        }
    }

    selectedCrew.erase(std::remove_if(selectedCrew.begin(), selectedCrew.end(), [](CrewMember* crew) { return !crew->GetControllable(); }), selectedCrew.end());
}

HOOK_METHOD(CrewControl, SelectCrew, (bool keep_current) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewControl::SelectCrew -> Begin (CustomCrew.cpp)\n")
    if (keep_current)
    {
        potentialSelectedCrew.erase(std::remove_if(potentialSelectedCrew.begin(), potentialSelectedCrew.end(), [this](CrewMember* crew)
        {
            return std::find(selectedCrew.begin(), selectedCrew.end(), crew) != selectedCrew.end();
        }), potentialSelectedCrew.end());
    }
    super(keep_current);
}

HOOK_METHOD(CrewMember, GetTooltip, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::GetTooltip -> Begin (CustomCrew.cpp)\n")
    std::string ret = super();
    auto custom = CustomOptionsManager::GetInstance();
    if (custom->advancedCrewTooltips.currentValue)
    {
        auto ex = CM_EX(this);

        std::string tooltip = "";
        tooltip += "-" + this->blueprint.crewNameLong.GetText() + " (" + this->blueprint.desc.title.GetText() + "):" + '\n';
        int maxHealth = (int)this->health.second;
        if (this->health.first == 0)
        {
            tooltip += G_->GetTextLibrary()->GetText("advanced_health_tooltip") + ": " + G_->GetTextLibrary()->GetText("death_tooltip");
        }
        else if (this->health.first == this->health.second)
        {
            std::stringstream stream;
            tooltip += G_->GetTextLibrary()->GetText("advanced_health_tooltip") + ": " + std::to_string(maxHealth) + "/" + std::to_string(maxHealth) + " (100%)";
        }
        else if (custom->advancedCrewTooltipRounding.currentValue == 0)
        {
            tooltip += G_->GetTextLibrary()->GetText("advanced_health_tooltip") + ": " + std::to_string((int)this->health.first) + "/" + std::to_string(maxHealth) + " (" + std::to_string((int)(this->health.first / maxHealth * 100)) + "%)";
        }
        else
        {
            std::stringstream stream;
            stream << std::fixed <<std::setprecision(custom->advancedCrewTooltipRounding.currentValue) << this->health.first;
            tooltip += G_->GetTextLibrary()->GetText("advanced_health_tooltip") + ": " + stream.str() + "/" + std::to_string(maxHealth) + " (" + std::to_string((int)(this->health.first / maxHealth * 100)) + "%)";
        }

        if (ex->deathTimer)
        {
            tooltip += '\n';
            float timer = ex->deathTimer->currGoal - ex->deathTimer->currTime;

            if (timer > 0.f)
            {
                std::string currentText = G_->GetTextLibrary()->GetText("crew_death_time");
                std::stringstream stream;
                stream << std::fixed <<std::setprecision(1) << timer;
                currentText = boost::algorithm::replace_all_copy(currentText, "\\1", stream.str());
                tooltip += currentText;
            }
            else
            {
                std::string currentText = G_->GetTextLibrary()->GetText("crew_death_time_expired");
                tooltip += currentText;
            }
        }

        if (this->fStunTime != 0)
        {
            tooltip += '\n';
            std::stringstream stream;
            stream << std::fixed <<std::setprecision(1) << this->fStunTime * ex->CalculateStat(CrewStat::STUN_MULTIPLIER, CustomCrewManager::GetInstance()->GetDefinition(this->species));
            std::string currentText = G_->GetTextLibrary()->GetText("crew_stun_time");
            currentText = boost::algorithm::replace_all_copy(currentText, "\\1", stream.str());
            tooltip += currentText;
        }

        if (custom->showEnemyPowers.currentValue && this->iShipId == 1)
        {
            tooltip += '\n';
            for (auto j : this->blueprint.powers)
            {
                tooltip += "*" + j.GetText() + '\n';
            }
            boost::trim_right(tooltip);
        }
        else if (custom->showAllyPowers.currentValue && this->iShipId == 0)
        {
            tooltip += '\n';
            for (auto j : this->blueprint.powers)
            {
                tooltip += "*" + j.GetText() + '\n';
            }
            boost::trim_right(tooltip);
        }
        tooltip += '\n';

//        if (this->bMindControlled)
//        {
//            tooltip += G_->GetTextLibrary()->GetText("mind_controlled_tooltip");
//        }
        boost::trim_right(tooltip);
        ret.assign(tooltip);
        return ret;
    }
    else
    {
        return ret;
    }
}

HOOK_METHOD(CrewAnimation, FireShot, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::FireShot -> Begin (CustomCrew.cpp)\n")
    if (CMA_EX(this)->isMantisAnimation)
    {
        anims[0][7].SetProgress(anims[direction][status].tracker.Progress(-1.f));
        anims[1][7].SetProgress(anims[direction][status].tracker.Progress(-1.f));
        anims[2][7].SetProgress(anims[direction][status].tracker.Progress(-1.f));
        anims[3][7].SetProgress(anims[direction][status].tracker.Progress(-1.f));

        auto frame = anims[direction][status].currentFrame;
        bool ret = false;

        if (frame == 3)
        {
            ret = false;
            if (!uniqueBool1)
            {
                uniqueBool1 = true;
                ret = true;
            }
        }
        else if (frame > 2)
        {
            ret = false;
        }
        else
        {
            uniqueBool1 = false;
            ret = false;
        }

        return ret;
    }

    return super();
}

HOOK_METHOD(CrewAnimation, GetFiringFrame, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::GetFiringFrame -> Begin (CustomCrew.cpp)\n")
    if (CMA_EX(this)->isMantisAnimation)
    {
        return -1;
    }

    return super();
}

CrewAnimation_Extend::~CrewAnimation_Extend()
{
    for (auto &it : boostAnim)
    {
        delete it.second;
    }
}

// Hack door ability
ShipManager* shipManagerForShip = nullptr;

HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnLoop -> Begin (CustomCrew.cpp)\n")
    shipManagerForShip = this;
    super();
    shipManagerForShip = nullptr;
}

HOOK_METHOD(Ship, OnLoop, (std::vector<float> &oxygenLevels) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnLoop -> Begin (CustomCrew.cpp)\n")
    if (shipManagerForShip != nullptr)
    {
        CustomCrewManager *custom = CustomCrewManager::GetInstance();
        auto doors = std::unordered_map<Door*,int>();

        for (auto crew : shipManagerForShip->vCrewList)
        {
            if (custom->IsRace(crew->species) && !crew->IsDead() && crew->Functional() && crew->iRoomId >= 0)
            {
                auto ex = CM_EX(crew);
                auto def = custom->GetDefinition(crew->species);
                bool hackDoors;
                ex->CalculateStat(CrewStat::HACK_DOORS, def, &hackDoors);
                if (hackDoors)
                {

                    for (auto door : vDoorList)
                    {
                        if (door->iRoom1 == crew->iRoomId || door->iRoom2 == crew->iRoomId)
                        {
                            auto it = doors.emplace(door, 0);
                            it.first->second += (crew->intruder ? 1 : -1);
                        }
                    }
                    for (auto door : vOuterAirlocks)
                    {
                        if (door->iRoom1 == crew->iRoomId || door->iRoom2 == crew->iRoomId)
                        {
                            auto it = doors.emplace(door, 0);
                            it.first->second += (crew->intruder ? 1 : -1);
                        }
                    }
                }
            }
        }

        for (auto door : doors)
        {
            if (!door.first->iHacked && door.second > 0)
            {
                door.first->iHacked = 1;
            }
            else if (door.first->iHacked && door.second < 0)
            {
                door.first->iHacked = 0;
            }
        }
    }

    super(oxygenLevels);
}

// GetClosestSlot bug fix for unusual layouts
HOOK_METHOD(ShipGraph, GetClosestSlot, (Point pos, int shipId, bool intruder) -> Slot)
{
    LOG_HOOK("HOOK_METHOD -> ShipGraph::GetClosestSlot -> Begin (CustomCrew.cpp)\n")
    for (Room *room : this->rooms)
    {
        Globals::Rect rect = room->rect;
        if (pos.x >= rect.x && pos.x <= rect.x + rect.w && pos.y >= rect.y && pos.y <= rect.y + rect.h)
        {
            return super(pos, shipId, intruder);
        }
    }
    // default return if not in any room
    // TODO: Might have to call super first, not sure if compiler will be smart enough to handle this with the implicit value thing?
    Slot slot = Slot();
    slot.roomId = -1;
    slot.slotId = -1;
    slot.worldLocation = {-1,-1};
    return slot;
}

HOOK_METHOD(CrewControl, SelectPotentialCrew, (CrewMember *crew, bool allowTeleportLeaving) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewControl::SelectPotentialCrew -> Begin (CustomCrew.cpp)\n")
    if (!crew) return;

    if (!crew->GetControllable()) return;

    if (allowTeleportLeaving || (crew->crewAnim->status != 6) || crew->crewAnim->anims[0][6].tracker.reverse)
    {
        if (std::find(potentialSelectedCrew.begin(), potentialSelectedCrew.end(), crew) == potentialSelectedCrew.end())
        {
            potentialSelectedCrew.push_back(crew);
        }
    }
}

// Player uses ability via hotkey - only first ability
HOOK_METHOD(CrewControl, KeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewControl::KeyDown -> Begin (CustomCrew.cpp)\n")
    if (key == Settings::GetHotkey("lockdown"))
    {
        for (auto i : selectedCrew)
        {
            auto ex = CM_EX(i);

            if (ex->hasSpecialPower)
            {
                bool activated = false;
                for (ActivatedPower *power : ex->crewPowers) // first check for "always" hotkeys
                {
                    if (!power->enabled) continue;

                    if (power->def->onHotkey == ActivatedPowerDefinition::HOTKEY_ALWAYS)
                    {
                        if (power->PowerReady() == PowerReadyState::POWER_READY && i->GetPowerOwner() == 0)
                        {
                            power->PreparePower();
                            activated = true;
                        }
                    }
                }
                for (ActivatedPower *power : ex->crewPowers) // then check for "first" hotkeys if none were activated from "always"
                {
                    if (!power->enabled) continue;

                    if (power->def->onHotkey == ActivatedPowerDefinition::HOTKEY_FIRST)
                    {
                        if (power->PowerReady() == PowerReadyState::POWER_READY && i->GetPowerOwner() == 0)
                        {
                            power->PreparePower();
                            break;
                        }
                    }
                }
            }
        }
    }
    else
    {
        super(key);
    }
}

// Player uses ability via button
HOOK_METHOD(CrewBox, MouseClick, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CrewBox::MouseClick -> Begin (CustomCrew.cpp)\n")

    auto bex = CBOX_EX(this);

    for (ActivatedPowerButton &pButton : bex->powerButtons)
    {
        if (pButton.button.bActive && pButton.button.bHover)
        {
            if (pButton.power->PowerReady() == PowerReadyState::POWER_READY && pCrew->GetPowerOwner() == 0)
            {
                pButton.power->PreparePower();
            }
            return true;
        }
    }
    return false;
}

HOOK_METHOD(CrewControl, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewControl::OnLoop -> Begin (CustomCrew.cpp)\n")
    crewMessage.Update();
    if (crewMessage.done)
    {
        crewMessage.Stop(false);
    }

    UpdateCrewBoxes();
    if (!bUpdated)
    {
        mouseDown = false;
        return;
    }
    std::vector<CrewMember*> filteredSelectedCrew = std::vector<CrewMember*>();

    for (auto i : selectedCrew)
    {
        if (i->Functional() && !i->IsDead() && i->crewAnim->status != 3)
        {
            filteredSelectedCrew.push_back(i);
        }
    }

    selectedCrew = filteredSelectedCrew;

    std::vector<CrewMember*> filteredPotentialSelectedCrew = std::vector<CrewMember*>();

    for (auto i : potentialSelectedCrew)
    {
        if (i->Functional() && !i->IsDead() && i->crewAnim->status != 3)
        {
            filteredPotentialSelectedCrew.push_back(i);
        }
    }

    potentialSelectedCrew = filteredPotentialSelectedCrew;

    for (auto i : shipManager->vCrewList)
    {
        i->selectionState = 0;
    }
    if (combatControl->currentTarget)
    {
        for (auto i : combatControl->currentTarget->shipManager->vCrewList)
        {
            i->selectionState = 0;
        }
    }

    for (auto i : potentialSelectedCrew)
    {
        i->selectionState = 2;
    }

    for (auto i : selectedCrew)
    {
        i->selectionState = 1;
    }

    if (!selectedCrew.empty() || !potentialSelectedCrew.empty())
    {
        G_->GetMouseControl()->valid = 1;
        G_->GetMouseControl()->lastValid = 1;
    }

    if (selectedDoor)
    {
        G_->GetMouseControl()->SetDoor(selectedDoor->bOpen ? 2 : ((int)selectedDoor->forcedOpen.running) + 1);
    }

    std::string tooltip = shipManager->GetTooltip(worldCurrentMouse.x, worldCurrentMouse.y);

    if (tooltip.empty())
    {
        tooltip = combatControl->GetCrewTooltip(currentMouse.x, currentMouse.y);
    }

    if (!tooltip.empty())
    {
        G_->GetMouseControl()->SetTooltip(tooltip);
    }

    for (int i = 0; i < crewBoxes.size(); i++)
    {
        crewBoxes[i]->OnLoop(selectedCrewBox == i);
    }

    bUpdated = false;
}

// Show path for mind controlled enemy crew.
HOOK_METHOD(CrewMember, OnRenderPath, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::OnRenderPath -> Begin (CustomCrew.cpp)\n")
    bool setShipId = false;
    if (bMindControlled && iShipId == 1)
    {
        ShipManager *ship = G_->GetShipManager(0);
        if (ship && ship->HasAugmentation("MIND_ORDER"))
        {
            setShipId = true;
            iShipId = 0;
        }
    }
    super();

    if (setShipId) iShipId = 1;
}

// Refresh boxes when the mind control status changes on a crewmember
HOOK_METHOD(CrewMember, SetMindControl, (bool controlled) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::SetMindControl -> Begin (CustomCrew.cpp)\n")
    super(controlled);
    if (iShipId == 1)
    {
        ShipManager *playerShip = G_->GetShipManager(0);
        if (playerShip && playerShip->HasAugmentation("MIND_ORDER"))
        {
            if (bMindControlled)
            {
                G_->GetCrewFactory()->MoveCrewMemberToEnd(this);
            }
            G_->GetCApp()->gui->crewControl.ClearCrewBoxes();
            G_->GetCApp()->gui->crewControl.UpdateCrewBoxes();
        }
    }
}

// Selectable/controllable split - doesn't work properly with touchscreen
HOOK_METHOD(CrewControl, RButton, (int mX, int mY, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewControl::RButton -> Begin (CustomCrew.cpp)\n")
    requiresFullControl = 1;
    super(mX, mY, shiftHeld);
    requiresFullControl = 0;
}

// Selectable/controllable split for player
HOOK_METHOD(ShipManager, RestoreCrewPositions, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::RestoreCrewPositions -> Begin (CustomCrew.cpp)\n")
    requiresFullControl = 1;
    bool ret = super();
    requiresFullControl = 0;
    return ret;
}

HOOK_METHOD(ShipManager, CommandCrewMoveRoom, (CrewMember* crew, int room) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CommandCrewMoveRoom -> Begin (CustomCrew.cpp)\n")

    // Selectable/controllable split; requiresFullControl == 1 when player is ordering
    if (requiresFullControl == 1)
    {
        if (!crew->GetControllable()) return false;
    }
    // requiresFullControl == -1 when AI is ordering
    else if (requiresFullControl == -1)
    {
        CrewMember_Extend *ex = CM_EX(crew);
        // check if crew is teleporting (leaving) within their own ship, if so block any orders so that the tile is reserved for them
        if ((ex->customTele.teleporting || crew->crewAnim->status == 6) && !crew->crewAnim->anims[0][6].tracker.reverse && ex->customTele.shipId == crew->currentShipId)
        {
            return false;
        }
        bool ret = super(crew, room);
        if (!ret)
        {
            if (crew->bDead || room == crew->iRoomId) return false;
            if (ex->customTele.teleporting || crew->crewAnim->status == 6) return false;
            if (!crew->Functional() || crew->fStunTime > 0.f) return false;
            if (ship.FullRoom(room, crew->GetIntruder())) return false;
            if (ex->CanTeleportMove(false))
            {
                ex->customTele.shipId = iShipId;
                ex->customTele.roomId = room;
                ex->customTele.slotId = -1;
                return true;
            }
        }
        return ret;
    }
    return super(crew, room);
}

// Selectable/controllable split for AI
HOOK_METHOD_PRIORITY(CrewAI, OnLoop, -100, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewAI::OnLoop -> Begin (CustomCrew.cpp)\n")
    requiresFullControl = -1;
    super();
    requiresFullControl = 0;
}

static std::unordered_map<CrewMember*, std::pair<bool, bool>> g_tempOutOfGame = std::unordered_map<CrewMember*, std::pair<bool, bool>>();

// Don't count noSlot crew towards crew counts
HOOK_METHOD(CrewMemberFactory, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMemberFactory::OnLoop -> Begin (CustomCrew.cpp)\n")

    CustomCrewManager *crewManager = CustomCrewManager::GetInstance();

    for (auto i : crewMembers)
    {
        bool noSlot;
        CM_EX(i)->CalculateStat(CrewStat::NO_SLOT, crewManager->GetDefinition(i->species), &noSlot);
        if (noSlot)
        {
            g_tempOutOfGame[i] = std::pair<bool, bool>(i->bOutOfGame, i->clone_ready);

            i->bOutOfGame = true;
            i->clone_ready = false;
        }
    }

    super();

    crewManager->crewCapacityUsed = 0.f;
    for (auto i : crewMembers)
    {
        if (i->iShipId == 0)
        {
            if (!i->bOutOfGame || i->clone_ready)
            {
                if (i->CountForVictory())
                {
                    crewManager->crewCapacityUsed += CM_EX(i)->CalculateStat(CrewStat::CREW_SLOTS, crewManager->GetDefinition(i->species));
                }
            }
        }
    }

    for (auto i : g_tempOutOfGame)
    {
        auto c = i.first;

        c->bOutOfGame = i.second.first;
        c->clone_ready = i.second.second;
    }

    g_tempOutOfGame.clear();
}


static bool g_inCrewCustomizeBox = false;

HOOK_METHOD(CrewCustomizeBox, CheckContents, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewCustomizeBox::CheckContents -> Begin (CustomCrew.cpp)\n")
    g_inCrewCustomizeBox = true;

    super();
    g_inCrewCustomizeBox = false;

}

// Get crewmember in slot; modified for noSlot
HOOK_METHOD(ShipManager, GetCrewmember, (int slot, bool present) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetCrewmember -> Begin (CustomCrew.cpp)\n")
    if (vCrewList.empty()) return nullptr;

    int currSlot = 0;

    for (auto crew : vCrewList)
    {
        if (crew->iShipId == 1 || crew->IsDrone()) continue;
        bool noSlot;
        CM_EX(crew)->CalculateStat(CrewStat::NO_SLOT, CustomCrewManager::GetInstance()->GetDefinition(crew->species), &noSlot);
        if (noSlot) continue;

        if (currSlot == slot) return crew;

        currSlot++;
    }

    return nullptr;
}

// No Clone stat
HOOK_METHOD(CrewMember, CheckSkills, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::CheckSkills -> Begin (CustomCrew.cpp)\n")
    super();

    auto ex = CM_EX(this);
    if (ex->deathTimer && ex->deathTimer->currTime >= ex->deathTimer->currGoal)
    {
        clone_ready = false;
        return;
    }

    auto custom = CustomCrewManager::GetInstance();
    if (custom->IsRace(species))
    {
        ex->CalculateStat(CrewStat::NO_CLONE, custom->GetDefinition(species), &ex->noClone);
        if (ex->noClone)
        {
            clone_ready = false;
            return;
        }
    }
}

//cloneSpeedMultiplier statBoost
HOOK_METHOD(CloneSystem, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CloneSystem::OnLoop -> Begin (CustomCrew.cpp)\n")
    std::vector<CrewMember*> crewList;
    G_->GetCrewFactory()->GetCloneReadyList(crewList,(_shipObj.iShipId==0));

    if (!crewList.empty())
    {
        CrewMember *cloningCrew = crewList[0];

        auto custom = CustomCrewManager::GetInstance();
        if (custom->IsRace(cloningCrew->species))
        {
            auto def = custom->GetDefinition(cloningCrew->species);
            auto ex = CM_EX(cloningCrew);

            float increment = (G_->GetCFPS()->GetSpeedFactor() * 0.0625);
            float cloneSpeedMultiplier = ex->CalculateStat(CrewStat::CLONE_SPEED_MULTIPLIER, def);
            fTimeToClone += (cloneSpeedMultiplier-1.f) * increment;
        }
    }
    super();
}

// Mind control resist/telepathy split
HOOK_METHOD(MindSystem, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MindSystem::OnLoop -> Begin (CustomCrew.cpp)\n")
    isTelepathicMindControl = g_resistsMindControlStat;
    super();
    isTelepathicMindControl = false;
}

// Mind control resist/telepathy split
HOOK_METHOD(CombatAI, UpdateMindControl, (bool hostile) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatAI::UpdateMindControl -> Begin (CustomCrew.cpp)\n")
    isTelepathicMindControl = g_resistsMindControlStat;
    super(hostile);
    isTelepathicMindControl = false;
}

// canTeleport
/*
HOOK_METHOD(CombatControl, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::OnLoop -> Begin (CustomCrew.cpp)\n")
    super();
    if (currentTarget && currentTarget->shipManager && shipManager->teleportSystem)
    {
        for (CrewMember* crew : currentTarget->shipManager->vCrewList)
        {
            if (!crew->IsDead())
            {
                CustomCrewManager* custom = CustomCrewManager::GetInstance();
                if (!crew->IsDrone())
                {
                    if (custom->IsRace(crew->species))
                    {
                        auto ex = CM_EX(crew);
                        auto def = CustomCrewManager::GetInstance()->GetDefinition(crew->species);
                        bool canTeleport;
                        ex->CalculateStat(CrewStat::CAN_TELEPORT, def, &canTeleport);
                        if (canTeleport)
                        {
                            shipManager->teleportSystem->bCanReceive = true;
                            return;
                        }
                    }
                    else
                    {
                        shipManager->teleportSystem->bCanReceive = true;
                        return;
                    }
                }
                else if (g_dronesCanTeleport)
                {
                    if (crew->CanTeleport())
                    {
                        shipManager->teleportSystem->bCanReceive = true;
                        return;
                    }
                }
            }
        }
    }
    shipManager->teleportSystem->bCanReceive = false;
}
*/

// Shoot when in melee without forcing to be a drone animation
HOOK_METHOD(CrewAnimation, OnUpdate, (Pointf position, bool moving, bool fighting, bool repairing, bool dying, bool onFire) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::OnUpdate -> Begin (CustomCrew.cpp)\n")
    auto aex = CMA_EX(this);
    if (aex->canPunch.enabled)
    {
        if (aex->canPunch.value)
        {
            if (!dying)
            {
                bool tempBDrone = bDrone;
                bDrone = false;
                super(position, moving, fighting, repairing, dying, onFire);
                bDrone = tempBDrone;
            }
            else
            {
                super(position, moving, fighting, repairing, dying, onFire);
            }
        }
        else
        {
            bool sharedSpot = bSharedSpot;
            bSharedSpot = false;
            super(position, moving, fighting, repairing, dying, onFire);
            bSharedSpot = sharedSpot;
        }
    }
    else
    {
        super(position, moving, fighting, repairing, dying, onFire);
    }
}

// Door damage multiplier
HOOK_METHOD(Door, ApplyDamage, (float amount) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> Door::ApplyDamage -> Begin (CustomCrew.cpp)\n")
    if (currentCrewLoop)
    {
        CrewMember_Extend *ex = CM_EX(currentCrewLoop);
        CrewDefinition *def = ex->GetDefinition();
        if (def)
        {
            if (forcedOpen.running) return false;

            float damage = ex->CalculateStat(CrewStat::DOOR_DAMAGE_MULTIPLIER, def);
            int iDamage = (int)damage;
            float fDamage = damage - iDamage;
            if (fDamage > 0.f && random32() < fDamage*2147483648.f) iDamage++;

            if (iDamage > 0) health -= iDamage;
            gotHit.Start(0.f);

            if (health < 1)
            {
                forcedOpen.Start(0.f);
                health = baseHealth;
                lockedDown.Stop(false);
                baseHealth = lastbase;
                health = lastbase;
                bOpen = true;
            }

            return false;
        }
    }
    return super(amount);
}

// Custom Teleport
static std::vector<CrewMember*> customTeleCrew = {};

bool CrewMember_Extend::CanTeleportMove(bool toOtherShip)
{
    bool ret;

    if (orig->crewAnim->status == 3) return false;

    if (toOtherShip)
    {
        if (orig->bMindControlled && orig->iShipId == 0 && orig->currentShipId == 0) return false; // anti-kidnapping

        if (orig->IsDrone()) return false; // drones cannot teleport to the other ship

        CalculateStat(CrewStat::CAN_TELEPORT, &ret);
        if (!ret) return false;
        CalculateStat(CrewStat::TELEPORT_MOVE_OTHER_SHIP, &ret);
        if (!ret) return false;

        int powerOwner = orig->GetPowerOwner();

        ShipManager *enemyShip = G_->GetShipManager(1);
        if (orig->currentShipId == powerOwner && (!enemyShip || !enemyShip->_targetable.hostile))
        {
            return false; // can't teleport off your own ship when not hostile
        }

        ShipManager *otherShip = G_->GetShipManager(powerOwner == 0 ? 1 : 0);

        if (otherShip)
        {
            if (otherShip->systemKey[10] != -1)
            {
                if (otherShip->cloakSystem->bTurnedOn) return false;
            }
            if ((otherShip->iShipId == 0 || otherShip->_targetable.hostile) && otherShip->GetShieldPower().super.first > 0)
            {
                ShipManager *crewShip = G_->GetShipManager(powerOwner);
                if (crewShip)
                {
                    return crewShip->HasEquipment("ZOLTAN_BYPASS");
                }
                return false;
            }
        }
        return true;
    }
    else
    {
        if (orig->crewAnim->status == 3) return false;
        //CalculateStat(CrewStat::CAN_TELEPORT, &ret);
        //if (!ret) return false;
        CalculateStat(CrewStat::TELEPORT_MOVE, &ret);
    }

    return ret;
}

HOOK_METHOD(CrewMember, StartTeleport, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::StartTeleport -> Begin (CustomCrew.cpp)\n")
    super();
    CM_EX(this)->customTele.teleporting = true;
}

void CrewMember_Extend::InitiateTeleport(int shipId, int roomId, int slotId)
{
    orig->StartTeleport();
    customTele.shipId = shipId;
    customTele.roomId = roomId;
    customTele.slotId = slotId;
}

void CompleteShip::CheckTeleportMovement()
{
    bool customTeleports = false;
    for (CrewMember *crew : shipManager->vCrewList)
    {
        CrewMember_Extend *ex = CM_EX(crew);

        if (ex->customTele.shipId == -1) // no armed teleport, can check conditions for auto-teleport to destination tile, otherwise pass
        {
            if (!crew->IsDead() && crew->Functional() && crew->fStunTime <= 0.f && !ex->customTele.teleporting && crew->crewAnim->status != 6)
            {
                if (!crew->AtFinalGoal() && ex->CanTeleportMove(false))
                {
                    if (crew->iRoomId != crew->currentSlot.roomId)
                    {
                        ex->InitiateTeleport(iShipId, crew->currentSlot.roomId, crew->currentSlot.slotId);
                        customTeleports = true;
                    }
                    else
                    {
                        bool canMove;
                        ex->CalculateStat(CrewStat::CAN_MOVE, &canMove);
                        if (!canMove || ex->CalculateStat(CrewStat::MOVE_SPEED_MULTIPLIER) == 0.f)
                        {
                            ex->InitiateTeleport(iShipId, crew->currentSlot.roomId, crew->currentSlot.slotId);
                            customTeleports = true;
                        }
                    }
                }
            }
            continue;
        }
        else if ((ex->customTele.teleporting || crew->crewAnim->status == 6) && !crew->crewAnim->anims[0][6].tracker.reverse) // crew is teleport leaving; don't interfere
        {
            continue;
        }
        else if (crew->IsDead() || !crew->Functional() || !ex->CanTeleportMove(crew->currentShipId != ex->customTele.shipId)) // disarm teleport if dead, nonfunctional, or loses ability
        {
            ex->customTele.shipId = -1;
            continue;
        }
        else if (crew->fStunTime > 0.f) // stunned, wait
        {
            continue;
        }
        else // initiate armed custom teleport
        {
            if (!crew->GetControllable() && ex->customTele.shipId == crew->currentShipId && ex->customTele.roomId != -1)
            {
                if (ex->customTele.roomId == crew->currentSlot.roomId)
                {
                    // Set the teleport slot to actual slot if the room matches
                    ex->customTele.slotId = crew->currentSlot.slotId;
                }
                else
                {
                    // The following logic will reassign the crew slot for AI controlled crew to the teleport room
                    // Note: This works even if the room is otherwise unreachable. Since we commit to the teleport here this is okay.
                    Slot slot = crew->FindSlot(ex->customTele.roomId, ex->customTele.slotId, false);
                    if (slot.roomId == ex->customTele.roomId)
                    {
                        crew->EmptySlot();

                        ShipGraph *graph = ShipGraph::GetShipInfo(ex->customTele.shipId);
                        Room *room = graph->rooms[ex->customTele.roomId];
                        room->FillSlot(slot.slotId, crew->GetIntruder());
                        crew->currentSlot = slot;

                        ex->customTele.slotId = slot.slotId;
                    }
                }
            }
            crew->StartTeleport();
            customTeleports = true;
        }
    }

    if (customTeleports)
    {
        G_->GetSoundControl()->PlaySoundMix("teleport", -1.f, false);
    }

    for (CrewMember *crew : customTeleCrew)
    {
        if (!crew->IsDead())
        {
            CrewMember_Extend *ex = CM_EX(crew);
            crew->SetCurrentShip(ex->customTele.shipId);

            ShipManager *targetShip = ex->customTele.shipId == iShipId ? shipManager : enemyShip->shipManager;
            ShipGraph *graph = ShipGraph::GetShipInfo(ex->customTele.shipId);

            if (ex->customTele.roomId == -1)
            {
                ex->customTele.roomId = random32() % graph->RoomCount();
            }

            targetShip->AddCrewMember(crew, ex->customTele.roomId);

            if (crew->currentShipId == ex->customTele.shipId && ex->customTele.slotId > -1 && crew->ship) // specific slot
            {
                if (crew->currentSlot.roomId == ex->customTele.roomId && crew->currentSlot.slotId != ex->customTele.slotId) // they got the right room ID but the wrong slot ID
                {
                    Room *room = graph->rooms[ex->customTele.roomId];
                    bool intruder = (crew->currentShipId == crew->iShipId) == crew->bMindControlled;
                    if (room->slots[intruder].size() > ex->customTele.slotId && room->slots[intruder][ex->customTele.slotId] == false)
                    {
                        crew->EmptySlot();
                        room->FillSlot(ex->customTele.slotId, intruder);
                        Point slotPosition = graph->GetSlotWorldPosition(ex->customTele.slotId, ex->customTele.roomId);
                        crew->x = slotPosition.x;
                        crew->y = slotPosition.y;
                        crew->goal_x = slotPosition.x;
                        crew->goal_y = slotPosition.y;
                        crew->crewAnim->lastPosition.x = slotPosition.x;
                        crew->crewAnim->lastPosition.y = slotPosition.y;
                        //crew->iRoomId = ex->customTele.roomId;
                        crew->currentSlot.roomId = ex->customTele.roomId;
                        crew->currentSlot.slotId = ex->customTele.slotId;
                        crew->currentSlot.worldLocation = slotPosition;
                        crew->ClearPath();
                        //crew->task.system = -1;
                        //crew->task.taskId = 4;
                        //crew->task.roomId = ex->customTele.roomId;
                    }
                }
            }

            ex->customTele.shipId = -1;
        }
    }
    customTeleCrew.clear();
}

HOOK_METHOD(CombatControl, GetTeleportationCommand, () -> std::pair<int,int>)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::GetTeleportationCommand -> Begin (CustomCrew.cpp)\n")
    // Check teleport movement on player ship and then on enemy ship.
    // Hooked here so it is the same timing as teleport system (affects timing with enemy cloaking).
    CompleteShip *ship = this->gui->shipComplete;
    if (ship)
    {
        ship->CheckTeleportMovement();
        ship = ship->enemyShip;
        if (ship)
        {
            ship->CheckTeleportMovement();
        }
    }

    return super();
}

HOOK_METHOD(CrewMember, CheckForTeleport, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::CheckForTeleport -> Begin (CustomCrew.cpp)\n")
    super();

    if (currentShipId == -1)
    {
        CrewMember_Extend *ex = CM_EX(this);
        if (ex->customTele.shipId != -1)
        {
            customTeleCrew.push_back(this);
        }
    }
}

HOOK_METHOD(CrewControl, RButton, (int x, int y, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewControl::RButton -> Begin (CustomCrew.cpp)\n")

    int _selectedRoom = selectedRoom;

    super(x, y, shiftHeld);

    if (selectedDoor == nullptr)
    {
        if (!selectedCrew.empty() && _selectedRoom != -1)
        {
            ShipManager* ship;
            if (selectedPlayerShip)
            {
                ship = shipManager;
            }
            else
            {
                ship = combatControl->GetCurrentTarget();
            }

            std::vector<CrewMember*> teleportingCrew = {};
            for (CrewMember *crew : selectedCrew)
            {
                CrewMember_Extend *ex = CM_EX(crew);
                if (ex->IsController(false))
                {
                    if (!ex->customTele.teleporting || crew->crewAnim->anims[0][6].tracker.reverse)
                    {
                        ex->customTele.shipId = -1;
                        if (ex->CanTeleportMove(crew->currentShipId != ship->iShipId))
                        {
                            if (crew->currentShipId != ship->iShipId || crew->iRoomId != _selectedRoom)
                            {
                                teleportingCrew.push_back(crew);
                            }
                            else
                            {
                                bool canMove;
                                ex->CalculateStat(CrewStat::CAN_MOVE, &canMove);
                                if (!canMove || ex->CalculateStat(CrewStat::MOVE_SPEED_MULTIPLIER) == 0.f)
                                {
                                    teleportingCrew.push_back(crew);
                                }
                            }
                        }
                    }
                }
            }

            if (!teleportingCrew.empty())
            {
                Room* room = ship->ship.vRoomList.at(_selectedRoom);
                int roomSize = room->slots[false].size();
                int tile = -1;
                std::vector<bool> filledTeleSlots(roomSize);

                if (CustomOptionsManager::GetInstance()->alternateCrewMovement.currentValue)
                {
                    int wX,wY;
                    if (selectedPlayerShip)
                    {
                        wX = worldCurrentMouse.x;
                        wY = worldCurrentMouse.y;
                    }
                    else
                    {
                        wX = x - combatControl->position.x - combatControl->targetPosition.x;
                        wY = y - combatControl->position.y - combatControl->targetPosition.y;
                    }

                    tile = ((wX - room->rect.x) / 35 + (room->rect.w / 35) * ((wY - room->rect.y) / 35) );
                    if (tile < 0 || tile >= roomSize)
                    {
                        tile = -1;
                    }
                }

                CrewMember *oldTeleportingTileCrew = nullptr;
                for (CrewMember *crew : G_->GetCrewFactory()->crewMembers)
                {
                    if (!crew->IsDead() && crew->iShipId == crew->bMindControlled)
                    {
                        CrewMember_Extend *ex = CM_EX(crew);
                        if ((!ex->customTele.teleporting || crew->crewAnim->anims[0][6].tracker.reverse) && ex->customTele.shipId == ship->iShipId && ex->customTele.roomId == _selectedRoom && ex->customTele.slotId != -1)
                        {
                            if (ex->customTele.slotId == tile)
                            {
                                ex->customTele.slotId = -1;
                                teleportingCrew.push_back(crew);
                                oldTeleportingTileCrew = crew;
                            }
                            else
                            {
                                filledTeleSlots[ex->customTele.slotId] = true;
                            }
                        }
                    }
                }

                for (CrewMember *crew : teleportingCrew)
                {
                    if (crew->currentShipId == ship->iShipId && _selectedRoom == crew->currentSlot.roomId && !filledTeleSlots[crew->currentSlot.slotId])
                    {
                        CrewMember_Extend *ex = CM_EX(crew);
                        ex->customTele.shipId = ship->iShipId;
                        ex->customTele.roomId = _selectedRoom;
                        ex->customTele.slotId = crew->currentSlot.slotId;
                        filledTeleSlots[crew->currentSlot.slotId] = true;
                    }
                }

                std::vector<int> slotOrder = {};
                if (tile != -1 && !filledTeleSlots[tile])
                {
                    slotOrder.push_back(tile);
                    filledTeleSlots[tile] = true;
                }
                if (room->primarySlot != -1 && !filledTeleSlots[room->primarySlot])
                {
                    slotOrder.push_back(room->primarySlot);
                    filledTeleSlots[room->primarySlot] = true;
                }
                for (int i=0; i<roomSize; ++i)
                {
                    if (!room->slots[ship->iShipId][i] && !filledTeleSlots[i])
                    {
                        slotOrder.push_back(i);
                        filledTeleSlots[i] = true;
                    }
                }
                for (int i=0; i<roomSize; ++i)
                {
                    if (!filledTeleSlots[i])
                    {
                        slotOrder.push_back(i);
                    }
                }

                int i = 0;
                for (CrewMember *crew : teleportingCrew)
                {
                    CrewMember_Extend *ex = CM_EX(crew);

                    if (ex->customTele.shipId != -1) continue;

                    tile = i >= slotOrder.size() ? -1 : slotOrder[i];

                    ex->customTele.shipId = ship->iShipId;
                    ex->customTele.roomId = _selectedRoom;
                    ex->customTele.slotId = tile;
                    i++;
                }
            }
        }
    }
}

// convenient spot for rendering crew teleports on enemy ship
HOOK_METHOD(ShipManager, RenderChargeBars, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::RenderChargeBars -> Begin (CustomCrew.cpp)\n")
    super();

    for (CrewMember *crew : G_->GetCrewFactory()->crewMembers)
    {
        if (!crew->IsDead() && (crew->iShipId == 0 || crew->GetPowerOwner() == 0))
        {
            CrewMember_Extend *ex = CM_EX(crew);
            if ((!ex->customTele.teleporting || crew->crewAnim->anims[0][6].tracker.reverse) && ex->customTele.shipId == iShipId && ex->customTele.roomId != -1)
            {
                ShipGraph *graph = ShipGraph::GetShipInfo(iShipId);
                Point pos;
                if (ex->customTele.slotId != -1)
                {
                    pos = graph->GetSlotWorldPosition(ex->customTele.slotId, ex->customTele.roomId);
                }
                else
                {
                    Pointf posf = graph->GetRoomCenter(ex->customTele.roomId);
                    pos = {(int)posf.x, (int)posf.y};
                }

                std::string image = "misc/teleport_placed_send_small.png";

                G_->GetResources()->RenderImageString(image, pos.x-17, pos.y-17, 0, COLOR_WHITE, 1.f, false);
            }
        }
    }
}

HOOK_METHOD(CombatControl, OnRenderSelfAiming, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::OnRenderSelfAiming -> Begin (CustomCrew.cpp)\n")
    super();

    for (CrewMember *crew : G_->GetCrewFactory()->crewMembers)
    {
        if (!crew->IsDead() && (crew->iShipId == 0 || crew->GetPowerOwner() == 0))
        {
            CrewMember_Extend *ex = CM_EX(crew);
            if ((!ex->customTele.teleporting || crew->crewAnim->anims[0][6].tracker.reverse) && ex->customTele.shipId == 0 && ex->customTele.roomId != -1)
            {
                ShipGraph *graph = ShipGraph::GetShipInfo(0);
                Point pos;
                if (ex->customTele.slotId != -1)
                {
                    pos = graph->GetSlotWorldPosition(ex->customTele.slotId, ex->customTele.roomId);
                }
                else
                {
                    Pointf posf = graph->GetRoomCenter(ex->customTele.roomId);
                    pos = {(int)posf.x, (int)posf.y};
                }

                std::string image = "misc/teleport_placed_send_small.png";

                G_->GetResources()->RenderImageString(image, pos.x-17, pos.y-17, 0, COLOR_WHITE, 1.f, false);
            }
        }
    }
}

HOOK_METHOD(ShipManager, GetLeavingCrew, (bool intruders) -> std::vector<CrewMember*>)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetLeavingCrew -> Begin (CustomCrew.cpp)\n")
    std::vector<CrewMember*> ret;

    for (CrewMember *crew : vCrewList)
    {
        if (crew->crewAnim->status == 6 && !crew->crewAnim->anims[0][6].tracker.reverse && crew->GetIntruder() == intruders)
        {
            CrewMember_Extend *ex = CM_EX(crew);

            if (ex->customTele.shipId == -1) // not a custom teleport
            {
                ret.push_back(crew);
            }
        }
    }

    return ret;
}

static bool addCrewFailed = false;
HOOK_METHOD(ShipManager, AddCrewMember, (CrewMember *crew, int roomId) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::AddCrewMember -> Begin (CustomCrew.cpp)\n")
    if (!addCrewFailed)
    {
        bool intruder = (iShipId == crew->iShipId) == crew->bMindControlled;
        int availableRoom = ship.GetAvailableRoom(roomId, intruder);
        if (availableRoom == -1 || ship.vRoomList[availableRoom]->Full(intruder)) // failsafe for no space
        {
            addCrewFailed = true;
            ShipManager *otherShip = G_->GetShipManager(iShipId == 0 ? 1 : 0);
            otherShip->AddCrewMember(crew, otherShip->GetSystemRoom(SYS_PILOT));
            addCrewFailed = false;
        }
        else
        {
            super(crew, roomId);
        }
    }
    else
    {
        super(crew, roomId);
    }
}

HOOK_METHOD_PRIORITY(ShipManager, CountPlayerCrew, 9999, () -> int)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::CountPlayerCrew -> Begin (CustomCrew.cpp)\n")
    int ret = 0;
    for (auto& crew: vCrewList)
    {   
        bool noWarning;
        auto ex = CM_EX(crew);
        ex->CalculateStat(CrewStat::NO_WARNING, &noWarning);
        if (crew->iShipId == 0 && !crew->IsDead() && !crew->IsDrone() && !noWarning) ret++;
    }
    return ret;
}
