#ifndef GBEMU_CPU_H
#define GBEMU_CPU_H

#include <iosfwd>

namespace gbemu {

class CPU
{
public:
    CPU();
    ~CPU();

public: // Power management
    void powerOn();
    void powerOff();

public: // Debug
    void dump(std::ostream& stream) const;

private: // Registers
    char A;
    char B;
    char C;
    char D;
    char E;
    char F;
    char H;
    char L;
    short SP;
    short PC;
};

} // namespace gbemu

#endif // GBEMU_CPU_H

