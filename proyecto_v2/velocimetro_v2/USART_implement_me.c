/***************************************************
 * This is a USART library for the ATMega328P.
 *
 * It can provide basic USART (serial) communication for any application.
 *
 * This code is in the public domain. Feel free to do with it whatever you want.
 *
 *
 *
 * FOR STUDENTS:
 *
 * This file will be given to you in an 'empty' state. The function bodies are
 * provided, but not their content. You are supposed to add the proper code
 * and complete these functions.
 *
 * Hint 1: RTFM! The Atmel device datasheets contain all information necessary.
 *
 * Hint 2: We do not expect you to write the most performant or exceptionally
 * well-engineered code, but it should work. If in doubt, sacrifice speed for
 * reliability. If you are bored, rewrite the entire library in assembler and
 * squeeze the last microsecond out of it.
 *
 ****************************************************/
#define F_CPU   16000000UL
#include <msp430.h>
#include <string.h>

#include "USART_implement_me.h"
//#include "TinyGPS++.h"

uint8_t USART_Init(struct USART_configuration config)
{
    UCA0CTL1 |= UCSWRST; //Resetea el módulo
    UCA0CTL1 |= UCSSEL_2; //Clock SMCLK=1,048MHz

    UCA0MCTL &= ~UCOS16; //UCOS16 = 0, no oversampling

    switch(config.baud_rate)
    {
    case 9600 : UCA0BR0 = 109; //9600
    UCA0BR1 = 0;
    break;
    case 57600 : UCA0BR0 = 18; //57600
    UCA0BR1 = 0;
    break;
    case 19200 : UCA0BR0 = 54; //19200
    UCA0BR1 = 0;
    break;
    case 38400 : UCA0BR0 = 27;
    UCA0BR1 = 0;
    break;
    case 1200 : UCA0BR0 = 105;
    UCA0BR1 = 3;
    break;
    case 2400 : UCA0BR0 = 180;
    UCA0BR1 = 1;
    break;
    case 4800 : UCA0BR0 = 218;
    UCA0BR1 = 0;
    break;
    default : P1OUT |= BIT0;
    break;
    }

    switch(config.baud_rate)
    {
    case 9600 : UCA0MCTL = (UCBRS_2);
    break;
    case 57600 : UCA0MCTL = (UCBRS_1);
    break;
    case 19200 : UCA0MCTL = (UCBRS_5);
    break;
    case 38400 : UCA0MCTL = (UCBRS_2);
    break;
    case 1200 : UCA0MCTL = (UCBRS_3);
    break;
    case 2400 : UCA0MCTL = (UCBRS_5);
    break;
    case 4800 : UCA0MCTL = (UCBRS_3);
    break;
    default : P1OUT |= BIT0;
    break;
    }
    //UCA0BR0 |= 109; //UCBR0 = 109, UCBRS0 = 2, UCBRF0 =0 -> Baud Rate 9600
    //UCA0MCTL |= UCBRS_2 + UCBRF_0;

    switch(config.data_bits){
    case 8 : UCA0CTL0 &= ~UC7BIT;
    break;
    case 7 : UCA0CTL0 |= UC7BIT;
    break;
    default : P1OUT |= BIT0;
    break;
    }

    switch(config.parity){
    case 0 : UCA0CTL0 &= ~UCPEN; //No parity bit
    UCA0CTL0 &= ~UCPAR;
    break;
    case 1 : UCA0CTL0 |= UCPEN; //Even parity
    UCA0CTL0 |= UCPAR;
    break;
    case 2 : UCA0CTL0 |= UCPEN; //Odd parity
    UCA0CTL0 &= ~UCPAR;
    break;
    default : P1OUT |= BIT0;
    break;
    }


    switch(config.stop_bits){
    case 1: UCA0CTL1 &= ~UCSPB; //1 stop bit
    break;
    case 2: UCA0CTL1 |= UCSPB; //2 stop bits
    break;
    default : P1OUT |= BIT0;
    break;
    }

    P3SEL |= BIT3 + BIT4;
    //P4SEL |= BIT4 + BIT5;
    //P1SEL2 |= BIT1+BIT2;
    UCA0CTL1 &= ~UCSWRST; //Inicializa USCI
    UCA0IE |= (UCRXIE); //Habilita interrupciones
    __delay_cycles(7000);
    return 0;
}

