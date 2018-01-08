#define LEDA() PORTB |= (1<<PB4)
#define LEDB() PORTD |= (1<<PD2)
#define LEDC() PORTC |= (1<<PC3)
#define LEDD() PORTC |= (1<<PC1)
#define LEDE() PORTC |= (1<<PC0)
#define LEDF() PORTB |= (1<<PB5)
#define LEDG() PORTC |= (1<<PC4)
#define LEDDP() PORTC |= (1<<PC2)

#define LEDa() PORTB &=~ (1<<PB4)
#define LEDb() PORTD &=~ (1<<PD2)
#define LEDc() PORTC &=~ (1<<PC3)
#define LEDd() PORTC &=~ (1<<PC1)
#define LEDe() PORTC &=~ (1<<PC0)
#define LEDf() PORTB &=~ (1<<PB5)
#define LEDg() PORTC &=~ (1<<PC4)
#define LEDdp() PORTC &=~ (1<<PC2)

#define LED1() PORTB |= (1<<PB2)
#define LED2() PORTD |= (1<<PD0)
#define LED3() PORTD |= (1<<PD1)
#define LED4() PORTC |= (1<<PC5)

#define led1() PORTB &=~ (1<<PB2)
#define led2() PORTD &=~ (1<<PD0)
#define led3() PORTD &=~ (1<<PD1)
#define led4() PORTC &=~ (1<<PC5)

#define LEDDD() PORTD |= (1<<PD7)
#define LEDdd() PORTD &=~ (1<<PD7)

uint8_t t = 0;

//const char chars[10] PROGMEM = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
//const char LEDsega[10] PROGMEM = {1, 0, 1, 1, 0, 1, 1, 1, 1, 1};
//const char LEDsegb[10] PROGMEM = {1, 1, 1, 1, 1, 0, 0, 1, 1, 1};
//const char LEDsegc[10] PROGMEM = {1, 1, 0, 1, 1, 1, 1, 1, 1, 1};
//const char LEDsegd[10] PROGMEM = {1, 0, 1, 1, 0, 1, 1, 0, 1, 1};
//const char LEDsege[10] PROGMEM = {1, 0, 1, 0, 0, 0, 1, 0, 1, 0};
//const char LEDsegf[10] PROGMEM = {1, 0, 0, 0, 1, 1, 1, 0, 1, 1};
//const char LEDsegg[10] PROGMEM = {0, 0, 1, 1, 1, 1, 1, 0, 1, 1};

int arraysearch(char a[], char s) {
	int x;
	x = -1;
	for(int i=0; i<sizeof(a); i++) {
		if (a[i] == s) {
			x = i;
		}
	}
	return x;
}

void lcdwritechar(int n, char ch) {
	switch(n) {
		case 1:
			LED1();
			led2();
			led3();
			led4();
			break;
		case 2:
			led1();
			LED2();
			led3();
			led4();
			break;
		case 3:
			led1();
			led2();
			LED3();
			led4();
			break;
		case 4:
			led1();
			led2();
			led3();
			LED4();
			break;
		default: 
			LED1();
			LED2();
			LED3();
			LED4();
			break;
	}
	/*if(arraysearch(chars, ch)>=0) {	
		//t=arraysearch(chars, ch);
		t=8;
		if(LEDsega[t] == 1) {
			LEDa();
		};
		if(LEDsegb[t] == 1) {
			LEDb();
		};
		if(LEDsegc[t] == 1) {
			LEDc();
		};
		if(LEDsegd[t] == 1) {
			LEDd();
		};
		if(LEDsege[t] == 1) {
			LEDe();
		};
		if(LEDsegf[t] == 1) {
			LEDf();
		};
		if(LEDsegg[t] == 1) {
			LEDg();
		};
	}
	else {
		LEDg();
	}*/
	switch(ch) {
		case 'j':
			LEDA();
			LEDb();
			LEDc();
			LEDd();
			LEDE();
			LEDF();
			LEDG();  
			break;
		default:
			LEDA();
			LEDB();
			LEDC();
			LEDD();
			LEDE();
			LEDF();
			LEDg();
			break;
	}
}
void lcdwriteint(int n, int ch, char dot) {
	switch(n) {
		case 1:
			LED1();
			led2();
			led3();
			led4();
			break;
		case 2:
			led1();
			LED2();
			led3();
			led4();
			break;
		case 3:
			led1();
			led2();
			LED3();
			led4();
			break;
		case 4:
			led1();
			led2();
			led3();
			LED4();
			break;
		default: 
			LED1();
			LED2();
			LED3();
			LED4();
			break;
	}
	switch(ch) {
		case 0:
			LEDa();
			LEDb();
			LEDc();
			LEDd();
			LEDe();
			LEDf();
			LEDG();
			break;
		case 1: 
			LEDA();
			LEDb();
			LEDc();
			LEDD();
			LEDE();
			LEDF();
			LEDG();
			break;
		case 2:
			LEDa();
			LEDb();
			LEDC();
			LEDd();
			LEDe();
			LEDF();
			LEDg(); 
			break;
		case 3:
			LEDa();
			LEDb();
			LEDc();
			LEDd();
			LEDE();
			LEDF();
			LEDg(); 
			break;
		case 4:
			LEDA();
			LEDb();
			LEDc();
			LEDD();
			LEDE();
			LEDf();
			LEDg(); 
			break;
		case 5:
			LEDa();
			LEDB();
			LEDc();
			LEDd();
			LEDE();
			LEDf();
			LEDg(); 
			break;
		case 6:
			LEDa();
			LEDB();
			LEDc();
			LEDd();
			LEDe();
			LEDf();
			LEDg(); 
			break;
		case 7:
			LEDa();
			LEDb();
			LEDc();
			LEDD();
			LEDE();
			LEDF();
			LEDG(); 
			break;
		case 8:
			LEDa();
			LEDb();
			LEDc();
			LEDd();
			LEDe();
			LEDf();
			LEDg(); 
			break;
		case 9:
			LEDa();
			LEDb();
			LEDc();
			LEDd();
			LEDE();
			LEDf();
			LEDg(); 
			break;
		default:
			LEDA();
			LEDB();
			LEDC();
			LEDD();
			LEDE();
			LEDF();
			LEDg();
			break;
	}
	switch(dot) {
		case '1':
			LEDdp();
			break;
		default:
			LEDDP();
			break;
	}
}