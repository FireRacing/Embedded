#include<LPC17xx.h>
#define RS 27 //P0.27
#define EN 28 //P0.28
#define DT 23 //P0.13 - P0.26
unsigned long temp,temp1;
unsigned char msg[] = {"Programme is working fine and dandy"};
unsigned char cmd[] = {0x30,0x30,0x30,0x20,0x28,0x06,0x0C,0x80,0x01};
unsigned int flag,flag2,flag1,i;
void delay(int n)
{
	int i1;
	for(i1=0;i1<n;i1++);
}
void port_write()
{
	unsigned int j;
	LPC_GPIO0->FIOPIN = 0;
	LPC_GPIO0->FIOPIN = temp1;
	if(flag==0)
		LPC_GPIO0->FIOCLR = 1<<RS;
	else
		LPC_GPIO0->FIOSET = 1<<RS;
	LPC_GPIO0->FIOSET = 1<<EN;
	for(j=0;j<25;j++);
	LPC_GPIO0->FIOCLR = 1<<EN;
	delay(30000);
}
void lcd_write()
{
	flag2 = (flag==1)?0:((temp==0x30)||(temp==0x20)?1:0);
	temp1 = temp&0xF0;
	temp1 = temp1>>4;
	temp1 = temp1<<DT;
	port_write();
	if(!flag2)
	{
		temp1  = temp&0x0F;
		temp1 = temp1<<DT;
		port_write();
	}
}
int main()
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_GPIO0->FIODIR = (1<<RS|1<<EN|0xF<<DT);
	flag =0;
	for(i=0;i<9;i++)
	{
		temp = cmd[i];
	
	lcd_write();

	}		flag =1;
	i=0;
	while(msg[i]!='\0')
	{
		temp = msg[i];
		lcd_write();
		i++;
		if(i==16)
		{
			flag =0;
			temp = 0xC0;
			lcd_write();
			flag =1;
		}
	}
	while(1);
}
	