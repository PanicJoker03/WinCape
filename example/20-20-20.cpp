//20-20-20 rule app
#include <windows.h>
#include <WinCape.hpp>

using namespace cape;

CON_WSTR TEXTO_20_MINS = L"Ya pasaron 20 Minutos";
usr::Window wnApp;
usr::DeviceContext dcWnd;

//Callback functions
void wnApp_OnPaint(EVENT e);
void btOk_OnClick(EVENT e);
void wnApp_OnTimer(EVENT e);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
	//Call this to initiate some WinCape internal stuff
	cape::Application::init();
	
	//Creating the app main window
	wnApp = cape::Application::createWindow(
		L"Pruebas", 
		L"Reglas 20-20-20", 
		CAPE_RECT(400, 400, 300, 200), 
		WindowStyles::DIALOG_FRAME
	);
	
	//Hiding window that holds message
	wnApp.hide();

	//Retrieving the main window device context
	dcWnd = wnApp.deviceContext();

	//setting up controls and callbacks
	wnApp.onPaint(wnApp_OnPaint);
	usr::Button btOk;
	wnApp.addButton(btOk, L"Ok", VEC_2I(100, 100));
	btOk.onClick(btOk_OnClick);
	wnApp.timer(wnApp_OnTimer, 1200000);
	
	//Finally run the main loop
	cape::Application::run();
	
	//exit ok
	return 0;
}

void wnApp_OnPaint(EVENT e){
	DRW_TXT_FMAT txFormat = 
		usr::DrawTextFormats::SINGLE_LINE | 
		usr::DrawTextFormats::HORIZONTAL_CENTER | 
		usr::DrawTextFormats::VERTICAL_CENTER;
	dcWnd.drawText(TEXTO_20_MINS, txFormat);
}

void btOk_OnClick(EVENT e){
	wnApp.hide();
}

void wnApp_OnTimer(EVENT e){
	wnApp.show();
}
