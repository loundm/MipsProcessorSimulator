#ifndef EXMEM
#define EXMEM

typedef struct ExMem {
	unsigned int memToRegFlag : 1;
	unsigned int regWriteFlag : 1;
	unsigned int branchFlag : 1;
	unsigned int memReadFlag : 1;
	unsigned int memWriteFlag : 1;
	unsigned int branchSum : 32;
	unsigned int zeroFlag : 1;
	int aluResult : 32;
	int memWriteData : 32;
	unsigned int writeReg : 5;
} ExMem;

//initialize the EX/MEM pipeline register
void ExMem_Init(ExMem* exMem);

void ExMem_setMemToRegFlagField(ExMem* exMem, unsigned int memToRegFlag);

void ExMem_setRegWriteFlagField(ExMem* exMem, unsigned int regWriteFlag);

void ExMem_setBranchFlagField(ExMem* exMem, unsigned int brnchFlag);

void ExMem_setMemReadFlagField(ExMem* exMem, unsigned int memReadFlag);

void ExMem_setMemWriteFlagField(ExMem* exMem, unsigned int memWriteFlag);

void ExMem_setBranchSum(ExMem* exMem, unsigned int brnchSum);

void ExMem_setZeroFlagField(ExMem* exMem, unsigned int zeroFlag);

void ExMem_setAluResult(ExMem* exMem, int aluResult);

void ExMem_setMemWriteData(ExMem* exMem, int memWriteData);

void ExMem_setWriteReg(ExMem* exMem, unsigned int writeReg);

#endif // !EXMEM
