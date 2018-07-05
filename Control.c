#include "Control.h"

#define MEMORY_FLAGS 0b00
#define BRANCH_FLAGS 0b01
#define R_TYPE_FLAGS 0b10

int evaluateAluOpFlags(Control* ctrl) {

    int aluOpFlags;
    if (ctrl->opCode & 0b100000) { //1XXXXX
        aluOpFlags = MEMORY_FLAGS;
    } else if (!(ctrl->opCode & 0b101000) && ctrl->opCode & 0b111) { //0X0XX1, 0X0X1X, 0X01XX
        aluOpFlags = BRANCH_FLAGS;
    } else { //0X0000
        aluOpFlags = R_TYPE_FLAGS;
    }
    return aluOpFlags;

}

void Control_Init(Control* ctrl) {

	ctrl->opCode = 0;
	ctrl->regDstFlag = 0;
	ctrl->branchFlag = 0;
	ctrl->memReadFlag = 0;
	ctrl->memToRegFlag = 0;
	ctrl->aluOpFlags = 0;
	ctrl->memWriteFlag = 0;
	ctrl->aluSrcFlag = 0;
	ctrl->regWriteFlag = 0;

}

void Control_setOpCode(Control* ctrl, unsigned int opCode) {

	ctrl->opCode = opCode;
	if (!ctrl->ctrlNopFlag) {
		ctrl->regDstFlag = !(ctrl->opCode & 0b101000); //0X0XXX
		ctrl->branchFlag = !(ctrl->opCode & 0b101000) && ctrl->opCode & 0b000111; //0X0XX1, 0X0X1X, 0X01XX
		ctrl->memReadFlag = ctrl->opCode & 0b100000 && !(ctrl->opCode & 0b001000); //1X0XXX
		ctrl->memToRegFlag = ctrl->opCode & 0b1000000 != 0; //1XXXXX
		ctrl->aluOpFlags = evaluateAluOpFlags(ctrl);
		ctrl->memWriteFlag = ctrl->opCode & 0b100000 && ctrl->opCode & 0b001000; //1X1XXX
		ctrl->aluSrcFlag = ctrl->opCode != 0;
		ctrl->regWriteFlag = ctrl->opCode & 0b100000 && !(ctrl->opCode & 0b001000) //1X0XXX,
			|| !(ctrl->opCode & 0b100000) & ctrl->opCode & 0b001000                //0X1XXX,
			|| !(ctrl->opCode & 0b101000) & !(ctrl->opCode & 0b000111);             //0X0000
	}

}

void Control_setNopFlag(Control* ctrl, unsigned int ctrlNopFlag) {

	ctrl->ctrlNopFlag = ctrlNopFlag;
	if (ctrl->ctrlNopFlag) {
		ctrl->regDstFlag = 0;
		ctrl->branchFlag = 0;
		ctrl->memReadFlag = 0;
		ctrl->memToRegFlag = 0;
		ctrl->aluOpFlags = 0;
		ctrl->memWriteFlag = 0;
		ctrl->aluSrcFlag = 0;
		ctrl->regWriteFlag = 0;
	}

}