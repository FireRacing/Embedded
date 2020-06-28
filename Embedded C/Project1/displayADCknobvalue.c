#include<LPC17xx.h>
#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#define RS 27
#define EN 28
#define DT 23
unsigned cmd[]={0x30, 0x30, 0x30, 0x20, 0x28, 0x06, 0x0C, 0x01, 0x80};
unsigned long i, j, flag, temp, flag2, temp1, x, y;
void LCD_Write();
void Port_Write();
void delay();
int main()
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_GPIO0->FIODIR=(1<<RS |1<<EN |0xF<<DT);
	flag=0;
	for(i=0; i<9; i++){
		temp=cmd[i];
		LCD_Write();
	}
	
}
void LCD_Write(){
	flag2 = (flag==1)?0:((temp==0x30)||(temp==0x20))?1:0;
	
	temp1 = temp&0xF0;
	temp1 = temp1>>4;
	temp1 = temp1<<DT;
	Port_Write();
	if(!flag2){
		temp1 = temp&0x0F;
		temp1 = temp1<<DT;
		Port_Write();

	}
}
void Port_Write(){
	LPC_GPIO0->FIOPIN=0;
	LPC_GPIO0->FIOPIN=temp1;
	if(flag==0)
		LPC_GPIO0->FIOCLR=1<<RS;
	else
		LPC_GPIO0->FIOSET=1<<RS;
	LPC_GPIO0->FIOSET=1<<EN;
	for(j=0; j<25; j++);
	LPC_GPIO0->FIOCLR=1<<EN;
	delay();
}

void delay(){
for(j=0; j<30000;j++);
}
void ADC_IRQHandler(void)
{
	x = LPC_ADC->ADGDR;
	x = LPC_ADC->ADDR5;
	flag =0;
	temp = 0x01;
	LCD_Write();
}