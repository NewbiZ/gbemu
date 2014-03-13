#include <gbemu/gpu.h>

#include <cassert>
#include <iostream>
#include <cstring>

namespace gbemu {

GPU::GPU() :
    vram_(0)
{
}

GPU::GPU(const GPU& other) :
    vram_(0)
{
    *this = other;
}

GPU::~GPU()
{
    assert(!isPowered() && "error: released GPU without powering it OFF");
}

GPU& GPU::operator=(const GPU& other)
{
    if (this==&other)
        return *this;

    if (other.isPowered())
    {
        if (isPowered())
            powerOff();
        powerOn();
        std::memcpy(vram_, other.vram_, vramSize);
    }
    else // !other.isPowered()
    {
        if (isPowered())
            powerOff();
    }

    return *this;
}

void GPU::powerOn()
{
    assert(!isPowered() && "error: powering ON GPU while already powered ON");
    // Allocate video RAM
    vram_ = new uint8_t[vramSize];
#ifndef NDEBUG
    // Initialize the vram to something noticeable
    for (std::size_t i=0; i<vramSize/sizeof(uint32_t); ++i)
        reinterpret_cast<uint32_t*>(vram_)[i] = 0xEFBEADDE;
#endif
}

bool GPU::isPowered() const
{
    return vram_;
}

void GPU::powerOff()
{
    assert(isPowered() && "error: powering OFF GPU while not powered ON");
    delete [] vram_;
    vram_ = 0;
}

const uint8_t* GPU::vram() const
{
    assert(isPowered() && "error: accessing GPU VRAM while powered OFF");
    return vram_;
}

uint8_t* GPU::vram()
{
    assert(isPowered() && "error: accessing GPU VRAM while powered OFF");
    return vram_;
}

void GPU::dump(std::ostream& stream) const
{
    assert(isPowered() && "error: dumping GPU while powered OFF");
    static const unsigned int columns = 32;
    stream << std::hex << std::uppercase;
    for (unsigned int i = 0; i<vramSize; ++i)
    {
        if (i%columns == 0)
            stream << std::endl;
        stream << " 0x" << (unsigned int)vram_[i];
    }
    stream << std::endl;
    stream << std::dec << std::nouppercase;
}
    
} // namespace gpu
