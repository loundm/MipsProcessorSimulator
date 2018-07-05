#ifndef CTRL
#define CTRL

typedef struct Control {
    //input
	unsigned int ctrlNopFlag : 1;
    unsigned int opCode : 6;
    //output
    unsigned int regDstFlag : 1;
    unsigned int branchFlag : 1;
    unsigned int memReadFlag : 1;
    unsigned int memToRegFlag : 1;
    unsigned int aluOpFlags : 2;
    unsigned int memWriteFlag : 1;
    unsigned int aluSrcFlag : 1;
    unsigned int regWriteFlag : 1;
} Control;

//initialize the control
void Control_Init(Control* ctrl);

//sets the instruction
void Control_setOpCode(Control* ctrl, unsigned int opCode);

void Control_setNopFlag(Control* ctrl, unsigned int ctrlNopFlag);

#endif // !CTRL
