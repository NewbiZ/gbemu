#ifndef GBEMU_GAMEBOY_H
#define GBEMU_GAMEBOY_H

#include <gbemu/cpu.h>
#include <gbemu/mmu.h>

namespace gbemu {

class Cartridge;

class GameBoy
{
public:
    GameBoy();
    ~GameBoy();

public: // Cartridge management
    void insert(const Cartridge& cart);
    void eject();

public: // Power management
    void powerOn();
    void powerOff();

private:
    CPU cpu;
    MMU mmu;
    const Cartridge* cartridge;
};

} // namespace gbemu

#endif // GBEMU_GAMEBOY_H

