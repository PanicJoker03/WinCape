#include "Ui/Base.h"
namespace w_cape{
namespace ui{
	//-------------------------------------------------------------------------
	//Base
	//-------------------------------------------------------------------------
	Base::Base() {}
	void Base::setText(WCH_STR_CONST text)
	{
		SetWindowTextW(handle(), text);
	}
	void Base::getText(WCH_STR text, int lenght) const
	{
		GetWindowTextW(handle(), text, lenght);
		//return text;
	}
}}
