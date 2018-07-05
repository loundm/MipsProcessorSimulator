#ifndef ADD
#define ADD

typedef struct Adder {
    //input
    int addend1 : 32;
    int addend2 : 32;
    //output
    int sum : 32;
} Adder;

//initialize the adder
void Adder_Init(Adder* adder);

//sets the first addend
void Adder_setAddend1(Adder* adder, int addend);

//sets the second added
void Adder_setAddend2(Adder* adder, int addend);

#endif // !ADD
