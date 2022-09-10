#include <iostream>
#include <WinCape.hpp>

using namespace wcape;

usr::DeviceContext dcWnd;
usr::Window wn;
usr::Bitmap btMap;
void onDcWndDraw(EVENT e);

struct Pixel24 {
    UnsignedI8 b;
    UnsignedI8 g;
    UnsignedI8 r;
    UnsignedI8 noUse;
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int showCmd)
{
    application.init();

    RECT rcClient = { 0, 0, 416, 146};
    AdjustWindowRect(&rcClient, WS_OVERLAPPEDWINDOW, FALSE);

    wn = application.createWindow(
        L"Ventana workman",
        L"Ventana workman",
		CAPE_RECT{ 841, 473, rcClient.right - rcClient.left, rcClient.bottom - rcClient.top },
        WindowStyles::OVERLAPPED_WINDOW, WindowStyles::Extended::TOPMOST
    );
    dcWnd = wn.deviceContext();
    wn.show();
    wn.onPaint(onDcWndDraw);
    
    //Cargar imagen de workman...
    btMap.load(L"C:\\your\\custom\\folder\\workman.bmp");

    application.run();
    return 0;
}

void onDcWndDraw(Event e) {
    dcWnd.drawBitmap(btMap);
}
