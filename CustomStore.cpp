#include "CustomStore.h"
#include "CustomEvents.h"
#include "CustomOptions.h"
#include "CustomShipSelect.h"
#include "CustomSystems.h"
#include "Store_Extend.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <array>

CustomStore* CustomStore::instance = new CustomStore();

// default property of the purchase limit number. these value should be overwritten by tag <purchaseLimitNumber> in hyperspace.xml
int PurchaseLimitIndicatorInfo::fontSize = 0;
int PurchaseLimitIndicatorInfo::x = -16;
int PurchaseLimitIndicatorInfo::y = 60;

static ItemPrice ParsePriceNode(rapidxml::xml_node<char>* node)
{
    ItemPrice def;

    for (auto cNode = node->first_node(); cNode; cNode = cNode->next_sibling())
    {
        std::string name = cNode->name();
        std::string val = cNode->value();

        if (name == "price")
        {
            if (cNode->first_attribute("min") && cNode->first_attribute("max"))
            {
                def.minMaxPrice.first = boost::lexical_cast<float>(cNode->first_attribute("min")->value());
                def.minMaxPrice.second = boost::lexical_cast<float>(cNode->first_attribute("max")->value());
                def.useMinMax = true;

                if (def.minMaxPrice.first > def.minMaxPrice.second)
                {
                    def.minMaxPrice.second = def.minMaxPrice.first;
                }
            }

            if (!val.empty())
            {
                def.price = boost::lexical_cast<int>(val);
            }
        }
        if (name == "sectorScaled")
        {
            def.sectorScaled = true;
        }
        if (name == "modifier")
        {
            if (cNode->first_attribute("min") && cNode->first_attribute("max"))
            {
                def.minMaxModifier.first = boost::lexical_cast<float>(cNode->first_attribute("min")->value());
                def.minMaxModifier.second = boost::lexical_cast<float>(cNode->first_attribute("max")->value());

                if (def.minMaxModifier.first > def.minMaxModifier.second)
                {
                    def.minMaxModifier.second = def.minMaxModifier.first;
                }
            }

            if (cNode->first_attribute("flat"))
            {
                def.flatModifier = EventsParser::ParseBoolean(cNode->first_attribute("flat")->value());
            }

            if (!val.empty())
            {
                def.minMaxModifier.first = boost::lexical_cast<float>(val);
                def.minMaxModifier.second = boost::lexical_cast<float>(val);
            }

            def.hasModifier = true;
        }
    }

    return def;
}

static HullRepair ParseHullRepairNode(rapidxml::xml_node<char>* node)
{
    HullRepair def;
    def.price = ParsePriceNode(node);

    for (auto cNode = node->first_node(); cNode; cNode = cNode->next_sibling())
    {
        std::string name = cNode->name();
        std::string val = cNode->value();
    }

    return def;
}

static ResourceItem ParseResourceNode(rapidxml::xml_node<char>* node)
{
    ResourceItem def;
    def.price = ParsePriceNode(node);

    for (auto cNode = node->first_node(); cNode; cNode = cNode->next_sibling())
    {
        std::string name = cNode->name();
        std::string val = cNode->value();

        if (name == "type")
        {
            def.type = val;
        }
        if (name == "count")
        {
            if (cNode->first_attribute("min") && cNode->first_attribute("max"))
            {
                def.minMaxCount.first = boost::lexical_cast<int>(cNode->first_attribute("min")->value());
                def.minMaxCount.second = boost::lexical_cast<int>(cNode->first_attribute("max")->value());
            }

            if (!val.empty())
            {
                def.minMaxCount.first = boost::lexical_cast<int>(val);
                def.minMaxCount.second = boost::lexical_cast<int>(val);
            }
        }
    }

    return def;
}

static StoreItem ParseStoreItemNode(rapidxml::xml_node<char>* node)
{
    StoreItem def;
    def.price = ParsePriceNode(node);

    for (auto cNode = node->first_node(); cNode; cNode = cNode->next_sibling())
    {
        std::string name = cNode->name();
        std::string val = cNode->value();

        if (name == "blueprint")
        {
            def.blueprint = val;
        }
        if (name == "mysteryItem")
        {
            def.mysteryItem = EventsParser::ParseBoolean(val);
        }
    }

    return def;
}

static StoreCategory ParseCategoryNode(rapidxml::xml_node<char>* node)
{
    StoreCategory def;

    if (node->first_attribute("type"))
    {
        std::array<std::string, 5> categories = {"WEAPONS", "DRONES", "AUGMENTS", "CREW", "SYSTEMS"};

        auto it = std::find(categories.begin(), categories.end(), node->first_attribute("type")->value());
        if (it != categories.end())
        {
            def.categoryType = static_cast<CategoryType>(it - categories.begin());
        }
    }

    for (auto cNode = node->first_node(); cNode; cNode = cNode->next_sibling())
    {
        std::string name = cNode->name();
        std::string val = cNode->value();


        if (name == "item")
        {
            auto item = ParseStoreItemNode(cNode);
            def.items.push_back(item);
        }
        if (name == "customTitle")
        {
            def.customTitle = val;
        }
        if (name == "chance")
        {
            def.chance = boost::lexical_cast<int>(val);
        }
        if (name == "groupChance")
        {
            def.groupChance = boost::lexical_cast<int>(val);
        }
        if (name == "allowDuplicates")
        {
            def.allowDuplicates = true;
        }
        if (name == "guaranteedSystems")
        {
            for (auto systemNode = cNode->first_node(); systemNode; systemNode = systemNode->next_sibling())
            {
                def.guaranteedSystems.push_back(systemNode->name());
            }
        }
    }

    return def;
}

void CustomStore::ParseStoreNode(rapidxml::xml_node<char>* node)
{
    for (auto storeNode = node->first_node(); storeNode; storeNode = storeNode->next_sibling())
    {
        std::string name = storeNode->name();
        std::string val = storeNode->value();
        if (name == "freeDrones")
        {
            for (auto droneNode = storeNode->first_node(); droneNode; droneNode = droneNode->next_sibling())
            {
                freeDrones.push_back(droneNode->name());
            }
        }
        if (name == "customStore")
        {
            std::string id = storeNode->first_attribute("id")->value();
            StoreDefinition def = StoreDefinition();

            for (auto cStoreNode = storeNode->first_node(); cStoreNode; cStoreNode = cStoreNode->next_sibling())
            {
                // do xml parsing for custom stores here
                std::string cStoreName = cStoreNode->name();

                if (cStoreName == "hullRepair")
                {
                    def.hullRepair = ParseHullRepairNode(cStoreNode);
                    def.hullRepair.visible = true;
                }

                if (cStoreName == "resource")
                {
                    def.resources.push_back(ParseResourceNode(cStoreNode));
                }

                if (cStoreName == "category")
                {
                    auto cat = ParseCategoryNode(cStoreNode);

                    int group = -1;

                    if (cStoreNode->first_attribute("group"))
                    {
                        group = boost::lexical_cast<int>(cStoreNode->first_attribute("group")->value());
                    }

                    def.categories[group].push_back(cat);
                }

                if (cStoreName == "itemPurchaseLimit")
                {
                    def.purchaseLimit = boost::lexical_cast<int>(cStoreNode->value());
                }
            }

            storeDefs[id] = def;
        }
    }
}

