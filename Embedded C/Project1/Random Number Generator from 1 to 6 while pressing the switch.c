#include<LPC17xx.h>
#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#define RS 27
#define EN 28
#define DT 23

unsigned char msg[] = {"Manipal Institute of Technology"};
unsigned cmd[]={0x30, 0x30, 0x30, 0x20, 0x28, 0x06, 0x0C, 0x01, 0x80};
unsigned int i, j, flag, temp, flag2, temp1, x;

void LCD_Write();
void Port_Write();
void delay();
int Randoms(int lower, int upper);

int main(){
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_GPIO0->FIODIR=(1<<RS |1<<EN |0xF<<DT);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
	flag=0;
	
	for(i=0; i<9; i++){
		temp=cmd[i];
		LCD_Write();
	}
	
	flag=1;
	i=0;
	while(1){
		x=(LPC_GPIO0->FIOPIN&1<<21);
		if(!x){
			temp=48+Randoms(1,6);
		LCD_Write();
		i++;
		if(i==16){
			flag=0;
			temp=0xC0;
			LCD_Write();
			flag=1;
		}
	 }
 }
 return 0;
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


int Randoms(int lower, int upper) 
{ 
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
} 
 