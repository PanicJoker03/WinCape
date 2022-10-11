# Wincape 

Wincape Window Manager is a general Win32Api wrapper. 

The philosophy behind the code is to hide all the macros, functions and legacy stuff from the win 32 api, integrating various purpose functionalities. Also preserving source code simplicity is a goal, so this library will use C++17 standard (23 is the most recent, but for compatibility issues with cygwin it must been set to 17).

![Oops](https://res.cloudinary.com/dc5vwax2d/image/upload/v1659298089/CapturaWinCape_l5knoe.png "Little Showcase Window")

## Build

It was originaly compiled on visual studio, now I use Dev C++, Cevelop, CodeBlocks, CodeLite to make the build. Either way, you should have installed mingw64 to procced. 

## Planned OS support

Windows XP isn't considered, but Windows Vista and later.

## Tested compilers

This library was tested on the following environments (Only support for Mingw is planned):
* Mingw 64 bit
* Cygwin 64 bit
* MCVS 64 bit

## TODO

Functors, so it will be possible to handle callback functions... Prepare wincape for lambda parameters support. NOT USE std::function!
* CMake multiple proyect support: Visual Studio, CodeBlocks, Cevelop, CodeLite, Visual Studio Code, Dev C++.
* Tab-strip control.
* File Handling.
* Radiobutton control.
* Font entity support.
* Documentation?
* (Done) Add workman mod layout topmost window display as an example.
* Use const specifier when possible.
* Strong type enums... again.
* Lib build.

## Troubleshoot

If building throws an error about __imp_wglCreateContext not resolved then you must include library OpenGl32.

**Cpp, Hell Yeah!**

### Credits

[lalmaguerdlg](https://github.com/lalmaguerdlg) - ListView implementation.
