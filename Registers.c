#include "Registers.h"

void updateRegisters(Regs* regs) {

    if (regs->regWriteFlag) {
        regs->registers[regs->writeRegister] = regs->writeData;
    }

}

void Regs_Init(Regs* regs) {

	regs->readRegister1 = 0;
	regs->readRegister2 = 0;
	regs->writeRegister = 0;
	regs->writeData = 0;
	regs->regWriteFlag = 0;
	for (int i = 0; i < 32; i++) {
		regs->registers[i] = 0;
	}
	regs->readData1 = 0;
	regs->readData2 = 0;

}

void Regs_setReadRegister1(Regs* regs, unsigned int _register) {

    regs->readRegister1 = _register;
    regs->readData1 = regs->registers[regs->readRegister1];

}

void Regs_setReadRegister2(Regs* regs, unsigned int _register) {

    regs->readRegister2 = _register;
    regs->readData2 = regs->registers[regs->readRegister2];

}

void Regs_setWriteRegister(Regs* regs, unsigned int _register) {

    regs->writeRegister = _register;

}

void Regs_setWriteData(Regs* regs, int data) {

    regs->writeData = data;
    updateRegisters(regs);

}

void Regs_setRegWriteFlag(Regs* regs, unsigned int state) {

    regs->regWriteFlag = state;

}