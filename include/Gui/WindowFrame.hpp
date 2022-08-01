#ifndef WINDOWFRAME_HPP
#define WINDOWFRAME_HPP
#include "defines.hpp"
#include "defaults.hpp"
#include "GuiDefaults.hpp"
#include "Window.hpp"
namespace WinCape{
	struct Application;
	namespace Gui{
		//////////////////////////
		//High level abstraction//
		//////////////////////////
		class WindowFrame : public Window
		{
		public:
			friend WinCape::Application;
		private:
			const wchar_t* windowName;
			const Rect rect;
			const WindowStyle style;
		protected:
			WindowFrame(const wchar_t* windowName = WinCape::Defaults::WindowName,
				const wchar_t* title = L"Default",
				const Rect& rect = Gui::Defaults::WindowRect,
				WindowStyle style = Gui::Defaults::DefWindowStyle
			);

			virtual void onCreate() = 0;
			virtual void onDraw(DeviceContext deviceContext) = 0;
			virtual void onDispose();
			virtual ~WindowFrame() = 0;
		};
	}
}
#endif
