#include "defines.h"
#include "Ui/UiDefines.h"
#include "Ui/UiDefaults.h"
#include "Ui/Style.h"
namespace w_cape{
namespace ui {
    const CAPE_RECT Defaults::WINDOW_RECT = CAPE_RECT( 100, 100, 800, 600 );

    const WND_STY Defaults::DEFWINDOW_STYLE =
            WindowStyles::OVERLAPPED_WND ^ WindowStyles::THICK_FRAME;

    const CLLS_STY Defaults::DEFCLASS_STYLE  =
            ClassStyles::HOR_REDRAW | ClassStyles::VER_REDRAW;

    const SHW_CMD Defaults::DEFSHOW_COMMAND =
            ShowCommands::SHW_DEF;

    WCH_STR_CON Defaults::BUTTON_CLASS_NAME = L"BUTTON";
    const I_VEC_2 Defaults::BUTTON_SIZE = I_VEC_2( 80, 24 );
    const I_VEC_2 Defaults::RADIO_BUTTON_PADDING = I_VEC_2( 0, 32 );

    const BTN_STY Defaults::DEFBUTTON_STYLE =
            WindowStyles::TAB_STOP | WindowStyles::VISIBLE |
            WindowStyles::CHILD | ButtonStyles::PUSH_BTN;

    const BTN_STY Defaults::RADIO_BUTTON_STYLE =
            WindowStyles::TAB_STOP | WindowStyles::VISIBLE |
            WindowStyles::CHILD | ButtonStyles::AUT_RADIO_BTN;

    const int Defaults::LIST_VIEW_MIN_COLUMN_WIDTH = 50;
    const int Defaults::LIST_VIEW_COLUMN_WIDTH = 100;
#ifdef WINCAPE_USES_WGL
    const PIXEL_FORMAT Defaults::DEFPIXEL_FORMAT = {
            PixelFormatFlags::DOUBLE_BUFFER |
            PixelFormatFlags::SUPPORT_OPENGL |
            PixelFormatFlags::SWAP_LAYER_BUFFERS
    };
#endif
}}
