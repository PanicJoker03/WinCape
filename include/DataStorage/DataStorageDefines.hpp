#ifndef DATASTORAGE_DEFINES_HPP
#define DATASTORAGE_DEFINES_HPP
#include "defines.hpp"
namespace WinCape{
namespace DataStorage{
    namespace DesiredAccesses {
        enum {
            GENERIC_READ = GENERIC_READ,
            GENERIC_WRITE = GENERIC_WRITE,
            GENERIC_READ_WRITE = GENERIC_READ | GENERIC_WRITE
        };
    }
}}
#endif
