#ifndef GBEMU_GPU_H
#define GBEMU_GPU_H

#include <iosfwd>
#include <cstdint>

namespace gbemu {
   
class GPU
{
public:
    static const std::size_t vramSize = 0x2000;

public:
    GPU();
    GPU(const GPU& other);
    ~GPU();
    GPU& operator=(const GPU& other);

public:
    bool isPowered() const;
    void powerOn();
    void powerOff();

public:
    const uint8_t* vram() const;
    uint8_t*       vram();

public:
    void dump(std::ostream& stream) const;

private:
    uint8_t* vram_;
};

} // namespace gbemu

#endif // GBEMU_GPU_H

