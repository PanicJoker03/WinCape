#ifndef DEFAULTS_HPP
#define DEFAULTS_HPP
#include "struct.hpp"
#include <memory>
namespace WinCape
{
	struct Defaults
	{
		constexpr const char* WindowName = "WinCape Window";
		constexpr Rect WindowRect = Rect{ 100, 100, 800, 600 };
		constexpr WindowStyle DefWindowStyle  = WindowStyle::OverlappedWindow;
	};
}
#endif // !DEFAULTS_HPP