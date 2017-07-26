#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include "defines.hpp"
#include "defaults.hpp"
//TODO:
//Use std::wstring/const w_char* for strings i/o. Remove own crappy pointer collector...
//Alias POINT and RECT with Point and Rect. Remove Int2 and Rect structures

struct Application
{
	/// <summary>
	/// Starts the application loop
	/// </summary>
	static int Run();
	static InstanceHandle Instance();
};
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
		Self& setText(const char* text);
	protected:
		TBase();
		void handle(const Handle& handle);
	private:
		Handle _handle;
	};
	class Window : public TBase<Window>
	{
	public:
		static Window& Create(Window& window, const char* windowName = Defaults::WindowName, Rect rect = Defaults::WindowRect, WindowStyle style = Defaults::DefWindowStyle);
		Self& show();
		Self& minimize();
		Self& addButton(Button& button, const char* text, const Int2& position, const Int2& size = Defaults::ButtonSize);
		Self& addRadioButton(std::initializer_list<RadioButton::Pair> radioButtonList, const Int2& position, const Int2& padding = Defaults::RadioButtonPadding);
		//try to define this in cpp
		//template<typename TControl> TControl addControl();
	};
	//enforce to this classes have to know nothing about Window class
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
		using Pair = std::pair<Reference<RadioButton>, const char*>;
	};
}
#endif // !INTERFACE_HPP
