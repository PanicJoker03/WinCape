#ifndef CORE_HPP
#define CORE_HPP
#ifdef BUILDING_DLL
    #ifdef BUILDING_WINCAPE
    #define WINCAPE_API __declspec(dllexport)
    #else
    #define WINCAPE_API __declspec(dllimport)
    #endif // BUILDING_WINCAPE
#else
#endif // BUILDING_DLL
#endif // CORE_HPP
