#include "Simple_Point.h"

/*
	A simple point.
*/

Simple_Point SimplePoint_Create(int x, int y)
{
	Simple_Point point;
	point.x = x;
	point.y = y;
	return point;
}

Simple_Point SimplePoint_Empty()
{
	Simple_Point point;
	point.x = -1;
	point.y = -1;
	return point;
}