HOOK_METHOD(SystemStoreBox, constructor, (ShipManager *shopper, Equipment *equip, int sys) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemStoreBox::constructor -> Begin (CustomStore.cpp)\n")

    if (!(shopper->myBlueprint.systemInfo[sys].location.size() > 0))
    {
        sys = 1;
    }

    super(shopper, equip, sys);

    if (itemId != 4)
    {
        return;
    }

    if (CustomStore::instance->freeDrones.size() <= 0)
        return;

    auto bp = G_->GetBlueprints()->GetDroneBlueprint(freeBlueprint);

    int oldPrice = bp->desc.cost / 2;

    DroneBlueprint *newBlueprint = G_->GetBlueprints()->GetDroneBlueprint(CustomStore::instance->freeDrones[random32() % CustomStore::instance->freeDrones.size()]);
    freeBlueprint = newBlueprint->name;

    desc.cost -= oldPrice;
    desc.cost += newBlueprint->desc.cost / 2;
}

static int GetItemPricing(const ItemPrice& price, int defaultCost, int worldLevel, int freeBlueprintCost = 0)
{
    int finalPrice = price.price;

    if (finalPrice == -1)
    {
        finalPrice = defaultCost;
    }

    if (price.useMinMax)
    {
        if (price.sectorScaled)
        {
            finalPrice = std::floor((float)(price.minMaxPrice.second - price.minMaxPrice.first) * ((float)worldLevel / 7.f) + price.minMaxPrice.first);
        }
        else
        {
            finalPrice = random32() % ((int)price.minMaxPrice.second - (int)price.minMaxPrice.first + 1) + (int)price.minMaxPrice.first;
        }
    }

    finalPrice += freeBlueprintCost/2;

    if (price.hasModifier)
    {
        float modifier;

        if (price.minMaxModifier.first == price.minMaxModifier.second)
        {
            modifier = price.minMaxModifier.first;
        }
        else
        {
            int rng = random32() % RAND_MAX;

            float random = (float)rng / (float)RAND_MAX;
            float range = price.minMaxModifier.second - price.minMaxModifier.first;
            modifier = (random * range) + price.minMaxModifier.first;
        }

        if (price.flatModifier)
        {
            finalPrice += modifier;
        }
        else
        {
            finalPrice *= modifier;
        }
    }

    return finalPrice;
}

