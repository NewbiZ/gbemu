#include <iostream>
#include <cstdlib>

#include <gbemu/gbemu.h>

int main( int argc, char** argv )
{
  std::cout << "gbemu-as" << std::endl;
  std::cout << "Using gbemu-lib " << gbemu::version() << std::endl;
  
    if (argc!=2)
    {
        std::cerr << "usage: ./gbemu <cartridge_file>" << std::endl;
        return EXIT_FAILURE;
    }

    gbemu::Cartridge cart(argv[1]);
    gbemu::GameBoy gameboy;

    gameboy.insert(cart);
    gameboy.powerOn();
    gameboy.powerOff();
    gameboy.eject();
    
    return EXIT_SUCCESS;
}
