#include "Global.h"
#include "CustomEquipment.h"
#include "Equipment_Extend.h"
#include "CustomShipSelect.h"
#include <boost/algorithm/string.hpp>

bool g_multipleOverCapacity = false;
bool g_showDummyEquipmentSlots = false;
float g_dummyEquipmentSlotsOpacity = 0.2f;

HOOK_METHOD(InfoBox, SetBlueprintWeapon, (const WeaponBlueprint* bp, int status, bool hasWeaponSystem, int yShift) -> void)
{
    LOG_HOOK("HOOK_METHOD -> InfoBox::SetBlueprintWeapon -> Begin (CustomEquipment.cpp)\n")
    if (hasWeaponSystem && status == 1)
    {
        return super(bp, 2, hasWeaponSystem, yShift);
    }

    super(bp, 2, hasWeaponSystem, yShift);
}


HOOK_METHOD(InfoBox, SetBlueprintWeapon, (const WeaponBlueprint* bp, int status, bool hasWeaponSystem, int yShift) -> void)
{
    LOG_HOOK("HOOK_METHOD -> InfoBox::SetBlueprintWeapon -> Begin (CustomEquipment.cpp)\n")
    super(bp, status, hasWeaponSystem, yShift);

    Pointf titleSize = freetype::easy_measurePrintLines(16, 0, 0, descBoxSize.x, desc.title.GetText());
    Pointf descSize = freetype::easy_measurePrintLines(10, 0, 0, descBoxSize.x, desc.description.GetText());

    Pointf boxSize = titleSize + descSize + Pointf(0, 28.f);
    boxSize.y = std::max(boxSize.y, 252.f);

    delete primaryBox;
    primaryBox = new WindowFrame(7, 7, 323, boxSize.y);


    descBoxSize.y = boxSize.y + 14.f;
}


HOOK_METHOD_PRIORITY(Equipment, GetCargoHold, 9999, () -> std::vector<std::string>)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Equipment::GetCargoHold -> Begin (CustomEquipment.cpp)\n")
    // Rewrite to fix a vanilla item duplication bug.

    std::vector<std::string> ret = std::vector<std::string>();

    for (unsigned int i = this->cargoId; i<this->vEquipmentBoxes.size(); ++i)
    {
        if (!this->vEquipmentBoxes[i]->IsEmpty())
        {
            Blueprint *bp = this->vEquipmentBoxes[i]->GetBlueprint();
            ret.push_back(bp->name);
        }
    }

    if (g_multipleOverCapacity)
    {
        CustomEquipment *custom = EQ_EX(this)->customEquipment;
        for (unsigned int i = 0; i < custom->overCapacityItems.size(); ++i)
        {
            if (i == custom->currentOverCapacityPage) continue;

            EquipmentBoxItem item = custom->overCapacityItems[i].first;
            if (item.pWeapon)
            {
                ret.push_back(item.pWeapon->blueprint->name);
            }
            else if (item.pDrone)
            {
                ret.push_back(item.pDrone->blueprint->name);
            }
            else if (item.pCrew)
            {
                ret.push_back(item.pCrew->blueprint.name);
            }
            else if (item.augment)
            {
                ret.push_back(item.augment->name);
            }
        }
    }

    return ret;
}

HOOK_METHOD_PRIORITY(Equipment, AddToCargo, 9999, (const std::string& name) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Equipment::AddToCargo -> Begin (CustomEquipment.cpp)\n")
    // Rewrite to fix deleting 0 power weapons/drones in cargo.

    WeaponBlueprint *weapon = G_->GetBlueprints()->GetWeaponBlueprint(name);
    if (weapon && weapon->type != -1)
    {
        AddWeapon(weapon,true,true);
        return;
    }

    DroneBlueprint *drone = G_->GetBlueprints()->GetDroneBlueprint(name);
    if (drone && drone->type != -1)
    {
        AddDrone(drone,true,true);
        return;
    }

    AugmentBlueprint *aug = G_->GetBlueprints()->GetAugmentBlueprint(name);
    if (aug && !aug->name.empty())
    {
        AddAugment(aug,true,true);
        return;
    }
}


// multiple over capacity

HOOK_METHOD(Equipment, AddWeapon, (WeaponBlueprint *bp, bool free, bool forceCargo) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Equipment::AddWeapon -> Begin (CustomEquipment.cpp)\n")
    if (!g_multipleOverCapacity) return super(bp, free, forceCargo);

    super(bp, free, forceCargo);

    if (bOverCapacity)
    {
        EQ_EX(this)->customEquipment->AddOverCapacityItem(overcapacityBox->item);
    }
}

