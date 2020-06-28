#include<LPC17xx.h>
void delay(void)
{
	unsigned int i;
	for (i=0;i<100000;i++);
}
int main(void)
{
	unsigned int i1=0;
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 = 0x00000000;
	LPC_GPIO0->FIODIR = 0x00000FF0;
	while(1)
	{
		for(i1=0;i1<=256;i1++)
		{
			LPC_GPIO0->FIOPIN = i1<<4;
			delay();
		}
	}
}