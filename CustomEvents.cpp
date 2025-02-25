#include "CustomAugments.h"
#include "CustomEvents.h"
#include "Resources.h"
#include "Seeds.h"
#include "ShipUnlocks.h"
#include "CustomFleetShips.h"
#include "CustomBoss.h"
#include "CustomCrew.h"
#include "CustomSectors.h"
#include "CustomOptions.h"
#include "CustomAchievements.h"
#include "CustomScoreKeeper.h"
#include "CustomBackgroundObject.h"
#include "EventButtons.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

std::bitset<8> advancedCheckEquipment{0x00};

CustomEventsParser *CustomEventsParser::instance = new CustomEventsParser();
bool alreadyWonCustom = false;
bool bossDefeated = false;

TimerHelper *restartMusicTimer = nullptr;

std::vector<CreditText> creditTextValues;
std::vector<CreditFinishText> creditFinishTextValues;
std::vector<CreditFile> creditFileNames;
float scrollSpeed = 1.f;
float fadeInSpeed = -0.005f;
float scrollDelay = 250.f;
float pauseDuration = 400.f;
float pausePosition = 675.f;
int creditNamesFontSize = 14;

std::unordered_map<std::string, EventAlias> eventAliases = std::unordered_map<std::string, EventAlias>();

std::unordered_map<int, std::string> renamedBeacons = std::unordered_map<int, std::string>();
std::unordered_map<int, std::pair<std::string, int>> regeneratedBeacons = std::unordered_map<int, std::pair<std::string, int>>();
std::vector<bool> savedPriorityEventReq = std::vector<bool>();

std::vector<JumpEvent> jumpEventQueue;
std::deque<DeathEvent> deathEventQueue;

std::unordered_map<std::string, int> playerVariables = std::unordered_map<std::string, int>();

CustomEvent::CustomEvent()
{
    checkCargo = CustomOptionsManager::GetInstance()->defaults.checkCargo;
    choiceRequiresCrew = CustomOptionsManager::GetInstance()->defaults.choiceRequiresCrew;
}

void CustomEventsParser::EarlyParseCustomEventNode(rapidxml::xml_node<char> *node)
{
    for (auto eventNode = node->first_node(); eventNode; eventNode = eventNode->next_sibling())
    {
        if (strcmp(eventNode->name(), "eventFile") == 0)
        {
            if (eventNode->value())
            {
                eventFiles.push_back(std::string(eventNode->value()));
            }
        }

        if (strcmp(eventNode->name(), "loadEventList") == 0)
        {

            EventLoadList *eventLoadList = new EventLoadList();
            std::string loadEventListName = "";
            if (eventNode->first_attribute("name"))
            {
                loadEventListName = eventNode->first_attribute("name")->value();
            }
            ParseCustomEventLoadList(eventNode, eventLoadList, loadEventListName);
            if (!loadEventListName.empty())
            {
                customEventLoadLists[loadEventListName] = eventLoadList;
            }
        }

        if (strcmp(eventNode->name(), "triggeredEventBox") == 0)
        {
            TriggeredEventBoxDefinition boxDef;
            ParseCustomTriggeredEventBoxNode(eventNode, &boxDef);
            if (eventNode->first_attribute("name"))
            {
                TriggeredEventGui::GetInstance()->boxDefs[eventNode->first_attribute("name")->value()] = boxDef;
            }
        }

        if (strcmp(eventNode->name(), "timerSounds") == 0)
        {
            std::vector<std::pair<float,std::string>> timerSounds;
            ParseCustomTriggeredEventSounds(eventNode, &timerSounds);
            if (eventNode->first_attribute("name"))
            {
                TriggeredEventDefinition::timerSoundDefs[eventNode->first_attribute("name")->value()] = timerSounds;
            }
        }

        if (strcmp(eventNode->name(), "warningMessage") == 0)
        {
            TriggeredEventWarningDefinition warningDef;
            ParseCustomTriggeredEventWarningNode(eventNode, &warningDef);
            if (eventNode->first_attribute("name"))
            {
                TriggeredEventGui::GetInstance()->warningDefs[eventNode->first_attribute("name")->value()] = warningDef;
            }
        }

        if (strcmp(eventNode->name(), "beaconType") == 0)
        {
            if (eventNode->first_attribute("name"))
            {
                std::string beaconName = std::string(eventNode->first_attribute("name")->value());

                BeaconType *beaconType = new BeaconType();
                beaconType->eventName = beaconName;

                ParseCustomBeaconType(eventNode, beaconType);

                customBeacons[beaconName] = beaconType;
            }
        }

        if (strcmp(eventNode->name(), "backgroundObject") == 0)
        {
            if (eventNode->first_attribute("name"))
            {
                CustomBackgroundObjectManager::instance->ParseCustomBackgroundObject(eventNode);
            }
        }

        if (strcmp(eventNode->name(), "eventButton") == 0)
        {
            if (eventNode->first_attribute("name"))
            {
                EventButtonManager::instance->ParseEventButton(eventNode);
            }
        }
    }
}

void CustomEventsParser::ParseCustomCredits(rapidxml::xml_node<char> *node)
{
    CreditText creditText;
    CreditFinishText creditFinishText;
    Pointf dynamicCutOff;
    int creditNamesLineSpacing = 40;
    int creditNamesToFinishTextSpacing = 100;
    
    for (auto creditNode = node->first_node(); creditNode; creditNode = creditNode->next_sibling())
    {
        // Parse <scrollSpeed/> xml tag
        if (strcmp(creditNode->name(), "scrollSpeed") == 0) 
        {
            if (auto speedMultiplier = creditNode->first_attribute("speed"))
            {
                std::string multiplierStr = speedMultiplier->value();
                try
                {
                    scrollSpeed = std::stof(multiplierStr);
                }
                catch (const std::invalid_argument& e)
                {
                    hs_log_file("Failed to convert an attribute value in 'scrollSpeed' to a float. Using default value.\n");
                }
            }
        }

        // Parse <fadeInSpeed/> xml tag
        if (strcmp(creditNode->name(), "fadeInSpeed") == 0) 
        {
            if (auto speedMultiplier = creditNode->first_attribute("speed"))
            {
                std::string multiplierStr = speedMultiplier->value();
                try
                {
                    fadeInSpeed = std::stof(multiplierStr);
                }
                catch (const std::invalid_argument& e)
                {
                    hs_log_file("Failed to convert an attribute value in 'fadeInSpeed' to a float. Using default value.\n");
                }
            }
        }

        // Parse scroll pause & initial delay
        if (strcmp(creditNode->name(), "scrollPause") == 0)
        {
            if (auto scrollDelayAttribute = creditNode->first_attribute("scrollDelay")) 
            {
                try
                {
                    scrollDelay = std::stof(scrollDelayAttribute->value()) * 50;
                }
                catch (const std::invalid_argument& e) 
                {
                    hs_log_file("Failed to convert an attribute value in 'scrollDelay' to a float. Using default value.\n");
                }
            }

            if (auto pauseDurationAttribute = creditNode->first_attribute("duration")) 
            {
                try 
                {
                    pauseDuration = std::stof(pauseDurationAttribute->value()) * 50 + scrollDelay;
                } 
                catch (const std::invalid_argument& e) 
                {
                    hs_log_file("Failed to convert an attribute value in 'duration' to a float. Using default value.\n");
                }
            }

            if (auto pausePositionAttribute = creditNode->first_attribute("pausePosition")) 
            {
                try 
                {
                    pausePosition = std::stof(pausePositionAttribute->value());
                } 
                catch (const std::invalid_argument& e) 
                {
                    hs_log_file("Failed to convert an attribute value in 'pausePosition' to a float. Using default value.\n");
                }
            }
        }

        // Parse <text/> xml tag
        if (strcmp(creditNode->name(), "text") == 0)
        {
            std::string textString;
            int textFont;
            if (auto idAttribute = creditNode->first_attribute("id"))
            {
                creditText.text = idAttribute->value();
                textString = creditText.text;
            }
            else creditText.text = "Error: 'id' attribute missing";

            if (auto fontSizeAttribute = creditNode->first_attribute("fontSize"))
            {
                std::string fontSizeStr = fontSizeAttribute->value();
                try
                {
                    creditText.font = std::stoi(fontSizeStr);
                    textFont = creditText.font;
                }
                catch (const std::invalid_argument& e)
                {
                    hs_log_file("Failed to convert an attribute value in 'text' to an integer. Using default value.\n");
                    creditText.font = 14;
                }
            }
            else creditText.font = 14;

            if (auto horizontalAttribute = creditNode->first_attribute("horizontal"))
            {
                std::string horizontalStr = horizontalAttribute->value();
                try
                {
                    creditText.horizontal = std::stoi(horizontalStr);
                }
                catch (const std::invalid_argument& e)
                {
                    hs_log_file("Failed to convert an attribute value in 'text' to an integer. Using default value.\n");
                    creditText.horizontal = 360;
                }
            }
            else creditText.horizontal = 360;

            if (auto spacingAttribute = creditNode->first_attribute("spacing"))
            {
                std::string spacingStr = spacingAttribute->value();
                try
                {
                    creditText.spacing = std::stoi(spacingStr);
                }
                catch (const std::invalid_argument& e)
                {
                    hs_log_file("Failed to convert an attribute value in 'text' to an integer. Using default value.\n");
                    creditText.spacing = 40;
                }
            }
            else creditText.spacing = 40;


            if (auto lineLenghtAttribute = creditNode->first_attribute("lineLenght"))
            {
                std::string lineLenghtStr = lineLenghtAttribute->value();
                try
                {
                    creditText.lineLenght = std::stoi(lineLenghtStr);
                }
                catch (const std::invalid_argument& e)
                {
                    hs_log_file("Failed to convert an attribute value in 'text' to an integer. Using default value.\n");
                    creditText.lineLenght = 750;
                }
            }
            else creditText.lineLenght = 750;
            
            dynamicCutOff = freetype::easy_measurePrintLines(textFont, 0, 0, 750, textString);
            creditText.cutOff = dynamicCutOff.x + 50;

            creditTextValues.push_back(creditText);
        }

        // Parse <finishText/> xml tag
        if (strcmp(creditNode->name(), "finishText") == 0)
        {
            std::string textString;
            int textFont;
            if (auto idAttribute = creditNode->first_attribute("id"))
            {
                creditFinishText.text = idAttribute->value();
                textString = creditFinishText.text;
            }
            else creditFinishText.text = "Error: 'id' attribute missing";

            if (auto fontSizeAttribute = creditNode->first_attribute("fontSize"))
            {
                std::string fontSizeStr = fontSizeAttribute->value();
                try
                {
                    creditFinishText.font = std::stoi(fontSizeStr);
                    textFont = creditFinishText.font;
                }
                catch (const std::invalid_argument& e)
                {
                    hs_log_file("Failed to convert an attribute value in 'finishText' to an integer. Using default value.\n");
                    creditFinishText.font = 14;
                }
            }
            else creditFinishText.font = 14;

            if (auto horizontalAttribute = creditNode->first_attribute("horizontal"))
            {
                std::string horizontalStr = horizontalAttribute->value();
                try
                {
                    creditFinishText.horizontal = std::stoi(horizontalStr);
                }
                catch (const std::invalid_argument& e)
                {
                    hs_log_file("Failed to convert an attribute value in 'finishText' to an integer. Using default value.\n");
                    creditFinishText.horizontal = 360;
                }
            }
            else creditFinishText.horizontal = 360;

            if (auto spacingAttribute = creditNode->first_attribute("spacing"))
            {
                std::string spacingStr = spacingAttribute->value();
                try
                {
                    creditFinishText.spacing = std::stoi(spacingStr);
                }
                catch (const std::invalid_argument& e)
                {
                    hs_log_file("Failed to convert an attribute value in 'finishText' to an integer. Using default value.\n");
                    creditFinishText.spacing = 40;
                }
            }
            else creditFinishText.spacing = 40;

            if (auto lineLenghtAttribute = creditNode->first_attribute("lineLenght"))
            {
                std::string lineLenghtStr = lineLenghtAttribute->value();
                try
                {
                    creditFinishText.lineLenght = std::stoi(lineLenghtStr);
                }
                catch (const std::invalid_argument& e)
                {
                    hs_log_file("Failed to convert an attribute value in 'text' to an integer. Using default value.\n");
                    creditFinishText.lineLenght = 1000;
                }
            }
            else creditFinishText.lineLenght = 1000;
            
            dynamicCutOff = freetype::easy_measurePrintLines(textFont, 0, 0, 1000, textString);
            creditFinishText.cutOff = dynamicCutOff.x + 50;

            creditFinishTextValues.push_back(creditFinishText);
        }

        // Parse values for credits.txt
        if (strcmp(creditNode->name(), "creditNames") == 0)
        {   
            if (auto valueAttribute = creditNode->first_attribute("fontSize"))
            {
                std::string valueStr = valueAttribute->value();
                try
                {
                    creditNamesFontSize = std::stoi(valueStr);
                }
                catch (const std::invalid_argument& e)
                {
                    hs_log_file("Failed to convert an attribute value in 'creditNames' to an integer. Using default value.\n");
                }
            }

            if (auto valueAttribute = creditNode->first_attribute("spacingBetweenNames"))
            {
                std::string valueStr = valueAttribute->value();
                try
                {
                    creditNamesLineSpacing = std::stoi(valueStr);
                }
                catch (const std::invalid_argument& e)
                {
                    hs_log_file("Failed to convert an attribute value in 'creditNames' to an integer. Using default value.\n");
                }
            }

            if (auto valueAttribute = creditNode->first_attribute("spacingToFinishTexts"))
            {
                std::string valueStr = valueAttribute->value();
                try
                {
                    creditNamesToFinishTextSpacing = std::stoi(valueStr);
                }
                catch (const std::invalid_argument& e)
                {
                    hs_log_file("Failed to convert an attribute value in 'creditNames' to an integer. Using default value.\n");
                }
            }
        }
    }

    // Parse contents in credit.txt
    CreditFile creditFile;
    char* creditsTextFile = G_->GetResources()->LoadFile("data/credits.txt");
    std::stringstream ss(creditsTextFile);
    delete [] creditsTextFile;
    std::string line;
    int lineCount = 0;
    int totalLines = std::count(std::istreambuf_iterator<char>(ss), std::istreambuf_iterator<char>(), '\n');
    ss.seekg(0);
    int remainder = totalLines % 3;
    int additionalEntries = (remainder == 0) ? 0 : 3 - remainder;

    while (std::getline(ss, line))
    {
        creditFile.names = line;
        creditFile.spacing = ((lineCount + 1) % 3 == 0) ? creditNamesLineSpacing : 0;
        dynamicCutOff = freetype::easy_measurePrintLines(creditNamesFontSize, 0, 0, 750, line);
        creditFile.cutOff = dynamicCutOff.x + 50;
        creditFileNames.push_back(creditFile);
        lineCount++;
    }

    for (int i = 0; i < additionalEntries; ++i)
    {
        CreditFile emptyEntry;
        emptyEntry.names = "\n";
        emptyEntry.spacing = 0;
        creditFileNames.push_back(emptyEntry);
    }

    int lastIndex = creditFileNames.size() - 1;
    creditFileNames[lastIndex].spacing = creditNamesToFinishTextSpacing;
}

void CustomEventsParser::ReadCustomEventFiles()
{
    char* eventText = G_->GetResources()->LoadFile("data/events_hyperspace.xml");

    if (eventText)
    {
        try
        {
            G_->GetEventsParser()->AddEvents(*G_->GetEventGenerator(), eventText, "data/events_hyperspace.xml");
        }
        catch (rapidxml::parse_error& e)
        {
            ErrorMessage(std::string("Failed parsing events_hyperspace.xml\n") + std::string(e.what()));
        }
        catch (std::exception &e)
        {
            ErrorMessage(std::string("Failed parsing events_hyperspace.xml\n") + std::string(e.what()));
        }
        catch (const char* e)
        {
            ErrorMessage(std::string("Failed parsing events_hyperspace.xml\n") + std::string(e));
        }

        delete [] eventText;
    }

    for (auto i : CustomEventsParser::GetInstance()->eventFiles)
    {
        std::string fileName = "data/events_" + i + ".xml";

        char* eventText = G_->GetResources()->LoadFile(fileName);

        if (eventText)
        {
            try
            {
                G_->GetEventsParser()->AddEvents(*G_->GetEventGenerator(), eventText, fileName);
            }
            catch (rapidxml::parse_error& e)
            {
                ErrorMessage(std::string("Failed parsing ") + fileName + std::string("\n") + std::string(e.what()));
            }
            catch (std::exception &e)
            {
                ErrorMessage(std::string("Failed parsing ") + fileName + std::string("\n") + std::string(e.what()));
            }
            catch (const char* e)
            {
                ErrorMessage(std::string("Failed parsing ") + fileName + std::string("\n") + std::string(e));
            }

            delete [] eventText;
        }
    }
}

void CustomEventsParser::ParseCustomEventNode(rapidxml::xml_node<char> *node)
{
    for (auto eventNode = node->first_node(); eventNode; eventNode = eventNode->next_sibling())
    {
        if (strcmp(eventNode->name(), "bossShip") == 0)
        {
            if (eventNode->value())
            {
                BossShipDefinition def = BossShipDefinition();
                def.shipId = eventNode->value();

                if (eventNode->first_attribute("yOffset"))
                {
                    def.yOffset = boost::lexical_cast<int>(eventNode->first_attribute("yOffset")->value());
                }

                bossShipIds[def.shipId] = def;
            }
        }

        if (strcmp(eventNode->name(), "fleetDef") == 0)
        {
            ParseFleetShipNode(eventNode);
        }

        if (strcmp(eventNode->name(), "sector") == 0)
        {
            std::string sectorName = eventNode->first_attribute("name")->value();

            if (!sectorName.empty())
            {
                CustomSector *sec = GetCustomSectorPreload(sectorName);

                if (sec == nullptr)
                {
                    sec = new CustomSector();
                }

                sec->sectorName = sectorName;

                ParseCustomSector(eventNode, sec);

                customSectorsPreload[sectorName] = sec;
            }
        }

        if (strcmp(eventNode->name(), "revisitEvent") == 0)
        {
            defaultRevisit = eventNode->value();

            if (eventNode->first_attribute("seeded"))
            {
                defaultRevisitSeeded = EventsParser::ParseBoolean(eventNode->first_attribute("seeded")->value());
            }
            if (eventNode->first_attribute("ignoreUnique"))
            {
                defaultRevisitIgnoreUnique = EventsParser::ParseBoolean(eventNode->first_attribute("ignoreUnique")->value());
            }
        }

        if (strcmp(eventNode->name(), "event") == 0)
        {
            if (eventNode->first_attribute("name"))
            {
                std::string eventName = std::string(eventNode->first_attribute("name")->value());

                CustomEvent *customEvent;
                if (eventName == "default_victory")
                {
                    customEvent = defaultVictory;
                    customEvent->eventName = "default_victory";
                    ParseCustomEvent(eventNode, customEvent);
                }
                else
                {
                    if (eventNode->first_attribute("recursive") && !EventsParser::ParseBoolean(eventNode->first_attribute("recursive")->value()))
                    {
                        auto it = customEvents.find(eventName);
                        if (it == customEvents.end())
                        {
                            auto it2 = customRecursiveEvents.find(eventName);
                            if (it2 != customRecursiveEvents.end())
                            {
                                customEvent = new CustomEvent(*it2->second);
                            }
                            else
                            {
                                customEvent = new CustomEvent();
                            }
                            customEvent->eventName = eventName;
                            customEvent->recursive = false;
                            ParseCustomEvent(eventNode, customEvent);
                            customEvents[eventName] = customEvent;
                            vCustomEvents[eventName].push_back(customEvent);
                        }
                        else
                        {
                            customEvent = it->second;
                            ParseCustomEvent(eventNode, customEvent);
                        }
                    }
                    else
                    {
                        auto it = customRecursiveEvents.find(eventName);
                        if (it == customRecursiveEvents.end())
                        {
                            customEvent = new CustomEvent();
                            customEvent->eventName = eventName;
                            ParseCustomEvent(eventNode, customEvent);
                            customRecursiveEvents[eventName] = customEvent;
                        }
                        else
                        {
                            customEvent = it->second;
                            ParseCustomEvent(eventNode, customEvent);
                        }

                        auto it2 = vCustomEvents.find(eventName);
                        if (it2 != vCustomEvents.end())
                        {
                            std::vector<CustomEvent*>& vCustomEvent = it2->second;
                            for (CustomEvent* customEvent : vCustomEvent)
                            {
                                ParseCustomEvent(eventNode, customEvent);
                            }
                        }
                    }
                }
            }
        }

        if (strcmp(eventNode->name(), "shipEvent") == 0)
        {
            if (eventNode->first_attribute("name"))
            {
                std::string eventName = std::string(eventNode->first_attribute("name")->value());
                CustomShipEvent *customEvent;

                auto it = customShipEvents.find(eventName);
                if (it == customShipEvents.end())
                {
                    customEvent = new CustomShipEvent();
                    customEvent->eventName = eventName;
                    ParseCustomShipEvent(eventNode, customEvent);
                    customShipEvents[eventName] = customEvent;
                }
                else
                {
                    customEvent = it->second;
                    ParseCustomShipEvent(eventNode, customEvent);
                }
            }
        }

        if (strcmp(eventNode->name(), "quest") == 0)
        {
            ParseCustomQuestNode(eventNode, defaultQuest);
        }

        if (strcmp(eventNode->name(), "req") == 0)
        {
            if (eventNode->first_attribute("name"))
            {
                std::string reqName = std::string(eventNode->first_attribute("name")->value());

                CustomReq *customReq;
                if (GetCustomReq(reqName) == nullptr)
                {
                    customReq = new CustomReq();
                }
                else
                {
                    customReq = GetCustomReq(reqName);
                    delete customReq;
                    customReq = new CustomReq();
                }

                ParseCustomReqNode(eventNode, customReq);

                customReqs[reqName] = customReq;
            }
            else
            {
                ErrorMessage("Custom req is missing a name!\n");
            }
        }

        if (strcmp(eventNode->name(), "combatTimerPosition") == 0)
        {
            for (auto child = eventNode->first_node(); child; child = child->next_sibling())
            {
                std::string nodeName(child->name());
                if (nodeName == "normalPos")
                {
                    if (child->first_attribute("x"))
                    {
                        TriggeredEventGui::GetInstance()->normalBoxPos.x = boost::lexical_cast<int>(child->first_attribute("x")->value());
                    }
                    if (child->first_attribute("y"))
                    {
                        TriggeredEventGui::GetInstance()->normalBoxPos.y = boost::lexical_cast<int>(child->first_attribute("y")->value());
                    }
                }
                if (nodeName == "bossPos")
                {
                    if (child->first_attribute("x"))
                    {
                        TriggeredEventGui::GetInstance()->bossBoxPos.x = boost::lexical_cast<int>(child->first_attribute("x")->value());
                    }
                    if (child->first_attribute("y"))
                    {
                        TriggeredEventGui::GetInstance()->bossBoxPos.y = boost::lexical_cast<int>(child->first_attribute("y")->value());
                    }
                }
            }
        }

        if (strcmp(eventNode->name(), "variable") == 0)
        {
            VariableModifier variable;
            variable.ParseVariableModifierNode(eventNode);
            initialPlayerVars.push_back(variable);
        }

        if (strcmp(eventNode->name(), "metaVariable") == 0)
        {
            VariableModifier variable;
            variable.ParseVariableModifierNode(eventNode);
            initialMetaVars.push_back(variable);
        }
    }
}

void CustomEventsParser::PostProcessCustomEvents()
{
    for (auto& def : TriggeredEventDefinition::defs)
    {
        if (def.loadBox)
        {
            rapidxml::xml_document<> doc;
            doc.parse<0>(def.loadBox->data());
            auto node = doc.first_node("triggeredEventBox");
            if (node)
            {
                if (node->first_attribute("load"))
                {
                    std::string loadName = node->first_attribute("load")->value();
                    auto it = TriggeredEventGui::GetInstance()->boxDefs.find(loadName);
                    if (it != TriggeredEventGui::GetInstance()->boxDefs.end())
                    {
                        *(def.box) = it->second;
                    }
                    else
                    {
                        ErrorMessage(std::string("Failed to load triggeredEventBox ") + loadName);
                    }
                }
                ParseCustomTriggeredEventBoxNode(node, def.box);
            }

            doc.clear();
            delete def.loadBox;
            def.loadBox = nullptr;
        }
        if (!def.loadTimerSounds.empty())
        {
            auto it = TriggeredEventDefinition::timerSoundDefs.find(def.loadTimerSounds);
            if (it != TriggeredEventDefinition::timerSoundDefs.end())
            {
                for (std::pair<float,std::string>& timerSound : it->second)
                {
                    def.timerSounds.push_back(timerSound);
                }
                std::sort(def.timerSounds.begin(), def.timerSounds.end(), [](const std::pair<float,std::string> &a, const std::pair<float,std::string> &b) -> bool {return a.first > b.first;});
            }
            else
            {
                ErrorMessage(std::string("Failed to load timerSounds ") + def.loadTimerSounds);
            }
        }
        if (def.loadWarning)
        {
            rapidxml::xml_document<> doc;
            doc.parse<0>(def.loadWarning->data());
            auto node = doc.first_node("warningMessage");
            if (node)
            {
                if (node->first_attribute("load"))
                {
                    std::string loadName = node->first_attribute("load")->value();
                    auto it = TriggeredEventGui::GetInstance()->warningDefs.find(loadName);
                    if (it != TriggeredEventGui::GetInstance()->warningDefs.end())
                    {
                        *(def.warning) = it->second;
                    }
                    else
                    {
                        ErrorMessage(std::string("Failed to load warningMessage ") + loadName);
                    }
                }
                ParseCustomTriggeredEventWarningNode(node, def.warning);
            }

            doc.clear();
            delete def.loadWarning;
            def.loadWarning = nullptr;
        }
    }

    for (auto& def : customEvents)
    {
        if (!def.second->loadBeacon.empty())
        {
            auto it = customBeacons.find(def.second->loadBeacon);
            if (it != customBeacons.end())
            {
                def.second->beacon = it->second;
            }
        }
        def.second->loadBeacon = "";
    }
    for (auto& def : customRecursiveEvents)
    {
        if (!def.second->loadBeacon.empty())
        {
            auto it = customBeacons.find(def.second->loadBeacon);
            if (it != customBeacons.end())
            {
                def.second->beacon = it->second;
            }
        }
        def.second->loadBeacon = "";
    }
}

