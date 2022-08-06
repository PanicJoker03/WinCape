#ifndef GUI_DEFAULTS_HPP
#define GUI_DEFAULTS_HPP

#include "defines.hpp"
#include "GuiDefines.hpp"
#include "Style.hpp"
namespace WinCape
{
    namespace Gui {
        struct Defaults
        {
            static const Rect WindowRect;

            static const WindowStyle DefWindowStyle;

            static const ClassStyle DefClassStyle;

            static const ShowCommand DefShowCommand;

            static const wchar_t* ButtonClassName;
            static const Vector2I ButtonSize;
            static const Vector2I RadioButtonPadding;

            static const ButtonStyle DefButtonStyle;

            static const ButtonStyle RadioButtonStyle;

            static const int ListViewMinColumnWidth;
            static const int ListViewColumnWidth;
    #ifdef WINCAPE_USES_WGL
            static const PixelFormat DefPixelFormat;
    #endif
        };
    }
}
#endif // !GUI_DEFAULTS_HPP
