#include <iostream>
#include <WinCape.h>

using namespace w_cape;

ui::DeviceContext dcWnd;
ui::Window wn;
ui::Bitmap btMap;
void onDcWndDraw(EVENT e);

struct Pixel24 {
    USIGN_8 b;
    USIGN_8 g;
    USIGN_8 r;
    USIGN_8 noUse;
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int showCmd)
{
    application.init();

    RECT rcClient = { 0, 0, 557, 195};
    AdjustWindowRect(&rcClient, WS_OVERLAPPEDWINDOW, FALSE);

    wn = application.createWindow(
        L"Ventana workman mod",
        L"Ventana workman mod",
		CAPE_RECT{ 841, 473, rcClient.right - rcClient.left, rcClient.bottom - rcClient.top },
        WindowStyles::OVERLAPPED_WND, WindowStyles::Extended::TOPMOST
    );
    dcWnd = wn.deviceContext();
    wn.show();
    wn.onPaint(onDcWndDraw);
    
    //Cargar imagen de workman mod...
    //route this path to your current repository location
    btMap.load(L"C:\\your\\custom\\folder\\examples\\workman mod.bmp");

    application.run();
    return 0;
}

void onDcWndDraw(EVENT e) {
    dcWnd.drawBitmap(btMap);
}
