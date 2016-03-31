/*
	A simple point structure.
*/

#ifndef SIMPLE_POINT_H
#define SIMPLE_POINT_H

struct Simple_Point {
	int x;
	int y;
};

Simple_Point SimplePoint_Create(int x, int y);
Simple_Point SimplePoint_Empty();

#endif