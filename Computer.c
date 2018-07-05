#include "Computer.h"

#define PC_INCREMENT 4
#define END_REACHED 1

void Computer_Init(Computer* comp) {

	Mux_Init(&comp->pcMux);
	Pc_Init(&comp->pc);
	Adder_Init(&comp->pcIncrementer);
	Adder_setAddend2(&comp->pcIncrementer, PC_INCREMENT);
	IMem_Init(&comp->iMem);
	IfId_Init(&comp->ifIdPipeReg);
	Hdu_Init(&comp->hdu);
	Control_Init(&comp->ctrl);
	Mux_Init(&comp->ctrlMux);
	Mux_setOption2(&comp->ctrlMux, 0);
	Regs_Init(&comp->regsBox);
	Sext_Init(&comp->sExt);
	IdEx_Init(&comp->idExPipeReg);
	Adder_Init(&comp->branchAdder);
	AluCtrl_Init(&comp->aluCtrl);
	Forwarding_Init(&comp->forwarding);
	Mux3_Init(&comp->regDataMux1);
	Mux3_Init(&comp->regDataMux2);
	Mux_Init(&comp->aluMux);
	Alu_Init(&comp->alu);
	Mux_Init(&comp->regDstMux);
	ExMem_Init(&comp->exMemPipeReg);
    DMem_Init(&comp->dMem);
	MemWb_Init(&comp->memWbPipeReg);
	Mux_Init(&comp->writeBackMux);

	comp->remainingCycles = -1;

	comp->regsBox.registers[1] = 0;
	comp->regsBox.registers[5] = 73;
	comp->regsBox.registers[6] = 6;

	uint32_t dataNumber = 2017;
	comp->dMem.data[20] = dataNumber >> 24;
	comp->dMem.data[21] = dataNumber >> 16 & 0xFF;
	comp->dMem.data[22] = dataNumber >> 8 & 0xFF;
	comp->dMem.data[23] = dataNumber & 0xFF;

}

void Computer_Destroy(Computer* comp) {

    IMem_Destroy(&comp->iMem);
    DMem_Destroy(&comp->dMem);

}

int executeIF(Computer* comp) {

	Pc_setNewPc(&comp->pc, comp->pcMux.choice);
    IMem_setReadAddress(&comp->iMem, comp->pc.pc);
	if (comp->iMem.instruction == 0) {
		return END_REACHED;
	}
	Adder_setAddend1(&comp->pcIncrementer, comp->pc.pc);
	Mux_setOption1(&comp->pcMux, comp->pcIncrementer.sum);

	IfId_setPcField(&comp->ifIdPipeReg, comp->pcIncrementer.sum);
	IfId_setInstructionField(&comp->ifIdPipeReg, comp->iMem.instruction);
	return !END_REACHED;

}

void executeID(Computer* comp) {

	unsigned int rs = comp->ifIdPipeReg.instruction >> 21 & 0b11111;
	Hdu_setIfIdRs(&comp->hdu, rs);
	unsigned int rt = comp->ifIdPipeReg.instruction >> 16 & 0b11111;
	Hdu_setIfIdRt(&comp->hdu, rt);
	Pc_setPcWriteFlag(&comp->pc, comp->hdu.pcWriteFlag);
	IfId_setIfIdWrite(&comp->ifIdPipeReg, comp->hdu.ifIdWriteFlag);
	Control_setNopFlag(&comp->ctrl, comp->hdu.ctrlNopFlag);
	
	unsigned int opCode = comp->ifIdPipeReg.instruction >> 26 & 0b111111;
	Control_setOpCode(&comp->ctrl, opCode);
	Regs_setReadRegister1(&comp->regsBox, rs);
	Regs_setReadRegister2(&comp->regsBox, rt);
	int immediate = comp->ifIdPipeReg.instruction & 0b1111111111111111;
	SExt_setInput(&comp->sExt, immediate);

	IdEx_setMemToRegFlagField(&comp->idExPipeReg, comp->ctrl.memToRegFlag);
	IdEx_setRegWriteFlagField(&comp->idExPipeReg, comp->ctrl.regWriteFlag);
	IdEx_setBranchFlagField(&comp->idExPipeReg, comp->ctrl.branchFlag);
	IdEx_setMemReadFlagField(&comp->idExPipeReg, comp->ctrl.memReadFlag);
	IdEx_setMemWriteFlagField(&comp->idExPipeReg, comp->ctrl.memWriteFlag);
	IdEx_setRegDstFlagField(&comp->idExPipeReg, comp->ctrl.regDstFlag);
	IdEx_setAluOpFlagsField(&comp->idExPipeReg, comp->ctrl.aluOpFlags);
	IdEx_setAluSrcFlagField(&comp->idExPipeReg, comp->ctrl.aluSrcFlag);
	IdEx_setPcField(&comp->idExPipeReg, comp->ifIdPipeReg.pc);
	IdEx_setRegReadData1Field(&comp->idExPipeReg, comp->regsBox.readData1);
	IdEx_setRegReadData2Field(&comp->idExPipeReg, comp->regsBox.readData2);
	IdEx_setImmediateField(&comp->idExPipeReg, comp->sExt.output);
	IdEx_setRsField(&comp->idExPipeReg, rs);
	IdEx_setRtField(&comp->idExPipeReg, rt);
	unsigned int rd = comp->iMem.instruction >> 11 & 0b11111;
	IdEx_setRdField(&comp->idExPipeReg, rd);

}

