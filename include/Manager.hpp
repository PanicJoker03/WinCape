#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "defines.hpp"
#include "Gui/Base.hpp"
namespace WinCape
{
	class Manager
	{
	private:
		Manager();
	public:
		int startListening();
		void listenEvent(Gui::Base::Handle handle, WindowMessage message, const EventCallback& callback);
		void unlistenEvent(Gui::Base::Handle handle, WindowMessage message);
		void defaultFont(const TextChar* fontName);
		FontHandle defaultFont();
		void registerClass(const TextChar* name);
		Gui::Base::Handle createHandle(const TextChar* className, const TextChar* text, WindowStyle style, const Rect& rect, Gui::Base::Handle parent = nullptr, WindowStyle exStyle = 0);
		static Manager& instance();
	};
}
#endif