HOOK_METHOD(Equipment, AddDrone, (DroneBlueprint *bp, bool free, bool forceCargo) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Equipment::AddDrone -> Begin (CustomEquipment.cpp)\n")
    if (!g_multipleOverCapacity) return super(bp, free, forceCargo);

    super(bp, free, forceCargo);

    if (bOverCapacity)
    {
        EQ_EX(this)->customEquipment->AddOverCapacityItem(overcapacityBox->item);
    }
}

HOOK_METHOD(Equipment, AddAugment, (AugmentBlueprint *bp, bool free, bool forceCargo) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Equipment::AddAugment -> Begin (CustomEquipment.cpp)\n")
    if (!g_multipleOverCapacity) return super(bp, free, forceCargo);

    super(bp, free, forceCargo);

    if (bOverAugCapacity)
    {
        EQ_EX(this)->customEquipment->AddOverCapacityItem(overAugBox->item);
    }
}

HOOK_METHOD(Equipment, IsCompletelyFull, (int type) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> Equipment::IsCompletelyFull -> Begin (CustomEquipment.cpp)\n")
    // Equipment::AddWeapon, Equipment::AddDrone and Equipment::AddAugment aren't called if Equipment::IsCompletelyFull returns true.
    // To allow adding items to multiple overcapacityBoxes, this method must return false.

    if (!g_multipleOverCapacity) return super(type);

    if (type == 0 || type == 1 || type == 3)
    {
        return false;
    }
    return super(type);
}

// adjust store augment purchase limit

HOOK_METHOD_PRIORITY(AugmentStoreBox, CanHold, 9999, () -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> AugmentStoreBox::CanHold -> Begin (CustomEquipment.cpp)\n")
    // Rewrite to get over vanilla hard-coded augment slots limit.

    if (!shopper || CustomShipSelect::GetInstance()->GetDefinition(shopper->myBlueprint.blueprintName).augSlots <= shopper->GetAugmentationCount()) return false; // in vanilla, augSlots is hard-coded to 3.

    bool ret = true;
    if (shopper->HasAugmentation(blueprint->name))
    {
        ret = blueprint->stacking;
    }
    return ret;
}

HOOK_METHOD_PRIORITY(AugmentStoreBox, MouseMove, 9999, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> AugmentStoreBox::MouseMove -> Begin (CustomEquipment.cpp)\n")
    // Rewrite to get over vanilla hard-coded augment slots limit.

    button.MouseMove(mX, mY, false);
    if (count < 1 || !button.bHover) return;

    bool aug_duplicated = false;
    if (shopper->HasAugmentation(blueprint->name))
    {
        aug_duplicated = !blueprint->stacking;
    }

    std::string tooltip;
    if (!aug_duplicated)
    {
        if (!button.bHover) return;

        int augMax = CustomShipSelect::GetInstance()->GetDefinition(shopper->myBlueprint.blueprintName).augSlots;
        if (shopper->GetAugmentationCount() < augMax) return; // in vanilla, augMax is hard-coded to 3.

        tooltip = G_->GetTextLibrary()->GetText("max_augments");
        boost::algorithm::replace_all(tooltip, "\\1", std::to_string(augMax));
    }
    else
    {
        tooltip = G_->GetTextLibrary()->GetText("have_augment");
    }

    G_->GetMouseControl()->SetTooltip(tooltip);
    G_->GetMouseControl()->InstantTooltip();
}

ShipManager *g_shipManager = nullptr;

HOOK_METHOD(ShipManager, ImportShip, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ImportShip -> Begin (CustomEquipment.cpp)\n")
    ShipManager *orig = g_shipManager;
    g_shipManager = this;
    super(file);
    g_shipManager = orig;
}

// called within ShipManager::ImportShip via ShipManager::OnInit
HOOK_METHOD(ShipManager, CreateArmory, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CreateArmory -> Begin (CustomEquipment.cpp)\n")
    ShipManager *orig = g_shipManager;
    g_shipManager = this;
    super();
    g_shipManager = orig;
}

// not sure if this is necessary. I cant conifrm if this is called in any vanilla code.
HOOK_METHOD(ShipManager, AddEquipmentFromList, (std::vector<std::string> *equipmentList) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::AddEquipmentFromList -> Begin (CustomEquipment.cpp)\n")
    ShipManager *orig = g_shipManager;
    g_shipManager = this;
    super(equipmentList);
    g_shipManager = orig;
}

