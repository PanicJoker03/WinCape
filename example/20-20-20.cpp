//NOT YET TESTED ON C++98 BUILDS!!!!
/*
//Tested on CodeBlocks on Cygwin
int main() {
    	const wchar_t* texto = L"Ya pasaron 20 Minutos";
	WinCape::Application::init();
	Gui::Window wnd = WinCape::Application::createWindow(L"Pruebas", L"Reglas 20-20-20", Rect{400, 400, 300, 200}, WindowStyles::DialogFrame);
	wnd.hide();

	Gui::DeviceContext dc = wnd.deviceContext();

	wnd.onPaint([&](Event e){
		DrawTextFormat textFormat = DrawTextFormats::SingleLine | DrawTextFormats::HorizontalCenter | DrawTextFormats::VerticalCenter;
		dc.drawText(texto, textFormat);
	});
	Gui::Button ok;
	wnd.addButton(ok, L"Ok", Vector2I{100, 100});
	ok.onClick([&](Event e){
		wnd.hide();
	});
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
	wnd.timer([&](Event e){
		wnd.show();
	}, 1200000);
	WinCape::Application::run();
	return 0;
}
*/
