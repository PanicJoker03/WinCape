#ifndef DEFINES_H
#define DEFINES_H
#ifdef _ENABLE_THEME
#pragma comment(linker,"\"/manifestdependency:type='win32' name = 'Microsoft.Windows.Common-Controls' version = '6.0.0.0' processorArchitecture = '*' publicKeyToken = '6595b64144ccf1df' language = '*'\"")
#endif
#include <windows.h>
#include <WinUser.h>
#include <commctrl.h>

namespace w_cape
{
	typedef long* PTR_LNG;
	typedef unsigned char USIGN_8;
	typedef const char * STR_CON;
	typedef const wchar_t * WSTR_CON;
	typedef char * PTR_STR;
	typedef wchar_t * PTR_WSTR;
	typedef HWND WND_HND;
	typedef HDC DCX_HND;
	typedef HMENU MNU_HND;
	typedef HICON ICO_HND;
	typedef HBITMAP BMP_HND;
	typedef HFONT FON_HND;
	typedef HINSTANCE INS_HND;
	typedef HANDLE FLL_HND;
	typedef unsigned int WND_STY;
	typedef unsigned int WNDX_STY;
	typedef unsigned int BTN_STY;
	typedef unsigned int LSB_STY;
	typedef unsigned int LVW_STY;
	typedef unsigned int DSRED_ACCES;
	typedef unsigned int CLLS_STY;
	typedef int SHW_CMD;
	typedef int RESRC_I;
	typedef unsigned int WND_MSG;
	typedef unsigned int LSB_MSG;
	typedef unsigned int LVW_MSG;
	typedef unsigned int CBX_MSG;
	typedef HGLRC GL_RCX_HND;
	typedef unsigned int PXF_FLG;
	typedef USIGN_8 PXF_TPE;
	typedef USIGN_8 PXF_LYR;
	typedef unsigned int LYR_WND_ATR;
	typedef struct capePixelFormat
	{
		PXF_FLG flags;
		PXF_TPE type;
	    USIGN_8 colorBits;
	    USIGN_8 depthBits;
		USIGN_8 stencilBits;
	}PIXEL_FORMAT;
	typedef unsigned int DRW_TXT_4MAT;
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
#endif // !DEFINES_H
