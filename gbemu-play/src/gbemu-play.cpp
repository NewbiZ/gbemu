#include <iostream>
#include <cstdlib>

#include <gbemu/gbemu.h>
#include <gbemu/cartridge.h>
#include <gbemu/gpu.h>

int main( int argc, char** argv )
{
    std::cout << "gbemu-play" << std::endl;
    std::cout << "Using gbemu-lib " << gbemu::version() << std::endl;
  
    if (argc!=2)
    {
        std::cerr << "usage: ./gbemu-play <cartridge_file>" << std::endl;
        return EXIT_FAILURE;
    }

    gbemu::Cartridge cart(argv[1]);
    cart.dump(std::cout);
    
    return EXIT_SUCCESS;
}
