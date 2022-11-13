#include "Ui/WindowFrame.hpp"
#include "Application.hpp"
#include "Ui/Manager.hpp"
namespace w_cape{
namespace ui
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
		SendMessage(handle(), WindowMessages::CRAT, 0, 0);
	}
	void WindowFrame::onDraw(DeviceContext deviceContext) {}
	void WindowFrame::onDispose() {
		ui::Manager::instance().unlistenEvent(handle(), WindowMessages::PINT);
		ui::Manager::instance().unlistenEvent(handle(), WindowMessages::D_TROY);
	}
	ui::WindowFrame::~WindowFrame() {}
}}
