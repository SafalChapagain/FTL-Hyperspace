#include "CustomHotkeys.h"
#include <boost/lexical_cast.hpp>
std::vector<CustomHotkey> CustomHotkeyManager::customHotkeys =
{
    {"weapon1", SDLKey::SDLK_1, 1, 8},
    {"weapon2", SDLKey::SDLK_2, 1, 9},
    {"weapon3", SDLKey::SDLK_3, 1, 10},
    {"weapon4", SDLKey::SDLK_4, 1, 11},
    {"drone4", SDLKey::SDLK_8, 1, 15},
    {"drone5", SDLKey::SDLK_9, 1, 16},
    {"drone6", SDLKey::SDLK_0, 1, 17},
    {"console", SDLKey::SDLK_BACKSLASH, 0, -1},
    {"speed", SDLKey::SDLK_BACKQUOTE, 0, -1},
    {"info", SDLKey::SDLK_RALT, 0, 11},
    {"temporal", SDLKey::SDLK_SEMICOLON, 2, 11},
    {"un_temporal", SDLKey::SDLK_UNKNOWN, 2, -1},
    {"temporal_speed", SDLKey::SDLK_PERIOD, 1, 8},
    {"temporal_slow", SDLKey::SDLK_COMMA, 1, 9}
};

bool CustomHotkeyManager::IsDuplicateHotkey(const std::string& hotkeyName)
{
    //Check native hotkeys for duplicate registration
    const auto& hotkeys = Global::GetInstance()->GetSettings()->hotkeys;
    for (const auto& descVector : hotkeys)
    {
        for (const auto& desc : descVector)
        {
            if (hotkeyName == desc.name)
            {
                return true;
            }
        }
    }
    //Check custom hotkeys for duplicate registration
    for (const auto& customHotkey : customHotkeys)
    {
        if (hotkeyName == customHotkey.hotkeyName)
        {
            return true;
        }
    }
    return false;
}
//TODO: Find neater way to do this (Find way to reverse GetHotkeyName?)
SDLKey CustomHotkeyManager::StringToKey(const std::string& keyName)
{
    if (keyName == "0") return SDLK_0;
    else if (keyName == "1") return SDLK_1;
    else if (keyName == "2") return SDLK_2;
    else if (keyName == "3") return SDLK_3;
    else if (keyName == "4") return SDLK_4;
    else if (keyName == "5") return SDLK_5;
    else if (keyName == "6") return SDLK_6;
    else if (keyName == "7") return SDLK_7;
    else if (keyName == "8") return SDLK_8;
    else if (keyName == "9") return SDLK_9;
    else if (keyName == "AT") return SDLK_AT;
    else if (keyName == "AMPERSAND") return SDLK_AMPERSAND;
    else if (keyName == "ASTERISK") return SDLK_ASTERISK;
    else if (keyName == "BACKQUOTE") return SDLK_BACKQUOTE;
    else if (keyName == "BACKSLASH") return SDLK_BACKSLASH;
    else if (keyName == "BACKSPACE") return SDLK_BACKSPACE;
    else if (keyName == "BREAK") return SDLK_BREAK;
    else if (keyName == "CAPSLOCK") return SDLK_CAPSLOCK;
    else if (keyName == "CARET") return SDLK_CARET;
    else if (keyName == "CLEAR") return SDLK_CLEAR;
    else if (keyName == "COLON") return SDLK_COLON;
    else if (keyName == "COMMA") return SDLK_COMMA;
    else if (keyName == "COMPOSE") return SDLK_COMPOSE;
    else if (keyName == "DELETE") return SDLK_DELETE;
    else if (keyName == "DOLLAR") return SDLK_DOLLAR;
    else if (keyName == "DOWN") return SDLK_DOWN;
    else if (keyName == "END") return SDLK_END;
    else if (keyName == "EQUALS") return SDLK_EQUALS;
    else if (keyName == "ESCAPE") return SDLK_ESCAPE;
    else if (keyName == "EURO") return SDLK_EURO;
    else if (keyName == "EXCLAIM") return SDLK_EXCLAIM;
    else if (keyName == "F1") return SDLK_F1;
    else if (keyName == "F10") return SDLK_F10;
    else if (keyName == "F11") return SDLK_F11;
    else if (keyName == "F12") return SDLK_F12;
    else if (keyName == "F13") return SDLK_F13;
    else if (keyName == "F14") return SDLK_F14;
    else if (keyName == "F15") return SDLK_F15;
    else if (keyName == "F2") return SDLK_F2;
    else if (keyName == "F3") return SDLK_F3;
    else if (keyName == "F4") return SDLK_F4;
    else if (keyName == "F5") return SDLK_F5;
    else if (keyName == "F6") return SDLK_F6;
    else if (keyName == "F7") return SDLK_F7;
    else if (keyName == "F8") return SDLK_F8;
    else if (keyName == "F9") return SDLK_F9;
    else if (keyName == "GREATER") return SDLK_GREATER;
    else if (keyName == "HASH") return SDLK_HASH;
    else if (keyName == "HELP") return SDLK_HELP;
    else if (keyName == "HOME") return SDLK_HOME;
    else if (keyName == "INSERT") return SDLK_INSERT;
    else if (keyName == "KP0") return SDLK_KP0;
    else if (keyName == "KP1") return SDLK_KP1;
    else if (keyName == "KP2") return SDLK_KP2;
    else if (keyName == "KP3") return SDLK_KP3;
    else if (keyName == "KP4") return SDLK_KP4;
    else if (keyName == "KP5") return SDLK_KP5;
    else if (keyName == "KP6") return SDLK_KP6;
    else if (keyName == "KP7") return SDLK_KP7;
    else if (keyName == "KP8") return SDLK_KP8;
    else if (keyName == "KP9") return SDLK_KP9;
    else if (keyName == "KP_PERIOD") return SDLK_KP_PERIOD;
    else if (keyName == "KP_DIVIDE") return SDLK_KP_DIVIDE;
    else if (keyName == "KP_MULTIPLY") return SDLK_KP_MULTIPLY;
    else if (keyName == "KP_MINUS") return SDLK_KP_MINUS;
    else if (keyName == "KP_PLUS") return SDLK_KP_PLUS;
    else if (keyName == "KP_ENTER") return SDLK_KP_ENTER;
    else if (keyName == "KP_EQUALS") return SDLK_KP_EQUALS;
    else if (keyName == "LALT") return SDLK_LALT;
    else if (keyName == "LCTRL") return SDLK_LCTRL;
    else if (keyName == "LEFT") return SDLK_LEFT;
    else if (keyName == "LEFTBRACKET") return SDLK_LEFTBRACKET;
    else if (keyName == "LEFTPAREN") return SDLK_LEFTPAREN;
    else if (keyName == "LESS") return SDLK_LESS;
    else if (keyName == "LMETA") return SDLK_LMETA;
    else if (keyName == "LSHIFT") return SDLK_LSHIFT;
    else if (keyName == "LSUPER") return SDLK_LSUPER;
    else if (keyName == "MENU") return SDLK_MENU;
    else if (keyName == "MINUS") return SDLK_MINUS;
    else if (keyName == "MODE") return SDLK_MODE;
    else if (keyName == "NUMLOCK") return SDLK_NUMLOCK;
    else if (keyName == "PAGEDOWN") return SDLK_PAGEDOWN;
    else if (keyName == "PAGEUP") return SDLK_PAGEUP;
    else if (keyName == "PAUSE") return SDLK_PAUSE;
    else if (keyName == "PERIOD") return SDLK_PERIOD;
    else if (keyName == "PLUS") return SDLK_PLUS;
    else if (keyName == "POWER") return SDLK_POWER;
    else if (keyName == "PRINTSCREEN") return SDLK_PRINTSCREEN;
    else if (keyName == "QUESTION") return SDLK_QUESTION;
    else if (keyName == "QUOTEDBL") return SDLK_QUOTEDBL;
    else if (keyName == "QUOTE") return SDLK_QUOTE;
    else if (keyName == "RALT") return SDLK_RALT;
    else if (keyName == "RCTRL") return SDLK_RCTRL;
    else if (keyName == "RETURN") return SDLK_RETURN;
    else if (keyName == "RIGHT") return SDLK_RIGHT;
    else if (keyName == "RIGHTBRACKET") return SDLK_RIGHTBRACKET;
    else if (keyName == "RIGHTPAREN") return SDLK_RIGHTPAREN;
    else if (keyName == "RMETA") return SDLK_RMETA;
    else if (keyName == "RSHIFT") return SDLK_RSHIFT;
    else if (keyName == "RSUPER") return SDLK_RSUPER;
    else if (keyName == "SCROLLOCK") return SDLK_SCROLLOCK;
    else if (keyName == "SEMICOLON") return SDLK_SEMICOLON;
    else if (keyName == "SLASH") return SDLK_SLASH;
    else if (keyName == "SPACE") return SDLK_SPACE;
    else if (keyName == "SYSREQ") return SDLK_SYSREQ;
    else if (keyName == "TAB") return SDLK_TAB;
    else if (keyName == "UNDERSCORE") return SDLK_UNDERSCORE;
    else if (keyName == "UNDO") return SDLK_UNDO;
    else if (keyName == "UP") return SDLK_UP;
    else if (keyName == "a") return SDLK_a;
    else if (keyName == "b") return SDLK_b;
    else if (keyName == "c") return SDLK_c;
    else if (keyName == "d") return SDLK_d;
    else if (keyName == "e") return SDLK_e;
    else if (keyName == "f") return SDLK_f;
    else if (keyName == "g") return SDLK_g;
    else if (keyName == "h") return SDLK_h;
    else if (keyName == "i") return SDLK_i;
    else if (keyName == "j") return SDLK_j;
    else if (keyName == "k") return SDLK_k;
    else if (keyName == "l") return SDLK_l;
    else if (keyName == "m") return SDLK_m;
    else if (keyName == "n") return SDLK_n;
    else if (keyName == "o") return SDLK_o;
    else if (keyName == "p") return SDLK_p;
    else if (keyName == "q") return SDLK_q;
    else if (keyName == "r") return SDLK_r;
    else if (keyName == "s") return SDLK_s;
    else if (keyName == "t") return SDLK_t;
    else if (keyName == "u") return SDLK_u;
    else if (keyName == "v") return SDLK_v;
    else if (keyName == "w") return SDLK_w;
    else if (keyName == "x") return SDLK_x;
    else if (keyName == "y") return SDLK_y;
    else if (keyName == "z") return SDLK_z;
    else throw std::runtime_error("Invalid hotkey: " + keyName);
}
void CustomHotkeyManager::ParseCustomHotkeyNode(rapidxml::xml_node<char>* node)
{
    for (auto hotkeyNode = node->first_node(); hotkeyNode; hotkeyNode = hotkeyNode->next_sibling())
    {
        //TODO: Use rapidxml errors to include line numbers?
        if (!hotkeyNode->first_attribute("name")) throw std::runtime_error("Hotkey missing name attribute!");
        if (!hotkeyNode->first_attribute("page")) throw std::runtime_error("Hotkey missing page attribute!");

        int page = boost::lexical_cast<int>(hotkeyNode->first_attribute("page")->value());
        if (page < 0 || page > 3) throw std::runtime_error("Hotkey is registered to page: " + std::to_string(page) + ", only pages 0-3 are valid!");

        std::string hotkeyName = hotkeyNode->first_attribute("name")->value();
        if (IsDuplicateHotkey(hotkeyName)) throw std::runtime_error("Attempted to register hotkey under name: " + hotkeyName + " while this name is already in use!");

        SDLKey defaultKey = hotkeyNode->first_attribute("default") ? StringToKey(hotkeyNode->first_attribute("default")->value()) : SDLK_UNKNOWN;
        int position = hotkeyNode->first_attribute("position") ? boost::lexical_cast<int>(hotkeyNode->first_attribute("position")->value()) : -1;
        
        CustomHotkey newKey{hotkeyName, defaultKey, page, position};
        customHotkeys.push_back(newKey);
    }
    Settings::RegenerateHotkeys();
}

