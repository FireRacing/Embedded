#include <lpc17xx.h>
#include<stdlib.h>
#define rs 27 //P0.27
#define en 28 //P0.28
#define dt 23 //P0.13 - P0.26
int flag,temp,flag2,flag3,temp1,j,i,m,row,col,y;
unsigned char cmd[]={0x30,0x30,0x30,0x20,0x28,0x06,0x0c,0x80,0x01};
void scan();
void lcd_write();
void port_write();
void delay();
int main(){
unsigned char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
SystemInit();
SystemCoreClockUpdate();
LPC_GPIO1->FIODIR=0<<23;
LPC_GPIO0->FIODIR=(1<<rs|1<<en|0xf<<dt);
LPC_GPIO2->FIODIR=0X0F<<10;
flag=0;
for(i=0;i<9;i++){
temp=cmd[i];
lcd_write();
}
flag=1;
while(1){
for(row=0;row<4;row++){
LPC_GPIO2->FIOPIN=1<<(row+10);
flag3=0;
scan();
if(flag3==1){
break;}}
if(flag3==1){
y=4*row+col;
temp=a[y];
  lcd_write();}}
}
void scan(){
unsigned long x;
x=LPC_GPIO1->FIOPIN&(0xF<<23);
if(x!=0){
flag3=1;
x=x>>23;
if(x==1){ col=0;}
if(x==2){col=1;}
if(x==4){col=2;}
if(x==8){col=3;}
}}
void lcd_write(){
int flag2=(flag==1)?0:((temp==0x30||temp==0x20)?1:0);
temp1= temp&0xf0;
temp1=temp1>>4;
temp1=temp1<<dt;
port_write();
if(!flag2){
temp1=temp&0x0f;
temp1=temp1<<dt;
port_write();
}
}
void port_write(){
LPC_GPIO0->FIOPIN=0;
LPC_GPIO0->FIOPIN=temp1;
if(flag==0){
LPC_GPIO0->FIOCLR=1<<rs;}
else{
LPC_GPIO0->FIOSET=1<<rs;}
LPC_GPIO0->FIOSET=1<<en;
for(j=0;j<25;j++);
LPC_GPIO0->FIOCLR=1<<en;
delay(150000);
}
void delay(int d){
unsigned int k;
for(k=0;k<d;k++);
}