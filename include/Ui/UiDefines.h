#ifndef UI_DEFINES_H
#define UI_DEFINES_H
#include "defines.h"
namespace w_cape{
    namespace ui{

      namespace ShowCommands {
            enum : SHW_CMD
            {
                FOR_MIN = 11,
                HIDE = SW_HIDE,
                MAXI = SW_MAXIMIZE,
                MINI = SW_MINIMIZE,
                STOR = SW_RESTORE,
                SHOW = SW_SHOW,
                SHW_DEF = SW_SHOWDEFAULT,
                SHW_MAX = SW_SHOWMAXIMIZED,
                SHW_MIN = SW_SHOWMINIMIZED,
                SHW_MIN_NO_ACT = SW_SHOWMINNOACTIVE,
                SHW_NA = SW_SHOWNA,
                SHW_NO_ACT = SW_SHOWNOACTIVATE,
                SHW_NRM = SW_SHOWNORMAL
            };
        }
        namespace WindowMessages {
            enum : WND_MSG
            {
                //Notifications
                ACT_APP = WM_ACTIVATEAPP,
                CNL_MOD = WM_CANCELMODE,
                CHL_ACT = WM_CHILDACTIVATE,
                CLOS = WM_CLOSE,
                CMD = WM_COMMAND,
                COMP = WM_COMPACTING,
                CRAT = WM_CREATE,
                D_TROY = WM_DESTROY,
                DOT_PER_NCH_CHD = 0x02E0,
                ENBL = WM_ENABLE,
                ETR_SZE_MOV = WM_ENTERSIZEMOVE,
                EXI_SZE_MOV = WM_EXITSIZEMOVE,
                GET_ICO = WM_GETICON,
                GET_MIN_MAX_INF = WM_GETMINMAXINFO,
                INP_LAG_CHG = WM_INPUTLANGCHANGE,
                INP_LAN_CHG_REQ = WM_INPUTLANGCHANGEREQUEST,
                MNU_CMD = 0x0126,
                MNU_SEL = WM_MENUSELECT,
                MOVE = WM_MOVE,
                MOVG = WM_MOVING,
                NC_ACT = WM_NCACTIVATE,
                NC_CAL_SZE = WM_NCCALCSIZE,
                NC_CRT = WM_NCCREATE,
                NC_DST = WM_NCDESTROY,
                NONE = WM_NULL,
                PINT = WM_PAINT,
                QRY_DRG_ICO = WM_QUERYDRAGICON,
                QRY_OPN = WM_QUERYOPEN,
                QTT = WM_QUIT,
                SET_ICO = WM_SETICON,
                SHW_WND = WM_SHOWWINDOW,
                SIZE = WM_SIZE,
                SIZG = WM_SIZING,
                STY_CHA = WM_STYLECHANGED,
                STY_CHG = WM_STYLECHANGING,
                THM_CHD = 0x031A,
                TIME = WM_TIMER,
                USR_CHD = WM_USERCHANGED,
                WND_POS_CHA = WM_WINDOWPOSCHANGED,
                WND_POS_CHG = WM_WINDOWPOSCHANGING
            };
        }
        namespace ListBoxMessages {
            enum : LSB_MSG {
                ADD_FLL = LB_ADDFILE,
                ADD_STR = LB_ADDSTRING,
                DEL_STR = LB_DELETESTRING,
                DIR = LB_DIR,
                FND_STR = LB_FINDSTRING,
                FND_STR_XCT = LB_FINDSTRINGEXACT,
                GET_ANC_IDX = LB_GETANCHORINDEX,
                GET_CAR_IDX = LB_GETCARETINDEX,
                GET_CONT = LB_GETCOUNT,
                GET_CUR_IDX = LB_GETCURSEL,
                GET_HOR_EXT = LB_GETHORIZONTALEXTENT,
                GET_ITM_DAT = LB_GETITEMDATA,
                GET_ITM_HGT = LB_GETITEMHEIGHT,
                GET_ITM_REC = LB_GETITEMRECT,
                GET_LBX_INF = 0x01B2,
                GET_LOC = LB_GETLOCALE,
                GET_SEL = LB_GETSEL,
                GET_SEL_CNT = LB_GETSELCOUNT,
                GET_SEL_ITM = LB_GETSELITEMS,
                GET_TXT = LB_GETTEXT,
                GET_TXT_LEN = LB_GETTEXTLEN,
                GET_TOP_IDX = LB_GETTOPINDEX,
                INI_STG = LB_INITSTORAGE,
                INS_STR = LB_INSERTSTRING,
                ITM_FRM_PNT = LB_ITEMFROMPOINT,
                RST_CNT = LB_RESETCONTENT,
                SEL_STRING = LB_SELECTSTRING,
                SEL_ITM_RAN = LB_SELITEMRANGE,
                SEL_ITM_RAN_X = LB_SELITEMRANGEEX,
                SET_ANC_IDX = LB_SETANCHORINDEX,
                SET_CAR_IDX = LB_SETCARETINDEX,
                SET_COL_WID = LB_SETCOLUMNWIDTH,
                SET_CNT = LB_SETCOUNT,
                SET_CUR_SEL = LB_SETCURSEL,
                SET_HOR_IDX = LB_SETHORIZONTALEXTENT,
                SET_ITM_DTT = LB_SETITEMDATA,
                SET_ITM_HEG = LB_SETITEMHEIGHT,
                SET_LLE = LB_SETLOCALE,
                SET_SEL_IDX = LB_SETSEL,
                SET_TAB_STO = LB_SETTABSTOPS,
                SET_TOP_IDX = LB_SETTOPINDEX
            };
        }
        struct ClassNames {
            static WCH_STR_CONST LST_VIW;// = L"SysListView32";//WC_LISTVIEW;
            static WCH_STR_CONST BTN;// = L"Button";//WC_BUTTON;
            static WCH_STR_CONST LST_BOX;// = L"ListBox";//WC_LISTBOX;
        };
        namespace ListViewMessages {
            enum : LVW_MSG {
                //solo posible en 64 bits
                ITM_CHA = 4294967195//LVN_ITEMCHANGED
            };
        }
    #ifdef WINCAPE_USES_WGL
        namespace PixelFormatFlags {
            enum : PXF_FLG {
                DRW_TO_WND  = PFD_DRAW_TO_WINDOW,
                DRW_TO_BMP = PFD_DRAW_TO_BITMAP,
                SUP_GDI = PFD_SUPPORT_GDI,
                SUP_OGL = PFD_SUPPORT_OPENGL,
                GEN_ACC = PFD_GENERIC_ACCELERATED,
                GEN_FMT = PFD_GENERIC_FORMAT,
                NED_PAL = PFD_NEED_PALETTE,
                NED_SYS_PAL = PFD_NEED_SYSTEM_PALETTE,
                DOB_BUF = PFD_DOUBLEBUFFER,
                STER = PFD_STEREO,
                SWP_LYR_BUF = PFD_SWAP_LAYER_BUFFERS
            };
        }
        namespace PixelFormatTypes {
            enum : PXF_TPE {
                RGBA,
                CLR_IDX
            };
        }
        namespace PixelFormatLayers {
            enum : PXF_LYR {
                MNN_PLN
            };
        }
    #endif
        namespace DrawTextFormats{
            enum : DRW_TXT_4MAT {
                BOTM = DT_BOTTOM,
                CAL_RCT = DT_CALCRECT,
                HOR_CEN = DT_CENTER,
                EDT_CTL = DT_EDITCONTROL,
                END_ELS = DT_END_ELLIPSIS,
                EXP_TAB = DT_EXPANDTABS,
                EXT_LED = DT_EXTERNALLEADING,
                HDE_PFX = DT_HIDEPREFIX,
                INTR = DT_INTERNAL,
                LEFT = DT_LEFT,
                MOD_STR = DT_MODIFYSTRING,
                NO_CLP = DT_NOCLIP,
                NO_FUL_WID_CHR_BRK = DT_NOFULLWIDTHCHARBREAK,
                NO_PFX = DT_NOPREFIX,
                PTH_ELS = DT_PATH_ELLIPSIS,
                PFX_NLY = DT_PREFIXONLY,
                RGH = DT_RIGHT,
                RGH_TO_LEF_RDG = DT_RTLREADING,
                SNG_LIN = DT_SINGLELINE ,
                TAB_STP = DT_TABSTOP,
                TOP = DT_TOP,
                VER_CEN = DT_VCENTER,
                WRD_BRK = DT_WORDBREAK,
                WRD_ELS = DT_WORD_ELLIPSIS
            };
        }
        namespace LayeredWindowAttributes{
            enum : LYR_WND_ATR {
                ALPH = 0x00000002,
                CLR_KEY = 0x00000001
            };
        }
    }
}
#endif // GUI_/DEFINES_H
