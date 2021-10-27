#pragma once

#include <stdio.h>

/*
struct LABEL
{
	unsigned short int location;
	char name[16];
};

typedef struct LABEL LABEL;
*/

typedef unsigned char ub;
typedef unsigned short int uw;
typedef unsigned int ud;
typedef unsigned long long int uq;

typedef signed char sb;
typedef signed short int sw;
typedef signed int sd;
typedef signed long long int sq;

typedef unsigned char uint8ptr_t;
typedef unsigned short int uint16ptr_t;
typedef unsigned int uintptr_t;

unsigned char eax[2][2] = {0};
unsigned char ebx[2][2] = {0};
unsigned char ecx[2][2] = {0};
unsigned char edx[2][2] = {0};

unsigned char memory[32768];
unsigned char* ptr = memory;

unsigned char temp[16][256] = {0};
unsigned char push[16][256] = {0};

#include "8-BITS.c"
#include "16-BITS.c"
#include "32-BITS.c"

void debug(unsigned char additionalValue)
{
	printf("AH: %d, AL: %d, MEM0: %d, AV: %d\n", eax[1][0], eax[1][1], memory[0], additionalValue);
}

void printStack()
{
	for(unsigned char i = 0 ; i < 200 ; i++)
		printf("%c. ", memory[i]);
}

void clearTemp()
{
	for(unsigned char i = 0 ; i < 16 ; i++)
		strcpy(temp[i], temp[15]);
}

void pushTemp()
{
	for(unsigned char i = 0 ; i < 16 ; i++)
		strcpy(push[i], temp[i]);
}

void popTemp()
{
	for(unsigned char i = 0 ; i < 16 ; i++)
		strcpy(temp[i], push[i]);
}

void increment(unsigned char reg)
{
	switch(reg)
	{
		//EAX
		case 0: //AL (EAL)
			eax[1][1]++;
			break;
		case 1: //AH (EAL)
			eax[1][0]++;
			break;
		case 2: //AL (EAH)
			eax[0][1]++;
			break;
		case 3: //AH (EAH)
			eax[0][0]++;
			break;
		//EBX
		case 4: //BL (EBL)
			ebx[1][1]++;
			break;
		case 5: //BH (EBL)
			ebx[1][0]++;
			break;
		case 6: //BL (EBH)
			ebx[0][1]++;
			break;
		case 7: //BH (EBH)
			ebx[0][0]++;
			break;
		//ECX
		case 8: //CL (ECL)
			ecx[1][1]++;
			break;
		case 9: //CH (ECL)
			ecx[1][0]++;
			break;
		case 10: //CL (ECH)
			ecx[0][1]++;
			break;
		case 11: //CH (ECH)
			ecx[0][0]++;
			break;
		//EDX
		case 12: //DL (EDL)
			edx[1][1]++;
			break;
		case 13: //DH (EDL)
			edx[1][0]++;
			break;
		case 14: //DL (EDH)
			edx[0][1]++;
			break;
		case 15: //DH (EDH)
			edx[0][0]++;
			break;
	}
}

void decrement(unsigned char reg)
{
	switch(reg)
	{
		//EAX
		case 0: //AL (EAL)
			eax[1][1]--;
			break;
		case 1: //AH (EAL)
			eax[1][0]--;
			break;
		case 2: //AL (EAH)
			eax[0][1]--;
			break;
		case 3: //AH (EAH)
			eax[0][0]--;
			break;
		//EBX
		case 4: //BL (EBL)
			ebx[1][1]--;
			break;
		case 5: //BH (EBL)
			ebx[1][0]--;
			break;
		case 6: //BL (EBH)
			ebx[0][1]--;
			break;
		case 7: //BH (EBH)
			ebx[0][0]--;
			break;
		//ECX
		case 8: //CL (ECL)
			ecx[1][1]--;
			break;
		case 9: //CH (ECL)
			ecx[1][0]--;
			break;
		case 10: //CL (ECH)
			ecx[0][1]--;
			break;
		case 11: //CH (ECH)
			ecx[0][0]--;
			break;
		//EDX
		case 12: //DL (EDL)
			edx[1][1]--;
			break;
		case 13: //DH (EDL)
			edx[1][0]--;
			break;
		case 14: //DL (EDH)
			edx[0][1]--;
			break;
		case 15: //DH (EDH)
			edx[0][0]--;
			break;
	}
}

void add(unsigned char reg, unsigned char change)
{
	for(unsigned char i = 0 ; i < change ; i++)
		increment(reg);
}

void sub(unsigned reg, unsigned char change)
{
	for(unsigned char i = 0 ; i < change ; i++)
		decrement(reg);
}

void interrupt()
{
	switch(eax[1][0])
	{
		case 0: //Print Char
			putchar(eax[1][1]);
			break;
		case 1: //Get Char
			eax[1][1] = getchar(); //AL
			break;
		case 2: //Get String
			pushTemp();
			scanf("%254s", temp[0]);
			strncpy(temp[1], temp[0], ebx[1][0]);
			temp[1][ebx[1][0]] = 0;
			strrev(temp[1]);
			*ptr++ = 0;
			for(unsigned char i = 0 ; i < 255 ; i++)
			{
				if(temp[1][i] != 0)
				{
					*ptr++ = temp[1][i];
				}
			}
			//setWord(0, (uint16ptr_t)ptr);
			popTemp();
			break;
		case 3: //Print String
			//ptr = (short int)getWord(0);
			do
			{
				*ptr = 0;
				putchar(*--ptr);
			}
			while(*ptr != 0);
			break;
	}
}