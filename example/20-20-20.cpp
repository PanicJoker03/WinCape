//20-20-20 rule app
#include <windows.h>
#include <WinCape.hpp>

using namespace WinCape;

const wchar_t* TEXTO_20_MINS = L"Ya pasaron 20 Minutos";
Gui::Window wnApp;
Gui::DeviceContext dcWnd;

//Callback functions
void wnApp_OnPaint(Event e);
void btOk_OnClick(Event e);
void wnApp_OnTimer(Event e);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
	//Call this to initiate some WinCape internal stuff
	WinCape::Application::init();
	
	//Creating the app main window
	wnApp = WinCape::Application::createWindow(
		L"Pruebas", 
		L"Reglas 20-20-20", 
		Rect(400, 400, 300, 200), 
		WindowStyles::DIALOG_FRAME
	);
	
	//Hiding window that holds message
	wnApp.hide();

	//Retrieving the main window device context
	dcWnd = wnApp.deviceContext();

	//setting up controls and callbacks
	wnApp.onPaint(wnApp_OnPaint);
	Gui::Button btOk;
	wnApp.addButton(btOk, L"Ok", Vector2I(100, 100));
	btOk.onClick(btOk_OnClick);
	wnApp.timer(wnApp_OnTimer, 1200000);
	
	//Finally run the main loop
	WinCape::Application::run();
	
	//exit ok
	return 0;
}

void wnApp_OnPaint(Event e){
	DrawTextFormat txFormat = 
		Gui::DrawTextFormats::SINGLE_LINE | 
		Gui::DrawTextFormats::HORIZONTAL_CENTER | 
		Gui::DrawTextFormats::VERTICAL_CENTER;
	dcWnd.drawText(TEXTO_20_MINS, txFormat);
}

void btOk_OnClick(Event e){
	wnApp.hide();
}

void wnApp_OnTimer(Event e){
	wnApp.show();
}
