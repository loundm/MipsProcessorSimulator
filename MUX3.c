#include "MUX3.h"

void Mux3_updateChoice1(Mux3* mux3) {

	if (mux3->select == 0) {
		mux3->choice = mux3->option1;
	}

}

void Mux3_updateChoice2(Mux3* mux3) {

	if (mux3->select == 1) {
		mux3->choice = mux3->option2;
	}

}

void Mux3_updateChoice3(Mux3* mux3) {

	if (mux3->select == 2) {
		mux3->choice = mux3->option3;
	}

}

void Mux3_reselectChoice(Mux3* mux3) {

	if (mux3->select == 0) {
		mux3->choice = mux3->option1;
	}
	else if (mux3->select == 1) {
		mux3->choice = mux3->option2;
	}
	else {
		mux3->choice = mux3->option3;
	}

}

void Mux3_Init(Mux3* mux3) {

	mux3->option1 = 0;
	mux3->option2 = 0;
	mux3->option3 = 0;
	mux3->select = 0;
	mux3->choice = 0;

}

void Mux3_setOption1(Mux3* mux3, int option) {

	mux3->option1 = option;
	Mux3_updateChoice1(mux3);

}

void Mux3_setOption2(Mux3* mux3, int option) {

	mux3->option2 = option;
	Mux3_updateChoice2(mux3);

}

void Mux3_setOption3(Mux3* mux3, int option) {

	mux3->option3 = option;
	Mux3_updateChoice3(mux3);

}

void Mux3_setSelect(Mux3* mux3, unsigned int select) {

	mux3->select = select;
	Mux3_reselectChoice(mux3);

}