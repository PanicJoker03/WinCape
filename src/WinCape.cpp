#include "WinCape.hpp"
#include "Manager.hpp"
#include <vector>
#include <iostream>
#include <map>

using namespace std;
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
	namespace UserGui 
	{
		//-------------------------------------------------------------------------
		//Base
		//-------------------------------------------------------------------------
		UserGui::Base::Base() {}
		void UserGui::Base::setText(const TextChar* text)
		{
			SetWindowText(handle(), text);
		}
		void UserGui::Base::getText(TextChar* text, int lenght) const
		{
			GetWindowText(handle(), text, lenght);
			//return text;
		}
		UserGui::Window::Window() {}
		UserGui::Window::Window(WindowHandle value)
		{
			handle(value);
		}
		void UserGui::Window::show()
		{
			ShowWindow(handle(), ShowCommands::Show);
		}
		void UserGui::Window::minimize()
		{
			ShowWindow(handle(), ShowCommands::Minimize);
		}
		void UserGui::Window::addButton(Button& button, const TextChar* text, const Vector2I& position, const Vector2I& size)
		{
			Handle buttonHandle;
			buttonHandle = Manager::instance().createHandle(Defaults::ButtonClassName, text, Defaults::DefButtonStyle, Rect{ position, size }, handle());
			button.handle(buttonHandle);
		}
		void UserGui::Window::addRadioButton(initializer_list<pair<Reference<RadioButton>, const TextChar*>> radioButtonList, const Vector2I& position, const Vector2I& padding)
		{
			const auto listSize = radioButtonList.size();
			for (auto i = 0; i < listSize; i++)
			{
				Handle radioButtonHandle;
				RadioButton& radioButton = radioButtonList.begin()[i].first;
				const TextChar* caption = radioButtonList.begin()[i].second;
				Vector2I position_ = position;
				position_.x += padding.x * i;
				position_.y += padding.y * i;
				const bool isLast = (i == (listSize - 1));
				const ButtonStyle style = isLast ? Defaults::RadioButtonStyle | WindowStyles::Group : Defaults::RadioButtonStyle;
				radioButtonHandle = Manager::instance().createHandle(Defaults::ButtonClassName, caption, style, Rect{ position_, Defaults::ButtonSize }, handle());
				radioButton.handle(radioButtonHandle);
			}
		}
		void UserGui::Window::attachMenu(Menu& menu)
		{
			SetMenu(handle(), menu.handle());
			DrawMenuBar(handle());
		}
		void UserGui::Window::onPaint(const EventCallback& callback)
		{
			//TODO: declare button notifications in defines
			Manager::instance().listenEvent(handle(), WindowMessages::Paint, callback);
		}
		void UserGui::Window::onDestroy(const EventCallback& callback)
		{
			//TODO: declare button notifications in defines
			Manager::instance().listenEvent(handle(), WindowMessages::Destroy, callback);
		}
		void UserGui::Window::redraw()
		{
			RedrawWindow(handle(), 0, 0, RDW_INVALIDATE | RDW_UPDATENOW);
		}
		UserGui::DeviceContext UserGui::Window::deviceContext()
		{
			UserGui::DeviceContext deviceContext;
			deviceContext.handle(GetDC(handle()));
			return deviceContext;
		}
		void UserGui::Window::close()
		{
			SendMessage(handle(), WindowMessages::Close, 0, 0);
		}
		void UserGui::Window::setIcon(const Icon& icon)
		{
			SendMessage(handle(), WindowMessages::SetIcon, ICON_BIG, (LPARAM)icon.handle());
		}
		//-------------------------------------------------------------------------
		//Control
		//-------------------------------------------------------------------------
		void UserGui::Control::createFromResource(WindowHandle parent, int resource) {
			handle(GetDlgItem(parent, resource));
		}
		//-------------------------------------------------------------------------
		//Button
		//-------------------------------------------------------------------------
		void UserGui::Button::onClick(const EventCallback& callback)
		{
			//TODO: declare button notifications in defines
			Manager::instance().listenEvent(handle(), BN_CLICKED, callback);
		}
		//-------------------------------------------------------------------------
		//ComboBox
		//-------------------------------------------------------------------------
		void UserGui::ComboBox::addString(const TextChar* string) {
			SendMessage(handle(), CB_ADDSTRING, 0, (LPARAM)string);
		}
		//-------------------------------------------------------------------------
		//ListBox
		//-------------------------------------------------------------------------
		void UserGui::ListBox::addString(const TextChar* string) {
			SendMessage(handle(), ListBoxMessages::AddString, 0, (LPARAM)string);
		}
		int UserGui::ListBox::count() {
			return SendMessage(handle(), ListBoxMessages::GetCount, 0, 0);
		}
		//-------------------------------------------------------------------------
		//Menu
		//-------------------------------------------------------------------------
		void UserGui::Menu::enableMenuCommand()
		{
			//Enabling WM_MENUCOMMAND
			//https://stackoverflow.com/questions/14916356/how-to-enable-popup-menu-to-communicate-with-wm-menucommand-instead-of-wm-comman
			MENUINFO menuInfo = {};
			menuInfo.cbSize = sizeof(MENUINFO);
			GetMenuInfo(handle(), &menuInfo);
			menuInfo.fMask = MIM_STYLE;
			menuInfo.dwStyle |= MNS_NOTIFYBYPOS;
			SetMenuInfo(handle(), &menuInfo);
		}
		void UserGui::Menu::addSubMenu(UserGui::Menu& menu, const TextChar* text)
		{
			AppendMenu(handle(), MF_STRING | MF_POPUP, (UINT_PTR)menu.handle(), text);
		}
		void UserGui::Menu::addItem(const TextChar* item)
		{
			//Create MenuFlags in defines
			AppendMenu(handle(), MF_STRING, 0, item);
		}
		void UserGui::Menu::addItems(std::initializer_list<const TextChar*> itemList)
		{
			for (const TextChar* item : itemList)
			{
				addItem(item);
			}
		}
		void UserGui::Menu::onItemSelect(const EventCallback& callback)
		{
			Manager::instance().listenEvent((UserGui::Base::Handle)handle(), WindowMessages::MenuCommand, callback);
		}
		void UserGui::Menu::create(UserGui::Menu& menu)
		{
			MenuHandle menuHandle = CreateMenu();
			menu.handle(menuHandle);
			menu.enableMenuCommand();
		}
		//-------------------------------------------------------------------------
		//Icon
		//-------------------------------------------------------------------------
		UserGui::Icon::Icon() {}
		void UserGui::Icon::load(ResourceInt idi)
		{
			IconHandle iconHandle = (IconHandle)LoadImage(Application::instance(), MAKEINTRESOURCE(idi), IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR | LR_DEFAULTSIZE);
			handle(iconHandle);
		}
		//-------------------------------------------------------------------------
		//DeviceContext
		//-------------------------------------------------------------------------
		UserGui::DeviceContext::DeviceContext() {}
		UserGui::DeviceContext::DeviceContext(DeviceContextHandle value)
		{
			handle(value);
		}
		void UserGui::DeviceContext::bitBlt(BitmapHandle bitmapHandle, DeviceContextHandle destiny, const Rect& rect)
		{
			BitmapHandle hbmOld = (BitmapHandle)SelectObject(destiny, bitmapHandle);
			BitBlt(handle(), rect.position.x, rect.position.y, rect.size.x, rect.size.y, destiny, 0, 0, SRCCOPY);
			SelectObject(destiny, hbmOld);
		}
		//void DeviceContext::drawBitmap(const Bitmap& bitmap)
		//{
		//	Int2 bitmapSize = bitmap.dimension();
		//	drawBitmap(bitmap, Rect{ 0, 0, bitmapSize });
		//}
		void UserGui::DeviceContext::drawBitmap(const UserGui::Bitmap& bitmap, const Vector2I& padding)
		{
			DeviceContextHandle deviceContextMemory = CreateCompatibleDC(handle());
			Vector2I bitmapSize = bitmap.dimension();
			bitBlt(bitmap.handle(), deviceContextMemory, Rect{ padding, bitmapSize });
			DeleteDC(deviceContextMemory);
		}
		//RenderContext DeviceContext::createRenderContext() {
		//	return RenderContext(wglCreateContext(handle()));
		//}
		////-------------------------------------------------------------------------
		////Bitmap
		////-------------------------------------------------------------------------
		//RenderContext::RenderContext() {}
		//RenderContext::RenderContext(GlRenderContextHandle value)
		//{
		//	handle(value);
		//}
		//-------------------------------------------------------------------------
		//Bitmap
		//-------------------------------------------------------------------------
		UserGui::Bitmap::Bitmap(const Vector2I& dimensions)
		{
			BitmapHandle bitmapHandle = CreateBitmap(dimensions.x, dimensions.y, 1, 32, NULL);
			handle(bitmapHandle);
		}

		UserGui::Bitmap& Bitmap::operator = (const Bitmap& bitmap)
		{
			DeleteObject(handle());
			BitmapHandle bitmapHandle = (BitmapHandle)CopyImage(bitmap.handle(), IMAGE_BITMAP, 0, 0, NULL);
			handle(bitmapHandle);
			return *this;
		}
		void UserGui::Bitmap::getBitmapInfo(const DeviceContextHandle& deviceContext, BITMAPINFO& bmpInfo) const
		{
			bmpInfo.bmiHeader.biSize = sizeof(bmpInfo.bmiHeader);
			GetDIBits(deviceContext, handle(), 0, 0, NULL, &bmpInfo, DIB_RGB_COLORS);
			bmpInfo.bmiHeader.biCompression = BI_RGB;
		}
		void UserGui::Bitmap::load(const TextChar* sourcePath)
		{
			DeleteObject(handle());
			handle((BitmapHandle)LoadImage(NULL, sourcePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
		}
		Vector2I UserGui::Bitmap::dimension() const
		{
			//Wonderfull code source from:
			//http://forums.codeguru.com/showthread.php?348350-Bitmap-Dimensions-after-using-LoadImage-How
			//check for handle nullity?
			BITMAP bitmap = {};
			GetObject(handle(), sizeof(bitmap), &bitmap);
			return Vector2I{ bitmap.bmWidth, bitmap.bmHeight };
		}
		void UserGui::Bitmap::clonePixels(void* buffer) const
		{
			//Must call GetDIBits twice...
			//https://stackoverflow.com/questions/26233848/c-read-pixels-with-getdibits
			const DeviceContextHandle deviceContext = GetDC(NULL); //Safe?
			BITMAPINFO bitmapInfo = {};
			getBitmapInfo(deviceContext, bitmapInfo);
			GetDIBits(deviceContext, handle(), 0, bitmapInfo.bmiHeader.biHeight, buffer, &bitmapInfo, DIB_RGB_COLORS);
		}
		void UserGui::Bitmap::setPixels(void* buffer)
		{
			const DeviceContextHandle deviceContext = GetDC(NULL); //Safe?
			BITMAPINFO bitmapInfo = {};
			getBitmapInfo(deviceContext, bitmapInfo);
			SetDIBits(deviceContext, handle(), 0, bitmapInfo.bmiHeader.biHeight, buffer, &bitmapInfo, DIB_RGB_COLORS);
		}
		UserGui::Bitmap::~Bitmap()
		{
			DeleteObject(handle());
		}
		//-------------------------------------------------------------------------
		//WindowFrame
		//-------------------------------------------------------------------------
		UserGui::WindowFrame::WindowFrame(const TextChar* windowName, const TextChar* title, const Rect& rect, WindowStyle style) 
			: windowName(windowName), rect(rect), style(style) {
			handle(Application::createWindow(windowName, title, rect, style).handle());
			SendMessage(handle(), WindowMessages::Create, 0, 0);
		}
		void UserGui::WindowFrame::onDraw(DeviceContext deviceContext) {}
		void UserGui::WindowFrame::onDispose() {
			Manager::instance().unlistenEvent(handle(), WindowMessages::Paint);
			Manager::instance().unlistenEvent(handle(), WindowMessages::Destroy);
		}
		UserGui::WindowFrame::~WindowFrame() {}
	}
	//-------------------------------------------------------------------------
	//Application
	//-------------------------------------------------------------------------
	void Application::init(const TextChar* name)
	{
		Manager::instance().registerClass(name);
	}
	UserGui::Window Application::createWindow(const TextChar* windowName, const TextChar* title, const Rect& rect, WindowStyle style)
	{
		UserGui::Window window;
		window = UserGui::Window(Manager::instance().createHandle(windowName, title, style, rect));
		return window;
	}
	int Application::run()
	{
		return WinCape::Manager::instance().startListening();
	}
	int Application::run(WinCape::UserGui::WindowFrame& window)
	{
		using namespace WinCape;
		window.onCreate();
		window.onPaint([&](Event e) {
			PAINTSTRUCT paintStruct;
			UserGui::DeviceContext deviceContext{ (BeginPaint(window.handle(), &paintStruct)) };
			window.onDraw(window.deviceContext());
			EndPaint(window.handle(), &paintStruct);
			});
		//window.onCreate();
		return WinCape::Manager::instance().startListening();
	}
	InstanceHandle Application::instance()
	{
		return GetModuleHandle(NULL);
	}
	void Application::defaultFont(const TextChar* fontName)
	{
		WinCape::Manager::instance().defaultFont(fontName);
	}
	//-------------------------------------------------------------------------
	//Avoiding template linkage errors
	//-------------------------------------------------------------------------
	template class HasHandle<WindowHandle>;
	//template class HasHandle<DeviceContextHandle>;
	template class HasHandle<MenuHandle>;
	template class HasHandle<BitmapHandle>;
}
