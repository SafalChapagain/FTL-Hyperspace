#include "CustomAugments.h"
#include "CustomOptions.h"
#include "EnemyShipIcons.h"
#include "Global.h"
#include "ShipManager_Extend.h"
#include "CustomEvents.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

CustomAugmentManager CustomAugmentManager::instance = CustomAugmentManager();

void CustomAugmentManager::ParseCustomAugmentNode(rapidxml::xml_node<char>* node)
{
    try
    {
        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            if (strcmp(child->name(), "aug") == 0)
            {
                const std::string& augName = child->first_attribute("name")->value();
                AugmentDefinition* augDef = new AugmentDefinition();

                augDef->name = augName;
                augDef->functions = std::unordered_multimap<std::string, AugmentFunction>();

                for (auto functionNode = child->first_node(); functionNode; functionNode = functionNode->next_sibling())
                {
                    std::string functionNodeName = functionNode->name();

                    if (functionNodeName == "function")
                    {
                        auto func = AugmentFunction();

                        const std::string& functionName = functionNode->first_attribute("name")->value();

                        if (functionName != augName)
                        {
                            func.value = G_->GetBlueprints()->GetAugmentValue(functionName);
                            bool preferHigher = true;

                            if (functionNode->first_attribute("value")) // Value of sub-augment
                            {
                                func.value = boost::lexical_cast<float>(functionNode->first_attribute("value")->value());
                            }
                            if (functionNode->first_attribute("preferHigher")) // Use higher or lower value for non-stackable augments?
                            {
                                func.preferHigher = EventsParser::ParseBoolean(functionNode->first_attribute("preferHigher")->value());
                            }
                            if (functionNode->first_attribute("useForReqs")) // Used for blue options?
                            {
                                func.useForReqs = EventsParser::ParseBoolean(functionNode->first_attribute("useForReqs")->value());
                            }
                            if (functionNode->first_attribute("warning")) // Display warning about which augments will have no effect with it?
                            {
                                func.warning = EventsParser::ParseBoolean(functionNode->first_attribute("warning")->value());
                            }
                            if (functionNode->first_attribute("sys")) // System must be installed, functional, and powered
                            {
                                func.sys = ShipSystem::NameToSystemId(functionNode->first_attribute("sys")->value());
                            }
                            if (functionNode->first_attribute("modifyChoiceTextScrap")) // For scrap recovery arm, modifies the scrap values in choice dialogs (does not modify scrap collected in score/stats)
                            {
                                func.modifyChoiceTextScrap = EventsParser::ParseBoolean(functionNode->first_attribute("modifyChoiceTextScrap")->value());
                            }

                            auto it = augDef->functions.emplace(functionName, func);
                            augDefsByFunction[functionName].emplace(augName, &(it->second));
                            if (func.useForReqs)
                            {
                                augDefsByReq[functionName].emplace(augName, &(it->second));
                            }
                        }
                    }
                    if (functionNodeName == "superShield")
                    {
                        augDef->superShield.present = true;
                        for (auto child = functionNode->first_node(); child; child = child->next_sibling())
                        {
                            if (strcmp(child->name(), "value") == 0)
                            {
                                augDef->superShield.value = boost::lexical_cast<int>(child->value());
                            }
                            if (strcmp(child->name(), "add") == 0)
                            {
                                augDef->superShield.add = boost::lexical_cast<int>(child->value());
                            }
                            if (strcmp(child->name(), "color") == 0)
                            {
                                augDef->superShield.customRender = true;
                                if (child->first_attribute("r"))
                                {
                                    augDef->superShield.shieldColor.r = boost::lexical_cast<float>(child->first_attribute("r")->value()) / 255.f;
                                }
                                if (child->first_attribute("g"))
                                {
                                    augDef->superShield.shieldColor.g = boost::lexical_cast<float>(child->first_attribute("g")->value()) / 255.f;
                                }
                                if (child->first_attribute("b"))
                                {
                                    augDef->superShield.shieldColor.b = boost::lexical_cast<float>(child->first_attribute("b")->value()) / 255.f;
                                }
                                if (child->first_attribute("a"))
                                {
                                    augDef->superShield.shieldColor.a = boost::lexical_cast<float>(child->first_attribute("a")->value());
                                }
                            }
                            if (strcmp(child->name(), "shieldImage") == 0)
                            {
                                augDef->superShield.customRender = true;
                                augDef->superShield.shieldTexture[0] = child->value();
                                augDef->superShield.shieldTexture[1] = child->value();
                            }
                            if (strcmp(child->name(), "playerImage") == 0)
                            {
                                augDef->superShield.customRender = true;
                                augDef->superShield.shieldTexture[0] = child->value();
                            }
                            if (strcmp(child->name(), "enemyImage") == 0)
                            {
                                augDef->superShield.customRender = true;
                                augDef->superShield.shieldTexture[1] = child->value();
                            }
                        }
                    }
                    if (functionNodeName == "crystalShard")
                    {
                        AugmentCrystalShard shard = AugmentCrystalShard();

                        if (functionNode->first_attribute("weapon"))
                        {
                            shard.weapon = functionNode->first_attribute("weapon")->value();
                        }
                        if (functionNode->first_attribute("value"))
                        {
                            shard.chance = boost::lexical_cast<float>(functionNode->first_attribute("value")->value());
                        }
                        if (functionNode->first_attribute("chance"))
                        {
                            shard.chance = boost::lexical_cast<float>(functionNode->first_attribute("chance")->value());
                        }
                        if (functionNode->first_attribute("stackable"))
                        {
                            std::string stackMode = functionNode->first_attribute("stackable")->value();
                            if (stackMode == "independent")
                            {
                                shard.stacking = 2;
                            }
                            else
                            {
                                shard.stacking = EventsParser::ParseBoolean(stackMode) ? 1 : 0;
                            }
                        }

                        augDef->crystalShard.push_back(shard);
                    }
                    if (functionNodeName == "locked")
                    {
                        augDef->locked = true;
                    }

                    if (functionNodeName == "statBoosts")
                    {
                        for (auto statBoostNode = functionNode->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
                        {
                            if (strcmp(statBoostNode->name(), "statBoost") == 0)
                            {
                                augDef->statBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, StatBoostDefinition::BoostSource::AUGMENT, false));
                            }
                        }
                    }

                    if (functionNodeName == "icon")
                    {
                        augDef->icon = functionNode->value();

                        if (functionNode->first_attribute("ship"))
                        {
                            std::string ship = functionNode->first_attribute("ship")->value();
                            if (ship == "player")
                            {
                                augDef->iconShipId = 0;
                            }
                            if (ship == "enemy")
                            {
                                augDef->iconShipId = 1;
                            }
                        }
                    }
                }

                augDefs[augName] = augDef;
            }
        }
    }
    catch (rapidxml::parse_error& e)
    {
        ErrorMessage(std::string("Error parsing <augments> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (std::exception &e)
    {
        ErrorMessage(std::string("Error parsing <augments> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (const char* e)
    {
        ErrorMessage(std::string("Error parsing <augments> in hyperspace.xml\n") + std::string(e));
    }
    catch (...)
    {
        ErrorMessage("Error parsing <augments> in hyperspace.xml\n");
    }
}

bool AugmentFunction::Functional(int iShipId)
{
    if (sys != -1)
    {
        ShipManager* shipManager = G_->GetShipManager(iShipId);
        if (shipManager != nullptr && shipManager->GetSystemRoom(sys) != -1)
        {
            ShipSystem* shipSystem = shipManager->GetSystem(sys);
            if (shipSystem != nullptr && shipSystem->iHackEffect < 2 && shipSystem->GetEffectivePower() > 0)
            {
                return true;
            }
        }
        return false;
    }
    return true;
}

std::unordered_multimap<std::string, AugmentFunction*>* CustomAugmentManager::GetPotentialAugments(const std::string& name, bool req)
{
    return req ? &augDefsByReq[name] : &augDefsByFunction[name];
}

std::unordered_map<std::string, int>* CustomAugmentManager::GetShipAugments(int iShipId)
{
    return &(augListWithHidden[iShipId]);
}

std::map<std::string, int> CustomAugmentManager::CheckHiddenAugments(const std::map<std::string, int>& augList)
{
    std::map<std::string, int> newList = std::map<std::string, int>();

    for (auto i : augList)
    {
        if (boost::algorithm::starts_with(i.first, "HIDDEN "))
        {
            newList[i.first.substr(7)] = i.second;
        }
        else
        {
            newList[i.first] = i.second;
        }
    }

    return newList;
}

std::vector<std::string> CustomAugmentManager::RemoveHiddenAugments(const std::vector<std::string>& augList)
{
    auto newList = std::vector<std::string>();

    for (auto i : augList)
    {
        if (!boost::algorithm::starts_with(i, "HIDDEN "))
        {
            newList.push_back(i);
        }
    }

    return newList;
}

void CustomAugmentManager::UpdateAugments(int iShipId)
{
    std::unordered_map<std::string, int>& hiddenList = augListWithHidden[iShipId];
    std::vector<std::string>& notHiddenList = augListNoHidden[iShipId];

    hiddenList.clear();
    notHiddenList.clear();

    for (auto i : G_->GetShipInfo(iShipId)->augList)
    {
        if (boost::algorithm::starts_with(i.first, "HIDDEN "))
        {
            hiddenList[i.first.substr(7)] += i.second;
        }
        else
        {
            hiddenList[i.first] += i.second;
            notHiddenList.push_back(i.first);
        }
    }

    std::vector<ShipIcon*>& iconList = augIconList[iShipId];
    for (auto i : iconList)
    {
        delete i;
    }
    iconList.clear();

    for (auto i : hiddenList)
    {
        if (i.second > 0)
        {
            if (IsAugment(i.first))
            {
                auto augDef = GetAugmentDefinition(i.first);
                if (!augDef->icon.empty() && (augDef->iconShipId == -1 || augDef->iconShipId == iShipId))
                {
                    auto iconDef = ShipIconManager::instance->GetShipIconDefinition(augDef->icon);
                    if (iconDef)
                    {
                        ShipIcon* icon = new ShipIcon();

                        icon->OnInit(iconDef->name, iconDef->tooltip, iconList.size());
                        iconList.push_back(icon);
                    }
                }
            }
        }
    }
}


//======================

HOOK_METHOD_PRIORITY(ShipObject, HasAugmentation, 2000, (const std::string& name) -> int)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipObject::HasAugmentation -> Begin (CustomAugments.cpp)\n")
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    std::unordered_map<std::string, int> *augList = customAug->GetShipAugments(iShipId);

    int augCount = 0;

    if (augList->count(name) > 0)
    {
        augCount = augList->at(name);
    }

    std::unordered_multimap<std::string, AugmentFunction*> *potentialAugs = customAug->GetPotentialAugments(name);



    for (auto const& x: *potentialAugs)
    {
        if (augList->count(x.first) && x.second->Functional(iShipId))
        {
            augCount += augList->at(x.first);
        }
    }

    // HAS_AUGMENTATION(ShipManager, name, augCount)
    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), G_->GetShipManager(this->iShipId), context->getLibScript()->types.pShipManager, 0);
    lua_pushstring(context->GetLua(), name.c_str());
    lua_pushinteger(context->GetLua(), augCount);
    context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::HAS_AUGMENTATION, 3, 1);
    if (lua_isinteger(context->GetLua(), -1)) augCount = lua_tointeger(context->GetLua(), -1);
    lua_pop(context->GetLua(), 3);

    return augCount;
}

int HasAugmentationById(const std::string& name, int iShipId)
{
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    std::unordered_map<std::string, int> *augList = customAug->GetShipAugments(iShipId);

    int augCount = 0;

    if (augList->count(name) > 0)
    {
        augCount = augList->at(name);
    }

    std::unordered_multimap<std::string, AugmentFunction*> *potentialAugs = customAug->GetPotentialAugments(name);



    for (auto const& x: *potentialAugs)
    {
        if (augList->count(x.first) && x.second->Functional(iShipId))
        {
            augCount += augList->at(x.first);
        }
    }

    // HAS_AUGMENTATION(ShipManager, name, augCount)
    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), G_->GetShipManager(iShipId), context->getLibScript()->types.pShipManager, 0);
    lua_pushstring(context->GetLua(), name.c_str());
    lua_pushinteger(context->GetLua(), augCount);
    context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::HAS_AUGMENTATION, 3, 1);
    if (lua_isinteger(context->GetLua(), -1)) augCount = lua_tointeger(context->GetLua(), -1);
    lua_pop(context->GetLua(), 3);

    return augCount;
}

