#ifndef ALUCTRL
#define ALUCTRL

typedef struct ALUControl {
    //input
    unsigned int function : 6;
    unsigned int aluOpFlags : 2;
    //output
    unsigned int aluOp : 4;
} AluCtrl;

//initialize the ALU control
void AluCtrl_Init(AluCtrl* aluCtrl);

//set the function
void AluCtrl_setFunction(AluCtrl* aluCtrl, unsigned int function);

//set the operation flags
void AluCtrl_setALUOpFlags(AluCtrl* aluCtrl, unsigned int aluOpFlags);

#endif // !ALUCTRL