HOOK_METHOD_PRIORITY(ShipObject, AddAugmentation, 1000, (const std::string& name) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipObject::AddAugmentation -> Begin (CustomEquipment.cpp)\n")
    ShipManager *ship = g_shipManager ? g_shipManager : G_->GetShipManager(iShipId);
    if (!ship)
    {
        hs_log_file("\nship not found in adding augment. shipId: %d (CustomEquipment.cpp)\n", iShipId);
        return super(name);
    }

    int augMax = CustomShipSelect::GetInstance()->GetDefinition(ship->myBlueprint.blueprintName).augSlots;

    ShipInfo *info = G_->GetShipInfo(iShipId);
    if (2 < info->augCount && info->augCount < augMax)
    {
        int origAugCount = info->augCount;
        info->augCount = 0;
        bool ret = super(name);
        info->augCount += origAugCount;
        return ret;
    }
    return super(name);
}

HOOK_METHOD(Equipment, Jump, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Equipment::Jump -> Begin (CustomEquipment.cpp)\n")
    super();

    CustomEquipment *custom = EQ_EX(this)->customEquipment;
    custom->overCapacityItems.clear();
    custom->currentOverCapacityPage = 0;
}


// custom equipment

void CustomEquipment::OnInit(ShipManager *ship)
{
    for (auto trash : orig->weaponsTrashList)
    {
        if (trash)
        {
            delete trash;
        }
    }
    orig->weaponsTrashList.clear();

    for (auto box : orig->vEquipmentBoxes)
    {
        if (box)
        {
            delete box;
        }
    }
    orig->vEquipmentBoxes.clear();

    orig->bOverCapacity = false;
    orig->shipManager = ship;
    orig->bOverAugCapacity = false;
    orig->box = G_->GetResources()->GetImageId("upgradeUI/Equipment/equipment_main.png");
    orig->storeBox = G_->GetResources()->GetImageId("storeUI/store_sell_main.png");

    TextString overBoxTitle = TextString("overcapacity_item_title", false);
    TextString overBoxBody = TextString("overcapacity_item_text1", false);
    TextString overBoxLower = TextString("overcapacity_item_text2", false);
    orig->overBox.OnInit(Point(-275, 100), false, &overBoxTitle, &overBoxBody, 100, &overBoxLower);

    TextString overAugTitle = TextString("overcapacity_aug_title", false);
    TextString overAugBody = TextString("overcapacity_aug_text1", false);
    TextString overAugLower = TextString("overcapacity_aug_text2", false);
    orig->overAugImage.OnInit(Point(-275, 100), false, &overAugTitle, &overAugBody, 65, &overAugLower);

    TextString sellBoxTitle = TextString("sell_box_title", false);
    TextString sellBoxBody = TextString("sell_box_text", false);
    TextString sellBoxLower = TextString("", true);
    orig->sellBox.OnInit(Point(0, 0), true, &sellBoxTitle, &sellBoxBody, 0, &sellBoxLower);


    for (int i = 0; i < orig->shipManager->myBlueprint.weaponSlots; ++i)
    {
        WeaponEquipBox *box = new WeaponEquipBox(Point(0, 0), orig->shipManager->weaponSystem, i);
        orig->vEquipmentBoxes.push_back(box);
    }

    for (int i = 0; i < orig->shipManager->myBlueprint.droneSlots; ++i)
    {
        DroneEquipBox *box = new DroneEquipBox(Point(0, 0), orig->shipManager->droneSystem, i);
        orig->vEquipmentBoxes.push_back(box);
    }

    auto custom = CustomShipSelect::GetInstance();
    augNumber = custom->GetDefinition(ship->myBlueprint.blueprintName).augSlots;

    for (int i = 0; i < augNumber; ++i)
    {
        AugmentEquipBox *box = new AugmentEquipBox(Point(0, 0), orig->shipManager, i);
        orig->vEquipmentBoxes.push_back(box);
    }

    if (!augLeftButton)
    {
        augLeftButton = new Button();
        augLeftButton->OnInit("statusUI/button_crew_up", Point(orig->position.x + 571, orig->position.y + 339));
    }
    if (!augRightButton)
    {
        augRightButton = new Button();
        augRightButton->OnInit("statusUI/button_crew_down", Point(orig->position.x + 571, orig->position.y + 394));
    }

    currentAugPage = 0;
    maxAugPage = std::max((augNumber - 1) / 3, 0);

    orig->cargoId = orig->vEquipmentBoxes.size();

    cargoNumber = custom->GetDefinition(ship->myBlueprint.blueprintName).cargoSlots;

    for (int i = 0; i < cargoNumber; ++i)
    {
        EquipmentBox *box = new EquipmentBox(Point(0, 0), i);
        orig->vEquipmentBoxes.push_back(box);
    }

    orig->overcapacityBox = new EquipmentBox(Point(0, 0), 4);
    orig->vEquipmentBoxes.push_back(orig->overcapacityBox);

    orig->overAugBox = new AugmentEquipBox(Point(0, 0), nullptr, 4);
    orig->vEquipmentBoxes.push_back(orig->overAugBox);

    orig->SetPosition(orig->position);

    for (auto box : orig->vEquipmentBoxes)
    {
        box->CheckContents();
    }

    currentCargoPage = 0;
    maxCargoPage = std::max((cargoNumber - 1) / 4, 0);

    if (!cargoLeftButton)
    {
        cargoLeftButton = new Button();
        cargoLeftButton->OnInit("upgradeUI/buttons_system_arrow", Point(orig->position.x + 16, orig->position.y + 369));
    }
    if (!cargoRightButton)
    {
        cargoRightButton = new Button();
        cargoRightButton->OnInit("upgradeUI/buttons_system_arrow", Point(orig->position.x + 278, orig->position.y + 369));
        cargoRightButton->bMirror = true;
    }

    if (!overCapacityLeftButton)
    {
        overCapacityLeftButton = new Button();
        overCapacityLeftButton->OnInit("upgradeUI/Equipment/button_crew_arrow", Point(orig->position.x - 95, orig->position.y + 70));
    }
    if (!overCapacityRightButton)
    {
        overCapacityRightButton = new Button();
        overCapacityRightButton->OnInit("upgradeUI/Equipment/button_crew_arrow", Point(orig->position.x - 60, orig->position.y + 70));
        overCapacityRightButton->bMirror = true;
    }

    overCapacityItems.clear();
}

