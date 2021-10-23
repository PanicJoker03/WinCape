#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include "defines.hpp"
#include "defaults.hpp"

//TODO...
//Use lower case on static methods
namespace WinCape
{
	// Utility function...
	//forward declarations
	class Window;
	class Button;
	class RadioButton;
	class Menu;
	class Icon;
	class DeviceContext;
	class Bitmap;
	template<typename T> class HasHandle
	{
	public:
		using Handle = T;
		T handle() const;
		template<typename> friend class CanCreateFromResource;
	protected:
		HasHandle();
		void handle(const T& handle);
	private:
		T _handle;
	};
	class Base : public HasHandle<WindowHandle>
	{
	public:
		void setText(const Char* text);
		void getText(Char* text, int lenght) const;
	protected:
		Base();
	};
	class Window : public Base
	{
	public:
		static Window& create(Window& window, const Char* windowName = Defaults::WindowName, Rect rect = Defaults::WindowRect, WindowStyle style = Defaults::DefWindowStyle);
		void show();
		void minimize();
		void addButton(Button& button, const wchar_t* text, const Int2& position, const Int2& size = Defaults::ButtonSize);
		void addRadioButton(std::initializer_list<std::pair<Reference<RadioButton>, const wchar_t*>> radioButtonList, const Int2& position, const Int2& padding = Defaults::RadioButtonPadding);
		void attachMenu(Menu& menu);
		void onPaint(const EventCallback& callback);
		void redraw();
		void close();
		void setIcon(const Icon& icon);
		DeviceContext deviceContext();
	};
	//enforce to this classes have to know nothing about Window class
	//add setFont function? (it may need a Font wrapper class, that can only be instantiated through ::new and returns a shared_ptr...)
	class Control : public Base
	{
	public:
		friend Window;
		void createFromResource(WindowHandle parent, int resource);
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
	class ComboBox final : public Control
	{
	public:
		void addString(const Char* string);
	};
	class ListBox final : public Control
	{
	public:
		void addString(const Char* string);
		int count();
	};
	class Menu final : public HasHandle<MenuHandle>
	{
	private:
		void enableMenuCommand();
	public:
		void addSubMenu(Menu& menu, const Char* text);
		void addItem(const Char* item);
		void addItems(std::initializer_list<const Char*> itemList);
		void onItemSelect(const EventCallback& callback);
		static void create(Menu& menu);
		friend Window;
	};
	class Icon final : public HasHandle<IconHandle> 
	{
	public:
		Icon();
		void load(ResourceInt idi);
		friend Window;
	};
	class Bitmap final : public HasHandle<BitmapHandle>
	{
	private:
		Bitmap(const Bitmap&) = delete;
		//Bitmap& operator=(const Bitmap&) = delete;
		void getBitmapInfo(const DeviceContextHandle& deviceContext, BITMAPINFO& bmpInfo) const;
	public:
		Bitmap(const Int2& dimensions = Int2{});
		Bitmap& operator = (const Bitmap& bitmap);
		void load(const Char* sourcePath);
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
		//void drawBitmap(const Bitmap& bitmap);
		void drawBitmap(const Bitmap& bitmap, const Int2& padding = Int2{});
		//drawBitmapClipped...
		friend Window;
	};
	class Font final : public HasHandle<FontHandle>
	{
		//Do something...
	};
	struct Application;
	//////////////////////////
	//High level abstraction//
	//////////////////////////
	class WindowFrame : public Window
	{
	private:
		const Char* windowName;
		const Rect rect;
		const WindowStyle style;
	protected:
		WindowFrame(const Char* windowName = Defaults::WindowName, Rect rect = Defaults::WindowRect, WindowStyle style = Defaults::DefWindowStyle);
		virtual void onCreate() = 0;
		virtual void onDraw(DeviceContext deviceContext);
		virtual ~WindowFrame() = 0;
		friend Application;
	};
	struct Application
	{
		/// <summary>
		/// Starts the application loop
		/// </summary>
		static int run();
		static int run(WinCape::WindowFrame& window);
		static InstanceHandle instance();
		//Really poor function, must be called at the application beginning in order to work...
		static void defaultFont(const Char* fontName);
	};
}
#endif INTERFACE_HPP
