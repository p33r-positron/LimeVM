#pragma once

unsigned short int getWord(unsigned char reg)
{
	switch(reg)
	{
		case 0: //AX (EAL)
			return (unsigned short int)eax[1][0]*256 + eax[1][1];
			break;
		case 1: //AX (EAH)
			return (unsigned short int)eax[0][0]*256 + eax[0][1];
			break;
		case 2: //BX (EBL)
			return (unsigned short int)ebx[1][0]*256 + ebx[1][1];
			break;
		case 3: //BX (EBH)
			return (unsigned short int)ebx[0][0]*256 + ebx[0][1];
			break;
		case 4: //CX (ECL)
			return (unsigned short int)ecx[1][0]*256 + ecx[1][1];
			break;
		case 5: //CX (ECH)
			return (unsigned short int)ecx[0][0]*256 + ecx[0][1];
			break;
		case 6: //DX (EDL)
			return (unsigned short int)edx[1][0]*256 + edx[1][1];
			break;
		case 7: //DX (EDH)
			return (unsigned short int)edx[0][0]*256 + edx[0][1];
			break;
	}
}

void setWord(unsigned char reg, unsigned short int value)
{
	switch(reg)
	{
		case 0: //AX (EAL)
			eax[1][0] = (unsigned char)value/256;
			eax[1][1] = value%256;
			break;
		case 1: //AX (EAH)
			eax[0][0] = (unsigned char)value/256;
			eax[0][1] = value%256;
			break;
		case 2: //BX (EBL)
			ebx[1][0] = (unsigned char)value/256;
			ebx[1][1] = value%256;
			break;
		case 3: //BX (EBH)
			ebx[0][0] = (unsigned char)value/256;
			ebx[0][1] = value%256;
			break;
		case 4: //CX (ECL)
			ecx[1][0] = (unsigned char)value/256;
			ecx[1][1] = value%256;
			break;
		case 5: //CX (ECH)
			ecx[0][0] = (unsigned char)value/256;
			ecx[0][1] = value%256;
			break;
		case 6: //DX (EDL)
			edx[1][0] = (unsigned char)value/256;
			edx[1][1] = value%256;
			break;
		case 7: //DX (EDH)
			edx[0][0] = (unsigned char)value/256;
			edx[0][1] = value%256;
			break;
	}
}