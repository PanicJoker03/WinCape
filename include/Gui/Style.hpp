#ifndef STYLE_HPP
#define STYLE_HPP
namespace wcape{
    namespace  WindowStyles {
		enum
		{
			BORDER = WS_BORDER,
			CAPTION = WS_CAPTION,
			CHILD = WS_CHILD,
			CHILD_WINDOW = WS_CHILDWINDOW,
			CLIP_CHILDREN = WS_CLIPCHILDREN,
			CLIP_CLIP_SIBLINGS = WS_CLIPSIBLINGS,
			DISABLED = WS_DISABLED,
			DIALOG_FRAME = WS_DLGFRAME,
			GROUP = WS_GROUP,
			HOR_SCROLL = WS_HSCROLL,
			ICON = WS_ICONIC,
			MAXI = WS_MAXIMIZE,
			MAX_BOX = WS_MAXIMIZEBOX,
			MINI = WS_MINIMIZE,
			MIN_BOX = WS_MINIMIZEBOX,
			OVERLAPPED = WS_OVERLAPPED,
			OVERLAPPED_WND = WS_OVERLAPPEDWINDOW,
			POPUP = WS_POPUP,
			POPUP_WND = WS_POPUPWINDOW,
			SIZE_BOX = WS_SIZEBOX,
			SYS_MENU = WS_SYSMENU,
			TAB_STOP = WS_TABSTOP,
			THICK_FRAME = WS_THICKFRAME,
			TILED = WS_TILED,
			TILED_WND = WS_TILEDWINDOW,
			VISIBLE = WS_VISIBLE,
			VER_SCROLL = WS_VSCROLL
		};
		namespace Extended {
			enum {
				ACEEPT_FLL = WS_EX_ACCEPTFILES,
				APP_WND = WS_EX_APPWINDOW,
				CLIENT_EDGE = WS_EX_CLIENTEDGE,
				COMPOSITED = 0x02000000,
				CONTEXT_HELP = WS_EX_CONTEXTHELP,
				CONTROL_PARENT = WS_EX_CONTROLPARENT,
				DIALOG_MODAL_FRAME = WS_EX_DLGMODALFRAME,
				LYER = 0x00080000,
				LAYOUT_RIGHT_TO_LEF = 0x00400000,
				LEFT = WS_EX_LEFT,
				LEF_SCROLL_BAR = WS_EX_LEFTSCROLLBAR,
				LEF_TO_RIGHT_READING = WS_EX_LTRREADING,
				MDI_CHILD = WS_EX_MDICHILD,
				NO_ACT = 0x08000000,
				NO_INHERIT_LAYOUT = 0x00100000,
				NO_PARENT_NOTIFY = WS_EX_NOPARENTNOTIFY,
				//NoRedirectionBitmap = WS_EX_NOREDIRECTIONBITMAP,
				OVERLAPPED_WND = WS_EX_OVERLAPPEDWINDOW,
				PAL_WND = WS_EX_PALETTEWINDOW,
				RIGHT = WS_EX_RIGHT,
				RIGHT_SCROLL_BAR = WS_EX_RIGHTSCROLLBAR,
				RIGHT_TO_LEF_READING = WS_EX_RTLREADING,
				STATIC_EDGE = WS_EX_STATICEDGE,
				TOL_WND = WS_EX_TOOLWINDOW,
				TOPMOST = WS_EX_TOPMOST,
				//TRANSPARENT = WS_EX_TRANSPARENT, Uncommenting this line result in compiler error
				WND_EDGE = WS_EX_WINDOWEDGE
			};
		}
	}
	namespace ButtonStyles {
		enum
		{
			_3STATE = BS_3STATE,
			AUT_STATE = BS_AUTO3STATE,
			AUT_CHECKBOX = BS_AUTOCHECKBOX,
			AUT_RADIO_BTN = BS_AUTORADIOBUTTON,
			BIMP = BS_BITMAP,
			BOTTOM = BS_BOTTOM,
			CENT = BS_CENTER,
			CHECKBOX = BS_CHECKBOX,
			//CommandLink = BS_COMMANDLINK,
			//DefCommandLink = BS_DEFCOMMANDLINK,
			DEFPUSH_BTN = BS_DEFPUSHBUTTON,
			//DefSplitButton = BS_DEFSPLITBUTTON,
			GROUP_BOX = BS_GROUPBOX,
			ICON = BS_ICON,
			FLAT = 32768,
			LEFT = BS_LEFT,
			LEF_TXT = BS_LEFTTEXT,
			MULTILINE = BS_MULTILINE,
			NOTIFY = BS_NOTIFY,
			OWNER_DRW = BS_OWNERDRAW,
			PUSH_BTN = BS_PUSHBUTTON,
			PUSH_LIKE = BS_PUSHLIKE,
			RADIO_BTN = BS_RADIOBUTTON,
			RIGHT = BS_RIGHT,
			RIGHT_BTN = BS_RIGHTBUTTON,
			//SplitButton = BS_SPLITBUTTON,
			TEXT = BS_TEXT,
			TOP = BS_TOP,
			TYPE_MSK = 15,
			USR_BTN = BS_USERBUTTON,
			V_CEN = BS_VCENTER
		};
	}
	namespace ClassStyles {
		enum
		{
			BYTE_ALIGN_CLIENT = CS_BYTEALIGNCLIENT,
			BYTE_ALIGN_WINDOW = CS_BYTEALIGNWINDOW,
			CLASS_DEVICE_CONTEXT = CS_CLASSDC,
			DOB_CLICKS = CS_DBLCLKS,
			DROP_SHADOWS = 0x00020000,
			GLOBAL_CLASS = CS_GLOBALCLASS,
			HOR_REDRAW = CS_HREDRAW,
			NO_CLOSE = CS_NOCLOSE,
			OWN_DEV_CONTEXT = CS_OWNDC,
			PARENT_DEV_CONTEXT = CS_PARENTDC,
			SAVE_BITS = CS_SAVEBITS,
			VER_REDRAW = CS_VREDRAW
		};
	}

