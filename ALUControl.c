#include "ALUControl.h"
#include "ALUOp.h"

#define AND 0b0000
#define OR 0b0001
#define ADD 0b0010
#define SUB 0b0110
#define SLT 0b0111
#define NOR 0b1100

void evaluateOp(AluCtrl* aluCtrl) {

    int aluOpFlag0 = aluCtrl->aluOpFlags & 0b01;
    int aluOpFlag1 = aluCtrl->aluOpFlags & 0b10;
    if (aluOpFlag0) { //X1
        aluCtrl->aluOp = ADD;
    }
    else if (aluOpFlag1) { //1X
        if (!(aluCtrl->function & 0b001111)) { //XX0000
            aluCtrl->aluOp = ADD;
        } else if (aluCtrl->function & 0b000010 && !(aluCtrl->function & 0b001101)) { //XX0010
            aluCtrl->aluOp = SUB;
        } else if (aluCtrl->function & 0b000100 && !(aluCtrl->function & 0b001011)) { //XX0100
            aluCtrl->aluOp = AND;
        } else if (aluCtrl->function & 0b000101 && !(aluCtrl->function & 0b001010)) { //XX0101
            aluCtrl->aluOp = OR;
        } else if (aluCtrl->function & 0b001010 && !(aluCtrl->function & 0b000101)) { //XX1010
            aluCtrl->aluOp = SLT;
        }
    }
    else { //00
        aluCtrl->aluOp = ADD;
    }

}

void AluCtrl_Init(AluCtrl* aluCtrl) {
	
	aluCtrl->function = 0;
	aluCtrl->aluOpFlags = 0;
	aluCtrl->aluOp = 0;

}

void AluCtrl_setFunction(AluCtrl* aluCtrl, unsigned int function) {

    aluCtrl->function = function;
    evaluateOp(aluCtrl);

}

void AluCtrl_setALUOpFlags(AluCtrl* aluCtrl, unsigned int aluOpFlags) {

    aluCtrl->aluOpFlags = aluOpFlags;
    evaluateOp(aluCtrl);

}