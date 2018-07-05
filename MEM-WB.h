#ifndef MEMWB
#define MEMWB

typedef struct MemWb {
	unsigned int memToRegFlag : 1;
	unsigned int regWriteFlag : 1;
	int memReadData : 32;
	int aluResult : 32;
	unsigned int writeReg : 5;
} MemWb;

//initialize the EX/MEM pipeline register
void MemWb_Init(MemWb* memWb);

void MemWb_setMemToRegFlagField(MemWb* memWb, unsigned int memToRegFlag);

void MemWb_setRegWriteFlagField(MemWb* memWb, unsigned int regWriteFlag);

void MemWb_setMemReadData(MemWb* memWb, int memReadData);

void MemWb_setAluResult(MemWb* memWb, int aluResult);

void MemWb_setWriteReg(MemWb* memWb, unsigned int writeReg);

#endif // !MEMWB
