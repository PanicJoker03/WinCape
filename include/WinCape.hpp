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
	class Base
	{
	public:
		//Try to implement CRTP chaining
		//Ty& setText(const char* text);
		~Base();
		Handle getHandle() const;
	protected:
		Base();
		Base(const Base&);
		void setHandle(const Handle& handle);
		class BaseImpl;
	private:
		std::unique_ptr<BaseImpl> baseImpl;
	};
	class Window : public Base
	{
	public:
		Window();
		~Window();
		Window(const Window&);
		static Window Create(const char* windowName = Defaults::WindowName, Rect rect = Defaults::WindowRect, WindowStyle style = Defaults::DefWindowStyle);
		Window& show();
		void hide();
		Window& addButton(Button& button, const char* text, const Int2& position, const Int2& size = Defaults::ButtonSize);
		//try to define this in cpp
		//template<typename TControl> TControl addControl();
	private:
		class WindowImpl;
		std::unique_ptr<WindowImpl> windowImpl;
	};
	//enforce to this classes have to know nothing about Window class
	class Control : public Base
	{
	public:
		friend Window;
		Control();
		~Control();
		Control(const Control&);
	protected:
		class ControlImpl;
	private:
		std::unique_ptr<ControlImpl> controlImpl;
	};
	class Button : public Control
	{
	public:
		Button();
		~Button();
		Button(const Button&);
		//TODO: rename "std::function<void()>" to a more readable type (MessageCallback)
		Button& onClick(const EventCallback& callback);
	private:
		class ButtonImpl;
		std::unique_ptr<ButtonImpl> buttonImpl;
	};
}
#endif // !INTERFACE_HPP