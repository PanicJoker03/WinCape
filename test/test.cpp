#include <WinCape.hpp>

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
	Application::Run();
}