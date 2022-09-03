#ifndef GUI_DEFINES_HPP
#define GUI_DEFINES_HPP
#include "defines.hpp"
namespace cape{
    namespace usr{

      namespace ShowCommands {
            enum
            {
                FORCE_MINIMIZE = 11,
                HIDE = SW_HIDE,
                MAXIMIZE = SW_MAXIMIZE,
                MINIMIZE = SW_MINIMIZE,
                RESTORE = SW_RESTORE,
                SHOW = SW_SHOW,
                SHOW_DEFAULT = SW_SHOWDEFAULT,
                SHOW_MAXIMIZED = SW_SHOWMAXIMIZED,
                SHOW_MINIMIZED = SW_SHOWMINIMIZED,
                SHOW_MIN_NO_ACTIVE = SW_SHOWMINNOACTIVE,
                SHOW_NA = SW_SHOWNA,
                SHOW_NO_ACTIVATE = SW_SHOWNOACTIVATE,
                SHOW_NORMAL = SW_SHOWNORMAL
            };
        }
        namespace WindowMessages {
            enum
            {
                //Notifications
                ACTIVATE_APP = WM_ACTIVATEAPP,
                CANCEL_MODE = WM_CANCELMODE,
                CHILD_ACTIVE = WM_CHILDACTIVATE,
                CLOSE = WM_CLOSE,
                COMMAND = WM_COMMAND,
                COMPACTING = WM_COMPACTING,
                CREATE = WM_CREATE,
                DESTROY = WM_DESTROY,
                DOT_PER_INCH_CHANGED = 0x02E0,
                ENABLE = WM_ENABLE,
                ENTER_SIZE_MOVE = WM_ENTERSIZEMOVE,
                EXIT_SIZE_MOVE = WM_EXITSIZEMOVE,
                GET_ICON = WM_GETICON,
                GET_MIN_MAX_INFO = WM_GETMINMAXINFO,
                INPUT_LAG_CHANGE = WM_INPUTLANGCHANGE,
                INPUT_LANG_CHANGE_REQUEST = WM_INPUTLANGCHANGEREQUEST,
                MENU_COMMAND = 0x0126,
                MENU_SELECT = WM_MENUSELECT,
                MOVE = WM_MOVE,
                MOVING = WM_MOVING,
                NC_ACTIVATE = WM_NCACTIVATE,
                NC_CAL_SIZE = WM_NCCALCSIZE,
                NC_CREATE = WM_NCCREATE,
                NC_DESTROY = WM_NCDESTROY,
                NONE = WM_NULL,
                PAINT = WM_PAINT,
                QUERY_DRAG_ICON = WM_QUERYDRAGICON,
                QUERY_OPEN = WM_QUERYOPEN,
                QUIT = WM_QUIT,
                SET_ICON = WM_SETICON,
                SHOW_WINDOW = WM_SHOWWINDOW,
                SIZE = WM_SIZE,
                SIZING = WM_SIZING,
                STYLE_CHANGED = WM_STYLECHANGED,
                STYLE_CHANGING = WM_STYLECHANGING,
                THEME_CHANGED = 0x031A,
                TIMER = WM_TIMER,
                USER_CHANGED = WM_USERCHANGED,
                WINDOW_POSITION_CHANGED = WM_WINDOWPOSCHANGED,
                WINDOW_POSITION_CHANGING = WM_WINDOWPOSCHANGING
            };
        }
        namespace ListBoxMessages {
            enum {
                ADD_FILE = LB_ADDFILE,
                ADD_STRING = LB_ADDSTRING,
                DELETE_STRING = LB_DELETESTRING,
                DIRECTORY = LB_DIR,
                FIND_STRING = LB_FINDSTRING,
                FIND_STRING_EXACT = LB_FINDSTRINGEXACT,
                GET_ANCHOR_INDEX = LB_GETANCHORINDEX,
                GET_CARET_INDEX = LB_GETCARETINDEX,
                GET_COUNT = LB_GETCOUNT,
                GET_CURRENT_INDEX = LB_GETCURSEL,
                GET_HORIZONTAL_EXTENT = LB_GETHORIZONTALEXTENT,
                GET_ITEM_DATA = LB_GETITEMDATA,
                GET_ITEM_HEIGHT = LB_GETITEMHEIGHT,
                GET_ITEM_RECT = LB_GETITEMRECT,
                GET_LISTBOX_INFO = 0x01B2,
                GET_LOCALE = LB_GETLOCALE,
                GET_SELECTION = LB_GETSEL,
                GET_SELECTION_COUNT = LB_GETSELCOUNT,
                GET_SELECTION_ITEMS = LB_GETSELITEMS,
                GET_TEXT = LB_GETTEXT,
                GET_TEXT_LENGTH = LB_GETTEXTLEN,
                GET_TOP_INDEX = LB_GETTOPINDEX,
                INIT_STORAGE = LB_INITSTORAGE,
                INSERT_STRING = LB_INSERTSTRING,
                ITEM_FROM_POINT = LB_ITEMFROMPOINT,
                RESET_CONTENT = LB_RESETCONTENT,
                SELECT_STRING = LB_SELECTSTRING,
                SELECT_ITEM_RANGE = LB_SELITEMRANGE,
                SELECT_ITEM_RANGE_X = LB_SELITEMRANGEEX,
                SET_ANCHOR_INDEX = LB_SETANCHORINDEX,
                SET_CARET_INDEX = LB_SETCARETINDEX,
                SET_COLUMN_WIDTH = LB_SETCOLUMNWIDTH,
                SET_COUNT = LB_SETCOUNT,
                SET_CURRENT_SELECTION = LB_SETCURSEL,
                SET_HORIZONTAL_INDEX = LB_SETHORIZONTALEXTENT,
                SET_ITEM_DATA = LB_SETITEMDATA,
                SET_ITEM_HEIGHT = LB_SETITEMHEIGHT,
                SET_LOCALE = LB_SETLOCALE,
                SET_SELECTION_INDEX = LB_SETSEL,
                SET_TAB_STOPS = LB_SETTABSTOPS,
                SET_TOP_INDEX = LB_SETTOPINDEX
            };
        }
        struct ClassNames {
            static CON_WSTR LISTVIEW;// = L"SysListView32";//WC_LISTVIEW;
            static CON_WSTR BUTTON;// = L"Button";//WC_BUTTON;
            static CON_WSTR LISTBOX;// = L"ListBox";//WC_LISTBOX;
        };
        namespace ListViewMessages {
            enum {
                //solo posible en 64 bits
                ITEM_CHANGED = 4294967195//LVN_ITEMCHANGED
            };
        }
    #ifdef WINCAPE_USES_WGL
        namespace PixelFormatFlags {
            enum {
                DRAW_TO_WINDOW  = PFD_DRAW_TO_WINDOW,
                DRAW_TO_BITMAP = PFD_DRAW_TO_BITMAP,
                SUPPORT_GDI = PFD_SUPPORT_GDI,
                SUPPORT_OPENGL = PFD_SUPPORT_OPENGL,
                GENERIC_ACCELERATED = PFD_GENERIC_ACCELERATED,
                GENERIC_FORMAT = PFD_GENERIC_FORMAT,
                NEED_PALETTE = PFD_NEED_PALETTE,
                NEED_SYSTEM_PALETTE = PFD_NEED_SYSTEM_PALETTE,
                DOUBLE_BUFFER = PFD_DOUBLEBUFFER,
                STEREO = PFD_STEREO,
                SWAP_LAYER_BUFFERS = PFD_SWAP_LAYER_BUFFERS
            };
        }
        namespace PixelFormatTypes {
            enum {
                RGBA,
                COLOX_INDEX
            };
        }
        namespace PixelFormatLayers {
            enum {
                MAIN_PLANE
            };
        }
    #endif
        namespace DrawTextFormats{
            enum {
                BOTTOM = DT_BOTTOM,
                CALCULATE_RECTANGLE = DT_CALCRECT,
                HORIZONTAL_CENTER = DT_CENTER,
                EDIT_CONTROL = DT_EDITCONTROL,
                END_ELLIPSIS = DT_END_ELLIPSIS,
                EXPAND_TABS = DT_EXPANDTABS,
                EXTERNAL_LEADING = DT_EXTERNALLEADING,
                HIDE_PREFIX = DT_HIDEPREFIX,
                INTERNAL = DT_INTERNAL,
                LEFT = DT_LEFT,
                MODIFY_STRING = DT_MODIFYSTRING,
                NO_CLIP = DT_NOCLIP,
                NO_FULL_WIDTH_CHAR_BREAK = DT_NOFULLWIDTHCHARBREAK,
                NO_PREFIX = DT_NOPREFIX,
                PATH_ELLIPSIS = DT_PATH_ELLIPSIS,
                PREFIX_ONLY = DT_PREFIXONLY,
                RIGHT = DT_RIGHT,
                RIGHT_TO_LEFT_READING = DT_RTLREADING,
                SINGLE_LINE = DT_SINGLELINE ,
                TAB_STOP = DT_TABSTOP,
                TOP = DT_TOP,
                VERTICAL_CENTER = DT_VCENTER,
                WORD_BREAK = DT_WORDBREAK,
                WORD_ELLIPSIS = DT_WORD_ELLIPSIS
            };
        }
        namespace LayeredWindowAttributes{
            enum {
                ALPHA = 0x00000002,
                COLOR_KEY = 0x00000001
            };
        }
    }
}
#endif // GUI_/DEFINES_HPP
