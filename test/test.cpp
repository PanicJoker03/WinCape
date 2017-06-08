#include <WinCape.hpp>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	using namespace WinCape;
	//Window window = Window::Create();
	//window.show();
	Window::Create().show();
	Application::Run();
}