#include "Gui/WindowFrame.hpp"
#include "Application.hpp"
#include "Gui/Manager.hpp"
namespace wcape{
namespace usr
{
	//-------------------------------------------------------------------------
	//WindowFrame
	//-------------------------------------------------------------------------
	WindowFrame::WindowFrame(WSTR_CON windowName, WSTR_CON title,
		const CAPE_RECT& rect, WND_STY style)
		: windowName(windowName), rect(rect), style(style) {
		handle(application.createWindow(
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
