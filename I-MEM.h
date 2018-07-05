#ifndef IMEM
#define IMEM

#include <inttypes.h>

typedef struct I_MEM {
    //input
    unsigned int readAddress : 32;
    //storage
    uint8_t* instructions;
    //output
    unsigned int instruction : 32;
} IMem;

//initialize the instrction memory
void IMem_Init(IMem* iMem);

//destroy the instruction memory
void IMem_Destroy(IMem* iMem);

//set the read address
void IMem_setReadAddress(IMem* iMem, unsigned int address);

#endif // !IMEM
