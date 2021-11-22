//============================================================================
// Name        : Experiments.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <WinCape.hpp>
#include <iostream>
using namespace WinCape;
Gui::Window wnd;
int vecesMostrado = 0;
const TextChar* texto20Mins = "Ya pasaron 20 minutos, tiempo de descansar la vista";
const TextChar* texto60Mins = "Ya pasó una hora... hora de hacer estiramientos";
const TextChar* texto = texto20Mins;
void ShowWindow(){
	vecesMostrado++;
	if(vecesMostrado % 3 == 0){
		texto = texto60Mins;
	}
	else{
		texto = texto20Mins;
	}
	wnd.show();
}

int main() {

	WinCape::Application::init();
	wnd = WinCape::Application::createWindow(Text("Ele Pruebas"), Text("Reglas 20-20-20"), Rect{400, 400, 300, 200}, WindowStyles::DialogFrame);
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
	wnd.addButton(ok, Text("Ok"), Vector2I{100, 100});
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