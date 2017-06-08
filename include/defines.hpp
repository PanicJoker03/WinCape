#ifndef STRUCT_HPP
#define STRUCT_HPP
#include <windows.h>
#include <type_traits>
#include <memory>
#include <functional>
//type definitions
using Handle = HWND;
using InstanceHandle = HINSTANCE;
using WindowStyle = DWORD;
using ClassStyle = UINT;
using ShowCommand  = int;
using WindowMessage = UINT;
namespace WinCape
{
	struct WindowStyles
	{
		static constexpr WindowStyle Border = WS_BORDER;
		static constexpr WindowStyle Caption = WS_CAPTION;
		static constexpr WindowStyle Child = WS_CHILD;
		static constexpr WindowStyle ChildWindow = WS_CHILDWINDOW;
		static constexpr WindowStyle ClipChildren = WS_CLIPCHILDREN;
		static constexpr WindowStyle ClipSiblings = WS_CLIPSIBLINGS;
		static constexpr WindowStyle Disabled = WS_DISABLED;
		static constexpr WindowStyle DialogFrame = WS_DLGFRAME;
		static constexpr WindowStyle Group = WS_GROUP;
		static constexpr WindowStyle HorizontalScroll = WS_HSCROLL;
		static constexpr WindowStyle Iconic = WS_ICONIC;
		static constexpr WindowStyle Maximize = WS_MAXIMIZE;
		static constexpr WindowStyle MaximizeBox = WS_MAXIMIZEBOX;
		static constexpr WindowStyle Minimize = WS_MINIMIZE;
		static constexpr WindowStyle MinimizeBox = WS_MINIMIZEBOX;
		static constexpr WindowStyle Overlapped = WS_OVERLAPPED;
		static constexpr WindowStyle OverlappedWindow = WS_OVERLAPPEDWINDOW;
		static constexpr WindowStyle Popup = WS_POPUP;
		static constexpr WindowStyle PopupWindow = WS_POPUPWINDOW;
		static constexpr WindowStyle SizeBox = WS_SIZEBOX;
		static constexpr WindowStyle SystemMenu = WS_SYSMENU;
		static constexpr WindowStyle TabStop = WS_TABSTOP;
		static constexpr WindowStyle ThickFrame = WS_THICKFRAME;
		static constexpr WindowStyle Tiled = WS_TILED;
		static constexpr WindowStyle TiledWindow = WS_TILEDWINDOW;
		static constexpr WindowStyle Visible = WS_VISIBLE;
		static constexpr WindowStyle VerticalScroll = WS_VSCROLL;
	};
	struct ClassStyles
	{
		static constexpr ClassStyle ByteAlignClient = CS_BYTEALIGNCLIENT;
		static constexpr ClassStyle ByteAlignWindow = CS_BYTEALIGNWINDOW;
		static constexpr ClassStyle ClassDeviceContext = CS_CLASSDC;
		static constexpr ClassStyle DoubleClicks = CS_DBLCLKS;
		static constexpr ClassStyle DropShadow = CS_DROPSHADOW;
		static constexpr ClassStyle GlobalClass = CS_GLOBALCLASS;
		static constexpr ClassStyle HorizontalRedraw = CS_HREDRAW;
		static constexpr ClassStyle NoClose = CS_NOCLOSE;
		static constexpr ClassStyle OwnDeviceContext = CS_OWNDC;
		static constexpr ClassStyle ParentDeviceContext = CS_PARENTDC;
		static constexpr ClassStyle SaveBits = CS_SAVEBITS;
		static constexpr ClassStyle VerticalRedraw = CS_VREDRAW;
	};
	struct ShowCommands
	{
		static constexpr ShowCommand ForceMinimize = SW_FORCEMINIMIZE;
		static constexpr ShowCommand Hide = SW_HIDE;
		static constexpr ShowCommand Maximize = SW_MAXIMIZE;
		static constexpr ShowCommand Minimize = SW_MINIMIZE;
		static constexpr ShowCommand Restore = SW_RESTORE;
		static constexpr ShowCommand Show = SW_SHOW;
		static constexpr ShowCommand ShowDefault = SW_SHOWDEFAULT;
		static constexpr ShowCommand ShowMaximized = SW_SHOWMAXIMIZED;
		static constexpr ShowCommand ShowMinimized = SW_SHOWMINIMIZED;
		static constexpr ShowCommand ShowMinNoActive = SW_SHOWMINNOACTIVE;
		static constexpr ShowCommand ShowNA = SW_SHOWNA;
		static constexpr ShowCommand ShowNoActivate = SW_SHOWNOACTIVATE;
		static constexpr ShowCommand ShowNormal = SW_SHOWNORMAL;
	};
	struct WindowMessages
	{
		struct General
		{
			//Notifications
			static constexpr WindowMessage ActivateApp = WM_ACTIVATEAPP;
			static constexpr WindowMessage CancelMode = WM_CANCELMODE;
			static constexpr WindowMessage ChildActive = WM_CHILDACTIVATE;
			static constexpr WindowMessage Close = WM_CLOSE;
			static constexpr WindowMessage Compacting = WM_COMPACTING;
			static constexpr WindowMessage Create = WM_CREATE;
			static constexpr WindowMessage Destroy = WM_DESTROY;
			static constexpr WindowMessage DotPerInchChanged = WM_DPICHANGED;
			static constexpr WindowMessage Enable = WM_ENABLE;
			static constexpr WindowMessage EnterSizeMove = WM_ENTERSIZEMOVE;
			static constexpr WindowMessage ExitSizeMove = WM_EXITSIZEMOVE;
			static constexpr WindowMessage GetIcon = WM_GETICON;
			static constexpr WindowMessage GetMinMaxInfo = WM_GETMINMAXINFO;
			static constexpr WindowMessage InputLangChange = WM_INPUTLANGCHANGE;
			static constexpr WindowMessage InputLangChangeRequest = WM_INPUTLANGCHANGEREQUEST;
			static constexpr WindowMessage Move = WM_MOVE;
			static constexpr WindowMessage Moving = WM_MOVING;
			static constexpr WindowMessage NCActivate = WM_NCACTIVATE;
			static constexpr WindowMessage NCCalSize = WM_NCCALCSIZE;
			static constexpr WindowMessage NCCreate = WM_NCCREATE;
			static constexpr WindowMessage NCDestroy = WM_NCDESTROY;
			static constexpr WindowMessage Null = WM_NULL;
			static constexpr WindowMessage QueryDragIcon = WM_QUERYDRAGICON;
			static constexpr WindowMessage QueryOpen = WM_QUERYOPEN;
			static constexpr WindowMessage Quit = WM_QUIT;
			static constexpr WindowMessage ShowWindow = WM_SHOWWINDOW;
			static constexpr WindowMessage Size = WM_SIZE;
			static constexpr WindowMessage Sizing = WM_SIZING;
			static constexpr WindowMessage StyleChanged = WM_STYLECHANGED;
			static constexpr WindowMessage StyleChanging = WM_STYLECHANGING;
			static constexpr WindowMessage ThemeChanged = WM_THEMECHANGED;
			static constexpr WindowMessage UserChanged = WM_USERCHANGED;
			static constexpr WindowMessage WindowPositionChanged = WM_WINDOWPOSCHANGED;
			static constexpr WindowMessage WindowPositionChanging = WM_WINDOWPOSCHANGING;
		};
	};
	struct Int2
	{
		int x = 0, y = 0;
	};
	struct Rect
	{
		Int2 position;
		Int2 size;
	};
	//struct WindowClass
	//{

	//};
	//struct WindowData
	//{
	//	//LPCTSTR className = NULL; nearly sure its not necesary
	//	//HINSTANCE instance; instance can be get with other function
	//	//LPVOID param;
	//};
}
#endif // !STRUCT_HPP