void executeEX(Computer* comp) {

	Hdu_setIdExMemRead(&comp->hdu, comp->idExPipeReg.memReadFlag);
	Hdu_setIdExRt(&comp->hdu, comp->idExPipeReg.rt);

	Mux_setSelect(&comp->regDstMux, comp->idExPipeReg.regDstFlag);
	AluCtrl_setALUOpFlags(&comp->aluCtrl, comp->idExPipeReg.aluOpFlags);
	Mux_setSelect(&comp->aluMux, comp->idExPipeReg.aluSrcFlag);
	Adder_setAddend1(&comp->branchAdder, comp->idExPipeReg.pc);
	Mux3_setOption1(&comp->regDataMux1, comp->idExPipeReg.regReadData1);
	Mux3_setOption1(&comp->regDataMux2, comp->idExPipeReg.regReadData2);
	Adder_setAddend2(&comp->branchAdder, comp->idExPipeReg.immediate << 2);
	Mux_setOption2(&comp->aluMux, comp->idExPipeReg.immediate);
	int function = comp->idExPipeReg.immediate & 0b111111;
	AluCtrl_setFunction(&comp->aluCtrl, function);
	Mux_setOption1(&comp->regDstMux, comp->idExPipeReg.rt);
	Mux_setOption2(&comp->regDstMux, comp->idExPipeReg.rd);

	Mux3_setOption2(&comp->regDataMux1, comp->writeBackMux.choice);
	Mux3_setOption2(&comp->regDataMux2, comp->writeBackMux.choice);
	Mux3_setOption3(&comp->regDataMux1, comp->exMemPipeReg.aluResult);
	Mux3_setOption3(&comp->regDataMux2, comp->exMemPipeReg.aluResult);
	Forwarding_setIdExRs(&comp->forwarding, comp->idExPipeReg.rs);
	Forwarding_setIdExRt(&comp->forwarding, comp->idExPipeReg.rt);

	Mux3_setSelect(&comp->regDataMux1, comp->forwarding.forwardA);
	Mux3_setSelect(&comp->regDataMux2, comp->forwarding.forwardB);
	Alu_setOperation(&comp->alu, comp->aluCtrl.aluOp);
	Alu_setOperand1(&comp->alu, comp->regDataMux1.choice);
	Mux_setOption1(&comp->aluMux, comp->regDataMux2.choice);
	Alu_setOperand2(&comp->alu, comp->aluMux.choice);

	ExMem_setMemToRegFlagField(&comp->exMemPipeReg, comp->idExPipeReg.memToRegFlag);
	ExMem_setRegWriteFlagField(&comp->exMemPipeReg, comp->idExPipeReg.regWriteFlag);
	ExMem_setBranchFlagField(&comp->exMemPipeReg, comp->idExPipeReg.branchFlag);
	ExMem_setMemReadFlagField(&comp->exMemPipeReg, comp->idExPipeReg.memReadFlag);
	ExMem_setMemWriteFlagField(&comp->exMemPipeReg, comp->idExPipeReg.memWriteFlag);
	ExMem_setBranchSum(&comp->exMemPipeReg, comp->branchAdder.sum);
	ExMem_setZeroFlagField(&comp->exMemPipeReg, comp->alu.zeroFlag);
	ExMem_setAluResult(&comp->exMemPipeReg, comp->alu.result);
	ExMem_setMemWriteData(&comp->exMemPipeReg, comp->idExPipeReg.regReadData2);
	ExMem_setWriteReg(&comp->exMemPipeReg, (unsigned int) comp->regDstMux.choice);

}

