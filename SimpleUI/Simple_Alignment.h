#include "Simple_UI.h"

/*
	A utility that aids in aligning layouts.
*/

#ifndef SIMPLE_ALIGNMENT_H
#define SIMPLE_ALIGNMENT_H

void Simple_AlignLeftOf(Simple_State *state, Simple_State *to, int padding);
void Simple_AlignRightOf(Simple_State *state, Simple_State *to, int padding);
void Simple_AlignTopOf(Simple_State *state, Simple_State *to, int padding);
void Simple_AlignBottomOf(Simple_State *state, Simple_State *to, int padding);
void Simple_AlignLeft(Simple_State *state, Simple_State *to, int padding);
void Simple_AlignRight(Simple_State *state, Simple_State *to, int padding);
void Simple_AlignTop(Simple_State *state, Simple_State *to, int padding);
void Simple_AlignBottom(Simple_State *state, Simple_State *to, int padding);

#endif