#ifndef DMEM
#define DMEM

#include <inttypes.h>

typedef struct D_MEM {
    //input
    unsigned int address : 32;
    int writeData : 32;
    unsigned int memReadFlag : 1;
    unsigned int memWriteFlag : 1;
    //storage
    int8_t* data;
    //output
    int readData : 32;
} DMem;

//initialize the data memory
void DMem_Init(DMem* dMem);

//destroy the data memory
void DMem_Destroy(DMem* dMem);

//set the address
void DMem_setAddress(DMem* dMem, unsigned int address);

//set the write data
void DMem_setWriteData(DMem* dMem, int data);

//set the memory read flag
void DMem_setMemReadFlag(DMem* dMem, unsigned int state);

//set the memory write flag
void DMem_setMemWriteFlag(DMem* dMem, unsigned int state);

#endif // !DMEM
