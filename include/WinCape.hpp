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
	template<typename> class TBase;
	template<typename> class TControl;
	using Control = TControl<void>;
	class Button;
	class RadioButton;
	template<typename Derived> class TBase
	{
	public:
		using Self = Derived;
		Handle handle() const;
		Self& setText(const wchar_t* text);
	protected:
		TBase();
		void handle(const Handle& handle);
	private:
		Handle _handle;
	};
	class Window : public TBase<Window>
	{
	public:
		static Window& create(Window& window, const wchar_t* windowName = Defaults::WindowName, Rect rect = Defaults::WindowRect, WindowStyle style = Defaults::DefWindowStyle);
		Self& show();
		Self& minimize();
		Self& addButton(Button& button, const wchar_t* text, const Int2& position, const Int2& size = Defaults::ButtonSize);
		Self& addRadioButton(std::initializer_list<std::pair<Reference<RadioButton>, const wchar_t*>> radioButtonList, const Int2& position, const Int2& padding = Defaults::RadioButtonPadding);
		//try to define this in cpp
		//template<typename TControl> TControl addControl();
	};
	//enforce to this classes have to know nothing about Window class
	//add setFont function? (it may need a Font wrapper class, that can only be instantiated through ::new and returns a shared_ptr...)
	template<typename Derived> class TControl : public TBase<TControl<Derived>>
	{
	public:
		friend Window;
	};
	class Button : public TControl<Button>
	{
	public:
		Self& onClick(const EventCallback& callback);
	};
	class RadioButton : public Button
	{
	public:
		using Pair = std::pair<Reference<RadioButton>, const wchar_t*>;
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
}
struct Application
{
	/// <summary>
	/// Starts the application loop
	/// </summary>
	static int Run();
	static int Run(WinCape::WindowFrame& window);
	static InstanceHandle instance();
	//Really poor function, must be called at the application beginning in order to work...
	static void defaultFont(const wchar_t* fontName);
};
#endif // !INTERFACE_HPP
