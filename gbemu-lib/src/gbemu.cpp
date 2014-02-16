#include <gbemu/gbemu.h>
#include <gbemu/gameboy.h>
#include <gbemu/cpu.h>
#include <gbemu/mmu.h>
#include <gbemu/cartridge.h>

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <sstream>

#define STR(x) #x
#define XSTR(x) STR(x)

namespace gbemu {

const std::string& version()
{

    static const std::string v = XSTR(GBEMU_VERSION_MAJOR) "." \
                                 XSTR(GBEMU_VERSION_MINOR) "." \
                                 XSTR(GBEMU_VERSION_PATCH);
    return v;
}

} // namespace gbemu

