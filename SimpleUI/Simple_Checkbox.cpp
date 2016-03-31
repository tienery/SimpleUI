#include "Simple_UI.h"

Simple_Checkbox SimpleCheckbox_Create(char* text, Simple_MouseState checked, int x, int y)
{
	Simple_Checkbox checkbox;
	checkbox.mouseState = checked;
	checkbox.text = text;
	checkbox.x = x;
	checkbox.y = y;
	return checkbox;
}

void SimpleCheckbox_Init(Simple_Checkbox &checkbox, Simple_State *checkState, Simple_State *upState, Simple_State *overState, Simple_State *downState, Simple_State *textState)
{
	checkbox.checkState = checkState;
	checkbox.downState = downState;
	checkbox.overState = overState;
	checkbox.textState = textState;
	checkbox.upState = upState;
}

void SimpleCheckbox_SetCheckState(Simple_Checkbox &checkbox, Simple_MouseState mouseState)
{
	checkbox.downState->visible = (mouseState == CHECK_DOWN);
	checkbox.overState->visible = (mouseState == CHECK_OVER);
	checkbox.upState->visible = (mouseState == CHECK_NONE);
}

int SimpleCheckbox_GetWidth(Simple_Checkbox &checkbox, int padding)
{
	return checkbox.checkState->width + checkbox.textState->width + padding;
}

int SimpleCheckbox_GetHeight(Simple_Checkbox &checkbox)
{
	if (checkbox.checkState->height > checkbox.textState->height)
		return checkbox.checkState->height;
	else
		return checkbox.textState->height;
}

void SimpleCheckbox_Move(Simple_Checkbox &checkbox, int x, int y, int padding)
{
	checkbox.x = x;
	checkbox.y = y;

	SimpleState_Move(checkbox.checkState, x, y);
	SimpleState_Move(checkbox.downState, x, y);
	SimpleState_Move(checkbox.overState, x, y);
	SimpleState_Move(checkbox.upState, x, y);
	Simple_AlignRightOf(checkbox.textState, checkbox.checkState, padding);
}

/*
	Build the layout of the checkbox.
*/
void SimpleCheckbox_Layout(Simple_Checkbox &checkbox, int padding, Simple_Mouse &mouse)
{
	int totalWidth = SimpleCheckbox_GetWidth(checkbox, padding);
	int totalHeight;
	bool isDown = mouse.mouseDown;

	totalHeight = SimpleCheckbox_GetHeight(checkbox);

	checkbox.width = totalWidth;
	checkbox.height = totalHeight;

	checkbox.checkState->visible = checkbox.checked;

	Simple_AlignRightOf(checkbox.textState, checkbox.checkState, padding);

	if (mouse.x > checkbox.x && mouse.y > checkbox.y && mouse.x < checkbox.x + totalWidth && mouse.y < checkbox.y + totalHeight)
	{
		if (isDown)
		{
			SimpleCheckbox_SetCheckState(checkbox, CHECK_DOWN);
		}
		else
		{
			SimpleCheckbox_SetCheckState(checkbox, CHECK_OVER);
		}
	}
	else
		SimpleCheckbox_SetCheckState(checkbox, CHECK_NONE);
}