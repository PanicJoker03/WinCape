#ifndef STRUCT_HPP
#define STRUCT_HPP
//Completely experimental, it may be proper to fail in other machines
#ifdef _ENABLE_THEME
#pragma comment(linker,"\"/manifestdependency:type='win32' name = 'Microsoft.Windows.Common-Controls' version = '6.0.0.0' processorArchitecture = '*' publicKeyToken = '6595b64144ccf1df' language = '*'\"")
#endif
#define NOMINMAX
#include <windows.h>
#include <type_traits>
#include <memory>
#include <functional>
#include <vector>
namespace WinCape
{
	//type definitions
	using WindowHandle = HWND;
	using DeviceContextHandle = HDC;
	using MenuHandle = HMENU;
	using IconHandle = HICON;
	using BitmapHandle = HBITMAP;
	using FontHandle = HFONT;
	using InstanceHandle = HINSTANCE;
	using WindowStyle = DWORD;
	using ButtonStyle = DWORD;
	using ClassStyle = UINT;
	using ShowCommand = int;
	using ResourceInt = int;
	using WindowMessage = UINT;
	using Byte = BYTE;
	struct Event
	{
		WindowHandle handle;
		WPARAM wparam;
		LPARAM lparam;
	};
	using EventCallback = std::function<void(Event)>;
	template<typename T> using Reference = std::reference_wrapper<T>;
	struct Int2
	{
		int x = 0, y = 0;
	};
	struct Rect
	{
		Int2 position, size;
	};
	namespace  WindowStyles {
		enum : WindowStyle
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
	}
	namespace ButtonStyles {
		enum : ButtonStyle
		{
			State = BS_3STATE,
			AutoState = BS_AUTO3STATE,
			AutoCheckBox = BS_AUTOCHECKBOX,
			AutoRadioButton = BS_AUTORADIOBUTTON,
			BitMap = BS_BITMAP,
			Bottom = BS_BOTTOM,
			Center = BS_CENTER,
			CheckBox = BS_CHECKBOX,
			//CommandLink = BS_COMMANDLINK,
			//DefCommandLink = BS_DEFCOMMANDLINK,
			DefPushButton = BS_DEFPUSHBUTTON,
			//DefSplitButton = BS_DEFSPLITBUTTON,
			GroupBox = BS_GROUPBOX,
			Icon = BS_ICON,
			Flat = BS_FLAT,
			Left = BS_LEFT,
			LeftText = BS_LEFTTEXT,
			MultiLine = BS_MULTILINE,
			Notify = BS_NOTIFY,
			OwnerDraw = BS_OWNERDRAW,
			PushButton = BS_PUSHBUTTON,
			PushLike = BS_PUSHLIKE,
			RadioButton = BS_RADIOBUTTON,
			Right = BS_RIGHT,
			RightButton = BS_RIGHTBUTTON,
			//SplitButton = BS_SPLITBUTTON,
			Text = BS_TEXT,
			Top = BS_TOP,
			TypeMask = BS_TYPEMASK,
			UserButton = BS_USERBUTTON,
			VCenter = BS_VCENTER
		};
	}
	namespace ClassStyles {
		enum : ClassStyle
		{
			ByteAlignClient = CS_BYTEALIGNCLIENT,
			ByteAlignWindow = CS_BYTEALIGNWINDOW,
			ClassDeviceContext = CS_CLASSDC,
			DoubleClicks = CS_DBLCLKS,
			DropShadow = CS_DROPSHADOW,
			GlobalClass = CS_GLOBALCLASS,
			HorizontalRedraw = CS_HREDRAW,
			NoClose = CS_NOCLOSE,
			OwnDeviceContext = CS_OWNDC,
			ParentDeviceContext = CS_PARENTDC,
			SaveBits = CS_SAVEBITS,
			VerticalRedraw = CS_VREDRAW
		};
	}
	namespace ShowCommands {
		enum : ShowCommand
		{
			ForceMinimize = SW_FORCEMINIMIZE,
			Hide = SW_HIDE,
			Maximize = SW_MAXIMIZE,
			Minimize = SW_MINIMIZE,
			Restore = SW_RESTORE,
			Show = SW_SHOW,
			ShowDefault = SW_SHOWDEFAULT,
			ShowMaximized = SW_SHOWMAXIMIZED,
			ShowMinimized = SW_SHOWMINIMIZED,
			ShowMinNoActive = SW_SHOWMINNOACTIVE,
			ShowNA = SW_SHOWNA,
			ShowNoActivate = SW_SHOWNOACTIVATE,
			ShowNormal = SW_SHOWNORMAL
		};
	}
	namespace WindowMessages {
		enum : WindowMessage
		{
			//Notifications
			ActivateApp = WM_ACTIVATEAPP,
			CancelMode = WM_CANCELMODE,
			ChildActive = WM_CHILDACTIVATE,
			Close = WM_CLOSE,
			Command = WM_COMMAND,
			Compacting = WM_COMPACTING,
			Create = WM_CREATE,
			Destroy = WM_DESTROY,
			DotPerInchChanged = WM_DPICHANGED,
			Enable = WM_ENABLE,
			EnterSizeMove = WM_ENTERSIZEMOVE,
			ExitSizeMove = WM_EXITSIZEMOVE,
			GetIcon = WM_GETICON,
			GetMinMaxInfo = WM_GETMINMAXINFO,
			InputLangChange = WM_INPUTLANGCHANGE,
			InputLangChangeRequest = WM_INPUTLANGCHANGEREQUEST,
			MenuCommand = WM_MENUCOMMAND,
			MenuSelect = WM_MENUSELECT,
			Move = WM_MOVE,
			Moving = WM_MOVING,
			NCActivate = WM_NCACTIVATE,
			NCCalSize = WM_NCCALCSIZE,
			NCCreate = WM_NCCREATE,
			NCDestroy = WM_NCDESTROY,
			Null = WM_NULL,
			Paint = WM_PAINT,
			QueryDragIcon = WM_QUERYDRAGICON,
			QueryOpen = WM_QUERYOPEN,
			Quit = WM_QUIT,
			SetIcon = WM_SETICON,
			ShowWindow = WM_SHOWWINDOW,
			Size = WM_SIZE,
			Sizing = WM_SIZING,
			StyleChanged = WM_STYLECHANGED,
			StyleChanging = WM_STYLECHANGING,
			ThemeChanged = WM_THEMECHANGED,
			UserChanged = WM_USERCHANGED,
			WindowPositionChanged = WM_WINDOWPOSCHANGED,
			WindowPositionChanging = WM_WINDOWPOSCHANGING
		};
	}
}
#endif // !STRUCT_HPP