void CustomEventsParser::ParseCustomSector(rapidxml::xml_node<char> *node, CustomSector *sector, bool parsingVanilla)
{
    bool isDefault = true;

    if (node->first_attribute("maxSector"))
    {
        isDefault = false;
        sector->maxSector = boost::lexical_cast<int>(node->first_attribute("maxSector")->value());
    }

    for (auto sectorNode = node->first_node(); sectorNode; sectorNode = sectorNode->next_sibling())
    {
        if (strcmp(sectorNode->name(), "exitBeacon") == 0)
        {
            isDefault = false;

            SectorExit exit = SectorExit();

            if (sectorNode->first_attribute("event"))
            {
                exit.event = sectorNode->first_attribute("event")->value();
            }
            if (sectorNode->first_attribute("rebelEvent"))
            {
                exit.rebelEvent = sectorNode->first_attribute("rebelEvent")->value();
            }
            if (sectorNode->first_attribute("nebulaEvent"))
            {
                exit.nebulaEvent = sectorNode->first_attribute("nebulaEvent")->value();
            }

            sector->exitBeacons = exit;
        }

        if (strcmp(sectorNode->name(), "rebelBeacon") == 0)
        {
            isDefault = false;

            SectorFleet fleet = SectorFleet();

            if (sectorNode->first_attribute("event"))
            {
                fleet.event = sectorNode->first_attribute("event")->value();
            }
            if (sectorNode->first_attribute("nebulaEvent"))
            {
                fleet.nebulaEvent = sectorNode->first_attribute("nebulaEvent")->value();
            }

            sector->fleetBeacons = fleet;
        }

        if (strcmp(sectorNode->name(), "removeFirstBeaconNebula") == 0)
        {
            isDefault = false;
            sector->removeFirstBeaconNebula = true;
        }

        if (strcmp(sectorNode->name(), "noExit") == 0)
        {
            isDefault = false;
            sector->noExit = true;
        }

        if (strcmp(sectorNode->name(), "nebulaSector") == 0)
        {
            isDefault = false;
            sector->nebulaSector = EventsParser::ParseBoolean(sectorNode->value());
        }

        if (strcmp(sectorNode->name(), "maxSector") == 0)
        {
            isDefault = false;
            sector->maxSector = boost::lexical_cast<int>(sectorNode->value());
        }
        if (strcmp(sectorNode->name(), "priorityEvent") == 0)
        {
            isDefault = false;

            sector->priorityEventCounts.emplace_back();
            auto &event = sector->priorityEventCounts.back();

            event.event.second.min = 0;
            event.event.second.max = 0;
            event.event.second.chanceNone = 0.f;

            if (sectorNode->first_attribute("name"))
            {
                event.event.first = sectorNode->first_attribute("name")->value();
            }
            if (sectorNode->first_attribute("min"))
            {
                event.event.second.min = boost::lexical_cast<int>(sectorNode->first_attribute("min")->value());
            }
            if (sectorNode->first_attribute("max"))
            {
                event.event.second.max = boost::lexical_cast<int>(sectorNode->first_attribute("max")->value());
            }
            if (sectorNode->first_attribute("priority"))
            {
                event.priority = boost::lexical_cast<int>(sectorNode->first_attribute("priority")->value());
            }
            else
            {
                event.priority = 0;
            }
            if (sectorNode->first_attribute("req"))
            {
                event.req = sectorNode->first_attribute("req")->value();
            }
            if (sectorNode->first_attribute("max_lvl"))
            {
                event.max_lvl = boost::lexical_cast<int>(sectorNode->first_attribute("max_lvl")->value());
                event.lvl = -2147483648;
            }
            if (sectorNode->first_attribute("lvl"))
            {
                event.lvl = boost::lexical_cast<int>(sectorNode->first_attribute("lvl")->value());
            }
        }
        if (strcmp(sectorNode->name(), "quest") == 0)
        {
            isDefault = false;

            sector->sectorQuests.emplace_back();
            auto &event = sector->sectorQuests.back();

            if (sectorNode->first_attribute("event"))
            {
                event.event = sectorNode->first_attribute("event")->value();

                CustomQuest* newCustomQuest = new CustomQuest();
                bool questIsDefault = ParseCustomQuestNode(sectorNode, newCustomQuest);
                if (questIsDefault)
                {
                    delete newCustomQuest;
                }
                else
                {
                    customQuests[event.event] = newCustomQuest;
                }
            }
            if (sectorNode->first_attribute("req"))
            {
                event.req = sectorNode->first_attribute("req")->value();
            }
            if (sectorNode->first_attribute("max_lvl"))
            {
                event.max_lvl = boost::lexical_cast<int>(sectorNode->first_attribute("max_lvl")->value());
                event.lvl = -2147483648;
            }
            if (sectorNode->first_attribute("lvl"))
            {
                event.lvl = boost::lexical_cast<int>(sectorNode->first_attribute("lvl")->value());
            }
        }
    }

    if (!isDefault)
    {
        std::stable_sort(sector->priorityEventCounts.begin(), sector->priorityEventCounts.end(),
                         [](const PriorityEvent &a, const PriorityEvent &b) -> bool
                         {
                             return a.priority > b.priority;
                         });
    }
}

bool CustomEventsParser::ParseCustomEvent(rapidxml::xml_node<char> *node, CustomEvent *customEvent, bool parsingVanilla)
{
    bool isDefault = true;

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string nodeName(child->name());
        if (nodeName == "checkCargo")
        {
            isDefault = false;
            std::string nodeValue = child->value();
            if (nodeValue.empty())
            {
                customEvent->checkCargo = true;
            }
            else
            {
                customEvent->checkCargo = EventsParser::ParseBoolean(nodeValue);
            }
        }

        if (nodeName == "preventQuest")
        {
            isDefault = false;
            customEvent->preventQuest = true;
        }

        if (nodeName == "noQuestText")
        {
            isDefault = false;
            customEvent->noQuestText = true;
        }

        if (nodeName == "quest")
        {
            std::string questEventName;
            if (child->first_attribute("event"))
            {
                questEventName = child->first_attribute("event")->value();
            }
            else
            {
                questEventName = customEvent->eventName;
            }

            CustomQuest* newCustomQuest = new CustomQuest();
            bool questIsDefault = ParseCustomQuestNode(child, newCustomQuest);
            if (questIsDefault)
            {
                delete newCustomQuest;
            }
            else
            {
                customQuests[questEventName] = newCustomQuest;
            }
        }

        if (nodeName == "triggeredEvent")
        {
            isDefault = false;
            TriggeredEventDefinition def;

            ParseCustomTriggeredEventNode(child, &def);

            customEvent->triggeredEvents.push_back(TriggeredEventDefinition::PushDef(def));
        }

        if (nodeName == "clearTriggeredEvent")
        {
            if (child->first_attribute("name"))
            {
                isDefault = false;
                customEvent->clearTriggeredEvents.push_back(child->first_attribute("name")->value());
            }
            else
            {
                ErrorMessage("clearTriggeredEvent is missing a name!\n");
            }
        }

        if (nodeName == "triggeredEventModifier")
        {
            if (child->first_attribute("name"))
            {
                isDefault = false;
                TriggeredEventModifier def;
                if (child->first_attribute("name"))
                {
                    def.name = child->first_attribute("name")->value();
                }
                if (child->first_attribute("time"))
                {
                    def.minTime = boost::lexical_cast<float>(child->first_attribute("time")->value());
                    def.maxTime = boost::lexical_cast<float>(child->first_attribute("time")->value());
                }
                if (child->first_attribute("minTime"))
                {
                    def.minTime = boost::lexical_cast<float>(child->first_attribute("minTime")->value());
                }
                if (child->first_attribute("maxTime"))
                {
                    def.maxTime = boost::lexical_cast<float>(child->first_attribute("maxTime")->value());
                }
                if (child->first_attribute("jumps"))
                {
                    def.minJumps = boost::lexical_cast<int>(child->first_attribute("jumps")->value());
                    def.maxJumps = boost::lexical_cast<int>(child->first_attribute("jumps")->value());
                }
                if (child->first_attribute("minJumps"))
                {
                    def.minJumps = boost::lexical_cast<int>(child->first_attribute("minJumps")->value());
                }
                if (child->first_attribute("maxJumps"))
                {
                    def.maxJumps = boost::lexical_cast<int>(child->first_attribute("maxJumps")->value());
                }
                customEvent->triggeredEventModifiers.push_back(def);
            }
            else
            {
                ErrorMessage("triggeredEventModifier is missing a name!\n");
            }
        }

        if (nodeName == "preventFleet")
        {
            isDefault = false;
            customEvent->preventFleet = true;
        }

        if (nodeName == "preventBossFleet")
        {
            isDefault = false;
            customEvent->preventBossFleet = 1;
            if (child->first_attribute("forever") && EventsParser::ParseBoolean(child->first_attribute("forever")->value()))
            {
                customEvent->preventBossFleet = 2;
            }
        }

        if (nodeName == "runFromFleet")
        {
            isDefault = false;
            customEvent->runFromFleet = 2;
            if (child->first_attribute("closest") && EventsParser::ParseBoolean(child->first_attribute("closest")->value()))
            {
                customEvent->runFromFleet = 1;
            }
        }

        if (nodeName == "secretSectorWarp" || nodeName == "secretSector")
        {
            std::string sec = child->value();
            if (!sec.empty())
            {
                isDefault = false;
                customEvent->secretSectorWarp = sec;
            }
        }

        if (nodeName == "loadEvent")
        {
            isDefault = false;
            customEvent->eventLoad = child->value();

            if (child->first_attribute("seeded"))
            {
                customEvent->eventLoadSeeded = EventsParser::ParseBoolean(child->first_attribute("seeded")->value());
            }
            if (child->first_attribute("ignoreUnique"))
            {
                customEvent->eventLoadIgnoreUnique = EventsParser::ParseBoolean(child->first_attribute("ignoreUnique")->value());
            }
        }

        if (nodeName == "revisitEvent")
        {
            isDefault = false;
            customEvent->eventRevisit = child->value();

            if (child->first_attribute("seeded"))
            {
                customEvent->eventRevisitSeeded = EventsParser::ParseBoolean(child->first_attribute("seeded")->value());
            }
            if (child->first_attribute("ignoreUnique"))
            {
                customEvent->eventRevisitIgnoreUnique = EventsParser::ParseBoolean(child->first_attribute("ignoreUnique")->value());
            }
        }

        if (nodeName == "loadEventList")
        {
            isDefault = false;
            customEvent->eventLoadList = new EventLoadList();
            ParseCustomEventLoadList(child, customEvent->eventLoadList, customEvent->eventName);
        }

        if (nodeName == "eventAlias")
        {
            isDefault = false;
            std::pair<std::string, EventAlias> alias;
            if (child->first_attribute("name"))
            {
                alias.first = child->first_attribute("name")->value();
            }
            alias.second.event = child->value();
            if (child->first_attribute("jumpClear"))
            {
                alias.second.jumpClear = EventsParser::ParseBoolean(child->first_attribute("jumpClear")->value());
            }
            if (child->first_attribute("once"))
            {
                alias.second.once = EventsParser::ParseBoolean(child->first_attribute("once")->value());
            }
            customEvent->eventAlias.push_back(alias);
        }

        if (nodeName == "queueEvent")
        {
            isDefault = false;

            EventQueueEvent queueEvent = EventQueueEvent();

            queueEvent.event = child->value();
            queueEvent.label = queueEvent.event;

            if (child->first_attribute("name"))
            {
                queueEvent.label = child->first_attribute("name")->value();
            }
            if (child->first_attribute("seeded"))
            {
                queueEvent.seed = EventsParser::ParseBoolean(child->first_attribute("seeded")->value()) ? 0 : -1;
            }

            customEvent->queueEvents.push_back(queueEvent);
        }
        if (nodeName == "clearQueueEvent")
        {
            isDefault = false;

            if (child->first_attribute("name"))
            {
                customEvent->clearQueueEvents.push_back(child->first_attribute("name")->value());
            }
            else
            {
                customEvent->clearQueueEvents.push_back("");
            }
        }

        if (nodeName == "restartEvent")
        {
            isDefault = false;
            customEvent->restartEvent = true;
        }

        if (nodeName == "renameBeacon")
        {
            isDefault = false;
            customEvent->renameBeacon = child->value();
        }

        if (nodeName == "jumpEvent")
        {
            isDefault = false;

            JumpEvent jumpEvent;
            jumpEvent.event = child->value();
            jumpEvent.label = jumpEvent.event;

            if (child->first_attribute("name"))
            {
                jumpEvent.label = child->first_attribute("name")->value();
            }
            if (child->first_attribute("loop"))
            {
                jumpEvent.loop = EventsParser::ParseBoolean(child->first_attribute("loop")->value());
            }
            if (child->first_attribute("priority"))
            {
                jumpEvent.priority = boost::lexical_cast<int>(child->first_attribute("priority")->value());
            }

            customEvent->jumpEvents.push_back(jumpEvent);
        }

        if (nodeName == "clearJumpEvent")
        {
            isDefault = false;

            if (child->first_attribute("name"))
            {
                customEvent->clearJumpEvents.push_back(child->first_attribute("name")->value());
            }
            else
            {
                customEvent->clearJumpEvents.push_back("");
            }
        }

        if (nodeName == "deathEvent")
        {
            isDefault = false;

            DeathEvent deathEvent;
            deathEvent.event = child->value();
            deathEvent.label = deathEvent.event;

            if (child->first_attribute("name"))
            {
                deathEvent.label = child->first_attribute("name")->value();
            }
            if (child->first_attribute("thisFight"))
            {
                deathEvent.thisFight = EventsParser::ParseBoolean(child->first_attribute("thisFight")->value());
                deathEvent.jumpClear = deathEvent.thisFight;
            }
            if (child->first_attribute("jumpClear"))
            {
                deathEvent.jumpClear = EventsParser::ParseBoolean(child->first_attribute("jumpClear")->value());
            }
            if (child->first_attribute("priority"))
            {
                deathEvent.priority = boost::lexical_cast<int>(child->first_attribute("priority")->value());
            }

            customEvent->deathEvents.push_back(deathEvent);
        }

        if (nodeName == "clearDeathEvent")
        {
            isDefault = false;

            if (child->first_attribute("name"))
            {
                customEvent->clearDeathEvents.push_back(child->first_attribute("name")->value());
            }
            else
            {
                customEvent->clearDeathEvents.push_back("");
            }
        }

        if (nodeName == "replaceSector")
        {
            isDefault = false;
            if (child->first_attribute("name"))
            {
                customEvent->replaceSector.targetSector = child->first_attribute("name")->value();
            }
            customEvent->replaceSector.sectorList = child->value();
        }

        if (nodeName == "recallBoarders")
        {
            isDefault = false;
            customEvent->recallBoarders = true;

            if (child->first_attribute("ship"))
            {
                auto stringValue = child->first_attribute("ship")->value();

                if (strcmp(stringValue, "enemy") == 0) {
                    customEvent->recallBoardersShip = 1;
                }
                else if (strcmp(stringValue, "player") == 0) {
                    customEvent->recallBoardersShip = -1;
                }
            }
            if (child->first_attribute("force"))
            {
                customEvent->recallBoardersForce = EventsParser::ParseBoolean(child->first_attribute("force")->value());
            }
        }

        if (nodeName == "resetFtl")
        {
            isDefault = false;
            customEvent->resetFtl = true;
        }

        if (nodeName == "instantEscape")
        {
            isDefault = false;
            customEvent->instantEscape = true;
        }

        if (nodeName == "escape")
        {
            isDefault = false;
            customEvent->escape = true;
        }

        if (nodeName == "surrender")
        {
            isDefault = false;
            customEvent->surrender = true;
        }

        if (nodeName == "loadEscape")
        {
            isDefault = false;
            customEvent->loadEscape = true;
            if (child->first_attribute("force"))
            {
                customEvent->loadEscapeForced = EventsParser::ParseBoolean(child->first_attribute("force")->value());
            }
        }

        if (nodeName == "loadSurrender")
        {
            isDefault = false;
            customEvent->loadSurrender = true;
            if (child->first_attribute("force"))
            {
                customEvent->loadSurrenderForced = EventsParser::ParseBoolean(child->first_attribute("force")->value());
            }
        }

        if (nodeName == "disableEscape")
        {
            isDefault = false;
            customEvent->disableEscape = true;
            if (child->first_attribute("force"))
            {
                customEvent->disableEscapeForced = EventsParser::ParseBoolean(child->first_attribute("force")->value());
            }
        }

        if (nodeName == "disableSurrender")
        {
            isDefault = false;
            customEvent->disableSurrender = true;
            if (child->first_attribute("force"))
            {
                customEvent->disableSurrenderForced = EventsParser::ParseBoolean(child->first_attribute("force")->value());
            }
        }

        if (nodeName == "goToFlagship")
        {
            isDefault = false;
            customEvent->goToFlagship = true;
            if (child->first_attribute("atBase"))
            {
                customEvent->goToFlagshipBase = EventsParser::ParseBoolean(child->first_attribute("atBase")->value());
            }
            if (child->first_attribute("allFleet"))
            {
                customEvent->goToFlagshipFleet = EventsParser::ParseBoolean(child->first_attribute("allFleet")->value());
            }
        }

        if (nodeName == "allowNoSlot")
        {
            isDefault = false;
            customEvent->allowNoSlot = true;
        }

        if (nodeName == "blockNoSlot")
        {
            isDefault = false;
            customEvent->blockNoSlot = true;
        }

        if (nodeName == "choiceRequiresCrew")
        {
            isDefault = false;
            customEvent->choiceRequiresCrew = true;
        }

        if (nodeName == "ignoreEssential")
        {
            isDefault = false;
            customEvent->ignoreEssential.first = 0.f;
            customEvent->ignoreEssential.second = 0.f;
            if (child->first_attribute("min"))
            {
                customEvent->ignoreEssential.first = boost::lexical_cast<float>(child->first_attribute("min")->value());
            }
            if (child->first_attribute("max"))
            {
                customEvent->ignoreEssential.second = boost::lexical_cast<float>(child->first_attribute("max")->value());
            }
        }

        if (nodeName == "transformRace")
        {
            isDefault = false;
            customEvent->transformRace.second = child->value();

            if (child->first_attribute("class"))
            {
                customEvent->transformRace.first = child->first_attribute("class")->value();
            }
        }

        if (nodeName == "beaconType")
        {
            isDefault = false;

            if (child->first_attribute("load"))
            {
                customEvent->loadBeacon = child->first_attribute("load")->value();
            }
            else
            {
                BeaconType* beaconType = new BeaconType();
                beaconType->eventName = customEvent->eventName;

                ParseCustomBeaconType(child, beaconType);

                customEvent->beacon = beaconType;
            }
        }
        if (nodeName == "removeHazards")
        {
            isDefault = false;
            customEvent->removeHazards = true;
        }
        if (nodeName == "removeNebula")
        {
            isDefault = false;
            customEvent->removeNebula = true;
        }
        if (nodeName == "hiddenAug")
        {
            isDefault = false;
            customEvent->hiddenAugs.push_back(child->value());
        }
        if (nodeName == "win")
        {
            isDefault = false;
            customEvent->gameOver.enabled = true;
            customEvent->gameOver.victory = true;
            customEvent->gameOver.sound = "victory";
            if (child->first_attribute("text"))
            {
                std::string textValue = child->first_attribute("text")->value();
                std::string parsedText = G_->GetTextLibrary()->GetText(textValue, G_->GetTextLibrary()->currentLanguage);
                if (parsedText.find("Could not find:") != std::string::npos)
                {
                    customEvent->gameOver.text = textValue;
                }
                else
                {
                    customEvent->gameOver.text = parsedText;
                }
            }
            if (child->first_attribute("creditsText"))
            {
                customEvent->gameOver.creditsText = child->first_attribute("creditsText")->value();
            }
            if (child->first_attribute("creditsBackground"))
            {
                customEvent->gameOver.creditsBackground = child->first_attribute("creditsBackground")->value();
            }
            if (child->first_attribute("music"))
            {
                customEvent->gameOver.creditsMusic = child->first_attribute("music")->value();
            }
            if (child->first_attribute("sound"))
            {
                customEvent->gameOver.sound = child->first_attribute("sound")->value();
            }
            if (child->first_attribute("ach"))
            {
                customEvent->gameOver.ach = child->first_attribute("ach")->value();
            }
        }
        if (nodeName == "lose")
        {
            isDefault = false;
            customEvent->gameOver.enabled = true;
            if (child->first_attribute("text"))
            {
                std::string textValue = child->first_attribute("text")->value();
                std::string parsedText = G_->GetTextLibrary()->GetText(textValue, G_->GetTextLibrary()->currentLanguage);
                if (parsedText.find("Could not find:") != std::string::npos)
                {
                    customEvent->gameOver.text = textValue;
                }
                else
                {
                    customEvent->gameOver.text = parsedText;
                }
            }
            if (child->first_attribute("sound"))
            {
                customEvent->gameOver.sound = child->first_attribute("sound")->value();
            }
        }
        if (nodeName == "achievement")
        {
            isDefault = false;
            customEvent->achievement = child->value();

            if (child->first_attribute("silent"))
            {
                customEvent->achievementSilent = EventsParser::ParseBoolean(child->first_attribute("silent")->value());
            }
        }
        if (nodeName == "playSound")
        {
            isDefault = false;
            customEvent->playSound = child->value();
        }
        if (nodeName == "playMusic")
        {
            isDefault = false;
            std::string track = child->value();
            if (track.empty())
            {
                customEvent->resetMusic = true;
            }
            else
            {
                customEvent->playMusic = child->value();
            }
        }
        if (nodeName == "changeBackground")
        {
            isDefault = false;
            customEvent->changeBackground = child->value();
        }
        if (nodeName == "backgroundObject")
        {
            isDefault = false;
            customEvent->backgroundObjects.push_back(CustomBackgroundObjectManager::instance->ParseCustomBackgroundObject(child));
        }
        if (nodeName == "clearBackgroundObject")
        {
            isDefault = false;
            if (child->first_attribute("name"))
            {
                customEvent->clearBackgroundObjects.push_back(child->first_attribute("name")->value());
            }
            else
            {
                customEvent->clearBackgroundObjects.push_back("");
            }
        }
        if (nodeName == "transformBackgroundObject")
        {
            isDefault = false;
            customEvent->transformBackgroundObjects.push_back(std::make_pair<std::string,std::string>(child->first_attribute("name")->value(), child->value()));
        }
        if (nodeName == "eventButton")
        {
            isDefault = false;
            customEvent->eventButtons.push_back(EventButtonManager::instance->ParseEventButton(child));
        }
        if (nodeName == "clearEventButton")
        {
            isDefault = false;
            if (child->first_attribute("name"))
            {
                customEvent->clearEventButtons.push_back(child->first_attribute("name")->value());
            }
            else
            {
                customEvent->clearEventButtons.push_back("");
            }
        }
        if (nodeName == "unlockCustomShip" || (!parsingVanilla && nodeName == "unlockShip"))
        {
            std::string shipName = child->value();
            if (!shipName.empty())
            {
                isDefault = false;
                customEvent->unlockShip = shipName;

                if (child->first_attribute("silent"))
                {
                    customEvent->unlockShipSilent = EventsParser::ParseBoolean(child->first_attribute("silent")->value());
                }

                if (child->first_attribute("shipReq"))
                {
                    customEvent->unlockShipReq = child->first_attribute("shipReq")->value();
                }
            }
        }
        if (nodeName == "disableScrapScore")
        {
            isDefault = false;
            customEvent->disableScrapScore = true;
        }
        if (nodeName == "disableScrapAugments")
        {
            isDefault = false;
            customEvent->disableScrapAugments = true;
        }
        if (nodeName == "removeItem")
        {
            isDefault = false;
            customEvent->removeItems.push_back(child->value());
        }
        if (nodeName == "variable" || nodeName == "metaVariable" || nodeName == "tempVariable")
        {
            isDefault = false;
            VariableModifier variable;
            variable.ParseVariableModifierNode(child);
            customEvent->variables.push_back(variable);
        }
        if (nodeName == "customStore" || nodeName == "store")
        {
            std::string storeName = child->value();
            if (!storeName.empty())
            {
                isDefault = false;
                customEvent->customStore = storeName;
            }
        }
        if (nodeName == "removeStore")
        {
            isDefault = false;
            customEvent->removeStore = true;
        }
        if (nodeName == "customFleet")
        {
            isDefault = false;
            bool right = false;
            bool firing = false;
            bool autoDarkening = false;

            if (child->first_attribute("right"))
            {
                right = EventsParser::ParseBoolean(child->first_attribute("right")->value());
            }
            if (child->first_attribute("firing"))
            {
                firing = EventsParser::ParseBoolean(child->first_attribute("firing")->value());
            }
            if (child->first_attribute("autoDarkening"))
            {
                autoDarkening = EventsParser::ParseBoolean(child->first_attribute("autoDarkening")->value());
            }

            if (!right)
            {
                customEvent->leftFleet.fleetDefName = child->value();
                customEvent->leftFleet.firing = firing;
                customEvent->leftFleet.autoDarkening = autoDarkening;
            }
            else
            {
                customEvent->rightFleet.fleetDefName = child->value();
                customEvent->rightFleet.firing = firing;
                customEvent->rightFleet.autoDarkening = autoDarkening;
            }
        }
        if (nodeName == "clearCustomFleet")
        {
            isDefault = false;
            customEvent->clearCustomFleet = true;
        }
        if (nodeName == "enemyDamage")
        {
            isDefault = false;
            EventDamage eventDamage{-1,0,0};
            if (child->first_attribute("amount"))
            {
                eventDamage.amount = boost::lexical_cast<int>(child->first_attribute("amount")->value());
            }
            if (child->first_attribute("system"))
            {
                eventDamage.system = ShipSystem::NameToSystemId(child->first_attribute("system")->value());
            }
            if (child->first_attribute("effect"))
            {
                std::string damageEffect = child->first_attribute("effect")->value();
                if (damageEffect == "fire")
                {
                    eventDamage.effect = 1;
                }
                if (damageEffect == "breach")
                {
                    eventDamage.effect = 2;
                }
                if (damageEffect == "all")
                {
                    eventDamage.effect = 3;
                }
                if (damageEffect == "random")
                {
                    eventDamage.effect = 4;
                }
            }
            if (child->first_attribute("force") && EventsParser::ParseBoolean(child->first_attribute("force")->value()))
            {
                eventDamage.effect |= 8;
            }
            if (child->first_attribute("damageHull") && !EventsParser::ParseBoolean(child->first_attribute("damageHull")->value()))
            {
                eventDamage.effect |= 16;
            }
            customEvent->enemyDamage.push_back(eventDamage);
        }
        if (nodeName == "repairAllSystems")
        {
            isDefault = false;
            customEvent->repairAllSystems = true;
        }
        if (nodeName == "killEnemyBoarders")
        {
            isDefault = false;
            customEvent->killEnemyBoarders = true;
        }
        if (nodeName == "superDrones")
        {
            isDefault = false;
            if (child->first_attribute("player"))
            {
                customEvent->superDrones = EventsParser::ParseBoolean(child->first_attribute("player")->value()) ? 0 : 1;
            }
            else
            {
                customEvent->superDrones = 1;
            }
            if (child->first_attribute("name"))
            {
                customEvent->superDronesName = child->first_attribute("name")->value();
            }
        }
        if (nodeName == "clearSuperDrones")
        {
            isDefault = false;
            if (child->first_attribute("player"))
            {
                customEvent->clearSuperDrones = EventsParser::ParseBoolean(child->first_attribute("player")->value()) ? 0 : 1;
            }
            else
            {
                customEvent->clearSuperDrones = 1;
            }
        }
        if (nodeName == "superBarrage")
        {
            isDefault = false;
            if (child->first_attribute("player"))
            {
                customEvent->superBarrage = EventsParser::ParseBoolean(child->first_attribute("player")->value()) ? 0 : 1;
            }
            else
            {
                customEvent->superBarrage = 1;
            }
            if (child->first_attribute("name"))
            {
                customEvent->superBarrageName = child->first_attribute("name")->value();
            }
        }
        if (nodeName == "superShields")
        {
            isDefault = false;
            if (child->first_attribute("player"))
            {
                customEvent->powerSuperShields = EventsParser::ParseBoolean(child->first_attribute("player")->value()) ? 0 : 1;
            }
            else
            {
                customEvent->powerSuperShields = 1;
            }
            if (child->first_attribute("amount"))
            {
                customEvent->powerSuperShieldsSet = boost::lexical_cast<int>(child->first_attribute("amount")->value());
            }
            if (child->first_attribute("add"))
            {
                customEvent->powerSuperShieldsAdd = boost::lexical_cast<int>(child->first_attribute("add")->value());
            }
        }
        if (nodeName == "noASBPlanet")
        {
            isDefault = false;
            customEvent->noASBPlanet = true;
        }
    }

    return isDefault;
}

