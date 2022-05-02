#include<main.h>

void main()
{
	unsigned char b;

	SM0 = SM1 = 0;			// Uart Mode 0
	REN = 1;						// Cho phep nhan du lieu

	P1_0 = 0;
	while(1)
	{
		P3_2 = 0;  				// Tao xung chot du lieu ngo vao 74265
		P3_2 = 1;	

		RI = 0;
		while(RI == 0);
		b = SBUF;

		if((b&0x2)==0)		// 0000 0010
		{
		 	P1_0 = 1;
		}

		if((b&0x01)==0)
		{
		 	P1_0 =0;	
		}
	}
}