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
		void defaultFont(const TextChar* fontName);
		FontHandle defaultFont();
		void registerClass();
		Base::Handle createHandle(const TextChar* className, const TextChar* text, const WindowStyle& style, const Rect& rect, Base::Handle parent = NULL);
		static Manager& instance();
	};
}