#ifndef ALU
#define ALU

typedef struct ALU {
    //input
    int operand1 : 32;
    int operand2 : 32;
    unsigned int aluOp : 4;
    //output
    int result : 32;
    unsigned int zeroFlag : 1;
} Alu;

//initialize the ALU
void Alu_Init(Alu* alu);

//set the first operand
void Alu_setOperand1(Alu* alu, int operand);

//set the second operand
void Alu_setOperand2(Alu* alu, int operand);

//set the operation
void Alu_setOperation(Alu* alu, unsigned int operation);

#endif // !ALU
