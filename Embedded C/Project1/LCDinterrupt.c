#include<LPC17xx.h>
#include<stdio.h>
#define RS 27 //P0.27
#define EN 28 //P0.28
#define DT 23 //P0.13 - P0.26
unsigned long temp,temp1,x;
unsigned char msg[] = {"programme is running good and dandy"};
unsigned char cmd[] = {0x30,0x30,0x30,0x20,0x28,0x06,0x0C,0x80,0x01};
unsigned int flag,flag2,flag1,i,col,row;
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
	delay(150000);
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
void scan(){
	x=LPC_GPIO1->FIOPIN&(0xF<<23);
  if(x!=0)
	{
		flag2=1;
    x=x>>23;
    if(x==1){ col=0;}
    if(x==2){col=1;}
    if(x==4){col=2;}
    if(x==8){col=3;}
  }
}
int main()
{
	int y;
	unsigned char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	SystemInit();
	SystemCoreClockUpdate();
	LPC_GPIO1->FIODIR=0<<23;
	LPC_GPIO0->FIODIR = (1<<RS|1<<EN|0xF<<DT);
	LPC_PINCON->PINSEL4 = 1<<20;
	LPC_GPIO2->FIODIR=0X0F<<10;
	flag =0;
	for(i=0;i<9;i++)
	{
		temp = cmd[i];
		lcd_write();
	}
	flag =1;
	i=0;
  x = LPC_SC->EXTPOLAR;
	while(1)
	{
		for(row=0;row<4;row++)
		{
			LPC_GPIO2->FIOPIN=1<<(row+10);
			flag2=0;
			scan();
			if(flag2==1)
			{
        break;
      }
    }
		if(flag2==1)
		{
			y=4*row+col;
      temp=a[y];
    }
		if(x==1)
		{
			return 0;
    }
		if(!x)
		{
      lcd_write();
    }
	}
}