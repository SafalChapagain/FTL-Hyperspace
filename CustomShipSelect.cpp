#include "Global.h"
#include "ShipManager_Extend.h"
#include "CustomShipSelect.h"
#include "CustomOptions.h"
#include "Seeds.h"
#include "ShipUnlocks.h"
#include "EnemyShipIcons.h"
#include "Resources.h"
#include "CustomColors.h"
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>

CustomShipSelect CustomShipSelect::instance = CustomShipSelect();

std::array<std::string, 10> CustomShipSelect::vanillaShipNames =
{
    "PLAYER_SHIP_HARD",
    "PLAYER_SHIP_STEALTH",
    "PLAYER_SHIP_MANTIS",
    "PLAYER_SHIP_CIRCLE",
    "PLAYER_SHIP_FED",
    "PLAYER_SHIP_JELLY",
    "PLAYER_SHIP_ROCK",
    "PLAYER_SHIP_ENERGY",
    "PLAYER_SHIP_CRYSTAL",
    "PLAYER_SHIP_ANAEROBIC",
};

std::array<int, 10> CustomShipSelect::vanillaShipOrder = {0, 3, 4, 7, 2, 5, 6, 1, 9, 8};

void CustomShipSelect::EarlyParseShipsNode(rapidxml::xml_node<char> *node)
{
    // parse <ships> node in hyperspace.xml
    try
    {
        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            std::string name = child->name();

            if (name == "customShip" && !child->first_attribute("name"))
            {
                CustomShipDefinition &def = GetDefaultDefinition();

                ParseCustomShipNode(child, def);
            }
        }
    }
    catch (rapidxml::parse_error& e)
    {
        ErrorMessage(std::string("Error parsing <ships> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (std::exception &e)
    {
        ErrorMessage(std::string("Error parsing <ships> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (const char* e)
    {
        ErrorMessage(std::string("Error parsing <ships> in hyperspace.xml\n") + std::string(e));
    }
    catch (...)
    {
        ErrorMessage("Error parsing <ships> in hyperspace.xml\n");
    }
}

void CustomShipSelect::ParseShipsNode(rapidxml::xml_node<char> *node)
{
    // parse <ships> node in hyperspace.xml
    try
    {
        if (node->first_attribute("hideFirstShipPage"))
        {
            hideFirstPage = EventsParser::ParseBoolean(node->first_attribute("hideFirstShipPage")->value());
        }

        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            std::string name = child->name();


            if (name == "shipIcons")
            {
                ShipIconManager::instance->ParseShipIconNode(child);
            }

            if (name == "ship")
            {
                if (child->first_attribute("name"))
                {
                    std::string shipName = std::string(child->first_attribute("name")->value());

                    ShipButtonDefinition buttonDef = ShipButtonDefinition();
                    buttonDef.name = shipName;

                    if (child->first_attribute("a"))
                    {
                        if (strcmp(child->first_attribute("a")->value(), "dlc") == 0)
                        {
                            buttonDef.typeA = 2;
                        }
                        else
                        {
                            buttonDef.typeA = EventsParser::ParseBoolean(child->first_attribute("a")->value()) ? 1 : 0;
                        }
                    }
                    if (child->first_attribute("b"))
                    {
                        if (strcmp(child->first_attribute("b")->value(), "dlc") == 0)
                        {
                            buttonDef.typeB = 2;
                        }
                        else
                        {
                            buttonDef.typeB = EventsParser::ParseBoolean(child->first_attribute("b")->value()) ? 1 : 0;
                        }
                    }
                    if (child->first_attribute("c"))
                    {
                        if (strcmp(child->first_attribute("c")->value(), "dlc") == 0)
                        {
                            buttonDef.typeC = 2;
                        }
                        else
                        {
                            buttonDef.typeC = EventsParser::ParseBoolean(child->first_attribute("c")->value()) ? 1 : 0;
                        }
                    }
                    if (child->first_attribute("secret"))
                    {
                        buttonDef.secretCruiser = EventsParser::ParseBoolean(child->first_attribute("secret")->value());
                    }
                    if (child->first_attribute("noAppend"))
                    {
                        buttonDef.noAppend = EventsParser::ParseBoolean(child->first_attribute("noAppend")->value());
                    }

                    if (child->first_attribute("splitUnlockQuestAchievement"))
                    {
                        buttonDef.splitUnlockQuestAchievement = EventsParser::ParseBoolean(child->first_attribute("splitUnlockQuestAchievement")->value());
                    }
                    if (child->first_attribute("splitVictoryAchievement"))
                    {
                        buttonDef.splitVictoryAchievement = EventsParser::ParseBoolean(child->first_attribute("splitVictoryAchievement")->value());
                    }

                    for (auto shipChild = child->first_node(); shipChild; shipChild = shipChild->next_sibling())
                    {
                        if (strcmp(shipChild->name(), "splitUnlockQuestAchievement") == 0)
                        {
                            buttonDef.splitUnlockQuestAchievement = EventsParser::ParseBoolean(shipChild->value());
                        }
                        if (strcmp(shipChild->name(), "splitVictoryAchievement") == 0)
                        {
                            buttonDef.splitVictoryAchievement = EventsParser::ParseBoolean(shipChild->value());
                        }
                        if (strcmp(shipChild->name(), "showShipAchievements") == 0)
                        {
                            buttonDef.showShipAchievements = EventsParser::ParseBoolean(shipChild->value());
                        }

                        if (strcmp(shipChild->name(), "achievement") == 0) // ship achievement
                        {
                            CustomAchievement &sAch = CustomAchievementTracker::instance->ParseShipAchievement(shipChild, shipName);

                            if (shipChild->first_attribute("variant"))
                            {
                                if (strcmp(shipChild->first_attribute("variant")->value(), "a") == 0)
                                {
                                    buttonDef.shipAchievements[0].push_back(&sAch);
                                }
                                else if (strcmp(shipChild->first_attribute("variant")->value(), "b") == 0)
                                {
                                    buttonDef.shipAchievements[1].push_back(&sAch);
                                }
                                else if (strcmp(shipChild->first_attribute("variant")->value(), "c") == 0)
                                {
                                    buttonDef.shipAchievements[2].push_back(&sAch);
                                }
                                else if (strcmp(shipChild->first_attribute("variant")->value(), "all") == 0)
                                {
                                    buttonDef.shipAchievements[0].push_back(&sAch);
                                    buttonDef.shipAchievements[1].push_back(&sAch);
                                    buttonDef.shipAchievements[2].push_back(&sAch);
                                }
                            }
                            else
                            {
                                buttonDef.shipAchievements[0].push_back(&sAch);
                                buttonDef.shipAchievements[1].push_back(&sAch);
                                buttonDef.shipAchievements[2].push_back(&sAch);
                            }
                        }

                        if (strcmp(shipChild->name(), "unlock") == 0)
                        {
                            CustomShipUnlocks::instance->ParseUnlockNode(shipChild, shipName);
                        }
                        if (strcmp(shipChild->name(), "arrow") == 0)
                        {
                            CustomUnlockArrow arrow = CustomUnlockArrow();
                            arrow.tooltip.data = "";
                            arrow.tooltip.isLiteral = true;

                            std::string image = "";
                            std::string lockedImage = "";
                            std::string unlockedImage = "";
                            std::string direction = "";
                            std::string imageDirection = "";
                            Point pos = {0,0};
                            float rotation = 0.f;
                            bool mirror = false;

                            arrow.ship = shipName;
                            arrow.targetShip = shipChild->value();

                            if (shipChild->first_attribute("variant"))
                            {
                                std::string variantStr = shipChild->first_attribute("variant")->value();

                                if (variantStr == "a")
                                {
                                    arrow.variant = 0;
                                }
                                else if (variantStr == "b")
                                {
                                    arrow.variant = 1;
                                }
                                else if (variantStr == "c")
                                {
                                    arrow.variant = 2;
                                }
                                else if (variantStr == "all")
                                {
                                    arrow.variant = -1;
                                }
                            }
                            if (shipChild->first_attribute("tooltip"))
                            {
                                arrow.tooltip.data = shipChild->first_attribute("tooltip")->value();
                                arrow.tooltip.isLiteral = false;
                            }
                            if (shipChild->first_attribute("tooltipText"))
                            {
                                arrow.tooltip.data = shipChild->first_attribute("tooltipText")->value();
                                arrow.tooltip.isLiteral = true;
                            }

                            if (shipChild->first_attribute("x"))
                            {
                                pos.x = boost::lexical_cast<int>(shipChild->first_attribute("x")->value());
                            }
                            if (shipChild->first_attribute("y"))
                            {
                                pos.y = boost::lexical_cast<int>(shipChild->first_attribute("y")->value());
                            }
                            if (shipChild->first_attribute("image"))
                            {
                                image = shipChild->first_attribute("image")->value();
                            }
                            if (shipChild->first_attribute("lockedImage"))
                            {
                                lockedImage = shipChild->first_attribute("lockedImage")->value();
                            }
                            if (shipChild->first_attribute("unlockedImage"))
                            {
                                unlockedImage = shipChild->first_attribute("unlockedImage")->value();
                            }
                            if (shipChild->first_attribute("direction"))
                            {
                                direction = shipChild->first_attribute("direction")->value();
                                imageDirection = direction;
                            }
                            if (shipChild->first_attribute("mirrorX") && EventsParser::ParseBoolean(shipChild->first_attribute("mirrorX")->value()))
                            {
                                mirror = !mirror;
                                if (imageDirection == "left")
                                {
                                    imageDirection = "right";
                                }
                                else if (imageDirection == "right")
                                {
                                    imageDirection = "left";
                                }
                            }
                            if (shipChild->first_attribute("mirrorY") && EventsParser::ParseBoolean(shipChild->first_attribute("mirrorY")->value()))
                            {
                                mirror = !mirror;
                                rotation = 180.f;
                                if (imageDirection == "up")
                                {
                                    imageDirection = "down";
                                }
                                else if (imageDirection == "down")
                                {
                                    imageDirection = "up";
                                }
                            }

                            if (image.empty()) image = "arrow_v_" + imageDirection + ".png";
                            if (lockedImage.empty()) lockedImage = "arrow_lock_" + imageDirection + ".png";

                            arrow.image[0] = new CachedImage("customizeUI/" + lockedImage, pos.x, pos.y);
                            arrow.image[0]->CreatePrimitive();
                            if (direction == "right")
                            {
                                arrow.image[0]->SetPosition(pos.x + 191, pos.y + (121-arrow.image[0]->texture->height_)/2);
                            }
                            else if (direction == "down")
                            {
                                arrow.image[0]->SetPosition(pos.x + (191-arrow.image[0]->texture->width_)/2, pos.y + 121);
                            }
                            else if (direction == "left")
                            {
                                arrow.image[0]->SetPosition(pos.x - arrow.image[0]->texture->width_, pos.y + (121-arrow.image[0]->texture->height_)/2);
                            }
                            else if (direction == "up")
                            {
                                arrow.image[0]->SetPosition(pos.x + (191-arrow.image[0]->texture->width_)/2, pos.y - arrow.image[0]->texture->height_);
                            }

                            arrow.image[0]->SetRotation(rotation);
                            arrow.image[0]->SetMirrored(mirror);

                            arrow.image[1] = new CachedImage("customizeUI/" + image, pos.x, pos.y);
                            arrow.image[1]->CreatePrimitive();
                            if (direction == "right")
                            {
                                arrow.image[1]->SetPosition(pos.x + 191, pos.y + (161-arrow.image[1]->texture->height_)/2);
                            }
                            else if (direction == "down")
                            {
                                arrow.image[1]->SetPosition(pos.x + (191-arrow.image[1]->texture->width_)/2, pos.y + 161);
                            }
                            else if (direction == "left")
                            {
                                arrow.image[1]->SetPosition(pos.x - arrow.image[1]->texture->width_, pos.y + (161-arrow.image[1]->texture->height_)/2);
                            }
                            else if (direction == "up")
                            {
                                arrow.image[1]->SetPosition(pos.x + (191-arrow.image[1]->texture->width_)/2, pos.y - arrow.image[1]->texture->height_);
                            }

                            arrow.image[1]->SetRotation(rotation);
                            arrow.image[1]->SetMirrored(mirror);

                            if (!unlockedImage.empty())
                            {
                                arrow.image[2] = new CachedImage("customizeUI/" + unlockedImage, pos.x, pos.y);
                                arrow.image[2]->CreatePrimitive();
                                if (direction == "right")
                                {
                                    arrow.image[2]->SetPosition(pos.x + 191, pos.y + (161-arrow.image[2]->texture->height_)/2);
                                }
                                else if (direction == "down")
                                {
                                    arrow.image[2]->SetPosition(pos.x + (191-arrow.image[2]->texture->width_)/2, pos.y + 161);
                                }
                                else if (direction == "left")
                                {
                                    arrow.image[2]->SetPosition(pos.x - arrow.image[2]->texture->width_, pos.y + (161-arrow.image[2]->texture->height_)/2);
                                }
                                else if (direction == "up")
                                {
                                    arrow.image[2]->SetPosition(pos.x + (191-arrow.image[2]->texture->width_)/2, pos.y - arrow.image[2]->texture->height_);
                                }

                                arrow.image[2]->SetRotation(rotation);
                                arrow.image[2]->SetMirrored(mirror);
                            }

                            buttonDef.unlockArrows.push_back(arrow);
                        }
                    }

                    if (G_->GetScoreKeeper()->GetShipId(shipName).first == -1)
                    {
                        shipButtonDefs.push_back(buttonDef);
                    }
                }
            }

            if (name == "shipOrder")
            {
                for (auto shipChild = child->first_node(); shipChild; shipChild = shipChild->next_sibling())
                {
                    if (strcmp(shipChild->name(), "ship") == 0)
                    {
                        customShipOrder.push_back(shipChild->value());
                    }
                    if (strcmp(shipChild->name(), "empty") == 0)
                    {
                        customShipOrder.push_back("empty");
                    }
                }
            }

            if (name == "hangarAnims")
            {
                for (auto animChild = child->first_node(); animChild; animChild = animChild->next_sibling())
                {
                    if (strcmp(animChild->name(), "anim") == 0)
                    {
                        Point pos = Point();
                        if (animChild->first_attribute("x"))
                        {
                            pos.x = boost::lexical_cast<int>(animChild->first_attribute("x")->value());
                        }
                        if (animChild->first_attribute("y"))
                        {
                            pos.y = boost::lexical_cast<int>(animChild->first_attribute("y")->value());
                        }
                        customAnimDefs.push_back(std::pair<Point, std::string>(pos, animChild->value()));
                    }
                }
            }

            if (name == "customShip" && child->first_attribute("name"))
            {
                std::string shipName = child->first_attribute("name")->value();
                bool exists = shipDefs.find(shipName) != shipDefs.end();

                CustomShipDefinition &def = shipDefs[shipName];
                if (child->first_attribute("load"))
                {
                    std::string loadName = child->first_attribute("load")->value();
                    if (shipDefs.find(loadName) != shipDefs.end())
                    {
                        def = CustomShipDefinition(shipDefs[loadName]);
                    }
                }
                else if (!exists)
                {
                    def = CustomShipDefinition(GetDefaultDefinition());
                }

                def.name = shipName;

                ParseCustomShipNode(child, def);
            }
        }
    }
    catch (rapidxml::parse_error& e)
    {
        ErrorMessage(std::string("Error parsing <ships> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (std::exception &e)
    {
        ErrorMessage(std::string("Error parsing <ships> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (const char* e)
    {
        ErrorMessage(std::string("Error parsing <ships> in hyperspace.xml\n") + std::string(e));
    }
    catch (...)
    {
        ErrorMessage("Error parsing <ships> in hyperspace.xml\n");
    }
}

HOOK_METHOD(BlueprintManager, ProcessShipBlueprint, (rapidxml::xml_node<char>* node) -> ShipBlueprint)
{
    LOG_HOOK("HOOK_METHOD -> BlueprintManager::ProcessShipBlueprint -> Begin (CustomShipSelect.cpp)\n")
    auto ret = super(node);

    CustomShipSelect::GetInstance()->ParseVanillaShipNode(node);

    return ret;
}

void CustomShipSelect::ParseVanillaShipNode(rapidxml::xml_node<char> *node)
{
    std::string shipName = node->first_attribute("name")->value();

    CustomShipDefinition &def = shipDefs[shipName];
    def = CustomShipDefinition(GetDefaultDefinition());

    bool isCustom = ParseCustomShipNode(node, def);

    if (!isCustom) shipDefs.erase(shipName);
}

bool CustomShipSelect::ParseCustomShipNode(rapidxml::xml_node<char> *node, CustomShipDefinition &def)
{
    bool isCustom = false;

    for (auto shipNode = node->first_node(); shipNode; shipNode = shipNode->next_sibling())
    {
        std::string name = std::string(shipNode->name());
        std::string val = std::string(shipNode->value());

        if (name == "hiddenAug")
        {
            isCustom = true;
            if (def.hiddenAugs.find(val) == def.hiddenAugs.end())
            {
                def.hiddenAugs[val] = 1;
            }
            else
            {
                def.hiddenAugs[val]++;
            }
        }
        if (name == "crewLimit")
        {
            isCustom = true;
            def.crewLimit = boost::lexical_cast<int>(val);
        }
        if (name == "shipIcons")
        {
            isCustom = true;
            for (auto iconNode = shipNode->first_node(); iconNode; iconNode = iconNode->next_sibling())
            {
                std::string iconName = iconNode->name();

                if (iconName == "shipIcon")
                {
                    def.shipIcons.push_back(iconNode->value());
                }
            }
        }
        if (name == "rooms")
        {
            isCustom = true;
            for (auto roomNode = shipNode->first_node(); roomNode; roomNode = roomNode->next_sibling())
            {
                if (strcmp(roomNode->name(), "room") == 0 && roomNode->first_attribute("id"))
                {
                    RoomDefinition* roomDef = new RoomDefinition();

                    int roomId = boost::lexical_cast<int>(roomNode->first_attribute("id")->value());

                    for (auto roomDefNode = roomNode->first_node(); roomDefNode; roomDefNode = roomDefNode->next_sibling())
                    {
                        std::string roomName = roomDefNode->name();
                        std::string roomValue = roomDefNode->value();

                        if (roomName == "roomAnim")
                        {
                            auto def = RoomAnimDef();

                            def.ParseRoomAnimNode(roomDefNode);

                            roomDef->roomAnims.push_back(def);
                        }
                        if (roomName == "sensorBlind")
                        {
                            roomDef->sensorBlind = EventsParser::ParseBoolean(roomValue);
                        }
                        if (roomName == "sysDamageResistChance")
                        {
                            roomDef->sysDamageResistChance = boost::lexical_cast<float>(roomValue);
                        }
                        if (roomName == "ionDamageResistChance")
                        {
                            roomDef->ionDamageResistChance = boost::lexical_cast<float>(roomValue);
                        }
                    }

                    def.roomDefs[roomId] = roomDef;
                }
            }
        }
        if (name == "crew")
        {
            isCustom = true;
            for (auto crewNode = shipNode->first_node(); crewNode; crewNode = crewNode->next_sibling())
            {
                int roomId = 0;
                std::string crewName = "";
                auto crewDef = CrewPlacementDefinition();

                crewDef.species = crewNode->name();

                if (crewNode->first_attribute("room"))
                {
                    crewDef.roomId = boost::lexical_cast<int>(crewNode->first_attribute("room")->value());
                }
                if (crewNode->first_attribute("name"))
                {
                    crewDef.name = crewNode->first_attribute("name")->value();
                }
                if (crewNode->first_attribute("list"))
                {
                    crewDef.isList = EventsParser::ParseBoolean(crewNode->first_attribute("list")->value());
                }

                def.crewList.push_back(crewDef);
            }
        }
        if (name == "noJump")
        {
            isCustom = true;
            def.noJump = true;
        }
        if (name == "noFuelStalemate")
        {
            isCustom = true;
            def.noFuelStalemate = true;
        }
        if (name == "hpCap")
        {
            isCustom = true;
            def.hpCap = boost::lexical_cast<int>(val);
        }
        if (name == "startingFuel")
        {
            isCustom = true;
            def.startingFuel = boost::lexical_cast<int>(val);
        }
        if (name == "startingScrap")
        {
            isCustom = true;
            def.startingScrap = boost::lexical_cast<int>(val);
        }
        if (name == "autoShipForce")
        {
            isCustom = true;
            def.forceAutomated = EventsParser::ParseBoolean(val);
        }
        if (name == "systemLimit")
        {
            isCustom = true;
            def.systemLimit = boost::lexical_cast<int>(val);
        }
        if (name == "subsystemLimit")
        {
            isCustom = true;
            def.subsystemLimit = boost::lexical_cast<int>(val);
        }
        if (name == "customReactor")
        {
            isCustom = true;
            if(shipNode->first_attribute("maxLevel")) def.maxReactorLevel = boost::lexical_cast<int>(shipNode->first_attribute("maxLevel")->value());
            if(def.maxReactorLevel < 0) def.maxReactorLevel = 0;
            if(def.maxReactorLevel > 25) def.reactorPrices.resize(ceil(def.maxReactorLevel / 5 + 1), -1);
            for (auto reactorNode = shipNode->first_node(); reactorNode; reactorNode = reactorNode->next_sibling())
            {
                std::string reactName = reactorNode->name();

                if(reactName == "baseCost") def.reactorPrices[0] = boost::lexical_cast<int>(reactorNode->value());
                if(reactName == "increment") def.reactorPriceIncrement = boost::lexical_cast<int>(reactorNode->value());
                if(reactName == "overrideCost") {
                    int coloumn = 0;
                    if (reactorNode->first_attribute("coloumn")) coloumn = boost::lexical_cast<int>(reactorNode->first_attribute("coloumn")->value());
                    if (reactorNode->first_attribute("column")) coloumn = boost::lexical_cast<int>(reactorNode->first_attribute("column")->value());
                    def.reactorPrices[coloumn] = boost::lexical_cast<int>(reactorNode->value());
                }
            }
        }
        if (name == "shipGenerator")
        {
            isCustom = true;
            def.shipGenerator = val;
        }

    }

    return isCustom;
}

void RoomAnimDef::ParseRoomAnimNode(rapidxml::xml_node<char> *node)
{
    if (node->first_attribute("renderLayer"))
    {
        renderLayer = boost::lexical_cast<int>(node->first_attribute("renderLayer")->value());
    }

    if (node->first_node() && node->first_node()->type() == rapidxml::node_type::node_element)
    {
        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            if (strcmp(child->name(), "anim") == 0)
            {
                animName = child->value();

                if (child->first_attribute("animType"))
                {
                    std::string value = child->first_attribute("animType")->value();
                    if (value == "stretch")
                    {
                        animType = RoomAnimType::STRETCH;
                    }
                    else if (value == "center")
                    {
                        animType = RoomAnimType::CENTER;
                    }
                    else if (value == "random")
                    {
                        animType = RoomAnimType::RANDOM_POSITION;
                    }
                    else
                    {
                        animType = RoomAnimType::DEFAULT;
                    }
                }
                if (child->first_attribute("animBorder"))
                {
                    animBorder = boost::lexical_cast<int>(child->first_attribute("animBorder")->value());
                }
            }
            if (strcmp(child->name(), "tileAnim") == 0)
            {
                tileAnim = child->value();
            }
            if (strcmp(child->name(), "wallAnim") == 0)
            {
                wallAnim = child->value();
            }
        }
    }
    else
    {
        animName = node->value();

        if (node->first_attribute("animType"))
        {
            std::string value = node->first_attribute("animType")->value();
            if (value == "stretch")
            {
                animType = RoomAnimType::STRETCH;
            }
            else if (value == "center")
            {
                animType = RoomAnimType::CENTER;
            }
            else if (value == "random")
            {
                animType = RoomAnimType::RANDOM_POSITION;
            }
            else
            {
                animType = RoomAnimType::DEFAULT;
            }
        }
        if (node->first_attribute("animBorder"))
        {
            animBorder = boost::lexical_cast<int>(node->first_attribute("animBorder")->value());
        }
    }
}

void CustomShipSelect::OnInit(ShipSelect* shipSelect_)
{
    if (!dummyAchievement)
    {
        dummyAchievement = new CAchievement();
        dummyAchievement->gap_ex_custom = -127;
    }

    if (!initialized)
    {
        auto toAdd = std::vector<std::string>();

        for (const ShipButtonDefinition& i : shipButtonDefs)
        {
            if (!i.noAppend)
            {
                if (std::find(customShipOrder.begin(), customShipOrder.end(), i.name) == customShipOrder.end())
                {
                    toAdd.push_back(i.name);
                }
            }
        }

        customShipOrder.insert(customShipOrder.end(), toAdd.begin(), toAdd.end());

        for (auto i : customAnimDefs)
        {
            Animation* newAnim = new Animation(G_->GetAnimationControl()->GetAnimation(i.second));
            newAnim->SetCurrentFrame(0);
            newAnim->tracker.SetLoop(true, 0);
            newAnim->Start(true);

            customAnims.push_back(std::pair<Point, Animation*>(i.first, newAnim));
        }
    }

    maxShipPage = std::ceil(customShipOrder.size() / 10.f);

    if (hideFirstPage && shipPage == 0)
    {
        shipPage = 1;
    }

    if (maxShipPage <= 0)
        maxShipPage = 0;
    else if (!initialized)
    {
        for (int i = 0; i < (customShipOrder.size()); i++)
        {
            int shipId = 0;
            shipId = GetShipButtonIdFromName(customShipOrder[i]);


            if (shipId == -1)
                continue;

            ShipButtonDefinition &x = shipButtonDefs[shipId];

            // create and initialize ShipButtons for each of the blueprints
            int curPage = i / 10;

            ShipButton* buttons[3];

            int onPage = i % 10;

            for (int variant = 0; variant < 3; ++variant)
            {
                buttons[variant] = new ShipButton(100 + shipId, variant);

                if (!x.VariantExists(variant))
                {
                    buttons[variant]->bNoExist = true;
                    buttons[variant]->bActive = false;
                }
            }

            ShipButtonList* buttonList = new ShipButtonList(curPage, 100 + shipId, buttons[0], buttons[1], buttons[2]);
            shipButtons.push_back(buttonList);


            Point pos = Point(0, 0);
            if (onPage < 4)
            {
                pos = Point(136 + 205 * onPage, 161);
            }
            else if (onPage < 8)
            {
                pos = Point(136 + 205 * 3 - 205 * (onPage - 4), 161 + 177);
            }
            else if (onPage == 8)
            {
                pos = Point(136 + 205 * 3 + 225, 161);
            }
            else if (onPage == 9)
            {
                pos = Point(136 + 205 * 3 + 225, 161 + 177);
            }

            //int oldY = pos.y;

            for (int variant = 0; variant < 3; ++variant)
            {
                if (x.VariantExists(variant))
                {
                    std::string finalName = GetVariantName(x.name, variant);

                    buttons[variant]->achievements.resize(5, nullptr);

                    if (CustomShipUnlocks::instance->CustomShipHasUnlock(finalName))
                    {
                        buttons[variant]->bShipLocked = !CustomShipUnlocks::instance->GetCustomShipUnlocked(finalName);
                        buttons[variant]->bLayoutLocked = buttons[variant]->bShipLocked;
                    }

                    if (x.splitVictoryAchievement)
                    {
                        buttons[variant]->achievements[3] = CustomShipUnlocks::instance->GetVictoryAchievement(finalName);
                    }
                    else
                    {
                        buttons[variant]->achievements[3] = CustomShipUnlocks::instance->GetVictoryAchievement(x.name);
                    }

                    if (x.splitUnlockQuestAchievement)
                    {
                        if (CustomShipUnlocks::instance->CustomShipHasUnlockQuest(finalName))
                        {
                            buttons[variant]->achievements[4] = CustomShipUnlocks::instance->GetQuestAchievement(finalName);
                        }
                    }
                    else
                    {
                        if (CustomShipUnlocks::instance->CustomShipHasUnlockQuestAnyLayout(x.name))
                        {
                            buttons[variant]->achievements[4] = CustomShipUnlocks::instance->GetQuestAchievement(x.name);
                        }
                    }

                    while (!buttons[variant]->achievements.empty() && buttons[variant]->achievements.back() == nullptr) buttons[variant]->achievements.pop_back();
                    buttons[variant]->achievements.shrink_to_fit();
                }

//                if (!(buttons[variant]->bNoExist || buttons[variant]->bShipLocked))
//                    pos.y = oldY + 20;
//                else
//                    pos.y = oldY;

                buttons[variant]->OnInit("customizeUI/ship_list_button", pos);
            }
        }
    }
    else
    {
        int i = 0;
        for (auto x : shipButtons)
        {
            std::string shipName = GetShipBlueprint(x->GetId());

            ShipButton *aButton = x->GetButton(0);
            ShipButton *bButton = x->GetButton(1);
            ShipButton *cButton = x->GetButton(2);

            if (!aButton->bNoExist)
            {
                if (CustomShipUnlocks::instance->CustomShipHasUnlock(shipName))
                {
                    aButton->bShipLocked = !CustomShipUnlocks::instance->GetCustomShipUnlocked(shipName);
                    aButton->bLayoutLocked = aButton->bShipLocked;
                    if (aButton->bShipLocked && aButton->hitbox.h > 140)
                    {
                        aButton->hitbox.h -= 40;
                        aButton->SetLocation({aButton->position.x, aButton->position.y + 20});
                    }
                    else if (!aButton->bShipLocked && aButton->hitbox.h < 140)
                    {
                        aButton->hitbox.h += 40;
                        aButton->SetLocation({aButton->position.x, aButton->position.y - 20});
                    }
                }
            }
            if (!bButton->bNoExist)
            {
                if (CustomShipUnlocks::instance->CustomShipHasUnlock(shipName + "_2"))
                {
                    bButton->bShipLocked = !CustomShipUnlocks::instance->GetCustomShipUnlocked(shipName + "_2");
                    bButton->bLayoutLocked = bButton->bShipLocked;
                    if (bButton->bShipLocked && bButton->hitbox.h > 140)
                    {
                        bButton->hitbox.h -= 40;
                        bButton->SetLocation({bButton->position.x, bButton->position.y + 20});
                    }
                    else if (!bButton->bShipLocked && bButton->hitbox.h < 140)
                    {
                        bButton->hitbox.h += 40;
                        bButton->SetLocation({bButton->position.x, bButton->position.y - 20});
                    }
                }
            }
            if (!cButton->bNoExist)
            {
                if (CustomShipUnlocks::instance->CustomShipHasUnlock(shipName + "_3"))
                {
                    cButton->bShipLocked = !CustomShipUnlocks::instance->GetCustomShipUnlocked(shipName + "_3");
                    cButton->bLayoutLocked = cButton->bShipLocked;
                    if (cButton->bShipLocked && cButton->hitbox.h > 140)
                    {
                        cButton->hitbox.h -= 40;
                        cButton->SetLocation({cButton->position.x, cButton->position.y + 20});
                    }
                    else if (!cButton->bShipLocked && cButton->hitbox.h < 140)
                    {
                        cButton->hitbox.h += 40;
                        cButton->SetLocation({cButton->position.x, cButton->position.y - 20});
                    }
                }
            }
        }
    }




    std::string buttonImg("customizeUI/button_ship_arrow");
    leftButton = new Button();
    leftButton->OnInit(buttonImg, Point(1100, 119));

    rightButton = new Button();
    rightButton->OnInit(buttonImg, Point(1135, 119));

    rightButton->bMirror = true;

    if (maxShipPage == 0 || (maxShipPage == 1 && hideFirstPage))
    {
        leftButton->bActive = false;
        rightButton->bActive = false;
    }


    shipSelect = shipSelect_;
    oldShipButtons = shipSelect->shipButtons;

    UpdateFilteredAchievements();

    initialized = true;
}

void CustomShipSelect::UpdateFilteredAchievements()
{
    CustomShipUnlocks *customUnlocks = CustomShipUnlocks::instance;

    std::vector<std::string> victoryTypes;
    for (std::string &i : shipVictoryFilters)
    {
        if (!customUnlocks->customVictories[i].secret || !customUnlocks->customVictories[i].SecretLocked())
        {
            victoryTypes.push_back(i);
        }
    }
    if (victoryTypes.size() > 3) victoryTypes.resize(3);

    int counter = 0;
    for (ShipButton *button : shipSelect->shipButtons) // vanilla buttons
    {
        std::string shipName = vanillaShipNames[vanillaShipOrder[counter%10]];

        if (victoryTypes.empty())
        {
            std::vector<CAchievement*> shipAchievements = G_->GetAchievementTracker()->GetShipAchievements(shipName);
            for (auto i=0; i<3; ++i)
            {
                button->achievements[i] = shipAchievements[i];
            }
        }
        else
        {
            for (auto i=0; i<3; ++i)
            {
                CAchievement *ach = dummyAchievement; // because nullptr will crash

                if (i < victoryTypes.size())
                {
                    ach = CustomShipUnlocks::instance->customVictories[victoryTypes[i]].GetVictoryAchievement(shipName);
                }

                if (button->achievements.size() > i)
                {
                    button->achievements[i] = ach;
                }
                else
                {
                    button->achievements.push_back(ach);
                }
            }
        }

        counter = counter + 1;
    }

    for (auto x : shipButtons)
    {
        std::string shipName = GetShipBlueprint(x->GetId());

        int shipId = GetShipButtonIdFromName(shipName);

        if (shipId == -1)
            continue;

        ShipButtonDefinition &buttonDef = shipButtonDefs[shipId];

        for (auto variant=0; variant<3; ++variant)
        {
            ShipButton *button = x->GetButton(variant);

            if (!button->bNoExist)
            {
                std::string finalName = GetVariantName(shipName, variant);

                if (victoryTypes.empty())
                {
                    std::vector<CAchievement*> customShipAchievements = CustomAchievementTracker::instance->GetShipAchievementsCustom(shipName, variant, false);
                    for (auto i=0; i<3; ++i)
                    {
                        CAchievement *ach = nullptr;
                        if (i < buttonDef.shipAchievements[variant].size())
                        {
                           ach = customShipAchievements[i];
                           ach->miniIcon.SetImagePath(boost::str(boost::format("achievements/S_%1d_on.png") % (i+1)));
                           ach->miniIconLocked.SetImagePath(boost::str(boost::format("achievements/S_%1d_off.png") % (i+1)));
                        }
                        if (button->achievements.size() > i)
                        {
                            button->achievements[i] = ach;
                        }
                        else
                        {
                            button->achievements.push_back(ach);
                        }
                    }
                }
                else
                {
                    for (auto i=0; i<3; ++i)
                    {
                        CAchievement *ach = nullptr;

                        if (i < victoryTypes.size())
                        {
                            CustomVictoryAchievement &victoryAch = CustomShipUnlocks::instance->customVictories[victoryTypes[i]];

                            if (buttonDef.splitVictoryAchievement)
                            {
                                ach = victoryAch.GetVictoryAchievement(finalName);
                            }
                            else
                            {
                                ach = victoryAch.GetVictoryAchievement(shipName);
                            }
                        }

                        if (button->achievements.size() > i)
                        {
                            button->achievements[i] = ach;
                        }
                        else
                        {
                            button->achievements.push_back(ach);
                        }
                    }
                }
            }
        }
    }
}

bool CustomShipSelect::ShowAchievementsForShip(int currentShipId, int currentType)
{
    if (currentShipId >= 100)
    {
        ShipButtonDefinition *def = &GetShipButtonDefinition(currentShipId - 100);
        return showShipAchievements && def->showShipAchievements && !(hideMissingShipAchievements && def->shipAchievements[currentType].empty());
    }
    return showShipAchievements;
}

void CustomShipSelect::OnRender(bool renderSelect)
{
    if (shipSelect->tutorial.bOpen)
    {
        GL_Color tint(0.5f, 0.5f, 0.5f, 1.f);
        CSurface::GL_SetColorTint(tint);
    }

    if (renderSelect)
    {
        for (auto const &x: shipButtons)
        {
            if (x->GetPage() == shipPage - 1)
            {
                ShipButton* button = x->GetButton(shipSelect->currentType);

                if (button)
                    button->OnRender();
            }
        }
        if (shipPage > 0)
        {
            for (auto const &x: shipButtons)
            {
                if (x->GetPage() == shipPage - 1)
                {
                    ShipButton* button = x->GetButton(shipSelect->currentType);

                    if (button)
                    {
                        ShipButtonDefinition* def = &GetShipButtonDefinition(x->GetIndex());
                        if (def && def->VariantExists(shipSelect->currentType))
                        {
                            for (CustomUnlockArrow &arrow : def->unlockArrows)
                            {
                                if (arrow.variant == shipSelect->currentType || arrow.variant == -1)
                                {
                                    if (!CustomShipUnlocks::instance->GetCustomShipUnlocked(arrow.targetShip))
                                    {
                                        if (button->bShipLocked)
                                        {
                                            arrow.OnRender(button->position.x, button->position.y, 0);
                                        }
                                        else
                                        {
                                            arrow.OnRender(button->position.x, button->position.y, 1);
                                        }
                                    }
                                    else if (arrow.image[2] != nullptr)
                                    {
                                        arrow.OnRender(button->position.x, button->position.y, 2);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        leftButton->OnRender();
        rightButton->OnRender();

        char buf[128];



        if (hideFirstPage)
        {
            sprintf(buf, "%d/%d", GetCurrentPage(), GetMaxPages());
        }
        else
        {
            sprintf(buf, "%d/%d", GetCurrentPage() + 1, GetMaxPages() + 1);
        }

        std::string text(buf);

        CSurface::GL_SetColor(COLOR_BUTTON_TEXT);
        CSurface::GL_RemoveColorTint();
        freetype::easy_printRightAlign(63, 1097, 118, text);
    }

    if (shipSelect->infoBox.desc.title.data.empty())
    {
        CustomShipUnlocks *customUnlocks = CustomShipUnlocks::instance;

        std::vector<std::string> victoryTypes;
        for (std::string &i : customUnlocks->customVictoryTypes)
        {
            if (!customUnlocks->customVictories[i].secret || !customUnlocks->customVictories[i].SecretLocked())
            {
                victoryTypes.push_back(i);
            }
        }

        if (!victoryTypes.empty())
        {
            std::string imagePath = "customizeUI/box_shipach2.png";
            G_->GetResources()->RenderImageString(imagePath, 515, 525, 0, GL_Color(1.f,1.f,1.f,1.f), 1.f, false);
            freetype::easy_printCenter(13, 640, 544, G_->GetTextLibrary()->GetText("hangar_achievements_title_filter"));

            int max_a = victoryTypes.size()%6;
            int max_b = victoryTypes.size()/6;
            for (int i=0; i<victoryTypes.size(); ++i)
            {
                int a = i%6;
                int b = i/6;

                Point pos = Point(640 - 17*(b==max_b ? max_a : 6) + 34*a, 607 - 17*((victoryTypes.size()+5)/6) + 34*b);

                imagePath = "achievements/";

                if (customUnlocks->customVictories[victoryTypes[i]].SecretLocked() && !customUnlocks->customVictories[victoryTypes[i]].secretIcon.empty())
                {
                    imagePath += customUnlocks->customVictories[victoryTypes[i]].secretIcon;
                }
                else
                {
                    imagePath += customUnlocks->customVictories[victoryTypes[i]].icon;
                }

                if (std::find(shipVictoryFilters.begin(), shipVictoryFilters.end(), victoryTypes[i]) != shipVictoryFilters.end())
                {
                    imagePath += "_on.png";
                }
                else
                {
                    imagePath += "_off.png";
                }

                G_->GetResources()->RenderImageString(imagePath, pos.x, pos.y, 0, GL_Color(1.f,1.f,1.f,1.f), 1.f, false);

                if (i == selectedVictoryFilter)
                {
                    CSurface::GL_DrawRectOutline(pos.x, pos.y, 32, 32, GL_Color(255.f/255.f,230.f/255.f,94.f/255.f,1.f), 2);
                }
            }
        }
    }

    shipSelect->infoBox.OnRender();

    if (shipSelect->tutorial.bOpen)
    {
        CSurface::GL_RemoveColorTint();
    }
}

void CustomShipSelect::MouseClick()
{
    if (leftButton->bActive && leftButton->bHover)
    {
        if (hideFirstPage)
        {
            if (shipPage == 1)
            {
                SwitchPage(maxShipPage);
            }
            else
            {
                SwitchPage(shipPage - 1);
            }
        }
        else
        {
            if (shipPage == 0)
            {
                SwitchPage(maxShipPage);
            }
            else
            {
                SwitchPage(shipPage - 1);
            }
        }
    }

    if (rightButton->bActive && rightButton->bHover)
    {
        if (hideFirstPage)
        {
            if (shipPage == maxShipPage)
            {
                SwitchPage(1);
            }
            else
            {
                SwitchPage(shipPage + 1);
            }
        }
        else
        {
            if (shipPage == maxShipPage)
            {
                SwitchPage(0);
            }
            else
            {
                SwitchPage(shipPage + 1);
            }
        }
    }

    if (shipSelect->infoBox.desc.title.data.empty() && selectedVictoryFilter != -1)
    {
        CustomShipUnlocks *customUnlocks = CustomShipUnlocks::instance;

        std::vector<std::string> victoryTypes;
        std::vector<std::string> enabledVictoryFilters;
        for (std::string &i : customUnlocks->customVictoryTypes)
        {
            if (!customUnlocks->customVictories[i].secret || !customUnlocks->customVictories[i].SecretLocked())
            {
                victoryTypes.push_back(i);
            }
        }
        for (std::string &i : shipVictoryFilters)
        {
            if (!customUnlocks->customVictories[i].secret || !customUnlocks->customVictories[i].SecretLocked())
            {
                enabledVictoryFilters.push_back(i);
            }
        }

        std::string clickedVictoryFilter = victoryTypes[selectedVictoryFilter];

        auto it = std::find(enabledVictoryFilters.begin(), enabledVictoryFilters.end(), clickedVictoryFilter);

        if (it != enabledVictoryFilters.end())
        {
            enabledVictoryFilters.erase(it);
            G_->GetSoundControl()->PlaySoundMix("powerDownSystem", -1.f, false);
        }
        else
        {
            if (enabledVictoryFilters.size() >= 3)
            {
                enabledVictoryFilters.erase(enabledVictoryFilters.begin());
            }
            enabledVictoryFilters.push_back(clickedVictoryFilter);
            G_->GetSoundControl()->PlaySoundMix("powerUpSystem", -1.f, false);
        }

        shipVictoryFilters = enabledVictoryFilters;
        UpdateFilteredAchievements();
    }
}

void CustomShipSelect::SwitchPage(int page)
{
    if (shipPage == page)
        return;


    if (shipPage == 0)
    {
        LeaveFirstPage();
    }

    if (page == 0)
    {
        EnterFirstPage();
    }

    shipPage = page;
}

void CustomShipSelect::LeaveFirstPage()
{
    for (auto const &x: oldShipButtons)
    {
        x->bActive = false;
    }
}

void CustomShipSelect::EnterFirstPage()
{
    for (auto const &x: oldShipButtons)
    {
        if (!x->bNoExist)
            x->bActive = true;
    }
}

bool CustomShipSelect::ShouldRenderButton(ShipButton *button)
{
    if (shipPage != 0 &&
            std::find(oldShipButtons.begin(), oldShipButtons.end(), button) != oldShipButtons.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool CustomShipSelect::ShouldRenderArrow()
{
    return shipPage == 0;
}

bool CustomShipSelect::ShouldRenderButtonLower()
{
    return shipPage == 0;
}

void CustomUnlockArrow::MouseMove(int x, int y, int enabled)
{
    if (x > image[enabled]->x && x < image[enabled]->x + image[enabled]->texture->width_ && y > image[enabled]->y && y < image[enabled]->y + image[enabled]->texture->height_)
    {
        std::string shipName = CustomShipSelect::GetVariantName(ship);
        std::string targetShipName = CustomShipSelect::GetVariantName(targetShip);

        ShipBlueprint *bp1 = G_->GetBlueprints()->GetShipBlueprint(shipName, -1);
        std::string str1 = bp1->shipClass.GetText();
        ShipBlueprint *bp2 = G_->GetBlueprints()->GetShipBlueprint(targetShipName, -1);
        std::string str2 = bp2->shipClass.GetText();

        int id1 = CustomShipSelect::GetInstance()->GetShipButtonIdFromName(ship);
        if (id1 != -1)
        {
            ShipButtonDefinition &def = CustomShipSelect::GetInstance()->GetShipButtonDefinition(id1);
            if (def.secretCruiser && !CustomShipUnlocks::instance->GetCustomShipUnlocked(shipName))
            {
                str1 = G_->GetTextLibrary()->GetText("unidentified");
            }
        }

        int id2 = CustomShipSelect::GetInstance()->GetShipButtonIdFromName(targetShip);
        if (id2 != -1)
        {
            ShipButtonDefinition &def = CustomShipSelect::GetInstance()->GetShipButtonDefinition(id2);
            if (def.secretCruiser && !CustomShipUnlocks::instance->GetCustomShipUnlocked(targetShipName))
            {
                str2 = G_->GetTextLibrary()->GetText("unidentified");
            }
        }

        std::string str = tooltip.GetText();

        if (!str.empty())
        {
            str = boost::algorithm::replace_all_copy(str, "\\1", str1);
            str = boost::algorithm::replace_all_copy(str, "\\2", str2);

            G_->GetMouseControl()->SetTooltip(str);
            G_->GetMouseControl()->InstantTooltip();
        }
    }
}

void CustomShipSelect::MouseMove(int x, int y)
{
    if (shipSelect->tutorial.bOpen)
        return;
    leftButton->MouseMove(x, y, false);
    rightButton->MouseMove(x, y, false);

    selectedShip = -1;
    int lockedSelectedShip = -1;

    for (auto const &i: shipButtons)
    {
        if (i->GetPage() == shipPage - 1)
        {
            ShipButton* button = i->GetButton(shipSelect->currentType);

            if (button)
            {
                button->MouseMove(x, y);
                if (button->bHover && button->bActive)
                {
                    if (button->bLayoutLocked)
                    {
                        lockedSelectedShip = i->GetIndex();
                    }
                    else
                    {
                        selectedShip = i->GetIndex();
                        lastSelectedShip = selectedShip;
                    }
                }
            }
        }
    }

    if (shipPage > 0)
    {
        for (auto const &buttons: shipButtons)
        {
            if (buttons->GetPage() == shipPage - 1)
            {
                ShipButton* button = buttons->GetButton(shipSelect->currentType);

                if (button)
                {
                    ShipButtonDefinition* def = &GetShipButtonDefinition(buttons->GetIndex());
                    if (def && def->VariantExists(shipSelect->currentType))
                    {
                        for (CustomUnlockArrow &arrow : def->unlockArrows)
                        {
                            if (arrow.variant == shipSelect->currentType || arrow.variant == -1)
                            {
                                if (!CustomShipUnlocks::instance->GetCustomShipUnlocked(arrow.targetShip))
                                {
                                    if (button->bShipLocked)
                                    {
                                        arrow.MouseMove(x - button->position.x, y - button->position.y, 0);
                                    }
                                    else
                                    {
                                        arrow.MouseMove(x - button->position.x, y - button->position.y, 1);
                                    }
                                }
                                else if (arrow.image[2] != nullptr)
                                {
                                    arrow.MouseMove(x - button->position.x, y - button->position.y, 2);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (!FirstPage())
    {
        if (selectedShip == -1 && lockedSelectedShip == -1)
            shipSelect->infoBox.Clear();
        else
        {
            bool showUnlock = false;

            int shipId = selectedShip;
            if (selectedShip == -1 && lockedSelectedShip != -1)
            {
                shipId = lockedSelectedShip;
                showUnlock = true;
            }

            std::string name(shipButtonDefs[shipId].name);

            if (shipSelect->currentType == 1)
            {
                name.append("_2");
            }
            else if (shipSelect->currentType == 2)
            {
                name.append("_3");
            }

            ShipBlueprint* bp = G_->GetBlueprints()->GetShipBlueprint(name, -1);

            if (showUnlock)
            {
                auto shipButton = GetShipButtonDefinition(lockedSelectedShip);

                std::string title = bp->shipClass.GetText();

                if (shipSelect->currentType == 0)
                {
                    title.append(" " + G_->GetTextLibrary()->GetText("type_a"));
                }
                if (shipSelect->currentType == 1)
                {
                    title.append(" " + G_->GetTextLibrary()->GetText("type_b"));
                }
                if (shipSelect->currentType == 2)
                {
                    title.append(" " + G_->GetTextLibrary()->GetText("type_c"));
                }

                if (shipButton.secretCruiser)
                {
                    title = G_->GetTextLibrary()->GetText("unidentified");
                }


                shipSelect->infoBox.SetText(title, bp->unlock.GetText(), 360, 176, InfoBox::ExpandDir::EXPAND_DOWN);
            }
            else
            {
                shipSelect->infoBox.SetDescription(&bp->desc, 360, 135, InfoBox::ExpandDir::EXPAND_DOWN);
            }
        }
    }


    shipSelect->typeA.MouseMove(x, y, false);
    shipSelect->typeB.MouseMove(x, y, false);
    shipSelect->typeC.MouseMove(x, y, false);

    if (shipSelect->infoBox.desc.title.data.empty())
    {
        CustomShipUnlocks *customUnlocks = CustomShipUnlocks::instance;

        selectedVictoryFilter = -1;
        std::vector<std::string> victoryTypes;
        for (std::string &i : customUnlocks->customVictoryTypes)
        {
            if (!customUnlocks->customVictories[i].secret || !customUnlocks->customVictories[i].SecretLocked())
            {
                victoryTypes.push_back(i);
            }
        }

        int max_a = victoryTypes.size()%6;
        int max_b = victoryTypes.size()/6;
        for (int i=0; i<victoryTypes.size(); ++i)
        {
            int a = i%6;
            int b = i/6;

            Point pos(640 - 17*(b==max_b ? max_a : 6) + 34*a, 607 - 17*((victoryTypes.size()+5)/6) + 34*b);

            if (x > pos.x && x < pos.x+32 && y > pos.y && y < pos.y+32)
            {
                std::string name;
                if (customUnlocks->customVictories[victoryTypes[i]].SecretLocked() && !customUnlocks->customVictories[victoryTypes[i]].secretName.data.empty())
                {
                    name = customUnlocks->customVictories[victoryTypes[i]].secretName.GetText();
                }
                else
                {
                    name = customUnlocks->customVictories[victoryTypes[i]].name.GetText();
                }
                boost::algorithm::replace_all(name, "\\1", "");
                boost::algorithm::trim(name);

                G_->GetMouseControl()->SetTooltip(name);
                G_->GetMouseControl()->InstantTooltip();
                selectedVictoryFilter = i;
            }
        }
    }
}

std::string CustomShipSelect::GetShipBlueprint(int shipId)
{
    if (shipId >= 100)
    {
        int customIndex = shipId - 100;
        return shipButtonDefs[customIndex].name;
    }
    else
    {
        return vanillaShipNames[shipId];
    }
}


void CustomShipSelect::SwitchShip(ShipBuilder *builder, int type, int variant, bool force)
{
    if (type == builder->currentShipId && variant == builder->currentType && !(force))
        return;




    ShipManager *oldShip = builder->currentShip;

    ShipButtonDefinition &def = shipButtonDefs[type - 100];
    std::string name( def.name );

    if (variant == 1)
    {
        name.append("_2");
    }
    else if (variant == 2)
    {
        name.append("_3");
    }

    ShipBlueprint* bp = G_->GetBlueprints()->GetShipBlueprint(name, -1);

    if (bp)
    {
        ShipManager *ship = new ShipManager(0);

        builder->currentShip = ship;
        builder->currentShipId = type;
        builder->currentType = variant;

        ship->OnInit(bp, 0);

        std::string shipRealName = std::string();
        shipRealName = ship->myBlueprint.name.GetText();

        builder->currentName.swap(shipRealName);
        builder->nameInput.SetText(builder->currentName);

        builder->CreateEquipmentBoxes();
        builder->CreateSystemBoxes();
        builder->SetupShipAchievements();

        builder->ClearShipAchievements();

        if (!def.typeA || !CustomShipUnlocks::instance->GetCustomShipUnlocked(def.name))
        {
            builder->typeA.bActive = false;
            builder->typeA.bRenderOff = true;
            builder->typeA.bRenderSelected = false;
        }
        else
        {
            builder->typeA.SetActive(variant != 0);
            builder->typeA.bRenderOff = false;
            builder->typeA.bRenderSelected = variant == 0;
        }

        if (!def.typeB || !CustomShipUnlocks::instance->GetCustomShipUnlocked(def.name + "_2"))
        {
            builder->typeB.bActive = false;
            builder->typeB.bRenderOff = true;
            builder->typeB.bRenderSelected = false;
        }
        else
        {
            builder->typeB.SetActive(variant != 1);

            builder->typeB.bRenderOff = false;
            builder->typeB.bRenderSelected = variant == 1;
        }

        if (!def.typeC || !CustomShipUnlocks::instance->GetCustomShipUnlocked(def.name + "_3"))
        {
            builder->typeC.bActive = false;
            builder->typeC.bRenderOff = true;
            builder->typeC.bRenderSelected = false;
        }
        else
        {
            builder->typeC.SetActive(variant != 2);
            builder->typeC.bRenderOff = false;
            builder->typeC.bRenderSelected = variant == 2;
        }

        Point typeAPos(builder->typeALoc.x + builder->typeAOffset, builder->typeALoc.y);
        builder->typeA.SetLocation(typeAPos);

        Point typeBPos(builder->typeBLoc.x + builder->typeBOffset, builder->typeBLoc.y);
        builder->typeB.SetLocation(typeBPos);

        Point typeCPos(builder->typeCLoc.x + builder->typeCOffset, builder->typeCLoc.y);
        builder->typeC.SetLocation(typeCPos);

        if (shipSelect && shipSelect->bOpen)
        {
            shipSelect->Close();
        }
    }
}

void CustomShipSelect::Open()
{
    open = true;
}

void CustomShipSelect::Close()
{
    open = false;
    selectedShip = -1;
}

int CustomShipSelect::CycleShipNext(int currentShipId, int currentType)
{
    int numShips = customShipOrder.size();

    int index = GetShipButtonOrderIndex(currentShipId - 100);
    if (index == -1) index = 0;

    if (index + 1 == numShips)
    {
        index = 0;
    }
    else
    {
        index++;
    }

    int counter = 0;
    while (true)
    {
        ShipButtonDefinition* def = GetOrderedShipButtonDefinition(index);

        if (!def || !def->VariantExists(currentType) || !CustomShipUnlocks::instance->GetCustomShipUnlocked(def->name, currentType))
        {
            if (index + 1 >= numShips)
            {
                index = 0;
            }
            else
            {
                index++;
            }

            counter++;
            if (counter > 1000)
            {
                printf("Infinite loop while getting next ship!");
                break;
            }
        }
        else
        {
            index = GetShipButtonIdFromName(def->name);
            break;
        }
    }

    return index + 100;
}

int CustomShipSelect::CycleShipPrevious(int currentShipId, int currentType)
{
    int numShips = customShipOrder.size() - 1;

    int index = GetShipButtonOrderIndex(currentShipId - 100);
    if (index == -1) index = numShips;

    if (index == 0)
    {
        index = numShips;
    }
    else
    {
        index--;
    }

    int counter = 0;
    while (true)
    {
        ShipButtonDefinition* def = GetOrderedShipButtonDefinition(index);

        if (!def || !def->VariantExists(currentType) || !CustomShipUnlocks::instance->GetCustomShipUnlocked(def->name, currentType))
        {
            if (index <= 0)
            {
                index = numShips;
            }
            else
            {
                index--;
            }

            counter++;
            if (counter > 1000)
            {
                printf("Infinite loop while getting next ship!");
                break;
            }
        }
        else
        {
            index = GetShipButtonIdFromName(def->name);

            break;
        }
    }

    return index + 100;
}

int CustomShipSelect::GetRandomShipIndex()
{
    return GetShipButtonOrderIndex(random32() % shipButtonDefs.size());
}

int CustomShipSelect::CountUnlockedShips(int variant=-1)
{
    int counter = 0;

    for (int i = 0; i < (customShipOrder.size()); i++)
    {
        ShipButtonDefinition* def = GetOrderedShipButtonDefinition(i);

        if (variant != -1)
        {
            if (def && CustomShipUnlocks::instance->GetCustomShipUnlocked(def->name, variant))
            {
                if (def->VariantExists(variant))
                {
                    counter++;
                }
            }
        }
        else
        {
            counter++;
        }
    }

    return counter;
}

//==========================

HOOK_METHOD(ScoreKeeper, GetShipBlueprint, (int index) -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::GetShipBlueprint -> Begin (CustomShipSelect.cpp)\n")
    std::string ret;
    if (index >= 100)
        ret = super(0);
    else
        ret = super(index);

    if (index >= 100)
    {
        auto customSel = CustomShipSelect::GetInstance();
        ret.assign(customSel->GetShipBlueprint(index));
    }


    return ret;
}

HOOK_METHOD(UnlockArrow, MouseMove, (int x, int y) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> UnlockArrow::MouseMove -> Begin (CustomShipSelect.cpp)\n")
    auto customSel = CustomShipSelect::GetInstance();

    if (customSel->ShouldRenderArrow())
    {
        return super(x, y);
    }

    return false;
}

HOOK_METHOD(UnlockArrow, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> UnlockArrow::OnRender -> Begin (CustomShipSelect.cpp)\n")
    auto customSel = CustomShipSelect::GetInstance();

    if (customSel->ShouldRenderArrow())
    {
        super();
    }
}


HOOK_METHOD(ShipButton, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipButton::OnRender -> Begin (CustomShipSelect.cpp)\n")
    auto customSel = CustomShipSelect::GetInstance();
    if (customSel->ShouldRenderButton(this))
    {
        if (customSel->ShouldRenderButtonLower() || bShipLocked || bNoExist)
        {
            super();
        }
        else
        {
            GL_Color white = GL_Color(1.f, 1.f, 1.f, 1.f);

            Point pos = {position.x, position.y+107};
            std::string buttonLower = ((bActive && bHover) || bSelected) ? "customizeUI/ship_list_button_lower_select2.png" : "customizeUI/ship_list_button_lower_on.png";
            G_->GetResources()->RenderImageString(buttonLower, pos.x, pos.y, 0, white, 1.f, false);
            pos.y += 16;
            pos.x += 6;
            for (int i=0; i<achievements.size(); ++i)
            {
                if (achievements[i]) achievements[i]->OnRender(pos, (iSelectedAch == i) ? 2 : 3, false);
                pos.x += 37;
            }

            Button::OnRender();
            G_->GetResources()->RenderImage(iShipImage, position.x, position.y, 0, white, 1.f, false);
        }
    }
}

HOOK_METHOD_PRIORITY(ShipButton, MouseMove, 9999, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipButton::MouseMove -> Begin (CustomShipSelect.cpp)\n")
    iSelectedAch = -1;
    if (!bShipLocked)
    {
        int b_y = position.y;
        int b_x = position.x + 6;
        if (y > b_y + 123 && y < b_y + 155)
        {
            for (int i=0; i<achievements.size(); ++i, b_x+=37)
            {
                if (x > b_x && x < b_x + 32)
                {
                    if (achievements[i] && achievements[i] != CustomShipSelect::GetInstance()->dummyAchievement)
                    {
                        G_->GetAchievementTracker()->SetTooltip(achievements[i]);
                        iSelectedAch = i;
                    }
                    break;
                }
            }
        }
    }
    GenericButton::MouseMove(x, y, false);
}

HOOK_METHOD(ShipSelect, MouseClick, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSelect::MouseClick -> Begin (CustomShipSelect.cpp)\n")
    super();

    auto customSel = CustomShipSelect::GetInstance();
    customSel->MouseClick();
}

HOOK_METHOD(ShipSelect, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSelect::MouseMove -> Begin (CustomShipSelect.cpp)\n")
    auto customSel = CustomShipSelect::GetInstance();

    if (customSel->FirstPage())
    {
        super(x, y);
    }



    customSel->MouseMove(x, y);
}

HOOK_METHOD(ShipSelect, Open, (int currentLayout, int currentType) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSelect::Open -> Begin (CustomShipSelect.cpp)\n")
    super(currentLayout, currentType);

    auto customSel = CustomShipSelect::GetInstance();
    customSel->OnInit(this);
    customSel->Open();
}

HOOK_METHOD(ShipSelect, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSelect::OnRender -> Begin (CustomShipSelect.cpp)\n")
    auto customSel = CustomShipSelect::GetInstance();

    if (customSel->FirstPage())
    {
        super();
    }
    else
    {
        super();
        customSel->OnRender(true);
    }

    customSel->OnRender();
}



HOOK_METHOD(ShipBuilder, SwitchShip, (int shipType, int shipVariant) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::SwitchShip -> Begin (CustomShipSelect.cpp)\n")
    if (shipType >= 100)
    {
        auto customSel = CustomShipSelect::GetInstance();

        customSel->SwitchShip(this, shipType, shipVariant);

        return;
    }

    return super(shipType, shipVariant);
}

// TODO: Why??? There's no implemenation here
HOOK_METHOD(AchievementTracker, GetShipAchievements, (std::string& ship) -> std::vector<CAchievement*>)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::GetShipAchievements -> Begin (CustomShipSelect.cpp)\n")
    return super(ship);
}

HOOK_METHOD(ShipBuilder, MouseClick, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::MouseClick -> Begin (CustomShipSelect.cpp)\n")
    super(x, y);

    auto customSel = CustomShipSelect::GetInstance();

    if (customSel->Initialized() && customSel->GetSelection() != -1)
    {
        currentShip->~ShipManager();

        customSel->SwitchShip(this, customSel->GetSelectedId(), shipSelect.currentType, true);
        customSel->ClearSelection();
    }
    else
    {
        if (customSel->shipAchievementsToggle && x > 244 && x < 276 && y > 438 && y < 470) // victory icon
        {
            customSel->showShipAchievements = !customSel->showShipAchievements;

            G_->GetSoundControl()->PlaySoundMix(customSel->showShipAchievements ? "powerDownSystem" : "powerUpSystem", -1.f, false);
        }
    }
}

HOOK_METHOD(ShipBuilder, SwapType, (int variant) -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::SwapType -> Begin (CustomShipSelect.cpp)\n")
    return super(variant);
}

HOOK_METHOD(ShipSelect, Close, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSelect::Close -> Begin (CustomShipSelect.cpp)\n")
    super();
    auto customSel = CustomShipSelect::GetInstance();
    customSel->Close();
}

HOOK_METHOD(ShipBuilder, CycleShipNext, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::CycleShipNext -> Begin (CustomShipSelect.cpp)\n")
    auto customSel = CustomShipSelect::GetInstance();

    if (currentShipId >= 100)
    {
        currentShip->~ShipManager();

        customSel->SwitchShip(this, customSel->CycleShipNext(currentShipId, currentType), currentType);
    }
    else
    {
        super();
    }
}

HOOK_METHOD(ShipBuilder, CycleShipPrevious, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::CycleShipPrevious -> Begin (CustomShipSelect.cpp)\n")
    auto customSel = CustomShipSelect::GetInstance();

    if (currentShipId >= 100)
    {
        currentShip->~ShipManager();

        customSel->SwitchShip(this, customSel->CycleShipPrevious(currentShipId, currentType), currentType);
    }
    else
    {
        super();
    }

}

HOOK_METHOD(ShipBuilder, MouseClick, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::MouseClick -> Begin (CustomShipSelect.cpp)\n")
    if (randomButton.bActive && randomButton.bHover)
    {
        auto customSel = CustomShipSelect::GetInstance();

        if (currentShipId >= 100 && customSel->Initialized())
        {
            std::vector<std::pair<int, int>> unlocked = std::vector<std::pair<int, int>>();

            int counter = 0;

            while (unlocked.size() == 0)
            {
                int id = customSel->GetRandomShipIndex();

                std::string blueprintName = customSel->customShipOrder[id];

                for (int i = 0; i < 3; i++)
                {
                    if (customSel->GetOrderedShipButtonDefinition(id)->VariantExists(i) && CustomShipUnlocks::instance->GetCustomShipUnlocked(blueprintName, i))
                    {
                        unlocked.push_back(std::pair<int, int>(customSel->GetShipButtonIdFromName(blueprintName) + 100, i));
                    }
                }

                counter++;
                if (counter >= 100) break;

            }


            if (counter != 100)
            {
                auto randomShip = unlocked[random32() % unlocked.size()];

                currentShip->~ShipManager();

                customSel->SwitchShip(this, randomShip.first, randomShip.second, true);
            }
        }
        else
        {
            super(x, y);
        }
    }
    else
    {
        super(x, y);
    }
}

HOOK_METHOD(ShipBuilder, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::OnLoop -> Begin (CustomShipSelect.cpp)\n")
    if (Global::forceDlc)
    {
        *Global::dlcEnabled = true;
    }

    super();

    if (currentShipId >= 100)
    {
        auto customSel = CustomShipSelect::GetInstance();

        ShipButtonDefinition *def = &customSel->GetShipButtonDefinition(currentShipId-100);

        bool buttonsActive = false;

        buttonsActive = customSel->CountUnlockedShips(currentType) > 1;

        leftButton.SetActive(buttonsActive);
        rightButton.SetActive(buttonsActive);
        randomButton.SetActive(customSel->CountUnlockedShips(-1) > 1);
        startButton.SetActive(Settings::GetDlcEnabled() || !def->VariantNeedsDlc(currentType));
    }
    else
    {
        startButton.SetActive(Settings::GetDlcEnabled() || (currentShipId != 9 && currentType != 2));
    }

    for (auto i : CustomShipSelect::GetInstance()->customAnims)
    {
        i.second->Update();
    }
}

static GL_Texture* seedBox;
static GL_Primitive* unlocksDisabledPrimitive;


HOOK_METHOD(MenuScreen, constructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MenuScreen::constructor -> Begin (CustomShipSelect.cpp)\n")
    super();

    seedBox = G_->GetResources()->GetImageId("optionsUI/info_seed.png");
    auto unlocksDisabledTexture = G_->GetResources()->GetImageId("customizeUI/unlocks_disabled.png");
    unlocksDisabledPrimitive = CSurface::GL_CreateImagePrimitive(unlocksDisabledTexture, 1106.f - unlocksDisabledTexture->width_ / 2, 104, unlocksDisabledTexture->width_, unlocksDisabledTexture->height_, 0.f, COLOR_WHITE);
}

static Button* reactorInfoButton = nullptr;
static Point reactorInfoPos = {335, 380};

HOOK_METHOD_PRIORITY(ShipBuilder, OnRender, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipBuilder::OnRender -> Begin (CustomShipSelect.cpp)\n")
    bool isVanillaShip = currentShipId < 100;

    auto customSel = CustomShipSelect::GetInstance();
    
    bool showShipAchievements = customSel->ShowAchievementsForShip(currentShipId, currentType);

    if (Global::forceDlc)
    {
        advancedOffButton.bActive = false;
        advancedOnButton.bActive = false;

        advancedOffButton.position.x = 4000;
        advancedOnButton.position.x = 4000;
        advancedOffButton.hitbox.x = 4000;
        advancedOnButton.hitbox.x = 4000;
    }

    // Tint if shipSelect is open

    if (shipSelect.bOpen)
    {
        GL_Color tint(0.25f, 0.25f, 0.25f, 1.f);
        CSurface::GL_SetColorTint(tint);
    }

    // Render background

    CSurface::GL_DisableBlend();
    CSurface::GL_RenderPrimitive(baseImage);

    CSurface::GL_EnableBlend();

    // Render custom animations

    for (auto i : CustomShipSelect::GetInstance()->customAnims)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(i.first.x, i.first.y);

        i.second->OnRender(1.f, COLOR_WHITE, false);

        CSurface::GL_PopMatrix();
    }

    // Render the ship

    CSurface::GL_PushMatrix();

    bool dlcLocked = !Settings::GetDlcEnabled();
    if (dlcLocked)
    {
        if (isVanillaShip)
        {
            dlcLocked = currentShipId == 9 || currentType == 2;
        }
        else
        {
            ShipButtonDefinition *def = &customSel->GetShipButtonDefinition(currentShipId-100);
            dlcLocked = def->VariantNeedsDlc(currentType);
        }
    }

    if (dlcLocked)
    {
        CSurface::GL_SetColorTint(COLOR_TINT);
    }

    CSurface::GL_Translate(currentShip->ship.horizontal_shift + 365.f, currentShip->ship.vertical_shift + 30.f);
    currentShip->OnRender(true, false);

    CSurface::GL_PopMatrix();

    // Render startButtonBox

    CSurface::GL_RenderPrimitive(startButtonBox);

    // Render AE warning

    if (dlcLocked)
    {
        CSurface::GL_RemoveColorTint();
        CSurface::GL_RenderPrimitive(enableAdvancedPrimitive);
    }

    // Render shipEquipBox

    CSurface::GL_RenderPrimitive(shipEquipBox);

    // Render shipSelectBox

    CSurface::GL_RenderPrimitive(shipSelectBox);

    // Render shipAchBox

    if (isVanillaShip)
    {
        CSurface::GL_RenderPrimitive(shipAchBox);
    }
    else
    {
        CSurface::GL_RenderPrimitive(shipAchBox); //for now
    }

    // Render advancedButtonBox (AE toggle)

    if (!Global::forceDlc)
    {
        CSurface::GL_RenderPrimitive(advancedButtonBox);
    }

    // Render texts

    CSurface::GL_SetColor(g_defaultTextButtonColors[3]); // color used for text overlays

    TextLibrary* lib = G_->GetTextLibrary();

    std::string langTxt;
    freetype::easy_print(62, 19, 117, lib->GetText("hangar_frame_ship"));
    freetype::easy_print(62, 19, 219, lib->GetText("hangar_frame_layout"));
    freetype::easy_print(62, 19, 489, lib->GetText("hangar_frame_crew"));
    freetype::easy_print(62, 388, 489, lib->GetText("equipment_frame_weapons"));
    freetype::easy_print(62, 388, 599, lib->GetText("equipment_frame_drones"));
    freetype::easy_print(62, 954, 489, lib->GetText("equipment_frame_augments"));

    CSurface::GL_SetColor(g_defaultTextButtonColors[1]); // color used for achievement title

    if (showShipAchievements)
    {
        if (isVanillaShip)
        {
            // Vanilla achievement heading
            freetype::easy_printCenter(13, 124, 374, lib->GetText("hangar_achievements_title"));
        }
        else
        {
            ShipButtonDefinition *def = &customSel->GetShipButtonDefinition(currentShipId-100);

            if (def->shipAchievementHeading.data.empty())
            {
                // Default custom achievement heading
                freetype::easy_printCenter(13, 124, 374, lib->GetText(customSel->shipAchievementsTitle));
            }
            else
            {
                // Ship specific custom achievement heading
                freetype::easy_printCenter(13, 124, 374, def->shipAchievementHeading.GetText());
            }
        }
    }
    else
    {
        // Ship victory heading
        freetype::easy_printCenter(13, 124, 374, lib->GetText("hangar_achievements_title_custom"));
    }

    if (!Global::forceDlc)
    {
        freetype::easy_printCenter(13, 1109, 400, lib->GetText("hangar_advanced_title"));
    }

    CSurface::GL_SetColor(GL_Color(1.f, 1.f, 1.f, 1.f));

    // Render vanilla hangar animations

    for (auto &anim: animations)
    {
        anim.OnRender(1.f, COLOR_WHITE, false);
    }

    walkingMan.OnRender(1.f, COLOR_WHITE, false);

    // Render ship name box

    CSurface::GL_RenderPrimitive(nameBoxPrimitive);

    // Render ship equipment boxes

    for (auto &box: vEquipmentBoxes)
    {
        if (box->CanDoJob())
        {
            if (bCustomizingCrew)
            {
                if (!box->CanHoldCrew())
                {
                    box->OnRender(false);
                    box->RenderLabels(false);
                }
            }
            else
            {
                box->OnRender(false);
                box->RenderLabels(false);
            }
        }

    }

    // Render ship crew boxes

    for (auto &box: vCrewBoxes)
    {
        if (box->bCustomizing)
        {
            box->OnRender(false);
            break;
        }
    }

    // Render buttons

    for (auto &button: buttons)
    {
        button->OnRender();
    }

    // Render system boxes

    for (auto &sys: sysBoxes)
    {
        sys->OnRender(true);
    }

    // Render encourageShipList

    if (encourageShipList)
    {
        int buttonX = listButton.position.x;
        int buttonY = listButton.position.y;


        CSurface::GL_BlitPixelImage(arrow, buttonX + 75, buttonY - 4, 164, 38, 0, COLOR_WHITE, true);
        descBox->Draw(buttonX + 245, buttonY - 47);
        freetype::easy_printAutoNewlines(12, buttonX + 265, buttonY - 27, 308, lib->GetText("tutorial_list_open"));
    }


    CSurface::GL_SetColor(COLOR_WHITE);

    Point shipNamePos = Point(273, 7);
    nameInput.OnRender(24, shipNamePos);

    // FIXED WTIH freetype_hack (fixed with new use that no longer needs freetype_hack but I don't see y being used anyways)

    // This doesn't work because of easy_measurePrintLines returning a Pointf
    // Need a way to get the y value of the returned Pointf
    // The Pointf is returned split into eax and edx

    // FIXED WITH freetype_hack (fixed with new use that no longer needs freetype_hack but I don't see y being used anyways)
    if (bRenaming)
    {
        Pointf ret = freetype::easy_measurePrintLines(12, 0, 0, 999, lib->GetText("rename"));
        float x = 6.f;
        float x2 = 227.f - ret.x / 2;
        if (x2 > 5)
            x = x2;
        freetype::easy_print(12, x, 65.f, lib->GetText("rename"));
    }

    if (!currentShip->HasSystem(3))
    {
        freetype::easy_printCenter(63, 662, 539, lib->GetText("equipment_no_system"));
    }
    if (!currentShip->HasSystem(4))
    {
        freetype::easy_printCenter(63, 662, 649, lib->GetText("equipment_no_system"));
    }

    CSurface::GL_SetColor(COLOR_WHITE);

    // Do victory/quest achievements and regular ship achievements

    ShipButtonDefinition *shipButtonDef = nullptr;
    std::string finalName;

    if (isVanillaShip)
    {
        int counter = 0;
        for (auto &ach: shipAchievements)
        {
            Point pos(ach.position.x, ach.position.y);

            if (counter >= 3)
            {
                ach.achievement->OnRender(pos, selectedAch == counter ? 2 : 3, 1);
            }
            else if (showShipAchievements)
            {
                ach.achievement->OnRender(pos, selectedAch == counter, 1);
            }

            counter++;
        }
    }
    else
    {
        shipButtonDef = &customSel->GetShipButtonDefinition(currentShipId-100);

        finalName = customSel->GetVariantName(shipButtonDef->name, currentType);

        CAchievement *ach = nullptr;
        if (shipButtonDef->splitVictoryAchievement)
        {
            ach = CustomShipUnlocks::instance->GetVictoryAchievement(finalName);
        }
        else
        {
            ach = CustomShipUnlocks::instance->GetVictoryAchievement(shipButtonDef->name);
        }

        if (ach)
        {
            ach->OnRender(Point(244, 438), selectedAch == 3 ? 2 : 3, 1);
        }

        ach = nullptr;
        if (shipButtonDef->splitUnlockQuestAchievement)
        {
            if (CustomShipUnlocks::instance->CustomShipHasUnlockQuest(finalName))
            {
                ach = CustomShipUnlocks::instance->GetQuestAchievement(finalName);
            }
        }
        else
        {
            if (CustomShipUnlocks::instance->CustomShipHasUnlockQuestAnyLayout(shipButtonDef->name))
            {
                ach = CustomShipUnlocks::instance->GetQuestAchievement(shipButtonDef->name);
            }
        }

        if (ach)
        {
            ach->OnRender(Point(244, 404), selectedAch == 4 ? 2 : 3, 1);
        }

        if (showShipAchievements)
        {
            std::vector<CAchievement*> customShipAchievements = CustomAchievementTracker::instance->GetShipAchievementsCustom(currentShipId, currentType, false);
            int counter = 0;
            int maxCounter = customShipAchievements.size()<3 ? customShipAchievements.size() : 3;

            if (maxCounter > 0)
            {
                for (CAchievement* ach: customShipAchievements)
                {
                    ach->OnRender(Point(126 - 35*maxCounter + 70*counter, 404), selectedAch == counter, 1);
                    if (++counter >= maxCounter) break;
                }
            }
            else
            {
                CSurface::GL_SetColor(g_defaultTextButtonColors[1]);
                freetype::easy_printCenter(13, 124, 429, lib->GetText("hangar_no_ship_achievements"));
            }
        }
    }

    // Do individual victory achievements

    if (!showShipAchievements)
    {
        std::vector<std::string> victoryTypes;
        for (std::string &i : CustomShipUnlocks::instance->customVictoryTypes)
        {
            if (!CustomShipUnlocks::instance->customVictories[i].secret || !CustomShipUnlocks::instance->customVictories[i].SecretLocked())
            {
                victoryTypes.push_back(i);
            }
        }

        int max_a = victoryTypes.size()%6;
        int max_b = victoryTypes.size()/6;
        for (int i=0; i<victoryTypes.size(); ++i)
        {
            CAchievement *ach = nullptr;

            if (!shipButtonDef)
            {
                ach = CustomShipUnlocks::instance->customVictories[victoryTypes[i]].GetVictoryAchievement(customSel->GetShipBlueprint(currentShipId));
            }
            else if (shipButtonDef->splitVictoryAchievement)
            {
                ach = CustomShipUnlocks::instance->customVictories[victoryTypes[i]].GetVictoryAchievement(finalName);
            }
            else
            {
                ach = CustomShipUnlocks::instance->customVictories[victoryTypes[i]].GetVictoryAchievement(shipButtonDef->name);
            }

            int a = i%6;
            int b = i/6;

            ach->OnRender(Point(124 - 17*(b==max_b ? max_a : 6) + 34*a, 437 - 17*((victoryTypes.size()+5)/6) + 34*b), selectedAch == -i-2 ? 2 : 3, 1);
        }
    }

    if (SeedInputBox::seedInput)
	{
		SeedInputBox::seedInput->OnRender(0, Point((int)SeedInputBox::drawLocation.x+2+(SeedInputBox::width/2), (int)SeedInputBox::drawLocation.y+5));

		std::string inputSeed = SeedInputBox::seedInput->GetText();

		if (inputSeed != "" && !SeedInputBox::seedsAllowUnlocks)
        {
            CSurface::GL_RenderPrimitive(unlocksDisabledPrimitive);
        }
	}

	if (!reactorInfoButton)
    {
        reactorInfoButton = new Button();
        reactorInfoButton->OnInit("customizeUI/box_system", Point(reactorInfoPos.x, reactorInfoPos.y));
        reactorInfoButton->bActive = true;
        reactorInfoButton->SetLocation(Point(reactorInfoPos.x, reactorInfoPos.y));
    }

	if (CustomOptionsManager::GetInstance()->showReactor.currentValue)
    {
        reactorInfoButton->OnRender();
        std::string reactorImagePath = "icons/s_reactor_green1.png";
        G_->GetResources()->RenderImageString(reactorImagePath, reactorInfoPos.x-13, reactorInfoPos.y+45, 0, {1.f,1.f,1.f,1.f}, 1.f, false);
        auto def = CustomShipSelect::GetInstance()->GetDefinition(currentShip->myBlueprint.blueprintName);
        CSurface::GL_SetColor(GL_Color(100.0/255, 1, 100.0/255, 1));
        freetype::easy_printCenter(52, reactorInfoPos.x+18, reactorInfoPos.y+25, std::to_string(PowerManager::GetPowerManager(0)->currentPower.second));
        freetype::easy_printCenter(52, reactorInfoPos.x+18, reactorInfoPos.y+43, std::to_string(def.maxReactorLevel));
        freetype::easy_printCenter(52, reactorInfoPos.x+19, reactorInfoPos.y+27, "_");
        CSurface::GL_SetColor(COLOR_WHITE);
    }

    CSurface::GL_RemoveColorTint();
    if (shipSelect.bOpen)
    {
        shipSelect.OnRender();
    }
    else
    {
        infoBox.OnRender();
    }

    introScreen.OnRender();
}

HOOK_METHOD(ShipBuilder, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::MouseMove -> Begin (CustomShipSelect.cpp)\n")
    super(x,y);

    if (introScreen.bOpen) return;
    if (shipSelect.bOpen) return;

    auto customSel = CustomShipSelect::GetInstance();

    ShipButtonDefinition *shipButtonDef = nullptr;
    std::string finalName;

    bool showShipAchievements = customSel->ShowAchievementsForShip(currentShipId, currentType);

    if (currentShipId >= 100)
    {
        shipButtonDef = &customSel->GetShipButtonDefinition(currentShipId-100);


        finalName = customSel->GetVariantName(shipButtonDef->name, currentType);

        if (x > 244 && x < 276)
        {
            if (y > 404 && y < 436)
            {
                CAchievement *ach = nullptr;

                if (shipButtonDef->splitUnlockQuestAchievement)
                {
                    if (CustomShipUnlocks::instance->CustomShipHasUnlockQuest(finalName))
                    {
                        ach = CustomShipUnlocks::instance->GetQuestAchievement(finalName);
                    }
                }
                else
                {
                    if (CustomShipUnlocks::instance->CustomShipHasUnlockQuestAnyLayout(shipButtonDef->name))
                    {
                        ach = CustomShipUnlocks::instance->GetQuestAchievement(shipButtonDef->name);
                    }
                }

                if (ach)
                {
                    G_->GetAchievementTracker()->SetTooltip(ach);
                    selectedAch = 4;
                }
            }
            else if (y > 438 && y < 470)
            {
                CAchievement *ach = nullptr;

                if (shipButtonDef->splitVictoryAchievement)
                {
                    ach = CustomShipUnlocks::instance->GetVictoryAchievement(finalName);
                }
                else
                {
                    ach = CustomShipUnlocks::instance->GetVictoryAchievement(shipButtonDef->name);
                }

                if (ach)
                {
                    G_->GetAchievementTracker()->SetTooltip(ach);
                    selectedAch = 3;
                }
            }
        }
        else if (showShipAchievements)
        {
            std::vector<CAchievement*> customShipAchievements = CustomAchievementTracker::instance->GetShipAchievementsCustom(currentShipId, currentType, false);
            int counter = 0;
            int maxCounter = customShipAchievements.size()<3 ? customShipAchievements.size() : 3;

            for (CAchievement* ach: customShipAchievements)
            {
                Point pos(126 - 35*maxCounter + 70*counter, 404);

                if (x > pos.x && x < pos.x+64 && y > pos.y && y < pos.y+64)
                {
                    G_->GetAchievementTracker()->SetTooltip(ach);
                    selectedAch = counter;
                }

                if (++counter >= maxCounter) break;
            }
        }
    }

    if (!showShipAchievements)
    {
        // deselect ship achievements
        if (selectedAch >= 0 && selectedAch < 3)
        {
            G_->GetMouseControl()->tooltip = "";
            G_->GetMouseControl()->tooltipTitle = "";
            selectedAch = -1;
        }

        std::vector<std::string> victoryTypes;
        for (std::string &i : CustomShipUnlocks::instance->customVictoryTypes)
        {
            if (!CustomShipUnlocks::instance->customVictories[i].secret || !CustomShipUnlocks::instance->customVictories[i].SecretLocked())
            {
                victoryTypes.push_back(i);
            }
        }

        int max_a = victoryTypes.size()%6;
        int max_b = victoryTypes.size()/6;
        for (int i=0; i<victoryTypes.size(); ++i)
        {
            CAchievement *ach;

            if (!shipButtonDef)
            {
                ach = CustomShipUnlocks::instance->customVictories[victoryTypes[i]].GetVictoryAchievement(customSel->GetShipBlueprint(currentShipId));
            }
            else if (shipButtonDef->splitVictoryAchievement)
            {
                ach = CustomShipUnlocks::instance->customVictories[victoryTypes[i]].GetVictoryAchievement(finalName);
            }
            else
            {
                ach = CustomShipUnlocks::instance->customVictories[victoryTypes[i]].GetVictoryAchievement(shipButtonDef->name);
            }

            int a = i%6;
            int b = i/6;

            Point pos(124 - 17*(b==max_b ? max_a : 6) + 34*a, 437 - 17*((victoryTypes.size()+5)/6) + 34*b);

            if (x > pos.x && x < pos.x+32 && y > pos.y && y < pos.y+32)
            {
                G_->GetAchievementTracker()->SetTooltip(ach);
                selectedAch = -i-2;
            }
        }
    }

    if (reactorInfoButton)
    {
        reactorInfoButton->MouseMove(x,y,false);
        if (reactorInfoButton->bHover)
        {
            auto def = CustomShipSelect::GetInstance()->GetDefinition(currentShip->myBlueprint.blueprintName);
            std::string reactorDescText = G_->GetTextLibrary()->GetText("reactor_desc") + "\n\n" +
                                          boost::algorithm::replace_all_copy(G_->GetTextLibrary()->GetText("reactor_desc_start"), "\\1", std::to_string(PowerManager::GetPowerManager(0)->currentPower.second)) + "\n" +
                                          boost::algorithm::replace_all_copy(G_->GetTextLibrary()->GetText("reactor_desc_max"), "\\1", std::to_string(def.maxReactorLevel));
            infoBox.SetText(G_->GetTextLibrary()->GetText("upgrade_reactor"), reactorDescText, -1, -1, InfoBox::EXPAND_DOWN);
        }
    }
}


HOOK_METHOD(GameOver, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> GameOver::OnRender -> Begin (CustomShipSelect.cpp)\n")
    if (bShowStats)
    {
        CSurface::GL_SetColorTint(COLOR_TINT);
    }

    if (SeedInputBox::seedsEnabled)
    {
        CSurface::GL_BlitPixelImageWide(seedBox,
                                position.x + 160.f,
                                position.y + 325.f,
                                162,
                                72,
                                1.f,
                                COLOR_WHITE,
                                false);

        CSurface::GL_SetColor(COLOR_BUTTON_ON);

        freetype::easy_printCenter(13, position.x + 81.f + 160.f, position.y + 325.f + 16.f, G_->GetTextLibrary()->GetText("menu_status_seed"));

        CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

        char buf[12];

        sprintf(buf, "%u", Global::currentSeed);

        freetype::easy_printCenter(62, position.x + 81.f + 160.f, position.y + 325.f + 40.f, std::string(buf));
    }

    if (bShowStats)
    {
        CSurface::GL_RemoveColorTint();
    }

    super();
}

HOOK_METHOD(MenuScreen, Open, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MenuScreen::Open -> Begin (CustomShipSelect.cpp)\n")

    super();

    if (G_->GetWorld()->playerShip)
    {
        ShipManager *ship = G_->GetWorld()->playerShip->shipManager;
        ShipManager_Extend *ex = SM_EX(ship);
        if (ex->isNewShip)
        {
            auto customSel = CustomShipSelect::GetInstance();
            std::pair<int,int> shipId = customSel->GetShipIdAndVariantFromName(ship->myBlueprint.blueprintName);

            if (shipId.first >= 0)
            {
                if (!customSel->dummyAchievement)
                {
                    customSel->dummyAchievement = new CAchievement();
                    customSel->dummyAchievement->gap_ex_custom = -127;
                }

                ShipButtonDefinition &buttonDef = customSel->GetShipButtonDefinition(shipId.first);

                shipAchievements.clear();

                std::vector<CAchievement*> customShipAchievements = CustomAchievementTracker::instance->GetShipAchievementsCustom(shipId.first+100, shipId.second, false);
                int maxCount = std::min(int(customShipAchievements.size()),3);
                for (auto i=0; i<maxCount; ++i)
                {
                    shipAchievements.push_back({customShipAchievements[i], Point(727.5 - 30.5*maxCount + 71*i, 362), 64});
                }
                for (auto i=maxCount; i<3; ++i) // need to insert dummies so that the victory and quest achievements render correctly
                {
                    shipAchievements.push_back({customSel->dummyAchievement, Point(-2147483647, -2147483647), 0});
                }

                CAchievement *ach = nullptr;
                if (buttonDef.splitVictoryAchievement)
                {
                    ach = CustomShipUnlocks::instance->GetVictoryAchievement(ship->myBlueprint.blueprintName);
                }
                else
                {
                    ach = CustomShipUnlocks::instance->GetVictoryAchievement(buttonDef.name);
                }
                if (ach) shipAchievements.push_back({ach, Point(859, 396), 32});

                ach = nullptr;
                if (buttonDef.splitUnlockQuestAchievement)
                {
                    if (CustomShipUnlocks::instance->CustomShipHasUnlockQuest(ship->myBlueprint.blueprintName))
                    {
                        ach = CustomShipUnlocks::instance->GetQuestAchievement(ship->myBlueprint.blueprintName);
                    }
                }
                else
                {
                    if (CustomShipUnlocks::instance->CustomShipHasUnlockQuestAnyLayout(buttonDef.name))
                    {
                        ach = CustomShipUnlocks::instance->GetQuestAchievement(buttonDef.name);
                    }
                }
                if (ach) shipAchievements.push_back({ach, Point(859, 362), 32});
            }
        }
    }
}
//TODO: Might be nice to also show victories here (Like in the ship select menu)
HOOK_METHOD_PRIORITY(MenuScreen, OnRender, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> MenuScreen::OnRender -> Begin (CustomShipSelect.cpp)\n")
    if (G_->GetWorld()->playerShip)
    {
        auto customSel = CustomShipSelect::GetInstance();
        int currentShipId = G_->GetCApp()->menu.shipBuilder.currentShipId;
        bool specificShipAchievements = currentShipId < 100 || customSel->GetShipButtonDefinition(currentShipId - 100).showShipAchievements;
        if ((!SM_EX(G_->GetWorld()->playerShip->shipManager)->isNewShip || CustomShipSelect::GetInstance()->showShipAchievements || CustomShipSelect::GetInstance()->shipAchievementsToggle) && specificShipAchievements)
        {
            super();

            if (!bShowControls && !G_->GetTutorialManager()->Running())
            {
                if (confirmDialog.bOpen)
                {
                    CSurface::GL_SetColorTint(COLOR_TINT);
                }

                // todo: checking !confirmDialog.bOpen is a hacky solution keep this from drawing
                //       on top of the "return to hangar" prompt, this function needs to be
                //       reverse-engineered and re-implemented to fix properly
                if (!confirmDialog.bOpen && (shipAchievements.empty() || shipAchievements[0].dimension != 64))
                {
                    //CSurface::GL_SetColor(g_defaultTextButtonColors[1]);
                    CSurface::GL_SetColor(COLOR_BUTTON_ON);
                    freetype::easy_printCenter(13, 742, 387, G_->GetTextLibrary()->GetText("hangar_no_ship_achievements"));
                }
                // todo: add "ACHIEVEMENTS DISABLED" overlay for seeded runs

                CSurface::GL_BlitPixelImageWide(seedBox,
                                        statusPosition.x + 66,
                                        statusPosition.y + 205,
                                        162,
                                        72,
                                        1.f,
                                        COLOR_WHITE,
                                        false);

                CSurface::GL_SetColor(COLOR_BUTTON_ON);

                freetype::easy_printCenter(13, statusPosition.x + 66.f + 81.f, statusPosition.y + 205.f + 16.f, G_->GetTextLibrary()->GetText("menu_status_seed"));

                CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

                char buf[12] = "-";

                if (SeedInputBox::seedsEnabled)
                {
                    sprintf(buf, "%u", Global::currentSeed);
                }
                freetype::easy_printCenter(62, statusPosition.x + 66.f + 81.f, statusPosition.y + 205.f + 40, std::string(buf));

                if (confirmDialog.bOpen)
                {
                    CSurface::GL_RemoveColorTint();
                }
            }


            return;
        }
    }

    if (bShowControls || G_->GetTutorialManager()->Running())
    {
        return super();
    }

    if (!menuPrimitive)
    {
        std::vector<GL_TexVertex> texVertices = std::vector<GL_TexVertex>();
        GL_Texture *img = mainImage;
        float unk1 = 81.f;
        float unk2 = 1.f;
        float unk3 = 1.f;

        if (img)
        {
            unk1 = 81.f / img->width_;
            unk2 = img->width_;
            unk3 = img->height_;
        }

        CSurface::AddTexVertices(&texVertices, position.x, position.y, 81.f, unk3, 0, unk1, 0, 1.f);
        CSurface::AddTexVertices(&texVertices, position.x + 81.f, position.y, menuWidth - 161.f, unk3, unk1, 82.f / unk2, 0, 1.f);
        CSurface::AddTexVertices(&texVertices, (menuWidth + position.x) - 80.f, position.y, 80.f, unk3, 82.f / unk2, 162.f / unk2, 0, 1.f);
        menuPrimitive = CSurface::GL_CreateMultiImagePrimitive(mainImage, &texVertices, COLOR_WHITE);
    }


    if (confirmDialog.bOpen)
    {
        CSurface::GL_SetColorTint(COLOR_TINT);
    }

    CSurface::GL_RenderPrimitive(menuPrimitive);

    for (auto &button : buttons)
    {
        button->OnRender();
    }

    CSurface::GL_BlitPixelImageWide(difficultyBox,
                                    statusPosition.x,
                                    statusPosition.y,
                                    difficultyWidth,
                                    72,
                                    1.f,
                                    COLOR_WHITE,
                                    false);


    CSurface::GL_BlitPixelImageWide(dlcBox,
                                    statusPosition.x + difficultyWidth + 3,
                                    statusPosition.y,
                                    dlcWidth,
                                    72,
                                    1.f,
                                    COLOR_WHITE,
                                    false);



    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    freetype::easy_printCenter(13, statusPosition.x + (difficultyWidth + 1.f) / 2.f, statusPosition.y + 16.f, difficultyLabel);
    freetype::easy_printCenter(13, statusPosition.x + difficultyWidth + (dlcWidth + 1.f) / 2.f + 3.f, statusPosition.y + 16.f, dlcLabel);

    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

    freetype::easy_printCenter(62, statusPosition.x + (difficultyWidth + 1.f) / 2.f, statusPosition.y + 40, difficultyText);
    freetype::easy_printCenter(62, statusPosition.x + difficultyWidth + (dlcWidth + 1.f) / 2.f + 3.f, statusPosition.y + 40.f, dlcText);


    CSurface::GL_BlitPixelImageWide(seedBox,
                                    statusPosition.x + 66,
                                    statusPosition.y + 72,
                                    162,
                                    72,
                                    1.f,
                                    COLOR_WHITE,
                                    false);



    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    freetype::easy_printCenter(13, statusPosition.x + 81.f + 66.f, statusPosition.y + 72.f + 16.f, G_->GetTextLibrary()->GetText("menu_status_seed"));

    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

    char buf[12] = "-";
    if (SeedInputBox::seedsEnabled)
    {
        sprintf(buf, "%u", Global::currentSeed);
    }
    freetype::easy_printCenter(62, statusPosition.x + 81.f + 66.f, statusPosition.y + 72.f + 40, std::string(buf));


    if (confirmDialog.bOpen)
    {
        CSurface::GL_RemoveColorTint();
        confirmDialog.OnRender();
    }
}

HOOK_METHOD(ShipBuilder, Open, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::Open -> Begin (CustomShipSelect.cpp)\n")
    auto customSel = CustomShipSelect::GetInstance();

    StatBoostManager::GetInstance()->statBoosts.clear();
    StatBoostManager::GetInstance()->animBoosts.clear();
    StatBoostManager::GetInstance()->statCacheFrame++;

    super();

    customSel->OnInit(&shipSelect);

    if (customSel->hideFirstPage)
    {
        currentShip->~ShipManager();

        customSel->SwitchShip(this, customSel->GetShipButtonIdFromName(customSel->customShipOrder[0]) + 100, 0);
    }
}

HOOK_METHOD(ShipBuilder, OnKeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::OnKeyDown -> Begin (CustomShipSelect.cpp)\n")
    if (key == SDLKey::SDLK_UP
        || key == SDLKey::SDLK_LEFT
        || key == SDLKey::SDLK_RIGHT
        || key == SDLKey::SDLK_DOWN)
    {
        return;
    }

    super(key);
}
