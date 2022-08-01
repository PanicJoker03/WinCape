#ifndef DEFINES_HPP
#define DEFINES_HPP
//Completely experimental, it may be proper to fail in other machines
#ifdef _ENABLE_THEME
#pragma comment(linker,"\"/manifestdependency:type='win32' name = 'Microsoft.Windows.Common-Controls' version = '6.0.0.0' processorArchitecture = '*' publicKeyToken = '6595b64144ccf1df' language = '*'\"")
#endif
//#define NOMINMAX
//#include <Windows.h>
#include <windows.h>
#include <WinUser.h>
//#include <tchar.h>
//#include <iostream>
#include <cstdint>
#include <CommCtrl.h>
//#include <cstdint>
//#ifdef WINCAPE_USES_WGL
//#include <GL/gl.h>
//#include <GL/glu.h>
//#endif

//For sake of simplicity, this framework will use char types
//TODO: use char and string on all text operations...

namespace WinCape
{
	constexpr static std::nullptr_t NullPointer = nullptr;
	constexpr static UINT Null = NULL;
	template<typename T>
	struct AsNull{
		static constexpr T value = NULL;
	};
	using WindowHandle = HWND;
	using DeviceContextHandle = HDC;
	using MenuHandle = HMENU;
	using IconHandle = HICON;
	using BitmapHandle = HBITMAP;
	using FontHandle = HFONT;
	using InstanceHandle = HINSTANCE;
	using FileHandle = HANDLE;
	using WindowStyle = DWORD;
	using WindowExtendedStyle = DWORD;
	using ButtonStyle = DWORD;
	using ListBoxStyle = DWORD;
	using ListViewStyle = DWORD;
	using ClassStyle = UINT;
	using ShowCommand = int;
	using ResourceInt = int;
	using WindowMessage = UINT;
	using ListBoxMessage = UINT;
	using ListViewMessage = UINT;
	using ComboBoxMessage = UINT;
	using Byte = BYTE;
	//#ifdef WINCAPE_USES_WGL
	using GlRenderContextHandle = HGLRC;
	using PixelFormatFlag = DWORD;
	using PixelFormatType = BYTE;
	using PixelFormatLayer = BYTE;
	using LayeredWindowAttribute = DWORD;
	struct PixelFormat
	{
		PixelFormatFlag flags;
		PixelFormatType type;
		std::uint8_t colorBits;
		std::uint8_t depthBits;
		std::uint8_t stencilBits;
	};
	//#endif
	using DrawTextFormat = UINT;
	struct Vector2I
	{
		int x = 0, y = 0;
	};
	struct Rect
	{
		Vector2I position, size;
	};
}
#endif // !DEFINES_HPP
