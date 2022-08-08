#ifndef DEFINES_HPP
#define DEFINES_HPP
//Completely experimental, it may be proper to fail in other machines
#ifdef _ENABLE_THEME
#pragma comment(linker,"\"/manifestdependency:type='win32' name = 'Microsoft.Windows.Common-Controls' version = '6.0.0.0' processorArchitecture = '*' publicKeyToken = '6595b64144ccf1df' language = '*'\"")
#endif
#include <windows.h>
#include <WinUser.h>
#include <commctrl.h>
//#ifdef WINCAPE_USES_WGL
//#include <GL/gl.h>
//#include <GL/glu.h>
//#endif

//For sake of simplicity, this framework will use char types
//TODO: use char and string on all text operations...

namespace WinCape
{
    //NULL;
	//template<typename T>
	//struct AsNull{
	//	static constexpr T value = NULL;
	//};
	typedef long* LongPointer;
	typedef unsigned char UnsignedI8;
	typedef HWND WindowHandle;
	typedef HDC DeviceContextHandle;
	typedef HMENU MenuHandle;
	typedef HICON IconHandle;
	typedef HBITMAP BitmapHandle;
	typedef HFONT FontHandle;
	typedef HINSTANCE InstanceHandle;
	typedef HFILE FileHandle;
	typedef DWORD WindowStyle;
	typedef DWORD WindowExtendedStyle;
	typedef DWORD ButtonStyle;
	typedef DWORD ListBoxStyle;
	typedef DWORD ListViewStyle;
	typedef DWORD DesiredAccess;
	typedef UINT ClassStyle;
	typedef int ShowCommand;
	typedef int ResourceInt;
	typedef UINT WindowMessage;
	typedef UINT ListBoxMessage;
	typedef UINT ListViewMessage;
	typedef UINT ComboBoxMessage;
	typedef BYTE Byte;
	//#ifdef WINCAPE_USES_WGL
	typedef HGLRC GlRenderContextHandle;
	typedef DWORD PixelFormatFlag;
	typedef BYTE PixelFormatType;
	typedef BYTE PixelFormatLayer;
	typedef DWORD LayeredWindowAttribute;
	struct PixelFormat
	{
		PixelFormatFlag flags;
		PixelFormatType type;
	    UnsignedI8 colorBits;
	    UnsignedI8 depthBits;
		UnsignedI8 stencilBits;
	};
	//#endif
	typedef UINT DrawTextFormat;
	struct Vector2I
	{
	    Vector2I() : x(0), y(0) {}
	    Vector2I(int x, int y) : x(x), y(y){}
		int x, y;
	};
	struct Rect
	{
	    Rect(){}
	    Rect(Vector2I position, Vector2I size) : position(position) , size(size){}
	    Rect(int pos_x, int pos_y, int size_x, int size_y) : position(Vector2I(pos_x, pos_y)), size(Vector2I(size_x, size_y)){}
		Vector2I position, size;
	};
}
#endif // !DEFINES_HPP
