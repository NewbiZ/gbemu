#ifndef GBEMU_MMU_H
#define GBEMU_MMU_H

#include <iosfwd>

namespace gbemu {

// 0xFFFF           Interrupt Enable Flag
// 0xFF80 - 0xFFFE  Zero Page
// 0xFF00 - 0xFF7F  Hardware I/O Register
// 0xFEA0 - 0xFEFF  Unusable
// 0xFE00 - 0xFE9F  Object Attribute Memory
// 0xE000 - 0xFDFF  Echo RAM - Reserved
// 0xD000 - 0xDFFF  Internal RAM - Bank 1-7
// 0xC000 - 0xCFFF  Internal RAM - Bank 0
// 0xA000 - 0xBFFF  Cartridge RAM
// 0x9C00 - 0x9FFF  BG Map Data 2
// 0x9800 - 0x9BFF  BG Map Data 1
// 0x8000 - 0x97FF  Character RAM
// 0x4000 - 0x7FFF  Cartridge ROM - Switchable Bank 1-*
// 0x0150 - 0x3FFF  Cartridge ROM - Bank 0
// 0x0100 - 0x014F  Cartridge header
// 0x0000 - 0x00FF  Restart & Interrupt vectors

class MMU
{
public:
    MMU();
    ~MMU();

public: // Power management
    void powerOn();
    void powerOff();

public: // Debug
    void dump(std::ostream& stream) const;

private:
    unsigned char memory[0xFFFF];
};

} // namespace gbemu

#endif // GBEMU_MMU_H

