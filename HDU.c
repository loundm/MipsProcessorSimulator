#include "HDU.h"

void checkForHazard(Hdu* hdu) {

	hdu->pcWriteFlag = 1;
	hdu->ifIdWriteFlag = 1;
	hdu->ctrlNopFlag = 0;
	if (hdu->idExMemRead && (hdu->idExRt == hdu->ifIdRs || hdu->idExRt == hdu->ifIdRt)) {
		hdu->pcWriteFlag = 0;
		hdu->ifIdWriteFlag = 0;
		hdu->ctrlNopFlag = 1;
	}

}

void Hdu_Init(Hdu* hdu) {

	hdu->idExMemRead = 0;
	hdu->idExRt = 0;
	hdu->ifIdRs = 0;
	hdu->ifIdRt = 0;
	hdu->pcWriteFlag = 1;
	hdu->ifIdWriteFlag = 1;
	hdu->ctrlNopFlag = 0;

}

void Hdu_setIdExMemRead(Hdu* hdu, unsigned int idExMemRead) {

	hdu->idExMemRead = idExMemRead;
	checkForHazard(hdu);

}

void Hdu_setIdExRt(Hdu* hdu, unsigned int idExRt) {

	hdu->idExRt = idExRt;
	checkForHazard(hdu);

}

void Hdu_setIfIdRs(Hdu* hdu, unsigned int ifIdRs) {

	hdu->ifIdRs = ifIdRs;
	checkForHazard(hdu);

}

void Hdu_setIfIdRt(Hdu* hdu, unsigned int ifIdRt) {

	hdu->ifIdRt = ifIdRt;
	checkForHazard(hdu);

}