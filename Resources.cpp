#include "rapidxml.hpp"
#include "Resources.h"
#include "CustomOptions.h"

#include "HullNumbers.h"
#include "CommandConsole.h"
#include "CustomShipSelect.h"
#include "CustomCrew.h"
#include "CustomDamage.h"
#include "CustomEvents.h"
#include "CustomRewards.h"
#include "CustomSectors.h"
#include "CustomLocalization.h"
#include "EventTooltip.h"
#include "CooldownNumbers.h"
#include "CustomAugments.h"
#include "Infinite.h"
#include "Balance.h"
#include "MainMenu.h"
#include "CustomBoss.h"
#include "CustomStore.h"
#ifdef USE_DISCORD
#include "DiscordIntegration.h"
#endif // USE_DISCORD
#include "CustomDrones.h"
#include "Seeds.h"
#include "SaveFile.h"
#include "CustomSystems.h"
#include "AlternateOxygenRendering.h"
#include "CustomColors.h"
#include "CustomShips.h"
#include "CustomCrystalShard.h"
#include "CustomShipGenerator.h"
#include "ShipUnlocks.h"
#include "CustomAchievements.h"
#include "HSVersion.h"
#include "CustomUpgrades.h"

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/split.hpp>

GL_Color& ParseColorNode(GL_Color& colorRef, rapidxml::xml_node<char>* node, bool divide)
{
    if (node->first_attribute("r")) { colorRef.r = boost::lexical_cast<float>(node->first_attribute("r")->value()) / (divide ? 255.f : 1.f); }
    if (node->first_attribute("g")) { colorRef.g = boost::lexical_cast<float>(node->first_attribute("g")->value()) / (divide ? 255.f : 1.f); }
    if (node->first_attribute("b")) { colorRef.b = boost::lexical_cast<float>(node->first_attribute("b")->value()) / (divide ? 255.f : 1.f); }
    if (node->first_attribute("a")) { colorRef.a = boost::lexical_cast<float>(node->first_attribute("a")->value()); }

    return colorRef;
}

HOOK_METHOD(ResourceControl, PreloadResources, (bool unk) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ResourceControl::PreloadResources -> Begin (Resources.cpp)\n")

    /* Search for files unique to MV & HS FTL zips so we can determine if a user patched both files in error */
    printf("Scanning for Multiverse & Hyperspace patching in ftl.dat\n");
    typedef void (*list_files_start_funcptr)(PackageModuleInfo* info_arg);
    typedef char* (*list_files_next_funcptr)(PackageModuleInfo* info_arg);
    list_files_start_funcptr list_files_start = (list_files_start_funcptr) this->package->list_files_start;
    list_files_next_funcptr list_files_next = (list_files_next_funcptr) this->package->list_files_next;

    list_files_start(this->package);
    bool mvDetected = false;
    bool hsDetected = false;
    for(char* pkgFile; pkgFile = list_files_next(this->package), pkgFile != (char*) 0x0;)
    {
        if(!mvDetected && strstr(pkgFile, "audio/music/mv_MUS_") == pkgFile)
            mvDetected = true;
        else if(!hsDetected && strcmp(pkgFile, "example_layout_syntax.xml") == 0)
            hsDetected = true;
        else if(hsDetected && mvDetected)
            break;
    }
    printf("ftl.dat scan detection: Hyperspace.ftl: %s, Multiverse.zip: %s\n", hsDetected ? "YES" : "NO", mvDetected ? "YES" : "NO");

    if(mvDetected && hsDetected)
        ErrorMessage("Hyperspace & Multiverse both detected patched into ftl.dat!\nPlease patch only Multiverse and not hyperspace.ftl\n");

    bool ret = super(unk);
    if (ret && G_)
    {
        G_->PreInitializeResources(this);
    }
    return ret;
}

HOOK_METHOD(AchievementTracker, LoadAchievementDescriptions, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::LoadAchievementDescriptions -> Begin (Resources.cpp)\n")
    if (G_ && !G_->AreResourcesInitialized())
    {
        G_->InitializeResources(G_->GetResources());
    }

    super();
}


