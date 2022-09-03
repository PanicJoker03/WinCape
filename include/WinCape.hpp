#ifndef WINCAPE_HPP
#define WINCAPE_HPP
//#include "defines.hpp"
#include "defaults.hpp"

#include "Gui.hpp"
#ifdef WINCAPE_USES_WGL
#include "rendering.hpp"
#endif
#include "Application.hpp"

//TODO...
//Use lower case on static methods

namespace cape{
namespace Base
{
	const usr::Window Console();
}}
#endif