std::vector<StoreBox*> StoreComplete::CreateCustomStoreBoxes(const StoreCategory& category, ShipManager *ship, Equipment *equip)
{
    auto vec = std::vector<StoreBox*>();

    for (auto i : orig->vStoreBoxes)
    {
        delete i;
    }

    orig->vStoreBoxes.clear();

    auto usedBlueprints = std::vector<std::string>();

    if (category.categoryType == CategoryType::WEAPONS)
    {
        orig->CreateStoreBoxes(0, equip);

        for (auto i : category.items)
        {
            WeaponStoreBox* box = nullptr;

            if (i.blueprint.empty())
            {
                box = (WeaponStoreBox*)orig->vStoreBoxes.back();
                orig->vStoreBoxes.pop_back();

                box->desc.cost = GetItemPricing(i.price, box->blueprint->desc.cost, orig->worldLevel);

                vec.push_back(box);

                if (box->pBlueprint)
                {
                    usedBlueprints.push_back(box->pBlueprint->name);
                }
            }
            else
            {
                WeaponBlueprint* bp = nullptr;

                auto potentialList = G_->GetBlueprints()->GetBlueprintList(i.blueprint);

                if (potentialList.empty())
                {
                    bp = G_->GetBlueprints()->GetWeaponBlueprint(i.blueprint);
                }
                else
                {
                    if (!category.allowDuplicates)
                    {
                        potentialList.erase(std::remove_if(potentialList.begin(), potentialList.end(),
                                                           [&usedBlueprints](const std::string& o) { return std::find(usedBlueprints.begin(), usedBlueprints.end(), o) != usedBlueprints.end(); }),
                                                           potentialList.end());
                    }

                    if (!potentialList.empty())
                    {
                        bp = G_->GetBlueprints()->GetWeaponBlueprint(potentialList[random32() % potentialList.size()]);
                    }
                }

                if (bp)
                {
                    box = new WeaponStoreBox(ship, equip, bp);

                    box->desc.cost = GetItemPricing(i.price, bp->desc.cost, orig->worldLevel);

                    vec.push_back(box);

                    if (box->pBlueprint)
                    {
                        usedBlueprints.push_back(box->pBlueprint->name);
                    }
                }
            }
        }
    }
    else if (category.categoryType == CategoryType::DRONES)
    {
        orig->CreateStoreBoxes(1, equip);

        for (auto i : category.items)
        {
            DroneStoreBox* box = nullptr;

            if (i.blueprint.empty())
            {
                box = (DroneStoreBox*)orig->vStoreBoxes.back();
                orig->vStoreBoxes.pop_back();

                box->desc.cost = GetItemPricing(i.price, box->blueprint->desc.cost, orig->worldLevel);

                vec.push_back(box);

                if (box->pBlueprint)
                {
                    usedBlueprints.push_back(box->pBlueprint->name);
                }
            }
            else
            {
                DroneBlueprint* bp = nullptr;

                auto potentialList = G_->GetBlueprints()->GetBlueprintList(i.blueprint);

                if (potentialList.empty())
                {
                    bp = G_->GetBlueprints()->GetDroneBlueprint(i.blueprint);
                }
                else
                {
                    if (!category.allowDuplicates)
                    {
                        potentialList.erase(std::remove_if(potentialList.begin(), potentialList.end(),
                                                           [&usedBlueprints](const std::string& o) { return std::find(usedBlueprints.begin(), usedBlueprints.end(), o) != usedBlueprints.end(); }),
                                                           potentialList.end());
                    }

                    if (!potentialList.empty())
                    {
                        bp = G_->GetBlueprints()->GetDroneBlueprint(potentialList[random32() % potentialList.size()]);
                    }
                }

                if (bp)
                {
                    box = new DroneStoreBox(ship, equip, bp);

                    box->desc.cost = GetItemPricing(i.price, bp->desc.cost, orig->worldLevel);

                    vec.push_back(box);

                    if (box->pBlueprint)
                    {
                        usedBlueprints.push_back(box->pBlueprint->name);
                    }
                }
            }
        }
    }
    else if (category.categoryType == CategoryType::AUGMENTS)
    {
        orig->CreateStoreBoxes(2, equip);

        for (auto i : category.items)
        {
            AugmentStoreBox* box = nullptr;

            if (i.blueprint.empty())
            {
                box = (AugmentStoreBox*)orig->vStoreBoxes.back();
                orig->vStoreBoxes.pop_back();

                box->desc.cost = GetItemPricing(i.price, box->blueprint->desc.cost, orig->worldLevel);

                vec.push_back(box);

                if (box->pBlueprint)
                {
                    usedBlueprints.push_back(box->pBlueprint->name);
                }
            }
            else
            {
                AugmentBlueprint* bp = nullptr;

                auto potentialList = G_->GetBlueprints()->GetBlueprintList(i.blueprint);

                if (potentialList.empty())
                {
                    bp = G_->GetBlueprints()->GetAugmentBlueprint(i.blueprint);
                }
                else
                {
                    if (!category.allowDuplicates)
                    {
                        potentialList.erase(std::remove_if(potentialList.begin(), potentialList.end(),
                                                           [&usedBlueprints](const std::string& o) { return std::find(usedBlueprints.begin(), usedBlueprints.end(), o) != usedBlueprints.end(); }),
                                                           potentialList.end());
                    }

                    if (!potentialList.empty())
                    {
                        bp = G_->GetBlueprints()->GetAugmentBlueprint(potentialList[random32() % potentialList.size()]);
                    }
                }

                if (bp)
                {
                    box = new AugmentStoreBox(ship, bp);

                    box->desc.cost = GetItemPricing(i.price, box->blueprint->desc.cost, orig->worldLevel);

                    vec.push_back(box);

                    if (box->pBlueprint)
                    {
                        usedBlueprints.push_back(box->pBlueprint->name);
                    }
                }
            }
        }
    }
    else if (category.categoryType == CategoryType::CREW)
    {
        orig->CreateStoreBoxes(3, equip);

        for (auto i : category.items)
        {
            CrewStoreBox* box = nullptr;

            if (i.blueprint.empty())
            {
                box = (CrewStoreBox*)orig->vStoreBoxes.back();
                orig->vStoreBoxes.pop_back();

                box->desc.cost = GetItemPricing(i.price, box->blueprint.desc.cost, orig->worldLevel);

                vec.push_back(box);
            }
            else
            {
                std::string species = i.blueprint;

                auto potentialList = G_->GetBlueprints()->GetBlueprintList(i.blueprint);

                if (!potentialList.empty())
                {
                    species = potentialList[random32() % potentialList.size()];
                }

                CrewBlueprint bp = G_->GetBlueprints()->GetCrewBlueprint(species);

                box = new CrewStoreBox(ship, orig->worldLevel, species);

                box->desc.cost = GetItemPricing(i.price, bp.desc.cost, orig->worldLevel);

                vec.push_back(box);
            }
        }
    }
    else if (category.categoryType == CategoryType::SYSTEMS)
    {
        orig->CreateStoreBoxes(4, equip);

        for (auto i : category.items)
        {
            SystemStoreBox* box = nullptr;

            if (i.blueprint.empty())
            {
                if (!orig->vStoreBoxes.empty())
                {
                    box = (SystemStoreBox*)orig->vStoreBoxes.front();
                    orig->vStoreBoxes.erase(orig->vStoreBoxes.begin());

                    if (box->pBlueprint)
                    {
                        Blueprint* freeBlueprint = G_->GetBlueprints()->GetDroneBlueprint(box->freeBlueprint);

                        box->desc.cost = GetItemPricing(i.price, box->blueprint->desc.cost, orig->worldLevel, freeBlueprint ? freeBlueprint->desc.cost : 0);

                        vec.push_back(box);

                        usedBlueprints.push_back(box->pBlueprint->name);
                    }
                }
            }
            else
            {
                SystemBlueprint* bp = nullptr;

                auto potentialList = G_->GetBlueprints()->GetBlueprintList(i.blueprint);

                if (potentialList.empty())
                {
                    // add bp only if the ship can have this system
                    int sysId = ShipSystem::NameToSystemId(i.blueprint);
                    if (ship->myBlueprint.systemInfo.find(sysId) != ship->myBlueprint.systemInfo.end())
                    {
                        bp = G_->GetBlueprints()->GetSystemBlueprint(i.blueprint);
                    }
                }
                else
                {

                    potentialList.erase(std::remove_if(potentialList.begin(), potentialList.end(),
                                   [&ship](const std::string& o) { int sysId = ShipSystem::NameToSystemId(o);
                                                                             return ship->HasSystem(sysId) ||  // Remove if the ship has the system
                                                                             ship->myBlueprint.systemInfo.find(sysId) == ship->myBlueprint.systemInfo.end(); // Remove if the ship can't fit the system
                                                                             }),
                                   potentialList.end());

                    if (!category.allowDuplicates)
                    {
                        potentialList.erase(std::remove_if(potentialList.begin(), potentialList.end(),
                                                           [&usedBlueprints](const std::string& o) { return std::find(usedBlueprints.begin(), usedBlueprints.end(), o) != usedBlueprints.end(); }),
                                                           potentialList.end());
                    }

                    if (!potentialList.empty())
                    {
                        std::string pickedBlueprint = potentialList[random32() % potentialList.size()];

                        for (auto i : category.guaranteedSystems)
                        {
                            if (std::find(potentialList.begin(), potentialList.end(), i) != potentialList.end())
                            {
                                pickedBlueprint = i;
                            }
                        }

                        bp = G_->GetBlueprints()->GetSystemBlueprint(pickedBlueprint);
                    }
                }

                if (bp)
                {
                    box = new SystemStoreBox(ship, equip, ShipSystem::NameToSystemId(bp->name));

                    Blueprint* freeBlueprint = nullptr;
                    if (!box->freeBlueprint.empty()) freeBlueprint = G_->GetBlueprints()->GetDroneBlueprint(box->freeBlueprint);

                    box->desc.cost = GetItemPricing(i.price, box->blueprint->desc.cost, orig->worldLevel, freeBlueprint ? freeBlueprint->desc.cost : 0);

                    vec.push_back(box);

                    if (box->pBlueprint)
                    {
                        usedBlueprints.push_back(box->pBlueprint->name);
                    }
                }
            }
        }
    }

    orig->vStoreBoxes.clear();


    return vec;

}

