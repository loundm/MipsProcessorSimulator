#include "Forwarding.h"

void checkForHazards(Forwarding* frwrd) {

	frwrd->forwardA = 0;
	frwrd->forwardB = 0;
	if (frwrd->exMemRegWrite && frwrd->exMemRd != 0) {
		if (frwrd->exMemRd == frwrd->idExRs) {
			frwrd->forwardA = 2;
		}
		if (frwrd->exMemRd == frwrd->idExRt) {
			frwrd->forwardB = 2;
		}
	}
	if (frwrd->memWbRegWrite && frwrd->memWbRd != 0) {
		if (!(frwrd->exMemRegWrite && frwrd->exMemRd != 0 && frwrd->exMemRd == frwrd->idExRs)
				&& frwrd->memWbRd == frwrd->idExRs) {
			frwrd->forwardA = 1;
		}
		if (!(frwrd->exMemRegWrite && frwrd->exMemRd != 0 && frwrd->exMemRd == frwrd->idExRt)
				&& frwrd->memWbRd == frwrd->idExRt) {
			frwrd->forwardB = 1;
		}
	}

}

void Forwarding_Init(Forwarding* frwrd) {

	frwrd->exMemRegWrite = 0;
	frwrd->memWbRegWrite = 0;
	frwrd->idExRs = 0;
	frwrd->idExRt = 0;
	frwrd->exMemRd = 0;
	frwrd->memWbRd = 0;
	frwrd->forwardA = 0;
	frwrd->forwardB = 0;

}

void Forwarding_setExMemRegWrite(Forwarding* frwrd, unsigned int exMemRegWrite) {

	frwrd->exMemRegWrite = exMemRegWrite;
	checkForHazards(frwrd);

}

void Forwarding_setMemWbRegWrite(Forwarding* frwrd, unsigned int memWbRegWrite) {

	frwrd->memWbRegWrite = memWbRegWrite;
	checkForHazards(frwrd);

}

void Forwarding_setIdExRs(Forwarding* frwrd, unsigned int idExRs) {

	frwrd->idExRs = idExRs;
	checkForHazards(frwrd);

}

void Forwarding_setIdExRt(Forwarding* frwrd, unsigned int idExRt) {

	frwrd->idExRt = idExRt;
	checkForHazards(frwrd);

}

void Forwarding_setExMemRd(Forwarding* frwrd, unsigned int exMemRd) {

	frwrd->exMemRd = exMemRd;
	checkForHazards(frwrd);

}

void Forwarding_setMemWbRd(Forwarding* frwrd, unsigned int memWbRd) {

	frwrd->memWbRd = memWbRd;
	checkForHazards(frwrd);

}