#include <WinCape.hpp>

void callbackTest(Handle, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	using namespace WinCape;
	//Window window = Window::Create();
	//window.show();
	Button buttonA;
	Button buttonB;
	Window::Create()
		.show()
		.addButton(buttonA, "Botón", Int2{ 100,100 })
		.addButton(buttonB, "Test", Int2{ 140, 140 });
	buttonA.onClick(callbackTest);
	Application::Run();
}

void callbackTest(Handle handle, WPARAM wParam, LPARAM lParam)
{
	int i = 0;
}