void executeMEM(Computer* comp) {

	Forwarding_setExMemRd(&comp->forwarding, comp->exMemPipeReg.writeReg);
	Forwarding_setExMemRegWrite(&comp->forwarding, comp->exMemPipeReg.regWriteFlag);
	
	Mux_setSelect(&comp->pcMux, comp->exMemPipeReg.branchFlag && comp->exMemPipeReg.zeroFlag);
	DMem_setMemWriteFlag(&comp->dMem, comp->exMemPipeReg.memWriteFlag);
	DMem_setMemReadFlag(&comp->dMem, comp->exMemPipeReg.memReadFlag);
	Mux_setOption2(&comp->pcMux, comp->exMemPipeReg.branchSum);
	DMem_setAddress(&comp->dMem, comp->exMemPipeReg.aluResult);
	DMem_setWriteData(&comp->dMem, comp->exMemPipeReg.memWriteData);

	MemWb_setMemToRegFlagField(&comp->memWbPipeReg, comp->exMemPipeReg.memToRegFlag);
	MemWb_setRegWriteFlagField(&comp->memWbPipeReg, comp->exMemPipeReg.regWriteFlag);
	MemWb_setMemReadData(&comp->memWbPipeReg, comp->dMem.readData);
	MemWb_setAluResult(&comp->memWbPipeReg, comp->exMemPipeReg.aluResult);
	MemWb_setWriteReg(&comp->memWbPipeReg, comp->exMemPipeReg.writeReg);

}

void executeWB(Computer* comp) {

	Forwarding_setMemWbRd(&comp->forwarding, comp->memWbPipeReg.writeReg);
	Forwarding_setMemWbRegWrite(&comp->forwarding, comp->memWbPipeReg.regWriteFlag);

	Regs_setRegWriteFlag(&comp->regsBox, comp->memWbPipeReg.regWriteFlag);
	Mux_setSelect(&comp->writeBackMux, comp->memWbPipeReg.memToRegFlag);
	Mux_setOption1(&comp->writeBackMux, comp->memWbPipeReg.aluResult);
	Mux_setOption2(&comp->writeBackMux, comp->memWbPipeReg.memReadData);
	Regs_setWriteRegister(&comp->regsBox, comp->memWbPipeReg.writeReg);

	Regs_setWriteData(&comp->regsBox, comp->writeBackMux.choice);

}

void Computer_execute(Computer* comp) {

	while (1) {
		executeWB(comp);
		executeMEM(comp);
		executeEX(comp);
		executeID(comp);
		if (executeIF(comp) == END_REACHED) {
			executeWB(comp);
			executeMEM(comp);
			executeEX(comp);
			executeWB(comp);
			executeMEM(comp);
			executeWB(comp);
			return;
		}
	}

}

int Computer_cycle(Computer* comp) {

	int computerFinished = 0;
	if (comp->remainingCycles == 3) {
		executeWB(comp);
		executeMEM(comp);
		executeEX(comp);
		comp->remainingCycles--;
	} else if (comp->remainingCycles == 2) {
		executeWB(comp);
		executeMEM(comp);
		comp->remainingCycles--;
	} else if (comp->remainingCycles == 1) {
		executeWB(comp);
		comp->remainingCycles--;
		computerFinished = 1;
	} else if (comp->remainingCycles < 0) {
		executeWB(comp);
		executeMEM(comp);
		executeEX(comp);
		executeID(comp);
		if (executeIF(comp) == END_REACHED) {
			comp->remainingCycles = 3;
		}
	}
	return computerFinished;

}