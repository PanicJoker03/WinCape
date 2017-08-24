#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include "defines.hpp"
#include "defaults.hpp"
//TODO...
//Use lower case on static methods
struct Application;
namespace WinCape
{
	//forward declarations
	class Button;
	class RadioButton;
	class Menu;
	class DeviceContext;
	class Bitmap;
	template<typename T> class HasHandle
	{
	public:
		using Handle = T;
		T handle() const;
	protected:
		HasHandle();
		void handle(const T& handle);
	private:
		T _handle;
	};
	class Base : public HasHandle<BaseHandle>
	{
	public:
		void setText(const wchar_t* text);
	protected:
		Base();
	};
	class Window : public Base
	{
	public:
		static Window& create(Window& window, const wchar_t* windowName = Defaults::WindowName, Rect rect = Defaults::WindowRect, WindowStyle style = Defaults::DefWindowStyle);
		void show();
		void minimize();
		void addButton(Button& button, const wchar_t* text, const Int2& position, const Int2& size = Defaults::ButtonSize);
		void addRadioButton(std::initializer_list<std::pair<Reference<RadioButton>, const wchar_t*>> radioButtonList, const Int2& position, const Int2& padding = Defaults::RadioButtonPadding);
		void attachMenu(Menu& menu);
		void onPaint(const EventCallback& callback);
		void redraw();
		void close();
		DeviceContext deviceContext();
	};
	//enforce to this classes have to know nothing about Window class
	//add setFont function? (it may need a Font wrapper class, that can only be instantiated through ::new and returns a shared_ptr...)
	class Control : public Base
	{
	public:
		friend Window;
	};
	class Button : public Control
	{
	public:
		void onClick(const EventCallback& callback);
	};
	class RadioButton final : public Button
	{
	public:
		using Pair = std::pair<Reference<RadioButton>, const wchar_t*>;
	};
	class Menu final : public HasHandle<MenuHandle>
	{
	private:
		void enableMenuCommand();
	public:
		void addSubMenu(Menu& menu, const wchar_t* text);
		void addItem(const wchar_t* item);
		void addItems(std::initializer_list<const wchar_t*> itemList);
		void onItemSelect(const EventCallback& callback);
		static void create(Menu& menu);
		friend Window;
	};
	class Bitmap final : public HasHandle<BitmapHandle>
	{
	private:
		Bitmap(const Bitmap&) = delete;
		Bitmap& operator=(const Bitmap&) = delete;
		void getBitmapInfo(const DeviceContextHandle& deviceContext, BITMAPINFO& bmpInfo) const;
	public:
		Bitmap();
		void load(const wchar_t* sourcePath);
		Int2 dimension() const;
		void clonePixels(void* buffer) const;
		void setPixels(void* buffer);
		~Bitmap();
	};
	class DeviceContext final : public HasHandle<DeviceContextHandle>
	{
	private:
		void bitBlt(const BitmapHandle& bitmapHandle, const DeviceContextHandle& destiny, const Rect& rect);
	public:
		DeviceContext();
		DeviceContext(const DeviceContextHandle& value);
		void drawBitmap(const Bitmap& bitmap);
		friend Window;
	};
	class Font final : public HasHandle<FontHandle>
	{
		//Do something...
	};
	//////////////////////////
	//High level abstraction//
	//////////////////////////
	class WindowFrame : public Window
	{
	private:
		const wchar_t* windowName;
		const Rect rect;
		const WindowStyle style;
	protected:
		WindowFrame(const wchar_t* windowName = Defaults::WindowName, Rect rect = Defaults::WindowRect, WindowStyle style = Defaults::DefWindowStyle);
		virtual void onCreate() = 0;
		virtual void onDraw(DeviceContext deviceContext);
		virtual ~WindowFrame() = 0;
		friend Application;
	};
}
struct Application
{
	/// <summary>
	/// Starts the application loop
	/// </summary>
	static int run();
	static int run(WinCape::WindowFrame& window);
	static InstanceHandle instance();
	//Really poor function, must be called at the application beginning in order to work...
	static void defaultFont(const wchar_t* fontName);
};
#endif // !INTERFACE_HPP
