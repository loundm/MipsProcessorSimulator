#include <stdlib.h>

#include "I-MEM.h"

void IMem_Init(IMem* iMem) {

	iMem->readAddress = 0;
	iMem->instructions = malloc(sizeof(uint8_t) * 0x200);
	for (int i = 0; i < 0x200; i++) {
		*(iMem->instructions + i) = 0;
	}
	iMem->instruction = 0;

}

void IMem_Destroy(IMem* iMem) {

    free(iMem->instructions);

}

void IMem_setReadAddress(IMem* iMem, unsigned int address) {

    iMem->readAddress = address;
    iMem->instruction = (*(iMem->instructions + iMem->readAddress) << 24) + (*(iMem->instructions + iMem->readAddress + 1) << 16)
		+ (*(iMem->instructions + iMem->readAddress + 2) << 8) + *(iMem->instructions + iMem->readAddress + 3);

}