#define _ENABLE_THEME
#include <WinCape.hpp>
using namespace WinCape;
class MyWindow : public WindowFrame
{
private:
	Button buttonA;
	Button buttonB;
	RadioButton radioButtonA;
	RadioButton radioButtonB;
	RadioButton radioButtonC;
public:
	MyWindow() : WindowFrame(L"Ventana", Rect{ 120,120, 640, 480 }) {}
private:
	void onCreate() override
	{
		show();
		//Setup window
		addButton(buttonA, L"Bot�n", Int2{ 100, 100 });
		addButton(buttonB, L"Test", Int2{ 140, 140 }); 
		addRadioButton(
			{
				{ radioButtonA, L"radio 1" },
				{ radioButtonB, L"radio 2" },
				{ radioButtonC, L"radio 3" }
			},
			Int2{ 200,200 }
		);
		//Event listening
		buttonA.onClick([&](Event e) {this->onButtonAClick(e);});
		buttonB.onClick([&](Event e) {this->onButtonBClick(e);});
		radioButtonA.onClick([&](Event e) {this->onRadioButtonAClick(e);});
	}
	void onDraw() override
	{
		//Do something on draw event...
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
		radioButtonA.setText(L"Me haz clickeado t�o!");
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