// hyperspace.xml parsing
void Global::PreInitializeResources(ResourceControl *resources)
{
    char *hyperspacetext = resources->LoadFile("data/hyperspace.xml");

    auto customOptions = CustomOptionsManager::GetInstance();

    try
    {
        if (!hyperspacetext)
        {
            __resourcesInitialized = true; // skip main pass
            throw "hyperspace.xml not found";
        }

        rapidxml::xml_document<> doc;
        doc.parse<0>(hyperspacetext);

        auto parentNode = doc.first_node("FTL");
        if (!parentNode)
        {
            __resourcesInitialized = true; // skip main pass
            throw "No parent node found in hyperspace.xml";
        }

        // Stuff to parse early
        for (auto node = parentNode->first_node(); node; node = node->next_sibling())
        {
            if (strcmp(node->name(), "defaults") == 0)
            {
                for (auto child = node->first_node(); child; child = child->next_sibling())
                {
                    if (strcmp(child->name(), "checkCargo") == 0)
                    {
                        customOptions->defaults.checkCargo = EventsParser::ParseBoolean(child->value());
                    }
                    if (strcmp(child->name(), "choiceRequiresCrew") == 0)
                    {
                        customOptions->defaults.choiceRequiresCrew = EventsParser::ParseBoolean(child->value());
                    }
                    if (strcmp(child->name(), "beaconType_hideVanillaLabel") == 0)
                    {
                        customOptions->defaults.beaconType_hideVanillaLabel = EventsParser::ParseBoolean(child->value());
                    }
                    if (strcmp(child->name(), "erosion") == 0)
                    {
                        ErosionEffect::defaultErosionEffect.ParseErosionEffect(child);
                        for (auto child2 = child->first_node(); child2; child2 = child2->next_sibling())
                        {
                            if (strcmp(child2->name(), "growBreachMultiplier") == 0)
                            {
                                ErosionEffect::growBreachMultiplier = boost::lexical_cast<float>(child2->value());
                            }
                            else if (strcmp(child2->name(), "newBreachDamage") == 0)
                            {
                                ErosionEffect::newBreachDamage = boost::lexical_cast<float>(child2->value());
                            }
                            else if (strcmp(child2->name(), "newBreachRequirement") == 0)
                            {
                                ErosionEffect::newBreachRequirement = boost::lexical_cast<float>(child2->value());
                            }
                            else if (strcmp(child2->name(), "canDilate") == 0)
                            {
                                ErosionEffect::canDilate = EventsParser::ParseBoolean(child2->value());
                            }
                        }
                    }
                }
            }

            if (strcmp(node->name(), "colors") == 0)
            {
                ParseCustomColorsNode(node);
            }

            if (strcmp(node->name(), "ships") == 0)
            {
                auto customShipManager = CustomShipSelect::GetInstance();
                customShipManager->EarlyParseShipsNode(node);
            }

            if (strcmp(node->name(), "languages") == 0)
            {
                ParseLanguagesNode(resources, node);
            }

            if (strcmp(node->name(), "customCredits") == 0)
            {
                auto customEventParser = CustomEventsParser::GetInstance();
                customEventParser->ParseCustomCredits(node);
            }

            // Read event files and other early stuff.
            if (strcmp(node->name(), "events") == 0)
            {
                auto customEventParser = CustomEventsParser::GetInstance();
                customEventParser->EarlyParseCustomEventNode(node);
            }

            // Perform custom text color registration before event parsing.
            if (strcmp(node->name(), "customChoiceColors") == 0)
            {
                ParseChoiceColorsNode(node);
            }
        }

        // Read the custom events.
        {
            auto customEventParser = CustomEventsParser::GetInstance();
            customEventParser->ReadCustomEventFiles();
        }

        doc.clear();
    }
    catch (rapidxml::parse_error& e)
    {
        ErrorMessage(std::string("Failed parsing hyperspace.xml\n") + std::string(e.what()));
    }
    catch (std::exception &e)
    {
        ErrorMessage(std::string("Failed parsing hyperspace.xml\n") + std::string(e.what()));
    }
    catch (const char* e)
    {
        ErrorMessage(e);
    }

    delete [] hyperspacetext;
}

