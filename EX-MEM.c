#include "EX-MEM.h"

void ExMem_Init(ExMem* exMem) {

	exMem->memToRegFlag = 0;
	exMem->regWriteFlag = 0;
	exMem->branchFlag = 0;
	exMem->memReadFlag = 0;
	exMem->memWriteFlag = 0;
	exMem->branchSum = 0;
	exMem->zeroFlag = 0;
	exMem->aluResult = 0;
	exMem->memWriteData = 0;
	exMem->writeReg = 0;

}

void ExMem_setMemToRegFlagField(ExMem* exMem, unsigned int memToRegFlag) {

	exMem->memToRegFlag = memToRegFlag;

}

void ExMem_setRegWriteFlagField(ExMem* exMem, unsigned int regWriteFlag) {

	exMem->regWriteFlag = regWriteFlag;

}

void ExMem_setBranchFlagField(ExMem* exMem, unsigned int brnchFlag) {

	exMem->branchFlag = brnchFlag;

}

void ExMem_setMemReadFlagField(ExMem* exMem, unsigned int memReadFlag) {

	exMem->memReadFlag = memReadFlag;

}

void ExMem_setMemWriteFlagField(ExMem* exMem, unsigned int memWriteFlag) {

	exMem->memWriteFlag = memWriteFlag;

}

void ExMem_setBranchSum(ExMem* exMem, unsigned int brnchSum) {

	exMem->branchSum = brnchSum;

}

void ExMem_setZeroFlagField(ExMem* exMem, unsigned int zeroFlag) {

	exMem->zeroFlag = zeroFlag;

}

void ExMem_setAluResult(ExMem* exMem, int aluResult) {

	exMem->aluResult = aluResult;

}

void ExMem_setMemWriteData(ExMem* exMem, int memWriteData) {

	exMem->memWriteData = memWriteData;

}

void ExMem_setWriteReg(ExMem* exMem, unsigned int writeReg) {

	exMem->writeReg = writeReg;

}