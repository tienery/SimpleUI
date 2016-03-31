#include "Simple_UI.h"

Simple_Checkbox SimpleCheckbox_Create(char* text, Simple_CheckState checked, int x, int y)
{
	Simple_Checkbox checkbox;
	checkbox.checked = checked;
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

void SimpleCheckbox_SetCheckState(Simple_Checkbox &checkbox, Simple_CheckState checkState)
{
	checkbox.downState->visible = (checkState == CHECK_DOWN);
	checkbox.overState->visible = (checkState == CHECK_OVER);
	checkbox.upState->visible = (checkState == CHECK_NONE);
}

/*
	Build the layout of the checkbox.
*/
void SimpleCheckbox_Layout(Simple_Checkbox &checkbox, int padding, Simple_Mouse &mouse)
{
	int totalWidth = checkbox.checkState->width + checkbox.textState->width + padding;
	int totalHeight;
	bool isDown = mouse.mouseDown;

	if (checkbox.checkState->height > checkbox.textState->height)
		totalHeight = checkbox.checkState->height;
	else
		totalHeight = checkbox.textState->height;

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