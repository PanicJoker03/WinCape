#define _ENABLE_THEME
#include <WinCape.hpp>
using namespace WinCape;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//Setup font
	//TODO... font class wrapper...
	Application::defaultFont(L"Segoe UI");
	//Setup window
	Window window;
	Button buttonA;
	Button buttonB;
	RadioButton radioButtonA;
	RadioButton radioButtonB;
	RadioButton radioButtonC;
	//Window creation, also method chaining
	Window::Create(window)
		.show()
		.addButton(buttonA, L"Botón", Int2{ 100, 100 })
		.addButton(buttonB, L"Test", Int2{ 140, 140 });
	//Adding radio buttons
	window.addRadioButton(
		{
			RadioButton::Pair{ radioButtonA, L"radio 1" },
			RadioButton::Pair{ radioButtonB, L"radio 2" },
			RadioButton::Pair{ radioButtonC, L"radio 3" } 
		},
		Int2{200,200}
	);
	//Event listening
	buttonA.onClick([&](Event e) {
		window.minimize();
	});
	buttonB.onClick([&](Event e) {
		radioButtonB.setText(L"Poof!");
	});
	radioButtonA.onClick([&](Event e) {
		radioButtonA.setText(L"Me haz clickeado tío!");
	});
	//Beginning to run the application...
	//Force to run a main frame window in a param?
	//Also add a 'font' param to default controls font style?
	Application::Run();
}
