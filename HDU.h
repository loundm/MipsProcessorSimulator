#ifndef HDU
#define HDU

typedef struct Hdu {
	//input
	unsigned int idExMemRead : 1;
	unsigned int idExRt : 5;
	unsigned int ifIdRs : 5;
	unsigned int ifIdRt : 5;
	//output
	unsigned int pcWriteFlag : 1;
	unsigned int ifIdWriteFlag : 1;
	unsigned int ctrlNopFlag;
} Hdu;

//initialize the hazard detection unit
void Hdu_Init(Hdu* hdu);

void Hdu_setIdExMemRead(Hdu* hdu, unsigned int idExMemRead);

void Hdu_setIdExRt(Hdu* hdu, unsigned int idExRt);

void Hdu_setIfIdRs(Hdu* hdu, unsigned int ifIdRs);

void Hdu_setIfIdRt(Hdu* hdu, unsigned int ifIdRt);

#endif // !HDU
