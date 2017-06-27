#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include "defines.hpp"
#include "defaults.hpp"
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
	class Button;
	template<typename Derived> class Base
	{
	public:
		Handle handle() const;
		Derived& setText(const char* text);
	protected:
		Base();
		void handle(const Handle& handle);
	private:
		Handle _handle;
	};
	class Window : public Base<Window>
	{
	public:
		static Window Create(const char* windowName = Defaults::WindowName, Rect rect = Defaults::WindowRect, WindowStyle style = Defaults::DefWindowStyle);
		Window& show();
		Window& minimize();
		Window& addButton(Button& button, const char* text, const Int2& position, const Int2& size = Defaults::ButtonSize);
		//try to define this in cpp
		//template<typename TControl> TControl addControl();
	};
	//enforce to this classes have to know nothing about Window class
	template<typename Derived> class Control : public Base<Control<Derived>>
	{
	public:
		friend Window;
	};
	class Button : public Control<Button>
	{
	public:
		Button& onClick(const EventCallback& callback);
	};
}
#endif // !INTERFACE_HPP