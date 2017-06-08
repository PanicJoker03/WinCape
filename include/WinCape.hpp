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
	class Base
	{
	public:
		Base();
		~Base();
		Base(const Base&);
		Handle getHandle() const;
	protected:
		void setHandle(const Handle& handle);
		class BaseImpl;
	private:
		std::unique_ptr<BaseImpl> baseImpl;
	};
	class Window : Base
	{
	public:
		Window();
		~Window();
		Window(const Window&);
		static Window Create(const char* windowName = Defaults::WindowName, Rect rect = Defaults::WindowRect, WindowStyle style = Defaults::DefWindowStyle);
		void show();
		void hide();
		//try to define this in cpp
		//template<typename TControl> TControl addControl(); //store controls in vector or map
	private:
		//check if I can remove all this pimpl repeat using templates
		class WindowImpl;
		std::unique_ptr<WindowImpl> windowImpl;
	};
	//enforce to this classes have to know nothing about Window class
	class Control : Base
	{

	};
	class Button : Control
	{
	public:
		Button();
		~Button();
		//TODO: rename "std::function<void()>" to a more readable type
		void onClick(std::function<void()> callback);
	private:
		class ButtonImpl;
		std::unique_ptr<ButtonImpl> buttonImpl;
	};
}
#endif // !INTERFACE_HPP