bool useAugmentReq = false;

HOOK_METHOD(WorldManager, CreateChoiceBox, (LocationEvent *event) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateChoiceBox -> Begin (CustomAugments.cpp)\n")
    useAugmentReq = true;

    super(event);

    useAugmentReq = false;
}


// Replaced ShipObject::HasEquipment function for Hyperspace augments

HOOK_METHOD_PRIORITY(ShipObject, HasEquipment, 2000, (const std::string& name) -> int)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipObject::HasEquipment -> Begin (CustomAugments.cpp)\n")
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    auto ship = G_->GetShipManager(iShipId);
    int augCount = 0;

    // Count hidden augments

    std::map<std::string, int> *augList = &(G_->GetShipInfo(iShipId)->augList);
    std::string hidden_name = "HIDDEN " + name;

    if (augList->count(hidden_name) > 0)
    {
        augCount = augList->at(hidden_name);
    }

    // Count augment functions

    std::unordered_multimap<std::string, AugmentFunction*> *potentialAugs = customAug->GetPotentialAugments(name, useAugmentReq);
    std::unordered_map<std::string, int> *augListWithHidden = customAug->GetShipAugments(iShipId);

    for (auto const& x: *potentialAugs)
    {
        if (augListWithHidden->count(x.first) && x.second->Functional(iShipId))
        {
            augCount += augListWithHidden->at(x.first);
        }
    }

    // Count normal augments

    return augCount + super(name);
}



