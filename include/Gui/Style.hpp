#ifndef STYLE_HPP
#define STYLE_HPP
namespace WinCape{
    namespace  WindowStyles {
		enum 
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
		namespace Extended {
			enum {
				AcceptFiles = WS_EX_ACCEPTFILES,
				AppWindow = WS_EX_APPWINDOW,
				ClientEdge = WS_EX_CLIENTEDGE,
				Composited = WS_EX_COMPOSITED,
				ContextHelp = WS_EX_CONTEXTHELP,
				ControlParent = WS_EX_CONTROLPARENT,
				DialogModalFrame = WS_EX_DLGMODALFRAME,
				Layered = WS_EX_LAYERED,
				LayoutRightToLeft = WS_EX_LAYOUTRTL,
				Left = WS_EX_LEFT,
				LeftScrollBar = WS_EX_LEFTSCROLLBAR,
				LeftToRighReading = WS_EX_LTRREADING,
				MdiChild = WS_EX_MDICHILD,
				NoActive = WS_EX_NOACTIVATE,
				NoInheritLayout = WS_EX_NOINHERITLAYOUT,
				NoParentNotify = WS_EX_NOPARENTNOTIFY,
				//NoRedirectionBitmap = WS_EX_NOREDIRECTIONBITMAP,
				OverlappedWindows = WS_EX_OVERLAPPEDWINDOW,
				PaletteWindow = WS_EX_PALETTEWINDOW,
				Right = WS_EX_RIGHT,
				RightScrollBar = WS_EX_RIGHTSCROLLBAR,
				RightToLeftReading = WS_EX_RTLREADING,
				StaticEdge = WS_EX_STATICEDGE,
				ToolWindow = WS_EX_TOOLWINDOW,
				TopMost = WS_EX_TOPMOST,
				Transparent = WS_EX_TRANSPARENT,
				WindowEdge = WS_EX_WINDOWEDGE
			};
		}
	}
	namespace ButtonStyles {
		enum
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
		enum
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

    namespace ListViewStyles
    {
        enum {
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
            enum {
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
}
#endif // STYLE_HPP
