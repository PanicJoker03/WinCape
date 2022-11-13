#ifndef WINCAPE_H
#define WINCAPE_H
#include "defaults.h"
#include "DataStorage.h"
#include "Ui.h"
#ifdef WINCAPE_USES_WGL
//#include "rendering.h"
#endif
#include "Application.h"

//TODO...
//Use lower case on static methods

namespace w_cape{
	extern Application application;

namespace bse
{
	const ui::Window Console();
}}
#endif
