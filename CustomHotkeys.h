#include "Global.h"
#include <vector>

struct CustomHotkey
{
    std::string hotkeyName;
    SDLKey defaultValue;
    int page;
    int index; // -1
};
struct CustomHotkeyManager
{
    static void ParseCustomHotkeyNode(rapidxml::xml_node<char>* node);
    static std::vector<CustomHotkey> customHotkeys;
private:
    static bool IsDuplicateHotkey(const std::string& hotkeyName);
    static SDLKey StringToKey(const std::string& keyName);
};