void StoreComplete::OnInit(const StoreDefinition& def, ShipManager *ship, Equipment *equip, int level)
{
    //delete orig->box;

    orig->box = G_->GetResources()->GetImageId("storeUI/store_buy_main_custom.png");

    orig->worldLevel = level;
    orig->shopper = ship;

    for (auto i : def.resources)
    {
        ItemStoreBox* box = new ItemStoreBox(ship, i.type);

        box->count = i.minMaxCount.first + (random32() % (i.minMaxCount.second - i.minMaxCount.first + 1));

        box->desc.cost = GetItemPricing(i.price, box->blueprint->desc.cost, level);

        resourceBoxes.push_back(box);
    }

    if (def.hullRepair.visible)
    {
        int price = 2;
        if (level > 5)
        {
            price = 4;
        }
        else if (level > 2)
        {
            price = 3;
        }

        price = GetItemPricing(def.hullRepair.price, price, level);

        RepairStoreBox* repairOne = new RepairStoreBox(ship, false, price);
        RepairStoreBox* repairAll = new RepairStoreBox(ship, true, price);

        repairBoxes.push_back(repairOne);
        repairBoxes.push_back(repairAll);
    }

    auto chosenCategories = std::vector<StoreCategory>();

    if (def.categories.find(-1) != def.categories.end())
    {
        auto catList = def.categories.at(-1);
        for (auto cat : catList)
        {
            if (random32() % 100 < cat.chance)
            {
                chosenCategories.push_back(cat);
            }
        }
    }

    for (auto secPair : def.categories)
    {
        if (secPair.first == -1) continue;
        int rng = random32() % 100;

        auto chancedVec = std::vector<StoreCategory>();
        auto unchancedVec = std::vector<StoreCategory>();

        for (auto cat : secPair.second)
        {
            if (cat.groupChance > 0)
            {
                chancedVec.push_back(cat);
            }
            else
            {
                unchancedVec.push_back(cat);
            }
        }


        int totalChance = 0;
        for (auto cat : chancedVec)
        {
            totalChance += cat.groupChance;
        }

        StoreCategory* selectedCat = nullptr;

        if (rng < totalChance)
        {
            int cumChance = 0;
            for (auto& cat : chancedVec)
            {
                if (rng > cumChance && rng < cumChance + cat.groupChance)
                {
                    selectedCat = &cat;
                    break;
                }

                cumChance += cat.groupChance;
            }
        }
        else if (unchancedVec.size() > 0)
        {
            int secChanceSize = (100 - totalChance) / unchancedVec.size();

            if (secChanceSize <= 0) secChanceSize = 1;

            int idx = rng / secChanceSize;

            if (idx < unchancedVec.size())
            {
                selectedCat = &unchancedVec[idx];
            }
        }

        if (selectedCat != nullptr)
        {
            if (random32() % 100 < selectedCat->chance)
            {
                chosenCategories.push_back(*selectedCat);
            }
        }
    }


    StorePage currPage = StorePage();

    for (int i = 0; i < chosenCategories.size(); i++)
    {
        auto cat = chosenCategories[i];
        StoreSection sec = StoreSection();
        sec.category = cat.categoryType;

        sec.customTitle = cat.customTitle;

        auto newBoxes = CreateCustomStoreBoxes(cat, ship, equip);

        if (newBoxes.size() == 0)
        {
            continue;
        }

        int currentSec = -1;
        for (int boxIdx = 0; boxIdx < newBoxes.size(); boxIdx++)
        {
            if (boxIdx % 3 == 0)
            {
                currentSec++;

                sec.storeBoxes.push_back(std::vector<CustomStoreBox*>());
            }

            auto customBox = new CustomStoreBox();
            customBox->orig = newBoxes[boxIdx];
            auto boxDef = cat.items[boxIdx];
            if (customBox->orig->pBlueprint)
            {
                customBox->originalPrice = customBox->orig->pBlueprint->desc.cost;
                customBox->showSale = true;
                customBox->mysteryItem = boxDef.mysteryItem;
            }
            //customBox->orig->button.SetImageBase(customBox->orig->buttonImage + "_custom");

            sec.storeBoxes[currentSec].push_back(customBox);
        }

        currPage.sections.push_back(sec);

        if ((currPage.sections.size() % 2 == 0 && currPage.sections.size() != 1) || i == chosenCategories.size() - 1)
        {
            pages.push_back(currPage);
            currPage = StorePage();
        }
    }

    std::string buttonImg("storeUI/button_store_arrow");
    leftButton = new Button();
    leftButton->OnInit(buttonImg, Point(orig->position.x + 451, orig->position.y + 12));

    rightButton = new Button();
    rightButton->OnInit(buttonImg, Point(orig->position.x + 547, orig->position.y + 12));

    rightButton->bMirror = true;

    leftButton->bActive = pages.size() > 1;
    rightButton->bActive = pages.size() > 1;

    itemPurchaseLimit = def.purchaseLimit;

    SetPositions();
}

std::string StoreComplete::GetHeadingText(CategoryType type)
{
    std::string base = "store_title_";

    switch (type)
    {
    case CategoryType::WEAPONS:
        return base + "weapons";
    case CategoryType::DRONES:
        return base + "drones";
    case CategoryType::AUGMENTS:
        return base + "augments";
    case CategoryType::CREW:
        return base + "crew";
    case CategoryType::SYSTEMS:
        return base + "systems";
    }
}

void StoreComplete::InitHeadings()
{
    for (auto& page : pages)
    {
        for (auto& sec : page.sections)
        {
            sec.headingTitle = GetHeadingText(sec.category);
        }
    }
}

void StoreComplete::SetPositions()
{
    if (!leftButton)
    {
        std::string buttonImg("storeUI/button_store_arrow");
        leftButton = new Button();
        leftButton->OnInit(buttonImg, Point(orig->position.x + 451, orig->position.y + 12));
    }
    if (!rightButton)
    {
        std::string buttonImg("storeUI/button_store_arrow");
        rightButton = new Button();
        rightButton->OnInit(buttonImg, Point(orig->position.x + 547, orig->position.y + 12));
        rightButton->bMirror = true;
    }

    if (!limitIndicator)
    {
        limitIndicator = G_->GetResources()->GetImageId("storeUI/store_limit_indicator.png");
    }

    leftButton->bActive = pages.size() > 1;
    rightButton->bActive = pages.size() > 1;

    orig->box = G_->GetResources()->GetImageId("storeUI/store_buy_main_custom.png");

    orig->infoBoxLoc.x = orig->position.x + 600;
    orig->infoBoxLoc.y = orig->position.y;
    orig->infoBox.location = orig->infoBoxLoc;

    leftButton->SetLocation(Point(orig->position.x + 451, orig->position.y + 12));
    rightButton->SetLocation(Point(orig->position.x + 547, orig->position.y + 12));

    int resourceBoxOffsets[3] = {0, 50, 99};

    for (int i = 0; i < resourceBoxes.size(); i++)
    {
        auto box = resourceBoxes[i];

        box->SetPosition(orig->position.x + 18, orig->position.y + 83 + resourceBoxOffsets[i]);
    }

    int repairBoxOffsets[3] = {291, 346};

    for (int i = 0; i < repairBoxes.size(); i++)
    {
        auto box = repairBoxes[i];
        box->SetPosition(orig->position.x + 18, orig->position.y + repairBoxOffsets[i]);
    }

    InitHeadings();

    for (auto page : pages)
    {
        for (int secIndex = 0; secIndex < page.sections.size(); secIndex++)
        {
            auto section = page.sections[secIndex];

            Point boxPos(208, 103 + secIndex * 209);
            Point altBoxPos(203, 83 + secIndex * 209);

            for (auto boxList : section.storeBoxes)
            {
                for (int boxIndex = 0; boxIndex < boxList.size(); boxIndex++)
                {
                    auto box = boxList[boxIndex];

                    if (section.category != CategoryType::AUGMENTS && section.category != CategoryType::SYSTEMS)
                    {
                        box->orig->SetPosition(boxPos.x + orig->position.x, boxPos.y + orig->position.y);

                        boxPos.x += 125;
                    }
                    else
                    {
                        box->orig->SetPosition(altBoxPos.x + orig->position.x, altBoxPos.y + orig->position.y);

                        altBoxPos.y += 53;
                    }
                }
            }
        }
    }
}