bool CustomEventsParser::ParseCustomShipEvent(rapidxml::xml_node<char> *node, CustomShipEvent *customEvent)
{
    bool isDefault = true;

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string nodeName(child->name());

        if (nodeName == "triggeredEvent")
        {
            isDefault = false;

            TriggeredEventDefinition def;

            ParseCustomTriggeredEventNode(child, &def);

            customEvent->triggeredEvents.push_back(TriggeredEventDefinition::PushDef(def));
        }

        if (nodeName == "clearTriggeredEvent")
        {
            isDefault = false;
            customEvent->clearTriggeredEvents.push_back(child->first_attribute("name")->value());
        }

        if (nodeName == "triggeredEventModifier")
        {
            isDefault = false;
            TriggeredEventModifier def;
            if (child->first_attribute("name"))
            {
                def.name = child->first_attribute("name")->value();
            }
            if (child->first_attribute("time"))
            {
                def.minTime = boost::lexical_cast<float>(child->first_attribute("time")->value());
                def.maxTime = boost::lexical_cast<float>(child->first_attribute("time")->value());
            }
            if (child->first_attribute("minTime"))
            {
                def.minTime = boost::lexical_cast<float>(child->first_attribute("minTime")->value());
            }
            if (child->first_attribute("maxTime"))
            {
                def.maxTime = boost::lexical_cast<float>(child->first_attribute("maxTime")->value());
            }
            if (child->first_attribute("jumps"))
            {
                def.minJumps = boost::lexical_cast<int>(child->first_attribute("jumps")->value());
                def.maxJumps = boost::lexical_cast<int>(child->first_attribute("jumps")->value());
            }
            if (child->first_attribute("minJumps"))
            {
                def.minJumps = boost::lexical_cast<int>(child->first_attribute("minJumps")->value());
            }
            if (child->first_attribute("maxJumps"))
            {
                def.maxJumps = boost::lexical_cast<int>(child->first_attribute("maxJumps")->value());
            }
            customEvent->triggeredEventModifiers.push_back(def);
        }

        if (nodeName == "jumpEvent")
        {
            isDefault = false;

            JumpEvent jumpEvent;
            jumpEvent.event = child->value();
            jumpEvent.label = jumpEvent.event;

            if (child->first_attribute("name"))
            {
                jumpEvent.label = child->first_attribute("name")->value();
            }
            if (child->first_attribute("loop"))
            {
                jumpEvent.loop = EventsParser::ParseBoolean(child->first_attribute("loop")->value());
            }
            if (child->first_attribute("priority"))
            {
                jumpEvent.priority = boost::lexical_cast<int>(child->first_attribute("priority")->value());
            }

            customEvent->jumpEvents.push_back(jumpEvent);
        }

        if (nodeName == "clearJumpEvent")
        {
            isDefault = false;

            if (child->first_attribute("name"))
            {
                customEvent->clearJumpEvents.push_back(child->first_attribute("name")->value());
            }
            else
            {
                customEvent->clearJumpEvents.push_back("");
            }
        }

        if (nodeName == "deathEvent")
        {
            isDefault = false;

            DeathEvent deathEvent;
            deathEvent.event = child->value();
            deathEvent.label = deathEvent.event;

            if (child->first_attribute("name"))
            {
                deathEvent.label = child->first_attribute("name")->value();
            }
            if (child->first_attribute("thisFight"))
            {
                deathEvent.thisFight = EventsParser::ParseBoolean(child->first_attribute("thisFight")->value());
                deathEvent.jumpClear = deathEvent.thisFight;
            }
            if (child->first_attribute("jumpClear"))
            {
                deathEvent.jumpClear = EventsParser::ParseBoolean(child->first_attribute("jumpClear")->value());
            }
            if (child->first_attribute("priority"))
            {
                deathEvent.priority = boost::lexical_cast<int>(child->first_attribute("priority")->value());
            }

            customEvent->deathEvents.push_back(deathEvent);
        }

        if (nodeName == "clearDeathEvent")
        {
            isDefault = false;

            if (child->first_attribute("name"))
            {
                customEvent->clearDeathEvents.push_back(child->first_attribute("name")->value());
            }
            else
            {
                customEvent->clearDeathEvents.push_back("");
            }
        }

        if (nodeName == "invincible")
        {
            isDefault = false;
            customEvent->invincible = true;
        }

        if (nodeName == "deadCrewAuto")
        {
            isDefault = false;
            customEvent->deadCrewAuto = true;
        }
        if (nodeName == "finalBoss" || nodeName == "miniBoss")
        {
            isDefault = false;
            customEvent->finalBoss.enabled = true;
            customEvent->finalBoss.victory = (nodeName == "finalBoss");
            customEvent->finalBoss.sound = "victory";
            if (child->first_attribute("text"))
            {
                std::string textValue = child->first_attribute("text")->value();
                std::string parsedText = G_->GetTextLibrary()->GetText(textValue, G_->GetTextLibrary()->currentLanguage);
                if (parsedText.find("Could not find:") != std::string::npos)
                {
                    customEvent->finalBoss.text = textValue;
                }
                else
                {
                    customEvent->finalBoss.text = parsedText;
                }
            }
            if (child->first_attribute("creditsText"))
            {
                customEvent->finalBoss.creditsText = child->first_attribute("creditsText")->value();
            }
            if (child->first_attribute("creditsBackground"))
            {
                customEvent->finalBoss.creditsBackground = child->first_attribute("creditsBackground")->value();
            }
            if (child->first_attribute("music"))
            {
                customEvent->finalBoss.creditsMusic = child->first_attribute("music")->value();
            }
            if (child->first_attribute("sound"))
            {
                customEvent->finalBoss.sound = child->first_attribute("sound")->value();
            }
            if (child->first_attribute("musicDelay"))
            {
                customEvent->bossMusicDelay = boost::lexical_cast<int>(child->first_attribute("musicDelay")->value());
            }
        }
    }

    return isDefault;
}

bool CustomEventsParser::ParseCustomQuestNode(rapidxml::xml_node<char> *node, CustomQuest *quest)
{
    bool isDefault = true;

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string nodeName(child->name());
        if (nodeName == "nonNebulaBeacon")
        {
            isDefault = false;
            quest->nonNebulaBeacon = EventsParser::ParseBoolean(child->value());
        }

        if (nodeName == "nebulaBeacon")
        {
            isDefault = false;
            quest->nebulaBeacon = EventsParser::ParseBoolean(child->value());
        }

        if (nodeName == "createNebula")
        {
            isDefault = false;
            quest->createNebula = EventsParser::ParseBoolean(child->value());
        }

        if (nodeName == "nebulaEvent")
        {
            isDefault = false;
            quest->nebulaEvent = child->value();
        }

        if (nodeName == "currentSector")
        {
            isDefault = false;
            quest->currentSector = EventsParser::ParseBoolean(child->value());
        }

        if (nodeName == "nextSector")
        {
            isDefault = false;
            quest->nextSector = EventsParser::ParseBoolean(child->value());
        }

        if (nodeName == "aggressive")
        {
            isDefault = false;
            quest->aggressive = boost::lexical_cast<int>(child->value());
        }

        if (nodeName == "sectorEight")
        {
            isDefault = false;
            quest->sectorEight = EventsParser::ParseBoolean(child->value());
        }

        if (nodeName == "lastStand")
        {
            isDefault = false;
            quest->lastStand = EventsParser::ParseBoolean(child->value());
        }
    }
    return isDefault;
}

void CustomEventsParser::ParseCustomBeaconType(rapidxml::xml_node<char> *node, BeaconType *beaconType)
{
    beaconType->hideVanillaLabel = CustomOptionsManager::GetInstance()->defaults.beaconType_hideVanillaLabel;

    if (node->first_attribute("id"))
    {
        beaconType->beaconText.data = node->first_attribute("id")->value();
        beaconType->beaconText.isLiteral = false;
    }
    else if (node->first_attribute("text"))
    {
        beaconType->beaconText.data = node->first_attribute("text")->value();
        beaconType->beaconText.isLiteral = true;
    }
    if (node->first_attribute("req"))
    {
        beaconType->equipmentReq = node->first_attribute("req")->value();
    }

    if (node->first_attribute("global"))
    {
        beaconType->global = EventsParser::ParseBoolean(node->first_attribute("global")->value());
    }

    if (node->first_attribute("persist"))
    {
        beaconType->persistent = EventsParser::ParseBoolean(node->first_attribute("persist")->value());
    }

    if (node->first_attribute("hideVanillaLabel"))
    {
        beaconType->hideVanillaLabel = EventsParser::ParseBoolean(node->first_attribute("hideVanillaLabel")->value());
    }

    GL_Color color = GL_Color(255.f, 255.f, 255.f, 1.f);

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        if (strcmp(child->name(), "unvisitedTooltip") == 0)
        {
            if (child->first_attribute("id"))
            {
                beaconType->unvisitedTooltip.data = child->first_attribute("id")->value();
                beaconType->unvisitedTooltip.isLiteral = false;
            }
            else
            {
                beaconType->unvisitedTooltip.data = child->value();
                beaconType->unvisitedTooltip.isLiteral = true;
            }
        }

        if (strcmp(child->name(), "visitedTooltip") == 0)
        {
            if (child->first_attribute("id"))
            {
                beaconType->visitedTooltip.data = child->first_attribute("id")->value();
                beaconType->visitedTooltip.isLiteral = false;
            }
            else
            {
                beaconType->visitedTooltip.data = child->value();
                beaconType->visitedTooltip.isLiteral = true;
            }
        }

        if (strcmp(child->name(), "undiscoveredTooltip") == 0)
        {
            if (child->first_attribute("id"))
            {
                beaconType->undiscoveredTooltip.data = child->first_attribute("id")->value();
                beaconType->undiscoveredTooltip.isLiteral = false;
            }
            else
            {
                beaconType->undiscoveredTooltip.data = child->value();
                beaconType->undiscoveredTooltip.isLiteral = true;
            }
        }

        if (strcmp(child->name(), "color") == 0)
        {
            ParseColorNode(color, child);
        }
    }

    beaconType->color = color;
}

void CustomEventsParser::ParseCustomReqNode(rapidxml::xml_node<char> *node, CustomReq *req)
{
    if (node->first_attribute("name"))
    {
        req->name = node->first_attribute("name")->value();
    }
    if (node->first_attribute("type"))
    {
        std::string reqtype = node->first_attribute("type")->value();
        boost::algorithm::to_lower(reqtype);
        if (reqtype == "any" || reqtype=="max")
        {
            req->type = CustomReq::TYPE_ANY;
        }
        else if (reqtype == "all" || reqtype=="min")
        {
            req->type = CustomReq::TYPE_ALL;
        }
        else if (reqtype == "sum" || reqtype=="count")
        {
            req->type = CustomReq::TYPE_SUM;
        }
        else
        {
            ErrorMessage("Invalid Custom Req Type found: "+reqtype+"\n");
        }
    }
    if (node->first_attribute("lvl"))
    {
        req->lvl = boost::lexical_cast<int>(node->first_attribute("lvl")->value());
    }
    if (node->first_attribute("max_lvl"))
    {
        req->max_lvl = boost::lexical_cast<int>(node->first_attribute("max_lvl")->value());
    }
    if (node->first_attribute("mult"))
    {
        req->mult = boost::lexical_cast<int>(node->first_attribute("mult")->value());
    }
    if (node->first_attribute("const"))
    {
        req->constant = boost::lexical_cast<int>(node->first_attribute("const")->value());
    }
    if (node->first_attribute("load"))
    {
        req->blueprints = G_->GetBlueprints()->GetBlueprintList(node->first_attribute("load")->value());
    }
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string nodeName(child->name());
        if (nodeName == "name")
        {
            req->blueprints.push_back(child->value());
        }
        if (nodeName == "req")
        {
            req->children.emplace_back();
            ParseCustomReqNode(child, &(req->children.back()));
        }
    }
}

void CustomEventsParser::ParseCustomEventLoadList(rapidxml::xml_node<char> *node, EventLoadList *eventList, std::string& eventName)
{
    if (node->first_attribute("seeded"))
    {
        eventList->seeded = EventsParser::ParseBoolean(node->first_attribute("seeded")->value());
    }
    if (node->first_attribute("first"))
    {
        eventList->useFirst = EventsParser::ParseBoolean(node->first_attribute("first")->value());
    }
    if (node->first_attribute("default"))
    {
        eventList->defaultEvent = node->first_attribute("default")->value();
    }
    if (node->first_attribute("generate"))
    {
        eventList->onGenerate = EventsParser::ParseBoolean(node->first_attribute("generate")->value());
    }
    if (node->first_attribute("ignoreUnique"))
    {
        eventList->ignoreUnique = EventsParser::ParseBoolean(node->first_attribute("ignoreUnique")->value());
    }
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string nodeName(child->name());
        if (nodeName == "event")
        {
            EventLoadListEvent event;

            if (child->first_attribute("name"))
            {
                event.event = child->first_attribute("name")->value();
            }
            if (child->first_attribute("load"))
            {
                event.event = child->first_attribute("load")->value();
            }
            if (child->first_attribute("req"))
            {
                event.req = child->first_attribute("req")->value();
            }
            if (child->first_attribute("max_lvl"))
            {
                event.max_lvl = boost::lexical_cast<int>(child->first_attribute("max_lvl")->value());
                event.lvl = -2147483648;
            }
            if (child->first_attribute("lvl"))
            {
                event.lvl = boost::lexical_cast<int>(child->first_attribute("lvl")->value());
            }
            if (child->first_attribute("max_group"))
            {
                event.max_group = boost::lexical_cast<int>(child->first_attribute("max_group")->value());
            }

            if (event.event.empty())
            {
                std::string newEventName = G_->GetEventsParser()->ProcessEvent(child, eventName);
                event.event = newEventName;
            }

            eventList->events.push_back(event);
        }
    }
}

void VariableModifier::ParseVariableModifierNode(rapidxml::xml_node<char> *node)
{
    if (strcmp(node->name(), "variable") == 0)
    {
        vType = VarType::VAR;
    }
    else if (strcmp(node->name(), "metaVariable") == 0)
    {
        vType = VarType::METAVAR;
    }
    else if (strcmp(node->name(), "tempVariable") == 0)
    {
        vType = VarType::TEMP;
    }

    name = node->first_attribute("name")->value();
    if (node->first_attribute("op"))
    {
        std::string opName = std::string(node->first_attribute("op")->value());
        opName = opName.substr(0,3);
        if (opName == "set")
        {
            op = VariableModifier::OP::SET;
        }
        else if (opName == "add")
        {
            op = VariableModifier::OP::ADD;
        }
        else if (opName == "mul")
        {
            op = VariableModifier::OP::MUL;
        }
        else if (opName == "div")
        {
            op = VariableModifier::OP::DIV;
        }
        else if (opName == "min")
        {
            op = VariableModifier::OP::MIN;
        }
        else if (opName == "max")
        {
            op = VariableModifier::OP::MAX;
        }
    }
    if (node->first_attribute("var"))
    {
        var = node->first_attribute("var")->value();
        minVal = 1;
        maxVal = 1;
    }
    if (node->first_attribute("val"))
    {
        minVal = boost::lexical_cast<int>(node->first_attribute("val")->value());
        maxVal = minVal;
    }
    if (node->first_attribute("value"))
    {
        minVal = boost::lexical_cast<int>(node->first_attribute("value")->value());
        maxVal = minVal;
    }
    if (node->first_attribute("amount"))
    {
        minVal = boost::lexical_cast<int>(node->first_attribute("amount")->value());
        maxVal = minVal;
    }
    if (node->first_attribute("min"))
    {
        minVal = boost::lexical_cast<int>(node->first_attribute("min")->value());
    }
    if (node->first_attribute("max"))
    {
        maxVal = boost::lexical_cast<int>(node->first_attribute("max")->value());
    }

    // Force attribute bypasses anything that might block the variable modifier from being applied
    if (node->first_attribute("force"))
    {
        force = EventsParser::ParseBoolean(node->first_attribute("force")->value());
    }
}

CustomEvent *CustomEventsParser::GetCustomEvent(const std::string& event)
{
    auto it = customEvents.find(event);
    if (it != customEvents.end())
    {
        return it->second;
    }

    std::string baseEvent = CustomEventsParser::GetBaseEventName(event);

    it = customRecursiveEvents.find(baseEvent);
    if (it != customRecursiveEvents.end())
    {
        return it->second;
    }

    return nullptr;
}

CustomEvent *CustomEventsParser::GetCustomEvent(Location *loc)
{
    if (loc)
    {
        if (loc->boss)
        {
            BossShip *boss = G_->GetWorld()->bossShip;

            std::stringstream s;
            s << "BOSS_TEXT_" << boss->nextStage;

            return GetCustomEvent(s.str());
        }
        else
        {
            return GetCustomEvent(loc->event->eventName);
        }
    }
    return nullptr;
}

CustomShipEvent *CustomEventsParser::GetCustomShipEvent(const std::string& event)
{
    auto it = customShipEvents.find(event);

    if (it != customShipEvents.end())
    {
        CustomShipEvent* customEvent = customShipEvents[event];
        return customEvent;
    }

    return nullptr;
}

CustomQuest *CustomEventsParser::GetCustomQuest(const std::string& event)
{
    auto it = customQuests.find(event);
    if (it != customQuests.end()) return it->second;
    return nullptr;
}

CustomSector *CustomEventsParser::GetCustomSector(const std::string& sectorName)
{
    auto it = customSectors.find(sectorName);

    if (it != customSectors.end())
    {
        return it->second;
    }

    return nullptr;
}

CustomSector *CustomEventsParser::GetCustomSectorPreload(const std::string& sectorName)
{
    auto it = customSectorsPreload.find(sectorName);

    if (it != customSectorsPreload.end())
    {
        return it->second;
    }

    return nullptr;
}

CustomSector *CustomEventsParser::GetCurrentCustomSector(StarMap *starMap)
{
    std::string sectorName;

    if (!starMap->forceSectorChoice.empty())
    {
        sectorName = starMap->forceSectorChoice;
    }
    else if (starMap->currentSector)
    {
        sectorName = starMap->currentSector->description.type;
        if (sectorName == "CIVILIAN_SECTOR" && starMap->currentSector->level == 0)
        {
            sectorName = "STANDARD_SPACE";
        }
    }
    else
    {
        return nullptr;
    }

    return GetCustomSector(sectorName);
}

CustomReq *CustomEventsParser::GetCustomReq(const std::string& blueprint)
{
    auto it = customReqs.find(blueprint);

    if (it != customReqs.end())
    {
        return it->second;
    }

    return nullptr;
}

void CustomEventsParser::ParseVanillaBaseNode(rapidxml::xml_node<char> *node)
{
    if (strcmp(node->name(), "sectorDescription") == 0)
    {
        if (node->first_attribute("name"))
        {
            std::string sectorName = node->first_attribute("name")->value();

            CustomSector *sec = GetCustomSector(sectorName);
            CustomSector *secPreload = GetCustomSectorPreload(sectorName);

            if (sec == nullptr)
            {
                sec = new CustomSector;
            }
            if (secPreload == nullptr)
            {
                *sec = CustomSector();
            }
            else
            {
                *sec = *secPreload;
            }

            sec->sectorName = sectorName;

            ParseCustomSector(node, sec, true);

            customSectors[sectorName] = sec;
        }
    }
    else if (strcmp(node->name(), "sectorMap") == 0)
    {
        auto customSectorParser = CustomSectorManager::GetInstance();
        customSectorParser->ParseCustomSectorMapNode(node);
    }
}

void CustomEventsParser::ParseVanillaEventNode(rapidxml::xml_node<char> *node, const std::string &eventName, const std::string &baseEventName)
{
    CustomEvent* customEvent;

    auto it = customEvents.find(eventName);
    if (it == customEvents.end())
    {
        customEvent = new CustomEvent();
        customEvent->eventName = eventName;
        customEvent->recursive = false;
        bool isDefault = ParseCustomEvent(node, customEvent, true);
        if (isDefault)
        {
            delete customEvent;
        }
        else
        {
            customEvents[eventName] = customEvent;
            vCustomEvents[baseEventName].push_back(customEvent);
        }
    }
    else
    {
        customEvent = it->second;
        *customEvent = CustomEvent(); // Reset the customEvent
        ParseCustomEvent(node, customEvent, true);
    }
}

void CustomEventsParser::ParseVanillaShipEventNode(rapidxml::xml_node<char> *node, const std::string &eventName)
{
    CustomShipEvent* customEvent;

    auto it = customShipEvents.find(eventName);
    if (it == customShipEvents.end())
    {
        customEvent = new CustomShipEvent();
        customEvent->eventName = eventName;
        bool isDefault = ParseCustomShipEvent(node, customEvent);
        if (isDefault)
        {
            delete customEvent;
        }
        else
        {
            customShipEvents[eventName] = customEvent;
        }
    }
    else
    {
        customEvent = it->second;
        *customEvent = CustomShipEvent(); // Reset the customEvent
        ParseCustomShipEvent(node, customEvent);
    }
}

HOOK_METHOD(EventsParser, ProcessBaseNode, (rapidxml::xml_node<char>* node, EventGenerator& generator) -> void)
{
    LOG_HOOK("HOOK_METHOD -> EventsParser::ProcessBaseNode -> Begin (CustomEvents.cpp)\n")
    super(node, generator);
    CustomEventsParser::GetInstance()->ParseVanillaBaseNode(node);
}

HOOK_METHOD(EventsParser, ProcessEvent, (rapidxml::xml_node<char> *node, const std::string &eventName) -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> EventsParser::ProcessEvent -> Begin (CustomEvents.cpp)\n")
    std::string strRef = super(node, eventName);
    if (!node->first_attribute("load"))
    {
        CustomEventsParser::GetInstance()->ParseVanillaEventNode(node, strRef, strRef.substr(0, strRef.find(" ")));
    }
    return strRef;
}

HOOK_METHOD(EventsParser, ProcessEventList, (rapidxml::xml_node<char> *node, const std::string &listName) -> std::vector<std::string>)
{
    LOG_HOOK("HOOK_METHOD -> EventsParser::ProcessEventList -> Begin (CustomEvents.cpp)\n")
    std::vector<std::string> vecRef = super(node, listName);
    CustomEventsParser::GetInstance()->ParseVanillaEventNode(node, listName, listName);
    return vecRef;
}

HOOK_METHOD(EventsParser, ProcessShipEvent, (rapidxml::xml_node<char> *node) -> ShipTemplate)
{
    LOG_HOOK("HOOK_METHOD -> EventsParser::ProcessShipEvent -> Begin (CustomEvents.cpp)\n")
    ShipTemplate shipEvent = super(node);
    if (node->first_attribute("name"))
    {
        CustomEventsParser::GetInstance()->ParseVanillaShipEventNode(node, shipEvent.shipEventName);
    }
    return shipEvent;
}

