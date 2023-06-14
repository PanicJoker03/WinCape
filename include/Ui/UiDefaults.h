#ifndef UI_DEFAULTS_H
#define UI_DEFAULTS_H

#include "defines.h"
#include "UiDefines.h"
#include "Style.h"
namespace w_cape{
namespace ui {
    struct Defaults
    {
        static const CAPE_RECT WINDOW_RECT;

        static const WND_STY DEFWINDOW_STYLE;

        static const CLLS_STY DEFCLASS_STYLE;

        static const SHW_CMD DEFSHOW_COMMAND;

        static WCH_STR_CONST BUTTON_CLASS_NAME;
        static const I_VEC_2 BUTTON_SIZE;
        static const I_VEC_2 RADIO_BUTTON_PADDING;

        static const BTN_STY DEFBUTTON_STYLE;

        static const BTN_STY RADIO_BUTTON_STYLE;

        static const int LIST_VIEW_MIN_COLUMN_WIDTH;
        static const int LIST_VIEW_COLUMN_WIDTH;
#ifdef WINCAPE_USES_WGL
        static const PIXEL_FORMAT DEFPIXEL_FORMAT;
#endif
    };
}}
#endif // !GUI_DEFAULTS_H
