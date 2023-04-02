#include "Ui/Base.h"
namespace w_cape{
namespace ui{
	//-------------------------------------------------------------------------
	//Base
	//-------------------------------------------------------------------------
	Base::Base() {}
	void Base::setText(WCH_STR_CON text)
	{
		SetWindowTextW(handle(), text);
	}
	void Base::getText(WCH_STR text, int lenght) const
	{
		GetWindowTextW(handle(), text, lenght);
		//return text;
	}

	void Base::setProp(WCH_STR_CON prop, long val)
	{
		SetPropW(handle(), prop, (HANDLE)val);
	}
	
	void Base::setProp(WCH_STR_CON prop, int val)
	{
		SetPropW(handle(), prop, (HANDLE)val);
	}
	
	void Base::setProp(WCH_STR_CON prop, float val)
	{
		//hyper code hack
		union{
			float valF;
			long valL;
		}storeMy;
		storeMy.valF = val;
		SetPropW(handle(), prop, (HANDLE)storeMy.valL);
	}

	template<typename T>
	T Base::getProp(WCH_STR_CON prop)
	{
		throw "Not valid prop template type";
	}

	template<>
	long Base::getProp(WCH_STR_CON prop)
	{
		return (long)GetPropW(handle(), prop);
	}
	
	template<>
	int Base::getProp(WCH_STR_CON prop)
	{
		return (int)(long)GetPropW(handle(), prop);
	}
	
	template<>
	float Base::getProp(WCH_STR_CON prop)
	{
		union{
			float valF;
			long valL;
		}storeMy;
		storeMy.valL = (long)GetPropW(handle(), prop);
		return storeMy.valF;
	}
}}
