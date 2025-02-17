#pragma once
#include "FTLGame.h"

struct Button_Extend
{
    Button *orig = nullptr;

    ~Button_Extend()
    {
    }

    bool upward = false;
    bool downward = false;
};

Button_Extend* Get_Button_Extend(Button* c);

#define BT_EX Get_Button_Extend