void CustomEquipment::SetPosition(Point p)
{
    orig->position = p;
    if (!orig->shipManager) return;

    orig->infoBoxLoc = Point(orig->position.x + 600, orig->position.y);
    orig->infoBox.location = Point(orig->position.x + 600, orig->position.y - 25);
    orig->sellBox.position = Point(orig->position.x - 275, orig->position.y + 100);

    int weaponSlots = orig->shipManager->myBlueprint.weaponSlots;
    int droneSlots = orig->shipManager->myBlueprint.droneSlots;

    int i = 0;
    int x = (4 - weaponSlots) * 58 + orig->position.x + 63;
    // set weapon slots position
    for (; i < weaponSlots; ++i)
    {
        orig->vEquipmentBoxes[i]->SetPosition(Point(x + 117 * i, orig->position.y + 70));
    }

    x = (4 - droneSlots) * 58 + orig->position.x + 63;
    // set drone slots position
    for (int j = 0; j < droneSlots; ++j)
    {
        orig->vEquipmentBoxes[i]->SetPosition(Point(x + 117 * j, orig->position.y + 180));
        ++i;
    }

    int y = orig->position.y + 293;
    // set augment slots position
    for (int j = 0; j < augNumber; ++j)
    {
        orig->vEquipmentBoxes[i]->SetPosition(Point(orig->position.x + 330, y + 60 * (j % 3)));
        ++i;
    }

    // set cargo slots position
    for (int j = 0; j < cargoNumber; ++j)
    {
        switch (j % 4)
        {
            case 0:
                x = orig->position.x + 30;
                y = orig->position.y + 293;
                break;
            case 1:
                x = orig->position.x + 160;
                y = orig->position.y + 293;
                break;
            case 2:
                x = orig->position.x + 30;
                y = orig->position.y + 373;
                break;
            case 3:
                x = orig->position.x + 160;
                y = orig->position.y + 373;
                break;
        }
        orig->vEquipmentBoxes[i]->SetPosition(Point(x, y));
        ++i;
    }

    orig->overcapacityBox->SetPosition(Point(orig->position.x + orig->overBox.position.x + 80, orig->position.y + orig->overBox.position.y + orig->overBox.GetBodySpaceOffset()));
    orig->overAugBox->SetPosition(Point(orig->position.x + orig->overAugImage.position.x + 19, orig->position.y + orig->overAugImage.position.y + orig->overAugImage.GetBodySpaceOffset() + 4));
    Globals::Rect overcapacytBoxRect = Globals::Rect(orig->position.x + orig->overBox.position.x, orig->position.y + orig->overBox.position.y, 272, orig->overBox.GetHeight());
    orig->overcapacityBox->ForceHitBox(&overcapacytBoxRect);
    Globals::Rect overAugBoxRect = Globals::Rect(orig->position.x + orig->overAugImage.position.x, orig->position.y + orig->overAugImage.position.y, 272, orig->overAugImage.GetHeight());
    orig->overAugBox->ForceHitBox(&overAugBoxRect);

    if (augLeftButton) augLeftButton->SetLocation(Point(orig->position.x + 571, orig->position.y + 339));
    if (augRightButton) augRightButton->SetLocation(Point(orig->position.x + 571, orig->position.y + 394));

    if (cargoLeftButton) cargoLeftButton->SetLocation(Point(orig->position.x + 16, orig->position.y + 369));
    if (cargoRightButton) cargoRightButton->SetLocation(Point(orig->position.x + 278, orig->position.y + 369));
}

