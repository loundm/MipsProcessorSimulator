#ifndef PC
#define PC

typedef struct Pc {
	unsigned int pcWriteFlag : 1;
	unsigned int pc : 32;
} Pc;

//initialize the program counter
void Pc_Init(Pc* pc);

void Pc_setNewPc(Pc* pc, unsigned int newPc);

void Pc_setPcWriteFlag(Pc* pc, unsigned int pcWriteFlag);

#endif // !PC
