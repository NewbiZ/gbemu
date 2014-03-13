#include <cassert>

#include <gbemu/gameboy.h>

#include <gbemu/cartridge.h>
#include <gbemu/cpu.h>
#include <gbemu/mmu.h>

namespace gbemu {
    
GameBoy::GameBoy():
    cartridge_(0)
{
}

GameBoy::~GameBoy()
{
}

void GameBoy::insert(const Cartridge& cart)
{
    cartridge_ = &cart;
}

void GameBoy::eject()
{
}

void GameBoy::powerOn()
{
    assert(cartridge_ && "error: cannot start GameBoy without cartridge");
    cpu_.powerOn();
    gpu_.powerOn();
    mmu_.powerOn(gpu_, *cartridge_);
}

void GameBoy::powerOff()
{
    mmu_.powerOff();
    gpu_.powerOff();
    cpu_.powerOff();
}

} // namespace gbemu

