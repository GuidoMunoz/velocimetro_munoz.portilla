#include <msp430.h> 

//#include "TinyGPS++.h"
#include <USART_implement_me.h>

/**
 * Tx -> 3.3
 * Rx -> 3.4
 * Realterm -> Puerto 9 9600 8N1
 */

volatile char buf[200]; //Buffer lineal para guardar las cosas del GPS
volatile unsigned int index_buf=0; //Index para recorrer el buffer lineal
volatile char condition=0; //Checks if lineal buffer has been filled or not

volatile int k;
volatile char debug;

volatile unsigned int cont_clock=0;
volatile unsigned int buf_index=0;
//Timer de 1 milisegundo
void timer0_init(void){
    cont_clock = 0;
    TA0CCTL0 = CCIE; //Enables interrupt CCR0
    TA0CCR0 = 4;  // set up terminal count, 4000-> 1 seg, 4-> 1 mseg
    TA0CTL = TASSEL_1 + ID_3 + MC_1; // Select clock, freq divider and mode control, clock de 4khz
}
//Timer para que se detenga
void timer0_stop(void){
    TA0CTL &= ~MC_1;
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void)
{
    if(!(UCA0STAT&UCBUSY)){
        cont_clock++;
    }
    else{
        cont_clock = 0;
    }
    if(cont_clock == 3){
        condition = 1;
    }
}


int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    struct USART_configuration config_9600_8N1 = {9600, 8, 0, 1}; //9600 bps, 8 bits, sin paridad y 1 stop bit
    USART_Init(config_9600_8N1);
    USART_Init_usb(config_9600_8N1);
    timer0_init();
    //struct gps_tpv tpv;
    _EINT(); //Habilita interrupciones
    //USART_Transmit_char('0'); //Dato inofensivo para iniciar comunicación.

	while(1){
	    if(condition){
	        USART_Transmit_String_usb(buf);
	        condition = 0;
	        buf_index = 0;
	    }
	}
	return 0;
}

//ISR Para A1 (gps), se activa para recepción y transmisión.

#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void)
{
    /*
   if(UCA0IFG&UCRXIFG){
   char debug = USART_Receive_char(); //Recibe un char y lo coloca en la posicion i del buffer
   buf[index_buf] = debug;
   index_buf++;
   if(index_buf > 200){
       index_buf = 0;
   }
   if((debug == '\r')||(debug == '\n')){
       condition = 1; //Condition fulfilled
       for(k = index_buf+3; k<200;k++){
           buf[k] = '\0';
       }
       index_buf = 0;
   }*/
   debug = USART_Receive_char();
   buf[buf_index] = debug;
   buf_index++;
   UCA0IFG &= ~UCRXIFG;
   //}

}

/*#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void)
{
    UCA1IFG &= ~((UCTXIFG)|(UCRXIFG));
}*/

