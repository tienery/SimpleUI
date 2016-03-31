# SimpleUI
SimpleUI is a utility library that helps abstract layout logic from rendering. It is designed to help in aiding the flow of user interfaces without taking away control from rendering, giving you maximum flexibility for your rendering needs.

## What SimpleUI is NOT...

* A rendering utility - It is designed to abstract layout logic, meaning you construct the elements you want positioned and laid out, then later draw yourself using rendering options you desire.
* A complete UI package - While it is a goal, it's most certainly not a short-term goal. Ideally, this library is designed to help layout UI in a meaningful manner using any framework, subsystem or rendering library of your choice.

## Using the library

You can simply `#include <Simple_UI.h>` which includes all the header files in the library for you.

It is designed to be as simple as possible in terms of its API, perhaps not in terms of options available. Primarily, the functions in each UI element are as follows:

 * `<Name>_Create(...)` will create a struct on the stack within the current scope.
 * `<Name>_Init(...)` will initialise the newly created struct. It asks you to pass in pointers to `Simple_State` which is defined as containing the necessary data for layout logic. There are some useful member variables such as `visible` for scene layout later in rendering.
 * `<Name>_Layout(...)` will actually do the layout logic for you, so that you don't have to. It will require a reference to a `Simple_Mouse` instance as that will determine mouse over/up/down states.

You don't necessarily need to know anything else unless you wish to have a bit more control over layout.

The `Simple_Alignment.h` file provides a series of utility functions that SimpleUI will use internally, but you can also use them for layout UI elements to your own liking.

### Naming Conventions

The naming conventions may be confusing at first, but we believe it will help to distinguish between functions and struct definitions. Mostly, struct definitions will be prefixed with `Simple_`, while functions relating to, for example the Checkbox, will be `SimpleCheckbox_`.

So in the case of the Layout function call, you would use `SimpleCheckbox_Layout(...)`.

### Using the Tests

For a more in-depth and hands-on experience, you can use the Tests within the `Tests/` folder. Currently, only one for SDL (v2.0.3) exists, but more will be included later. The test is built primarily on x86 architecture.

## Building from Source

The project is written in pure C, but is built using VC++ 2013.

To build, the project in Visual Studio comes with predefined build configurations. Simply open the respective `*.vcxproj` file in Visual Studio 2013 (or later at your choice), and then choose [Static] Debug/Release in the configuration list. Static will build the *.lib, while those tagged non-Static will build *.dll.

## Copyright Notice

Primarily, I, Luke (tienery) Selman, will be maintaining, testing and making improvements for this project. Later, this may be rebranded under my company name if I feel it is necessary. While this will not affect you as a developer, if you consider attributing back, please check this copyright periodically to ensure that the correct author is being attributed.

If in doubt, use the following attribution and I will accept it:

    SimpleUI is a library created and maintained by Colour Multimedia Enterprises and its respective contributors, licensed under the MIT license.

An attribution would be kindly appreciated if you use this in any of your projects, but is not required.
