#include <gbemu/cpu.h>

namespace gbemu {

CPU::CPU()
{
}

CPU::~CPU()
{
}

void CPU::powerOn()
{
    PC = 0x100;
    SP = 0xFFFE;
}

void CPU::powerOff()
{
}

void CPU::dump(std::ostream& stream) const
{
}
    
} // namespace cpu