void CustomEquipment::OnRender()
{
    CSurface::GL_PushMatrix();
    if (orig->bStoreMode)
    {
        // Adjust sellBox position. sellBox is completely overlapped by over capacity box in vanilla.
        if (orig->bStoreMode && orig->bOverCapacity)
        {
            orig->sellBox.position = Point(orig->position.x - 275, orig->position.y + orig->overBox.position.y + orig->overBox.GetHeight() - 5);
        }
        else if (orig->bStoreMode && orig->bOverAugCapacity)
        {
            orig->sellBox.position = Point(orig->position.x - 275, orig->position.y + orig->overAugImage.position.y + orig->overAugImage.GetHeight() - 5);
        }
        else
        {
            orig->sellBox.position = Point(orig->position.x - 275, orig->position.y + 100);
        }
        orig->sellBox.sellCostText = orig->sellCostText;
        orig->sellBox.OnRender();
    }
    CSurface::GL_Translate(orig->position.x, orig->position.y);
    if (orig->bStoreMode)
    {
        G_->GetResources()->RenderImage(orig->storeBox, 0, 0, 0, COLOR_WHITE, 1.f, false);
    }
    else
    {
        G_->GetResources()->RenderImage(orig->box, 0, -7, 0, COLOR_WHITE, 1.f, false);
    }
    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);
    if (orig->bStoreMode)
    {
        Store::DrawBuySellTabText();
    }
    auto lib = G_->GetTextLibrary();
    freetype::easy_print(62, 18.f, 44.f, lib->GetText("equipment_frame_weapons"));
    freetype::easy_print(62, 18.f, 154.f, lib->GetText("equipment_frame_drones"));
    freetype::easy_print(62, 18.f, 264.f, lib->GetText("equipment_frame_cargo"));
    freetype::easy_print(62, 307.f, 264.f, lib->GetText("equipment_frame_augments"));
    if (maxAugPage > 0)
    {
        freetype::easy_printRightAlign(62, 582.f, 264.f, std::to_string(currentAugPage + 1) + "/" + std::to_string(maxAugPage + 1));
    }
    if (maxCargoPage > 0)
    {
        freetype::easy_printRightAlign(62, 288.f, 264.f, std::to_string(currentCargoPage + 1) + "/" + std::to_string(maxCargoPage + 1));
    }
    CSurface::GL_SetColor(COLOR_WHITE);
    if (orig->bOverCapacity)
    {
        orig->overBox.OnRender();
    }
    if (orig->bOverAugCapacity)
    {
        orig->overAugImage.OnRender();
    }
    CSurface::GL_PopMatrix();

    int weaponSlots = orig->shipManager->myBlueprint.weaponSlots;
    int droneSlots = orig->shipManager->myBlueprint.droneSlots;
    bool hasWeaopn = orig->shipManager->HasSystem(3);
    bool hasDrone = orig->shipManager->HasSystem(4);

    // FYI: vEquipmentBoxes = {weaopn slots..., drone slots..., augment slots..., cargo slots..., over capacity slot, over capacity augment slot}
    for (int i = 0; i < orig->vEquipmentBoxes.size(); ++i)
    {
        EquipmentBox *box = orig->vEquipmentBoxes[i];

        // skip unavailable boxes; when you dont install weapon or drone, their boxes are not rendered.
        if (!hasWeaopn && weaponSlots > i)
        {
            if (g_showDummyEquipmentSlots)
            {
                CSurface::GL_PushMatrix();
                CSurface::GL_Translate(box->location.x, box->location.y);
                box->UpdateBoxImage(false);
                CSurface::GL_RenderPrimitiveWithColor(box->empty, GL_Color(1.f, 1.f, 1.f, g_dummyEquipmentSlotsOpacity));
                CSurface::GL_PopMatrix();
            }
            continue;
        }

        if (!hasDrone && i >= weaponSlots && weaponSlots + droneSlots > i)
        {
            if (g_showDummyEquipmentSlots)
            {
                CSurface::GL_PushMatrix();
                CSurface::GL_Translate(box->location.x, box->location.y);
                box->UpdateBoxImage(false);
                CSurface::GL_RenderPrimitiveWithColor(box->empty, GL_Color(1.f, 1.f, 1.f, g_dummyEquipmentSlotsOpacity));
                CSurface::GL_PopMatrix();
            }
            continue;
        }

        // skip over capacity boxes; when you dont have over capacity, over capacity box is not rendered.
        if ((!orig->bOverCapacity && i == orig->vEquipmentBoxes.size() - 2) || (!orig->bOverAugCapacity && i == orig->vEquipmentBoxes.size() - 1))
        {
            continue;
        }

        if (weaponSlots + droneSlots <= i && i < orig->cargoId && !(weaponSlots + droneSlots + currentAugPage * 3 <= i && i < weaponSlots + droneSlots + (currentAugPage + 1) * 3))
        {
            continue;
        }

        if (orig->cargoId <= i && i < orig->vEquipmentBoxes.size() - 2 && !(orig->cargoId + currentCargoPage * 4 <= i && i < orig->cargoId + (currentCargoPage + 1) * 4))
        {
            continue;
        }

        // over capacity check have been done by the if statement above. idk why this exists in vanilla code.
        /*
        if (!orig->bOverCapacity && static_cast<void*>(box) == static_cast<void*>(orig->overcapacityBox))
        {
            continue;
        }
        if (!orig->bOverAugCapacity && static_cast<void*>(box) == static_cast<void*>(orig->overAugBox))
        {
            continue;
        }
        */

        box->OnRender(i == orig->draggingEquipBox ? orig->bDragging : false);
        box->RenderLabels(i == orig->draggingEquipBox ? orig->bDragging : false);
    }

    if (maxAugPage > 0)
    {
        augLeftButton->OnRender();
        augRightButton->OnRender();
    }

    if (maxCargoPage > 0)
    {
        cargoLeftButton->OnRender();
        cargoRightButton->OnRender();
    }

    if (overCapacityItems.size() > 1)
    {
        overCapacityLeftButton->OnRender();
        overCapacityRightButton->OnRender();
    }

    orig->infoBox.OnRender();
    CSurface::GL_SetColor(COLOR_BUTTON_ON);
    if (!hasWeaopn)
    {
        freetype::easy_printCenter(63, orig->position.x + 301, orig->position.y + 93, lib->GetText("equipment_no_system"));
    }
    if (!hasDrone)
    {
        freetype::easy_printCenter(63, orig->position.x + 301, orig->position.y + 203, lib->GetText("equipment_no_system"));
    }
    CSurface::GL_SetColor(COLOR_WHITE);
    if (orig->bDragging)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(orig->currentMouse.x, orig->currentMouse.y);
        orig->vEquipmentBoxes[orig->draggingEquipBox]->RenderIcon();
        CSurface::GL_PopMatrix();
    }
}

