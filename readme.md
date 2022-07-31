# WinCape

WinCape is a general Win32Api wrapper. The philosophy behind the code is to hide all the macros, functions and legacy stuff from the win 32 api.

![Oops](https://res.cloudinary.com/dc5vwax2d/image/upload/v1659298089/CapturaWinCape_l5knoe.png "Little Showcase Window")

## Build

It was originaly compiled on visual studio, now I use Code::Blocks to make the build. Soon I will share the g++ command to build the .exe. Either way, you should have installed cygwin to procced. 

You can download Code::Blocks [here](https://www.codeblocks.org/downloads/).
And a usefull cygwin installation guide [here](https://www.sefidian.com/2020/05/09/installing-g-c-compiler-on-windows/#:~:text=%20Installing%20g%2B%2B%20%28C%2B%2B%20Compiler%29%20on%20Windows%20,a%20Cygwin%20terminal%2C%20either%20from%20the...%20More%20) on the sefidian website, just follow the steps to get cygwin installed on your machine.

## Troubleshoot

If building throws an error about __imp_wglCreateContext not resolved then you must include library OpenGl32.

**Cpp, Hell Yeah!**

TODO: Rollback TextChar changes, use wchar_t and char instead on all methods.

### Credits

[lalmaguerdlg](https://github.com/lalmaguerdlg) - ListView implementation.
