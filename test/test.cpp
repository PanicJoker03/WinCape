#include <WinCape.hpp>
using namespace WinCape;
Window window;
Button buttonA;
Button buttonB;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	window = Window::Create();
	window.show()
		.addButton(buttonA, "Botón", Int2{ 100, 100 })
		.addButton(buttonB, "Test", Int2{ 140, 140 });

	buttonA.onClick([](Event e) {
		window.minimize();
	});
	Application::Run();
}