HOOK_METHOD(ControlsScreen, OnInit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ControlsScreen::OnInit -> Begin (CustomHotkeys.cpp)\n")
    for (int i = 0; i < 4; i++)
    {
        buttons[i].clear();
    }

    super();

    Point origin = Point(480, 130);
    int btnsPerColumn = 8;
    for (int page = 0; page < 3; page++)
    {
        if (page == 0)
        {
            btnsPerColumn = 12;
        }
        else if (page == 1)
        {
            btnsPerColumn = 10;
        }
        else if (page == 2)
        {
            btnsPerColumn = 12;
        }

        for (int i = 0; i < buttons[page].size(); i++)
        {
            auto& button = buttons[page][i];

            button.rect.x = origin.x + ((i >= btnsPerColumn) ? 440 : 0);
            button.rect.y = origin.y + (40 * (i >= btnsPerColumn ? i - btnsPerColumn : i));
        }

    }
}

void Settings::RegenerateHotkeys()
{
    SettingValues* settings = G_->GetSettings();

    for (auto i : CustomHotkeyManager::customHotkeys)
    {
        HotkeyDesc hk = HotkeyDesc();
        hk.name = i.hotkeyName;
        hk.key = i.defaultValue;

        for (auto it = settings->hotkeys[i.page].begin(); it != settings->hotkeys[i.page].end(); ++it)
        {
            if (it->name == i.hotkeyName)
            {
                hk = *it;
                settings->hotkeys[i.page].erase(it);
                break;
            }
        }

        if (i.index == -1)
        {
            settings->hotkeys[i.page].push_back(hk);
        }
        else
        {
            settings->hotkeys[i.page].insert(settings->hotkeys[i.page].begin() + i.index, hk);
        }
    }
}

HOOK_STATIC(Settings, ResetHotkeys, () -> void)
{
    LOG_HOOK("HOOK_STATIC -> Settings::ResetHotkeys -> Begin (CustomHotkeys.cpp)\n")
    super();

    RegenerateHotkeys();
}
