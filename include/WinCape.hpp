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
//TODO: If private functions aren't needed, then redesign the whole class structure without pimpl
namespace WinCape
{
	//forward declarations
	class Button;
	template<typename Derived> class Base
	{
	public:
		//Try to implement CRTP chaining
		//Ty& setText(const char* text);
		Handle getHandle() const;
		Derived& setText(const char* text);
	protected:
		Base();
		void setHandle(const Handle& handle);
	private:
		Handle handle;
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
	//TODO: Find a way to multilevel inheritance chaining
	//enforce to this classes have to know nothing about Window class
	//class Control
	//{
	//public:
	//	friend Window;
	//};
	class Button : public Base<Button>
	{
	public:
		friend Window;
		//TODO: rename "std::function<void()>" to a more readable type (MessageCallback)
		Button& onClick(const EventCallback& callback);
	};
}
#endif // !INTERFACE_HPP