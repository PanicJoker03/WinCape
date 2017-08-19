#include <WinCape.hpp>
#include <Manager.hpp>
#include <Helper.hpp>
#include <vector>
#include <map>
using namespace std;
//-------------------------------------------------------------------------
//Application
//-------------------------------------------------------------------------
int Application::run()
{
	return WinCape::Manager::instance().startListening();
}
int Application::run(WinCape::WindowFrame& window)
{
	using namespace WinCape;
	Window::create(window, window.windowName, window.rect, window.style);
	window.onPaint([&](Event e) {
		PAINTSTRUCT paintStruct;
		DeviceContext deviceContext{ (BeginPaint(window.handle(), &paintStruct)) };
		window.onDraw(window.deviceContext());
		EndPaint(window.handle(), &paintStruct);
	});
	window.onCreate();
	return WinCape::Manager::instance().startListening();
}
InstanceHandle Application::instance()
{
	return GetModuleHandle(NULL);
}
void Application::defaultFont(const wchar_t* fontName)
{
	WinCape::Manager::instance().defaultFont(fontName);
}
namespace
{
	int idCounter = 0;
}
namespace WinCape
{
	//-------------------------------------------------------------------------
	//HasHandle
	//-------------------------------------------------------------------------
	template<typename T> HasHandle<T>::HasHandle() {}
	template<typename T> void HasHandle<T>::handle(const T& handle)
	{
		this->_handle = handle;
	}
	template<typename T> T HasHandle<T>::handle() const
	{
		return _handle;
	}
	//-------------------------------------------------------------------------
	//Base
	//-------------------------------------------------------------------------
	Base::Base() {}
	void Base::setText(const wchar_t* text)
	{
		SetWindowText(handle(), text);
	}
	//-------------------------------------------------------------------------
	//Window
	//-------------------------------------------------------------------------
	Window& Window::create(Window& window, const wchar_t* windowName, Rect rect, WindowStyle style)
	{
		Handle windowHandle;
		//RegisterClassEx(&WindowClass());
		Manager::instance().registerClass();
		windowHandle = Manager::instance().createHandle(Defaults::WindowName, windowName, style, rect);
		window.handle(windowHandle);
		return window;
	}
	void Window::show()
	{
		ShowWindow(handle(), ShowCommands::Show);
	}
	void Window::minimize()
	{
		ShowWindow(handle(), ShowCommands::Minimize);
	}
	void Window::addButton(Button& button, const wchar_t* text, const Int2& position, const Int2& size)
	{
		Handle buttonHandle;
		buttonHandle = Manager::instance().createHandle(Defaults::ButtonClassName, text, Defaults::DefButtonStyle, Rect{ position, size }, handle());
		button.handle(buttonHandle);
	}
	void Window::addRadioButton(initializer_list<pair<Reference<RadioButton>, const wchar_t*>> radioButtonList, const Int2& position, const Int2& padding)
	{
		const auto listSize = radioButtonList.size();
		for (auto i = 0; i < listSize; i++)
		{
			Handle radioButtonHandle;
			RadioButton& radioButton = radioButtonList.begin()[i].first;
			const wchar_t* caption = radioButtonList.begin()[i].second;
			Int2 position_ = position;
			position_.x += padding.x * i;
			position_.y += padding.y * i;
			const bool isLast = (i == (listSize - 1));
			const ButtonStyle style = isLast ? Defaults::RadioButtonStyle | WindowStyles::Group : Defaults::RadioButtonStyle;
			radioButtonHandle = Manager::instance().createHandle(Defaults::ButtonClassName, caption, style, Rect{ position_, Defaults::ButtonSize }, handle());
			radioButton.handle(radioButtonHandle);
		}
	}
	void Window::addMenu(Menu& menu)
	{
		SetMenu(handle(), menu.handle());
		DrawMenuBar(handle());
	}
	void Window::onPaint(const EventCallback& callback)
	{
		//TODO: declare button notifications in defines
		Manager::instance().listenEvent(handle(), WindowMessages::Paint, callback);
	}
	void Window::redraw()
	{
		RedrawWindow(handle(), 0, 0, RDW_INVALIDATE | RDW_UPDATENOW);
	}
	DeviceContext Window::deviceContext()
	{
		DeviceContext deviceContext;
		deviceContext.handle(GetDC(handle()));
		return deviceContext;
	}
	void Window::close()
	{
		SendMessage(handle(), WindowMessages::Close, 0, 0);
	}
	//-------------------------------------------------------------------------
	//Button
	//-------------------------------------------------------------------------
	void Button::onClick(const EventCallback& callback)
	{
		//TODO: declare button notifications in defines
		Manager::instance().listenEvent(handle(), BN_CLICKED, callback);
	}
	//-------------------------------------------------------------------------
	//Menu
	//-------------------------------------------------------------------------
	void Menu::addSubMenu(Menu& menu, const wchar_t* text)
	{
		AppendMenu(handle(), MF_STRING | MF_POPUP, (UINT_PTR)menu.handle(), text);
	}
	void Menu::addItem(const wchar_t* item)
	{
		//Create MenuFlags in defines
		AppendMenu(handle(), MF_STRING, ++idCounter, item);
	}
	void Menu::addItems(std::initializer_list<const wchar_t*> itemList)
	{
		for (const wchar_t* item : itemList)
		{
			addItem(item);
		}
	}
	void Menu::onItemSelect(const EventCallback& callback)
	{
		Manager::instance().listenEvent((Base::Handle)handle(), WindowMessages::MenuCommand, callback);
	}
	void Menu::create(Menu& menu)
	{
		MenuHandle menuHandle = CreateMenu();
		menu.handle(menuHandle);
		//Enabling WM_MENUCOMMAND
		//https://stackoverflow.com/questions/14916356/how-to-enable-popup-menu-to-communicate-with-wm-menucommand-instead-of-wm-comman
		MENUINFO menuInfo = {};
		menuInfo.cbSize = sizeof(MENUINFO);
		GetMenuInfo(menu.handle(), &menuInfo);
		menuInfo.fMask = MIM_STYLE;
		menuInfo.dwStyle |= MNS_NOTIFYBYPOS;
		SetMenuInfo(menu.handle(), &menuInfo);
	}
	//-------------------------------------------------------------------------
	//WindowFrame
	//-------------------------------------------------------------------------
	WindowFrame::WindowFrame(const wchar_t* windowName, Rect rect, WindowStyle style)
		:windowName(windowName), rect(rect), style(style) {}
	void WindowFrame::onDraw(DeviceContext deviceContext) {}
	WindowFrame::~WindowFrame() {}
	//-------------------------------------------------------------------------
	//DeviceContext
	//-------------------------------------------------------------------------
	DeviceContext::DeviceContext() {}
	DeviceContext::DeviceContext(const DeviceContextHandle& value)
	{
		handle(value);
	}
	void DeviceContext::bitBlt(const BitmapHandle& bitmapHandle, const DeviceContextHandle& destiny, const Rect& rect)
	{
		BitmapHandle hbmOld = (BitmapHandle)SelectObject(destiny, bitmapHandle);
		BitBlt(handle(), rect.position.x, rect.position.y, rect.size.x, rect.size.y, destiny, 0, 0, SRCCOPY);
		SelectObject(destiny, hbmOld);
	}
	void DeviceContext::drawBitmap(const Bitmap& bitmap)
	{
		DeviceContextHandle deviceContextMemory = CreateCompatibleDC(handle());
		Int2 bitmapSize = bitmap.dimension();
		bitBlt(bitmap.handle(), deviceContextMemory, Rect{ 0, 0, bitmapSize });
		DeleteDC(deviceContextMemory);
	}
	//-------------------------------------------------------------------------
	//Bitmap
	//-------------------------------------------------------------------------
	Bitmap::Bitmap() {}
	void Bitmap::getBitmapInfo(const DeviceContextHandle& deviceContext, BITMAPINFO& bmpInfo) const
	{
		bmpInfo.bmiHeader.biSize = sizeof(bmpInfo.bmiHeader);
		GetDIBits(deviceContext, handle(), 0, 0, NULL, &bmpInfo, DIB_RGB_COLORS);
		bmpInfo.bmiHeader.biCompression = BI_RGB;
	}
	void Bitmap::load(const wchar_t* sourcePath)
	{
		DeleteObject(handle());
		handle((BitmapHandle)LoadImage(NULL, sourcePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
	}
	Int2 Bitmap::dimension() const
	{
		//Wonderfull code source from:
		//http://forums.codeguru.com/showthread.php?348350-Bitmap-Dimensions-after-using-LoadImage-How
		//check for handle nullity?
		BITMAP bitmap = {};
		GetObject(handle(), sizeof(bitmap), &bitmap);
		return Int2{ bitmap.bmWidth, bitmap.bmHeight };
	}
	void Bitmap::pixels(Pixel32Buffer& buffer) const
	{
		//Must call GetDIBits twice...
		//https://stackoverflow.com/questions/26233848/c-read-pixels-with-getdibits
		DeviceContextHandle deviceContext = GetDC(NULL); //Safe?
		BITMAPINFO bitmapInfo = {};
		getBitmapInfo(deviceContext, bitmapInfo);
		buffer.resize(bitmapInfo.bmiHeader.biSizeImage / 4); //replace 4 with variable?
		GetDIBits(deviceContext, handle(), 0, bitmapInfo.bmiHeader.biHeight, &buffer[0], &bitmapInfo, DIB_RGB_COLORS);
	}
	void Bitmap::paintBuffer(const Pixel32Buffer& buffer)
	{
		DeviceContextHandle deviceContext = GetDC(NULL); //Safe?
		BITMAPINFO bitmapInfo = {};
		getBitmapInfo(deviceContext, bitmapInfo);
		//buffer = Pixel32Buffer(bitmapInfo.bmiHeader.biSizeImage / 4); //replace 4 with variable?
		SetDIBits(deviceContext, handle(), 0, bitmapInfo.bmiHeader.biHeight, &buffer[0], &bitmapInfo, DIB_RGB_COLORS);
	}
	void Bitmap::foreachPixel(Pixel32Buffer& buffer, std::function<void(Pixel32&)> callback)
	{
		pixels(buffer);
		for (auto& pixel : buffer)
		{
			callback(pixel);
		}
		paintBuffer(buffer);
	}
	Bitmap::~Bitmap()
	{
		DeleteObject(handle());
	}
	//-------------------------------------------------------------------------
	//Avoiding template linkage errors
	//-------------------------------------------------------------------------
	template class HasHandle<BaseHandle>;
	//template class HasHandle<DeviceContextHandle>;
	template class HasHandle<MenuHandle>;
	template class HasHandle<BitmapHandle>;
}