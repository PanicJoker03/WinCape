#define _ENABLE_THEME
#include <WinCape.hpp>
using namespace WinCape;
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
	Pixel32Buffer buffer;
public:
	MyWindow() : WindowFrame(L"Ventana", Rect{ 120,120, 640, 480 }) {}
private:
	void onCreate() override
	{
		show();
		//Setup window
		Menu::create(menu);
		Menu::create(fileMenu);
		fileMenu.addItems({L"Abrir imagen", L"Guardar imagen", L"Salir"});
		menu.addSubMenu(fileMenu, L"Archivo");
		addMenu(menu);
		addButton(buttonA, L"Botón", Int2{ 100, 100 });
		addButton(buttonB, L"Test", Int2{ 140, 140 }); 
		addRadioButton(
			{
				{ radioButtonA, L"radio 1" },
				{ radioButtonB, L"radio 2" },
				{ radioButtonC, L"radio 3" }
			},
			Int2{ 200,200 }
		);
		//Loading the image...
		image.load(L"c:\\Users\\w7\\Pictures\\chrono.bmp");
		//Event listening
		buttonA.onClick([&](Event e) {this->onButtonAClick(e);});
		buttonB.onClick([&](Event e) {this->onButtonBClick(e);});
		radioButtonA.onClick([&](Event e) {this->onRadioButtonAClick(e);});
		fileMenu.onItemSelect([&](Event e) {this->onFileMenuSelect(e); });
	}
	void onDraw(DeviceContext deviceContext) override
	{
		image.foreachPixel(buffer, [](Pixel32& pixel) {
			pixel.b += 4;
		});
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
		radioButtonA.setText(L"Me haz clickeado tío!");
		redraw();
	}
	void onFileMenuSelect(Event e)
	{
		int index = e.wparam;
		if (index == 2)
		{
			close();
		}
	}
};
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//Setup font
	//TODO... font class wrapper...
	Application::defaultFont(L"Segoe UI");
	//Beginning to run the application...
	//Also add a 'font' param to default controls font style?
	MyWindow myWindow;
	Application::run(myWindow);
}
