#include "IF-ID.h"

void IfId_Init(IfId* ifId) {
	ifId->pc = 0;
	ifId->instruction = 0;
}

void IfId_setIfIdWrite(IfId* ifId, unsigned ifIdWrite) {

	ifId->ifidWrite = ifIdWrite;

}

//set the program counter field
void IfId_setPcField(IfId* ifId, unsigned int pc) {

	if (ifId->ifidWrite) {
		ifId->pc = pc;
	}

}

//set the instruction field
void IfId_setInstructionField(IfId* ifId, unsigned int instr) {

	if (ifId->ifidWrite) {
		ifId->instruction = instr;
	}

}