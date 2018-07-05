#include "SExt.h"

void Sext_Init(SExt* sExt) {

	sExt->input = 0;
	sExt->output = 0;

}

void SExt_setInput(SExt* sExt, int input) {

    sExt->input = input;
    sExt->output = sExt->input;

}
