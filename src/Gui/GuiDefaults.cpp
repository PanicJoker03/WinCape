#include "defines.hpp"
#include "Gui/GuiDefines.hpp"
#include "Gui/GuiDefaults.hpp"
#include "Gui/Style.hpp"
namespace wcape{
namespace usr {
    const CAPE_RECT Defaults::WINDOW_RECT = CAPE_RECT( 100, 100, 800, 600 );

    const WND_STY Defaults::DEFWINDOW_STYLE =
            WindowStyles::OVERLAPPED_WINDOW ^ WindowStyles::THICK_FRAME;

    const CLLS_STY Defaults::DEFCLASS_STYLE  =
            ClassStyles::HORIZONTAL_REDRAW | ClassStyles::VERTICAL_REDRAW;

    const SHW_CMD Defaults::DEFSHOW_COMMAND =
            ShowCommands::SHOW_DEFAULT;

    WSTR_CON Defaults::BUTTON_CLASS_NAME = L"BUTTON";
    const VEC_2I Defaults::BUTTON_SIZE = VEC_2I( 80, 24 );
    const VEC_2I Defaults::RADIO_BUTTON_PADDING = VEC_2I( 0, 32 );

    const BTN_STY Defaults::DEFBUTTON_STYLE =
            WindowStyles::TAB_STOP | WindowStyles::VISIBLE |
            WindowStyles::CHILD | ButtonStyles::PUSH_BUTTON;

    const BTN_STY Defaults::RADIO_BUTTON_STYLE =
            WindowStyles::TAB_STOP | WindowStyles::VISIBLE |
            WindowStyles::CHILD | ButtonStyles::AUTO_RADIO_BUTTON;

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
