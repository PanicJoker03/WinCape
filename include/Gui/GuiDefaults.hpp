#ifndef GUI_DEFAULTS_HPP
#define GUI_DEFAULTS_HPP

#include "defines.hpp"
#include "GuiDefines.hpp"
#include "Style.hpp"
namespace WinCape{
namespace Gui {
    struct Defaults
    {
        static const Rect WINDOW_RECT;

        static const WindowStyle DEFWINDOW_STYLE;

        static const ClassStyle DEFCLASS_STYLE;

        static const ShowCommand DEFSHOW_COMMAND;

        static const wchar_t* BUTTON_CLASS_NAME;
        static const Vector2I BUTTON_SIZE;
        static const Vector2I RADIO_BUTTON_PADDING;

        static const ButtonStyle DEFBUTTON_STYLE;

        static const ButtonStyle RADIO_BUTTON_STYLE;

        static const int LIST_VIEW_MIN_COLUMN_WIDTH;
        static const int LIST_VIEW_COLUMN_WIDTH;
#ifdef WINCAPE_USES_WGL
        static const PixelFormat DEFPIXEL_FORMAT;
#endif
    };
}}
#endif // !GUI_DEFAULTS_HPP
