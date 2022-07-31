// Tested on Visual Studio 2017 with std++17
// This was a file originally generated by a visual studio wizard
// WinCape.cpp : Define el punto de entrada de la aplicación.
//

#include "framework.h"
#include <iostream>
#include <WinCape.hpp>

#define MAX_LOADSTRING 100

using WinCape::Application;
using WinCape::Gui::Window;
using WinCape::Rect;
using WinCape::Gui::ListView;
using WinCape::Gui::Button;
using WinCape::Gui::DeviceContext;
using WinCape::Gui::Bitmap;

// Variables globales:
HINSTANCE hInst;                                // instancia actual
WCHAR szTitle[MAX_LOADSTRING];                  // Texto de la barra de título
WCHAR szWindowClass[MAX_LOADSTRING];            // nombre de clase de la ventana principal

// Declaraciones de funciones adelantadas incluidas en este módulo de código:
void                MyRegisterClass(HINSTANCE hInstance, WNDPROC wndProc);
HWND                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	std::cout << sizeof(wchar_t) << std::endl;
	Application::init();
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Colocar código aquí.
	Window childWnd = Application::createWindow(L"Ventana", L"Ventana WinCape", Rect{ 10, 10, 250, 54 }, WinCape::WindowStyles::ThickFrame);
	WNDPROC wndProc = (WNDPROC)GetWindowLongPtrW(childWnd.handle(), GWLP_WNDPROC);
    // Inicializar cadenas globales
    //LoadStringW(hInstance, L"Pogo", szTitle, MAX_LOADSTRING);
    //LoadStringW(hInstance, L"WinCape", szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance, wndProc);

    // Realizar la inicialización de la aplicación:
	HWND hWnd = InitInstance(hInstance, nCmdShow);
    if (!hWnd)
    {
		DWORD err = GetLastError();
		LPWCH mess = NULL;
		std::cout << FormatMessageW(FORMAT_MESSAGE_FROM_STRING | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_ALLOCATE_BUFFER,
			NULL, err, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), &mess[0], 0, NULL);
		auto deleter = [](void * p) {::HeapFree(::GetProcessHeap(), 0, p); };
		std::unique_ptr<WCHAR, decltype(deleter)> ptrBuffer(mess, deleter);

		std::cout << mess << std::endl;

        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(0));

    MSG msg;

    // Bucle principal de mensajes:
   /// Skip message loop
	/* while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }*/

	Window msterWnd = Window(hWnd);
	childWnd.show();
	childWnd.parent(msterWnd);

	ListView lvLayers;
	msterWnd.addListView(lvLayers, Rect{ 30, 100, 150, 100 }, WinCape::Vector2I{ 30, 148 });
	lvLayers.addColumn(0, "Fruta", 50);
	lvLayers.addColumn(1, "Verdura", 50);
	lvLayers.addColumn(2, "Grano", 50);

	lvLayers.addRow(0, std::vector<std::string>({"Mango", "Tomate", "Ajonjoli"}));
	lvLayers.addRow(1, std::vector<std::string>({"Platano", "Brocoli", "Arroz"}));
	lvLayers.addRow(2, std::vector<std::string>({"Pera", "Coliflor", "Garbanzo"}));

	Button btHide;
	msterWnd.addButton(btHide, L"Escondidas", WinCape::Vector2I{ 50, 170 });
	//Potente implementacion para manejar funciones 
	std::function<void(WinCape::Event)> onBtHideClick = [&](WinCape::Event e) {
		msterWnd.hide();
	};
	btHide.onClick(onBtHideClick);

	//Dibujar bitmap
	DeviceContext dcBitmp = msterWnd.deviceContext();
	Bitmap bitmp{ WinCape::Vector2I{ 190 , 120 } };
	bitmp.load(L"C:\\Users\\Luis\\Pictures\\xp_memories.bmp");
	//Solo se puede dibujar dentro del evento paint...
	std::function<void(WinCape::Event)> onPaint = [&](WinCape::Event e) {
		dcBitmp.drawBitmap(bitmp, WinCape::Vector2I{ 38, 88 });
	};
	msterWnd.onPaint(onPaint);
	Application::run();

    return 0;
}



//
//  FUNCIÓN: MyRegisterClass()
//
//  PROPÓSITO: Registra la clase de ventana.
//
void MyRegisterClass(HINSTANCE hInstance, WNDPROC wndProc)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = wndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = NULL;
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = L"TEST";
    wcex.hIconSm        = NULL;

    RegisterClassExW(&wcex);
}

//
//   FUNCIÓN: InitInstance(HINSTANCE, int)
//
//   PROPÓSITO: Guarda el identificador de instancia y crea la ventana principal
//
//   COMENTARIOS:
//
//        En esta función, se guarda el identificador de instancia en una variable común y
//        se crea y muestra la ventana principal del programa.
//
HWND InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Almacenar identificador de instancia en una variable global

   HWND hWnd = CreateWindowW(L"TEST", L"What Do I Have To Lose", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 284, 360, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return NULL;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return hWnd;
}

//
//  FUNCIÓN: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PROPÓSITO: Procesa mensajes de la ventana principal.
//
//  WM_COMMAND  - procesar el menú de aplicaciones
//  WM_PAINT    - Pintar la ventana principal
//  WM_DESTROY  - publicar un mensaje de salida y volver
//
//
// NO SE USA, WINCAPE gestiona internamente los eventos...
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Analizar las selecciones de menú:
            switch (wmId)
            {
            case WM_CLOSE:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Agregar cualquier código de dibujo que use hDC aquí...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// NO se usa
// Controlador de mensajes del cuadro Acerca de.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