// Replaced ShipObject::GetAugmentationValue function for custom Hyperspace augments

HOOK_METHOD_PRIORITY(ShipObject, GetAugmentationValue, 1000, (const std::string& name) -> float)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipObject::GetAugmentationValue -> Begin (CustomAugments.cpp)\n")
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    AugmentBlueprint* augBlueprint = G_->GetBlueprints()->GetAugmentBlueprint(name);

    auto ship = G_->GetShipManager(iShipId);
    std::unordered_map<std::string, int> *augList = customAug->GetShipAugments(iShipId);
    int augCount = 0;

    if (augList->count(name) > 0)
    {
        augCount = augList->at(name);
    }


    float augValue = augBlueprint->value * augCount;

    std::unordered_multimap<std::string, AugmentFunction*> *potentialAugs = customAug->GetPotentialAugments(name);


    float highestValue = augValue;
    for (auto const& x: *potentialAugs)
    {
        if (augList->count(x.first) && x.second->Functional(iShipId))
        {
            augCount += augList->at(x.first);
            augValue += x.second->value * augList->at(x.first);

            if ((x.second->preferHigher && x.second->value > highestValue) || (!x.second->preferHigher && x.second->value < highestValue))
            {
                highestValue = x.second->value;
            }
        }
    }

    if (augCount <= 0)
    {
        return 0.f;
    }

    auto ret = augBlueprint->stacking ? augValue : highestValue;

    return ret;
}

