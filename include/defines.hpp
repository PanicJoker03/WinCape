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

namespace cape
{
	typedef long* LNG_PTR;
	typedef unsigned char USIGN_8;
	typedef const char * CON_STR;
	typedef const wchar_t * CON_WSTR;
	typedef char * STR_PTR;
	typedef WSTR_PTR WSTR_PTR;
	typedef HWND WND_HND;
	typedef HDC DCX_HND;
	typedef HMENU MNU_HND;
	typedef HICON ICO_HND;
	typedef HBITMAP BMP_HND;
	typedef HFONT FON_HND;
	typedef HINSTANCE ISC_HND;
	typedef HFILE FLL_HND;
	typedef DWORD WND_STY;
	typedef DWORD WNDX_STY;
	typedef DWORD BTN_STY;
	typedef DWORD LSB_STY;
	typedef DWORD LVW_STY;
	typedef DWORD DRD_ACCES;
	typedef UINT CLLS_STY;
	typedef int SHW_CMD;
	typedef int RESRC_I;
	typedef UINT WND_MSG;
	typedef UINT LSB_MSG;
	typedef UINT LVW_MSG;
	typedef UINT CBX_MSG;
	//#ifdef WINCAPE_USES_WGL
	typedef HGLRC GL_RCX_HND;
	typedef DWORD PXF_FLG;
	typedef BYTE PXF_TPE;
	typedef BYTE PXF_LYR;
	typedef DWORD LYR_WND_ATR;
	typedef struct capePixelFormat
	{
		PXF_FLG flags;
		PXF_TPE type;
	    USIGN_8 colorBits;
	    USIGN_8 depthBits;
		USIGN_8 stencilBits;
	}PIXEL_FORMAT;
	//#endif
	typedef UINT DRW_TXT_FMAT;
	typedef struct capeVector2I
	{
	    capeVector2I() : x(0), y(0) {}
	    capeVector2I(int x, int y) : x(x), y(y){}
		int x, y;
	}VEC_2I;
	typedef struct capeRect
	{
	    capeRect(){}
	    capeRect(VEC_2I position, VEC_2I size) : position(position) , size(size){}
	    capeRect(int pos_x, int pos_y, int size_x, int size_y) : position(VEC_2I(pos_x, pos_y)), size(VEC_2I(size_x, size_y)){}
		VEC_2I position, size;
	}CAPE_RECT;
}
#endif // !DEFINES_HPP
