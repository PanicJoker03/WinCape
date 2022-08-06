#include "Gui/WindowFrame.hpp"
#include "Application.hpp"
#include "Gui/Manager.hpp"
namespace WinCape::Gui
{
	//-------------------------------------------------------------------------
	//WindowFrame
	//-------------------------------------------------------------------------
	WindowFrame::WindowFrame(const wchar_t* windowName, const wchar_t* title,
		const Rect& rect, WindowStyle style)
		: windowName(windowName), rect(rect), style(style) {
		handle(Application::createWindow(
			windowName, title, rect, style).handle()
		);
		SendMessage(handle(), WindowMessages::Create, 0, 0);
	}
	void WindowFrame::onDraw(DeviceContext deviceContext) {}
	void WindowFrame::onDispose() {
		Gui::Manager::instance().unlistenEvent(handle(), WindowMessages::Paint);
		Gui::Manager::instance().unlistenEvent(handle(), WindowMessages::Destroy);
	}
	Gui::WindowFrame::~WindowFrame() {}

}
