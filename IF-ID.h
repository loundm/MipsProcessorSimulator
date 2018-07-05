#ifndef IFID
#define IFID

typedef struct IfId {
	unsigned int ifidWrite : 1;
	unsigned int pc : 32;
	unsigned int instruction : 32;
} IfId;

//initialize the IF/ID pipeline register
void IfId_Init(IfId* ifId);

void IfId_setIfIdWrite(IfId* ifId, unsigned int ifIdWrite);

//set the program counter field
void IfId_setPcField(IfId* ifId, unsigned int pc);

//set the instruction field
void IfId_setInstructionField(IfId* ifId, unsigned int instr);

#endif // !IFID
