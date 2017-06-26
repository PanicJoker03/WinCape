#include <WinCape.hpp>
using namespace WinCape;
Window window;
Button buttonA;
Button buttonB;
void callbackTest(Handle, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	window = Window::Create();
	window.show()
		.addButton(buttonA, "Botón", Int2{ 100,100 })
		.addButton(buttonB, "Test", Int2{ 140, 140 });
	buttonA.onClick(callbackTest);
	Application::Run();
}

void callbackTest(Handle handle, WPARAM wParam, LPARAM lParam)
{
	window.minimize();
}