void StoreComplete::OnRender()
{
    CSurface::GL_PushMatrix();
    if (orig->confirmBuy)
    {
        CSurface::GL_SetColorTint(COLOR_TINT);
    }

    CSurface::GL_Translate(orig->position.x, orig->position.y);

    if (orig->box)
    {
        CSurface::GL_BlitPixelImage(orig->box, 0, 0, orig->box->width_, orig->box->height_, 0, COLOR_WHITE, false);
    }

    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

    orig->DrawBuySellTabText();
    freetype::easy_print(62, 18.f, 45.f, G_->GetTextLibrary()->GetText("store_title_items"));
    freetype::easy_print(62, 18.f, 254.f, G_->GetTextLibrary()->GetText("store_title_repair"));

    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    std::string currentHullText = G_->GetTextLibrary()->GetText("store_current_hull");

    float currentHullY = 419.f;

    if (currentHullText.find('\n') == std::string::npos)
    {
        currentHullY = 427.f;
    }

    freetype::easy_printCenter(59, 73.f, currentHullY, currentHullText);

    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

    if (pages.size() > 9)
    {
        freetype::easy_printCenter(63, 515, 11, std::to_string(currentPage + 1));
    }
    else
    {
        std::string pageStr = std::to_string(currentPage + 1);
        std::string maxPageStr = std::to_string(pages.size());

        if (pages.size() == 0)
        {
            pageStr = "1";
            maxPageStr = "1";
        }

        freetype::easy_printCenter(63, 515, 11, pageStr + "/" + maxPageStr);
    }

    CSurface::GL_PopMatrix();

    leftButton->OnRender();
    rightButton->OnRender();

    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    std::string unavailableText = G_->GetTextLibrary()->GetText("store_unavailable");

    if (pages.size() > 0)
    {
        Point headingPos = Point(206, 45);
        for (auto section : pages[currentPage].sections)
        {
            CSurface::GL_SetColor(COLOR_BUTTON_TEXT);
            if (section.customTitle.empty())
            {
                freetype::easy_print(62, orig->position.x + headingPos.x, orig->position.y + headingPos.y, G_->GetTextLibrary()->GetText(section.headingTitle));
            }
            else
            {
                freetype::easy_print(62, orig->position.x + headingPos.x, orig->position.y + headingPos.y, section.customTitle);
            }

            for (auto box : section.storeBoxes[section.currentSection])
            {
                box->OnRender();
            }

            headingPos.y += 209;
        }

        if (pages[currentPage].sections.size() == 1)
        {
            CSurface::GL_SetColor(COLOR_BUTTON_ON);

            freetype::easy_printCenter(52, orig->position.x + 394, orig->position.y + 358, unavailableText);
        }
    }
    else
    {
        CSurface::GL_SetColor(COLOR_BUTTON_ON);

        freetype::easy_printCenter(52, orig->position.x + 394, orig->position.y + 148, unavailableText);
        freetype::easy_printCenter(52, orig->position.x + 394, orig->position.y + 358, unavailableText);
    }

    for (auto i : resourceBoxes)
    {
        i->OnRender();
    }

    if (resourceBoxes.empty())
    {
        CSurface::GL_SetColor(COLOR_BUTTON_ON);

        freetype::easy_printCenter(52, orig->position.x + 102, orig->position.y + 148, unavailableText);
    }

    for (auto i : repairBoxes)
    {
        i->OnRender();
    }

    if (repairBoxes.empty())
    {
        CSurface::GL_SetColor(COLOR_BUTTON_ON);

        freetype::easy_printCenter(52, orig->position.x + 102, orig->position.y + 332, unavailableText);
    }

    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    char buffer[64];
    sprintf(buffer, "%d", orig->shopper->ship.hullIntegrity.first);
    freetype::easy_print(0, orig->position.x + 143, orig->position.y + 432, buffer);
    orig->infoBox.OnRender();

    if (itemPurchaseLimit != -1)
    {
        G_->GetResources()->RenderImage(limitIndicator, orig->position.x + 7 - limitIndicator->width_, orig->position.y + 26, 0.f, COLOR_WHITE, 1.f, false);

        CSurface::GL_SetColor(COLOR_BUTTON_ON);

        std::string txt = std::to_string(itemPurchaseLimit - itemsPurchased);

        freetype::easy_printCenter(PurchaseLimitIndicatorInfo::fontSize, orig->position.x + PurchaseLimitIndicatorInfo::x, orig->position.y + PurchaseLimitIndicatorInfo::y, txt);
    }

    if (orig->confirmBuy)
    {
        CSurface::GL_RemoveColorTint();
        orig->confirmDialog.OnRender();
    }
}

void StoreComplete::NextPage()
{
    currentPage++;

    if (currentPage >= pages.size())
    {
        currentPage = 0;
    }
}

void StoreComplete::PreviousPage()
{
    currentPage--;
    if (currentPage < 0)
    {
        currentPage = pages.size() - 1;
    }
}

void StoreComplete::KeyDown(SDLKey key)
{
    if (key == SDLKey::SDLK_RIGHT)
    {
        NextPage();
    }
    if (key == SDLKey::SDLK_LEFT)
    {
        PreviousPage();
    }
}

void StoreComplete::OnLoop()
{
    for (auto i : resourceBoxes)
    {
        i->OnLoop();
    }

    for (auto i : repairBoxes)
    {
        i->OnLoop();
    }

    if (pages.size() > 0)
    {
        for (auto sec : pages[currentPage].sections)
        {
            if (sec.storeBoxes.size() > 0)
            {
                for (auto i : sec.storeBoxes[sec.currentSection])
                {
                    i->orig->OnLoop();

                    if (itemPurchaseLimit != -1 && itemsPurchased >= itemPurchaseLimit)
                    {
                        i->orig->button.SetActive(false);
                    }
                }
            }
        }
    }

    leftButton->OnLoop();
    rightButton->OnLoop();
}

static StoreBox* g_purchasedStoreItem = nullptr;

HOOK_METHOD(StoreBox, Purchase, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StoreBox::Purchase -> Begin (CustomStore.cpp)\n")
    if (pBlueprint && pBlueprint->GetType() != 5)
    {
        g_purchasedStoreItem = this;
    }

    super();
}

void StoreComplete::MouseClick(int x, int y)
{
    g_purchasedStoreItem = nullptr;

    if (orig->confirmBuy)
    {
        orig->confirmDialog.MouseClick(x, y);

        if (orig->confirmDialog.noButton.bActive && orig->confirmDialog.noButton.bHover) // Not sure why I need this, but it doesn't close on no otherwise
        {
            orig->confirmDialog.result = false;
            CSurface::GL_DestroyPrimitive(orig->confirmDialog.window);
            orig->confirmDialog.window = nullptr;
            orig->confirmDialog.bOpen = false;
        }

        if (!orig->confirmDialog.bOpen)
        {
            orig->confirmBuy->Confirm(orig->confirmDialog.result);
            orig->confirmBuy = nullptr;
        }
    }
    else
    {
        for (auto i : resourceBoxes)
        {
            i->MouseClick(x, y);
        }

        for (auto i : repairBoxes)
        {
            i->MouseClick(x, y);
        }

        if (pages.size() > 0)
        {
            for (auto sec : pages[currentPage].sections)
            {
                if (sec.storeBoxes.size() > 0)
                {
                    for (auto i : sec.storeBoxes[sec.currentSection])
                    {
                        i->orig->MouseClick(x, y);


                        if (i->orig->RequiresConfirm())
                        {
                            orig->confirmBuy = i->orig;

                            TextString yes;
                            yes.data = "confirm_yes";
                            yes.isLiteral = false;
                            TextString no;
                            no.data = "confirm_no";
                            no.isLiteral = false;

                            orig->confirmDialog.SetText(i->orig->GetConfirmText(), 300, true, yes, no);
                            orig->confirmDialog.Open();
                        }
                    }
                }
            }
        }

        if (leftButton->bActive && leftButton->bHover)
        {
            PreviousPage();
        }
        if (rightButton->bActive && rightButton->bHover)
        {
            NextPage();
        }

        if (g_purchasedStoreItem)
        {
            itemsPurchased++;
        }
    }
}