//=====================================================================================

static bool g_checkCargo = false;

void SetCheckCargo(CustomEvent *event)
{
    if (event)
    {
        g_checkCargo = event->checkCargo;
    }
    else
    {
        g_checkCargo = CustomOptionsManager::GetInstance()->defaults.checkCargo;
    }
}

void ShipObject::CheckCargo(const std::string& equipment, int &ret)
{
    std::vector<std::string> blueprintList = G_->GetBlueprints()->GetBlueprintList(equipment);

    if (ret != 0 && blueprintList.size() > 0) return; // list check; if already found then return

    Equipment equip = G_->GetWorld()->commandGui->equipScreen;
    auto boxes = equip.vEquipmentBoxes;

    for (auto const& box: boxes)
    {
        bool isCargo = box->IsCargoBox();

        if (isCargo)
        {
            Blueprint* cargoItem = box->GetBlueprint();
            if (cargoItem)
            {
                if (blueprintList.size() > 0)
                {
                    for (auto const& x: blueprintList)
                    {
                        if (cargoItem->name == x)
                        {
                            ret = 1;
                            return; // blueprintList check returns 1 if any item is found
                        }
                    }
                }
                else
                {
                    if (cargoItem->name == equipment)
                    {
                        ret++;
                    }
                }
            }
        }
    }
}

int ShipObject::HasCargo(const std::string& equip)
{
    int ret = 0;
    CheckCargo(equip, ret);
    return ret;
}

HOOK_METHOD(ShipObject, HasEquipment, (const std::string& equipment) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipObject::HasEquipment -> Begin (CustomEvents.cpp)\n")
    int ret = super(equipment);

    if (g_checkCargo)
    {
        CheckCargo(equipment, ret);
    }

    return ret;
}

int ShipObject::HasItem(const std::string& equip)
{
    int ret = 0;

    std::map<std::string, int> &equipList = G_->GetShipInfo(iShipId)->equipList;

    std::vector<std::string> blueprintList = G_->GetBlueprints()->GetBlueprintList(equip);

    if (blueprintList.size() > 0)
    {
        for (std::string &bp : blueprintList)
        {
            if (equipList.count(bp) && equipList[bp] > 0)
            {
                return 1;
            }
        }
    }
    else
    {
        if (equipList.count(equip))
        {
            ret = equipList[equip];
        }
    }

    if (g_checkCargo)
    {
        CheckCargo(equip, ret);
    }

    return ret;
}

HOOK_METHOD_PRIORITY(ShipObject, HasEquipment, -100, (const std::string& equipment) -> int)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipObject::HasEquipment -> Begin (CustomEvents.cpp)\n")

    // advancedCheckEquipment is true for actual requirement checks and false for embedded checks such as for slug lifeform detection or clonebay for cloning
    if (advancedCheckEquipment.any())
    {
        if (boost::algorithm::starts_with(equipment, "ANY "))
        {
            std::string child = equipment.substr(4);
            std::vector<std::string> blueprintList = G_->GetBlueprints()->GetBlueprintList(child);
            if (!blueprintList.size()) blueprintList.push_back(child);
            return CustomReq::HasEquipment_Any(*(ShipObject*)this, blueprintList);
        }
        if (boost::algorithm::starts_with(equipment, "ALL "))
        {
            std::string child = equipment.substr(4);
            std::vector<std::string> blueprintList = G_->GetBlueprints()->GetBlueprintList(child);
            if (!blueprintList.size()) blueprintList.push_back(child);
            return CustomReq::HasEquipment_All(*(ShipObject*)this, blueprintList);
        }
        if (boost::algorithm::starts_with(equipment, "SUM "))
        {
            std::string child = equipment.substr(4);
            std::vector<std::string> blueprintList = G_->GetBlueprints()->GetBlueprintList(child);
            if (!blueprintList.size()) blueprintList.push_back(child);
            return CustomReq::HasEquipment_Sum(*(ShipObject*)this, blueprintList);
        }
        if (boost::algorithm::starts_with(equipment, "SEC "))
        {
            // checks the current sector ID
            return G_->GetWorld()->starMap.currentSector->description.type == equipment.substr(4);
        }
        if (boost::algorithm::starts_with(equipment, "SHIP "))
        {
            // checks if ship's blueprint name matches a given name
            ShipManager *ship = G_->GetShipManager(iShipId);
            if (ship)
            {
                ShipBlueprint &shipBp = ship->myBlueprint;
                return shipBp.blueprintName == equipment.substr(5);
            }
            return 0;
        }
        if (boost::algorithm::starts_with(equipment, "ACH "))
        {
            // add 1 so it's 0 if no achievement, 1 on easy, 2 on normal, 3 on hard
            // does not count autogenerated victory/quest achievements, only user-created custom achievements
            return CustomAchievementTracker::instance->GetAchievementStatus(equipment.substr(4)) + 1;
        }
        if (boost::algorithm::starts_with(equipment, "ITEM "))
        {
            // checks if the ship has the exact item, no custom reqs, no augment functions, hidden augments are separate, blueprintList and checkCargo are still processed
            // use for reqs where the exact item is needed (e.g. crafting events that remove the item)
            return HasItem(equipment.substr(5));
        }
        if (equipment == "difficulty")
        {
            // returns the current difficulty level
            return *G_->difficulty;
        }
        if (equipment == "dlc")
        {
            // returns whether Advanced Edition is enabled
            return Settings::GetDlcEnabled();
        }
        if (equipment == "hull")
        {
            // returns the ship's remaining hull integrity, good to stop players from killing themselves on hull damage risking events
            ShipManager *ship = G_->GetShipManager(iShipId);
            if (ship)
            {
                return ship->ship.hullIntegrity.first;
            }
            return 0;
        }

        auto customReq = CustomEventsParser::GetInstance()->GetCustomReq(equipment);

        if (customReq != nullptr)
        {
            return customReq->HasEquipment(*(ShipObject*)this);
        }

        auto playerVariable = playerVariables.find(equipment);

        if (playerVariable != playerVariables.end())
        {
            return playerVariable->second;
        }

        auto metaVariable = metaVariables.find(equipment);

        if (metaVariable != metaVariables.end())
        {
            return metaVariable->second;
        }
    }

    return super(equipment);
}

HOOK_METHOD_PRIORITY(ShipObject, HasEquipment, -1000, (const std::string& equipment) -> int)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipObject::HasEquipment -> Begin (CustomEvents.cpp)\n")

    int ret = super(equipment);

    if (advancedCheckEquipment.any()) // avoids clobbering any embedded equipment checks
    {
        // HAS_EQUIPMENT(ShipManager, equipment, retValue)
        auto context = G_->getLuaContext();
        SWIG_NewPointerObj(context->GetLua(), G_->GetShipManager(this->iShipId), context->getLibScript()->types.pShipManager, 0);
        lua_pushstring(context->GetLua(), equipment.c_str());
        lua_pushinteger(context->GetLua(), ret);
        context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::HAS_EQUIPMENT, 3, 1);
        if (lua_isinteger(context->GetLua(), -1)) ret = lua_tointeger(context->GetLua(), -1);
        lua_pop(context->GetLua(), 3);
    }

    return ret;
}

int ShipObject::HS_HasEquipment(const std::string& equip)
{
    bool temp = advancedCheckEquipment[7];
    advancedCheckEquipment[7] = true;

    int ret = HasEquipment(equip);

    advancedCheckEquipment[7] = temp;
    return ret;
}

static std::string removeHiddenAug = "";

HOOK_METHOD(WorldManager, CreateChoiceBox, (LocationEvent *event) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateChoiceBox -> Begin (CustomEvents.cpp)\n")
    auto customEvents = CustomEventsParser::GetInstance();

    SetCheckCargo(customEvents->GetCustomEvent(event->eventName));

    if (!event->stuff.removeItem.empty())
    {
        if (boost::algorithm::starts_with(event->stuff.removeItem, "HIDDEN "))
        {
            removeHiddenAug = event->stuff.removeItem;
            event->stuff.removeItem = "";
        }
    }

    advancedCheckEquipment[0] = true;

    super(event);

    advancedCheckEquipment[0] = false;

    g_checkCargo = false;
}

// hidden augs, checkCargo
HOOK_METHOD_PRIORITY(WorldManager, ModifyResources, -200, (LocationEvent *event) -> LocationEvent*)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WorldManager::ModifyResources -> Begin (CustomEvents.cpp)\n")
    auto customEvents = CustomEventsParser::GetInstance();
    auto customEvent = customEvents->GetCustomEvent(event->eventName);

    SetCheckCargo(customEvent);

    if (customEvent)
    {
        for (auto i : customEvent->hiddenAugs)
        {
            auto augList = G_->GetShipInfo()->augList;

            if (augList.find("HIDDEN " + i) != augList.end())
            {
                G_->GetShipInfo()->augList["HIDDEN " + i]++;
            }
            else
            {
                G_->GetShipInfo()->augList["HIDDEN " + i] = 1;
            }
            CustomAugmentManager::GetInstance()->UpdateAugments(0);
        }
    }
    else
    {
        g_checkCargo = CustomOptionsManager::GetInstance()->defaults.checkCargo;
    }


    auto ret = super(event);

    g_checkCargo = false;

    if (!removeHiddenAug.empty())
    {
        playerShip->shipManager->RemoveItem(removeHiddenAug);
    }

    removeHiddenAug = "";

    return ret;
}

HOOK_METHOD(ShipManager, RemoveItem, (const std::string& name) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::RemoveItem -> Begin (CustomEvents.cpp)\n")
    bool removedItem = false;

    if (HasAugmentation(name) || boost::algorithm::starts_with(name, "HIDDEN "))
    {
        RemoveAugmentation(name);
        removedItem = true;
    }

    if (systemKey[3] != -1)
    {
        auto weaponList = weaponSystem->weapons;

        int counter = 0;
        for (auto i: weaponList)
        {
            if (name == i->blueprint->name)
            {
                weaponSystem->RemoveWeapon(counter);
                removedItem = true;
                break;
            }

            counter++;
        }
    }

    if (systemKey[4] != -1)
    {
        auto droneList = droneSystem->drones;

        int counter = 0;
        for (auto i: droneList)
        {
            if (name == i->blueprint->name)
            {
                droneSystem->RemoveDrone(counter);
                removedItem = true;
                break;
            }

            counter++;
        }
    }



    if (!removedItem && g_checkCargo)
    {
        Equipment equip = G_->GetWorld()->commandGui->equipScreen;
        auto boxes = equip.vEquipmentBoxes;

        for (auto const& box: boxes)
        {
            bool isCargo = box->IsCargoBox();

            if (isCargo)
            {
                Blueprint* cargoItem = box->GetBlueprint();

                if (cargoItem)
                {
                    if (cargoItem->name == name)
                    {
                        box->RemoveItem();
                        return;
                    }
                }
            }
        }
    }
}

HOOK_METHOD(CommandGui, AddEnemyShip, (CompleteShip *ship) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::AddEnemyShip -> Begin (CustomEvents.cpp)\n")
    super(ship);
    auto custom = CustomEventsParser::GetInstance();

    if (custom->GetBossShipDefinition(ship->shipManager->myBlueprint.blueprintName))
    {
        shipPosition.x = 150 + shipComplete->shipManager->ship.horizontal_shift;
        combatControl.playerShipPosition.x = shipPosition.x;
        space->shipPosition.x = shipPosition.x;

        ftlButton.bBossFight = true;
        shipStatus.bBossFight = true;
    }
}


HOOK_METHOD(CombatControl, AddEnemyShip, (CompleteShip *ship) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::AddEnemyShip -> Begin (CustomEvents.cpp)\n")
    super(ship);
    auto custom = CustomEventsParser::GetInstance();

    if (custom->GetBossShipDefinition(ship->shipManager->myBlueprint.blueprintName))
    {
        boxPosition.x = 5;
        boxPosition.y = 7;

        targetPosition.x = boxPosition.x + 261 - ShipGraph::GetShipInfo(currentTarget->shipManager->iShipId)->shipBox.w / 2;
        targetPosition.y = boxPosition.y + custom->GetBossShipDefinition(ship->shipManager->myBlueprint.blueprintName)->yOffset;

        boss_visual = true;
    }
}

static GL_Texture* boxCustom[3];

HOOK_METHOD(StarMap, constructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::constructor -> Begin (CustomEvents.cpp)\n")
    super();
    boxCustom[0] = G_->GetResources()->GetImageId("map/map_box_custom_1.png");
    boxCustom[1] = G_->GetResources()->GetImageId("map/map_box_custom_2.png");
    boxCustom[2] = G_->GetResources()->GetImageId("map/map_box_custom_3.png");
}

static std::map<Location*, bool[2]> locValues = std::map<Location*, bool[2]>();
static bool questActuallyEnoughTime = false;
static bool questNextSectorPopped = false;
static int questOverrideWorldLevel = -1;
static LocationEvent *lastQuestEvent = nullptr; // used to recycle generated event rather than generating it multiple times

HOOK_METHOD(StarMap, AddQuest, (const std::string& name, bool force) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::AddQuest -> Begin (CustomEvents.cpp)\n")
    int savedSeed = 0;
    int nextQuestSeed = Global::questSeed;
    questOverrideWorldLevel = worldLevel;
    lastQuestEvent = nullptr;
    int numAddedQuests = addedQuests.size();
    int numDelayedQuests = delayedQuests.size();

    if (SeedInputBox::seedsEnabled) savedSeed = random32();

    // Check if this is delayed from the previous sector (currently always from delayedQuests)
    // If special string is detected it must be parsed to get the quest name and seed
    // This won't interfere with addedQuests since addedQuests does not use AddQuest
    std::string questEvent;
    bool isNextSector;
    bool isSeeded;
    if (boost::algorithm::starts_with(name, "QUEST\t")) //loading a saved quest
    {
        std::string name2 = name.substr(6);
        std::vector<std::string> s = std::vector<std::string>();
        boost::split(s, name2, boost::is_any_of("\t"));
        Global::questSeed = std::stoi(s[0]);
        questEvent = s[1];
        isNextSector = s.size() > 2 && s[2] == "D";
        isSeeded = true;
    }
    else
    {
        questEvent = name;
        isNextSector = false;
        isSeeded = false;
    }

    // Get the custom quest options (default and event-specific).
    CustomQuest quest = *(CustomEventsParser::GetInstance()->defaultQuest);
    CustomQuest *eventCustomQuest = CustomEventsParser::GetInstance()->GetCustomQuest(questEvent);
    if (eventCustomQuest) quest.add(eventCustomQuest);

    // Set dynamic defaults.
    if (!quest.createNebula.enabled)
    {
        quest.createNebula = quest.nonNebulaBeacon.value && quest.nebulaEvent.value.empty();
    }
    if (!quest.sectorEight.enabled)
    {
        quest.sectorEight = quest.lastStand.value;
    }

    // quest.sectorEight is forced true if infinite mode is on.
    if (bInfiniteMode)
    {
        quest.sectorEight = true;
    }

    questActuallyEnoughTime = false;
    questNextSectorPopped = false;
    locValues.clear();

    // Set the restricted beacons.
    for (auto i : locations)
    {
        locValues[i][0] = i->questLoc;
        locValues[i][1] = i->nebula;
        CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(i->event->eventName);

        if (i->nebula)
        {
            i->nebula = !quest.nebulaBeacon.value;
        }
        else
        {
            i->nebula = !quest.nonNebulaBeacon.value;
        }

        if (!quest.currentSector.value && !isNextSector)
        {
            i->nebula = true;
        }

        if (customEvent && customEvent->preventQuest)
        {
            i->nebula = true;
        }
    }

    // Override to allow quests to spawn in s8 and later.
    if (quest.sectorEight.value && (worldLevel > 5 || bossLevel))
    {
        worldLevel = 5;

        if (bInfiniteMode || quest.lastStand.value)
        {
            questActuallyEnoughTime = true;
        }
    }

    // Override for last stand.
    if (bossLevel) force = quest.lastStand.value;

    // Don't let quests spawn at beacons taken over or about to be taken over.
    if (force)
    {
        for (auto i : locations)
        {
            i->nebula = i->nebula || i->fleetChanging || i->dangerZone;
        }
    }

    // Seed the quest then try to spawn it normally.
    if (SeedInputBox::seedsEnabled) srandom32(Global::questSeed);
    bool ret = super(questEvent, force);
    if (SeedInputBox::seedsEnabled && !isSeeded) nextQuestSeed = random32();

    // Don't let aggressive quests spawn at beacons taken over or about to be taken over.
    if (!ret && quest.aggressive.value)
    {
        for (auto i : locations)
        {
            i->nebula = i->nebula || i->fleetChanging || i->dangerZone;
            if (!i->nebula) // check fleet arc
            {
                int dangerMove = 0;
                if (dangerZone.x < 60) dangerMove = GetNextDangerMove();
                Pointf nextDangerZone = Pointf(dangerZone.x + dangerMove, dangerZone.y);
                i->nebula = i->loc.RelativeDistance(nextDangerZone) < 588289.f;
            }
        }
    }

    // aggressive == 2: Remove the quest from delayedQuests and try to spawn it again.
    if (!ret && (quest.aggressive.value == 2))
    {
        if (delayedQuests.size() > numDelayedQuests) delayedQuests.pop_back();

        if (SeedInputBox::seedsEnabled) srandom32(Global::questSeed);
        ret = super(questEvent, true);
        if (SeedInputBox::seedsEnabled && !isSeeded) nextQuestSeed = random32();
    }

    // Remove the quest from delayedQuests if nextSector is false.
    if (!ret && !quest.nextSector.value && delayedQuests.size() > numDelayedQuests)
    {
        delayedQuests.pop_back();
        questNextSectorPopped = true;
    }

    // aggressive == 1: Try to spawn the quest again if it can't spawn in the next sector.
    if (!ret && (quest.aggressive.value == 1) && delayedQuests.size() == numDelayedQuests)
    {
        if (SeedInputBox::seedsEnabled) srandom32(Global::questSeed);
        ret = super(questEvent, true);
        if (SeedInputBox::seedsEnabled && !isSeeded) nextQuestSeed = random32();
    }

    worldLevel = questOverrideWorldLevel;
    questOverrideWorldLevel = -1;

    // Reset restricted beacons.
    for (auto i : locValues)
    {
        i.first->nebula = i.second[1];
    }

    // If quest was spawned we need to check if it should be a nebula quest instead.
    if (ret)
    {
        for (auto i : locations)
        {
            if (i->questLoc != locValues[i][0]) //found the new quest location
            {
                if (i->nebula)
                {
                    if (!quest.nebulaEvent.value.empty()) //replace event with nebula event
                    {
                        if (SeedInputBox::seedsEnabled) srandom32(Global::questSeed);
                        i->event = G_->GetEventGenerator()->GetBaseEvent(quest.nebulaEvent.value, worldLevel, false, -1);
                        if (addedQuests.size() > numAddedQuests) {
                            addedQuests[numAddedQuests].first = quest.nebulaEvent.value;
                        }
                    }
                    if (quest.createNebula.value) //add nebula environment
                    {
                        i->event->environment = 3;
                        i->event->statusEffects.push_back({2,7,0,2});
                    }
                }
                break;
            }
        }
    }

    // Override formatting for addedQuests vector to save the quest's seed.
    if (ret && addedQuests.size() > numAddedQuests)
    {
        addedQuests[numAddedQuests].first = "QUEST\t" + std::to_string(Global::questSeed) + "\t" + addedQuests[numAddedQuests].first;
    }

    // Override formatting for delayedQuests vector to save the quest's seed.
    if (!ret && delayedQuests.size() > numDelayedQuests)
    {
        delayedQuests[numDelayedQuests] = "QUEST\t" + std::to_string(Global::questSeed) + "\t" + questEvent + "\tD";
    }

    if (SeedInputBox::seedsEnabled)
    {
        Global::questSeed = nextQuestSeed;
        srandom32(savedSeed);
    }

    return ret;
}

HOOK_METHOD(EventGenerator, GetBaseEvent, (const std::string& name, int worldLevel, char ignoreUnique, int seed) -> LocationEvent*)
{
    LOG_HOOK("HOOK_METHOD -> EventGenerator::GetBaseEvent -> Begin (CustomEvents.cpp)\n")
    if (questOverrideWorldLevel > -1)
    {
        if (lastQuestEvent) return lastQuestEvent;
        LocationEvent *ret = super(name, questOverrideWorldLevel, ignoreUnique, seed);
        lastQuestEvent = ret;
        return ret;
    }

    return super(name, worldLevel, ignoreUnique, seed);
}

HOOK_METHOD(StarMap, RenderLabels, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::RenderLabels -> Begin (CustomEvents.cpp)\n")
    struct LocLabelValues
    {
        bool questLoc;
        bool beacon;
        bool repair;
        Store *pStore;
        bool store;
        bool distressBeacon;
    };
    std::unordered_map<Location*, LocLabelValues> locLabelValues = std::unordered_map<Location*, LocLabelValues>();

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(position.x, position.y, 0.f);
    CSurface::GL_Translate(translation.x, translation.y, 0.f);

    advancedCheckEquipment[1] = true;

    if (!outOfFuel)
    {
        for (auto i : locations)
        {
            if (i->event == nullptr) continue;
            CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(i->event->eventName);

            bool hideVanillaLabel = (customEvent && customEvent->beacon && customEvent->beacon->hideVanillaLabel && (i->visited < 1 || customEvent->beacon->persistent));

            if (customEvent && customEvent->beacon && (i->visited < 1 || customEvent->beacon->persistent) && (bMapRevealed || customEvent->beacon->global || i->known))
            {
                BeaconType *beaconType = customEvent->beacon;

                if (beaconType->equipmentReq.empty() || (shipManager->HasEquipment(beaconType->equipmentReq) > 0) )
                {
                    hideVanillaLabel = true;

                    std::string text = std::string();

                    text = customEvent->beacon->beaconText.GetText();

                    Pointf printLines = freetype::easy_measurePrintLines(51, 0, 0, 999, text);
                    float x = i->loc.x - 1.f;
                    float y = i->loc.y - 33.f;

                    float x2 = 0.f;
                    float y2 = 0.f;

                    GL_Color color = beaconType->color;
                    color.a = color.a * (i->flashTracker.GetAlphaLevel(false) * 0.5 + 0.5);

                    GL_Texture** box;

                    if (color.r == 255.f && color.g == 255.f && color.b == 255.f)
                    {
                        box = boxWhite;
                    }
                    else
                    {
                        box = boxCustom;
                    }

                    if (box[0])
                    {
                        x2 = box[0]->width_;
                        y2 = box[0]->height_;
                    }


                    CSurface::GL_BlitPixelImage(box[0], x, y, x2, y2, 0.f, color, false);

                    CSurface::GL_BlitPixelImage(box[1], x + box[0]->width_, y, printLines.x - 8, box[1]->height_, 0.f, color, false);

                    CSurface::GL_BlitPixelImage(box[2], x + box[0]->width_ + printLines.x - 8, y, box[2]->width_, box[2]->height_, 0.f, color, false);

                    CSurface::GL_SetColor(color);
                    freetype::easy_print(51, i->loc.x + 14.f, i->loc.y - 25.f, text);
                }
            }

            if (hideVanillaLabel && (i->questLoc || i->beacon || i->event->repair || i->event->pStore || i->event->store || i->event->distressBeacon))
            {
                locLabelValues[i].questLoc = i->questLoc;
                locLabelValues[i].beacon = i->beacon;
                locLabelValues[i].repair = i->event->repair;
                locLabelValues[i].pStore = i->event->pStore;
                locLabelValues[i].store = i->event->store;
                locLabelValues[i].distressBeacon = i->event->distressBeacon;

                i->questLoc = false;
                i->beacon = false;
                i->event->repair = false;
                i->event->pStore = nullptr;
                i->event->store = false;
                i->event->distressBeacon = false;
            }
        }
    }

    CSurface::GL_PopMatrix();

    advancedCheckEquipment[1] = false;

    super();

    for (auto i : locations)
    {
        if (i->fleetChanging && i->visited < 1 && i->event)
        {
            LocationEvent *locEvent = i->event;
            auto customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(locEvent->eventName);
            if (customEvent && customEvent->preventFleet)
            {
                i->fleetChanging = false;
            }
        }
    }

    for (auto i : locLabelValues)
    {
        i.first->questLoc = i.second.questLoc;
        i.first->beacon = i.second.beacon;
        if (i.first->event != nullptr)
        {
            i.first->event->repair = i.second.repair;
            i.first->event->pStore = i.second.pStore;
            i.first->event->store = i.second.store;
            i.first->event->distressBeacon = i.second.distressBeacon;
        }
    }
}

static Location* originalExit = nullptr;

