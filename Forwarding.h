#ifndef FORWARD
#define FORWARD

typedef struct Forwarding {
	//input
	unsigned int exMemRegWrite : 1;
	unsigned int memWbRegWrite : 1;
	unsigned int idExRs : 5;
	unsigned int idExRt : 5;
	unsigned int exMemRd : 5;
	unsigned int memWbRd : 5;
	//output
	unsigned int forwardA : 2;
	unsigned int forwardB : 2;
} Forwarding;

//initialize the forwarding unit
void Forwarding_Init(Forwarding* frwrd);

void Forwarding_setExMemRegWrite(Forwarding* frwrd, unsigned int exMemRegWrite);

void Forwarding_setMemWbRegWrite(Forwarding* frwrd, unsigned int memWbRegWrite);

void Forwarding_setIdExRs(Forwarding* frwrd, unsigned int idExRs);

void Forwarding_setIdExRt(Forwarding* frwrd, unsigned int idExRt);

void Forwarding_setExMemRd(Forwarding* frwrd, unsigned int exMemRd);

void Forwarding_setMemWbRd(Forwarding* frwrd, unsigned int memWbRd);

#endif // !FORWARD
