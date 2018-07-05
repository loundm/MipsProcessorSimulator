#include "D-MEM.h"

void processData(DMem* dMem) {

    if (dMem->memReadFlag) {
        dMem->readData = (*(dMem->data + dMem->address) << 24) + ((uint8_t) *(dMem->data + dMem->address + 1) << 16)
			+ ((uint8_t) *(dMem->data + dMem->address + 2) << 8) + (uint8_t) *(dMem->data + dMem->address + 3);
    }
    if (dMem->memWriteFlag) {
        *(dMem->data + dMem->address) = dMem->writeData >> 24;
		*(dMem->data + dMem->address + 1) = dMem->writeData >> 16 & 0xFF;
		*(dMem->data + dMem->address + 2) = dMem->writeData >> 8 & 0xFF;
		*(dMem->data + dMem->address + 3) = dMem->writeData & 0xFF;
    }

}

void DMem_Init(DMem* dMem) {

	dMem->address = 0;
	dMem->writeData = 0;
	dMem->memReadFlag = 0;
	dMem->memWriteFlag = 0;
	dMem->data = malloc(sizeof(int8_t) * 128);
	for (int i = 0; i < 128; i++) {
		*(dMem->data + i) = 0;
	}
	dMem->readData = 0;

}

void DMem_Destroy(DMem* dMem) {

    free(dMem->data);

}

void DMem_setAddress(DMem* dMem, unsigned int address) {

    dMem->address = address;

}

void DMem_setWriteData(DMem* dMem, int data) {

    dMem->writeData = data;
    processData(dMem);

}

void DMem_setMemReadFlag(DMem* dMem, unsigned int state) {

    dMem->memReadFlag = state;
    processData(dMem);

}

void DMem_setMemWriteFlag(DMem* dMem, unsigned int state) {

    dMem->memWriteFlag = state;

}