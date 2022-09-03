//NOT TESTED YET ON C++98 BUILDS
/*
#define _ENABLE_THEME
#include "WinCape.hpp"
#include <iostream>
using namespace cape;
struct Pixel32 { std::uint8_t b, g, r, offset = 0; };
class MyWindow : public usr::WindowFrame
{
private:
	usr::Menu menu;
	usr::Menu fileMenu;
	usr::Button buttonA;
	usr::Button buttonB;
	usr::RadioButton radioButtonA;
	usr::RadioButton radioButtonB;
	usr::RadioButton radioButtonC;
	usr::Bitmap image;
	std::vector<Pixel32> buffer;
public:
	MyWindow() : usr::WindowFrame(L"Wincape Test", L"Ventana", CAPE_RECT{120,120, 640, 480}) {}
private:
	void MyWindow::onCreate() override
	{
		show();
		//Setup window
		usr::Menu::create(menu);
		usr::Menu::create(fileMenu);
		fileMenu.addItems({ L"Abrir imagen", L"Guardar imagen", L"Salir"});
		menu.addSubMenu(fileMenu, L"Archivo");
		attachMenu(menu);
		addButton(buttonA, L"Bot�n", VEC_2I{ 100, 100 });
		addButton(buttonB, L"Test", VEC_2I{ 140, 140 });
		addRadioButton(
			{
				{ radioButtonA, L"radio 1" },
				{ radioButtonB, L"radio 2" },
				{ radioButtonC, L"radio 3" }
			},
			VEC_2I{ 200,200 }
		);
		//Loading the image...
		image.load(L"c:\\Users\\w7\\Pictures\\chrono.bmp");
		buffer.resize(image.dimension().x * image.dimension().y);
		//Event listening
		buttonA.onClick([&](EVENT e) {this->onButtonAClick(e);});
		buttonB.onClick([&](EVENT e) {this->onButtonBClick(e);});
		radioButtonA.onClick([&](EVENT e) {this->onRadioButtonAClick(e);});
		fileMenu.onItemSelect([&](EVENT e) {this->onFileMenuSelect(e); });
	}
	void MyWindow::onDraw(usr::DeviceContext& deviceContext) override
	{
		image.clonePixels(&buffer[0]);
		for (auto& pixel : buffer)
		{
			pixel.b += 4;
		}
		image.setPixels(&buffer[0]);
		deviceContext.drawBitmap(image);
	}
	void onButtonAClick(EVENT e)
	{
		minimize();
	}
	void onButtonBClick(EVENT e)
	{
		radioButtonB.setText(L"Poof!");
	}
	void onRadioButtonAClick(EVENT e)
	{
		radioButtonA.setText(L"Me haz clickeado t�o!");
		redraw();
	}
	void onFileMenuSelect(EVENT e)
	{
		int index = e.wparam;
		if (index == 2)
			close();
	}
};
//For console main
int main() {
	Application::init();
	//Setup font
	//TODO... font class wrapper...
	Application::defaultFont(L"Segoe UI");
	//Beginning to run the application...
	//Also add a 'font' param to default controls font style?
	MyWindow myWindow;
	Application::run(myWindow);
	return 0;
}
//For Win32 Api main
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	//Setup font
//	//TODO... font class wrapper...
//	Application::defaultFont(L"Segoe UI");
//	//Beginning to run the application...
//	//Also add a 'font' param to default controls font style?
//	MyWindow myWindow;
//	Application::run(myWindow);
//}

*/