void StoreComplete::MouseMove(int x, int y)
{
    orig->FocusWindow::MouseMove(x, y);

    if (orig->confirmBuy)
    {
        orig->confirmDialog.MouseMove(x, y);
        return;
    }

    orig->infoBox.Clear();

    // show tooltip when the mouse is hovering the purchase limit indicator
    if (itemPurchaseLimit != -1 &&
        orig->position.x + 10 - limitIndicator->width_ < x && x < orig->position.x + 7 &&
        orig->position.y + 38 < y && y <  orig->position.y + 12 + limitIndicator->height_)
    {
        std::string tooltip = G_->GetTextLibrary()->GetText("tooltip_purchase_limit");
        if (tooltip.find("Could not find:") == std::string::npos)
        {
            G_->GetMouseControl()->SetTooltip(tooltip);
            G_->GetMouseControl()->InstantTooltip();
        }
    }

    for (auto i : resourceBoxes)
    {
        i->MouseMove(x, y);

        if ((i->button.bHover || i->button.bSelected) && i->count > 0)
        {
            i->SetInfoBox(orig->infoBox, 347);
        }
    }

    for (auto i : repairBoxes)
    {
        i->MouseMove(x, y);
    }

    if (pages.size() > 0)
    {
        for (auto sec : pages[currentPage].sections)
        {
            if (sec.storeBoxes.size() > 0)
            {
                for (auto i : sec.storeBoxes[sec.currentSection])
                {
                    i->orig->MouseMove(x, y);

                    if ((i->orig->button.bHover || i->orig->button.bSelected) && i->orig->count > 0 && !i->mysteryItem)
                    {
                        i->orig->SetInfoBox(orig->infoBox, 347);
                    }
                }
            }
        }
    }

    leftButton->MouseMove(x, y, false);
    rightButton->MouseMove(x, y, false);
}

HOOK_METHOD(Store, KeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Store::KeyDown -> Begin (CustomStore.cpp)\n")
    if (STORE_EX(this)->isCustomStore)
    {
        STORE_EX(this)->customStore->KeyDown(key);
        return;
    }

    return super(key);
}

HOOK_METHOD(Store, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Store::OnRender -> Begin (CustomStore.cpp)\n")
    if (STORE_EX(this)->isCustomStore)
    {
        STORE_EX(this)->customStore->OnRender();
        return;
    }

    return super();

    // Unused rewritten code - could have some use in the future
    CSurface::GL_PushMatrix();
    if (confirmBuy)
    {
        CSurface::GL_SetColorTint(COLOR_TINT);
    }

    CSurface::GL_Translate(position.x, position.y);


    CSurface::GL_BlitPixelImage(box, 0, 0, box->width_, box->height_, 0, COLOR_WHITE, false);
    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

    DrawBuySellTabText();
    freetype::easy_print(62, 18.f, 45.f, G_->GetTextLibrary()->GetText("store_title_items"));
    freetype::easy_print(62, 18.f, 254.f, G_->GetTextLibrary()->GetText("store_title_repair"));

    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    std::string currentHullText = G_->GetTextLibrary()->GetText("store_current_hull");

    float currentHullY = 419.f;

    if (currentHullText.find('\n') == std::string::npos)
    {
        currentHullY = 427.f;
    }

    freetype::easy_printCenter(59, 73.f, currentHullY, currentHullText);

    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

    int headingIndex = bShowPage2 ? 2 : 0;

    Point pos1 = Point(198, 42);
    freetype::easy_print(62, pos1.x + 7, pos1.y + 3, headingTitle[headingIndex].GetText());

    int heading2Index = bShowPage2 ? 3 : 1;

    Point pos2 = Point(198, 251);
    freetype::easy_print(62, pos2.x + 7, pos2.y + 3, headingTitle[heading2Index].GetText());

    CSurface::GL_PopMatrix();

    if (sectionCount > 2)
    {
        Pointf pos3 = Pointf(currentButton->position.x, currentButton->position.y + 7);

        currentButton->OnRender();
        CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

        freetype::easy_printCenter(62, pos3.x + 65, pos3.y, G_->GetTextLibrary()->GetText("store_tab_page1"));
        freetype::easy_printCenter(62, pos3.x + 171, pos3.y, G_->GetTextLibrary()->GetText("store_tab_page2"));
    }

    if (bShowPage2)
    {
        for (int i = 6; i < sectionCount * 3; i++)
        {
            vStoreBoxes[i]->OnRender();
        }
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            vStoreBoxes[i]->OnRender();
        }
    }

    // appears to be for items/repair, but it's weird??
    if (3 * sectionCount + 5 > 3 * sectionCount)
    {
        for (int i = 3 * sectionCount; i < 3 * sectionCount + 5; i++)
        {
            vStoreBoxes[i]->OnRender();
        }
    }

    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    char buffer[64];
    sprintf(buffer, "%d", shopper->ship.hullIntegrity.first);
    freetype::easy_print(0, position.x + 143, position.y + 432, buffer);
    infoBox.OnRender();
    if (confirmBuy)
    {
        CSurface::GL_RemoveColorTint();
        confirmDialog.OnRender();
    }
}

void StoreComplete::SaveStore(int file)
{
    FileHelper::writeInt(file, pages.size());
    for (auto page : pages)
    {
        FileHelper::writeInt(file, page.sections.size());
        for (auto sec : page.sections)
        {
            FileHelper::writeInt(file, static_cast<int>(sec.category));
            FileHelper::writeString(file, sec.customTitle);
            FileHelper::writeInt(file, sec.storeBoxes.size());

            for (auto boxSec : sec.storeBoxes)
            {
                FileHelper::writeInt(file, boxSec.size());

                for (auto storeBox : boxSec)
                {
                    if (storeBox->orig->pBlueprint)
                    {
                        FileHelper::writeInt(file, storeBox->orig->count);
                        FileHelper::writeString(file, storeBox->orig->pBlueprint->name);
                        FileHelper::writeInt(file, storeBox->orig->GetExtraData());
                        FileHelper::writeInt(file, storeBox->orig->desc.cost);

                        FileHelper::writeInt(file, storeBox->showSale);
                        FileHelper::writeInt(file, storeBox->originalPrice);
                        FileHelper::writeInt(file, storeBox->mysteryItem);
                    }
                    else
                    {
                        FileHelper::writeInt(file, -1);
                    }
                }
            }
        }
    }

    FileHelper::writeInt(file, resourceBoxes.size());
    for (auto storeBox : resourceBoxes)
    {
        FileHelper::writeInt(file, storeBox->itemId);
        FileHelper::writeInt(file, storeBox->count);
        FileHelper::writeInt(file, storeBox->desc.cost);
    }

    FileHelper::writeInt(file, repairBoxes.size() > 0);
    if (repairBoxes.size() > 0)
    {
        FileHelper::writeInt(file, repairBoxes[0]->desc.cost);
    }

    FileHelper::writeInt(file, itemPurchaseLimit);
    FileHelper::writeInt(file, itemsPurchased);
}

