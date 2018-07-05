#ifndef SEXT
#define SEXT

typedef struct SignExtender {
    //input
    int input : 16;
    //output
    int output : 32;
} SExt;

//initialize the sign extender
void Sext_Init(SExt* sExt);

//set the 16-bit input to convert to 32-bit
void SExt_setInput(SExt* sExt, int input);

#endif // !SEXT
