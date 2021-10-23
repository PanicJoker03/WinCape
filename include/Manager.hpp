#include <defines.hpp>
#include <WinCape.hpp>
namespace WinCape
{
	class Manager
	{
	private:
		Manager();
	public:
		int startListening();
		void listenEvent(const Base::Handle& handle, const WindowMessage& message, const EventCallback& callback);
		void defaultFont(const Char* fontName);
		FontHandle defaultFont();
		void registerClass();
		Base::Handle createHandle(const Char* className, const Char* text, const WindowStyle& style, const Rect& rect, const Base::Handle& parent = NULL);
		static Manager& instance();
	};
}