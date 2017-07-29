#include <defines.hpp>|
namespace WinCape
{
	class Manager
	{
	private:
		Manager();
	public:
		int startListening();
		void listenEvent(const Handle& handle, const WindowMessage& message, const EventCallback& callback);
		void defaultFont(const wchar_t* fontName);
		FontHandle defaultFont();
		void registerClass();
		Handle createHandle(const wchar_t* className, const wchar_t* text, const WindowStyle& style, const Rect& rect, const Handle& parent = NULL);
		static Manager& Instance();
	};
}