HOOK_METHOD(StarMap, GenerateMap, (bool tutorial, bool seed) -> LocationEvent*)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::GenerateMap -> Begin (CustomEvents.cpp)\n")
    originalExit = nullptr;

    if (!loadingGame)
    {
        regeneratedBeacons.clear();
        renamedBeacons.clear();
        CustomBackgroundObjectManager::instance->backgroundObjects.clear();
    }

    // sector quests, set flag to prepend sector quests to delayed quests when generating events
    if (!loadingGame) needSectorQuests = true;

    auto ret = super(tutorial, seed);

    // check custom sector
    auto custom = CustomEventsParser::GetInstance();
    CustomSector *customSector = custom->GetCurrentCustomSector(this);

    // exit beacon event
    if (!tutorial && !bossLevel)
    {
        if (customSector)
        {
            SectorExit customBeacon = customSector->exitBeacons;

            EventGenerator *eventGenerator = G_->GetEventGenerator();
            for (auto i : locations)
            {
                if (i->beacon)
                {
                    std::string event = "";
                    if (i->dangerZone && !customBeacon.rebelEvent.empty())
                    {
                        event = customBeacon.rebelEvent;
                    }
                    else
                    {
                        if (i->nebula && !customBeacon.nebulaEvent.empty())
                        {
                            event = customBeacon.nebulaEvent;
                        }
                        else if (!customBeacon.event.empty())
                        {
                            event = customBeacon.event;
                        }
                    }
                    if (!event.empty())
                    {
                        LocationEvent *newEvent = eventGenerator->GetBaseEvent(event, worldLevel, false, -1);

                        bool isNebula = i->nebula;

                        if (newEvent)
                        {
                            i->event = newEvent;
                            if (isNebula)
                            {
                                i->nebula = true;
                                newEvent->environment = 3;
                                newEvent->statusEffects.push_back({2, 7, 0, 2});
                            }
                        }
                    }
                    if (customSector->noExit)
                    {
                        originalExit = i;
                        i->beacon = false;
                    }
                }
            }

            if (customSector->nebulaSector.enabled)
            {
                bNebulaMap = customSector->nebulaSector.value;
            }
        }
    }

    if (!loadingGame)
    {
        for (int i=0; i<locations.size(); ++i)
        {
            Location *loc = locations[i];
            if (loc->event == nullptr) continue;

            auto customEvent = custom->GetCustomEvent(loc->event->eventName);
            while (customEvent && customEvent->eventLoadList && customEvent->eventLoadList->onGenerate)
            {
                int seed = customEvent->eventLoadList->seeded ? (int)(loc->loc.x + loc->loc.y) ^ currentSectorSeed : -1;
                advancedCheckEquipment[6] = true;
                LocationEvent* newEvent = custom->GetEvent(G_->GetWorld(), customEvent->eventLoadList, seed);
                advancedCheckEquipment[6] = false;
                if (newEvent)
                {
                    //delete loc->event;
                    loc->event->ClearEvent(false);
                    loc->event = newEvent;
                    regeneratedBeacons[i] = std::pair<std::string,int>(newEvent->eventName, seed); // Note: doesn't respect nested "seeded" attributes in eventLoadLists.
                    customEvent = custom->GetCustomEvent(loc->event->eventName);
                }
            }
        }
    }
    else
    {
        for (auto i : regeneratedBeacons)
        {
            LocationEvent* newEvent = G_->GetEventGenerator()->GetBaseEvent(i.second.first, worldLevel, false, i.second.second);

            if (newEvent)
            {
                if (i.first < locations.size() && !locations[i.first]->questLoc && !locations[i.first]->dangerZone) // don't place the event if a dive/quest has already been placed here
                {
                    locations[i.first]->event = newEvent;
                }
                else
                {
                    newEvent->ClearEvent(false);
                }
            }
        }
    }

    for (auto i : renamedBeacons)
    {
        if (i.first < locations.size())
        {
            LocationEvent *event = locations[i.first]->event;
            if (event)
            {
                event->eventName = i.second;
            }
        }
    }

    return ret;
}

// priorityEvents and sector quests
bool needSectorQuests = false;
HOOK_METHOD(StarMap, GenerateEvents, (bool bTutorial) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::GenerateEvents -> Begin (CustomEvents.cpp)\n")

    CustomSector *sec = CustomEventsParser::GetInstance()->GetCurrentCustomSector(this);
    if (sec)
    {
        int i=0;
        std::vector<std_pair_std_string_RandomAmount> highPriorityEventCounts;
        std::vector<std_pair_std_string_RandomAmount> lowPriorityEventCounts;
        ShipManager *ship = G_->GetShipManager(0);

        if (!loadingGame) savedPriorityEventReq.clear();

        for (PriorityEvent &pEvent : sec->priorityEventCounts)
        {
            if (!pEvent.req.empty())
            {
                if (loadingGame)
                {
                    if (!savedPriorityEventReq.at(i++)) continue;
                }
                else
                {
                    bool reqMet = false;
                    if (ship)
                    {
                        advancedCheckEquipment[6] = true;
                        int reqLvl = ship->HasEquipment(pEvent.req);
                        advancedCheckEquipment[6] = false;
                        reqMet = (reqLvl >= pEvent.lvl && reqLvl <= pEvent.max_lvl);
                    }
                    savedPriorityEventReq.push_back(reqMet);
                    if (!reqMet) continue;
                }
            }
            if (pEvent.priority >= 0)
            {
                highPriorityEventCounts.push_back(pEvent.event);
            }
            else
            {
                lowPriorityEventCounts.push_back(pEvent.event);
            }
        }

        if (!highPriorityEventCounts.empty())
        {
            currentSector->description.eventCounts.insert(currentSector->description.eventCounts.begin(), highPriorityEventCounts.begin(), highPriorityEventCounts.end());
        }
        if (!lowPriorityEventCounts.empty())
        {
            currentSector->description.eventCounts.insert(currentSector->description.eventCounts.end(), lowPriorityEventCounts.begin(), lowPriorityEventCounts.end());
        }

        if (needSectorQuests)
        {
            // Only do this once; don't do it multiple times if the generator resets itself
            needSectorQuests = false;

            std::vector<std::string> addedSectorQuests = std::vector<std::string>();

            for (SectorQuest &event : sec->sectorQuests)
            {
                bool reqMet = event.req.empty();
                if (!reqMet)
                {
                    if (ship)
                    {
                        advancedCheckEquipment[6] = true;
                        int reqLvl = ship->HasEquipment(event.req);
                        advancedCheckEquipment[6] = false;
                        reqMet = (reqLvl >= event.lvl && reqLvl <= event.max_lvl);
                    }
                }
                if (reqMet)
                {
                    // seed is -1
                    addedSectorQuests.push_back("QUEST\t-1\t" + event.event);
                }
            }

            if (!addedSectorQuests.empty())
            {
                delayedQuests.insert(delayedQuests.begin(), addedSectorQuests.begin(), addedSectorQuests.end());
            }
        }
    }

    super(bTutorial);
}


HOOK_METHOD_PRIORITY(StarMap, TurnIntoFleetLocation, 9999, (Location *loc) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> StarMap::TurnIntoFleetLocation -> Begin (CustomEvents.cpp)\n")
    EventGenerator *eventGenerator = G_->GetEventGenerator();

    auto locEvent = loc->event;
    loc->dangerZone = true;
    loc->fleetChanging = false;
    loc->questLoc = false; // Remove quest marker from overtaken beacons

    if (locEvent)
    {
        locEvent->ClearEvent(false);
        std::string event;

        if ((loc->beacon || loc == originalExit) && !bossLevel)
        {
            event = "FLEET_EASY_BEACON";
        }
        else if (loc->nebula)
        {
            event = "FLEET_EASY_NEBULA";
        }
        else
        {
            event = "FLEET_EASY";
        }


        if (Settings::GetDlcEnabled() && !loc->nebula)
        {
            event.append("_DLC");
        }
        auto replaceEvent = eventGenerator->GetBaseEvent(event, worldLevel, false, -1);

        if (replaceEvent)
        {
            loc->event = replaceEvent;
        }

        loc->event->fleetPosition = 1;
        loc->event->repair = false;

        if ((loc->beacon || loc == originalExit) && loc->nebula)
        {
            loc->event->environment = 3;
            loc->event->statusEffects.push_back({2, 7, 0, 2});
        }
    }



    if (!bossLevel)
    {
        auto custom = CustomEventsParser::GetInstance();

        CustomSector *customSector = custom->GetCurrentCustomSector(this);

        if (customSector)
        {
            SectorExit customBeacon = customSector->exitBeacons;
            if ((loc->beacon || loc == originalExit) && !customBeacon.rebelEvent.empty())
            {
                bool isNebula = loc->nebula;

                LocationEvent *newEvent = eventGenerator->GetBaseEvent(customBeacon.rebelEvent, worldLevel, false, -1);

                if (newEvent)
                {
                    loc->event->ClearEvent(false);
                    loc->event = newEvent;

                    if (isNebula)
                    {
                        loc->nebula = true;
                        newEvent->environment = 3;
                        newEvent->statusEffects.push_back({2, 7, 0, 2});
                    }
                }
            }
        }
    }

    if (!(loc->beacon || loc == originalExit) || bossLevel)
    {
        auto custom = CustomEventsParser::GetInstance();
        CustomSector *customSector = custom->GetCurrentCustomSector(this);

        if (customSector)
        {
            SectorFleet customBeacon = customSector->fleetBeacons;

            std::string event = "";
            if (loc->nebula && !customBeacon.nebulaEvent.empty())
            {
                event = customBeacon.nebulaEvent;
            }
            else if (!customBeacon.event.empty())
            {
                event = customBeacon.event;
            }

            if (!event.empty())
            {
                LocationEvent *newEvent = eventGenerator->GetBaseEvent(event, worldLevel, false, -1);

                if (newEvent)
                {
                    loc->event->ClearEvent(false);
                    loc->event = newEvent;
                    loc->event->repair = false;
                }
            }
        }
    }
}


HOOK_METHOD(WorldManager, CreateChoiceBox, (LocationEvent *loc) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateChoiceBox -> Begin (CustomEvents.cpp)\n")
    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(loc->eventName);
    if (customEvent)
    {
        if (!customEvent->unlockShip.empty())
        {
            if (customEvent->unlockShipReq.empty() || G_->GetAchievementTracker()->currentShip == customEvent->unlockShipReq)
            {
                CustomShipUnlocks::instance->UnlockShip(customEvent->unlockShip, customEvent->unlockShipSilent, true, true);
            }
        }

        if (!customEvent->achievement.empty())
        {
            CustomAchievementTracker::instance->SetAchievement(customEvent->achievement, customEvent->achievementSilent);
        }

        if (customEvent->noQuestText)
        {
            std::string str;
            str = G_->GetTextLibrary()->GetText("added_quest");
            str.insert(0, "\n\n");
            loc->text.data = boost::algorithm::replace_first_copy(loc->text.data, str, "");
            str = G_->GetTextLibrary()->GetText("no_time");
            str.insert(0, "\n\n");
            loc->text.data = boost::algorithm::replace_first_copy(loc->text.data, str, "");
            str = G_->GetTextLibrary()->GetText("added_quest_sector");
            str.insert(0, "\n\n");
            loc->text.data = boost::algorithm::replace_first_copy(loc->text.data, str, "");
        }
    }
    if (questActuallyEnoughTime)
    {
        std::string str;
        std::string repl;

        str = G_->GetTextLibrary()->GetText("no_time");
        repl = G_->GetTextLibrary()->GetText("added_quest_sector");
        loc->text.data = boost::algorithm::replace_first_copy(loc->text.data, str, repl);
    }
    if (questNextSectorPopped)
    {
        std::string str;
        std::string repl;

        str = G_->GetTextLibrary()->GetText("added_quest_sector");
        repl = G_->GetTextLibrary()->GetText("no_time_sector");
        loc->text.data = boost::algorithm::replace_first_copy(loc->text.data, str, repl);
    }

    super(loc);

    if (customEvent)
    {
        if (!customEvent->transformRace.second.empty() && G_->GetCrewFactory()->playerCrew > 0)
        {
            if (lastSelectedCrewSeed == -1) lastSelectedCrewSeed = random32();

            CrewBlueprint crewBlue = playerShip->shipManager->SelectRandomCrew(lastSelectedCrewSeed, customEvent->transformRace.first);

            CrewBlueprint newBlueprint = G_->GetBlueprints()->GetCrewBlueprint(customEvent->transformRace.second);

            crewBlue.powers = newBlueprint.powers;
            crewBlue.name = newBlueprint.name;
            crewBlue.desc = newBlueprint.desc;
            crewBlue.type = newBlueprint.type;

            if (g_transformColorMode == TransformColorMode::KEEP_INDICES)
            {
                CrewMember_Extend::TransformColors(crewBlue, &newBlueprint);
            }
            else
            {
                if (newBlueprint.colorLayers.size() < crewBlue.colorLayers.size()) crewBlue.colorLayers.resize(newBlueprint.colorLayers.size());
                if (newBlueprint.colorChoices.size() < crewBlue.colorChoices.size()) crewBlue.colorChoices.resize(newBlueprint.colorChoices.size());
            }

            commandGui->choiceBox.rewards.crew = 1;
            commandGui->choiceBox.rewards.crewType = crewBlue.name;
            commandGui->choiceBox.rewards.crewBlue = crewBlue;
        }
    }
}

HOOK_METHOD(LocationEvent, constructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> LocationEvent::constructor -> Begin (CustomEvents.cpp)\n")
    super();
    gap_ex_cleared = false;
}

HOOK_METHOD(LocationEvent, ClearEvent, (bool force) -> void)
{
    LOG_HOOK("HOOK_METHOD -> LocationEvent::ClearEvent -> Begin (CustomEvents.cpp)\n")
    super(force);
    if (fleetPosition == 1 && !force) return;
    gap_ex_cleared = true;
}

void EventDamageEnemy(EventDamage eventDamage)
{
    ShipManager* enemyShip = G_->GetShipManager(1);
    if (enemyShip != nullptr)
    {
        if (enemyShip->bJumping) return;
        if (!(eventDamage.effect & 16)) enemyShip->DamageHull(eventDamage.amount,true);
        if (eventDamage.system == -1) return;
        int room = -1;
        if (eventDamage.system == 18)
        {
            ShipSystem* randomSystem = enemyShip->vSystemList[random32() % enemyShip->vSystemList.size()];
            room = randomSystem->GetRoomId();
        }
        else if (eventDamage.system == 19)
        {
            room = random32() % ShipGraph::GetShipInfo(1)->RoomCount();
        }
        else
        {
            room = enemyShip->GetSystemRoom(eventDamage.system);
        }
        if (room == -1) return;

        if (eventDamage.effect & 8)
        {
            ShipSystem* sys = enemyShip->GetSystemInRoom(room);
            if (sys)
            {
                sys->AddDamage(eventDamage.amount);
                DamageMessage *msg = new DamageMessage(1.f, eventDamage.amount, enemyShip->ship.GetRoomCenter(room), false);
                msg->color = GL_Color(1.f, 0.3921569f, 0.3921569f, 1.f);
                enemyShip->damMessages.push_back(msg);
            }
        }
        else
        {
            Damage damage;

            damage.iDamage = 0;
            damage.iShieldPiercing = 0;
            damage.fireChance = 0;
            damage.breachChance = 0;
            damage.stunChance = 0;
            damage.iIonDamage = 0;
            damage.iSystemDamage = eventDamage.amount;
            damage.iPersDamage = 0;
            damage.bHullBuster = false;
            damage.ownerId = -1;
            damage.selfId = -1;
            damage.bLockdown = false;
            damage.crystalShard = false;
            damage.bFriendlyFire = false;
            damage.iStun = 0;

            enemyShip->DamageSystem(room, damage);
        }

        if (eventDamage.effect & 4)
        {
            int effect = random32();
            if (effect&1)
            {
                enemyShip->StartFire(room);
            }
            else
            {
                enemyShip->ship.BreachRandomHull(room);
            }
        }
        else
        {
            if (eventDamage.effect&1) enemyShip->StartFire(room);
            if (eventDamage.effect&2) enemyShip->ship.BreachRandomHull(room);
        }
    }
}

void RecallBoarders(int direction, bool force)
{
    int targetRoom;
    bool canTeleport;

    CompleteShip *playerShip = G_->GetWorld()->playerShip;
    if (playerShip == nullptr) return;

    CompleteShip *enemyShip = G_->GetWorld()->playerShip->enemyShip;
    if (enemyShip == nullptr) return;

    if (direction >= 0) { // player's boarders from enemy ship
        targetRoom = playerShip->shipManager->GetSystemRoom(6);

        for (auto i : enemyShip->shipManager->vCrewList)
        {
            //if (i->iShipId == 0 && !i->IsDrone())
            if (!i->bDead && i->iShipId == 0 && !i->IsDrone())
            {
                CrewMember_Extend *ex = CM_EX(i);
                auto def = CustomCrewManager::GetInstance()->GetDefinition(i->species);
                ex->CalculateStat(CrewStat::CAN_TELEPORT, def, &canTeleport);

                if (canTeleport || force) // do it this way to ignore the vanilla conditions
                {
                    i->EmptySlot();
                    playerShip->AddCrewMember2(i,targetRoom);
                }
            }
        }
    }
    if (direction <= 0) { // enemy boarders from player ship
        targetRoom = enemyShip->shipManager->GetSystemRoom(6);

        for (auto i : playerShip->shipManager->vCrewList)
        {
            //if (i->iShipId == 1 && !i->IsDrone())
            if (!i->bDead && i->iShipId == 1 && !i->IsDrone())
            {
                CrewMember_Extend *ex = CM_EX(i);
                auto def = CustomCrewManager::GetInstance()->GetDefinition(i->species);
                ex->CalculateStat(CrewStat::CAN_TELEPORT, def, &canTeleport);

                if (canTeleport || force) // do it this way to ignore the vanilla conditions
                {
                    i->EmptySlot();
                    enemyShip->AddCrewMember2(i,targetRoom);
                }
            }
        }
    }
}

void CustomCreateLocation(WorldManager* world, LocationEvent* event, CustomEvent* customEvent)
{
    for (auto& alias : customEvent->eventAlias)
    {
        if (alias.second.event.empty())
        {
            auto it = eventAliases.find(alias.first);
            if (it != eventAliases.end())
            {
                eventAliases.erase(it);
            }
        }
        else
        {
            eventAliases[alias.first] = alias.second;
        }
    }

    if (!customEvent->changeBackground.empty())
    {
        world->starMap.currentLoc->space = world->space.SwitchBackground(customEvent->changeBackground);

        world->starMap.currentLoc->spaceImage = customEvent->changeBackground;
    }

    if (!customEvent->clearBackgroundObjects.empty())
    {
        for (std::string &def : customEvent->clearBackgroundObjects)
        {
            CustomBackgroundObjectManager::instance->ClearObjects(def);
        }
    }

    if (!customEvent->transformBackgroundObjects.empty())
    {
        for (auto &def : customEvent->transformBackgroundObjects)
        {
            CustomBackgroundObjectManager::instance->TransformObjects(def.first, def.second);
        }
    }

    if (!customEvent->backgroundObjects.empty())
    {
        for (CustomBackgroundObjectDefinition *def : customEvent->backgroundObjects)
        {
            CustomBackgroundObjectManager::instance->CreateObject(def);
        }
    }

    if (!customEvent->clearEventButtons.empty())
    {
        for (std::string &def : customEvent->clearEventButtons)
        {
            EventButtonManager::instance->ClearButtons(def);
        }
    }

    if (!customEvent->eventButtons.empty())
    {
        for (EventButtonDefinition *def : customEvent->eventButtons)
        {
            EventButtonManager::instance->CreateButton(def);
        }
        EventButtonManager::instance->Sort();
    }

    if (customEvent->recallBoarders) {
        RecallBoarders(customEvent->recallBoardersShip, customEvent->recallBoardersForce);
    }

    if (!customEvent->playSound.empty())
    {
        G_->GetSoundControl()->PlaySoundMix(customEvent->playSound, -1.f, false);
    }

    if (customEvent->resetMusic)
    {
        G_->GetSoundControl()->StartPlaylist(world->starMap.currentSector->description.musicTracks);
    }

    if (!customEvent->playMusic.empty())
    {
        std::vector<std::string> track = {customEvent->playMusic};
        G_->GetSoundControl()->StartPlaylist(track);
    }

    if (customEvent->removeStore)
    {
        // Close store window to prevent issues.
        TabbedWindow& storeScreens = G_->GetWorld()->commandGui->storeScreens;
        if (storeScreens.currentTab >= 0 && storeScreens.currentTab < storeScreens.windows.size() && storeScreens.windows[storeScreens.currentTab])
        {
            storeScreens.Close();
        }
        storeScreens.bOpen = false;
        storeScreens.windows[0] = nullptr;

        world->baseLocationEvent->pStore = nullptr;
        world->baseLocationEvent->store = false;
    }

    if (!customEvent->enemyDamage.empty() && event->damage.empty())
    {
        G_->GetSoundControl()->PlaySoundMix("eventDamage", -1, false);
    }

    for (EventDamage& eventDamage: customEvent->enemyDamage)
    {
        EventDamageEnemy(eventDamage);
    }

    if (customEvent->repairAllSystems)
    {
        ShipManager* shipManager = G_->GetShipManager(0);
        if (shipManager != nullptr)
        {
            for (auto sys : shipManager->vSystemList)
            {
                sys->AddDamage(-sys->healthState.second);
            }
        }
    }

    if (customEvent->killEnemyBoarders)
    {
        ShipManager* shipManager = G_->GetShipManager(0);
        if (shipManager != nullptr)
        {
            for (auto crew : shipManager->vCrewList)
            {
                if (crew->iShipId != 0)
                {
                    crew->health.first = 0;
                }
            }
        }
    }

    if (customEvent->instantEscape)
    {
        CompleteShip* enemyShip = world->playerShip->enemyShip;
        if (enemyShip != nullptr && !enemyShip->shipManager->bDestroyed)
        {
            enemyShip->shipAI.escaping = true;
            enemyShip->shipManager->JumpLeave();
        }
    }

    if (customEvent->escape)
    {
        CompleteShip* enemyShip = world->playerShip->enemyShip;
        if (enemyShip != nullptr && !enemyShip->shipManager->bDestroyed)
        {
            enemyShip->shipAI.escaping = true;
        }
    }

    if (customEvent->surrender)
    {
        CompleteShip* enemyShip = world->playerShip->enemyShip;
        if (enemyShip != nullptr && !enemyShip->shipManager->bDestroyed)
        {
            enemyShip->shipAI.surrendered = true;
        }
    }

    if (customEvent->loadEscape)
    {
        CompleteShip* enemyShip = world->playerShip->enemyShip;
        if (enemyShip != nullptr && (customEvent->loadEscapeForced || enemyShip->shipAI.escapeThreshold > 0))
        {
            enemyShip->shipAI.escapeThreshold = 2147483647;
        }
    }

    if (customEvent->loadSurrender)
    {
        CompleteShip* enemyShip = world->playerShip->enemyShip;
        if (enemyShip != nullptr && (customEvent->loadSurrenderForced || enemyShip->shipAI.surrenderThreshold > 0))
        {
            enemyShip->shipAI.surrenderThreshold = 2147483647;
        }
    }

    if (customEvent->disableEscape)
    {
        CompleteShip* enemyShip = world->playerShip->enemyShip;
        if (enemyShip != nullptr)
        {
            enemyShip->shipAI.escapeThreshold = 0;
            if (customEvent->disableEscapeForced)
            {
                enemyShip->shipAI.escaping = false;
            }
        }
    }

    if (customEvent->disableSurrender)
    {
        CompleteShip* enemyShip = world->playerShip->enemyShip;
        if (enemyShip != nullptr)
        {
            enemyShip->shipAI.surrenderThreshold = 0;
            if (customEvent->disableSurrenderForced)
            {
                enemyShip->shipAI.surrendered = false;
            }
        }
    }

    if (customEvent->superDrones != -1)
    {
        ShipManager* shipManager = G_->GetShipManager(customEvent->superDrones);
        if (shipManager != nullptr)
        {
            droneSurgeOverride = customEvent->superDronesName;
            shipManager->PrepareSuperDrones();
        }
    }

    if (customEvent->clearSuperDrones != -1)
    {
        ShipManager* shipManager = G_->GetShipManager(customEvent->clearSuperDrones);
        if (shipManager != nullptr)
        {
            /*
            for (auto i : shipManager->superDrones)
            {
                delete i;
            }
            */
            shipManager->superDrones.clear();
        }
    }

    if (customEvent->superBarrage != -1)
    {
        ShipManager* shipManager = G_->GetShipManager(customEvent->superBarrage);
        if (shipManager != nullptr)
        {
            barrageOverride = customEvent->superBarrageName;
            shipManager->PrepareSuperBarrage();
        }
    }

    if (customEvent->powerSuperShields != -1)
    {
        ShipManager* shipManager = G_->GetShipManager(customEvent->powerSuperShields);
        if (shipManager != nullptr)
        {
            Shields *shields = shipManager->shieldSystem;
            if (shields != nullptr)
            {
                if (customEvent->powerSuperShieldsSet > shields->shields.power.super.second)
                {
                    shields->shields.power.super.second = customEvent->powerSuperShieldsSet;
                }
                if (customEvent->powerSuperShieldsSet == -1)
                {
                    shields->shields.power.super.first = shields->shields.power.super.second;
                }
                else if (customEvent->powerSuperShieldsSet > shields->shields.power.super.first)
                {
                    shields->shields.power.super.first = customEvent->powerSuperShieldsSet;
                }
                shields->shields.power.super.first = std::min(shields->shields.power.super.second, shields->shields.power.super.first + customEvent->powerSuperShieldsAdd);
            }
        }
    }

    if (!customEvent->renameBeacon.empty())
    {
        world->starMap.currentLoc->event->eventName = customEvent->renameBeacon;
        auto it = std::find(world->starMap.locations.begin(), world->starMap.locations.end(), world->starMap.currentLoc);
        if (it != world->starMap.locations.end())
        {
            renamedBeacons[std::distance(world->starMap.locations.begin(), it)] = customEvent->renameBeacon;
        }
    }

    if (!customEvent->clearQueueEvents.empty())
    {
        for (std::string &name : customEvent->clearQueueEvents)
        {
            if (!name.empty())
            {
                eventQueue.erase(std::remove_if(eventQueue.begin(), eventQueue.end(),
                                                [&name](EventQueueEvent& obj) { return obj.label == name; }),
                                                eventQueue.end());
            }
            else
            {
                eventQueue.clear();
            }
        }
    }
}

