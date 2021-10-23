#define _ENABLE_THEME
#include "WinCape.hpp"
#include <iostream>
using namespace WinCape;
struct Pixel32 { std::uint8_t b, g, r, offset = 0; };
class MyWindow : public WindowFrame
{
private:
	Menu menu;
	Menu fileMenu;
	Button buttonA;
	Button buttonB;
	RadioButton radioButtonA;
	RadioButton radioButtonB;
	RadioButton radioButtonC;
	Bitmap image;
	std::vector<Pixel32> buffer;
public:
	MyWindow() : WindowFrame(Text("Ventana"), Rect{ 120,120, 640, 480 }) {}
private:
	void onCreate() override
	{
		std::cout << "Tamaño de char: " << sizeof(char) << '\n';
		std::cout << "Tamaño de wchar: " << sizeof(wchar_t) << '\n';
		
		std::cout << "Valor en bytes de 'a': " << 'a' << '\n';
		charout << L"Valor en bytes de wchar 'a': " << L'a' << '\n';

		show();
		//Setup window
		Menu::create(menu);
		Menu::create(fileMenu);
		fileMenu.addItems({ Text("Abrir imagen"), Text("Guardar imagen"), Text("Salir")});
		menu.addSubMenu(fileMenu, Text("Archivo"));
		attachMenu(menu);
		addButton(buttonA, Text("Botón"), Vector2I{ 100, 100 });
		addButton(buttonB, Text("Test"), Vector2I{ 140, 140 }); 
		addRadioButton(
			{
				{ radioButtonA, Text("radio 1") },
				{ radioButtonB, Text("radio 2") },
				{ radioButtonC, Text("radio 3") }
			},
			Vector2I{ 200,200 }
		);
		//Loading the image...
		image.load(Text("c:\\Users\\w7\\Pictures\\chrono.bmp"));
		buffer.resize(image.dimension().x * image.dimension().y);
		//Event listening
		buttonA.onClick([&](Event e) {this->onButtonAClick(e);});
		buttonB.onClick([&](Event e) {this->onButtonBClick(e);});
		radioButtonA.onClick([&](Event e) {this->onRadioButtonAClick(e);});
		fileMenu.onItemSelect([&](Event e) {this->onFileMenuSelect(e); });
	}
	void onDraw(DeviceContext deviceContext) override
	{
		image.clonePixels(&buffer[0]);
		for (auto& pixel : buffer) 
		{
			pixel.b += 4;
		}
		image.setPixels(&buffer[0]);
		deviceContext.drawBitmap(image);
	}
	void onButtonAClick(Event e)
	{
		minimize();
	}
	void onButtonBClick(Event e)
	{
		radioButtonB.setText(L"Poof!");
	}
	void onRadioButtonAClick(Event e)
	{
		radioButtonA.setText(Text("Me haz clickeado tío!"));
		redraw();
	}
	void onFileMenuSelect(Event e)
	{
		int index = e.wparam;
		if (index == 2)
			close();
	}
};

int main() {

	//Setup font
	//TODO... font class wrapper...
	Application::defaultFont(Text("Segoe UI"));
	//Beginning to run the application...
	//Also add a 'font' param to default controls font style?
	MyWindow myWindow;
	Application::run(myWindow);
	return 0;
}

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
