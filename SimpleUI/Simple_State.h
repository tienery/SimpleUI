/*
	A simple state.
*/

#ifndef SIMPLE_STATE_H
#define SIMPLE_STATE_H

struct Simple_State {
	int width;
	int height;
	int x;
	int y;
	bool visible;
};

Simple_State SimpleState_Create(int width, int height, int x, int y);

#endif