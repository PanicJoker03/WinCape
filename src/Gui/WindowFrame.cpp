#include "Gui/WindowFrame.hpp"
#include "Application.hpp"
#include "Manager.hpp"
namespace WinCape::Gui
{
	//-------------------------------------------------------------------------
	//WindowFrame
	//-------------------------------------------------------------------------
	WindowFrame::WindowFrame(const TextChar* windowName, const TextChar* title,
		const Rect& rect, WindowStyle style)
		: windowName(windowName), rect(rect), style(style) {
		handle(Application::createWindow(
			windowName, title, rect, style).handle()
		);
		SendMessage(handle(), WindowMessages::Create, 0, 0);
	}
	void WindowFrame::onDraw(DeviceContext deviceContext) {}
	void WindowFrame::onDispose() {
		Manager::instance().unlistenEvent(handle(), WindowMessages::Paint);
		Manager::instance().unlistenEvent(handle(), WindowMessages::Destroy);
	}
	Gui::WindowFrame::~WindowFrame() {}

}
