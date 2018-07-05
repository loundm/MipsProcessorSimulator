#include "ALU.h"
#include "ALUOp.h"


void evaluate(Alu* alu) {

    if (alu->aluOp == AND) {
        alu->result = alu->operand1 & alu->operand2;
    } else if (alu->aluOp == OR) {
        alu->result = alu->operand1 | alu->operand2;
    } else if (alu->aluOp == ADD) {
        alu->result = alu->operand1 + alu->operand2;
    } else if (alu->aluOp == SUB) {
        alu->result = alu->operand1 - alu->operand2;
    } else if (alu->aluOp == SLT) {
        alu->result = alu->operand1 < alu->operand2;
    } else if (alu->aluOp == NOR) {
        alu->result = !(alu->operand1 | alu->operand2);
    }
    alu->zeroFlag = alu->result == 0;

}

void Alu_Init(Alu* alu) {

	alu->operand1 = 0;
	alu->operand2 = 0;
	alu->aluOp = 0;
	alu->result = 0;
	alu->zeroFlag = 0;

}

void Alu_setOperand1(Alu* alu, int operand) {

    alu->operand1 = operand;
    evaluate(alu);

}

void Alu_setOperand2(Alu* alu, int operand) {

    alu->operand2 = operand;
    evaluate(alu);

}

void Alu_setOperation(Alu* alu, unsigned int operation) {

    alu->aluOp = operation;
    evaluate(alu);

}