#ifndef WINCAPE_HPP
#define WINCAPE_HPP
#include "defaults.hpp"
#include "DataStorage.hpp"
#include "Gui.hpp"
#ifdef WINCAPE_USES_WGL
//#include "rendering.hpp"
#endif
#include "Application.hpp"

//TODO...
//Use lower case on static methods

namespace wcape{
	extern Application application;

namespace bse
{
	const usr::Window Console();
}}
#endif
