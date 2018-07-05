#ifndef MUX3
#define MUX3

typedef struct MUX3 {
	//input
	int option1 : 32;
	int option2 : 32;
	int option3 : 32;
	unsigned int select : 2;
	//output
	int choice : 32;
} Mux3;

//initialize the MUX
void Mux3_Init(Mux3* mux3);

//set the first option
void Mux3_setOption1(Mux3* mux3, int option);

//set the second option
void Mux3_setOption2(Mux3* mux3, int option);

//set the select bit
void Mux3_setSelect(Mux3* mux3, unsigned int select);

#endif // !MUX3
