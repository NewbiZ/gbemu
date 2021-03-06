#include <gbemu/cartridge.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

static inline std::string bytesToHuman(std::size_t size)
{
    int i = 0;
    static const char* units[] = {"B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
    while (size>1024 && ++i)
        size /= 1024;
    std::ostringstream oss;
    oss << size << units[i];
    return oss.str();
}

namespace gbemu {

Cartridge::Cartridge(const std::string& filename)
{
    load(filename);
}

Cartridge::~Cartridge()
{
    delete [] data_;
}

void Cartridge::load(const std::string& filename)
{
    std::ifstream file;

    file.open(filename.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
    assert(file.good() && "cannot read cartridge file");

    size_ = file.tellg();
    file.seekg(0, std::ios::beg);

    data_ = new unsigned char[size_];
    file.read((char*)data_, size_);

    file.close();
}

bool Cartridge::isLegit() const
{
    // Every legit Nintendo cartridge should contain this
    // logo.
    static const unsigned char logo[] = {
        0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B,
        0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D,
        0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E,
        0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99,
        0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC,
        0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E,
    };

    // Logo should be between [0x0104-0x0133]
    static const std::size_t logoStartPos = 0x0104;
    static const std::size_t logoEndPos = 0x0133;
    for (std::size_t p=logoStartPos; p<=logoEndPos; ++p)
    {
        if (data_[p]!=logo[p-logoStartPos])
            return false;
    }

    return true;
}

std::size_t Cartridge::size() const
{
    return size_;
}

std::string Cartridge::title() const
{
    // Cartridge should contain the game title ASCII
    // uppercase letters at [0x0134-0x0143]
    static const std::size_t titlePos = 0x0134;
    return std::string((char*)data_+titlePos, 0x0F);
}

Cartridge::Type Cartridge::type() const
{
    // Cartridge type should be located at 0x0147. See
    // header for listing of different types & their meanings
    static const std::size_t typePos = 0x0147;
    return (Cartridge::Type)data_[typePos];
}

unsigned int Cartridge::ROMSize() const
{
    // Cartridge ROM size should be located at 0x0148.
    // Size is expressed as power of 32k.
    // TODO: if power is 0x52, 0x53 or 0x54 then size
    // is hardcoded.
    static const std::size_t ROMSizePos = 0x0148;
    return (32 << data_[ROMSizePos]) * 1024;
}

unsigned short Cartridge::RAMSize() const
{
    // Size of the external cartridge RAM,
    // located at 0x0149.
    static const std::size_t RAMSizePos = 0x0149;
    unsigned char RAMSize = data_[RAMSizePos];
    std::size_t RAMSizes[] = {0, 2*1024, 8*1024, 32*1024};
    return RAMSizes[RAMSize];
}

unsigned char Cartridge::headerChecksum() const
{
    // 8bit checksum of the cartridge header
    static const std::size_t headerChecksumPos = 0x014D;
    return data_[headerChecksumPos];
}

unsigned short Cartridge::cartridgeChecksum() const
{
    // 16bit checksum of the whole cartridge
    static const std::size_t cartridgeChecksumStartPos = 0x014E;
    return (data_[cartridgeChecksumStartPos]<<8) | data_[cartridgeChecksumStartPos+1];
}

bool Cartridge::isHeaderChecksumValid() const
{
    static const std::size_t headerStartPos = 0x0134;
    static const std::size_t headerEndPos = 0x014C;
    char checksum = 0;
    for (std::size_t pos=headerStartPos; pos<=headerEndPos; ++pos)
        checksum = checksum-data_[pos]-1;
    return checksum==headerChecksum();
}

bool Cartridge::isCartridgeChecksumValid() const
{
    static const std::size_t cartridgeStartPos = 0;
    static const std::size_t cartridgeEndPos = size_-1;
    static const std::size_t cartridgeChecksumStartPos = 0x014E;
    static const std::size_t cartridgeChecksumEndPos = 0x014F;
    unsigned short checksum = 0;
    for (std::size_t pos=cartridgeStartPos; pos<=cartridgeEndPos; ++pos)
        if (pos!=cartridgeChecksumStartPos && pos!=cartridgeChecksumEndPos)
            checksum += data_[pos];
    return checksum==cartridgeChecksum();
}

const uint8_t* Cartridge::data() const
{
    return data_;
}

void Cartridge::dump(std::ostream& stream) const
{
    stream << "Title: " << title() << std::endl;
    stream << "Legit: " << (isLegit() ? "yes" : "no") << std::endl;
    stream << "Type: ";
    std::cout << std::hex;
    switch (type())
    {
#define X(NAME, CODE)                               \
        case CODE:                                  \
            stream << #NAME  << " (0x"              \
                   << CODE << ")" << std::endl;     \
            break;
        GBEMU_CARTRIDGE_TYPES
#undef X
        default:
            stream << "UNKNOWN (0x"
                   << (unsigned int)type() << ")"
                   << std::endl;
            break;
    };
    std::cout << std::dec;
    stream << "ROM size: " << bytesToHuman(ROMSize()) << std::endl;
    stream << "RAM size: " << bytesToHuman(RAMSize()) << std::endl;
    std::cout << std::hex;
    stream << "Header checksum: 0x" << (unsigned int)headerChecksum() << std::endl;
    stream << "Cartridge checksum: 0x" << (unsigned int)cartridgeChecksum() << std::endl;
    std::cout << std::dec;
    stream << "Header checksum valid? " << (isHeaderChecksumValid() ? "yes" : "no") << std::endl;
    stream << "Cartridge checksum valid? " << (isCartridgeChecksumValid() ? "yes" : "no") << std::endl;
}

} // namespace gbemu

