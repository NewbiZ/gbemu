#ifndef GBEMU_GPU_H
#define GBEMU_GPU_H

namespace gbemu {
   
class GPU
{
public:
    GPU();
    ~GPU();

public:
    void powerOn();
    void powerOff();
};

} // namespace gbemu

#endif // GBEMU_GPU_H

