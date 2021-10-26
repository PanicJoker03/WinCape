#include "defines.hpp"
#include "WinCape.hpp"
namespace WinCape
{
	class Manager
	{
	private:
		Manager();
	public:
		int startListening();
		void listenEvent(Base::Handle handle, WindowMessage message, const EventCallback& callback);
		void unlistenEvent(Base::Handle handle, WindowMessage message);
		void defaultFont(const Char* fontName);
		FontHandle defaultFont();
		void registerClass();
		Base::Handle createHandle(const Char* className, const Char* text, const WindowStyle& style, const Rect& rect, Base::Handle parent = NULL);
		static Manager& instance();
	};
}