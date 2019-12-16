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
 * This file is complete, but the according .c file will be given to you in an
 * 'empty' state. See there for further information.
 * 
 ****************************************************/

#ifndef _USART_IMPLEMENT_ME_H_
#define _USART_IMPLEMENT_ME_H_

#include <stdint.h>

struct USART_configuration
{
    unsigned long baud_rate;
    unsigned int data_bits;
    unsigned int parity;
    unsigned int stop_bits;
};

// Call once to initialise USART communication
uint8_t USART_Init(struct USART_configuration config);

// Call once to initialise USART communication
uint8_t USART_Init_usb(struct USART_configuration config);

// Transmits a single character
void USART_Transmit_char(uint8_t data);

// Transmits a single character
void USART_Transmit_char_usb(uint8_t data);

// Transmits a given string
void USART_Transmit_String(char* string);

// Transmits a given string through usb
void USART_Transmit_String_usb(char* string);

// Receives a char
unsigned char USART_Receive_char(void);

// Receives a string
void USART_Receive_String(int length, char string[]);

//Receives a string which length we know. Returns the adress of last recieved char
char* USART_Obtain(char* Array, int length);


#endif // _USART_IMPLEMENT_ME_H_
