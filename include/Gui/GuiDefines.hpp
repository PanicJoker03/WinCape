#ifndef GUI_DEFINES_HPP
#define GUI_DEFINES_HPP
#include "defines.hpp"
namespace WinCape{
    namespace Gui{

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
                Timer = WM_TIMER,
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
        struct ClassNames final {
            constexpr static const wchar_t* ListView = L"SysListView32";//WC_LISTVIEW;
            constexpr static const wchar_t* Button = L"Button";//WC_BUTTON;
            constexpr static const wchar_t* ListBox = L"ListBox";//WC_LISTBOX;
        };
        namespace ListViewMessages {
            enum : ListViewMessage {
                ItemChanged = LVN_ITEMCHANGED
            };
        }
    #ifdef WINCAPE_USES_WGL
        namespace PixelFormatFlags {
            enum : PixelFormatFlag{
                DrawToWindow  = PFD_DRAW_TO_WINDOW,
                DrawToBitmap = PFD_DRAW_TO_BITMAP,
                SupportGdi = PFD_SUPPORT_GDI,
                SupportOpengl = PFD_SUPPORT_OPENGL,
                GenericAccelerated = PFD_GENERIC_ACCELERATED,
                GenericFormat = PFD_GENERIC_FORMAT,
                NeedPalette = PFD_NEED_PALETTE,
                NeedSystemPalette = PFD_NEED_SYSTEM_PALETTE,
                DoubleBuffer = PFD_DOUBLEBUFFER,
                Stereo = PFD_STEREO,
                SwapLayerBuffers = PFD_SWAP_LAYER_BUFFERS
            };
        }
        namespace PixelFormatTypes {
            enum : PixelFormatType {
                RGBA,
                ColorIndex
            };
        }
        namespace PixelFormatLayers {
            enum : PixelFormatLayer {
                MainPlane
            };
        }
    #endif
        namespace DrawTextFormats{
            enum : DrawTextFormat {
                Bottom,
                CalculateRectangle,
                HorizontalCenter,
                EditControl,
                EndEllipsis,
                ExpandTabs,
                ExternalLeading,
                HidePrefix,
                Internal,
                Left,
                ModifyString,
                NoClip,
                NoFullWidthCharBreak,
                NoPrefix,
                PathEllipsis,
                PrefixOnly,
                Right,
                RightToLeftReading,
                SingleLine,
                TabStop,
                Top,
                VerticalCenter,
                WordBreak,
                WordEllipsis
            };
        }
        namespace LayeredWindowAttributes{
            enum : LayeredWindowAttribute {
                Alpha = LWA_ALPHA,
                ColorKey = LWA_COLORKEY
            };
        }
    }
}
#endif // GUI_/DEFINES_HPP
