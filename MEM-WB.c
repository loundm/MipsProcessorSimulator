#include "MEM-WB.h"

//initialize the EX/MEM pipeline register
void MemWb_Init(MemWb* memWb) {

	memWb->memToRegFlag = 0;
	memWb->regWriteFlag = 0;
	memWb->memReadData = 0;
	memWb->aluResult = 0;
	memWb->writeReg = 0;

}

void MemWb_setMemToRegFlagField(MemWb* memWb, unsigned int memToRegFlag) {

	memWb->memToRegFlag = memToRegFlag;

}

void MemWb_setRegWriteFlagField(MemWb* memWb, unsigned int regWriteFlag) {

	memWb->regWriteFlag = regWriteFlag;

}

void MemWb_setMemReadData(MemWb* memWb, int memReadData) {

	memWb->memReadData = memReadData;

}

void MemWb_setAluResult(MemWb* memWb, int aluResult) {

	memWb->aluResult = aluResult;

}

void MemWb_setWriteReg(MemWb* memWb, unsigned int writeReg) {

	memWb->writeReg = writeReg;

}