void StoreComplete::LoadStore(int file, int worldLevel)
{
    int pageCount = FileHelper::readInteger(file);
    for (int pageNum = 0; pageNum < pageCount; pageNum++)
    {
        StorePage page = StorePage();

        int secCount = FileHelper::readInteger(file);

        for (int secNum = 0; secNum < secCount; secNum++)
        {
            StoreSection sec = StoreSection();

            sec.category = static_cast<CategoryType>(FileHelper::readInteger(file));
            sec.customTitle = FileHelper::readString(file);
            int boxSecCount = FileHelper::readInteger(file);

            for (int boxSecNum = 0; boxSecNum < boxSecCount; boxSecNum++)
            {
                int boxCount = FileHelper::readInteger(file);

                std::vector<CustomStoreBox*> boxSec = std::vector<CustomStoreBox*>();

                for (int boxNum = 0; boxNum < boxCount; boxNum++)
                {
                    int count = FileHelper::readInteger(file);

                    if (count == -1)
                    {
                        continue;
                    }

                    std::string blueprintName = FileHelper::readString(file);

                    CustomStoreBox* box = new CustomStoreBox();

                    switch (sec.category)
                    {
                    case CategoryType::WEAPONS:

                        box->orig = new WeaponStoreBox(nullptr, nullptr, G_->GetBlueprints()->GetWeaponBlueprint(blueprintName));
                        break;
                    case CategoryType::DRONES:
                        box->orig = new DroneStoreBox(nullptr, nullptr, G_->GetBlueprints()->GetDroneBlueprint(blueprintName));
                        break;
                    case CategoryType::AUGMENTS:
                        box->orig = new AugmentStoreBox(nullptr, G_->GetBlueprints()->GetAugmentBlueprint(blueprintName));
                        break;
                    case CategoryType::CREW:
                        box->orig = new CrewStoreBox(nullptr, worldLevel, blueprintName);
                        break;
                    case CategoryType::SYSTEMS:
                        box->orig = new SystemStoreBox(nullptr, nullptr, ShipSystem::NameToSystemId(blueprintName));
                        break;
                    }

                    box->orig->count = count;
                    box->orig->SetExtraData(FileHelper::readInteger(file));
                    box->orig->desc.cost = FileHelper::readInteger(file);

                    box->showSale = FileHelper::readInteger(file);
                    box->originalPrice = FileHelper::readInteger(file);
                    box->mysteryItem = FileHelper::readInteger(file);

                    boxSec.push_back(box);
                }

                sec.storeBoxes.push_back(boxSec);
            }

            page.sections.push_back(sec);
        }

        pages.push_back(page);
    }


    int resourceBoxCount = FileHelper::readInteger(file);
    for (int i = 0; i < resourceBoxCount; i++)
    {
        int itemId = FileHelper::readInteger(file);

        std::string blueprintName;

        if (itemId == 0) blueprintName = "missiles";
        else if (itemId == 1) blueprintName = "fuel";
        else blueprintName = "drones";

        ItemStoreBox* box = new ItemStoreBox(nullptr, blueprintName);

        box->count = FileHelper::readInteger(file);
        box->desc.cost = FileHelper::readInteger(file);

        resourceBoxes.push_back(box);
    }

    bool hasRepairBoxes = FileHelper::readInteger(file);

    if (hasRepairBoxes)
    {
        int price = FileHelper::readInteger(file);
        RepairStoreBox* repairOne = new RepairStoreBox(nullptr, false, price);
        RepairStoreBox* repairAll = new RepairStoreBox(nullptr, true, price);

        repairBoxes.push_back(repairOne);
        repairBoxes.push_back(repairAll);
    }

    itemPurchaseLimit = FileHelper::readInteger(file);
    itemsPurchased = FileHelper::readInteger(file);
}

void StoreComplete::RelinkShip(ShipManager *ship, Equipment *equip)
{
    orig->shopper = ship;

    for (auto pg : pages)
    {
        for (auto sec : pg.sections)
        {
            for (auto boxSec : sec.storeBoxes)
            {
                for (auto box : boxSec)
                {
                    box->orig->shopper = ship;
                    box->orig->equipScreen = equip;
                }
            }
        }
    }

    for (auto i : repairBoxes)
    {
        i->shopper = ship;
        i->equipScreen = equip;
    }

    for (auto i : resourceBoxes)
    {
        i->shopper = ship;
        i->equipScreen = equip;
    }
}

std::string customStoreId;

HOOK_METHOD(WorldManager, CreateStore, (LocationEvent *event) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateStore -> Begin (CustomStore.cpp)\n")
    auto customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(event->eventName);

    customStoreId = "";


    if (customEvent)
    {
        customStoreId = customEvent->customStore;
    }

    super(event);
}

HOOK_METHOD(Store, OnInit, (ShipManager *_shopper, Equipment *_equip, int _worldLevel) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Store::OnInit -> Begin (CustomStore.cpp)\n")
    if (!customStoreId.empty() || !CustomStore::instance->forceCustomStore.empty())
    {
        std::string storeId = CustomStore::instance->forceCustomStore;

        if (storeId.empty()) storeId = customStoreId;

        auto def = CustomStore::instance->GetStoreDefinition(storeId);

        if (def && !STORE_EX(this)->isCustomStore)
        {
            StoreComplete* newStore = new StoreComplete(this);

            STORE_EX(this)->isCustomStore = true;
            STORE_EX(this)->customStore = newStore;

            // Moved this after setting isCustomStore as Store::CreateStoreBoxes will check isCustomStore
            newStore->OnInit(*def, _shopper, _equip, _worldLevel);

            return;
        }

        CustomStore::instance->forceCustomStore = "";
    }

    super(_shopper, _equip, _worldLevel);
}

HOOK_METHOD(Store, RelinkShip, (ShipManager *ship, Equipment *equip) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Store::RelinkShip -> Begin (CustomStore.cpp)\n")
    if (STORE_EX(this)->isCustomStore)
    {
        STORE_EX(this)->customStore->RelinkShip(ship, equip);
        // do stuff
        return;
    }

    super(ship, equip);
}

HOOK_METHOD(Store, LoadStore, (int file, int worldLevel) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Store::LoadStore -> Begin (CustomStore.cpp)\n")
    bool isCustomStore = FileHelper::readInteger(file);

    STORE_EX(this)->isCustomStore = isCustomStore;

    if (isCustomStore)
    {
        STORE_EX(this)->customStore = new StoreComplete(this);
        STORE_EX(this)->customStore->LoadStore(file, worldLevel);

        return;
    }

    super(file, worldLevel);
}

HOOK_METHOD(Store, SaveStore, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Store::SaveStore -> Begin (CustomStore.cpp)\n")
    FileHelper::writeInt(file, STORE_EX(this)->isCustomStore);

    if (STORE_EX(this)->isCustomStore)
    {
        STORE_EX(this)->customStore->SaveStore(file);

        return;
    }

    super(file);


}

HOOK_METHOD(Store, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Store::OnLoop -> Begin (CustomStore.cpp)\n")
    if (STORE_EX(this)->isCustomStore)
    {
        STORE_EX(this)->customStore->OnLoop();
        return;
    }

    super();
}

HOOK_METHOD(Store, SetPositions, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Store::SetPositions -> Begin (CustomStore.cpp)\n")
    if (STORE_EX(this)->isCustomStore)
    {
        STORE_EX(this)->customStore->SetPositions();
        return;
    }

    super();
}

HOOK_METHOD(Store, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Store::MouseMove -> Begin (CustomStore.cpp)\n")
    if (STORE_EX(this)->isCustomStore)
    {
        STORE_EX(this)->customStore->MouseMove(x, y);
        return;
    }

    super(x, y);
}