LocationEvent* CustomEventsParser::GetEvent(WorldManager *world, EventLoadList *eventList, int seed)
{
    if (!eventList->seeded) seed = -1;

    ShipManager* player = G_->GetShipManager(0);
    std::unordered_set<int> used_groups;
    std::vector<LocationEvent*> candidateEvents;

    for (auto& event : eventList->events)
    {
        if (event.max_group != -1 && used_groups.count(event.max_group)) continue;

        if (!event.req.empty())
        {
            int result = player->HasEquipment(event.req);
            if (result < event.lvl || result > event.max_lvl) continue;
            if (event.max_group != -1) used_groups.insert(event.max_group);
        }

        LocationEvent* locEvent = GetEvent(world, event.event, eventList->ignoreUnique, seed);
        if (locEvent)
        {
            if (world->CheckRequirements(locEvent, false))
            {
                if (eventList->useFirst) return locEvent;
                candidateEvents.push_back(locEvent);
            }
            else
            {
                G_->GetEventGenerator()->ClearUsedEvent(locEvent);
                locEvent->ClearEvent(false);
            }
        }
    }

    if (candidateEvents.empty())
    {
        if (eventList->defaultEvent.empty()) return nullptr;
        return GetEvent(world, eventList->defaultEvent, eventList->ignoreUnique, seed);
    }
    if (candidateEvents.size() == 1) return candidateEvents[0];

    if (seed != -1) srandom32(seed);
    LocationEvent* ret = candidateEvents[random32()%candidateEvents.size()];
    for (LocationEvent* event : candidateEvents)
    {
        if (event != ret)
        {
            G_->GetEventGenerator()->ClearUsedEvent(event);
            event->ClearEvent(false);
        }
    }

    return ret;
}

LocationEvent* CustomEventsParser::GetEvent(WorldManager *world, std::string eventName, bool ignoreUnique, int seed)
{
    auto it_alias = eventAliases.find(eventName);
    if (it_alias != eventAliases.end())
    {
        eventName = it_alias->second.event;
        if (it_alias->second.once)
        {
            eventAliases.erase(it_alias);
        }
    }
    auto it = customEventLoadLists.find(eventName);
    if (it != customEventLoadLists.end())
    {
        return GetEvent(world, it->second, seed);
    }
    return G_->GetEventGenerator()->GetBaseEvent(eventName, world->starMap.currentSector->level, ignoreUnique, seed);
}

void CustomEventsParser::LoadEvent(WorldManager *world, EventLoadList *eventList, int seed, CustomEvent *parentEvent)
{
    SetCheckCargo(parentEvent);
    advancedCheckEquipment[2] = true;

    LocationEvent *event = GetEvent(world, eventList, seed);

    g_checkCargo = false;
    advancedCheckEquipment[2] = false;

    if (event) world->UpdateLocation(event);
}

void CustomEventsParser::LoadEvent(WorldManager *world, std::string eventName, bool ignoreUnique, int seed, CustomEvent *parentEvent)
{
    SetCheckCargo(parentEvent);
    advancedCheckEquipment[2] = true;

    LocationEvent *event = GetEvent(world, eventName, ignoreUnique, seed);

    g_checkCargo = false;
    advancedCheckEquipment[2] = false;

    if (event) world->UpdateLocation(event);
}

void CustomEventsParser::QueueEvent(EventQueueEvent &event)
{
    eventQueue.push_back(event);
}

void CustomEventsParser::QueueEvent(std::string &event, int seed)
{
    EventQueueEvent queueEvent;

    queueEvent.event = event;
    queueEvent.seed = seed;
    queueEvent.label = "";

    eventQueue.push_back(queueEvent);
}

HOOK_METHOD(WorldManager, CreateLocation, (Location *location) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateLocation -> Begin (CustomEvents.cpp)\n")
    if (!loadingGame)
    {
        for (auto it = eventAliases.begin(); it != eventAliases.end(); )
        {
            if (it->second.jumpClear)
            {
                it = eventAliases.erase(it);
            }
            else
            {
                ++it;
            }
        }
        deathEventQueue.erase(std::remove_if(deathEventQueue.begin(), deathEventQueue.end(),
                              [](DeathEvent& obj) { return obj.jumpClear; }),
                              deathEventQueue.end());
    }

    bool needsBackground = location->space.tex == nullptr && location->planet.tex == nullptr;

    super(location);

    if (loadingGame) return;

    // Load correct federation base background if the boss got there first
    if (needsBackground && location->boss && location->beacon && location->event != nullptr)
    {
        location->space = space.SwitchBackground(location->event->spaceImage);

        location->planet = space.SwitchPlanet(location->event->planetImage);

        location->spaceImage = location->event->spaceImage;
        location->planetImage = location->event->planetImage;
    }

    LocationEvent *loc = location->event;

    if (!loc) return;

    //if (location->visited > 1 && !location->boss && !location->dangerZone)
    if (!location->boss && loc->gap_ex_cleared)
    {
        std::string revisitEvent = CustomEventsParser::GetInstance()->defaultRevisit;
        bool revisitSeeded = CustomEventsParser::GetInstance()->defaultRevisitSeeded;
        bool revisitIgnoreUnique = CustomEventsParser::GetInstance()->defaultRevisitIgnoreUnique;

        CustomEvent *customEvent = nullptr;

        if (loc->ship.present && loc->ship.hostile) return; // left behind an enemy ship

        customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(loc->eventName);

        if (customEvent && !customEvent->eventRevisit.empty())
        {
            revisitEvent = customEvent->eventRevisit;
            revisitSeeded = customEvent->eventRevisitSeeded;
            revisitIgnoreUnique = customEvent->eventRevisitIgnoreUnique;
        }

        if (!revisitEvent.empty())
        {
            int seed = revisitSeeded ? (int)(location->loc.x + location->loc.y) ^ (starMap.currentSectorSeed*location->visited + location->visited) : -1;
            CustomEventsParser::GetInstance()->LoadEvent(this, revisitEvent, revisitIgnoreUnique, seed, customEvent);
        }

        return;
    }

    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(location); // this version of GetCustomEvent accounts for boss

    if (customEvent)
    {
        CustomCreateLocation(this, loc, customEvent);

        for (EventQueueEvent queueEvent : customEvent->queueEvents) // by value
        {
            if (queueEvent.seed != -1) queueEvent.seed = GenerateLocationSeed(*location, starMap.currentSectorSeed);
            CustomEventsParser::QueueEvent(queueEvent);
        }

        if (customEvent->eventLoadList != nullptr)
        {
            int seed = customEvent->eventLoadList->seeded ? GenerateLocationSeed(*location, starMap.currentSectorSeed) : -1;
            CustomEventsParser::GetInstance()->LoadEvent(this, customEvent->eventLoadList, seed, customEvent);
        }

        if (!customEvent->eventLoad.empty())
        {
            int seed = customEvent->eventLoadSeeded ? GenerateLocationSeed(*location, starMap.currentSectorSeed) : -1;
            CustomEventsParser::GetInstance()->LoadEvent(this, customEvent->eventLoad, customEvent->eventLoadIgnoreUnique, seed, customEvent);
        }

        if (!customEvent->secretSectorWarp.empty())
        {
            location->event->eventName = loc->eventName;
        }
    }
}

static bool g_noASBPlanet = false;

HOOK_METHOD(WorldManager, UpdateLocation, (LocationEvent *loc) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::UpdateLocation -> Begin (CustomEvents.cpp)\n")
    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(loc->eventName);

    if (!loadingGame)
    {
        lastSelectedCrewSeed = -1;
    }

    if (customEvent)
    {
        if (customEvent->noASBPlanet)
        {
            g_noASBPlanet = true;
        }
    }

    super(loc);

    if (loc->ship.present && loc->ship.hostile && !ships.empty())
    {
        CompleteShip* enemyShip = ships[0];
        if (enemyShip->shipManager && enemyShip->shipManager->_targetable.hostile)
        {
            if (playerShip->shipManager->current_target != enemyShip->shipManager)
            {
                commandGui->combatControl.Clear();
                commandGui->AddEnemyShip(enemyShip);
                if (playerShip->shipManager->hackingSystem)
                {
                    bool needHackingDrone = true;
                    for (SpaceDrone* drone : space.drones)
                    {
                        if (drone == &playerShip->shipManager->hackingSystem->drone)
                        {
                            needHackingDrone = false;
                            break;
                        }
                    }
                    if (needHackingDrone)
                    {
                        space.drones.push_back(&playerShip->shipManager->hackingSystem->drone);
                    }
                }
                if (enemyShip->shipManager->hackingSystem)
                {
                    bool needHackingDrone = true;
                    for (SpaceDrone* drone : space.drones)
                    {
                        if (drone == &enemyShip->shipManager->hackingSystem->drone)
                        {
                            needHackingDrone = false;
                            break;
                        }
                    }
                    if (needHackingDrone)
                    {
                        space.drones.push_back(&enemyShip->shipManager->hackingSystem->drone);
                    }
                }
            }
        }
    }

    if (!loc->gap_ex_cleared && customEvent)
    {
        if (customEvent->removeHazards)
        {
            space.asteroidGenerator.bRunning = false;
            space.SetPulsarLevel(false);
            space.SetPlanetaryDefense(false, 0);
            space.SetFireLevel(false);
            space.nebulaClouds.clear();
            space.bStorm = false;
            playerShip->shipManager->ClearStatusAll();
            if (space.bNebula)
            {
                space.SetNebula(true);
            }
        }
        if (customEvent->removeNebula)
        {
            space.bNebula = false;
            space.bStorm = false;
            space.nebulaClouds.clear();
        }

        if (customEvent->resetFtl)
        {
            playerShip->shipManager->jump_timer.first = 0.f;
        }

        CustomCreateLocation(this, loc, customEvent);

        for (EventQueueEvent queueEvent : customEvent->queueEvents) // by value
        {
            if (queueEvent.seed != -1) queueEvent.seed = GenerateLocationSeed(*starMap.currentLoc, starMap.currentSectorSeed);
            CustomEventsParser::QueueEvent(queueEvent);
        }

        if (customEvent->eventLoadList != nullptr)
        {
            int seed = customEvent->eventLoadList->seeded ? GenerateLocationSeed(*starMap.currentLoc, starMap.currentSectorSeed) : -1;
            CustomEventsParser::GetInstance()->LoadEvent(this, customEvent->eventLoadList, seed, customEvent);
        }

        if (!customEvent->eventLoad.empty())
        {
            int seed = customEvent->eventLoadSeeded ? GenerateLocationSeed(*starMap.currentLoc, starMap.currentSectorSeed) : -1;
            CustomEventsParser::GetInstance()->LoadEvent(this, customEvent->eventLoad, customEvent->eventLoadIgnoreUnique, seed, customEvent);
        }

        if (customEvent->restartEvent)
        {
            super(starMap.currentLoc->event);
        }

        if (!customEvent->secretSectorWarp.empty())
        {
            starMap.currentLoc->event->eventName = loc->eventName;
        }
    }

    g_noASBPlanet = false;
}

HOOK_METHOD(WorldManager, CreateShip, (ShipEvent* shipEvent, bool boss) -> CompleteShip*)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateShip -> Begin (CustomEvents.cpp)\n")
    auto ret = super(shipEvent, boss);

    bossDefeated = false;

    if (loadingGame) return ret;

    CustomShipEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomShipEvent(shipEvent->name);

    if (customEvent)
    {
        if (!customEvent->clearJumpEvents.empty())
        {
            for (std::string &name : customEvent->clearJumpEvents)
            {
                if (!name.empty())
                {
                    jumpEventQueue.erase(std::remove_if(jumpEventQueue.begin(), jumpEventQueue.end(),
                                         [&name](JumpEvent& obj) { return obj.label == name; }),
                                         jumpEventQueue.end());
                }
                else
                {
                    jumpEventQueue.clear();
                }
            }
        }

        if (!customEvent->jumpEvents.empty())
        {
            for (JumpEvent &jumpEvent : customEvent->jumpEvents)
            {
                jumpEventQueue.push_back(jumpEvent);
            }
            std::stable_sort(jumpEventQueue.begin(), jumpEventQueue.end(),
            [](const JumpEvent &a, const JumpEvent &b) -> bool
            {
                return a.priority > b.priority;
            });
        }

        if (!customEvent->clearDeathEvents.empty())
        {
            for (std::string &name : customEvent->clearDeathEvents)
            {
                if (!name.empty())
                {
                    deathEventQueue.erase(std::remove_if(deathEventQueue.begin(), deathEventQueue.end(),
                                          [&name](DeathEvent& obj) { return obj.label == name; }),
                                          deathEventQueue.end());
                }
                else
                {
                    deathEventQueue.clear();
                }
            }
        }

        if (!customEvent->deathEvents.empty())
        {
            for (DeathEvent &deathEvent : customEvent->deathEvents)
            {
                if (deathEvent.event.empty() && deathEvent.label.empty())
                {
                    deathEventQueue.clear(); // backwards compatibility
                }
                else
                {
                    deathEventQueue.push_back(deathEvent);
                }
            }
            std::stable_sort(deathEventQueue.begin(), deathEventQueue.end(),
            [](const DeathEvent &a, const DeathEvent &b) -> bool
            {
                return a.priority > b.priority;
            });
        }

        for (auto& triggeredEvent: customEvent->clearTriggeredEvents)
        {
            TriggeredEvent::DestroyEvent(triggeredEvent);
        }

        for (auto& triggeredEvent: customEvent->triggeredEvents)
        {
            TriggeredEvent::NewEvent(&TriggeredEventDefinition::defs.at(triggeredEvent));
        }

        for (auto& triggeredEvent: customEvent->triggeredEventModifiers)
        {
            triggeredEvent.ApplyModifier();
        }

        if (customEvent->invincible)
        {
            ret->shipManager->bInvincible = true;
        }
    }

    return ret;
}

HOOK_METHOD(StarMap, GetLocationText, (Location* loc) -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::GetLocationText -> Begin (CustomEvents.cpp)\n")
    struct LocLabelValues
    {
        bool questLoc;
        bool beacon;
        bool repair;
        Store *pStore;
        bool store;
        bool distressBeacon;
    };

    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(loc->event->eventName);

    if (!customEvent) return super(loc);

    if (loc->fleetChanging || loc == this->currentLoc || !customEvent->beacon)
    {
        return super(loc);
    }

    TextString tooltip;
    bool hideVanillaLabel = true;

    if ((!customEvent->beacon->global && !loc->known && !this->bMapRevealed) ||
        (!customEvent->beacon->equipmentReq.empty() && this->shipManager->HasEquipment(customEvent->beacon->equipmentReq) <= 0))
    {
        if (loc->visited)
        {
            return super(loc);
        }
        tooltip = customEvent->beacon->undiscoveredTooltip;
        hideVanillaLabel = customEvent->beacon->hideVanillaLabel;
    }
    else if (loc->visited)
    {
        tooltip = customEvent->beacon->visitedTooltip;
    }
    else
    {
        tooltip = customEvent->beacon->unvisitedTooltip;
    }

    if (tooltip.data.empty())
    {
        if (hideVanillaLabel)
        {
            LocLabelValues locValues;

            locValues.questLoc = loc->questLoc;
            locValues.beacon = loc->beacon;
            locValues.repair = loc->event->repair;
            locValues.pStore = loc->event->pStore;
            locValues.store = loc->event->store;
            locValues.distressBeacon = loc->event->distressBeacon;

            loc->questLoc = false;
            loc->beacon = loc->beacon && loc->visited;
            loc->event->repair = false;
            loc->event->pStore = loc->visited ? locValues.pStore : nullptr;
            loc->event->store = false;
            loc->event->distressBeacon = false;

            auto ret = super(loc);

            loc->questLoc = locValues.questLoc;
            loc->beacon = locValues.beacon;
            loc->event->repair = locValues.repair;
            loc->event->pStore = locValues.pStore;
            loc->event->store = locValues.store;
            loc->event->distressBeacon = locValues.distressBeacon;

            return ret;
        }
        else
        {
            return super(loc);
        }
    }

    std::string retStr = tooltip.GetText();

    auto lib = G_->GetTextLibrary();

    if (loc->nebula)
    {
        if (this->bNebulaMap)
        {
            retStr += " \n" + lib->GetText("map_nebula_fleet_loc");
        }
        else
        {
            retStr += " \n" + lib->GetText("map_nebula_loc");
        }
    }

    if (!this->bMapRevealed && (!loc->known || !this->shipManager->HasAugmentation("ADV_SCANNERS")))
        return retStr;

    int env = loc->event->environment;

    // TODO: Switch anyone, or maybe at least some elses?
    if (env == 1)
    {
        retStr += " \n" + lib->GetText("map_asteroid_loc");
    }
    if (env == 2)
    {
        retStr += " \n" + lib->GetText("map_sun_loc");
    }
    if (env == 4)
    {
        retStr += " \n" + lib->GetText("map_ion_loc");
    }
    if (env == 5)
    {
        retStr += " \n" + lib->GetText("map_pulsar_loc");
    }

    if (env != 6 || loc->boss)
    {
        return retStr;
    }

    if (loc->dangerZone)
    {
        retStr += " \n" + lib->GetText("map_pds_fleet");
    }
    else
    {
        retStr += " \n" + lib->GetText("map_pds_loc");
    }

    return retStr;
}

HOOK_METHOD(StarMap, GenerateNebulas, (std::vector<std::string>& names) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::GenerateNebulas -> Begin (CustomEvents.cpp)\n")
    if (names.size() > locations.size())
    {
        names.resize(locations.size());
    }

    super(names);

    CustomSector* customSector = CustomEventsParser::GetInstance()->GetCurrentCustomSector(this);

    if (customSector && customSector->removeFirstBeaconNebula)
    {
        if (currentLoc->nebula)
        {
            currentLoc->nebula = false;
            currentLoc->event->environment = 0;
            currentLoc->event->statusEffects.erase(
                std::remove_if(
                    currentLoc->event->statusEffects.begin(),
                    currentLoc->event->statusEffects.end(),
                    [](const StatusEffect& item) { return item.system == 7; }),
                currentLoc->event->statusEffects.end());
        }
    }
}


HOOK_METHOD(StarMap, StartSecretSector, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::StartSecretSector -> Begin (CustomEvents.cpp)\n")
    // Close store window to prevent crashes.
    TabbedWindow& storeScreens = G_->GetWorld()->commandGui->storeScreens;
    if (storeScreens.currentTab >= 0 && storeScreens.currentTab < storeScreens.windows.size() && storeScreens.windows[storeScreens.currentTab])
    {
        storeScreens.Close();
    }
    storeScreens.bOpen = false;

    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(currentLoc->event->eventName);

    if (customEvent && !customEvent->secretSectorWarp.empty())
    {
        bSecretSector = true;
        Sector *newSector = new Sector();

        newSector->description = G_->GetEventGenerator()->GetSpecificSector(customEvent->secretSectorWarp);

        currentSector = newSector;
    }
    else
    {
        super();
    }
}

// boss is the last thing saved/loaded so we do stuff after for it to be at the end

HOOK_METHOD(BossShip, LoadBoss, (int fh) -> void)
{
    LOG_HOOK("HOOK_METHOD -> BossShip::LoadBoss -> Begin (CustomEvents.cpp)\n")
    super(fh);

    EventGenerator* eventGenerator = G_->GetEventGenerator();

    int n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        std::string eventName = FileHelper::readString(fh);
        auto it = eventGenerator->events.find(eventName);
        if (it != eventGenerator->events.end())
        {
            eventGenerator->usedEvents[it->first] = it->second;
            eventGenerator->events.erase(it);
        }
    }
}

HOOK_METHOD(BossShip, SaveBoss, (int fh) -> void)
{
    LOG_HOOK("HOOK_METHOD -> BossShip::SaveBoss -> Begin (CustomEvents.cpp)\n")
    super(fh);

    EventGenerator* eventGenerator = G_->GetEventGenerator();

    FileHelper::writeInt(fh, eventGenerator->usedEvents.size());
    for (auto i : eventGenerator->usedEvents)
    {
        FileHelper::writeString(fh, i.first);
    }
}

static std::string sectorChange = "";

HOOK_METHOD(StarMap, SaveGame, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::SaveGame -> Begin (CustomEvents.cpp)\n")

    // Delete saved quests that are no longer there (completed or fleet overtaken)
    for (auto it = addedQuests.begin(); it != addedQuests.end(); )
    {
        if (it->second < 0 || it->second >= locations.size())
        {
            it = addedQuests.erase(it);
            continue;
        }

        Location *loc = locations[it->second];
        if (loc != currentLoc && (!loc->questLoc || loc->visited > 0))
        {
            it = addedQuests.erase(it);
            continue;
        }

        ++it;
    }

    FileHelper::writeString(file, currentSector->description.type);
    super(file);
}

HOOK_METHOD(StarMap, LoadGame, (int file) -> Location*)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::LoadGame -> Begin (CustomEvents.cpp)\n")
    std::string sectorName = FileHelper::readString(file);
    sectorChange = sectorName;
    forceSectorChoice = sectorName;
    Location* ret = super(file);
    sectorChange = "";
    return ret;
}


HOOK_METHOD(StarMap, NewGame, (bool unk) -> Location*)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::NewGame -> Begin (CustomEvents.cpp)\n")
    bSecretSector = false;
    pursuitDelay = 0;
    reversedPath = false;

    return super(unk);
}

HOOK_METHOD(StarMap, GenerateMap, (bool tutorial, bool seed) -> LocationEvent*)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::GenerateMap -> Begin (CustomEvents.cpp)\n")
    if (!sectorChange.empty() && bSecretSector)
    {
        Sector *newSector = new Sector();

        newSector->description = G_->GetEventGenerator()->GetSpecificSector(sectorChange);

        currentSector = newSector;
    }

    return super(tutorial, seed);
}


static std::string replaceGameOverText = "";
static std::string replaceGameOverCreditsText = "";
static bool shouldReplaceCreditsText = false;
static bool shouldReplaceBackground = false;
static std::string replaceCreditsBackground = "";
std::string replaceCreditsMusic = "";

HOOK_METHOD(GameOver, OpenText, (const std::string& text) -> void)
{
    LOG_HOOK("HOOK_METHOD -> GameOver::OpenText -> Begin (CustomEvents.cpp)\n")
    if (!replaceGameOverText.empty())
    {
        super(replaceGameOverText);
        replaceGameOverText = "";
    }
    else
    {
        super(text);
    }
}

HOOK_METHOD(CommandGui, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::OnLoop -> Begin (CustomEvents.cpp)\n")
    super();
}

static bool blockScrapCollected = false;
static bool blockScrapAugments = false;

HOOK_METHOD(ScoreKeeper, AddScrapCollected, (int scrap) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::AddScrapCollected -> Begin (CustomEvents.cpp)\n")
    if (blockScrapCollected) return;

    super(scrap);
}

HOOK_METHOD(ShipManager, ModifyScrapCount, (int scrap, bool income) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ModifyScrapCount -> Begin (CustomEvents.cpp)\n")
    if (blockScrapAugments) income = false;
    super(scrap, income);
}

HOOK_METHOD(WorldManager, ModifyResources, (LocationEvent *event) -> LocationEvent*)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::ModifyResources -> Begin (CustomEvents.cpp)\n")
    if (event->gap_ex_cleared) return super(event);

    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(event->eventName);

    if (customEvent)
    {
        if (customEvent->disableScrapScore)
        {
            blockScrapCollected = true;
        }
        if (customEvent->disableScrapAugments)
        {
            blockScrapAugments = true;
        }
    }

    LocationEvent *ret = super(event);

    blockScrapCollected = false;
    blockScrapAugments = false;

    //Location *location = starMap.currentLoc;
    //if (location->visited > 1 && !location->boss && !location->dangerZone)
    //{
    //    if (location->event == event) return ret;
    //}

    if (customEvent)
    {
        for (auto i : customEvent->removeItems)
        {
            playerShip->shipManager->RemoveItem(i);
        }

        if (!customEvent->variables.empty())
        {
            VariableModifier::ApplyVariables(customEvent->variables, playerShip->shipManager);
        }

        if (customEvent->gameOver.enabled)
        {
            if (customEvent->gameOver.victory)
            {
                G_->GetSoundControl()->StopPlaylist(100);
                if (!customEvent->gameOver.sound.empty())
                {
                    G_->GetSoundControl()->PlaySoundMix(customEvent->gameOver.sound, -1.f, false);
                }
                replaceGameOverText = customEvent->gameOver.text;
                replaceGameOverCreditsText = customEvent->gameOver.creditsText;
                replaceCreditsBackground = G_->GetEventGenerator()->GetImageFromList(customEvent->gameOver.creditsBackground);
                replaceCreditsMusic = customEvent->gameOver.creditsMusic;

                G_->GetScoreKeeper()->SetVictory(true);
                hs_log_file("Event victory: Set custom victory type to %s\n", customEvent->gameOver.ach.c_str());
                CustomShipUnlocks::instance->setCustomVictoryType = customEvent->gameOver.ach;
                G_->GetAchievementTracker()->SetVictoryAchievement();
                commandGui->gameover = true;
                commandGui->Victory();
                G_->GetScoreKeeper()->Save(true);
            }
            else
            {
                if (!customEvent->gameOver.sound.empty())
                {
                    G_->GetSoundControl()->StopPlaylist(100);
                    G_->GetSoundControl()->PlaySoundMix(customEvent->gameOver.sound, -1.f, false);
                }
                replaceGameOverText = customEvent->gameOver.text;

                G_->GetScoreKeeper()->SetVictory(false);
                commandGui->gameover = true;
                commandGui->CheckGameover();
            }
        }

        if (!customEvent->clearJumpEvents.empty())
        {
            for (std::string &name : customEvent->clearJumpEvents)
            {
                if (!name.empty())
                {
                    jumpEventQueue.erase(std::remove_if(jumpEventQueue.begin(), jumpEventQueue.end(),
                                         [&name](JumpEvent& obj) { return obj.label == name; }),
                                         jumpEventQueue.end());
                }
                else
                {
                    jumpEventQueue.clear();
                }
            }
        }

        if (!customEvent->jumpEvents.empty())
        {
            for (JumpEvent &jumpEvent : customEvent->jumpEvents)
            {
                jumpEventQueue.push_back(jumpEvent);
            }
            std::stable_sort(jumpEventQueue.begin(), jumpEventQueue.end(),
            [](const JumpEvent &a, const JumpEvent &b) -> bool
            {
                return a.priority > b.priority;
            });
        }

        if (!customEvent->clearDeathEvents.empty())
        {
            for (std::string &name : customEvent->clearDeathEvents)
            {
                if (!name.empty())
                {
                    deathEventQueue.erase(std::remove_if(deathEventQueue.begin(), deathEventQueue.end(),
                                          [&name](DeathEvent& obj) { return obj.label == name; }),
                                          deathEventQueue.end());
                }
                else
                {
                    deathEventQueue.clear();
                }
            }
        }

        if (!customEvent->deathEvents.empty())
        {
            for (DeathEvent &deathEvent : customEvent->deathEvents)
            {
                deathEventQueue.push_back(deathEvent);
            }
            std::stable_sort(deathEventQueue.begin(), deathEventQueue.end(),
            [](const DeathEvent &a, const DeathEvent &b) -> bool
            {
                return a.priority > b.priority;
            });
        }

        if (customEvent->goToFlagship)
        {
            GoToFlagship(customEvent->goToFlagshipBase, customEvent->goToFlagshipFleet);
        }

        if (!customEvent->transformRace.second.empty() && G_->GetCrewFactory()->playerCrew > 0)
        {
            if (lastSelectedCrewSeed == -1) lastSelectedCrewSeed = random32();

            CrewBlueprint crewBlue = playerShip->shipManager->SelectRandomCrew(lastSelectedCrewSeed, customEvent->transformRace.first);

            // Select the race now for consistent seeding with the event box generation.
            CrewBlueprint newBlueprint = G_->GetBlueprints()->GetCrewBlueprint(customEvent->transformRace.second);
            std::string newSpecies = newBlueprint.name;

            CrewMember* crew = playerShip->shipManager->FindCrew(&crewBlue);
            if (crew != nullptr)
            {
                auto ex = CM_EX(crew);
                ex->originalRace = newSpecies;
                ex->TransformRace(newSpecies);
            }
        }

        for (auto& triggeredEvent: customEvent->clearTriggeredEvents)
        {
            TriggeredEvent::DestroyEvent(triggeredEvent);
        }

        for (auto& triggeredEvent: customEvent->triggeredEvents)
        {
            TriggeredEvent::NewEvent(&TriggeredEventDefinition::defs.at(triggeredEvent));
        }

        for (auto& triggeredEvent: customEvent->triggeredEventModifiers)
        {
            triggeredEvent.ApplyModifier();
        }

        if (!customEvent->replaceSector.targetSector.empty())
        {
            ReplaceSector(customEvent->replaceSector);
        }
    }

    return ret;
}

