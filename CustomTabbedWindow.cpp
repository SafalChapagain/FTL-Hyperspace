#include "CustomTabbedWindow.h"
#include "CustomCrewManifest.h"

CustomTabbedWindow CustomTabbedWindow::instance = CustomTabbedWindow();
GL_Texture* altEquipmentBox = nullptr;

void CustomTabbedWindow::ParseWindowNode(rapidxml::xml_node<char>* node)
{
    for (rapidxml::xml_node<char>* tabNode = node->first_node("tab"); tabNode; tabNode = tabNode->next_sibling("tab")) 
    {
        Tab newTab;

        newTab.button = new Button();
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
            newTab.hasUndo = tabNode->first_attribute("hasUndo")->value();
        }
        newTab.window = new FocusWindow();
        tabs.push_back(newTab);
    }
    altEquipmentBox = G_->GetResources()->GetImageId("upgradeUI/Equipment/equipment_main_2.png");
}

void CustomTabbedWindow::InitialiseButton(CustomTabbedWindow::Tab tab) // This may seem uneccessary but restarting the game increment the position of every tab button, so this is to avoid that
{
    tab.button->OnInit("upgradeUI/Equipment/tabButtons/right_end", tab.butPos);
    Globals::Rect rect = Globals::Rect();
    rect.x = tab.butPos.x + 25;
    rect.y = 0;
    rect.w = 75;
    rect.h = 38;
    tab.button->hitbox = rect;
}

void CustomTabbedWindow::PopulateWindow(TabbedWindow* window)
{
    for (auto tab : tabs)
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
        InitialiseButton(tab);
        window->AddWindow(tab.name, tab.button, tab.window);
    }

    if (undoButton == nullptr) undoButton = new TextButton();

    TextString undoText = TextString();

    undoText.isLiteral = false;
    undoText.data = "button_undo";
    undoButton->OnInit(Point(335 + 33, 85 + 471), Point(97, 32), 4, &undoText, 63);
    undoButton->SetBaseImage("upgradeUI/buttons_undo_base.png", Point(-23, -7), 97);
}

HOOK_METHOD(CommandGui, LinkShip, (CompleteShip *ship) -> void) // should be linksip when chrono finally find the right sig
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::LinkShip -> Begin (CustomTabbedWindow.cpp)\n")

    super(ship);
    CustomTabbedWindow::GetInstance()->PopulateWindow(&(this->shipScreens));
}

HOOK_METHOD(TabbedWindow, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> TabbedWindow::OnRender -> Begin (CustomTabbedWindow.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), currentTab);

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(335, 78);

    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::TABBED_WINDOW, 1);
    
    if (idx >= 0)
    {
        CSurface::GL_Translate(-335, -78);
        super();
        for (int i = 0; i < buttons.size(); ++i)
        {   
            if (i == currentTab) continue;
            std::string buttonIcon = "upgradeUI/Equipment/tabButtons/icon_"+names[i]+".png";
            G_->GetResources()->RenderImageString(buttonIcon, i == buttons.size() -1 ? buttons[i]->position.x - 10 : buttons[i]->position.x , buttons[i]->position.y, 0, COLOR_WHITE, 1.f, false);
        }

        if (currentTab > 2 && CustomTabbedWindow::GetInstance()->GetTab(currentTab).hasUndo)
            CustomTabbedWindow::GetInstance()->undoButton->OnRender();
            
        CSurface::GL_Translate(335, 78);
        if (currentTab > 2)
            G_->GetResources()->RenderImage(CustomTabbedWindow::GetInstance()->GetTab(currentTab).background, 0, 0, 0, COLOR_WHITE, 1.f, false);
    }

    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::TABBED_WINDOW, std::abs(idx), 1);

    CSurface::GL_PopMatrix();

    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(TabbedWindow, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> TabbedWindow::MouseMove -> Begin (CustomTabbedWindow.cpp)\n")

    super(x, y);
    if (currentTab > 2 && CustomTabbedWindow::GetInstance()->GetTab(currentTab).hasUndo)
    {
        CustomTabbedWindow::GetInstance()->undoButton->MouseMove(x, y, false);
    }
}

HOOK_METHOD(CommandGui, LButtonDown, (int mX, int mY, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::LButtonDown -> Begin (CustomTabbedWindow.cpp)\n")

    if (shipScreens.doneButton.bActive && shipScreens.doneButton.bHover)
    {
        auto context = Global::GetInstance()->getLuaContext();
        lua_pushinteger(context->GetLua(), shipScreens.currentTab);
        context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::TABBED_WINDOW_CONFIRM, 1);
        lua_pop(context->GetLua(), 1);
    }

    if (CustomTabbedWindow::GetInstance()->undoButton->bActive && CustomTabbedWindow::GetInstance()->undoButton->bHover)
    {
        auto context = Global::GetInstance()->getLuaContext();
        lua_pushinteger(context->GetLua(), shipScreens.currentTab);
        context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::TABBED_WINDOW_UNDO, 1);
        lua_pop(context->GetLua(), 1);
    }

    super(mX, mY, shiftHeld);
}

HOOK_METHOD(TabbedWindow, Close, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> TabbedWindow::Close -> Begin (CustomTabbedWindow.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();
    lua_pushinteger(context->GetLua(), currentTab);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::TABBED_WINDOW_CONFIRM, 1);
    lua_pop(context->GetLua(), 1);
    super();
}

HOOK_METHOD(TabbedWindow, SetTab, (unsigned int tab) -> void)
{
    LOG_HOOK("HOOK_METHOD -> TabbedWindow::SetTab -> Begin (CustomTabbedWindow.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();
    lua_pushinteger(context->GetLua(), currentTab);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::TABBED_WINDOW_CONFIRM, 1);
    lua_pop(context->GetLua(), 1);

    windows[currentTab]->Close();
    windows[tab]->Open();
    if (tab == 1)
        CustomCrewManifest::GetInstance()->Update();
    
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
                buttons[i]->position.x = 335 + 182 - 19; // 182
                buttons[i]->hitbox.x = 335 + 197 - 5; // 197
                buttons[i]->hitbox.w = 70;
                G_->GetWorld()->commandGui->equipScreen.box = altEquipmentBox;
            }else if (i == buttons.size() - 1)
            {
                buttons[i]->position.x = 335 + (buttons.size() - 1) * CustomTabbedWindow::GetInstance()->hitboxWidth + 20 + 8;
                buttons[i]->hitbox.x = 335 + (buttons.size() - 1) * CustomTabbedWindow::GetInstance()->hitboxWidth + 20 + 10 + 15;
            }
        }
    }
    currentTab = tab;
}
