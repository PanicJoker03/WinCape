#include <defines.hpp>
namespace Utility
{
	extern int o = 0;
	wchar_t* toWchar_t(const char* str)
	{
		WCHAR* buffer; 
		int nChars = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
		buffer = new WCHAR[nChars];
		MultiByteToWideChar(CP_ACP, 0, str, -1, (LPWSTR)buffer, nChars);
		return buffer;
	}
}