uint8_t USART_Init_usb(struct USART_configuration config)
{
    UCA1CTL1 |= UCSWRST; //Resetea el módulo
    UCA1CTL1 |= UCSSEL_2; //Clock SMCLK=1,048MHz

    UCA1MCTL &= ~UCOS16; //UCOS16 = 0, no oversampling

    switch(config.baud_rate)
    {
    case 9600 : UCA1BR0 = 109; //9600
    UCA1BR1 = 0;
    break;
    case 57600 : UCA1BR0 = 18; //57600
    UCA1BR1 = 0;
    break;
    case 19200 : UCA1BR0 = 54; //19200
    UCA1BR1 = 0;
    break;
    case 38400 : UCA1BR0 = 27;
    UCA1BR1 = 0;
    break;
    case 1200 : UCA1BR0 = 105;
    UCA1BR1 = 3;
    break;
    case 2400 : UCA1BR0 = 180;
    UCA1BR1 = 1;
    break;
    case 4800 : UCA1BR0 = 218;
    UCA1BR1 = 0;
    break;
    default : P1OUT |= BIT0;
    break;
    }

    switch(config.baud_rate)
    {
    case 9600 : UCA1MCTL = (UCBRS_2);
    break;
    case 57600 : UCA1MCTL = (UCBRS_1);
    break;
    case 19200 : UCA1MCTL = (UCBRS_5);
    break;
    case 38400 : UCA1MCTL = (UCBRS_2);
    break;
    case 1200 : UCA1MCTL = (UCBRS_3);
    break;
    case 2400 : UCA1MCTL = (UCBRS_5);
    break;
    case 4800 : UCA1MCTL = (UCBRS_3);
    break;
    default : P1OUT |= BIT0;
    break;
    }
    //UCA0BR0 |= 109; //UCBR0 = 109, UCBRS0 = 2, UCBRF0 =0 -> Baud Rate 9600
    //UCA0MCTL |= UCBRS_2 + UCBRF_0;

    switch(config.data_bits){
    case 8 : UCA1CTL0 &= ~UC7BIT;
    break;
    case 7 : UCA1CTL0 |= UC7BIT;
    break;
    default : P1OUT |= BIT0;
    break;
    }

    switch(config.parity){
    case 0 : UCA1CTL0 &= ~UCPEN; //No parity bit
    UCA1CTL0 &= ~UCPAR;
    break;
    case 1 : UCA1CTL0 |= UCPEN; //Even parity
    UCA1CTL0 |= UCPAR;
    break;
    case 2 : UCA1CTL0 |= UCPEN; //Odd parity
    UCA1CTL0 &= ~UCPAR;
    break;
    default : P1OUT |= BIT0;
    break;
    }


    switch(config.stop_bits){
    case 1: UCA1CTL1 &= ~UCSPB; //1 stop bit
    break;
    case 2: UCA1CTL1 |= UCSPB; //2 stop bits
    break;
    default : P1OUT |= BIT0;
    break;
    }

    //P3SEL |= BIT3 + BIT4;
    P4SEL |= BIT4 + BIT5;
    //P1SEL2 |= BIT1+BIT2;
    UCA1CTL1 &= ~UCSWRST; //Inicializa USCI
    //UCA1IE |= UCTXIE; //Habilita interrupciones
    __delay_cycles(7000);
    return 0;
}

// Transmits a single character
void USART_Transmit_char(uint8_t data)
{
    //while (!(UCA0IFG&UCTXIFG)); //Checks for data being transmitted
    UCA0TXBUF = data;
    UCA0IFG &= ~UCTXIFG;
    //UCA0TXBUF = data;
}

// Transmits a single character, usb
void USART_Transmit_char_usb(uint8_t data)
{
    while (!(UCA1IFG&UCTXIFG)); //Checks for data being transmitted
    UCA1TXBUF = data;
    UCA1IFG &= ~UCTXIFG;
}



// Transmits a given string
void USART_Transmit_String(char* string)
{

    while(*string != 0x00){
        //__delay_cycles(100);
        USART_Transmit_char(*string);
        string ++;
    }
}

// Transmits a given string through usb
void USART_Transmit_String_usb(char* string)
{

    while(*string != 0x00){
        //__delay_cycles(100);
        USART_Transmit_char_usb(*string);
        string ++;
    }
}

unsigned char USART_Receive_char(void)
{
    unsigned char string;
    while (!(UCA0IFG&UCRXIFG));
    //if(UCA0IFG&UCRXIFG){ //If a transmission has been completed
    string = UCA0RXBUF;
//}
    UCA0IFG &= ~UCRXIFG;
    return string;
}

void USART_Receive_String(int length, char string[])
{
    unsigned volatile int i = 0;
    //char* string;
    while (i < length){
        string[i] = USART_Receive_char();
        //string++;
        i++;
    }
}

char* USART_Obtain(char Array[], int length)
{
    unsigned int i = 0;

    while((i <= length))                 //Grab data till the array fills
    {
        Array[i] = USART_Receive_char();
        if(Array[i] == '\n')                //If we receive a \r the master wants to end
        {
            for( ; i < length ; i++)        //fill the rest of the string with \0 nul. Overwrites the \r with \0
            {
                Array[i] = '\0';
            }
            break;
        }
        i++;
        if (i == length){
            i = 0;  //If buffer is filled, start from the beginning.
        }
    }


    return Array;
}
