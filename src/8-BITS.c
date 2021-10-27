#pragma once

unsigned char getReg(unsigned char reg)
{
	switch(reg)
	{
		//EAX
		case 0: //AL (EAL)
			return eax[1][1];
			break;
		case 1: //AH (EAL)
			return eax[1][0];
			break;
		case 2: //AL (EAH)
			return eax[0][1];
			break;
		case 3: //AH (EAH)
			return eax[0][0];
			break;
		//EBX
		case 4: //BL (EBL)
			return ebx[1][1];
			break;
		case 5: //BH (EBL)
			return ebx[1][0];
			break;
		case 6: //BL (EBH)
			return ebx[0][1];
			break;
		case 7: //BH (EBH)
			return ebx[0][0];
			break;
		//ECX
		case 8: //CL (ECL)
			return ecx[1][1];
			break;
		case 9: //CH (ECL)
			return ecx[1][0];
			break;
		case 10: //CL (ECH)
			return ecx[0][1];
			break;
		case 11: //CH (ECH)
			return ecx[0][0];
			break;
		//EDX
		case 12: //DL (EDL)
			return edx[1][1];
			break;
		case 13: //DH (EDL)
			return edx[1][0];
			break;
		case 14: //DL (EDH)
			return edx[0][1];
			break;
		case 15: //DH (EDH)
			return edx[0][0];
			break;
	}
}

void setReg(unsigned char reg, unsigned char value)
{
	switch(reg)
	{
		//EAX
		case 0: //AL (EAL)
			eax[1][1] = value;
			break;
		case 1: //AH (EAL)
			eax[1][0] = value;
			break;
		case 2: //AL (EAH)
			eax[0][1] = value;
			break;
		case 3: //AH (EAH)
			eax[0][0] = value;
			break;
		//EBX
		case 4: //BL (EBL)
			ebx[1][1] = value;
			break;
		case 5: //BH (EBL)
			ebx[1][0] = value;
			break;
		case 6: //BL (EBH)
			ebx[0][1] = value;
			break;
		case 7: //BH (EBH)
			ebx[0][0] = value;
			break;
		//ECX
		case 8: //CL (ECL)
			ecx[1][1] = value;
			break;
		case 9: //CH (ECL)
			ecx[1][0] = value;
			break;
		case 10: //CL (ECH)
			ecx[0][1] = value;
			break;
		case 11: //CH (ECH)
			ecx[0][0] = value;
			break;
		//EDX
		case 12: //DL (EDL)
			edx[1][1] = value;
			break;
		case 13: //DH (EDL)
			edx[1][0] = value;
			break;
		case 14: //DL (EDH)
			edx[0][1] = value;
			break;
		case 15: //DH (EDH)
			edx[0][0] = value;
			break;
	}
}