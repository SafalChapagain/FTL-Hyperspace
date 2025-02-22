#include "CustomTabbedWindow.h"
#include "CustomCrewManifest.h"

CustomTabbedWindow CustomTabbedWindow::instance = CustomTabbedWindow();
GL_Texture* altEquipmentBox = nullptr;

void CustomTabbedWindow::ParseWindowNode(rapidxml::xml_node<char>* node)
{
    for (rapidxml::xml_node<char>* tabNode = node->first_node("tab"); tabNode; tabNode = tabNode->next_sibling("tab")) 
    {
        Tab newTab;

        newTab.butPos = Point(xPos, -7);
        xPos += hitboxWidth;
        
        if(tabNode->first_attribute("name")){
            newTab.name = tabNode->first_attribute("name")->value();
        }
        if (tabNode->first_attribute("windowPath")) {
            std::string windowPath = tabNode->first_attribute("windowPath")->value();
            newTab.background = G_->GetResources()->GetImageId(windowPath + ".png");
        }
        if (tabNode->first_attribute("hasUndo")) {
            newTab.hasUndo = EventsParser::ParseBoolean(tabNode->first_attribute("hasUndo")->value());
        }
        newTab.window = new FocusWindow();
        tabs.push_back(newTab);
    }
    altEquipmentBox = G_->GetResources()->GetImageId("upgradeUI/Equipment/equipment_main_2.png");
}

void CustomTabbedWindow::InitialiseButton(CustomTabbedWindow::Tab &tab, Button *newButton) // This may seem uneccessary but restarting the game increment the position of every tab button, so this is to avoid that
{
    newButton->OnInit("upgradeUI/Equipment/tabButtons/right_end", tab.butPos);
    newButton->hitbox = Globals::Rect(tab.butPos.x + 25, 0, 75, 38);
}

void CustomTabbedWindow::PopulateWindow(TabbedWindow* window)
{
    for (auto &tab : tabs)
    {
        bool skip = false;
        for (auto name : window->names)
        {
            if (tab.name == name)
            {
                skip = true;
            }
        }
        if (skip)
            continue;
        Button *newButton = new Button();
        InitialiseButton(tab, newButton);
        window->AddWindow(tab.name, newButton, tab.window);
    }

    if (undoButton == nullptr) undoButton = new TextButton();

    TextString undoText = TextString();

    undoText.isLiteral = false;
    undoText.data = "button_undo";
    undoButton->OnInit(Point(window->position.x + 33, window->position.y + 471), Point(97, 32), 4, &undoText, 63);
    undoButton->SetBaseImage("upgradeUI/buttons_undo_base.png", Point(-23, -7), 97);
}

HOOK_METHOD(CommandGui, LinkShip, (CompleteShip *ship) -> void) // should be linksip when chrono finally find the right sig
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::LinkShip -> Begin (CustomTabbedWindow.cpp)\n")

    super(ship);
    if (CustomTabbedWindow::GetInstance()->enabled) CustomTabbedWindow::GetInstance()->PopulateWindow(&(this->shipScreens));
}

HOOK_METHOD(TabbedWindow, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> TabbedWindow::OnRender -> Begin (CustomTabbedWindow.cpp)\n")

    auto context = G_->getLuaContext();

    lua_pushstring(context->GetLua(), names[currentTab].c_str());

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(position.x, position.y - 7);

    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::TABBED_WINDOW, 1);
    
    if (idx >= 0)
    {
        if (currentTab > 2) // should never be true outside of CustomTabbedWindow being enabled
            G_->GetResources()->RenderImage(CustomTabbedWindow::GetInstance()->GetTab(currentTab).background, 0, 0, 0, COLOR_WHITE, 1.f, false);
        CSurface::GL_Translate(-position.x, -(position.y - 7));
        super();
        
        if (CustomTabbedWindow::GetInstance()->enabled && G_->GetWorld()->commandGui->shipScreens.bOpen)
        {
            for (int i = 0; i < buttons.size(); ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (buttons[i]->primitives[j])
                        buttons[i]->primitives[j]->textureAntialias = true;
                }

                if (i == currentTab && i > 2)
                {
                    bool isLast = i == buttons.size() - 1;
                    std::string buttonBack = isLast ? "upgradeUI/Equipment/tabButtons/select_button_end.png" : "upgradeUI/Equipment/tabButtons/select_button.png";
                    G_->GetResources()->RenderImageString(buttonBack, isLast ? buttons[i]->position.x - 17: buttons[i]->position.x + 2, buttons[i]->position.y, 0, COLOR_WHITE, 1.f, false);
                }
                std::string buttonIcon = "upgradeUI/Equipment/tabButtons/icon_"+names[i]+".png";
                G_->GetResources()->RenderImageString(buttonIcon, i == buttons.size() -1 ? buttons[i]->position.x - 10 : buttons[i]->position.x , buttons[i]->position.y, 0, COLOR_WHITE, 1.f, false);
            }

            if (currentTab > 2 && CustomTabbedWindow::GetInstance()->GetTab(currentTab).hasUndo)
                    CustomTabbedWindow::GetInstance()->undoButton->OnRender();
        }
    }

    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::TABBED_WINDOW, std::abs(idx), 1);

    CSurface::GL_PopMatrix();

    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(TabbedWindow, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> TabbedWindow::MouseMove -> Begin (CustomTabbedWindow.cpp)\n")

    super(x, y);
    if (currentTab > 2 && CustomTabbedWindow::GetInstance()->GetTab(currentTab).hasUndo) // should never be true outside of CustomTabbedWindow being enabled
    {
        CustomTabbedWindow::GetInstance()->undoButton->MouseMove(x, y, false);
    }
}

