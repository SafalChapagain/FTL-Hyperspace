#include "CommandConsole.h"
#include "ShipUnlocks.h"
#include "CustomStore.h"
#include "CustomOptions.h"
#include "CustomEvents.h"
#include "CustomScoreKeeper.h"
#include "CustomSystems.h"
#include "CustomAchievements.h"
#include "CustomShips.h"
#include "CustomSystems.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <string>

CommandConsole CommandConsole::instance = CommandConsole();
PrintHelper PrintHelper::instance = PrintHelper();
bool speedEnabled = true;
static bool squishyTextEnabled = false;
static std::string squishyText = "";
static bool printCenterToLeft = false;
static Point *consolePos = new Point(381, 235);

HOOK_METHOD(MouseControl, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MouseControl::OnRender -> Begin (CommandConsole.cpp)\n")
    if(squishyTextEnabled)
        freetype::easy_printRightAlign(51, 1280.f, 10.f, squishyText.c_str());
    super();
}

bool CommandConsole::RunCommand(CommandGui *commandGui, const std::string& cmd)
{
    hs_log_file("%s\n", cmd.c_str());

    std::string command = cmd;

    std::string cmdName = command.substr(0, command.find(" "));
    boost::to_upper(cmdName);

    if (cmdName == "SQUISHY")
    {
        if (command.length() > 8)
        {
            std::string squishyTitle = boost::trim_copy(command.substr(8));
            hs_log_file("Squishy is awesome\n");
            if(!squishyTitle.empty())
            {
                squishyTextEnabled = true;
                squishyText = squishyTitle;
            }
            return true;
        }
    }
    if (cmdName == "STORE")
    {
        if (command.length() == 5)
        {
            commandGui->CreateNewStore(commandGui->starMap->worldLevel);
        }
        else
        {
            try
            {
                int sector = boost::lexical_cast<int>(boost::trim_copy(command.substr(6)));
                commandGui->CreateNewStore(sector);
            }
            catch (boost::bad_lexical_cast const &e)
            {
                printf("boost::bad_lexical_cast in RunCommand STORE\n");
            }
        }
        return true;
    }
    if (cmdName == "FORCE_STORE")
    {
        if (command.length() > 12)
        {
            std::string storeId = boost::trim_copy(command.substr(12));

            CustomStore::instance->forceCustomStore = storeId;
        }
        return true;
    }
    if (cmdName == "EXIT")
    {
        commandGui->starMap->bOpen = true;
        commandGui->starMap->bChoosingNewSector = true;
    }
    if (cmdName == "KILL" && command.length() > 5)
    {
        std::string crewName = boost::trim_copy(command.substr(5));

        for (auto i : commandGui->shipComplete->shipManager->vCrewList)
        {
            if (i->blueprint.crewName.data == crewName)
            {
                i->health.first = 0;
                break;
            }
        }
        return true;
    }
    if (cmdName == "SKILL")
    {
        for (auto i : G_->GetCrewFactory()->crewMembers)
        {
            if (i->iShipId == 0)
            { 
                for (int skill = 0; skill<6; skill++)
                {
                    i->MasterSkill(skill);
                }
            }
        }
        G_->GetSoundControl()->PlaySoundMix("levelup", -1.f, false);
    }
    if (cmdName == "DELETECREW" || cmdName == "COOLSWORDBRO")
    {
        if (commandGui->shipComplete->shipManager->current_target)
        {
            for (auto i : commandGui->shipComplete->shipManager->current_target->vCrewList)
            {
                i->health.first = 0;
            }
        }
        return true;
    }
    if (cmdName == "SPEED" && command.length() > 5)
    {
        // TODO: In the future we could force vsync off by calling `graphics_set_display_attr("vsync", 0);`
        try
        {
            int speedFactor = boost::lexical_cast<int>(boost::trim_copy(command.substr(6)));
            G_->GetCFPS()->speedLevel = speedFactor;
        }
        catch (boost::bad_lexical_cast const &e)
        {
            printf("boost::bad_lexical_cast in RunCommand SPEED\n");
        }

        return true;
    }
    if (cmdName == "LUA" && command.length() > 3)
    {
        std::string luaCode = boost::trim_copy(command.substr(4));
        Global::GetInstance()->getLuaContext()->runLuaString(luaCode);
    }
    if (boost::to_upper_copy(command) == "SYS ALL")
    {
        ShipManager *ship = commandGui->shipComplete->shipManager;
        
        //Vanilla Systems
        for (int systemId = 0; systemId < 16; ++systemId) 
        {
            if (!ship->HasSystem(systemId) && ship->SystemWillReplace(systemId) == SYS_INVALID)
            {
                ship->AddSystem(systemId);
            } 
        }

        //Temporal system
        if (!ship->HasSystem(SYS_TEMPORAL) && ship->SystemWillReplace(SYS_TEMPORAL) == SYS_INVALID)
        {
            ship->AddSystem(SYS_TEMPORAL);
        }
        
        //Custom systems
        for (int systemId = SYS_CUSTOM_FIRST; systemId <= CustomUserSystems::GetLastSystemId(); ++systemId)
        {
            if (!ship->HasSystem(systemId) && ship->SystemWillReplace(systemId) == SYS_INVALID)
            {
                ship->AddSystem(systemId);
            } 
        }
        return true;
    }
    if (cmdName == "DAMAGESYS" && command.length() > 9)
    {
        ShipSystem* sys = commandGui->shipComplete->shipManager->GetSystem(ShipSystem::NameToSystemId(boost::trim_copy(command.substr(10))));

        if (sys)
        {
            sys->healthState.first = 0;
        }

        return true;
    }
    if (cmdName == "REMOVESYS" && command.length() > 9)
    {
        commandGui->shipComplete->shipManager->RemoveSystem(ShipSystem::NameToSystemId(boost::trim_copy(command.substr(10))));
        
        return true;
    }
    if (cmdName == "DEBUG")
    {
        return true;
    }
    if (command == "SHIP ALL")
    {
        CustomShipUnlocks::instance->UnlockAllShips();
        return false; //Run native game ship unlocks as well
    }
    if (cmdName == "SHIP_CUSTOM")
    {
        std::string shipName = boost::trim_copy(command.substr(11));

        if (CustomShipUnlocks::instance->CustomShipHasUnlock(shipName))
        {
            CustomShipUnlocks::instance->UnlockShip(shipName, false, true, false);
        }
        return true;
    }
    if (cmdName == "SHIP_CUSTOM_LOCK")
    {
        std::string shipName = boost::trim_copy(command.substr(16));

        CustomShipUnlocks::instance->RemoveShipUnlock(shipName);

        return true;
    }
    if(cmdName == "RICH")
    {
        commandGui->shipComplete->shipManager->ModifyScrapCount(9999999 , false);
        commandGui->shipComplete->shipManager->ModifyMissileCount(800);
        commandGui->shipComplete->shipManager->fuel_count += 800;
        commandGui->shipComplete->shipManager->ModifyDroneCount(800);
        return true;
    }
    if(cmdName == "POOR")
    {
        commandGui->shipComplete->shipManager->ModifyScrapCount(-9999999 , false);
        commandGui->shipComplete->shipManager->ModifyMissileCount(-800);
        commandGui->shipComplete->shipManager->fuel_count -= 800;
        if (commandGui->shipComplete->shipManager->fuel_count < 0) commandGui->shipComplete->shipManager->fuel_count = 0;
        commandGui->shipComplete->shipManager->ModifyDroneCount(-800);
        return true;
    }
    /*
    if(cmdName == "JUMPEVENT")
    {
        if (command.length() > 10)
        {
            jumpEvent = boost::trim_copy(command.substr(10));
        }
        else
        {
            jumpEvent = "";
        }
        jumpEventLoop = false;
        return true;
    }
    */
    if(cmdName == "LOADEVENT")
    {
        if (command.length() > 10)
        {
            std::string eventName = boost::trim_copy(command.substr(10));
            CustomEventsParser::GetInstance()->LoadEvent(G_->GetWorld(), eventName, false, -1);
        }
        return true;
    }
    if (cmdName == "CREDITS" || cmdName == "VICTORY")
    {
        G_->GetWorld()->commandGui->Victory();
        return true;
    }
    if(cmdName == "VARIABLE" || cmdName == "VAR")
    {
        std::vector<std::string> cmdList = std::vector<std::string>();
        boost::split(cmdList, cmd, boost::is_any_of(" "), boost::token_compress_on);
        if (cmdList.size() >= 2)
        {
            std::string varName = cmdList[1];
            if (cmdList.size() >= 3)
            {
                try
                {
                    int v = boost::lexical_cast<int>(boost::trim_copy(cmdList[2]));
                    playerVariables[varName] = v;
                }
                catch (boost::bad_lexical_cast const &e)
                {
                    printf("boost::bad_lexical_cast in RunCommand %s\n", cmdName.c_str());
                }
            }
            hs_log_file("Variable %s = %d\n", varName.c_str(), playerVariables[varName]);
        }
        return true;
    }
    if(cmdName == "METAVARIABLE" || cmdName == "METAVAR" || cmdName == "MVAR")
    {
        std::vector<std::string> cmdList = std::vector<std::string>();
        boost::split(cmdList, cmd, boost::is_any_of(" "), boost::token_compress_on);
        if (cmdList.size() >= 2)
        {
            std::string varName = cmdList[1];
            if (cmdList.size() >= 3)
            {
                try
                {
                    int v = boost::lexical_cast<int>(boost::trim_copy(cmdList[2]));
                    metaVariables[varName] = v;
                }
                catch (boost::bad_lexical_cast const &e)
                {
                    printf("boost::bad_lexical_cast in RunCommand %s\n", cmdName.c_str());
                }
            }
            hs_log_file("Metavariable %s = %d\n", varName.c_str(), metaVariables[varName]);
        }
        return true;
    }
    if(cmdName == "ACH" && command.length() > 3)
    {
        std::string achName = boost::trim_copy(command.substr(4));
        CustomAchievementTracker::instance->SetAchievement(achName, false);

        return true;
    }
    if(cmdName == "ACH_LOCK" && command.length() > 8)
    {
        std::string achName = boost::trim_copy(command.substr(9));
        CustomAchievementTracker *customAchTrack = CustomAchievementTracker::instance;
        customAchTrack->RemoveAchievement(achName);

        return true;
    }
    if(cmdName == "SWITCHALL" && command.length() > 9)
    {
        std::string shipName = boost::trim_copy(command.substr(10));
        hs_log_file("Loading new ship and transfering from old ship %s\n", shipName.c_str());
        G_->GetWorld()->SwitchShipTransfer(shipName, 1);

        return true;
    }
    if(cmdName == "SWITCH" && command.length() > 6)
    {
        std::string shipName = boost::trim_copy(command.substr(7));
        hs_log_file("Loading new ship %s\n", shipName.c_str());
        G_->GetWorld()->SwitchShip(shipName);

        return true;
    }
    if(cmdName == "WEAPON" && command.length() > 6)
    {
        std::string weaponName = boost::trim_copy(command.substr(7));
        WeaponBlueprint *weapon = G_->GetBlueprints()->GetWeaponBlueprint(weaponName);
        if (weapon && weapon->type != -1)
        {
            commandGui->equipScreen.AddWeapon(weapon, true, false);
        }

        return true;
    }

    return false;
}

