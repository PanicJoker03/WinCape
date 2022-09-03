#include "Gui/WindowFrame.hpp"
#include "Application.hpp"
#include "Gui/Manager.hpp"
namespace cape{
namespace usr
{
	//-------------------------------------------------------------------------
	//WindowFrame
	//-------------------------------------------------------------------------
	WindowFrame::WindowFrame(CON_WSTR windowName, CON_WSTR title,
		const CAPE_RECT& rect, WND_STY style)
		: windowName(windowName), rect(rect), style(style) {
		handle(Application::createWindow(
			windowName, title, rect, style).handle()
		);
		SendMessage(handle(), WindowMessages::CREATE, 0, 0);
	}
	void WindowFrame::onDraw(DeviceContext deviceContext) {}
	void WindowFrame::onDispose() {
		usr::Manager::instance().unlistenEvent(handle(), WindowMessages::PAINT);
		usr::Manager::instance().unlistenEvent(handle(), WindowMessages::DESTROY);
	}
	usr::WindowFrame::~WindowFrame() {}
}}
