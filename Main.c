#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Computer.h"

char* INSTRUCTIONS_WITH_RD_RS_RT_FORMAT[] = {"add", "sub", "or", "and"};

char* INSTRUCTIONS_WITH_RT_RS_IMM_FORMAT[] = {"lw", "sw"};

char* REGISTER_NUMERICS[32];

char* REGISTER_MNEMONICS[32];

void pause() {

	char* pause = malloc(sizeof(char) * 512);
	printf("Enter a character and press [Enter] to continue...\n");
	scanf("%s", pause);
	free(pause);

}

char* intToString(int a) {

	char number[32];
	sprintf(number, "%d", a);
	return number;

}

void iReallyDontKnowWhatToNameThis(char* strings[], int startValue, int numOfIterations, int indexOffset, char* stringHead) {

	for (int i = 0; i < numOfIterations; i++) {
		char* buffer = malloc(sizeof(char) * 4);
		strcpy(buffer, stringHead);
		char* result = strcat(buffer, intToString(i));
		strings[i + indexOffset] = malloc(sizeof(char) * 4);
		strcpy(strings[i + indexOffset], result);
		free(buffer);
	}

}

void initializeRegisterNumerics() {

	iReallyDontKnowWhatToNameThis(REGISTER_NUMERICS, 0, 32, 0, "$");

}

void initializeRegisterMnemonics() {

	REGISTER_MNEMONICS[0] = "$zero";
	REGISTER_MNEMONICS[1] = "$at";
	iReallyDontKnowWhatToNameThis(REGISTER_MNEMONICS, 0, 2, 2, "$v");
	iReallyDontKnowWhatToNameThis(REGISTER_MNEMONICS, 0, 4, 4, "$a");
	iReallyDontKnowWhatToNameThis(REGISTER_MNEMONICS, 0, 8, 8, "$t");
	iReallyDontKnowWhatToNameThis(REGISTER_MNEMONICS, 0, 8, 16, "$s");
	iReallyDontKnowWhatToNameThis(REGISTER_MNEMONICS, 8, 2, 24, "$t");
	iReallyDontKnowWhatToNameThis(REGISTER_MNEMONICS, 0, 2, 26, "$k");
	REGISTER_MNEMONICS[28] = "$gp";
	REGISTER_MNEMONICS[29] = "$sp";
	REGISTER_MNEMONICS[30] = "$fp";
	REGISTER_MNEMONICS[31] = "$ra";

}

int isStringIn(char* strings[], char* checkString, int arraySize) {

	for (int i = 0; i < arraySize; i++) {
		if (strcmp(checkString, strings[i]) == 0) {
			return 1;
		}
	}
	return 0;

}

int isRdRsRtFormat(char* instructionName) {

	return isStringIn(INSTRUCTIONS_WITH_RD_RS_RT_FORMAT, instructionName, 4);

}

int isRtRsImmFormat(char* instructionName) {

	return isStringIn(INSTRUCTIONS_WITH_RT_RS_IMM_FORMAT, instructionName, 2);

}

int parseOpCode(char* instructionName) {

    if (strcmp(instructionName, "add") == 0 || strcmp(instructionName, "sub") == 0
		|| strcmp(instructionName, "or") == 0 || strcmp(instructionName, "and") == 0) {
        return 0b000000;
	} else if (strcmp(instructionName, "lw") == 0) {
		return 0b100011;
	} else if (strcmp(instructionName, "sw") == 0) {
		return 0b101011;
	}
    return -1;

}

int parseFunction(char* instructionName) {

    if (strcmp(instructionName, "add") == 0) {
        return 0b100000;
	} else if (strcmp(instructionName, "sub") == 0) {
		return 0b100010;
	} else if (strcmp(instructionName, "or") == 0) {
		return 0b100101;
	} else if (strcmp(instructionName, "and") == 0) {
		return 0b100100;
	}
    fprintf(stderr, "Error: function not found for %s. Please report this to the programmer.\n", instructionName);
	pause();
    exit(1);

}

int getIndexOf(char* strings[], char* checkString) {

	for (int i = 0; i < 32; i++) {
		if (strcmp(checkString, strings[i]) == 0) {
			return i;
		}
	}
	return -1;

}

int parseRegister(char* _register) {

	int check1 = getIndexOf(REGISTER_NUMERICS, _register);
	if (check1 != -1) {
		return check1;
	}
	int check2 = getIndexOf(REGISTER_MNEMONICS, _register);
	if (check2 != -1) {
		return check2;
	}
	fprintf(stderr, "Error: Unrecognized register found (%s).\n", _register);
	pause();
	exit(1);

}

