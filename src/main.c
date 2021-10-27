#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "VM.c"

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		puts("Utilisation: limevm <imageDisque.bin>");
		return 1;
	}

	FILE* image = NULL;

	image = fopen(argv[1], "r");

	if(image == NULL)
	{
		puts("Erreur pendant la lecture de l'image disque.");
		return 1;
	}

	printf("\tLimeVM v0.0.1\r\n-----------------------------\r\n\r\n");

	unsigned short int i = 0;

	unsigned char octets[512];
	for(; i < 512 ; i++)
	{
		octets[i] = fgetc(image);
	}

	if(octets[510] ^ octets[511] == 256)
		puts("Found bootable disk !");

	//LABEL labels[128];
	unsigned short int labels[128];
	unsigned char labelPtr = 0;

	for(i = 0 ; i < 510 ; i++)
	{
		switch(octets[i])
		{
			case 1: //Mov Reg = Val
				i++;
				setReg(octets[i], octets[i+1]);
				i++;
				break;
			case 2: //Interruption
				interrupt();
				break;
			case 3: //Incrémentation
				i++;
				add(octets[i], 1);
				break;
			case 4: //Décrémentation
				i++;
				add(octets[i], -1);
				break;
			case 5: //Addition
				i++;
				add(octets[i], octets[i+1]);
				i++;
				break;
			case 6: //Soustraction
				i++;
				add(octets[i], -octets[i+1]);
				i++;
				break;
			case 7: //Mov Reg = Reg
				i++;
				setReg(octets[i], getReg(octets[i+1]));
				i++;
				break;
			/*case 8: //Mov *ptr = Reg
				i++;
				//*(char*)(octets[i]) = getReg(octets[i+1]);
				i++;
				break;
			case 9: //Mov *ptr = Val
				i++;
				//*(char*)(octets[i]) = octets[i+1];
				i++;
				break;
			case 10: //Mov Reg = *ptr
				i++;
				//setReg(octets[i], *(char*)(octets[i+1]));
				i++;
				break;*/ //ALL COMMENTED BECAUSE ALL UNTESTED
			case 11: //Push value to stack
				i++;
				*ptr++ = octets[i];
				break;
			case 12: //Pop value from stack
				eax[1][1] = *--ptr;
				*ptr = 0;
				break;
			case 13: //Mov WORD_REG = Val
				i++;
				setWord(octets[i], (octets[i+1]*256 + octets[i+2]));
				i++;
				i++;
				break;
			case 14: //Mov DWORD_REG = Val
				i++;
				setDWord(octets[i], (octets[i+1]*256 + octets[i+2])*65536 + (octets[i+3]*256 + octets[i+4]));
				i+=4;
				break;
			case 15: //LABEL
				//(*labels++).location = i;
				labels[labelPtr++] = i;
				break;
			case 16: //GOTO
				i++;
				i = labels[octets[i]];
				break;
		}
	}

	return 0;
}