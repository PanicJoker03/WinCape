#ifndef DEFINES_HPP
#define DEFINES_HPP
//Completely experimental, it may be proper to fail in other machines
#ifdef _ENABLE_THEME
#pragma comment(linker,"\"/manifestdependency:type='win32' name = 'Microsoft.Windows.Common-Controls' version = '6.0.0.0' processorArchitecture = '*' publicKeyToken = '6595b64144ccf1df' language = '*'\"")
#endif
#define NOMINMAX
#include <Windows.h>
#include <windows.h>
#include <limits.h>
#include <memory>
#include <functional>
#include <vector>
#include <tchar.h>
#include <iostream>
#include <CommCtrl.h>
namespace WinCape
{
#ifndef Text(str)
#define Text(str) TEXT(str)
#endif
	//type definitions
#ifndef UNICODE || _UNICODE
	std::ostream& charout = std::cout;
#else 
	std::wostream& charout = std::wcout;
#endif
	using TextChar = TCHAR;
	class BaseStringView {
	public:
		constexpr BaseStringView(const TextChar* str) : str(str) {

		}
	private:
		const TextChar* str;
	public:
		const TextChar operator[](size_t i) {
			return str[i];
		}
		constexpr const TextChar* ptr() const {
			return str;
		}
	};

	template<size_t Len>
	class TextView : public BaseStringView {
	public:
		constexpr TextView(const TextChar* str) : BaseStringView(str) {

		}
		constexpr size_t count() const {
			return Len;
		}
		constexpr size_t length() const {
			return Len - 1;//Omits null terminated character
		}
		constexpr size_t size() const {
			return sizeof(TextChar) * Len;
		}
	};
#ifndef StringLen(str)
#define StringLen(str) sizeof(Text(str))/sizeof(TextChar)
#endif
#ifndef StringView(str)
#define StringView(str) TextView<StringLen(str)>{ Text(str) }
#endif
	using WindowHandle = HWND;
	using GlRenderContextHandle = HGLRC;
	using DeviceContextHandle = HDC;
	using MenuHandle = HMENU;
	using IconHandle = HICON;
	using BitmapHandle = HBITMAP;
	using FontHandle = HFONT;
	using InstanceHandle = HINSTANCE;
	using WindowStyle = DWORD;
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
	struct Event
	{
		WindowHandle handle;
		WPARAM wparam;
		LPARAM lparam;
	};
	using EventCallback = std::function<void(Event)>;
	template<typename T> using Reference = std::reference_wrapper<T>;
	struct Vector2I
	{
		int x = 0, y = 0;
	};
	struct Rect
	{
		Vector2I position, size;
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
			Bitmap = BS_BITMAP,
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
	namespace ListBoxMessages {
		enum : ListBoxMessage {
			AddFile = LB_ADDFILE,
			AddString = LB_ADDSTRING,
			DeleteString = LB_DELETESTRING,
			Directory = LB_DIR,
			FindString = LB_FINDSTRING,
			FindStringExact = LB_FINDSTRINGEXACT,
			GetAnchorIndex = LB_GETANCHORINDEX,
			GetCaretIndex = LB_GETCARETINDEX,
			GetCount = LB_GETCOUNT,
			GetCurrentIndex = LB_GETCURSEL,
			GetHorizontalExtent = LB_GETHORIZONTALEXTENT,
			GetItemData = LB_GETITEMDATA,
			GetItemHeight = LB_GETITEMHEIGHT,
			GetItemRect = LB_GETITEMRECT,
			GetListBoxInfo = LB_GETLISTBOXINFO,
			GetLocale = LB_GETLOCALE,
			GetSelection = LB_GETSEL,
			GetSelectionCount = LB_GETSELCOUNT,
			GetSelectionItems = LB_GETSELITEMS,
			GetText = LB_GETTEXT,
			GetTextLength = LB_GETTEXTLEN,
			GetTopIndex = LB_GETTOPINDEX,
			InitStorage = LB_INITSTORAGE,
			InsertString = LB_INSERTSTRING,
			ItemFromPoint = LB_ITEMFROMPOINT,
			ResetContent = LB_RESETCONTENT,
			SelectString = LB_SELECTSTRING,
			SelectItemRange = LB_SELITEMRANGE,
			SelectItemRangeX = LB_SELITEMRANGEEX,
			SetAnchorIndex = LB_SETANCHORINDEX,
			SetCaretIndex = LB_SETCARETINDEX,
			SetColumnWidth = LB_SETCOLUMNWIDTH,
			SetCount = LB_SETCOUNT,
			SetCurrentSelection = LB_SETCURSEL,
			SetHorizontalExtent = LB_SETHORIZONTALEXTENT,
			SetItemData = LB_SETITEMDATA,
			SetItemHeight = LB_SETITEMHEIGHT,
			SetLocale = LB_SETLOCALE,
			SetSelectionIndex = LB_SETSEL,
			SetTabStops = LB_SETTABSTOPS,
			SetTopIndex = LB_SETTOPINDEX
		};
	}
	static struct ClassNames final {
		const TextChar* ListView = WC_LISTVIEW;
		const TextChar* Button = WC_BUTTON;
		const TextChar* ListBox = WC_LISTBOX;
	};
	namespace ListViewStyles
	{
		enum : ListViewStyle {
			AlignLeft = LVS_ALIGNLEFT,
			AlignMask = LVS_ALIGNMASK,
			AlignTop = LVS_ALIGNTOP,
			AutoArrange = LVS_AUTOARRANGE,
			EditLabels = LVS_EDITLABELS,
			Icon = LVS_ICON,
			List = LVS_LIST,
			NoColumnHeader = LVS_NOCOLUMNHEADER,
			NoLabelWrap = LVS_NOLABELWRAP,
			NoScroll = LVS_NOSCROLL,
			NoSortHeader = LVS_NOSORTHEADER,
			OwnerData = LVS_OWNERDATA,
			OwnerDrawFixed = LVS_OWNERDRAWFIXED,
			Report = LVS_REPORT,
			ShareImageLists = LVS_SHAREIMAGELISTS,
			ShowSelAlways = LVS_SHOWSELALWAYS,
			SignleSel = LVS_SINGLESEL,
			SmallIcon = LVS_SMALLICON,
			SortAscending = LVS_SORTASCENDING,
			SortDescending = LVS_SORTDESCENDING,
			TypeMask = LVS_TYPEMASK,
			TypeStyleMask = LVS_TYPESTYLEMASK
		};
		namespace Extended {
			enum : ListViewStyle {
				AutoArrange = LVS_EX_AUTOAUTOARRANGE,
				AutoCheckSelect = LVS_EX_AUTOCHECKSELECT,
				AutoSizeColumns = LVS_EX_AUTOSIZECOLUMNS,
				AutoBorderSelect = LVS_EX_BORDERSELECT,
				Checkboxes = LVS_EX_CHECKBOXES,
				ColumnOverflow = LVS_EX_COLUMNOVERFLOW,
				ColumnSnapPoints = LVS_EX_COLUMNSNAPPOINTS,
				DoubleBuffer = LVS_EX_DOUBLEBUFFER,
				FlatSB = LVS_EX_FLATSB,
				FullRowSelect = LVS_EX_FULLROWSELECT,
				GridLines = LVS_EX_GRIDLINES,
				HeaderDragDrop = LVS_EX_HEADERDRAGDROP,
				HeaderInAllViews = LVS_EX_HEADERINALLVIEWS,
				HideLabels = LVS_EX_HIDELABELS,
				InfoTip = LVS_EX_INFOTIP,
				JustifyColumns = LVS_EX_JUSTIFYCOLUMNS,
				LabelTip = LVS_EX_LABELTIP,
				MultiWorkAreas = LVS_EX_MULTIWORKAREAS,
				OneClickActivate = LVS_EX_ONECLICKACTIVATE,
				Regional = LVS_EX_REGIONAL,
				SimpleSelect = LVS_EX_SIMPLESELECT,
				SingleRow = LVS_EX_SINGLEROW,
				SnapToGrid = LVS_EX_SNAPTOGRID,
				SubItemImages = LVS_EX_SUBITEMIMAGES,
				TrackSelect = LVS_EX_TRACKSELECT,
				TransparentBackground = LVS_EX_TRANSPARENTBKGND,
				TransparentShadowText = LVS_EX_TRANSPARENTSHADOWTEXT,
				TwoClickActivate = LVS_EX_TWOCLICKACTIVATE,
				UnderLineCold = LVS_EX_UNDERLINECOLD,
				UnderLineHot = LVS_EX_UNDERLINEHOT
			};
		}
	};
	namespace ListViewMessages {
		enum : ListViewMessage {
			ItemChanged = LVN_ITEMCHANGED
		};
	}
}
#endif // !DEFINES_HPP