void CustomEquipment::MouseMove(int mX, int mY)
{
    if (!orig->bDragging)
    {
        orig->FocusWindow::MouseMove(mX, mY);
    }
    orig->selectedEquipBox = -1;
    orig->currentMouse = Point(mX, mY);
    for (auto box : orig->vEquipmentBoxes)
    {
        box->bGlow = false;
    }

    int weaponSlots = orig->shipManager->myBlueprint.weaponSlots;
    int droneSlots = orig->shipManager->myBlueprint.droneSlots;
    bool hasWeaopn = orig->shipManager->HasSystem(3);
    bool hasDrone = orig->shipManager->HasSystem(4);

    for (int i = 0; i < orig->vEquipmentBoxes.size(); ++i)
    {
        if ((!hasWeaopn && weaponSlots > i) || (!hasDrone && i >= weaponSlots && weaponSlots + droneSlots > i))
        {
            continue;
        }

        if ((!orig->bOverCapacity && i == orig->vEquipmentBoxes.size() - 2) || (!orig->bOverAugCapacity && i == orig->vEquipmentBoxes.size() - 1))
        {
            continue;
        }

        if (weaponSlots + droneSlots <= i && i < orig->cargoId && !(weaponSlots + droneSlots + currentAugPage * 3 <= i && i < weaponSlots + droneSlots + (currentAugPage + 1) * 3))
        {
            continue;
        }

        if (orig->cargoId <= i && i < orig->vEquipmentBoxes.size() - 2 && !(orig->cargoId + currentCargoPage * 4 <= i && i < orig->cargoId + (currentCargoPage + 1) * 4))
        {
            continue;
        }

        EquipmentBox *box = orig->vEquipmentBoxes[i];
        box->MouseMove(mX, mY);
        
        if (!box->bMouseHovering)
        {
            continue;
        }

        if (orig->bDragging)
        {
            if (box->bBlocked)
            {
                continue;
            }

            orig->selectedEquipBox = i;
        }
        else
        {
            orig->selectedEquipBox = i;
            if (box->IsEmpty())
            {
                continue;
            }
        }

        box->bGlow = true;
    }

    if (maxAugPage > 0)
    {
        augLeftButton->MouseMove(mX, mY, false);
        augRightButton->MouseMove(mX, mY, false);
    }

    if (maxCargoPage > 0)
    {
        cargoLeftButton->MouseMove(mX, mY, false);
        cargoRightButton->MouseMove(mX, mY, false);
    }

    if (overCapacityItems.size() > 1)
    {
        overCapacityLeftButton->MouseMove(mX, mY, false);
        overCapacityRightButton->MouseMove(mX, mY, false);
    }

    orig->infoBox.Clear();
    orig->sellCostText = "";
    if (orig->selectedEquipBox == -1)
    {
        if (!orig->bDragging)
        {
            orig->bSellingItem = false;
            orig->sellBox.selectedImage = 0;
            return;
        }
    }
    else
    {
        orig->vEquipmentBoxes[orig->selectedEquipBox]->SetBlueprint(&orig->infoBox, false);
        if (orig->vEquipmentBoxes[orig->selectedEquipBox]->IsEmpty() && !orig->bDragging)
        {
            orig->bSellingItem = false;
            orig->sellBox.selectedImage = 0;
            return;
        }
    }
    
    orig->sellCostText = std::to_string(orig->vEquipmentBoxes[orig->bDragging ? orig->draggingEquipBox : orig->selectedEquipBox]->GetItemValue() / 2);
    orig->bSellingItem = orig->bDragging && orig->bStoreMode && orig->sellBox.Contains(mX, mY);
    orig->sellBox.selectedImage = static_cast<int>(orig->bSellingItem);
}

