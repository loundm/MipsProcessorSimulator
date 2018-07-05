#include "MUX.h"

void updateChoice1(Mux* mux) {

    if (!mux->select) {
        mux->choice = mux->option1;
    }

}

void updateChoice2(Mux* mux) {

    if (mux->select) {
        mux->choice = mux->option2;
    }

}

void reselectChoice(Mux* mux) {

    if (mux->select) {
        mux->choice = mux->option2;
    } else {
        mux->choice = mux->option1;
    }

}

void Mux_Init(Mux* mux) {

	mux->option1 = 0;
	mux->option2 = 0;
	mux->select = 0;
	mux->choice = 0;

}

void Mux_setOption1(Mux* mux, int option) {

    mux->option1 = option;
    updateChoice1(mux);

}

void Mux_setOption2(Mux* mux, int option) {

    mux->option2 = option;
    updateChoice2(mux);

}

void Mux_setSelect(Mux* mux, unsigned int select) {

    mux->select = select;
    reselectChoice(mux);

}