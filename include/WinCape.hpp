#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include "defines.hpp"
#include "defaults.hpp"
//TODO...
//Use lower case on static methods
struct Application;
namespace WinCape
{
	struct Event;
	using EventCallback = std::function<void(Event)>;
	//forward declarations
	class Button;
	class RadioButton;
	class DeviceContext;
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
		void onPaint(const EventCallback& callback);
		//try to define this in cpp
		//template<typename TControl> TControl addControl();
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
	class RadioButton : public Button
	{
	public:
		using Pair = std::pair<Reference<RadioButton>, const wchar_t*>;
	};
	//Experimental...
	class DeviceContext : public HasHandle<DeviceContextHandle>
	{
	private:
		DeviceContext(const DeviceContext&) = delete;
		DeviceContext& operator=(const DeviceContext&) = delete;
	public:
		//using Self = DeviceContext;
		//friend std::_Ref_count<Self>;
		//using Unique = std::unique_ptr<Self>;
		~DeviceContext();
	};
	class Font : public HasHandle<FontHandle>
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
		virtual ~WindowFrame() = 0;
		friend Application;
	};
	//
	struct Event
	{
		Base::Handle handle;
		WPARAM wparam;
		LPARAM lparam;
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
