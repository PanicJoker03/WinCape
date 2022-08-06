#include "defines.hpp"
#include "Gui/GuiDefines.hpp"
#include "Gui/GuiDefaults.hpp"
#include "Gui/Style.hpp"
namespace WinCape
{
    namespace Gui {
        const Rect Defaults::WindowRect = Rect( 100, 100, 800, 600 );

        const WindowStyle Defaults::DefWindowStyle =
                WindowStyles::OverlappedWindow ^ WindowStyles::ThickFrame;

        const ClassStyle Defaults::DefClassStyle  =
                ClassStyles::HorizontalRedraw | ClassStyles::VerticalRedraw;

        const ShowCommand Defaults::DefShowCommand =
                ShowCommands::ShowDefault;

        const wchar_t* Defaults::ButtonClassName = L"BUTTON";
        const Vector2I Defaults::ButtonSize = Vector2I( 80, 24 );
        const Vector2I Defaults::RadioButtonPadding = Vector2I( 0, 32 );

        const ButtonStyle Defaults::DefButtonStyle =
                WindowStyles::TabStop | WindowStyles::Visible |
                WindowStyles::Child | ButtonStyles::PushButton;

        const ButtonStyle Defaults::RadioButtonStyle =
                WindowStyles::TabStop | WindowStyles::Visible |
                WindowStyles::Child | ButtonStyles::AutoRadioButton;

        const int Defaults::ListViewMinColumnWidth = 50;
        const int Defaults::ListViewColumnWidth = 100;
#ifdef WINCAPE_USES_WGL
        const PixelFormat Defaults::DefPixelFormat = {
                PixelFormatFlags::DoubleBuffer |
                PixelFormatFlags::SupportOpengl |
                PixelFormatFlags::SwapLayerBuffers
        };
#endif
    }
}
