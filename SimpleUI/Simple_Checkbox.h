#include "Simple_UI.h"

/*
	A simple checkbox.
*/

#ifndef SIMPLE_CHECKBOX_H
#define SIMPLE_CHECKBOX_H

struct Simple_Checkbox : Simple_State {
	bool checked;
	Simple_MouseState mouseState;
	Simple_State *checkState;
	Simple_State *upState;
	Simple_State *overState;
	Simple_State *downState;
	Simple_State *textState;
	char* text;
};

Simple_Checkbox SimpleCheckbox_Create(char* text, Simple_MouseState checked, int x, int y);
void SimpleCheckbox_Init(Simple_Checkbox &checkbox, Simple_State *mouseState, Simple_State *upState, Simple_State *overState, Simple_State *downState, Simple_State *textState);
void SimpleCheckbox_SetMouseState(Simple_Checkbox &checkbox, Simple_MouseState mouseState);
int SimpleCheckbox_GetWidth(Simple_Checkbox &checkbox, int padding);
int SimpleCheckbox_GetHeight(Simple_Checkbox &checkbox);
void SimpleCheckbox_Move(Simple_Checkbox &checkbox, int x, int y, int padding);
void SimpleCheckbox_Layout(Simple_Checkbox &checkbox, int padding, Simple_Mouse &mouse);

#endif