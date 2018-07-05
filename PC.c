#include "PC.h"

void Pc_Init(Pc* pc) {

	pc->pc = 0;
	pc->pcWriteFlag = 1;

}

void Pc_setNewPc(Pc* pc, unsigned int newPc) {

	if (pc->pcWriteFlag) {
		pc->pc = newPc;
	}

}

void Pc_setPcWriteFlag(Pc* pc, unsigned int pcWriteFlag) {

	pc->pcWriteFlag = pcWriteFlag;

}