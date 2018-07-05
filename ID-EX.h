#ifndef IDEX
#define IDEX

typedef struct IdEx {
	unsigned int memToRegFlag : 1;
	unsigned int regWriteFlag : 1;
	unsigned int branchFlag : 1;
	unsigned int memReadFlag : 1;
	unsigned int memWriteFlag : 1;
	unsigned int regDstFlag : 1;
	unsigned int aluOpFlags : 2;
	unsigned int aluSrcFlag : 1;
	unsigned int pc : 32;
	int regReadData1 : 32;
	int regReadData2 : 32;
	int immediate : 32;
	unsigned int rs : 5;
	unsigned int rt : 5;
	unsigned int rd : 5;
} IdEx;

//initialize the ID/EX pipeline register
void IdEx_Init(IdEx* idEx);

void IdEx_setMemToRegFlagField(IdEx* idEx, unsigned int memToRegFlag);

void IdEx_setRegWriteFlagField(IdEx* idEx, unsigned int regWriteFlag);

void IdEx_setBranchFlagField(IdEx* idEx, unsigned int brnchFlag);

void IdEx_setMemReadFlagField(IdEx* idEx, unsigned int memReadFlag);

void IdEx_setMemWriteFlagField(IdEx* idEx, unsigned int memWriteFlag);

void IdEx_setRegDstFlagField(IdEx* idEx, unsigned int regDstFlag);

void IdEx_setAluOpFlagsField(IdEx* idEx, unsigned int aluOpFlags);

void IdEx_setAluSrcFlagField(IdEx* idEx, unsigned int aluSrcFlag);

void IdEx_setPcField(IdEx* idEx, unsigned int pc);

void IdEx_setRegReadData1Field(IdEx* idEx, int regReadData1);

void IdEx_setRegReadData2Field(IdEx* idEx, int regReadData2);

void IdEx_setImmediateField(IdEx* idEx, int imm);

void IdEx_setRsField(IdEx* idEx, unsigned int rs);

void IdEx_setRtField(IdEx* idEx, unsigned int rt);

void IdEx_setRdField(IdEx* idEx, unsigned int rd);

#endif // !IDEX
