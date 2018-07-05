#include "Adder.h"

void reevaluateSum(Adder* adder) {

    adder->sum = adder->addend1 + adder->addend2;

}

void Adder_Init(Adder* adder) {

	adder->addend1 = 0;
	adder->addend2 = 0;
	adder->sum = 0;

}

void Adder_setAddend1(Adder* adder, int addend) {

    adder->addend1 = addend;
    reevaluateSum(adder);

}

void Adder_setAddend2(Adder* adder, int addend) {

    adder->addend2 = addend;
    reevaluateSum(adder);

}