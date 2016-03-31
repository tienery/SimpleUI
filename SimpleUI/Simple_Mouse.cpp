#include "Simple_Mouse.h"

Simple_Mouse SimpleMouse_Create(int x, int y)
{
	Simple_Mouse mouse;
	mouse.x = x;
	mouse.y = y;
	return mouse;
}