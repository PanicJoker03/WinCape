# WinCape Entertainment Framework

WinCape Entertainment Framework is a general Win32Api wrapper. 

The philosophy behind the code is to hide all the macros, functions and legacy stuff from the win 32 api, integrating various purpose functionalities. Also preserving source code simplicity is a goal, so this library will use C++17 standard (23 is the most recent, but for compatibility issues with cygwin it must been set to 17).

![Oops](https://res.cloudinary.com/dc5vwax2d/image/upload/v1659298089/CapturaWinCape_l5knoe.png "Little Showcase Window")

## Build

It was originaly compiled on visual studio, now I use Dev C++, Cevelop, CodeBlocks, CodeLite to make the build. Either way, you should have installed mingw64 to procced. 

You can download Dev C++ [here](https://sourceforge.net/projects/dev-cpp/files/Binaries/Dev-C%2B%2B%204.9.9.2/devcpp-4.9.9.2_setup.exe/download).
And a usefull msys2 installation guide [here](https://www.msys2.org/) on the Msys2 website, just follow the steps to get mingw64 installed on your machine.

## Planned OS support

Windows XP isn't considered, but Windows Vista and later.

## Tested compilers

This library was tested on the following environments:
* Mingw 64 bit
* Cygwin 64 bit
* MCVS 64 bit

## TODO

Functors, so it will be possible to handle callback functions... Prepare wincape for lambda parameters support. NOT USE std::function!
* CMake multiple proyect support: Visual Studio, CodeBlocks, Cevelop, CodeLite, Visual Studio Code, Dev C++.
* Tab-strip control.
* File entity.
* Pass editor prototype from my computer to this repository (edt namespace).
* phy namespace for collision stuff.
* Radiobutton control.
* Font entity support.
* Pass my tunned sfml cygwin integration to this repository (dll and headers only).
* Documentation?
* Add workman mod layout topmost window display as an example.
* Input handling (Gamepad, keyboard, mouse, webcam, microphone).
* Device controlling (wifi).
* Use const specifier when possible.

## Troubleshoot

If building throws an error about __imp_wglCreateContext not resolved then you must include library OpenGl32.

**Cpp, Hell Yeah!**

### Credits

[lalmaguerdlg](https://github.com/lalmaguerdlg) - ListView implementation.
