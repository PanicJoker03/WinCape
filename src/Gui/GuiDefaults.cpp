#include "defines.hpp"
#include "Gui/GuiDefines.hpp"
#include "Gui/GuiDefaults.hpp"
#include "Gui/Style.hpp"
namespace WinCape{
namespace Gui {
    const Rect Defaults::WINDOW_RECT = Rect( 100, 100, 800, 600 );

    const WindowStyle Defaults::DEFWINDOW_STYLE =
            WindowStyles::OVERLAPPED_WINDOW ^ WindowStyles::THICK_FRAME;

    const ClassStyle Defaults::DEFCLASS_STYLE  =
            ClassStyles::HORIZONTAL_REDRAW | ClassStyles::VERTICAL_REDRAW;

    const ShowCommand Defaults::DEFSHOW_COMMAND =
            ShowCommands::SHOW_DEFAULT;

    const wchar_t* Defaults::BUTTON_CLASS_NAME = L"BUTTON";
    const Vector2I Defaults::BUTTON_SIZE = Vector2I( 80, 24 );
    const Vector2I Defaults::RADIO_BUTTON_PADDING = Vector2I( 0, 32 );

    const ButtonStyle Defaults::DEFBUTTON_STYLE =
            WindowStyles::TAB_STOP | WindowStyles::VISIBLE |
            WindowStyles::CHILD | ButtonStyles::PUSH_BUTTON;

    const ButtonStyle Defaults::RADIO_BUTTON_STYLE =
            WindowStyles::TAB_STOP | WindowStyles::VISIBLE |
            WindowStyles::CHILD | ButtonStyles::AUTO_RADIO_BUTTON;

    const int Defaults::LIST_VIEW_MIN_COLUMN_WIDTH = 50;
    const int Defaults::LIST_VIEW_COLUMN_WIDTH = 100;
#ifdef WINCAPE_USES_WGL
    const PixelFormat Defaults::DEFPIXEL_FORMAT = {
            PixelFormatFlags::DOUBLE_BUFFER |
            PixelFormatFlags::SUPPORT_OPENGL |
            PixelFormatFlags::SWAP_LAYER_BUFFERS
    };
#endif
}}
