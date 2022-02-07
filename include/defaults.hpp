#ifndef DEFAULTS_HPP
#define DEFAULTS_HPP

#include "defines.hpp"
namespace WinCape
{
	struct Defaults
	{
		static constexpr const TextChar* WindowName = Text("WinCape Window");
		static constexpr Rect WindowRect = Rect{ 100, 100, 800, 600 };

		static constexpr WindowStyle DefWindowStyle =
				WindowStyles::OverlappedWindow ^ WindowStyles::ThickFrame;

		static constexpr ClassStyle DefClassStyle  =
				ClassStyles::HorizontalRedraw | ClassStyles::VerticalRedraw;

		static constexpr ShowCommand DefShowCommand =
				ShowCommands::ShowDefault;

		static constexpr const TextChar* ButtonClassName = Text("BUTTON");
		static constexpr Vector2I ButtonSize = Vector2I{ 80, 24 };
		static constexpr Vector2I RadioButtonPadding = Vector2I{ 0, 32 };

		static constexpr ButtonStyle DefButtonStyle =
				WindowStyles::TabStop | WindowStyles::Visible |
				WindowStyles::Child | ButtonStyles::PushButton;

		static constexpr ButtonStyle RadioButtonStyle =
				WindowStyles::TabStop | WindowStyles::Visible |
				WindowStyles::Child | ButtonStyles::AutoRadioButton;
#ifdef WINCAPE_USES_WGL
		static constexpr PixelFormat DefPixelFormat = {
				PixelFormatFlags::DoubleBuffer |
				PixelFormatFlags::SupportOpengl |
				PixelFormatFlags::SwapLayerBuffers
		};
#endif
	};
}
#endif // !DEFAULTS_HPP
