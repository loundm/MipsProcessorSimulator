#include "ID-EX.h"

void IdEx_Init(IdEx* idEx) {

	idEx->memToRegFlag = 0;
	idEx->regWriteFlag = 0;
	idEx->branchFlag = 0;
	idEx->memReadFlag = 0;
	idEx->memWriteFlag = 0;
	idEx->regDstFlag = 0;
	idEx->aluOpFlags = 0;
	idEx->aluSrcFlag = 0;
	idEx->pc = 0;
	idEx->regReadData1 = 0;
	idEx->regReadData2 = 0;
	idEx->immediate = 0;
	idEx->rs = 0;
	idEx->rt = 0;
	idEx->rd = 0;

}

void IdEx_setMemToRegFlagField(IdEx* idEx, unsigned int memToRegFlag) {

	idEx->memToRegFlag = memToRegFlag;

}

void IdEx_setRegWriteFlagField(IdEx* idEx, unsigned int regWriteFlag) {

	idEx->regWriteFlag = regWriteFlag;

}

void IdEx_setBranchFlagField(IdEx* idEx, unsigned int brnchFlag) {

	idEx->branchFlag = brnchFlag;

}

void IdEx_setMemReadFlagField(IdEx* idEx, unsigned int memReadFlag) {

	idEx->memReadFlag = memReadFlag;

}

void IdEx_setMemWriteFlagField(IdEx* idEx, unsigned int memWriteFlag) {

	idEx->memWriteFlag = memWriteFlag;

}

void IdEx_setRegDstFlagField(IdEx* idEx, unsigned int regDstFlag) {

	idEx->regDstFlag = regDstFlag;

}

void IdEx_setAluOpFlagsField(IdEx* idEx, unsigned int aluOpFlags) {

	idEx->aluOpFlags = aluOpFlags;

}

void IdEx_setAluSrcFlagField(IdEx* idEx, unsigned int aluSrcFlag) {

	idEx->aluSrcFlag = aluSrcFlag;

}

void IdEx_setPcField(IdEx* idEx, unsigned int pc) {

	idEx->pc = pc;

}

void IdEx_setRegReadData1Field(IdEx* idEx, int regReadData1) {

	idEx->regReadData1 = regReadData1;

}

void IdEx_setRegReadData2Field(IdEx* idEx, int regReadData2) {

	idEx->regReadData2 = regReadData2;

}

void IdEx_setImmediateField(IdEx* idEx, int imm) {

	idEx->immediate = imm;

}

void IdEx_setRsField(IdEx* idEx, unsigned int rs) {

	idEx->rs = rs;

}

void IdEx_setRtField(IdEx* idEx, unsigned int rt) {

	idEx->rt = rt;

}

void IdEx_setRdField(IdEx* idEx, unsigned int rd) {

	idEx->rd = rd;

}