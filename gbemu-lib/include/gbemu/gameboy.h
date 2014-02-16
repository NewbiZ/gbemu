#ifndef GBEMU_GAMEBOY_H
#define GBEMU_GAMEBOY_H

#include <gbemu/cpu.h>
#include <gbemu/mmu.h>
#include <gbemu/gpu.h>

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
    CPU cpu_;
    MMU mmu_;
    GPU gpu_;
    const Cartridge* cartridge_;
};

} // namespace gbemu

#endif // GBEMU_GAMEBOY_H