HOOK_METHOD(CommandGui, LButtonDown, (int mX, int mY, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::LButtonDown -> Begin (CustomTabbedWindow.cpp)\n")

    if (shipScreens.doneButton.bActive && shipScreens.doneButton.bHover)
    {
        auto context = G_->getLuaContext();
        lua_pushstring(context->GetLua(), shipScreens.names[shipScreens.currentTab].c_str());
        context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::TABBED_WINDOW_CONFIRM, 1);
        lua_pop(context->GetLua(), 1);
    }

    if (CustomTabbedWindow::GetInstance()->enabled && CustomTabbedWindow::GetInstance()->undoButton->bActive && CustomTabbedWindow::GetInstance()->undoButton->bHover)
    {
        auto context = G_->getLuaContext();
        lua_pushstring(context->GetLua(), shipScreens.names[shipScreens.currentTab].c_str());
        context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::TABBED_WINDOW_UNDO, 1);
        lua_pop(context->GetLua(), 1);
    }

    super(mX, mY, shiftHeld);
}

HOOK_METHOD(TabbedWindow, Close, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> TabbedWindow::Close -> Begin (CustomTabbedWindow.cpp)\n")
    auto context = G_->getLuaContext();
    lua_pushstring(context->GetLua(), names[currentTab].c_str());
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::TABBED_WINDOW_CONFIRM, 1);
    lua_pop(context->GetLua(), 1);
    super();
}

HOOK_METHOD_PRIORITY(TabbedWindow, SetTab, 1000, (unsigned int tab) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> TabbedWindow::SetTab -> Begin (CustomTabbedWindow.cpp)\n")

    auto context = G_->getLuaContext();
    lua_pushstring(context->GetLua(), names[currentTab].c_str());
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::TABBED_WINDOW_CONFIRM, 1);
    lua_pop(context->GetLua(), 1);

    if (CustomTabbedWindow::GetInstance()->enabled && G_->GetWorld()->commandGui->shipScreens.bOpen)
    {
        switch (currentTab)
        {
        case 0:
            G_->GetWorld()->commandGui->upgradeScreen.Close();
            break;
        
        case 1:
            //CustomCrewManifest::GetInstance()->Update();
            G_->GetWorld()->commandGui->crewScreen.Close();
            break;
        
        case 2:
            G_->GetWorld()->commandGui->equipScreen.Close();
            break;
        
        default:
            windows[currentTab]->Close();
            break;
        }

        switch (tab)
        {
        case 0:
            G_->GetWorld()->commandGui->upgradeScreen.Open();
            break;
        
        case 1:
            G_->GetWorld()->commandGui->crewScreen.Open();
            //CustomCrewManifest::GetInstance()->Update();
            break;
        
        case 2:
            G_->GetWorld()->commandGui->equipScreen.Open();
            break;
        
        default:
            windows[tab]->Open();
            break;
        }
        
        for (int i = 0; i < buttons.size(); ++i)
        {
            if (i == tab) continue;

            std::string imageBase = "upgradeUI/Equipment/tabButtons/";
            if (i == 0)
            {
                imageBase += "left_start";
            }
            else if (i == buttons.size() - 1)
            {
                imageBase += "right_end";
            }
            else if (i > tab)
            {
                imageBase += "right";
            }
            else if (i < tab)
            {
                imageBase += "left";
            }
            
            buttons[i]->SetImageBase(imageBase);

            if (buttons.size() > 3)
            {
                if (i == 2)
                {
                    buttons[i]->position.x = position.x + 182 - 19; // 182
                    buttons[i]->hitbox.x = position.x + 197 - 5; // 197
                    buttons[i]->hitbox.w = 70;
                    G_->GetWorld()->commandGui->equipScreen.box = altEquipmentBox;
                }else if (i == buttons.size() - 1)
                {
                    buttons[i]->position.x = position.x + (buttons.size() - 1) * CustomTabbedWindow::GetInstance()->hitboxWidth + 20 + 8;
                    buttons[i]->hitbox.x = position.x + (buttons.size() - 1) * CustomTabbedWindow::GetInstance()->hitboxWidth + 20 + 10 + 15;
                }
            }
        }
    }
    else
    {
        super(tab);
    }
    currentTab = tab;
}
