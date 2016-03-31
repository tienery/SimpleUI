/*
	A simple mouse structure.
*/

#ifndef SIMPLE_MOUSE_H
#define SIMPLE_MOUSE_H

struct Simple_Mouse {
	int x;
	int y;
	bool mouseDown;
};

Simple_Mouse SimpleMouse_Create(int x, int y);

#endif