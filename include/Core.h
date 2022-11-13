#ifndef CORE_H
#define CORE_H
#ifdef BUILDING_DLL
    #ifdef BUILDING_WINCAPE
    #define WINCAPE_API __declspec(dllexport)
    #else
    #define WINCAPE_API __declspec(dllimport)
    #endif // BUILDING_WINCAPE
#else
#endif // BUILDING_DLL
#endif // CORE_H
