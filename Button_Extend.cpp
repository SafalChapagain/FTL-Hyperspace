#include "Button_Extend.h"

Button::~Button()
{
    delete BT_EX(this);
    CSurface::GL_DestroyPrimitive(primitives[0]);
    CSurface::GL_DestroyPrimitive(primitives[1]);
    CSurface::GL_DestroyPrimitive(primitives[2]);
}

HOOK_METHOD_PRIORITY(Button, constructor, 900, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Button::constructor -> Begin (Button_Extend.cpp)\n")
	super();

	auto ex = new Button_Extend();

    uintptr_t dEx = (uintptr_t)ex;

#ifdef __amd64__
    this->gap_ex[3] = (dEx >> 56) & 0xFF;
    this->gap_ex[4] = (dEx >> 48) & 0xFF;
    this->gap_ex[5] = (dEx >> 40) & 0xFF;
    this->gap_ex[6] = (dEx >> 32) & 0xFF;
#endif // __amd64__
	this->gap_ex_gb[0] = (dEx >> 24) & 0xFF;
	this->gap_ex[0] = (dEx >> 16) & 0xFF;
	this->gap_ex[1] = (dEx >> 8) & 0xFF;
	this->gap_ex[2] = dEx & 0xFF;
	ex->orig = this;
}

Button_Extend* Get_Button_Extend(Button* c)
{
    if (!c) return nullptr;

    uintptr_t dEx = 0;

#ifdef __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex[3];
    dEx <<= 8;
    dEx |= c->gap_ex[4];
    dEx <<= 8;
    dEx |= c->gap_ex[5];
    dEx <<= 8;
    dEx |= c->gap_ex[6];
#endif // __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_gb[0];
    dEx <<= 8;
    dEx |= c->gap_ex[0];
    dEx <<= 8;
    dEx |= c->gap_ex[1];
    dEx <<= 8;
    dEx |= c->gap_ex[2];

    return (Button_Extend*)dEx;
}

float g_buttonLotation;
bool g_buttonCustomLotation = false;

HOOK_METHOD(Button, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Button::OnRender -> Begin (Button_Extend.cpp)\n")
    
    auto ex = BT_EX(this);
    if (ex->upward)
    {
        g_buttonLotation = 90.f;
        g_buttonCustomLotation = true;
    }
    else if (ex->downward)
    {
        g_buttonLotation = 270.f;
        g_buttonCustomLotation = true;
    }
    else
    {
       return super();
    }
    super();
    g_buttonCustomLotation = false;
}

HOOK_STATIC(CSurface, GL_CreatePixelImagePrimitive, (GL_Texture *tex, float x, float y, float size_x, float size_y, float rotate, GL_Color color, bool mirrored) -> GL_Primitive*)
{
    LOG_HOOK("HOOK_STATIC -> CSurface::GL_CreatePixelImagePrimitive -> Begin (Button_Extend.cpp)\n")
    
    if (g_buttonCustomLotation)
    {
        rotate = g_buttonLotation;
    }
    return super(tex, x, y, size_x, size_y, rotate, color, mirrored);
}
