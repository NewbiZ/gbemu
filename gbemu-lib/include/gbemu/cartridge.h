#ifndef GBEMU_CARTRIDGE_H
#define GBEMU_CARTRIDGE_H

#include <string>
#include <cstdlib>
#include <iosfwd>

#include <gbemu/gbemu.h>

namespace gbemu {

#define GBEMU_CARTRIDGE_TYPES        \
    X(ROM_ONLY,                0x00) \
    X(MBC1,                    0x01) \
    X(MBC1_RAM,                0x02) \
    X(MBC1_RAM_BATTERY,        0x03) \
    X(MBC2,                    0x05) \
    X(MBC2_BATTERY,            0x06) \
    X(ROM_RAM,                 0x08) \
    X(ROM_RAM_BATTERY,         0x09) \
    X(MMM01,                   0x0B) \
    X(MMM01_RAM,               0x0C) \
    X(MMM01_RAM_BATTERY,       0x0D) \
    X(MBC3_TIMER_BATTERY,      0x0F) \
    X(MBC3_TIMER_RAM_BATTERY,  0x10) \
    X(MBC3,                    0x11) \
    X(MBC3_RAM,                0x12) \
    X(MBC3_RAM_BATTERY,        0x13) \
    X(MBC4,                    0x15) \
    X(MBC4_RAM,                0x16) \
    X(MBC4_RAM_BATTERY,        0x17) \
    X(MBC5,                    0x19) \
    X(MBC5_RAM,                0x1A) \
    X(MBC5_RAM_BATTERY,        0x1B) \
    X(MBC5_RUMBLE,             0x1C) \
    X(MBC5_RUMBLE_RAM,         0x1D) \
    X(MBC5_RUMBLE_RAM_BATTERY, 0x1E) \
    X(POCKET_CAMERA,           0xFC) \
    X(BANDAI_TAMA5,            0xFD) \
    X(HUC3,                    0xFE) \
    X(HUC1_RAM_BATTERY,        0xFF)

class Cartridge
{
public:
    enum Type
    {
#define X(NAME, CODE) NAME = CODE,
        GBEMU_CARTRIDGE_TYPES
#undef X
    };

public:
    Cartridge(const std::string& filename);
    ~Cartridge();

public:
    std::size_t size() const;
    std::string title() const;
    Cartridge::Type type() const;
    unsigned int ROMSize() const;
    unsigned short RAMSize() const;
    unsigned char headerChecksum() const;
    unsigned short cartridgeChecksum() const;

    bool isLegit() const;
    bool isHeaderChecksumValid() const;
    bool isCartridgeChecksumValid() const;

public:
    const uint8_t* data() const;

public: // Debug
    void dump(std::ostream& stream) const;

protected:
    void load(const std::string& filename);

private:
    std::size_t size_;
    unsigned char* data_;
};

} // namespace gbemu

#endif // GBEMU_CARTRIDGE_H