int main() {

	initializeRegisterNumerics();
	initializeRegisterMnemonics();
	
	printf("Enter the path to the file containing MIPS assembly: ");
	char* filePath = malloc(512 * sizeof(char));
	int errCheck = scanf("%s", filePath);
	if (errCheck == 0) {
		fprintf(stderr, "Error: Could not parse given input as a string.\n");
		pause();
		return 1;
	}
	char* filePathEnd = filePath;
	while (*filePathEnd != '\0') {
		filePathEnd++;
	}
	if (*filePath == '\"' && *(filePathEnd - 1) == '\"') {
		filePath = filePath + 1;
		*(filePathEnd - 1) = '\0';
	}
    FILE* input = fopen(filePath, "r");
    if (input == NULL) {
        fprintf(stderr, "Error: File does not exist!\n");
		pause();
        return 1;
    }
	
	Computer comp;
	Computer_Init(&comp);
	char buffer[32];
	char* pos = &buffer[0];
	int instructionIndex = 0;
	while (fgets(buffer, 32, input)) {
        uint32_t machineCode = 0;
        char* instructionName = strtok(buffer, " ");
        int opCode = parseOpCode(instructionName);
        if (opCode == -1) {
            fprintf(stderr, "Error: Unrecognized instruction found (%s).\n", instructionName);
			pause();
            return 1;
        }
        machineCode += opCode << 26;
        if (opCode == 0b000000) { //has function
            int function = parseFunction(instructionName);
			machineCode += function;
        }
		if (isRdRsRtFormat(instructionName)) {
			char* regDst = strtok(NULL, " ,");
			int rd = parseRegister(regDst);
			char* regSrc = strtok(NULL, " ,");
			int rs = parseRegister(regSrc);
			char* regSrc2 = strtok(NULL, " \n");
			int rt = parseRegister(regSrc2);
			machineCode += (rs << 21) + (rt << 16) + (rd << 11);
		}
		if (isRtRsImmFormat(instructionName)) {
			char* regTrgtOrSrc2 = strtok(NULL, " ,");
			int rt = parseRegister(regTrgtOrSrc2);
			char* immediate = strtok(NULL, " (");
			int imm = atoi(immediate);
			char* regSrc = strtok(NULL, ")");
			int rs = parseRegister(regSrc);
			machineCode += (rs << 21) + (rt << 16) + imm;
		}
		*(comp.iMem.instructions + instructionIndex) = machineCode >> 24;
		*(comp.iMem.instructions + instructionIndex + 1) = machineCode >> 16 & 0xFF;
		*(comp.iMem.instructions + instructionIndex + 2) = machineCode >> 8 & 0xFF;
		*(comp.iMem.instructions + instructionIndex + 3) = machineCode & 0xFF;
		instructionIndex += 4;
    }
    fclose(input);

	int userInput = 0;
	int computerFinished = 0;
	int view = 0;
	do {
		int error = 0;
		do {
			printf("What do you want to do?\n");
			printf("1) Run the remaining program.\n");
			printf("2) Run a single clock cycle.\n");
			printf("3) Switch to ");
			if (view) {
				printf("registers");
			} else {
				printf("DMEM");
			}
			printf(" view.\n");
			printf("4) Exit the simulator.\n");
			printf("Enter the number of your choice: ");
			int errCheck = scanf("%d", &userInput);
			if (errCheck == 0) {
				printf("Problem: Could not read input as integer.");
				error = 1;
			} else if (userInput < 1 || userInput > 3) {
				printf("Problem: Input out of range.");
				error = 1;
			}
		} while (error);
		if (userInput == 1) {
			Computer_execute(&comp);
			computerFinished = 1;
		} else if (userInput == 2) {
			computerFinished = Computer_cycle(&comp);
		} else if (userInput == 3) {
			view = !view;
		}
		if (userInput != 4) {
			if (view) {
				for (int i = 0; i < 128; i += 4) {
					printf("0x%02X: %d\n", i, (*(comp.dMem.data + i) << 24) + ((uint8_t) *(comp.dMem.data + i + 1) << 16)
										  + ((uint8_t) *(comp.dMem.data + i + 2) << 8) + (uint8_t) *(comp.dMem.data + i + 3));
				}
			} else {
				for (int i = 0; i < 32; i++) {
					printf("%s = %d\n", REGISTER_MNEMONICS[i], comp.regsBox.registers[i]);
				}
			}
		}
		printf("\n");
	} while (userInput != 4 && !computerFinished);

	pause();

	Computer_Destroy(&comp);

	for (int i = 0; i < 32; i++) {
		free(REGISTER_NUMERICS[i]);
	}
	for (int i = 2; i < 28; i++) {
		free(REGISTER_MNEMONICS[i]);
	}

    return 0;

}