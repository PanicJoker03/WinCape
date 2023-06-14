#ifndef DEFINES_H
#define DEFINES_H
#ifdef _ENABLE_THEME
#pragma comment(linker,"\"/manifestdependency:type='win32' name = 'Microsoft.Windows.Common-Controls' version = '6.0.0.0' processorArchitecture = '*' publicKeyToken = '6595b64144ccf1df' language = '*'\"")
#endif
#include <windows.h>
#include <WinUser.h>
#include <commctrl.h>

#define PROGRAM_CODE_OK 0 
#define PROGRAM_CODE_BAD 1

namespace w_cape
{
	typedef int PROGRAM_RESULT;
	typedef long* PTR_LNG;
	typedef unsigned char U_SIGN_8;
	typedef const char * CHR_STR_CONST;
	typedef const wchar_t * WCH_STR_CONST;
	typedef char** CHR_STR_ARR;
	typedef char * CHR_STR;
	typedef wchar_t * WCH_STR;
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
	typedef U_SIGN_8 PXF_TPE;
	typedef U_SIGN_8 PXF_LYR;
	typedef unsigned int LYR_WND_ATR;
	typedef struct capePixelFormat
	{
		PXF_FLG flags;
		PXF_TPE type;
	    U_SIGN_8 colorBits;
	    U_SIGN_8 depthBits;
		U_SIGN_8 stencilBits;
	}PIXEL_FORMAT;
	typedef unsigned int DRW_TXT_4MAT;
	typedef struct capeIVector2
	{
	    capeIVector2() : x(0), y(0) {}
	    capeIVector2(int x, int y) : x(x), y(y){}
		int x, y;
	}I_VEC_2;
	typedef struct capeRect
	{
	    capeRect(){}
	    capeRect(I_VEC_2 position, I_VEC_2 size) : position(position) , size(size){}
	    capeRect(int pos_x, int pos_y, int size_x, int size_y) : 
			position(I_VEC_2(pos_x, pos_y)), size(I_VEC_2(size_x, size_y)){

			}
		I_VEC_2 position, size;
	}CAPE_RECT;
}
#endif // !DEFINES_H