//===============================================

static AnimationTracker *g_consoleMessage;
static bool shouldOpenConsole = true;

HOOK_METHOD(CommandGui, KeyDown, (SDLKey key, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::KeyDown -> Begin (CommandConsole.cpp)\n")

    CommandConsole *console = CommandConsole::GetInstance();
    if (key == Settings::GetHotkey("speed"))
    {
        speedEnabled = !speedEnabled;
    }

    auto custom = CustomOptionsManager::GetInstance();
    if (key == Settings::GetHotkey("info"))
    {
        custom->altMode = !custom->altMode;
        custom->altModeChanged = true;
        G_->GetSoundControl()->PlaySoundMix(custom->altMode ? "moreInfoOn" : "moreInfoOff", -1.f, false);
    }

    if (console->enabled && key == Settings::GetHotkey("console"))
    {
        if (!writeErrorDialog.bOpen &&
            !menuBox.bOpen &&
            !gameOverScreen.bOpen &&
            !shipComplete->shipManager->bJumping &&
            !inputBox.bOpen &&
            key != Settings::GetHotkey("options"))
        {
            bool shouldCheckConsoleKey = true;

            for (auto i : focusWindows)
            {
                if (i->bOpen)
                {
                    shouldCheckConsoleKey = false;
                    break;
                }
            }

            if (shouldCheckConsoleKey)
            {
                inputBox.StartInput();
            }
        }
    }

    shouldOpenConsole = false;
    super(key, shiftHeld);
    shouldOpenConsole = true;

    if (console->enabled && inputBox.bOpen && key == SDLK_UP)
    {
        console->textInput->SetText(inputBox.inputText);
        console->textInput->pos = console->textInput->text.size();
    }

}

HOOK_STATIC(Settings, GetCommandConsole, () -> char)
{
    LOG_HOOK("HOOK_STATIC -> Settings::GetCommandConsole -> Begin (CommandConsole.cpp)\n")
    return shouldOpenConsole && CommandConsole::GetInstance()->enabled; //&& CommandConsole::GetInstance()->shouldOpen;
}

HOOK_METHOD(CommandGui, RunCommand, (std::string& command) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::RunCommand -> Begin (CommandConsole.cpp)\n")
    if (!CommandConsole::GetInstance()->RunCommand(this, command))
    {
        super(command);

        // This is here instead of in CommandConsole::RunCommand because CommandGui has shipComplete
        if(command == "GOD")
            PowerManager::GetPowerManager(0)->currentPower.second = CustomShipSelect::GetInstance()->GetDefinition(shipComplete->shipManager->myBlueprint.blueprintName).maxReactorLevel;
    }
}

HOOK_METHOD(CFPS, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CFPS::OnLoop -> Begin (CommandConsole.cpp)\n")
    int oldSpeedLevel = speedLevel;

    if (!speedEnabled)
    {
        speedLevel = 0;
    }

    super();

    speedLevel = oldSpeedLevel;
}

void PrintHelper::Render()
{
    if (messages.size() > 0)
    {
        if (timer <= duration)
        {
            std::string screenMessage = std::string();
            //Maybe change to just translate each message by the height of the previous one, but the Pointf.y value doesn't seem to be useful for that.
            for (const auto& message : messages)
            {
                screenMessage += message;
                screenMessage += "\n";
            }
            CSurface::GL_SetColor(COLOR_WHITE);
            freetype::easy_printAutoNewlines(font, x, y, lineLength, screenMessage);
            float increment = useSpeed ? G_->GetCFPS()->GetSpeedFactor() * 0.0625 : 1.0 / G_->GetCFPS()->NumFrames;
            timer += increment;
        }
        else
        {
            timer = 0;
            messages.pop_front();
        }
    }  
}

void PrintHelper::AddMessage(const std::string message)
{

    timer = 0;
    messages.push_back(message);
    if (messages.size() > messageLimit)
    {
        messages.pop_front();
    }
}

HOOK_METHOD(MouseControl, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MouseControl::OnRender -> Begin (CommandConsole.cpp)\n")
    PrintHelper::GetInstance()->Render();
    super();
}

//===============================================

HOOK_METHOD(InputBox, StartInput, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> InputBox::StartInput -> Begin (CommandConsole.cpp)\n")

    CommandConsole *console = CommandConsole::GetInstance();
    if (!(console->textInput))
    {
        console->textInput = new struct TextInput(480, TextInput::ALLOW_ANY, "");
    }
    console->textInput->Start();
    console->textInput->SetText("");
    console->textInput->pos = 0;
    super();
}

HOOK_METHOD(InputBox, TextEvent, (CEvent::TextEvent event) -> void)
{
    LOG_HOOK("HOOK_METHOD -> InputBox::TextEvent -> Begin (CommandConsole.cpp)\n")

    CommandConsole *console = CommandConsole::GetInstance();
    if (console->textInput)
    {
        console->textInput->OnTextEvent(event);
        inputText = console->textInput->GetText();

        if (event == CEvent::TEXT_CONFIRM || event == CEvent::TEXT_CANCEL)
        {
            console->textInput->Stop();
            super(event);
        }
    }
}

HOOK_METHOD(InputBox, TextInput, (int ch) -> void)
{
    LOG_HOOK("HOOK_METHOD -> InputBox::TextInput -> Begin (CommandConsole.cpp)\n")

    CommandConsole *console = CommandConsole::GetInstance();
    if (console->textInput)
    {
        if (console->invertCaps)
        {
            if (ch >= 'a' && ch <= 'z')
            {
                ch -= 32;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                ch += 32;
            }
        }
        console->textInput->OnTextInput(ch);
        inputText = console->textInput->GetText();
    }
}

HOOK_METHOD(InputBox, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> InputBox::OnRender -> Begin (CommandConsole.cpp)\n")
        
    if (bOpen == false) return;

    textBox->Draw(consolePos->x - 25, consolePos->y - 25);

    freetype::easy_printAutoNewlines(8, (float)consolePos->x, (float)consolePos->y, 490, mainText);

    CommandConsole *console = CommandConsole::GetInstance();
    if (console->textInput)
    {
        CSurface::GL_SetColor(COLOR_WHITE);
        printCenterToLeft = true;
        console->textInput->OnRender(8, Point(consolePos->x, consolePos->y + 20));
        printCenterToLeft = false;
        console->textInput->OnLoop();
    }
}

HOOK_STATIC(CSurface, GL_DrawRect, (float x, float y, float w, float h, GL_Color color) -> bool)
{
    LOG_HOOK("HOOK_STATIC -> CSurface::GL_DrawRect -> Begin (CommandConsole.cpp)\n")
        
    if (printCenterToLeft)
        return super(x + 2, y, 1.0, h, color);

    return super(x, y, w, h, color);
}

HOOK_STATIC(freetype, easy_printCenter , (int fontSize, float x, float y, const std::string &text) -> Pointf)
{
    if (printCenterToLeft)
    {
        freetype::easy_print(8, x, y, text);
        return Pointf(x, y);
    }

    return super(fontSize, x, y, text);
}
