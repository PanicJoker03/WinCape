#ifndef GUI_DEFAULTS_HPP
#define GUI_DEFAULTS_HPP

#include "defines.hpp"
#include "GuiDefines.hpp"
#include "Style.hpp"
namespace w_cape{
namespace ui {
    struct Defaults
    {
        static const CAPE_RECT WINDOW_RECT;

        static const WND_STY DEFWINDOW_STYLE;

        static const CLLS_STY DEFCLASS_STYLE;

        static const SHW_CMD DEFSHOW_COMMAND;

        static WSTR_CON BUTTON_CLASS_NAME;
        static const VEC_2I BUTTON_SIZE;
        static const VEC_2I RADIO_BUTTON_PADDING;

        static const BTN_STY DEFBUTTON_STYLE;

        static const BTN_STY RADIO_BUTTON_STYLE;

        static const int LIST_VIEW_MIN_COLUMN_WIDTH;
        static const int LIST_VIEW_COLUMN_WIDTH;
#ifdef WINCAPE_USES_WGL
        static const PIXEL_FORMAT DEFPIXEL_FORMAT;
#endif
    };
}}
#endif // !GUI_DEFAULTS_HPP