HOOK_METHOD(TextLibrary, GetText, (const std::string& name, const std::string& lang) -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> TextLibrary::GetText -> Begin (CustomEvents.cpp)\n")
    if (!shouldReplaceCreditsText || replaceGameOverCreditsText.empty() || name != "credit_victory") return super(name, lang);

    return super(replaceGameOverCreditsText, lang);
}

HOOK_METHOD(ResourceControl, GetImageId, (const std::string& name) -> GL_Texture*)
{
    LOG_HOOK("HOOK_METHOD -> ResourceControl::GetImageId -> Begin (CustomEvents.cpp)\n")
    if (shouldReplaceBackground && !replaceCreditsBackground.empty() && name == "stars/bg_darknebula.png")
    {
        return super(replaceCreditsBackground);
    }

    return super(name);
}

// I'm sorry, IDK C++ better to know what to write instead of globals :anguish:
float fadeIn;
float scrollEnd;
float crewStringCutOff;
HOOK_METHOD(CreditScreen, Start, (const std::string& shipName, const std::vector<std::string>& crewNames) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CreditScreen::Start -> Begin (CustomEvents.cpp)\n")
    auto defaultVictory = CustomEventsParser::GetInstance()->defaultVictory;
    if (defaultVictory)
    {
        if (replaceCreditsBackground.empty() && !defaultVictory->gameOver.creditsBackground.empty())
        {
            replaceCreditsBackground = G_->GetEventGenerator()->GetImageFromList(defaultVictory->gameOver.creditsBackground);
        }
        if (replaceGameOverCreditsText.empty() && !defaultVictory->gameOver.creditsText.empty())
        {
            replaceGameOverCreditsText = defaultVictory->gameOver.creditsText;
        }
    }


    // Setting if started in-game or from menu:
    if (shipName.empty())
    {
        scroll = 0.1f;
    }
    else
    {
        fadeIn = 1.f;
        pausing = -scrollDelay;
    }


    // Calculate when the credits stop:
    scrollEnd = 750.f;
    for (const auto &creditText : creditTextValues)
    {
        scrollEnd += creditText.spacing;
    }
    for (const auto &creditFile : creditFileNames)
    {
        scrollEnd += creditFile.spacing;
    }
    for (const auto &creditFinishText : creditFinishTextValues)
    {
        scrollEnd += creditFinishText.spacing;
    }


    // Run original code:
    super(shipName, crewNames);


    // select background image:
    bg = G_->GetResources()->GetImageId(replaceCreditsBackground.empty() ? "stars/bg_darknebula.png" : replaceCreditsBackground);


    // Parse crewString with patch:
    std::string crewlistAnd = G_->GetTextLibrary()->GetText("crewlist_and");
    std::string crewlistComma = G_->GetTextLibrary()->GetText("crewlist_comma");
    std::string crewlistMore = G_->GetTextLibrary()->GetText("crewlist_more");

    std::string newCrewString;
    int totalLength = 0;

    if (!(crewNames.size() <= 1))
    {
        for (size_t i = 0; i < crewNames.size(); ++i)
        {
            newCrewString += crewlistComma + crewNames[i];
            totalLength += crewNames[i].length() + crewlistComma.length();
            if (totalLength > 140) 
            {
                newCrewString += crewlistMore;
                break;
            }
        }

        newCrewString.erase(0, crewlistComma.length());
        if (!(newCrewString.find(crewlistMore) != std::string::npos))
        {
            newCrewString.replace(newCrewString.rfind(crewlistComma), 2, crewlistAnd);
        }

        crewString = newCrewString;
    }


    // Calculate crew names cut out:
    Pointf dynamicCutOff = freetype::easy_measurePrintLines(18, 0, 0, 720, crewString);
    crewStringCutOff = dynamicCutOff.x + 50;
}

HOOK_METHOD(CreditScreen, Done, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CreditScreen::Done -> Begin (CustomEvents.cpp)\n")

    bool ret;
    if (CustomOptionsManager::GetInstance()->altCreditSystem.currentValue) 
    {
        ret = (scroll <= -scrollEnd) ? true : false;
    }
    else
    {
        ret = super();
    }

    if (ret)
    {
        replaceCreditsBackground = "";
        replaceGameOverCreditsText = "";
    }

    return ret;
}

HOOK_METHOD(CreditScreen, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CreditScreen::OnRender -> Begin (CustomEvents.cpp)\n")

    shouldReplaceBackground = true;
    shouldReplaceCreditsText = true;

    if (CustomOptionsManager::GetInstance()->altCreditSystem.currentValue) 
    {
        /* ----- Resources ----- */
        std::string creditTextThankShip = G_->GetTextLibrary()->GetText("thank_ship");
        std::string creditTextThankCrew = G_->GetTextLibrary()->GetText("thank_crew");
        std::string creditTextThankAi = G_->GetTextLibrary()->GetText("thank_ai");
        std::string creditTextVictory = G_->GetTextLibrary()->GetText("credit_victory");

        /* ----- Positions ----- */
        int creditTextCentered = 640; // G_->GetResources()->screenWidth / 2
        int creditTextLeft = 256; // G_->GetResources()->screenWidth / 5
        int creditTextRight = 1024; // G_->GetResources()->screenHeight / 5 * 2
        int creditNamesHorizontal;
        int creditTextStartHeight = 144; // G_->GetResources()->screenHeight / 5
        int xmlCreditTextStartHeight = 740;
        int currentHeight = xmlCreditTextStartHeight;

        /* ----- Colors -----*/
        GL_Color colorWhite;
        colorWhite.r = 1.f;
        colorWhite.g = 1.f;
        colorWhite.b = 1.f;
        colorWhite.a = 1.f;
        GL_Color colorGray;
        colorGray.r = 0.5f;
        colorGray.g = 0.5f;
        colorGray.b = 0.5f;
        colorGray.a = 1.f;

        /* ----- Visuals -----*/
        float gameSpeed = G_->GetCFPS()->GetSpeedFactor();
        float trueScrollSpeed = gameSpeed * 3.5 * scrollSpeed;
        
        fadeIn += gameSpeed * 3.5 * -0.025f * fadeInSpeed;

        if (scroll == 0.f && pausing > -scrollDelay) {
            pausing -= trueScrollSpeed;
        }
        else if (std::max(scroll, -pausePosition) ==  -pausePosition && pausing > -pauseDuration) {
            pausing -= trueScrollSpeed;
        }
        else {
            scroll -= trueScrollSpeed;
        }

        /* ----- Rendering -----*/
        // Background rendering
        G_->GetResources()->RenderImage(bg, 0, 0, 0, colorGray, 1.f, false);
        CSurface::GL_SetColor(colorWhite);
        // Hardcoded Texts
        if (!shipName.empty()) {
            int yPos = static_cast<int>(creditTextStartHeight + scroll);
            if (yPos > -100 && yPos < 800) {
                freetype::easy_printNewlinesCentered(14, creditTextCentered, yPos, 1200, creditTextThankShip);
            }
            yPos += 40;
            if (yPos > -100 && yPos < 800) {
                freetype::easy_printNewlinesCentered(20, creditTextCentered, yPos, 1200, shipName);
            }
            if (!crewString.empty()) {
                yPos += 80;
                if (yPos > -720 && yPos < 800) {
                    freetype::easy_printNewlinesCentered(14, creditTextCentered, yPos, 1200, creditTextThankCrew);
                }
                yPos += 40;
                if (yPos > -crewStringCutOff && yPos < 800) {
                    freetype::easy_printNewlinesCentered(18, creditTextCentered, yPos, 720, crewString);
                }
            } else {
                yPos += 80;
                if (yPos > -100 && yPos < 800) {
                    freetype::easy_printNewlinesCentered(14, creditTextCentered, yPos, 1200, creditTextThankAi);
                }
            }
            yPos += 246;
            if (yPos > -100 && yPos < 800) {
                freetype::easy_printNewlinesCentered(14, creditTextCentered, yPos, 750, creditTextVictory);
            }
        }
        // xml Texts
        for (const auto& creditText : creditTextValues) {
            if ((currentHeight + scroll) > -creditText.cutOff && (currentHeight + scroll) < 800) {
                freetype::easy_printNewlinesCentered(creditText.font, creditText.horizontal, static_cast<int>(currentHeight + scroll), creditText.lineLenght, G_->GetTextLibrary()->GetText(creditText.text, G_->GetTextLibrary()->currentLanguage));
            }
            currentHeight += creditText.spacing;
        }
        // credit.txt Names
        int nameCount = 0;
        for (const auto& creditFile : creditFileNames) {
            if (nameCount == 0) {
                creditNamesHorizontal = creditTextLeft;
            } else {
                creditNamesHorizontal = (nameCount == 1) ? creditTextCentered : creditTextRight;
            }
            if ((currentHeight + scroll) > -creditFile.cutOff && (currentHeight + scroll) < 800) {
                freetype::easy_printNewlinesCentered(creditNamesFontSize, creditNamesHorizontal, static_cast<int>(currentHeight + scroll), 1280, creditFile.names);
            }
            nameCount++;
            if (nameCount == 3) {
                nameCount = 0;
                currentHeight += creditFile.spacing;
            }
        }
        // xml Finish Texts
        for (const auto& creditFinishText : creditFinishTextValues) {
            if ((currentHeight + scroll) > -creditFinishText.cutOff && (currentHeight + scroll) < 800) {
                freetype::easy_printNewlinesCentered(creditFinishText.font, creditFinishText.horizontal, static_cast<int>(currentHeight + scroll), creditFinishText.lineLenght, G_->GetTextLibrary()->GetText(creditFinishText.text, G_->GetTextLibrary()->currentLanguage));
            }
            currentHeight += creditFinishText.spacing;
        }
        // Text Fading
        if (fadeIn > 0) {
            G_->GetResources()->RenderImage(bg, 0, 0, 0, colorGray, fadeIn, false);
            CSurface::GL_SetColor(colorWhite);
        }
        
        /* ----- Auto Stop -----*/
        Done();
    } 
    else
    {
        super();
    }

    shouldReplaceCreditsText = false;
    shouldReplaceBackground = false;
}

HOOK_METHOD(StarMap, NewGame, (bool unk) -> Location*)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::NewGame -> Begin (CustomEvents.cpp)\n")
    bossDefeated = false;
    delete restartMusicTimer;
    restartMusicTimer = nullptr;

    // jumpEvent
    jumpEventQueue.clear();

    // deathEvent
    deathEventQueue.clear();

    // eventAlias
    eventAliases.clear();

    // regeneratedBeacons
    regeneratedBeacons.clear();

    // renamedBeacons
    renamedBeacons.clear();

    // savedPriorityEventReq
    savedPriorityEventReq.clear();

    // backgroundObjects;
    CustomBackgroundObjectManager::instance->backgroundObjects.clear();

    // eventButtons
    EventButtonManager::instance->buttons.clear();

    // playerVariables
    playerVariables.clear();
    if (SeedInputBox::seedsEnabled)
    {
        Global::questSeed = (Global::currentSeed^0x282b2048) & 0x7fffffff; // same operation for other questSeed stuff but without location and using global seed.
    }
    VariableModifier::ApplyVariables(CustomEventsParser::GetInstance()->initialPlayerVars, G_->GetWorld()->playerShip->shipManager);

    // Game Over
    G_->GetWorld()->commandGui->alreadyWon = false;
    alreadyWonCustom = false;
    replaceGameOverText = "";
    replaceGameOverCreditsText = "";
    replaceCreditsBackground = "";
    replaceCreditsMusic = "";
    hs_log_file("New Game: Reset custom victory type to flagship\n");
    CustomShipUnlocks::instance->setCustomVictoryType = "flagship";

    return super(unk);
}

HOOK_METHOD(StarMap, LoadGame, (int fh) -> Location*)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::LoadGame -> Begin (CustomEvents.cpp)\n")
    bossDefeated = false;
    delete restartMusicTimer;
    restartMusicTimer = nullptr;

    // jumpEvent
    jumpEventQueue.clear();
    int n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        jumpEventQueue.emplace_back();
        JumpEvent &jumpEvent = jumpEventQueue.back();
        jumpEvent.event = FileHelper::readString(fh);
        jumpEvent.label = FileHelper::readString(fh);
        jumpEvent.loop = FileHelper::readInteger(fh);
        jumpEvent.priority = FileHelper::readInteger(fh);
    }

    // deathEvent
    deathEventQueue.clear();
    n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        deathEventQueue.emplace_back();
        DeathEvent &deathEvent = deathEventQueue.back();
        deathEvent.event = FileHelper::readString(fh);
        deathEvent.label = FileHelper::readString(fh);
        deathEvent.jumpClear = FileHelper::readInteger(fh);
        deathEvent.thisFight = FileHelper::readInteger(fh);
        deathEvent.priority = FileHelper::readInteger(fh);
    }

    // eventAlias
    eventAliases.clear();
    n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        std::string alias_name = FileHelper::readString(fh);
        EventAlias alias;
        alias.event = FileHelper::readString(fh);
        alias.jumpClear = FileHelper::readInteger(fh);
        alias.once = FileHelper::readInteger(fh);
        eventAliases[alias_name] = alias;
    }

    // regeneratedBeacons
    regeneratedBeacons.clear();
    n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        int idx = FileHelper::readInteger(fh);
        std::string eventName = FileHelper::readString(fh);
        int seed = FileHelper::readInteger(fh);
        regeneratedBeacons[idx] = std::pair<std::string,int>(eventName, seed);
    }

    // renamedBeacons
    renamedBeacons.clear();
    n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        int idx = FileHelper::readInteger(fh);
        renamedBeacons[idx] = FileHelper::readString(fh);
    }

    // savedPriorityEventReq
    savedPriorityEventReq.clear();
    n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        savedPriorityEventReq.push_back(FileHelper::readInteger(fh));
    }

    // backgroundObjects
    CustomBackgroundObjectManager::instance->backgroundObjects.clear();
    n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        int idx = FileHelper::readInteger(fh);
        std::vector<CustomBackgroundObject> &vec = CustomBackgroundObjectManager::instance->backgroundObjects[idx];
        int backgroundObjects_size = FileHelper::readInteger(fh);
        for (int j=0; j<backgroundObjects_size; ++j)
        {
            vec.emplace_back();
            vec.back().Load(fh);
        }
    }

    // eventButtons
    EventButtonManager::instance->Load(fh);

    // playerVariables
    playerVariables.clear();
    n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        std::string varName = FileHelper::readString(fh);
        int varValue = FileHelper::readInteger(fh);
        if (varValue != 0)
        {
            playerVariables[varName] = varValue;
            CustomAchievementTracker::instance->UpdateVariableAchievements(varName, varValue);
        }
    }

    // Game Over
    G_->GetWorld()->commandGui->alreadyWon = FileHelper::readInteger(fh);
    alreadyWonCustom = FileHelper::readInteger(fh);
    replaceGameOverText = FileHelper::readString(fh);
    replaceGameOverCreditsText = FileHelper::readString(fh);
    replaceCreditsBackground = FileHelper::readString(fh);
    replaceCreditsMusic = FileHelper::readString(fh);
    CustomShipUnlocks::instance->setCustomVictoryType = FileHelper::readString(fh);
    hs_log_file("Load Game: Set custom victory type to %s\n", CustomShipUnlocks::instance->setCustomVictoryType.c_str());

    return super(fh);
}

HOOK_METHOD(StarMap, SaveGame, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::SaveGame -> Begin (CustomEvents.cpp)\n")
    // jumpEvent
    FileHelper::writeInt(file, jumpEventQueue.size());
    for (JumpEvent &jumpEvent : jumpEventQueue)
    {
        FileHelper::writeString(file, jumpEvent.event);
        FileHelper::writeString(file, jumpEvent.label);
        FileHelper::writeInt(file, jumpEvent.loop);
        FileHelper::writeInt(file, jumpEvent.priority);
    }

    // deathEvent
    FileHelper::writeInt(file, deathEventQueue.size());
    for (DeathEvent &deathEvent : deathEventQueue)
    {
        FileHelper::writeString(file, deathEvent.event);
        FileHelper::writeString(file, deathEvent.label);
        FileHelper::writeInt(file, deathEvent.jumpClear);
        FileHelper::writeInt(file, deathEvent.thisFight);
        FileHelper::writeInt(file, deathEvent.priority);
    }

    // eventAlias
    FileHelper::writeInt(file, eventAliases.size());
    for (auto& i : eventAliases)
    {
        FileHelper::writeString(file, i.first);
        FileHelper::writeString(file, i.second.event);
        FileHelper::writeInt(file, i.second.jumpClear);
        FileHelper::writeInt(file, i.second.once);
    }

    // regeneratedBeacons
    FileHelper::writeInt(file, regeneratedBeacons.size());
    for (auto& i : regeneratedBeacons)
    {
        FileHelper::writeInt(file, i.first);
        FileHelper::writeString(file, i.second.first);
        FileHelper::writeInt(file, i.second.second);
    }

    // renamedBeacons
    FileHelper::writeInt(file, renamedBeacons.size());
    for (auto& i : renamedBeacons)
    {
        FileHelper::writeInt(file, i.first);
        if (i.first < locations.size() && locations[i.first]->event)
        {
            FileHelper::writeString(file, locations[i.first]->event->eventName);
        }
        else
        {
            FileHelper::writeString(file, i.second);
        }
    }

    // savedPriorityEventReq
    FileHelper::writeInt(file, savedPriorityEventReq.size());
    for (bool i : savedPriorityEventReq)
    {
        FileHelper::writeInt(file, i);
    }

    // backgroundObjects
    FileHelper::writeInt(file, CustomBackgroundObjectManager::instance->backgroundObjects.size());
    for (auto& i : CustomBackgroundObjectManager::instance->backgroundObjects)
    {
        FileHelper::writeInt(file, i.first);
        FileHelper::writeInt(file, i.second.size());
        for (auto& j : i.second)
        {
            j.Save(file);
        }
    }

    // eventButtons
    EventButtonManager::instance->Save(file);

    // playerVariables
    FileHelper::writeInt(file, playerVariables.size());
    for (auto& i : playerVariables)
    {
        FileHelper::writeString(file, i.first);
        FileHelper::writeInt(file, i.second);
    }

    // Game Over
    FileHelper::writeInt(file, G_->GetWorld()->commandGui->alreadyWon);
    FileHelper::writeInt(file, alreadyWonCustom);
    FileHelper::writeString(file, replaceGameOverText);
    FileHelper::writeString(file, replaceGameOverCreditsText);
    FileHelper::writeString(file, replaceCreditsBackground);
    FileHelper::writeString(file, replaceCreditsMusic);
    FileHelper::writeString(file, CustomShipUnlocks::instance->setCustomVictoryType);

    return super(file);
}

HOOK_METHOD(StarMap, Open, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::Open -> Begin (CustomEvents.cpp)\n")

    WorldManager *world = G_->GetWorld();

    auto it = jumpEventQueue.begin();
    while (it != jumpEventQueue.end())
    {
        CustomEventsParser::GetInstance()->LoadEvent(world, it->event, false, -1);
        if (it->loop)
        {
            ++it;
        }
        else
        {
            it = jumpEventQueue.erase(it);
        }

        if (world->commandGui->choiceBox.bOpen) return;
    }

    super();
}

HOOK_METHOD_PRIORITY(StarMap, Open, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> StarMap::Open -> Begin (CustomEvents.cpp)\n")
    if (!bOpen)
    {
        closeButton.SetActive(true);

        finalSectorChoice = -1;
        potentialSectorChoice = -1;

        int rng = random32();
        shipRotation[0] = rng % 360;
        rng = random32();
        shipRotation[1] = rng % 360;

        if (shipManager->fuel_count == 0)
        {
            hoverLoc = nullptr;
        }
        else
        {
            hoverLoc = currentLoc;
            targetBoxTimer.Start(0.f);
        }
        potentialLoc = nullptr;

        bOpen = true;
    }

    return;
}

static BossFleetPrevention bossFleetPrevention = BossFleetPrevention();
static bool inUpdateBoss = false;

HOOK_METHOD(StarMap, UpdateBoss, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::UpdateBoss -> Begin (CustomEvents.cpp)\n")
    inUpdateBoss = true;

    bossFleetPrevention.starMap = this;
    bossFleetPrevention.Set();

    super();

    bossFleetPrevention.Clear();

    inUpdateBoss = false;
}

HOOK_METHOD(StarMap, GenerateMap, (bool unk, bool seed) -> Location*)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::GenerateMap -> Begin (CustomEvents.cpp)\n")
    auto ret = super(unk, seed);

    if (!loadingMap)
    {
        for (auto i : locations)
        {
            if (!i->dangerZone && i->fleetChanging)
            {
                auto locEvent = i->event;
                auto customEvents = CustomEventsParser::GetInstance();
                auto customEvent = customEvents->GetCustomEvent(locEvent->eventName);

                if (customEvent && customEvent->preventBossFleet)
                {
                    i->fleetChanging = false;
                }
            }
        }
    }

    return ret;
}

HOOK_METHOD(StarMap, TurnIntoFleetLocation, (Location *loc) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::TurnIntoFleetLocation -> Begin (CustomEvents.cpp)\n")
    auto locEvent = loc->event;
    auto customEvents = CustomEventsParser::GetInstance();
    auto customEvent = customEvents->GetCustomEvent(locEvent->eventName);

    if (customEvent && customEvent->preventFleet && loc->visited < 1) return;

    if (!loadingMap) {
        if (!loc->visited && customEvent && customEvent->runFromFleet)
        {
            bool requireClosest = customEvent->runFromFleet == 1;
            int closestDistance = 9999;

            auto allowedDestinations = std::vector<Location*>();

            for (auto i : locations)
            {
                if (!i->beacon && !i->visited && (!i->dangerZone || bossFleetPrevention.fleetBlockedLocs.count(i)) && !i->newSector && !i->questLoc && !i->fleetChanging && i->nebula == loc->nebula && i != currentLoc && i != potentialLoc && !i->event->store && !i->event->repair)
                {
                    auto destinationEvent = customEvents->GetCustomEvent(i->event->eventName);

                    if (!(destinationEvent && destinationEvent->preventQuest))
                    {
                        if (requireClosest)
                        {
                            std::vector<Location*> path = Dijkstra(loc, i, false);
                            if (path.size() < closestDistance)
                            {
                                allowedDestinations.clear();
                                closestDistance = path.size();
                            }
                            if (path.size() <= closestDistance)
                            {
                                allowedDestinations.push_back(i);
                            }
                        }
                        else
                        {
                            allowedDestinations.push_back(i);
                        }
                    }
                }
            }
            if (allowedDestinations.size())
            {
                loc->questLoc = false;

                auto dest = allowedDestinations[random32()%allowedDestinations.size()];
                unsigned int seed = random32();
                dest->event = G_->GetEventGenerator()->GetBaseEvent(locEvent->eventName, worldLevel, false, seed);
                dest->questLoc = true;
                dest->visited = 0;

                if (inUpdateBoss)
                {
                    bossFleetPrevention.Clear();
                    bossFleetPrevention.Set();
                }

                auto destIt = std::find(locations.begin(), locations.end(), dest);
                addedQuests.push_back({"QUEST\t" + std::to_string(seed) + "\t" + locEvent->eventName, std::distance(locations.begin(), destIt)});
            }
        }
    }

    super(loc);
}

// Crew Removal Functions

static bool selectRandomCrew_allowNoSlot = false;
static bool selectRandomCrew_blockNoSlot = false;
static std::pair<float,float> selectRandomCrew_ignoreEssential = {-HUGE_VAL, HUGE_VAL};

HOOK_METHOD_PRIORITY(WorldManager, CreateLocation, -100, (Location *location) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WorldManager::CreateLocation -> Begin (CustomEvents.cpp)\n")
    LocationEvent *event = location->event;

    if (event)
    {
        CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(location);

        if (customEvent)
        {
            selectRandomCrew_allowNoSlot = customEvent->allowNoSlot;
            selectRandomCrew_blockNoSlot = customEvent->blockNoSlot;
            selectRandomCrew_ignoreEssential = customEvent->ignoreEssential;
        }
    }

    super(location);

    selectRandomCrew_allowNoSlot = false;
    selectRandomCrew_blockNoSlot = false;
    selectRandomCrew_ignoreEssential = {-HUGE_VAL, HUGE_VAL};
}