    namespace ListViewStyles
    {
        enum {
            ALIGN_LEF = LVS_ALIGNLEFT,
            ALIGN_MSK = LVS_ALIGNMASK,
            ALIGN_TOP = LVS_ALIGNTOP,
            AUT_ARRANGE = LVS_AUTOARRANGE,
            EDIT_LBL = LVS_EDITLABELS,
            ICON = LVS_ICON,
            LIST = LVS_LIST,
            NO_COL_HEADER = LVS_NOCOLUMNHEADER,
            NO_LBL_WRAP = LVS_NOLABELWRAP,
            NO_SCROLL = LVS_NOSCROLL,
            NO_SORT_HEADER = LVS_NOSORTHEADER,
            //OWNER_DATA = 0x1000,
            OWN_DRW_FIX = LVS_OWNERDRAWFIXED,
            REPORT = LVS_REPORT,
            SHARE_IMAGE_LISTS = LVS_SHAREIMAGELISTS,
            SHW_SEL_ALWAYS = LVS_SHOWSELALWAYS,
            SINGLE_SEL = LVS_SINGLESEL,
            SMALL_ICO = LVS_SMALLICON,
            SORT_ASCENDING = LVS_SORTASCENDING,
            SORT_DESCENDING = LVS_SORTDESCENDING,
            TYPE_MASK = LVS_TYPEMASK,
            TYPE_STYLE_MASK = LVS_TYPESTYLEMASK
        };
        namespace Extended {
            enum {
                AUT_ARRANGE = 0x01000000,
                AUT_CHECK_SEL = 0x08000000,
                AUT_SIZE_COL = 0x10000000,
                AUT_BORDER_SEL = 32768,
                CHECKBOXES = 4,
                COL_OVERFLOW = 2147483648,
                COL_SNAP_POINTS = 0x40000000,
                DOB_BUF = 65536,
                FLAT_SB = 0x00000100,
                FUL_ROW_SEL = 32,
                GRD_LINES = 1,
                HEADER_DRAG_DROP = 16,
                HEADER_IN_ALL_VIEWS = 33554432,
                HIDE_LBL = 131072,
                INF_TIP = 1024,
                JUSTIFY_COL = 2097152,
                LBL_TIP = 16384,
                MULTIWORK_AREAS = 8192,
                ONE_CLICK_ACT = 0x00000040,
                REGIONAL = 512,
                SIMPLE_SEL = 1048576,
                SINGLE_ROW = 0x00040000,
                SNAP_TO_GRD = 0x00080000,
                SUB_ITEM_IMG = 0x00000002,
                TRACK_SEL = 8,
                //TRANSPARENT_BACKGROUND = -1,NOT FOUND!
                TRANSPARENT_SHADOW_TXT = 8388608,
                TWO_CLICK_ACT = 128,
                UNDERLINE_COLD = 4096,
                UNDERLINE_HOT = 2048
            };
        }
    };
}
#endif // STYLE_HPP
