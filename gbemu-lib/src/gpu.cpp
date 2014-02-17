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
   if (other.vram_) 
   {
       powerOff();
       powerOn();
       std::memcpy(vram_, other.vram_, vramSize);
   }
}

GPU::~GPU()
{
    assert(vram_ && "error: destroyed GPU without powering it off");
}

void GPU::powerOn()
{
    vram_ = new uint8_t[vramSize];
#ifndef NDEBUG
    // Initialize the vram to something noticeable
    for (std::size_t i=0; i<vramSize/sizeof(uint32_t); ++i)
        reinterpret_cast<uint32_t*>(vram_)[i] = 0xDEADBEEF;
#endif
}

void GPU::powerOff()
{
    delete [] vram_;
    vram_ = 0;
}

const uint8_t* GPU::vram() const
{
    return vram_;
}

uint8_t* GPU::vram()
{
    return vram_;
}

void GPU::dump(std::ostream& stream) const
{
    assert(vram_ && "error: tried to use GPU without powering it on");
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
