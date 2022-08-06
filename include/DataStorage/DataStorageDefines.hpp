#ifndef DATASTORAGE_DEFINES_HPP
#define DATASTORAGE_DEFINES_HPP
#include "defines.hpp"
namespace WinCape{
    namespace DataStorage{
        namespace DesiredAccesses {
            enum {
                GenericRead = GENERIC_READ,
                GeneridWrite = GENERIC_WRITE,
                Both = GENERIC_READ | GENERIC_WRITE
            };
        }
    }
}
#endif
