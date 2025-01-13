#pragma once
#include "Global.h"

extern GL_Color g_defaultTextButtonColors[4];
extern GL_Color g_autofireButtonColors[4];
extern GL_Color g_jumpButtonColors[8];

void ParseCustomColorsNode(rapidxml::xml_node<char>* node);


void ParseChoiceColorsNode(rapidxml::xml_node<char>* node);
