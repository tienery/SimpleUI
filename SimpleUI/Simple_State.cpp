#include "Simple_UI.h"

Simple_State SimpleState_Create(int width, int height, int x, int y)
{
	Simple_State state;
	state.width = width;
	state.height = height;
	state.x = x;
	state.y = y;
	state.visible = false;
	return state;
}