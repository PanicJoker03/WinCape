#include <WinCape.hpp>
using namespace WinCape;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
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
		.addButton(buttonA, "Botón", Int2{ 100, 100 })
		.addButton(buttonB, "Test", Int2{ 140, 140 });
	//Adding radio buttons
	window.addRadioButton(
		{
			RadioButton::Pair{ radioButtonA, "radio 1" },
			RadioButton::Pair{ radioButtonB, "radio 2" },
			RadioButton::Pair{ radioButtonC, "radio 3" } 
		},
		Int2{200,200}
	);
	//Event listening
	buttonA.onClick([&](Event e) {
		window.minimize();
	});
	//Beginning to run the application
	Application::Run();
}
