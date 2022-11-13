#ifndef DATASTORAGE_DEFINES_H
#define DATASTORAGE_DEFINES_H
#include "defines.h"
namespace w_cape{
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
