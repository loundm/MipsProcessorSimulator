#ifndef REGS
#define REGS

#include <inttypes.h>

typedef struct Registers {
    //input
    unsigned int readRegister1 : 5;
    unsigned int readRegister2 : 5;
    unsigned int writeRegister : 5;
    int writeData : 32;
    unsigned int regWriteFlag : 1;
    //storage
    int32_t registers[32];
    //output
    int readData1 : 32;
    int readData2 : 32;
} Regs;

//initialize the registers
void Regs_Init(Regs* regs);

//set the first read register
void Regs_setReadRegister1(Regs* regs, unsigned int _register);

//set the second read register
void Regs_setReadRegister2(Regs* regs, unsigned int _register);

//set the write register
void Regs_setWriteRegister(Regs* regs, unsigned int _register);

//set the write data
void Regs_setWriteData(Regs* regs, int data);

//set the register write flag
void Regs_setRegWriteFlag(Regs* regs, unsigned int state);

#endif // !REGS
