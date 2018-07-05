#ifndef COMP
#define COMP

#include "MUX.h"
#include "PC.h"
#include "Adder.h"
#include "I-MEM.h"
#include "IF-ID.h"
#include "HDU.h"
#include "Control.h"
#include "Registers.h"
#include "SExt.h"
#include "ID-EX.h"
#include "ALUControl.h"
#include "Forwarding.h"
#include "MUX3.h"
#include "ALU.h"
#include "EX-MEM.h"
#include "D-MEM.h"
#include "MEM-WB.h"

typedef struct Computer {
    Mux pcMux;
	Pc pc;
    Adder pcIncrementer;
    IMem iMem;
	IfId ifIdPipeReg;
	Hdu hdu;
    Control ctrl;
	Mux ctrlMux;
    Regs regsBox;
    SExt sExt;
	IdEx idExPipeReg;
    Adder branchAdder;
    AluCtrl aluCtrl;
	Forwarding forwarding;
	Mux3 regDataMux1;
	Mux3 regDataMux2;
    Mux aluMux;
    Alu alu;
	Mux regDstMux;
	ExMem exMemPipeReg;
    DMem dMem;
	MemWb memWbPipeReg;
    Mux writeBackMux;
	int remainingCycles : 3;
} Computer;

//initialize the computer
void Computer_Init(Computer* comp);

//destroy the Computer
void Computer_Destroy(Computer* comp);

//execute the entire program
void Computer_execute(Computer* comp);

//execute a single simulated clock cycle
int Computer_cycle(Computer* comp);

#endif // !COMP