void CustomEquipment::MouseClick(int mX, int mY)
{
    if (maxCargoPage > 0)
    {
        if (cargoLeftButton->bActive && cargoLeftButton->bHover)
        {
            if (currentCargoPage == 0)
            {
                currentCargoPage = maxCargoPage;
            }
            else
            {
                --currentCargoPage;
            }
        }

        if (cargoRightButton->bActive && cargoRightButton->bHover)
        {
            if (currentCargoPage == maxCargoPage)
            {
                currentCargoPage = 0;
            }
            else
            {
                ++currentCargoPage;
            }
        }
    }

    if (maxAugPage > 0)
    {
        if (augLeftButton->bActive && augLeftButton->bHover)
        {
            if (currentAugPage == 0)
            {
                currentAugPage = maxAugPage;
            }
            else
            {
                --currentAugPage;
            }
        }

        if (augRightButton->bActive && augRightButton->bHover)
        {
            if (currentAugPage == maxAugPage)
            {
                currentAugPage = 0;
            }
            else
            {
                ++currentAugPage;
            }
        }
    }

    if (overCapacityItems.size() > 1)
    {
        bool clicked = (overCapacityLeftButton->bActive && overCapacityLeftButton->bHover) || (overCapacityRightButton->bActive && overCapacityRightButton->bHover);
        if (clicked)
        {
            if (orig->bOverCapacity)
            {
                overCapacityItems[currentOverCapacityPage].first = orig->overcapacityBox->item;
                orig->overcapacityBox->RemoveItem();
            }
            else if (orig->bOverAugCapacity)
            {
                overCapacityItems[currentOverCapacityPage].first = orig->overAugBox->item;
                orig->overAugBox->RemoveItem();
            }
            orig->bOverCapacity = false;
            orig->bOverAugCapacity = false;

            if (overCapacityLeftButton->bActive && overCapacityLeftButton->bHover)
            {
                if (currentOverCapacityPage == 0)
                {
                    currentOverCapacityPage = overCapacityItems.size() - 1;
                }
                else
                {
                    --currentOverCapacityPage;
                }
            }

            if (overCapacityRightButton->bActive && overCapacityRightButton->bHover)
            {
                if (currentOverCapacityPage == overCapacityItems.size() - 1)
                {
                    currentOverCapacityPage = 0;
                }
                else
                {
                    ++currentOverCapacityPage;
                }
            }

            if (overCapacityItems[currentOverCapacityPage].second)
            {
                orig->overAugBox->AddItem(overCapacityItems[currentOverCapacityPage].first);
                orig->bOverCapacity = false;
                orig->bOverAugCapacity = true;
            }
            else
            {
                orig->overcapacityBox->AddItem(overCapacityItems[currentOverCapacityPage].first);
                orig->bOverCapacity = true;
                orig->bOverAugCapacity = false;
            }
        }
    }
}

