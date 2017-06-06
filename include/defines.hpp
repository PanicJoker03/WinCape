#ifndef STRUCT_HPP
#define STRUCT_HPP
#include <windows.h>
#include <type_traits>
#include <memory>
#include <functional>
namespace WinCape
{
	//type definitions
	using Handle = HWND;
	enum class WindowStyle : DWORD
	{
		Border = WS_BORDER,
		Caption = WS_CAPTION,
		Child = WS_CHILD,
		ChildWindow = WS_CHILDWINDOW,
		ClipChildren = WS_CLIPCHILDREN,
		ClipSiblings = WS_CLIPSIBLINGS,
		Disabled = WS_DISABLED,
		DialogFrame = WS_DLGFRAME,
		Group = WS_GROUP,
		HorizontalScroll = WS_HSCROLL,
		Iconic = WS_ICONIC,
		Maximize = WS_MAXIMIZE,
		MaximizeBox = WS_MAXIMIZEBOX,
		Minimize = WS_MINIMIZE,
		MinimizeBox = WS_MINIMIZEBOX,
		Overlapped = WS_OVERLAPPED,
		OverlappedWindow = WS_OVERLAPPEDWINDOW,
		Popup = WS_POPUP,
		PopupWindow = WS_POPUPWINDOW,
		SizeBox = WS_SIZEBOX,
		SystemMenu = WS_SYSMENU,
		TabStop = WS_TABSTOP,
		ThickFrame = WS_THICKFRAME,
		Tiled = WS_TILED,
		TiledWindow = WS_TILEDWINDOW,
		Visible = WS_VISIBLE,
		VerticalScroll = WS_VSCROLL
	};
	inline constexpr WindowStyle operator|(WindowStyle lhs, WindowStyle rhs)
	{
		using EnumType = std::underlying_type<WindowStyle>;
		return static_cast<WindowStyle>(static_cast<EnumType>(lhs) | static_cast<EnumType>(rhs));
	}
	struct Int2
	{
		int x = 0, y = 0;
	};
	struct Rect
	{
		Int32 position;
		Int32 size;
	};
	struct WindowClass
	{

	};
	struct WindowData
	{
		//LPCTSTR className = NULL; nearly sure its not necesary
		//HINSTANCE instance; instance can be get with other function
		//LPVOID param;
	};
}
#endif // !STRUCT_HPP