HOOK_METHOD(ShipObject, GetAugmentationValue, (const std::string& name) -> float)
{
    LOG_HOOK("HOOK_METHOD -> ShipObject::GetAugmentationValue -> Begin (CustomAugments.cpp)\n")
    float ret = super(name);

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), G_->GetShipManager(this->iShipId), context->getLibScript()->types.pShipManager, 0);
    lua_pushstring(context->GetLua(), name.c_str());
    lua_pushnumber(context->GetLua(), ret);
    context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::GET_AUGMENTATION_VALUE, 3, 1); //Unsure what preempt would do here, if anything
    if (lua_isnumber(context->GetLua(), -1))
    {
        ret = lua_tonumber(context->GetLua(), -1);
    }
    lua_pop(context->GetLua(), 3);
    return ret;
}

// Locked augments

static GL_Texture* augLockTexture = nullptr;

HOOK_METHOD(Equipment, MouseClick, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Equipment::MouseClick -> Begin (CustomAugments.cpp)\n")
    super(mX, mY);
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    if (draggingEquipBox != -1)
    {
        auto box = vEquipmentBoxes[draggingEquipBox];
        if (box->CanHoldAugment() && box->slot != 4)
        {
            if (box->item.augment && customAug->IsAugment(box->item.augment->name))
            {
                if (customAug->GetAugmentDefinition(box->item.augment->name)->locked)
                {
                    draggingEquipBox = -1;
                    bDragging = false;
                }
            }
        }
    }
}

HOOK_METHOD(EquipmentBox, OnRender, (bool isEmpty) -> void)
{
    LOG_HOOK("HOOK_METHOD -> EquipmentBox::OnRender -> Begin (CustomAugments.cpp)\n")
    super(isEmpty);

    if (CanHoldAugment())
    {
        CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

        if (!augLockTexture)
        {
            augLockTexture = G_->GetResources()->GetImageId("upgradeUI/Equipment/aug_lock.png");
        }

        if (item.augment && customAug->IsAugment(item.augment->name) && customAug->GetAugmentDefinition(item.augment->name)->locked && augLockTexture)
        {
            float xPos = slot == 4 ? location.x - 36.f : location.x - 24.f;

            G_->GetResources()->RenderImage(augLockTexture, xPos, location.y + 7.f, 0.f, COLOR_WHITE, 1.f, false);
        }
    }
}