void CustomEquipment::AddOverCapacityItem(const EquipmentBoxItem &item)
{
    overCapacityItems.push_back(std::make_pair(item, item.augment));
    orig->bOverCapacity = !overCapacityItems[0].second;
    orig->bOverAugCapacity = overCapacityItems[0].second;
    orig->overcapacityBox->RemoveItem();
    orig->overAugBox->RemoveItem();
    if (orig->bOverCapacity)
    {
        orig->overcapacityBox->AddItem(overCapacityItems[0].first);
    }
    else if (orig->bOverAugCapacity)
    {
        orig->overAugBox->AddItem(overCapacityItems[0].first);
    }
    currentOverCapacityPage = 0;
}


HOOK_METHOD_PRIORITY(Equipment, OnInit, 9999, (ShipManager *ship) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Equipment::OnInit -> Begin (CustomEquipment.cpp)\n")
    EQ_EX(this)->customEquipment->OnInit(ship);
}

HOOK_METHOD_PRIORITY(Equipment, SetPosition, 9999, (Point p) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Equipment::SetPosition -> Begin (CustomEquipment.cpp)\n")
    EQ_EX(this)->customEquipment->SetPosition(p);
}

HOOK_METHOD_PRIORITY(Equipment, OnRender, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Equipment::OnRender -> Begin (CustomEquipment.cpp)\n")
    EQ_EX(this)->customEquipment->OnRender();
}

HOOK_METHOD_PRIORITY(Equipment, MouseMove, 9999, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Equipment::MouseMove -> Begin (CustomEquipment.cpp)\n")
    EQ_EX(this)->customEquipment->MouseMove(mX, mY);
}

HOOK_METHOD(Equipment, MouseClick, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Equipment::MouseClick -> Begin (CustomEquipment.cpp)\n")
    super(mX, mY);
    EQ_EX(this)->customEquipment->MouseClick(mX, mY);
}


// unused rewrite
/*
HOOK_METHOD_PRIORITY(Equipment, MouseClick, 9999, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Equipment::MouseClick -> Begin (CustomEquipment.cpp)\n")
    FocusWindow::MouseClick(mX, mY);
    if (selectedEquipBox == -1) return;

    if (!vEquipmentBoxes[selectedEquipBox]->IsEmpty())
    {
        bDragging = true;
        draggingEquipBox = selectedEquipBox;
        firstMouse = currentMouse;
    }
}

HOOK_METHOD_PRIORITY(Equipment, MouseUp, 9999, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Equipment::MouseUp -> Begin (CustomEquipment.cpp)\n")
    if (!bDragging) return;

    if (!bSellingItem)
    {
        if (selectedEquipBox != -1 && selectedEquipBox != draggingEquipBox)
        {
            EquipmentBoxItem draggingItem = vEquipmentBoxes[draggingEquipBox]->item;
            EquipmentBoxItem selectedItem = vEquipmentBoxes[selectedEquipBox]->item;
            if (vEquipmentBoxes[selectedEquipBox]->IsEmpty())
            {
                vEquipmentBoxes[draggingEquipBox]->RemoveItem();
            }
            else
            {
                if (vEquipmentBoxes[draggingEquipBox]->item.augment && !vEquipmentBoxes[draggingEquipBox]->item.augment.name.empty())
                {
                    vEquipmentBoxes[draggingEquipBox]->RemoveItem();
                }
                vEquipmentBoxes[draggingEquipBox]->AddItem(selectedItem);
            }

            if (vEquipmentBoxes[selectedEquipBox]->item.augment && !vEquipmentBoxes[selectedEquipBox]->item.augment.name.empty())
            {
                vEquipmentBoxes[selectedEquipBox]->RemoveItem();
            }
            vEquipmentBoxes[selectedEquipBox]->AddItem(draggingItem);
        }
    }
    else
    {
        shipManager->ModifyScrapCount(vEquipmentBoxes[draggingEquipBox]->GetItemValue() / 2, false);
        G_->GetSoundControl()->PlaySoundMix("buy", -1, false);
        vEquipmentBoxes[draggingEquipBox]->RemoveItem();
        sellBox.selectedImage = 0;
    }
    bDragging = false;
    draggingEquipBox = -1;
}
*/
