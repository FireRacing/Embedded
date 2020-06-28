#include<LPC17xx.h>
unsigned char dig0=4,dig1=3,dig2=2,dig3=1;
unsigned char a[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char digcount=0,temp,temp2;
void display(void)
{
	unsigned int i;
	if(digcount==1)
	{
		LPC_GPIO1->FIOPIN = 0<<23;
		temp = dig0;
	}
	else if(digcount==2)
	{
		LPC_GPIO1->FIOPIN = 01<<23;
		temp = dig1;
	}
	else if(digcount==3)
	{
		LPC_GPIO1->FIOPIN = 02<<23;
		temp = dig2;
	}
	else if(digcount==4)
	{
		LPC_GPIO1->FIOPIN = 03<<23;
		temp = dig3;
	}
	temp2 = a[temp];
	LPC_GPIO0->FIOPIN = temp2<<4;
	for(i=0;i<23;i++);
	LPC_GPIO0->FIOPIN = 0x00<<4;
}
int main(void)
{
	LPC_PINCON->PINSEL0 = 0x00000000;
	LPC_PINCON->PINSEL3 = 0x00;
	LPC_GPIO0->FIODIR = 0xFF<<4;
	LPC_GPIO1->FIODIR = 0xF<<23;
	while(1)
	{
		digcount++;
		if(digcount==0x5)
			digcount=0;
		display();
	}
}