HOOK_METHOD(Equipment, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Equipment::OnLoop -> Begin (CustomAugments.cpp)\n")
    super();
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    EquipmentBox *firstSlot;
    EquipmentBox *fullSlot;
    bool swapSlots = false;

    for (auto i : vEquipmentBoxes)
    {
        if (i->CanHoldAugment())
        {
            if (i->item.augment && i->slot == 0)
            {
                firstSlot = i;
            }

            if (i->item.augment && customAug->IsAugment(i->item.augment->name) && customAug->GetAugmentDefinition(i->item.augment->name)->locked)
            {
                i->bBlocked = true;

                if (i->slot == 4)
                {
                    fullSlot = i;
                    swapSlots = true;
                }
            }
        }
    }

    if (swapSlots)
    {
        EquipmentBoxItem item1 = fullSlot->item;
        EquipmentBoxItem item2 = firstSlot->item;
        fullSlot->RemoveItem();
        firstSlot->RemoveItem();
        fullSlot->AddItem(item2);
        firstSlot->AddItem(item1);
    }
}



// Hidden augments

static bool exportingShip = false;

HOOK_METHOD_PRIORITY(ShipManager, ExportShip, 100, (int fileHelper) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::ExportShip -> Begin (CustomAugments.cpp)\n")
    super(fileHelper);

    std::vector<std::string> hiddenList = std::vector<std::string>();

    auto augList = G_->GetShipInfo(iShipId)->augList;

    for (auto i : augList)
    {
        if (boost::algorithm::starts_with(i.first, "HIDDEN "))
        {
            for (int j = 0; j < i.second; j++)
            {
                hiddenList.push_back(i.first);
            }
        }
    }

    FileHelper::writeInt(fileHelper, hiddenList.size());

    for (auto i : hiddenList)
    {
        FileHelper::writeString(fileHelper, i);
    }
}

HOOK_METHOD_PRIORITY(ShipManager, ImportShip, 100, (int fileHelper) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::ImportShip -> Begin (CustomAugments.cpp)\n")
    super(fileHelper);

    int hiddenCount = FileHelper::readInteger(fileHelper);
    auto augList = G_->GetShipInfo(iShipId)->augList;

    for (int i = 0; i < hiddenCount; i++)
    {
        auto aug = FileHelper::readString(fileHelper);

        if (augList.find(aug) != augList.end())
        {
            augList[aug]++;
        }
        else
        {
            augList[aug] = 1;
        }
    }

    G_->GetShipInfo(iShipId)->augList = augList;
    CustomAugmentManager::GetInstance()->UpdateAugments(iShipId);
}

HOOK_METHOD(ShipObject, GetAugmentationList, () -> std::vector<std::string>)
{
    LOG_HOOK("HOOK_METHOD -> ShipObject::GetAugmentationList -> Begin (CustomAugments.cpp)\n")
    std::vector<std::string> vec = super();

    vec = CustomAugmentManager::RemoveHiddenAugments(vec);

    return vec;
}

HOOK_METHOD(ShipObject, GetAugmentationCount, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipObject::GetAugmentationCount -> Begin (CustomAugments.cpp)\n")
    int count = 0;

    for (auto i : G_->GetShipInfo(iShipId)->augList)
    {
        if (!boost::algorithm::starts_with(i.first, "HIDDEN "))
        {
            count += i.second;
        }
    }

    return count;
}
HOOK_METHOD(ShipObject, AddAugmentation, (const std::string& name) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipObject::AddAugmentation -> Begin (CustomAugments.cpp)\n")
    if (boost::algorithm::starts_with(name, "HIDDEN ")){
        G_->GetShipInfo(iShipId)->augCount--;
    }
    auto ret = super(name);
    CustomAugmentManager::GetInstance()->UpdateAugments(iShipId);
    return ret;
}
HOOK_METHOD(ShipObject, RemoveAugmentation, (const std::string& name) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipObject::RemoveAugmentation -> Begin (CustomAugments.cpp)\n")
    super(name);

    int augCount = 0;

    for (auto i : G_->GetShipInfo(iShipId)->augList)
    {

        if (!boost::algorithm::starts_with(i.first, "HIDDEN "))
        {
            augCount += i.second;
        }
    }

    G_->GetShipInfo(iShipId)->augCount = augCount;

    CustomAugmentManager::GetInstance()->UpdateAugments(iShipId);

    /*
    ShipManager* ship = G_->GetShipManager(this);
    if (ship != nullptr)
    {
        auto sm = SM_EX(ship);
    }
    */
}
HOOK_METHOD(ShipObject, ClearShipInfo, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipObject::ClearShipInfo -> Begin (CustomAugments.cpp)\n")
    super();
    CustomAugmentManager::GetInstance()->UpdateAugments(iShipId);
}


HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnLoop -> Begin (CustomAugments.cpp)\n")
    super();

    // Dynamic defense scrambler
    if (current_target != nullptr)
    {
        bool has_defense = false;
        bool scrambled = false;
        for (auto drone : spaceDrones)
        {
            if (drone->type == 0)
            {
                if (!has_defense)
                {
                    has_defense = true;
                    scrambled = current_target->HasEquipment("DEFENSE_SCRAMBLER");
                }
                drone->bDisrupted = scrambled;
            }
        }
    }
}

HOOK_METHOD(WorldManager, CreateChoiceBox, (LocationEvent *event) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateChoiceBox -> Begin (CustomAugments.cpp)\n")
    super(event);

    // Modify choice text scrap

    float augValue = 0.f;

    if (CustomOptionsManager::GetInstance()->showScrapCollectorScrap.currentValue == false)
    {
        AugmentBlueprint* augBlueprint = G_->GetBlueprints()->GetAugmentBlueprint("SCRAP_COLLECTOR");
        CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

        std::unordered_map<std::string, int> *augList = customAug->GetShipAugments(0);
        std::unordered_multimap<std::string, AugmentFunction*> *potentialAugs = customAug->GetPotentialAugments("SCRAP_COLLECTOR");

        float highestValue = 0.f;
        for (auto const& x: *potentialAugs)
        {
            if (augList->count(x.first) && x.second->modifyChoiceTextScrap && x.second->Functional(0))
            {
                augValue += x.second->value * augList->at(x.first);

                if ((x.second->preferHigher && x.second->value > highestValue) || (!x.second->preferHigher && x.second->value < highestValue))
                {
                    highestValue = x.second->value;
                }
            }
        }

        if (!augBlueprint->stacking) augValue = highestValue;
    }
    else
    {
        augValue = G_->GetShipManager(0)->GetAugmentationValue("SCRAP_COLLECTOR");
    }

    if (augValue != 0.f)
    {
        if (commandGui->choiceBox.rewards.scrap > 0)
        {
            CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(event->eventName);
            if (!customEvent || !customEvent->disableScrapAugments)
            {
                commandGui->choiceBox.rewards.scrap = ((float)commandGui->choiceBox.rewards.scrap) + ((float)commandGui->choiceBox.rewards.scrap) * augValue;
            }
        }

        int numChoices = std::min(commandGui->choiceBox.choices.size(), event->choices.size());

        for (int i=0; i<numChoices; ++i)
        {
            ChoiceText &choiceText = commandGui->choiceBox.choices[i];

            if (choiceText.rewards.scrap > 0)
            {
                LocationEvent *choiceEvent = event->choices[i].event;

                if (choiceEvent)
                {
                    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(choiceEvent->eventName);
                    if (customEvent && customEvent->disableScrapAugments)
                    {
                        continue;
                    }
                }

                choiceText.rewards.scrap = choiceText.rewards.scrap + choiceText.rewards.scrap * augValue;
            }
        }
    }
}

HOOK_METHOD(WorldManager, CreateChoiceBox0, (LocationEvent *event) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateChoiceBox0 -> Begin (CustomAugments.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), event, context->getLibScript()->types.pLocationEvent, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::PRE_CREATE_CHOICEBOX, 1, 0);
    lua_pop(context->GetLua(), 1);

    super(event);

    SWIG_NewPointerObj(context->GetLua(), &commandGui->choiceBox, context->getLibScript()->types.pChoiceBox, 0);
    SWIG_NewPointerObj(context->GetLua(), event, context->getLibScript()->types.pLocationEvent, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::POST_CREATE_CHOICEBOX, 2, 0);
    lua_pop(context->GetLua(), 2);
}
