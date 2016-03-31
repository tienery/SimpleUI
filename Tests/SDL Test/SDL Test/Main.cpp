#include <Simple_UI.h>
#include <SDL.h>
#include <stdio.h>

inline void SetupRect(SDL_Rect &rect, Simple_State &state)
{
	rect.x = state.x;
	rect.y = state.y;
	rect.w = state.width;
	rect.h = state.height;
}

int wmain(int argc, wchar_t *argv[])
{
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;

	SDL_Init(SDL_INIT_VIDEO);

	//Create a checkbox and default states
	Simple_Checkbox checkbox = SimpleCheckbox_Create("Some test value", CHECK_NONE, 5, 5);
	Simple_State checkState = SimpleState_Create(30, 30, 0, 0);
	Simple_State textState = SimpleState_Create(100, 20, 0, 0);

	//Initialise the checkbox to the references of the states this checkbox needs.
	SimpleCheckbox_Init(checkbox, &checkState, &checkState, &checkState, &checkState, &textState);
	
	//Basic SDL stuff that is required
	window = SDL_CreateWindow("SimpleUI Test on SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	bool running = true;
	SDL_Event event;

	while (running)
	{
		int mouseX = -1;
		int mouseY = -1;
		bool mouseDown = false;

		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
				running = false;
			if (event.type == SDL_MOUSEMOTION)
			{
				mouseX = event.motion.x;
				mouseY = event.motion.y;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				mouseDown = (event.button.state == SDL_PRESSED);
				mouseX = event.button.x;
				mouseY = event.button.y;
			}
		}

		//Setup the mouse.
		Simple_Mouse mouse = SimpleMouse_Create(mouseX, mouseY);
		mouse.mouseDown = mouseDown;

		//This function handles layout logic for the checkbox as necessary.
		SimpleCheckbox_Layout(checkbox, 2, mouse);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		SDL_Rect checkStateRect, textStateRect;
		SetupRect(checkStateRect, checkState);
		SetupRect(textStateRect, textState);
		
		SDL_RenderDrawRect(renderer, &checkStateRect);
		SDL_RenderDrawRect(renderer, &textStateRect);

		SDL_RenderPresent(renderer);
		SDL_UpdateWindowSurface(window);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}