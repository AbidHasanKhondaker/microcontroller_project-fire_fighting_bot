
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>


void left_rotate(){
	PORTD=0b00000110;
}

void right_rotate(){
	PORTD=0b00001001;
}

void go_straight(){
	PORTD=0b00001010;
}

void go_back(){
	PORTD=0b00000101;
}

void stop(){
	PORTD=0b00000000;
}



int main(void)
{
	char inp,inp2;
	DDRA =0b00000000;
	DDRD =0b11111111;
	DDRB =0b01000110;
	
	
	int gas =0;
	while (1)
	{
		
		if(PINB & 0b10000000){
			gas=1;
			char tem=PINB;
			PORTB=tem|0b01000000;
		}
		
		if(gas==1){
			inp=~PINA;
			inp2=~PINB;
			
			
			if(inp2 & 0b00000001){
				//go_back();
				//_delay_us(10);
				
				PORTB=0b01000100;
				stop();
				PORTD=0b00000000;
			}
			else {
				PORTB=0b01000000;
			
			if(inp==0b00000000){
				stop();
			}
			
			else if((inp&0b00001000)!=0){
				go_straight();
			}
			
			else if(inp<=0b00000111){
				left_rotate();
			}
			
			else {
				right_rotate();
			}
			
			
			
		}
		}
		
	}
}