HOOK_METHOD_PRIORITY(WorldManager, UpdateLocation, -100, (LocationEvent *event) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WorldManager::UpdateLocation -> Begin (CustomEvents.cpp)\n")
    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(event->eventName);

    if (customEvent)
    {
        selectRandomCrew_allowNoSlot = customEvent->allowNoSlot;
        selectRandomCrew_blockNoSlot = customEvent->blockNoSlot;
        selectRandomCrew_ignoreEssential = customEvent->ignoreEssential;
    }

    super(event);

    selectRandomCrew_allowNoSlot = false;
    selectRandomCrew_blockNoSlot = false;
    selectRandomCrew_ignoreEssential = {-HUGE_VAL, HUGE_VAL};
}

HOOK_METHOD_PRIORITY(WorldManager, ModifyResources, -100, (LocationEvent *event) -> LocationEvent*)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WorldManager::ModifyResources -> Begin (CustomEvents.cpp)\n")
    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(event->eventName);

    bool old_allowNoSlot = selectRandomCrew_allowNoSlot;
    bool old_blockNoSlot = selectRandomCrew_blockNoSlot;
    std::pair<float,float> old_ignoreEssential = selectRandomCrew_ignoreEssential;

    if (customEvent)
    {
        selectRandomCrew_allowNoSlot = customEvent->allowNoSlot;
        selectRandomCrew_blockNoSlot = customEvent->blockNoSlot;
        selectRandomCrew_ignoreEssential = customEvent->ignoreEssential;
    }

    LocationEvent *ret = super(event);

    selectRandomCrew_allowNoSlot = old_allowNoSlot;
    selectRandomCrew_blockNoSlot = old_blockNoSlot;
    selectRandomCrew_ignoreEssential = old_ignoreEssential;

    return ret;
}

std::vector<CrewMember*> HS_GetEligibleCrewList(int iShipId, const std::vector<std::string> &blueprintList, bool includeNoSlot)
{
    std::vector<CrewMember*> eligibleCrewList = std::vector<CrewMember*>();
    std::vector<CrewMember*> crewList = std::vector<CrewMember*>();
    G_->GetCrewFactory()->GetCrewList(&crewList, iShipId, false);

    for (CrewMember* crew: crewList)
    {
        bool isRace = blueprintList.empty();
        if (!isRace)
        {
            for (const std::string &i : blueprintList)
            {
                if (crew->species == i)
                {
                    isRace = true;
                    break;
                }
            }
        }

        if (isRace)
        {
            if (!includeNoSlot)
            {
                CrewMember_Extend *ex = CM_EX(crew);
                bool noSlot = ex->noSlot;
                CustomCrewManager *customCrew = CustomCrewManager::GetInstance();

                if (customCrew->IsRace(crew->species))
                {
                    const CrewDefinition *def = customCrew->GetDefinition(crew->species);
                    ex->CalculateStat(CrewStat::NO_SLOT, def, &noSlot);
                }

                if (noSlot)
                {
                    continue;
                }
            }
            eligibleCrewList.push_back(crew);
        }
    }

    return eligibleCrewList;
}

std::vector<CrewMember*> HS_GetEligibleCrewList(int iShipId, bool includeNoSlot)
{
    return HS_GetEligibleCrewList(iShipId, std::vector<std::string>{}, includeNoSlot);
}

std::vector<CrewMember*> HS_GetEligibleCrewList(int iShipId, std::string &racePref, bool includeNoSlot)
{
    if (racePref == "random") return HS_GetEligibleCrewList(iShipId, includeNoSlot);
    return HS_GetEligibleCrewList(iShipId, std::vector<std::string>{racePref}, includeNoSlot);
}

std::vector<std::string> HS_GetRecursiveBlueprintList(std::string &bp)
{
    std::vector<std::string> blueprintList = G_->GetBlueprints()->GetBlueprintList(bp);

    for (int i=0; i<blueprintList.size(); ++i)
    {
        std::vector<std::string> blueprintList2 = G_->GetBlueprints()->GetBlueprintList(blueprintList[i]);
        for (auto j : blueprintList2)
        {
            blueprintList.push_back(j);
        }
    }

    return blueprintList;
}

std::vector<CrewMember*> HS_GetRandomCrewList(int iShipId, std::string &racePref, bool randomRaceAllowed, bool noSlotAllowed, bool noSlotForbidden)
{
    noSlotForbidden |= noSlotAllowed;

    std::vector<std::string> blueprintList = HS_GetRecursiveBlueprintList(racePref);

    std::vector<CrewMember*> eligibleCrewList;
    if (!blueprintList.empty())
    {
        // List race
        eligibleCrewList = HS_GetEligibleCrewList(0, blueprintList, noSlotAllowed);
        if (eligibleCrewList.empty() && !noSlotForbidden) eligibleCrewList = HS_GetEligibleCrewList(0, blueprintList, true);
    }
    else if (!racePref.empty())
    {
        // Fixed race
        eligibleCrewList = HS_GetEligibleCrewList(0, racePref, noSlotAllowed);
        if (eligibleCrewList.empty() && !noSlotForbidden) eligibleCrewList = HS_GetEligibleCrewList(0, racePref, true);
    }
    else
    {
        randomRaceAllowed = true;
    }
    if (eligibleCrewList.empty() && randomRaceAllowed)
    {
        // No race
        eligibleCrewList = HS_GetEligibleCrewList(0, noSlotAllowed);
        if (eligibleCrewList.empty() && !noSlotForbidden) eligibleCrewList = HS_GetEligibleCrewList(0, true);
    }

    return eligibleCrewList;
}

HOOK_METHOD(StarMap, GenerateMap, (bool tutorial, bool seed) -> Location*)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::GenerateMap -> Begin (CustomEvents.cpp)\n")
    G_->GetWorld()->lastLocationEvent = nullptr;
    return super(tutorial, seed);
}

HOOK_METHOD(WorldManager, CheckRequirements, (LocationEvent *event, bool hidden) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CheckRequirements -> Begin (CustomEvents.cpp)\n")
    bool ret = super(event, hidden);

    if (ret && event)
    {
        if (lastLocationEvent && !event->stuff.steal && !lastLocationEvent->stuff.steal)
        {
            // fix a vanilla bug that player can select a choice that requires more resources than they have when two costing events are back to back
            // this is because requirements check is done before the cost of the previous event is applied to the resources balance
            int fuel_cost = event->stuff.fuel + lastLocationEvent->stuff.fuel;
            if (fuel_cost < 0 && playerShip->shipManager->fuel_count < fuel_cost * -1)
                return false;

            int missiles_cost = event->stuff.missiles + lastLocationEvent->stuff.missiles;
            if (missiles_cost < 0 && playerShip->shipManager->GetMissileCount() < missiles_cost * -1)
                return false;

            int drones_cost = event->stuff.drones + lastLocationEvent->stuff.drones;
            if (drones_cost < 0 && playerShip->shipManager->GetDroneCount() < drones_cost * -1)
                return false;

            int scrap_cost = event->stuff.scrap + lastLocationEvent->stuff.scrap;
            if (scrap_cost < 0 && playerShip->shipManager->currentScrap < scrap_cost * -1)
                return false;
        }
        
        CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(event->eventName);

        if (customEvent)
        {
            if (customEvent->choiceRequiresCrew)
            {
                if (event->stuff.crew < 0)
                {
                    std::vector<CrewMember*> eligibleCrewList = HS_GetRandomCrewList(0, event->stuff.crewType, false, customEvent->allowNoSlot, customEvent->blockNoSlot);
                    if (eligibleCrewList.empty()) return false;
                }
                if (!customEvent->transformRace.second.empty())
                {
                    std::vector<CrewMember*> eligibleCrewList = HS_GetRandomCrewList(0, customEvent->transformRace.first, false, customEvent->allowNoSlot, customEvent->blockNoSlot);
                    if (eligibleCrewList.empty()) return false;
                }
            }
        }
        else if (event->stuff.crew < 0 && CustomOptionsManager::GetInstance()->defaults.choiceRequiresCrew)
        {
            std::vector<CrewMember*> eligibleCrewList = HS_GetRandomCrewList(0, event->stuff.crewType, false, false, false);
            if (eligibleCrewList.empty()) return false;
        }
    }

    return ret;
}

void HS_ShuffleSortCrewList(std::vector<CrewMember*> &crewList, float minPriority, float maxPriority)
{
    // Not super efficient but we're not going to call this function constantly
    // This will be useful when we want something that can pick out multiple crew.
    std::random_shuffle(crewList.begin(), crewList.end(), [](int i){return random32()%i;});
    if (minPriority < maxPriority)
    {
        std::stable_sort(crewList.begin(), crewList.end(),
        [minPriority,maxPriority](const CrewMember *a, const CrewMember *b) -> bool
        {
            float aRet = 0.f;
            float bRet = 0.f;
            CrewMember_Extend *aex = CM_EX(a);
            CrewMember_Extend *bex = CM_EX(b);
            CrewDefinition *adef = aex->GetDefinition();
            CrewDefinition *bdef = bex->GetDefinition();
            if (adef) aRet = aex->CalculateStat(CrewStat::ESSENTIAL, adef);
            if (bdef) bRet = bex->CalculateStat(CrewStat::ESSENTIAL, bdef);

            return std::max(aRet,minPriority) < std::min(bRet,maxPriority);
        });
    }
}

HOOK_METHOD_PRIORITY(ShipManager, SelectRandomCrew, 100, (int seed, std::string &racePref) -> CrewBlueprint)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::SelectRandomCrew -> Begin (CustomEvents.cpp)\n")
    std::string species = racePref;
    CrewBlueprint bp = super(seed, species); // species is not const?!

    species = racePref;

    std::vector<CrewMember*> eligibleCrewList = HS_GetRandomCrewList(0, racePref, true, selectRandomCrew_allowNoSlot, selectRandomCrew_blockNoSlot);

    if (!eligibleCrewList.empty())
    {
        if (seed != -1) srandom32(seed);
        HS_ShuffleSortCrewList(eligibleCrewList, selectRandomCrew_ignoreEssential.first, selectRandomCrew_ignoreEssential.second);

        bp = eligibleCrewList[0]->blueprint;
    }

    return bp;
}

HOOK_METHOD(ShipManager, SelectRandomCrew, (int seed, std::string &racePref) -> CrewBlueprint)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::SelectRandomCrew -> Begin (CustomEvents.cpp)\n")
    if (this->CountCrew(false) == 0 && this->bAutomated)
    {
        CrewMember* crew;
        crew = this->AddCrewMemberFromString(G_->GetTextLibrary()->GetText("autoship_dismissed_crew_name"), "human", false, 0, false, false);
    }
    return super(seed, racePref);
}

HOOK_METHOD_PRIORITY(WorldManager, CreateLocation, 100, (Location *location) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WorldManager::CreateLocation -> Begin (CustomEvents.cpp)\n")
    LocationEvent *event = location->event;

    if (event && event->stuff.crew < 0)
    {
        ShipManager *ship = G_->GetShipManager(0);
        if (ship && ship->CountCrew(false) == 0)
        {
            event->stuff.crew = 0;
            event->reward.crew = 0;
        }
    }

    super(location);
}

HOOK_METHOD_PRIORITY(WorldManager, UpdateLocation, 100, (LocationEvent *event) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WorldManager::UpdateLocation -> Begin (CustomEvents.cpp)\n")

    if (event->stuff.crew < 0)
    {
        ShipManager *ship = G_->GetShipManager(0);
        if (ship && ship->CountCrew(false) == 0)
        {
            event->stuff.crew = 0;
            event->reward.crew = 0;
        }
    }

    super(event);
}

HOOK_METHOD_PRIORITY(ShipManager, FindCrew, 9999, (const CrewBlueprint* bp) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::FindCrew -> Begin (CustomEvents.cpp)\n")
    std::vector<CrewMember*> crewList = std::vector<CrewMember*>();
    G_->GetCrewFactory()->GetCrewList(&crewList, 0, false);

    for (CrewMember* crew: crewList)
    {
        if (crew->blueprint.crewNameLong.isLiteral != bp->crewNameLong.isLiteral) continue;
        if (crew->blueprint.crewNameLong.data != bp->crewNameLong.data) continue;
        if (crew->blueprint.colorChoices != bp->colorChoices) continue;
        if (crew->blueprint.male != bp->male) continue;
        if (crew->blueprint.name != bp->name) continue;
        return crew;
    }

    return nullptr;
}

//

void GoToFlagship(bool atBase, bool allFleet)
{
    StarMap& starMap = G_->GetWorld()->starMap;

    if (!starMap.bossLevel) return;

    // Advance Flagship to base.
    if (atBase && !starMap.boss_path[starMap.bossLoc]->beacon)
    {
        Location* base = nullptr;
        unsigned int bossLoc;
        for (bossLoc=0; bossLoc<starMap.boss_path.size(); ++bossLoc)
        {
            if (starMap.boss_path[bossLoc]->beacon)
            {
                base = starMap.boss_path[bossLoc];
                break;
            }
        }

        if (base != nullptr)
        {
            starMap.boss_path[starMap.bossLoc]->boss = false;

            starMap.bossJumping = false;
            starMap.arrivedAtBase = 3;
            starMap.bossLoc = bossLoc;
            base->boss = true;
            LocationEvent* baseEvent = base->event;
            if (baseEvent != nullptr)
            {
                baseEvent->pStore = nullptr;
                baseEvent->store = false;
                baseEvent->repair = false;
                baseEvent->distressBeacon = false;
            }
            starMap.bossPosition = base->loc;
        }
    }

    // Fleet overtakes entire sector (except base).
    if (allFleet)
    {
        for (Location* loc : starMap.locations)
        {
            if (!loc->beacon)
            {
                starMap.TurnIntoFleetLocation(loc);
            }
        }
    }

    Location* dest = starMap.boss_path[starMap.bossLoc];
    if (starMap.bossJumping && starMap.bossLoc+1 < starMap.boss_path.size())
    {
        dest = starMap.boss_path[starMap.bossLoc + 1];
    }

    CommandGui* commandGui = G_->GetWorld()->commandGui;

    starMap.potentialLoc = dest;
    starMap.readyToTravel = true;
    starMap.outOfFuel = false;
    commandGui->waitLocation = false;
}

HOOK_METHOD(CompleteShip, DeadCrew, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CompleteShip::DeadCrew -> Begin (CustomEvents.cpp)\n")
    bool ret = super();

    if (ret && !bPlayerShip)
    {
        ShipEvent& event = G_->GetWorld()->currentShipEvent;

        if (event.present)
        {
            CustomShipEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomShipEvent(event.name);
            if (customEvent)
            {
                if (customEvent->deadCrewAuto)
                {
                    shipManager->bAutomated = true;
                    CustomEventsParser::QueueEvent(event.deadCrew, event.shipSeed);
                    return false;
                }

                if (customEvent->finalBoss.enabled && !bossDefeated)
                {
                    bossDefeated = true;

                    CommandGui* commandGui = G_->GetWorld()->commandGui;

                    if (!customEvent->finalBoss.sound.empty())
                    {
                        G_->GetSoundControl()->StopPlaylist(100);
                        G_->GetSoundControl()->PlaySoundMix(customEvent->finalBoss.sound, -1.f, false);

                        delete restartMusicTimer;
                        if (customEvent->bossMusicDelay != -1)
                        {
                            restartMusicTimer = new TimerHelper(false);
                            restartMusicTimer->Start(customEvent->bossMusicDelay);
                        }
                    }

                    if (customEvent->finalBoss.victory)
                    {
                        commandGui->alreadyWon = true;
                        alreadyWonCustom = true;
                        replaceGameOverText = customEvent->finalBoss.text;
                        replaceGameOverCreditsText = customEvent->finalBoss.creditsText;
                        replaceCreditsMusic = customEvent->finalBoss.creditsMusic;
                        replaceCreditsBackground = G_->GetEventGenerator()->GetImageFromList(customEvent->finalBoss.creditsBackground);
                        hs_log_file("Final Boss crewkilled: Set custom victory type to %s\n", customEvent->finalBoss.ach.c_str());
                        CustomShipUnlocks::instance->setCustomVictoryType = customEvent->finalBoss.ach;
                    }
                }
            }
        }
    }

    return ret;
}

HOOK_METHOD(WorldManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::OnLoop -> Begin (CustomEvents.cpp)\n")
    super();

    if (!playerShip) return;

    if (alreadyWonCustom && commandGui->alreadyWon)
    {
        if (playerShip->DeadCrew() || (playerShip->shipManager->bDestroyed && playerShip->shipManager->ship.explosion.done))
        {
            ShipManager *enemy = playerShip->shipManager->current_target;
            if (!enemy || !enemy->bDestroyed || enemy->ship.explosion.done)
            {
                G_->GetSoundControl()->StopPlaylist(100);
                G_->GetScoreKeeper()->SetVictory(true);
                G_->GetAchievementTracker()->SetVictoryAchievement();
                commandGui->gameover = true;
                commandGui->Victory();
                G_->GetScoreKeeper()->Save(true);
            }
        }
    }
    if (!bossDefeated)
    {
        ShipManager *enemy = playerShip->shipManager->current_target;
        if (!enemy) return;

        if (enemy->bDestroyed && currentShipEvent.present)
        {
            CustomShipEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomShipEvent(currentShipEvent.name);
            if (customEvent && customEvent->finalBoss.enabled)
            {
                bossDefeated = true;
                enemy->ship.explosion.time = 6.0;

                if (!customEvent->finalBoss.sound.empty())
                {
                    G_->GetSoundControl()->StopPlaylist(100);
                    G_->GetSoundControl()->PlaySoundMix(customEvent->finalBoss.sound, -1.f, false);

                    delete restartMusicTimer;
                    if (customEvent->bossMusicDelay != -1)
                    {
                        restartMusicTimer = new TimerHelper(false);
                        restartMusicTimer->Start(customEvent->bossMusicDelay);
                    }
                }

                if (customEvent->finalBoss.victory)
                {
                    commandGui->alreadyWon = true;
                    alreadyWonCustom = true;
                    replaceGameOverText = customEvent->finalBoss.text;
                    replaceGameOverCreditsText = customEvent->finalBoss.creditsText;
                    replaceCreditsMusic = customEvent->finalBoss.creditsMusic;
                    replaceCreditsBackground = G_->GetEventGenerator()->GetImageFromList(customEvent->finalBoss.creditsBackground);
                    hs_log_file("Final Boss destroyed: Set custom victory type to %s\n", customEvent->finalBoss.ach.c_str());
                    CustomShipUnlocks::instance->setCustomVictoryType = customEvent->finalBoss.ach;
                }
            }
        }
    }
}

HOOK_METHOD(CApp, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnLoop -> Begin (CustomEvents.cpp)\n")
    super();
    if (restartMusicTimer != nullptr)
    {
        restartMusicTimer->Update();
        if (restartMusicTimer->Done())
        {
            delete restartMusicTimer;
            restartMusicTimer = nullptr;

            if (!menu.bOpen)
            {
                Sector *sec = G_->GetWorld()->starMap.currentSector;
                if (sec != nullptr)
                {
                    G_->GetSoundControl()->StartPlaylist(sec->description.musicTracks);
                }
            }
        }
    }
}


HOOK_METHOD(SpaceManager, SetPlanetaryDefense, (bool state, int target) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::SetPlanetaryDefense -> Begin (CustomEvents.cpp)\n")
    bool dangerSet = false;
    if (g_noASBPlanet && !dangerZone)
    {
        dangerSet = true;
        dangerZone = true;
    }

    super(state, target);

    if (dangerSet)
    {
        dangerZone = false;
    }
}

HOOK_METHOD(SpaceManager, UpdatePDS, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::UpdatePDS -> Begin (CustomEvents.cpp)\n")

    Point pdsPoint;

    if (dangerZone)
    {
        pdsPoint.x = fleetShip.x + fleetShip.w/2 - shipPosition.x;
        pdsPoint.y = fleetShip.y + fleetShip.h/2 - shipPosition.y;
    }
    else
    {
        pdsPoint.x = currentPlanet.x + currentPlanet.w/2 - shipPosition.x;
        pdsPoint.y = currentPlanet.y + currentPlanet.h/2 - shipPosition.y;
    }

    // SpaceManager::shipPosition is only used for the ASB so it's safe to modify for this.
    if (pdsPoint.x > 800) shipPosition.x += (pdsPoint.x-800);
    if (pdsPoint.y > 800) shipPosition.x += (pdsPoint.x-800);

    super();
}

// Fixes time advancement during events

HOOK_METHOD(WorldManager, CheckStatusEffects, (std::vector<StatusEffect> &effects) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CheckStatusEffects -> Begin (CustomEvents.cpp)\n")
    CFPS *cFPS = G_->GetCFPS();
    float speed = cFPS->SpeedFactor;
    cFPS->SpeedFactor = 0.f;

    super(effects);

    cFPS->SpeedFactor = speed;
}

HOOK_METHOD(ProjectileFactory, Update, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::Update -> Begin (CustomEvents.cpp)\n")
    if (powered || cooldown.first != cooldown.second || G_->GetCFPS()->SpeedFactor > 0.f) super();
}

// Vanilla method has a bug so let's rewrite it
HOOK_METHOD_PRIORITY(WorldManager, CheckStatusEffects, 9999, (std::vector<StatusEffect> &effects) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WorldManager::CheckStatusEffects -> Begin (CustomEvents.cpp)\n")
    for (StatusEffect &effect : effects)
    {
        if (effect.target == 0 || effect.target == 2)
        {
            ModifyStatusEffect(effect, playerShip->shipManager, 0);
        }
        if (!ships.empty() && (effect.target == 1 || effect.target == 2))
        {
            for (CompleteShip *ship : ships)
            {
                ModifyStatusEffect(effect, ship->shipManager, 1);
            }
        }
        currentEffects.push_back(effect);
    }

    // Do OnLoop for all shipManagers to update system powers
    if (!ships.empty())
    {
        for (CompleteShip *ship : ships)
        {
            ship->shipManager->OnLoop();
        }
    }
    playerShip->shipManager->OnLoop();
}

HOOK_METHOD(WorldManager, ModifyStatusEffect, (StatusEffect effect, ShipManager *target, int targetType) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::ModifyStatusEffect -> Begin (CustomEvents.cpp)\n")
    super(effect, target, targetType);
    if (effect.system == 16 && (targetType == effect.target || effect.target == 2)) // all systems
    {
        super(StatusEffect{effect.type, SYS_TEMPORAL, effect.amount, effect.target}, target, targetType);
    }
}

// Death Event

bool deathEventActive = false;

HOOK_METHOD(WorldManager, UpdateLocation0, (LocationEvent *loc) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::UpdateLocation0 -> Begin (CustomEvents.cpp)\n")
    if (deathEventActive) return UpdateLocation(loc);
    return super(loc);
}

HOOK_METHOD(WorldManager, CreateChoiceBox0, (LocationEvent *event) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateChoiceBox0 -> Begin (CustomEvents.cpp)\n")
    if (deathEventActive) return CreateChoiceBox(event);
    return super(event);
}

HOOK_METHOD(GameOver, OpenText, (const std::string &text) -> void)
{
    LOG_HOOK("HOOK_METHOD -> GameOver::OpenText -> Begin (CustomEvents.cpp)\n")

    if (deathEventQueue.empty()) return super(text);

    if (bVictory) return super(text);

    deathEventActive = true;

    std::string event = deathEventQueue.front().event;
    deathEventQueue.pop_front();
    CustomEventsParser::GetInstance()->LoadEvent(G_->GetWorld(), event, false, -1);
}

// Variable Stuff

void VariableModifier::ApplyVariables(std::vector<VariableModifier> &variables, ShipManager *ship)
{
    std::unordered_map<std::string, int> tempVariables;
    for (VariableModifier &i : variables)
    {
        int val;

        if (i.minVal == i.maxVal)
        {
            val = i.minVal;
        }
        else
        {
            int savedSeed;
            if (SeedInputBox::seedsEnabled)
            {
                savedSeed = random32();
                srandom32(Global::questSeed);
            }

            val = i.minVal + random32()%(i.maxVal-i.minVal+1);

            if (SeedInputBox::seedsEnabled)
            {
                Global::questSeed = random32();
                srandom32(savedSeed);
            }
        }

        if (!i.var.empty())
        {
            auto it = tempVariables.find(i.var);
            if (it != tempVariables.end())
            {
                val *= it->second;
            }
            else if (ship)
            {
                advancedCheckEquipment[4] = true;
                val *= ship->HasEquipment(i.var);
                advancedCheckEquipment[4] = false;
            }
            else
            {
                it = playerVariables.find(i.var);
                if (it != playerVariables.end())
                {
                    val *= it->second;
                }
                else
                {
                    it = metaVariables.find(i.var);
                    if (it != metaVariables.end())
                    {
                        val *= it->second;
                    }
                }
            }
        }

        std::unordered_map<std::string, int> *varList;
        switch(i.vType)
        {
        case VarType::VAR:
            varList = &playerVariables;
            break;
        case VarType::METAVAR:
            if (!i.force && !SeedInputBox::seedsAllowMetaVars && Global::IsSeededRun()) continue; // seeded run blocks meta variables unless force = true
            varList = &metaVariables;
            break;
        default:
            varList = &tempVariables;
            break;
        }

        switch (i.op)
        {
        case OP::SET:
            (*varList)[i.name] = val;
            break;
        case OP::ADD:
            (*varList)[i.name] += val;
            break;
        case OP::MUL:
            (*varList)[i.name] *= val;
            break;
        case OP::DIV:
            (*varList)[i.name] /= val;
            break;
        case OP::MIN:
            (*varList)[i.name] = std::min((*varList)[i.name], val);
            break;
        case OP::MAX:
            (*varList)[i.name] = std::max((*varList)[i.name], val);
            break;
        }

        CustomAchievementTracker::instance->UpdateVariableAchievements(i.name, (*varList)[i.name]);
    }
}
