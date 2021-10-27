#pragma once

unsigned int getDWord(unsigned char reg)
{
	switch(reg)
	{
		case 0: //EAX
			return (unsigned int)getWord(1)*65536 + getWord(0);
			break;
		case 1: //EBX
			return (unsigned int)getWord(3)*65536 + getWord(2);
			break;
		case 2: //ECX
			return (unsigned int)getWord(5)*65536 + getWord(4);
			break;
		case 3: //EDX
			return (unsigned int)getWord(7)*65536 + getWord(6);
			break;
	}
}

unsigned int setDWord(unsigned char reg, unsigned int value)
{
	switch(reg)
	{
		case 0: //EAX
			setWord(1, (unsigned int)value/256);
			setWord(0, value%256);
			break;
		case 1: //EBX
			setWord(3, (unsigned int)value/256);
			setWord(2, value%256);
			break;
			break;
		case 2: //ECX
			setWord(5, (unsigned int)value/256);
			setWord(4, value%256);
			break;
		case 3: //EDX
			setWord(7, (unsigned int)value/256);
			setWord(6, value%256);
			break;
	}
}