#include "Global.h"

struct ScrollingTooltip
{
    static bool OnScrollWheel(float direction);
    
    static GL_Primitive *scrollUpArrow;
    static GL_Primitive *scrollDownArrow;
    static std::string tooltip;
    static float scrollAmount;
    static float maxScroll;
};
