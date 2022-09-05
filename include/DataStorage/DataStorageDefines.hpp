#ifndef DATASTORAGE_DEFINES_HPP
#define DATASTORAGE_DEFINES_HPP
#include "defines.hpp"
namespace cap{
namespace dst{
    namespace DesiredAccesses {
        enum {
            READ = 0x80000000L,
            WRITE = 0x40000000L,
            READ_WRITE = 0x80000000L | 0x40000000L
        };
    }
}}
#endif
