
/*
int main() {

	WinCape::Application::init();
	wnd = WinCape::Application::createWindow(L"Ele Pruebas", L"Reglas 20-20-20", Rect{400, 400, 300, 200}, WindowStyles::DialogFrame);
	wnd.hide();

	Gui::DeviceContext dc = wnd.deviceContext();
	std::cout << dc.handle() << std::endl;
	std::cout << dc.bounds().position.x << std::endl;
	std::cout << dc.bounds().position.y << std::endl;
	std::cout << dc.bounds().size.x << std::endl;
	std::cout << dc.bounds().size.y << std::endl;
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
		ShowWindow();
	}, 1200000);
	WinCape::Application::run();
	return 0;
}
*/
