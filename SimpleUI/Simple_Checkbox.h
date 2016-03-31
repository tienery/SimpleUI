#include "Simple_UI.h"

/*
	A simple checkbox.
*/

#ifndef SIMPLE_CHECKBOX_H
#define SIMPLE_CHECKBOX_H

enum Simple_CheckState {
	CHECK_DOWN,
	CHECK_OVER,
	CHECK_NONE
};

struct Simple_Checkbox {
	Simple_CheckState checked;
	Simple_State *checkState;
	Simple_State *upState;
	Simple_State *overState;
	Simple_State *downState;
	Simple_State *textState;
	char* text;
	int x;
	int y;
};

Simple_Checkbox SimpleCheckbox_Create(char* text, Simple_CheckState checked, int x, int y);
void SimpleCheckbox_Init(Simple_Checkbox &checkbox, Simple_State *checkState, Simple_State *upState, Simple_State *overState, Simple_State *downState, Simple_State *textState);
void SimpleCheckbox_SetCheckState(Simple_Checkbox &checkbox, Simple_CheckState checkState);
void SimpleCheckbox_Layout(Simple_Checkbox &checkbox, int padding, Simple_Mouse &mouse);

#endif