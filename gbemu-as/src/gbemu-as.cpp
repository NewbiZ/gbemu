#include <iostream>
#include <cstdlib>

#include <gbemu/gbemu.h>
#include <gbemu/cartridge.h>
#include <gbemu/gpu.h>

int main( int argc, char** argv )
{
    std::cout << "gbemu-as" << std::endl;
    std::cout << "Using gbemu-lib " << gbemu::version() << std::endl;
  
    if (argc!=2)
    {
        std::cerr << "usage: ./gbemu-as <assembly_file>" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

