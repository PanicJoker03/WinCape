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
	template<typename> class TBase;
	template<typename> class TControl;
	using Control = TControl<void>;
	class Button;
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
		static Window Create(const char* windowName = Defaults::WindowName, Rect rect = Defaults::WindowRect, WindowStyle style = Defaults::DefWindowStyle);
		Self& show();
		Self& minimize();
		Self& addButton(Button& button, const char* text, const Int2& position, const Int2& size = Defaults::ButtonSize);
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
}
#endif // !INTERFACE_HPP