void Global::InitializeResources(ResourceControl *resources)
{
    __resourcesInitialized = true;

    char *hyperspacetext = resources->LoadFile("data/hyperspace.xml");

    auto customOptions = CustomOptionsManager::GetInstance();

    try
    {
        if (!hyperspacetext)
        {
            throw "hyperspace.xml not found";
        }

        rapidxml::xml_document<> doc;
        doc.parse<0>(hyperspacetext);

        auto parentNode = doc.first_node("FTL");
        if (!parentNode)
            throw "No parent node found in hyperspace.xml";

        bool checkedVersion = false;

        std::string discordModName = "";

        // First Pass
        for (auto node = parentNode->first_node(); node; node = node->next_sibling())
        {
            if (strcmp(node->name(), "version") == 0)
            {
                std::string versionStr = node->value();
                if(versionStr.find('.') == std::string::npos)
                {
                    hs_log_file("Old version check in use. Mod authors please update your hyperspace.xml's version tag!\n");
                    checkedVersion = boost::lexical_cast<int>(node->value()) == HS_Version.getDeprecatedIntegerVersion();
                }
                else
                {
                    // Enhanced Hyperspace version check
                    hs_log_file("Checking version Mod requests version: '%s' vs Hyperspace version: '%s'\n", versionStr.c_str(), HS_Version.toVersionString().c_str());

                    char firstChar = versionStr.front();
                    if(firstChar == '=' || firstChar == '~' || firstChar == '^')
                    {
                        versionStr.erase(0, 1);
                    }

                    std::vector<std::string> version;
                    boost::split(version, versionStr, boost::is_any_of("."));

                    if(version.size() != 3)
                    {
                        hs_log_file("Invalid version check syntax.\n");
                        checkedVersion = false;
                        throw "Invalid/Unknown Hyperspace version check syntax in mod, could not validate hyperspace version matches mod requirements.\nMods may function incorrectly.";
                    }

                    unsigned int v_major = boost::lexical_cast<unsigned int>(version[0]);
                    unsigned int v_minor = boost::lexical_cast<unsigned int>(version[1]);
                    unsigned int v_patch = boost::lexical_cast<unsigned int>(version[2]);

                    switch(firstChar)
                    {
                        case '=':
                            checkedVersion = v_major == HS_Version.major && v_minor == HS_Version.minor && v_patch == HS_Version.patch;
                            break;

                        case '~':
                            checkedVersion = v_major == HS_Version.major && v_minor == HS_Version.minor && v_patch <= HS_Version.patch;
                            break;

                        default:
                            hs_log_file("No version check case specified, defaulting to '^'.\n");
                        case '^':
                            checkedVersion = v_major == HS_Version.major && (v_minor < HS_Version.minor || (v_minor == HS_Version.minor && v_patch <= HS_Version.patch));
                    }
                }
            }
            if (strcmp(node->name(), "hullNumbers") == 0)
            {
                if (node->first_attribute("enabled"))
                {
                    auto enabled = node->first_attribute("enabled")->value();

                    if (EventsParser::ParseBoolean(enabled))
                    {
                        auto hullManager = HullNumbers::GetInstance();
                        hullManager->enabled = true;
                        hullManager->ParseHullNumbersNode(node);
                    }
                }
            }

            if (strcmp(node->name(), "hullBars") == 0)
            {
                HullBars::GetInstance()->ParseHullBarsNode(node);
            }

            if (strcmp(node->name(), "hackingDroneFix") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_hackingDroneFix = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "repairDroneRecoveryFix") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_repairDroneRecoveryFix = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "controllableIonDroneFix") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_controllableIonDroneFix = EventsParser::ParseBoolean(enabled);
                if (g_controllableIonDroneFix && node->first_attribute("ionDelay"))
                {
                    float delay = boost::lexical_cast<float>(node->first_attribute("ionDelay")->value());
                    g_controllableIonDroneFix_Delay = delay;
                    g_controllableIonDroneFix_DelayInitial = delay;
                }
                if (g_controllableIonDroneFix && node->first_attribute("ionDelayInitial"))
                {
                    g_controllableIonDroneFix_DelayInitial = boost::lexical_cast<float>(node->first_attribute("ionDelayInitial")->value());
                }
            }

            if (strcmp(node->name(), "enemyPreigniterFix") == 0) // enables enemies to have their weapons enabled and preignited
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_enemyPreigniterFix = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "crystalShardFix") == 0) // fixes crystal shards being targeted by friendly defense drones; default true
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_crystalShardFix = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "defenseDroneFix") == 0) // fixes defense drone blind spot by making the visible area resize with the ship
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_defenseDroneFix = EventsParser::ParseBoolean(enabled);
                if (g_defenseDroneFix)
                {
                    for (auto child = node->first_node(); child; child = child->next_sibling())
                    {
                        if (strcmp(child->name(), "boxRange") == 0)
                        {
                            if (child->value())
                            {
                                g_defenseDroneFix_BoxRange[0] = boost::lexical_cast<float>(child->value());
                                g_defenseDroneFix_BoxRange[1] = g_defenseDroneFix_BoxRange[0];
                            }
                            if (child->first_attribute("player"))
                            {
                                g_defenseDroneFix_BoxRange[0] = boost::lexical_cast<float>(child->first_attribute("player")->value());
                            }
                            if (child->first_attribute("enemy"))
                            {
                                g_defenseDroneFix_BoxRange[1] = boost::lexical_cast<float>(child->first_attribute("enemy")->value());
                            }
                        }
                        if (strcmp(child->name(), "ellipseRange") == 0)
                        {
                            if (child->value())
                            {
                                g_defenseDroneFix_EllipseRange[0] = boost::lexical_cast<float>(child->value());
                                g_defenseDroneFix_EllipseRange[1] = g_defenseDroneFix_EllipseRange[0];
                            }
                            if (child->first_attribute("player"))
                            {
                                g_defenseDroneFix_EllipseRange[0] = boost::lexical_cast<float>(child->first_attribute("player")->value());
                            }
                            if (child->first_attribute("enemy"))
                            {
                                g_defenseDroneFix_EllipseRange[1] = boost::lexical_cast<float>(child->first_attribute("enemy")->value());
                            }
                        }
                    }
                }
            }

            if (strcmp(node->name(), "artilleryGibMountFix") == 0) // fixes artillery disappearing during ship explosions
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_artilleryGibMountFix = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "warningLightPositionFix") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_warningLightPositionFix = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "hideHullDuringExplosion") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_hideHullDuringExplosion = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "resistsMindControlStat") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_resistsMindControlStat = EventsParser::ParseBoolean(enabled);
            }

            /*
            if (strcmp(node->name(), "dronesCanTeleport") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_dronesCanTeleport = EventsParser::ParseBoolean(enabled);
            }
            */

            if (strcmp(node->name(), "alternateCrewMovement") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->alternateCrewMovement.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->alternateCrewMovement.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "rightClickDoorOpening") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->rightClickDoorOpening.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->rightClickDoorOpening.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "redesignedWeaponTooltips") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->redesignedWeaponTooltips.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->redesignedWeaponTooltips.currentValue = EventsParser::ParseBoolean(enabled);
            }
            if (strcmp(node->name(), "redesignedCrewTooltips") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->redesignedCrewTooltips.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->redesignedCrewTooltips.currentValue = EventsParser::ParseBoolean(enabled);
            }
            if (strcmp(node->name(), "redesignedDroneTooltips") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->redesignedDroneTooltips.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->redesignedDroneTooltips.currentValue = EventsParser::ParseBoolean(enabled);
            }
            if (strcmp(node->name(), "redesignedAugmentTooltips") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->redesignedAugmentTooltips.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->redesignedAugmentTooltips.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "eventTooltips") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->eventTooltips.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->eventTooltips.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "showNumericalWeaponCooldown") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->showWeaponCooldown.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->showWeaponCooldown.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "showReactor") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->showReactor.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->showReactor.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "extraShipInfo") == 0)
            {
                auto showMissileCount = node->first_attribute("missileCount")->value();
                customOptions->showMissileCount.defaultValue = EventsParser::ParseBoolean(showMissileCount);
                customOptions->showMissileCount.currentValue = EventsParser::ParseBoolean(showMissileCount);

                auto showDroneCount = node->first_attribute("droneCount")->value();
                customOptions->showDroneCount.defaultValue = EventsParser::ParseBoolean(showDroneCount);
                customOptions->showDroneCount.currentValue = EventsParser::ParseBoolean(showDroneCount);

                auto showCrewLimit = node->first_attribute("crewLimit")->value();
                customOptions->showCrewLimit.defaultValue = EventsParser::ParseBoolean(showCrewLimit);
                customOptions->showCrewLimit.currentValue = EventsParser::ParseBoolean(showCrewLimit);
            }

            if (strcmp(node->name(), "showAllConnections") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->showAllConnections.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->showAllConnections.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "showScrapCollectorScrap") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->showScrapCollectorScrap.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->showScrapCollectorScrap.currentValue = EventsParser::ParseBoolean(enabled);
            }
            
            if (strcmp(node->name(), "preIgniteChargers") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->preIgniteChargers.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->preIgniteChargers.currentValue = EventsParser::ParseBoolean(enabled);
            }
            
            if (strcmp(node->name(), "altLockedMiniships") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->altLockedMiniships.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->altLockedMiniships.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "altCreditSystem") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->altCreditSystem.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->altCreditSystem.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "allowRenameInputSpecialCharacters") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->allowRenameInputSpecialCharacters.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->allowRenameInputSpecialCharacters.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "alternateOxygenRendering") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->alternateOxygenRendering.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->alternateOxygenRendering.currentValue = EventsParser::ParseBoolean(enabled);
                if (EventsParser::ParseBoolean(enabled))
                {
                    for (auto child = node->first_node(); child; child = child->next_sibling())
                    {
                        if (strcmp(child->name(), "gradient") == 0)
                        {
                            AlternateOxygenManager::GetInstance()->ParseGradientNode(child);
                        }
                    }
                    if (AlternateOxygenManager::GetInstance()->IsGradientEmpty())
                    {
                        AlternateOxygenManager::GetInstance()->CreateDefaultGradient();
                    }
                }
            }

            if (strcmp(node->name(), "advancedCrewTooltips") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->advancedCrewTooltips.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->advancedCrewTooltips.currentValue = EventsParser::ParseBoolean(enabled);
                if(EventsParser::ParseBoolean(enabled))
                {
                    if(node->first_attribute("ally"))
                    {
                        customOptions->showAllyPowers.defaultValue = EventsParser::ParseBoolean(node->first_attribute("ally")->value());
                        customOptions->showAllyPowers.currentValue = EventsParser::ParseBoolean(node->first_attribute("ally")->value());
                    }
                    if(node->first_attribute("enemy"))
                    {
                        customOptions->showEnemyPowers.defaultValue = EventsParser::ParseBoolean(node->first_attribute("enemy")->value());
                        customOptions->showEnemyPowers.currentValue = EventsParser::ParseBoolean(node->first_attribute("enemy")->value());
                    }
                    if(node->first_attribute("rounding"))
                    {
                        customOptions->advancedCrewTooltipRounding.defaultValue = boost::lexical_cast<int>(node->first_attribute("rounding")->value());
                        customOptions->advancedCrewTooltipRounding.currentValue = boost::lexical_cast<int>(node->first_attribute("rounding")->value());
                    }
                }
            }

            if (strcmp(node->name(), "dismissSound") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                if (EventsParser::ParseBoolean(enabled))
                {
                    if (node->first_attribute("sound"))
                    {
                        customOptions->dismissSound.defaultValue = node->first_attribute("sound")->value();
                        customOptions->dismissSound.currentValue = node->first_attribute("sound")->value();
                    }
                }
                else
                {
                    customOptions->dismissSound.defaultValue = "";
                    customOptions->dismissSound.currentValue = "";
                }
            }

            if (strcmp(node->name(), "console") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                CommandConsole::GetInstance()->enabled = EventsParser::ParseBoolean(enabled);

                if (node->first_attribute("invertCaps"))
                {
                    auto invertCaps = node->first_attribute("invertCaps")->value();
                    CommandConsole::GetInstance()->invertCaps = EventsParser::ParseBoolean(invertCaps);
                }
            }

            if (strcmp(node->name(), "infinite") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_infiniteMode = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "transformColorMode") == 0)
            {
                if (strcmp(node->name(), "KEEP_COLORS") == 0)
                {
                    g_transformColorMode = TransformColorMode::KEEP_COLORS;
                }
                else if (strcmp(node->name(), "KEEP_INDICES") == 0)
                {
                    g_transformColorMode = TransformColorMode::KEEP_INDICES;
                }
            }

            if (strcmp(node->name(), "showShipAchievements") == 0)
            {
                auto customShipManager = CustomShipSelect::GetInstance();
                if (node->first_attribute("enabled"))
                {
                    customShipManager->showShipAchievements = EventsParser::ParseBoolean(node->first_attribute("enabled")->value());
                }
                if (node->first_attribute("toggle"))
                {
                    customShipManager->shipAchievementsToggle = EventsParser::ParseBoolean(node->first_attribute("toggle")->value());
                }
                if (node->first_attribute("hideIfMissing"))
                {
                    customShipManager->hideMissingShipAchievements = EventsParser::ParseBoolean(node->first_attribute("hideIfMissing")->value());
                }
                if (node->first_attribute("id"))
                {
                    customShipManager->shipAchievementsTitle = node->first_attribute("id")->value();
                }
            }

            if (strcmp(node->name(), "victories") == 0)
            {
                auto customUnlocks = CustomShipUnlocks::instance;
                customUnlocks->ParseVictoryAchievements(node);
            }

            if (strcmp(node->name(), "achievements") == 0)
            {
                auto customAchievements = CustomAchievementTracker::instance;
                customAchievements->ParseAchievements(node);
            }

            if (strcmp(node->name(), "ships") == 0)
            {
                auto customShipManager = CustomShipSelect::GetInstance();
                customShipManager->ParseShipsNode(node);
            }

            if (strcmp(node->name(), "shipGenerators") == 0)
            {
                CustomShipGenerator::Init();
                CustomShipGenerator::ParseGeneratorNode(node);
            }

            if (strcmp(node->name(), "crew") == 0)
            {
                auto customCrewManager = CustomCrewManager::GetInstance();
                customCrewManager->ParseCrewNode(node);
            }

            if (strcmp(node->name(), "rewards") == 0)
            {
                auto customRewardsManager = CustomRewardsManager::GetInstance();
                customRewardsManager->ParseRewardsNode(node);
            }

            if (strcmp(node->name(), "sectorMap") == 0)
            {
                auto customSectorParser = CustomSectorManager::GetInstance();
                customSectorParser->ParseCustomSectorMapNode(node);
            }

            if (strcmp(node->name(), "events") == 0)
            {
                auto customEventParser = CustomEventsParser::GetInstance();
                customEventParser->ParseCustomEventNode(node);
            }

            if (strcmp(node->name(), "augments") == 0)
            {
                auto customAugmentManager = CustomAugmentManager::GetInstance();
                customAugmentManager->ParseCustomAugmentNode(node);
            }

            if (strcmp(node->name(), "titleScreen") == 0)
            {
                CustomMainMenu::GetInstance()->ParseTitleScreenNode(node);
            }
            if (strcmp(node->name(), "forceDlc") == 0)
            {
                Global::forceDlc = EventsParser::ParseBoolean(node->first_attribute("enabled")->value());
            }
            if (strcmp(node->name(), "boss") == 0)
            {
                CustomBoss::instance->ParseBossNode(node);
            }
            if (strcmp(node->name(), "store") == 0)
            {
                CustomStore::instance->ParseStoreNode(node);
            }
            if (strcmp(node->name(), "purchaseLimitNumber") == 0)
            {
                PurchaseLimitIndicatorInfo::fontSize = boost::lexical_cast<int>(node->first_attribute("fontSize")->value());
                PurchaseLimitIndicatorInfo::x = boost::lexical_cast<int>(node->first_attribute("x")->value());
                PurchaseLimitIndicatorInfo::y = boost::lexical_cast<int>(node->first_attribute("y")->value());
            }
            if (strcmp(node->name(), "drones") == 0)
            {
                CustomDroneManager::GetInstance()->ParseDroneNode(node);
            }
            if (strcmp(node->name(), "seeds") == 0)
            {
                if (node->first_attribute("enabled"))
                {
                    SeedInputBox::seedsEnabled = EventsParser::ParseBoolean(node->first_attribute("enabled")->value());
                }
                if (node->first_attribute("allowUnlocks"))
                {
                    SeedInputBox::seedsAllowUnlocks = EventsParser::ParseBoolean(node->first_attribute("allowUnlocks")->value());
                }
                if (node->first_attribute("allowAchievements"))
                {
                    SeedInputBox::seedsAllowAchievements = EventsParser::ParseBoolean(node->first_attribute("allowAchievements")->value());
                }
                if (node->first_attribute("allowMetaVars"))
                {
                    SeedInputBox::seedsAllowMetaVars = EventsParser::ParseBoolean(node->first_attribute("allowMetaVars")->value());
                }
            }
            if (strcmp(node->name(), "renameShipInRun") == 0)
            {
                if (node->first_attribute("enabled"))
                {
                    CustomUpgrades::GetInstance()->allowRename = EventsParser::ParseBoolean(node->first_attribute("enabled")->value());
                }
                if (node->first_attribute("allowButton"))
                {
                    CustomUpgrades::GetInstance()->allowButton = EventsParser::ParseBoolean(node->first_attribute("allowButton")->value());
                }
            }
            if (strcmp(node->name(), "customSystems") == 0)
            {
                ParseSystemsNode(node);
            }
            if (strcmp(node->name(), "scripts") == 0)
            {
                for (auto child = node->first_node(); child; child = child->next_sibling())
                {
                    if (strcmp(child->name(), "script") == 0)
                    {
                        Global::GetInstance()->getLuaContext()->runLuaFileFromDat(child->value());
                    }
                }
            }
            #ifdef USE_DISCORD
            if (strcmp(node->name(), "discord") == 0)
            {
                auto enabled = EventsParser::ParseBoolean(node->first_attribute("enabled")->value());

                if (enabled)
                {
                    DiscordHandler::GetInstance()->ParseDiscordNode(node);

                    DiscordHandler::GetInstance()->Initialize();

                    std::string modName = G_->GetTextLibrary()->GetText("discord_mod");

                    std::string details = "";

                    if (modName.empty())
                    {
                        details = G_->GetTextLibrary()->GetText("discord_playing_vanilla");
                        DiscordHandler::GetInstance()->vanilla = true;
                    }
                    else
                    {
                        details = G_->GetTextLibrary()->GetText("discord_playing_modded");
                        boost::replace_all(details, "\\1", modName);
                        DiscordHandler::GetInstance()->vanilla = false;
                    }

                    DiscordHandler::GetInstance()->SetLargeImageText(details);
                }
            }
            #endif // USE_DISCORD
            if (strcmp(node->name(), "saveFile") == 0)
            {
                SaveFileHandler::instance->ParseSaveFileNode(node);
            }
            if (strcmp(node->name(), "systemNoPurchaseThreshold") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                SystemNoPurchaseThreshold::enabled = EventsParser::ParseBoolean(enabled);
                if (SystemNoPurchaseThreshold::enabled)
                {
                    SystemNoPurchaseThreshold::threshold = boost::lexical_cast<int>(node->first_attribute("threshold")->value());
                    SystemNoPurchaseThreshold::replace = node->first_attribute("replace")->value();
                }
            }
        }

        // Post-processing (might not be needed anymore)
        {
            auto customEventParser = CustomEventsParser::GetInstance();
            customEventParser->PostProcessCustomEvents();
        }


        if (!checkedVersion)
        {
            throw "Wrong version of Hyperspace detected. Please check that Hyperspace is installed correctly and you are using the correct version of Hyperspace for all of your mods. You can continue, but mods may function incorrectly.";
        }

        doc.clear();
    }
    catch (rapidxml::parse_error& e)
    {
        ErrorMessage(std::string("Error parsing hyperspace.xml\n") + std::string(e.what()));
    }
    catch (std::exception &e)
    {
        ErrorMessage(std::string("Error parsing hyperspace.xml\n") + std::string(e.what()));
    }
    catch (const char* e)
    {
        ErrorMessage(std::string("Error parsing hyperspace.xml\n") + std::string(e));
    }
    catch (...)
    {
        ErrorMessage("Error parsing hyperspace.xml\n");
    }

    delete [] hyperspacetext;
    //G_->lua = new LuaState;
}





