#ifndef MUX
#define MUX

typedef struct MUX {
    //input
    int option1 : 32;
    int option2 : 32;
    unsigned int select : 1;
    //output
    int choice : 32;
} Mux;

//initialize the MUX
void Mux_Init(Mux* mux);

//set the first option
void Mux_setOption1(Mux* mux, int option);

//set the second option
void Mux_setOption2(Mux* mux, int option);

//set the select bit
void Mux_setSelect(Mux* mux, unsigned int select);

#endif // !MUX
