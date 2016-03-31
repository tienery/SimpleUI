#include "Simple_State.h"

void Simple_AlignLeftOf(Simple_State *state, Simple_State *to, int padding = 2)
{
	state->x = to->x - padding - to->width;
	state->y = (to->height / 2 - state->height / 2) + to->y;
}

void Simple_AlignRightOf(Simple_State *state, Simple_State *to, int padding = 2)
{
	state->x = to->x + to->width + padding;
	state->y = (to->height / 2 - state->height / 2) + to->y;
}

void Simple_AlignTopOf(Simple_State *state, Simple_State *to, int padding = 2)
{
	state->y = to->y - state->height - padding;
	state->x = (to->width / 2 - state->width / 2) + to->x;
}

void Simple_AlignBottomOf(Simple_State *state, Simple_State *to, int padding = 2)
{
	state->x = (to->width / 2 - state->width / 2) + to->x;
	state->y = to->y + to->height + padding;
}

void Simple_AlignLeft(Simple_State *state, Simple_State *to, int padding = 2)
{
	state->x = to->x + padding;
	state->y = state->height / 2 - to->height / 2;
}

void Simple_AlignRight(Simple_State *state, Simple_State *to, int padding = 2)
{
	state->x = (to->x + to->width) - state->width - padding;
	state->y = state->height / 2 - to->height / 2;
}

void Simple_AlignTop(Simple_State *state, Simple_State *to, int padding = 2)
{
	state->x = state->width / 2 - to->width / 2;
	state->y = to->y + padding;
}

void Simple_AlignBottom(Simple_State *state, Simple_State *to, int padding = 2)
{
	state->x = state->width / 2 - to->width / 2;
	state->y = (to->y + to->height) - state->height - padding;
}