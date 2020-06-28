#include<LPC17xx.h>
void delay()
{
	unsigned int i1;
	for(i1=0;i1<100000;i1++);
}
int main(void)
{
	unsigned int i;
	int a[100] = {1,2,4,8,16,32,64,128,256};
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 = 0x00000000;
	LPC_GPIO0->FIODIR = 0x00000FF0;
	while(1)
	{
		for(i=0;i<=8;i++)
		{
			LPC_GPIO0->FIOPIN = a[i]<<4;
			delay();
		}
	} 
}