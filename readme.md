# WinCape

WinCape is a general Win32Api wrapper. The philosophy behind the code is to hide all the macros, functions and legacy stuff from the win 32 api. Also preserving source code simplicity is a goal, so this library uses C++11 standard.

![Oops](https://res.cloudinary.com/dc5vwax2d/image/upload/v1659298089/CapturaWinCape_l5knoe.png "Little Showcase Window")

## Build

It was originaly compiled on visual studio, now I use Dev C++ to make the build. Soon I will share the g++ command to build the .exe. Either way, you should have installed mingw64 to procced. 

You can download Dev C++ [here](https://sourceforge.net/projects/dev-cpp/files/Binaries/Dev-C%2B%2B%204.9.9.2/devcpp-4.9.9.2_setup.exe/download).
And a usefull msys2 installation guide [here](https://www.msys2.org/) on the Msys2 website, just follow the steps to get mingw64 installed on your machine.

## Planned OS support

Windows XP isn't considered, but Windows Vista and later.

## Troubleshoot

If building throws an error about __imp_wglCreateContext not resolved then you must include library OpenGl32.

## TODO
Tabstrip component

**Cpp, Hell Yeah!**

### Credits

[lalmaguerdlg](https://github.com/lalmaguerdlg) - ListView implementation.