HOOK_METHOD(Store, MouseClick, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Store::MouseClick -> Begin (CustomStore.cpp)\n")
    if (STORE_EX(this)->isCustomStore)
    {
        STORE_EX(this)->customStore->MouseClick(x, y);
        return;
    }

    super(x, y);
}

HOOK_METHOD(Store, CreateStoreBoxes, (int category, Equipment* equip) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Store::CreateStoreBoxes -> Begin (CustomStore.cpp)\n")
    if (category == 4) // systems
    {
        bool guaranteedShields = !shopper->HasSystem(0);
        bool guaranteedDrones = (!shopper->HasSystem(4)) && (types[0] == 1 || types[1] == 1 || types[2] == 1 || types[3] == 1);
        int guaranteedMedicalId = -1;

        auto& systemPlacements = shopper->myBlueprint.systemInfo;

        if (!shopper->HasSystem(5) && (!Settings::GetDlcEnabled() || !shopper->HasSystem(13)))
        {
            if (!Settings::GetDlcEnabled() || systemPlacements.find(SYS_CLONEBAY) == systemPlacements.end())
            {
                guaranteedMedicalId = SYS_MEDBAY;
            }
            else if (systemPlacements.find(SYS_MEDBAY) == systemPlacements.end())
            {
                guaranteedMedicalId = SYS_CLONEBAY;
            }
            else
            {
                if ((random32() & 1) == 0)
                {
                    guaranteedMedicalId = SYS_MEDBAY;
                }
                else
                {
                    guaranteedMedicalId = SYS_CLONEBAY;
                }
            }
        }

        int numAddedSystems = 0;

        if (guaranteedDrones && systemPlacements.find(SYS_DRONES) != systemPlacements.end())
        {
            vStoreBoxes.push_back(new SystemStoreBox(shopper, equip, SYS_DRONES));
            numAddedSystems++;
        }
        if (guaranteedShields && systemPlacements.find(SYS_SHIELDS) != systemPlacements.end())
        {
            vStoreBoxes.push_back(new SystemStoreBox(shopper, equip, SYS_SHIELDS));
            numAddedSystems++;
        }
        if (guaranteedMedicalId != -1 && systemPlacements.find(guaranteedMedicalId) != systemPlacements.end())
        {
            vStoreBoxes.push_back(new SystemStoreBox(shopper, equip, guaranteedMedicalId));
            numAddedSystems++;
        }

        std::vector<int> newSystems = std::vector<int>();

        std::vector<int> systemCheckList = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 20 };
        std::vector<int> aeSystems = { 12, 13, 14, 15 };

        if (Settings::GetDlcEnabled())
        {
            systemCheckList.insert(systemCheckList.end(), aeSystems.begin(), aeSystems.end());
        }

        for (auto sysId : systemCheckList)
        {
            if (sysId == SYS_SHIELDS && guaranteedShields ||
                sysId == SYS_DRONES && guaranteedDrones ||
                (sysId == SYS_MEDBAY || sysId == SYS_CLONEBAY) && guaranteedMedicalId>0)
            {
                continue;
            }

            auto bp = G_->GetBlueprints()->GetSystemBlueprint(ShipSystem::SystemIdToName(sysId));

            if (!shopper->HasSystem(sysId) && bp && bp->desc.rarity > 0 && systemPlacements.find(sysId) != systemPlacements.end())
            {
                newSystems.push_back(sysId);
            }
        }


        if (STORE_EX(this)->isCustomStore)
        {
            for (int i = 0; i < (3 - numAddedSystems); i++)
            {
                if (newSystems.size() == 0)
                {
                    vStoreBoxes.push_back(new StoreBox("storeUI/store_weapons", nullptr, nullptr));
                    continue;
                }

                int chosenIdx = random32() % newSystems.size();

                vStoreBoxes.push_back(new SystemStoreBox(shopper, equip, newSystems[chosenIdx]));

                newSystems.erase(newSystems.begin() + chosenIdx);
            }
        }
        else
        {
            // This should replicate the original behaviour in vanilla.
            int numSystemsToAdd = 3;
            if (newSystems.size() < 3) numSystemsToAdd = newSystems.size();
            numSystemsToAdd -= numAddedSystems;
            for (int i = 0; i < newSystems.size(); i++)
            {
                if (numSystemsToAdd <= 0) break;
                if (random32()%(newSystems.size()-i) < numSystemsToAdd)
                {
                    vStoreBoxes.push_back(new SystemStoreBox(shopper, equip, newSystems[i]));
                    numAddedSystems++;
                    numSystemsToAdd--;
                }
            }

            for (int i = 0; i < (3 - numAddedSystems); i++)
            {
                vStoreBoxes.push_back(new StoreBox("storeUI/store_weapons", nullptr, nullptr));
                continue;
            }
        }

        return;
    }

    return super(category, equip);
}
static int newSystem = -1;
static int replaceSystem = -1;
HOOK_METHOD(SystemStoreBox, Activate, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemStoreBox::Activate -> Begin (CustomStore.cpp)\n")
    if (shopper->currentScrap < desc.cost) return super(); // Not enough scrap
    if ((itemId == SYS_MEDBAY && shopper->HasSystem(SYS_CLONEBAY) || itemId == SYS_CLONEBAY && shopper->HasSystem(SYS_MEDBAY)) && !CustomOptionsManager::GetInstance()->duelMedical.currentValue) return super(); // Change medical system
    bool isSubsystem = ShipSystem::IsSubsystem(itemId);

    auto custom = CustomShipSelect::GetInstance();
    int sysLimit = isSubsystem ? custom->GetDefinition(shopper->myBlueprint.blueprintName).subsystemLimit : custom->GetDefinition(shopper->myBlueprint.blueprintName).systemLimit;

    if (isSubsystem && sysLimit >= 4) return super(); // Subsystem limit doesn't currently matter if one can have at least 4.

    int sysCount = 0;

    for (auto i : shopper->vSystemList)
    {
        if (i->bNeedsPower != isSubsystem)
        {
            sysCount++;
        }
    }

    if (sysLimit - sysCount == 1)
    {
        bConfirming = true;
        confirmString = "confirm_buy_last_system";
    }

    if (shopper->SystemWillReplace(itemId) != SYS_INVALID)
    {
        newSystem = itemId;
        replaceSystem = shopper->SystemWillReplace(itemId);
        bConfirming = true;
    }

    if (!bConfirming)
    {
        Purchase();
    }
}

HOOK_METHOD(SystemStoreBox, GetConfirmText, () -> TextString)
{
    LOG_HOOK("HOOK_METHOD -> SystemStoreBox::GetConfirmText -> Begin (CustomStore.cpp)\n")
    if (newSystem == -1 || replaceSystem == -1) return super();

    std::string newSystemName = G_->GetBlueprints()->GetSystemBlueprint(ShipSystem::SystemIdToName(newSystem))->GetNameLong();
    std::string replaceSystemName = G_->GetBlueprints()->GetSystemBlueprint(ShipSystem::SystemIdToName(replaceSystem))->GetNameLong();
    
    std::string confirmText = G_->GetTextLibrary()->GetText("confirm_buy_custom");
    boost::algorithm::replace_all(confirmText, "\\1", newSystemName);
    boost::algorithm::replace_all(confirmText, "\\2", replaceSystemName);

    newSystem = -1;
    replaceSystem = -1;

    return TextString(confirmText, true);
}
