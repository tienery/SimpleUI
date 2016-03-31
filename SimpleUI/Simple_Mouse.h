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

enum Simple_MouseState {
	CHECK_DOWN,
	CHECK_OVER,
	CHECK_NONE
};

Simple_Mouse SimpleMouse_Create(int x, int y);

#endif