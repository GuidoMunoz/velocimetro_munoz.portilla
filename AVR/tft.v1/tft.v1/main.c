// MCU Clock Speed - needed for delay.h
#define F_CPU	16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <avr/interrupt.h>


#include "SPI/SPI_implement_me.h"

#include "PetitFatFilesystem/PetitFS.h"

#include "display/ST7735_commands.h"
#include "display/graphic_shapes.h"
#include "display/testroutines.h"


// UART configuration

void imagen_mapa(char* imagen);
void posicion(int cuadrante, int16_t radio);
void p_real(char* imagen, int cuadrante, int16_t err);
void par_init(void);
char* rec_imagen(void);
int16_t rec_cuadrante(void);


/* A simple helper function to stop in case of some error */
void errorHalt(char* msg) {
	
	while(1);
}

//Variables interrupcion
volatile int16_t cuad;
volatile int16_t fail;
char* img;



/** The main function */
int main(void)
{

	//struct buffer ring; //Buffer UART Receive
	//buffer_init(&ring, 20);
	
	
	// Initialises USART
	
	//Init Pantalla y SPI
	SPI_Master_Init();
	ST7735_init();
	par_init();
	
	
	sei();
	
	//Variables operacion del loop
	

	//Loop infinito de prueba interfas de prueba
	//Inicializar imagen de la tft
	SPI_TFTsel();
	fillScreen(ST7735_BLACK);
	SPI_TFTdsel();
	
	while(1){
		//No hacer nada
		
		
// 		p_real("imagen0.bmp",0);
// 		p_real("imagen1.bmp",1);
// 		p_real("imagen2.bmp",2);
// 		p_real("imagen3.bmp",3);
// 		p_real("imagen4.bmp",4);
// 		p_real("imagen5.bmp",5);
// 		p_real("imagen6.bmp",6);
// 		p_real("imagen7.bmp",7);
// 		p_real("imagen8.bmp",8);
// 		p_real("imagen9.bmp",9);
// 		p_real("imagen10.bmp",10);
// 		p_real("imagen11.bmp",11);
// 		p_real("imagen12.bmp",12);
// 		p_real("imagen13.bmp",13);
// 		p_real("imagen14.bmp",14);
// 		p_real("imagen15.bmp",15);
	}
	
	
}

//Funcion desplegar imagen del mapa
void imagen_mapa(char* imagen){
	uint8_t z_pos;
	uint8_t pixels[480];
	
	FATFS sf;     		/* File system structure */
	UINT rn;			/* Used for various file access functions. */

	//LIMPIAR DISPLAY (?)
	//SPI_TFTsel();
	//fillScreen(ST7735_BLACK);
	//SPI_TFTdsel();
	
	//CASO ERROR
	if (imagen == "error")
	{
		fillScreen(ST7735_YELLOW);
		errorHalt("error");
		return;
	}

	//MONTAR TARJETA
	if (pf_mount(&sf)) {
		//ERROR ABRIR SD COLOR
		fillScreen(ST7735_RED);
		errorHalt("pf_mount");
		return;
	}

	//Abrir imagen del mapa
	if (pf_open(imagen)) {
		//ERROR ABRIR IMAGEN COLOR
		fillScreen(ST7735_BLUE);
		errorHalt("pf_open");
		return;
	}

	// Set read/write pointer to beginning of file.
	//Inicio de la imagen
	if (pf_lseek(138))  {
		//Imprimir color de error
		fillScreen(ST7735_GREEN);
		errorHalt("pf_lseek");
		return;
	}
	

	// Print test file to the serial interface.
	//Desplegar imagen
	z_pos = 127;
	while (1) {
		if (pf_read(pixels, sizeof(pixels), &rn)){
			fillScreen(ST7735_WHITE);
			errorHalt("pf_read");
			//Encender pantalla color ALGO
			return;
		}
		if (rn == 0) break;
		SPI_TFTsel();
		for(uint8_t x_pos=0; x_pos < 160; x_pos++)
		{
			drawPixelRGB(x_pos, z_pos, pixels[3*x_pos + 2], pixels[3*x_pos + 1], pixels[3*x_pos]);
		}
		SPI_TFTdsel();
		z_pos--;
	}
	
	//_delay_ms(100);
	return;
}

void posicion(int cuadrante, int16_t radio)
{
	switch(cuadrante) {
		case 0 :
		SPI_TFTsel();
		drawCircle(20,16,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		case 1 :
		SPI_TFTsel();
		drawCircle(60,16,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		case 2 :
		SPI_TFTsel();
		drawCircle(100,16,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		case 3 :
		SPI_TFTsel();
		drawCircle(140,16,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		case 4 :
		SPI_TFTsel();
		drawCircle(20,48,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		case 5 :
		SPI_TFTsel();
		drawCircle(60,48,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		case 6 :
		SPI_TFTsel();
		drawCircle(100,48,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		case 7 :
		SPI_TFTsel();
		drawCircle(140,48,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		case 8 :
		SPI_TFTsel();
		drawCircle(20,80,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		case 9 :
		SPI_TFTsel();
		drawCircle(60,80,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		case 10 :
		SPI_TFTsel();
		drawCircle(100,80,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		case 11 :
		SPI_TFTsel();
		drawCircle(140,80,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		case 12 :
		SPI_TFTsel();
		drawCircle(20,112,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		case 13 :
		SPI_TFTsel();
		drawCircle(60,112,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		case 14 :
		SPI_TFTsel();
		drawCircle(100,112,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		case 15 :
		SPI_TFTsel();
		drawCircle(140,112,radio,ST7735_RED);
		SPI_TFTdsel();
		break;
		
		//CASO ERROR
		default :
		SPI_TFTsel();
		drawCircle(80,64,30,ST7735_RED);
		SPI_TFTdsel();
		break;
	}
	//_delay_ms(10);
	return;
}

void p_real(char* imagen, int cuadrante, int16_t err)
{
	if (err == 1)
	{
		imagen_mapa("error.bmp");
		return;
	} else {
		imagen_mapa(imagen);
		posicion(cuadrante,12);
		posicion(cuadrante,13);
		return;
	}
}

//Init recepcion paralela
void par_init(void)
{
	//Puerto C como entrada
	DDRC &= 0x00;
	//PD0 y PD1 como entrada
	DDRD &= ~((1<<PORTD0) | (1<<PORTD1));
	//PB0 y PB1 como entrada
	DDRB &= ~((1<<PORTB0) | (1<<PORTB1));
	//Pullups
	PORTC |= (1<<PORTC0) | (1<<PORTC1) | (1<<PORTC2)  | (1<<PORTC3)  | (1<<PORTC4) | (1<<PORTC5);
	PORTD |= (1<<PORTD0) | (1<<PORTD1);
	PORTB |= (1<<PORTB0) | (1<<PORTB1);
	//Interrupcion Pin PC0
	PCMSK1 |= (1<<PCINT8);
	PCICR |= (1<<PCIE1);
}

//Funcion que entrega imagen
char* rec_imagen(void)
{
	if (!(PINC&(1<<PINC1)) && !(PINC&(1<<PINC2)) && !(PINC&(1<<PINC3)) && !(PINC&(1<<PINC4))) //Caso 0
	{
		return "imagen0.bmp";
	}
	else if (!(PINC&(1<<PINC1)) && !(PINC&(1<<PINC2)) && !(PINC&(1<<PINC3)) && (PINC&(1<<PINC4))) //Caso 1
	{
		return "imagen1.bmp";
	}
	else if (!(PINC&(1<<PINC1)) && !(PINC&(1<<PINC2)) && (PINC&(1<<PINC3)) && !(PINC&(1<<PINC4))) //Caso 2
	{
		return "imagen2.bmp";
	}
	else if (!(PINC&(1<<PINC1)) && !(PINC&(1<<PINC2)) && (PINC&(1<<PINC3)) && (PINC&(1<<PINC4))) //Caso 3
	{
		return "imagen3.bmp";
	}
	else if (!(PINC&(1<<PINC1)) && (PINC&(1<<PINC2)) && !(PINC&(1<<PINC3)) && !(PINC&(1<<PINC4))) //Caso 4
	{
		return "imagen4.bmp";
	}
	else if (!(PINC&(1<<PINC1)) && (PINC&(1<<PINC2)) && !(PINC&(1<<PINC3)) && (PINC&(1<<PINC4))) //Caso 5
	{
		return "imagen5.bmp";
	}
	else if (!(PINC&(1<<PINC1)) && (PINC&(1<<PINC2)) && (PINC&(1<<PINC3)) && !(PINC&(1<<PINC4))) //Caso 6
	{
		return "imagen6.bmp";
	}
	else if (!(PINC&(1<<PINC1)) && (PINC&(1<<PINC2)) && (PINC&(1<<PINC3)) && (PINC&(1<<PINC4))) //Caso 7
	{
		return "imagen7.bmp";
	}
	else if ((PINC&(1<<PINC1)) && !(PINC&(1<<PINC2)) && !(PINC&(1<<PINC3)) && !(PINC&(1<<PINC4))) //Caso 8
	{
		return "imagen8.bmp";
	}
	else if ((PINC&(1<<PINC1)) && !(PINC&(1<<PINC2)) && !(PINC&(1<<PINC3)) && (PINC&(1<<PINC4))) //Caso 9
	{
		return "imagen9.bmp";
	}
	else if ((PINC&(1<<PINC1)) && !(PINC&(1<<PINC2)) && (PINC&(1<<PINC3)) && !(PINC&(1<<PINC4))) //Caso 10
	{
		return "imagen10.bmp";
	}
	else if ((PINC&(1<<PINC1)) && !(PINC&(1<<PINC2)) && (PINC&(1<<PINC3)) && (PINC&(1<<PINC4))) //Caso 11
	{
		return "imagen11.bmp";
	}
	else if ((PINC&(1<<PINC1)) && (PINC&(1<<PINC2)) && !(PINC&(1<<PINC3)) && !(PINC&(1<<PINC4))) //Caso 12
	{
		return "imagen12.bmp";
	}
	else if ((PINC&(1<<PINC1)) && (PINC&(1<<PINC2)) && !(PINC&(1<<PINC3)) && (PINC&(1<<PINC4))) //Caso 13
	{
		return "imagen13.bmp";
	}
	else if ((PINC&(1<<PINC1)) && (PINC&(1<<PINC2)) && (PINC&(1<<PINC3)) && !(PINC&(1<<PINC4))) //Caso 14
	{
		return "imagen14.bmp";
	}
	else if ((PINC&(1<<PINC1)) && (PINC&(1<<PINC2)) && (PINC&(1<<PINC3)) && (PINC&(1<<PINC4))) //Caso 15
	{
		return "imagen15.bmp";
	}
	else
	{
		return "error";
	}
}

//Funcion que entrega el circulo
int16_t rec_cuadrante(void)
{
	if (!(PINC&(1<<PINC5)) && !(PIND&(1<<PIND0)) && !(PIND&(1<<PIND1)) && !(PINB&(1<<PINB0))) //Caso 0
	{
		return 0;
	}
	else if (!(PINC&(1<<PINC5)) && !(PIND&(1<<PIND0)) && !(PIND&(1<<PIND1)) && (PINB&(1<<PINB0))) //Caso 1
	{
		return 1;
	}
	else if (!(PINC&(1<<PINC5)) && !(PIND&(1<<PIND0)) && (PIND&(1<<PIND1)) && !(PINB&(1<<PINB0))) //Caso 2
	{
		return 2;
	}
	else if (!(PINC&(1<<PINC5)) && !(PIND&(1<<PIND0)) && (PIND&(1<<PIND1)) && (PINB&(1<<PINB0))) //Caso 3
	{
		return 3;
	}
	else if (!(PINC&(1<<PINC5)) && (PIND&(1<<PIND0)) && !(PIND&(1<<PIND1)) && !(PINB&(1<<PINB0))) //Caso 4
	{
		return 4;
	}
	else if (!(PINC&(1<<PINC5)) && (PIND&(1<<PIND0)) && !(PIND&(1<<PIND1)) && (PINB&(1<<PINB0))) //Caso 5
	{
		return 5;
	}
	else if (!(PINC&(1<<PINC5)) && (PIND&(1<<PIND0)) && (PIND&(1<<PIND1)) && !(PINB&(1<<PINB0))) //Caso 6
	{
		return 6;
	}
	else if (!(PINC&(1<<PINC5)) && (PIND&(1<<PIND0)) && (PIND&(1<<PIND1)) && (PINB&(1<<PINB0))) //Caso 7
	{
		return 7;
	}
	else if ((PINC&(1<<PINC5)) && !(PIND&(1<<PIND0)) && !(PIND&(1<<PIND1)) && !(PINB&(1<<PINB0))) //Caso 8
	{
		return 8;
	}
	else if ((PINC&(1<<PINC5)) && !(PIND&(1<<PIND0)) && !(PIND&(1<<PIND1)) && (PINB&(1<<PINB0))) //Caso 9
	{
		return 9;
	}
	else if ((PINC&(1<<PINC5)) && !(PIND&(1<<PIND0)) && (PIND&(1<<PIND1)) && !(PINB&(1<<PINB0))) //Caso 10
	{
		return 10;
	}
	else if ((PINC&(1<<PINC5)) && !(PIND&(1<<PIND0)) && (PIND&(1<<PIND1)) && (PINB&(1<<PINB0))) //Caso 11
	{
		return 11;
	}
	else if ((PINC&(1<<PINC5)) && (PIND&(1<<PIND0)) && !(PIND&(1<<PIND1)) && !(PINB&(1<<PINB0))) //Caso 12
	{
		return 12;
	}
	else if ((PINC&(1<<PINC5)) && (PIND&(1<<PIND0)) && !(PIND&(1<<PIND1)) && (PINB&(1<<PINB0))) //Caso 13
	{
		return 13;
	}
	else if ((PINC&(1<<PINC5)) && (PIND&(1<<PIND0)) && (PIND&(1<<PIND1)) && !(PINB&(1<<PINB0))) //Caso 14
	{
		return 14;
	}
	else if ((PINC&(1<<PINC5)) && (PIND&(1<<PIND0)) && (PIND&(1<<PIND1)) && (PINB&(1<<PINB0))) //Caso 15
	{
		return 15;
	}
	else
	{
		return 16;
	}
}

//Recibir error
int16_t rec_error(void)
{
	if (PINB&(1<<PINB1))
	{
		return 1;
	} else {
		return 0;
	}
}

//Interrupcion Comunicacion paralela
ISR(PCINT1_vect)
{
	//leer info msp
	img = rec_imagen();
	cuad = rec_cuadrante();
	fail = rec_error();
	
	//imprimir en pantalla
	p_real(img, cuad, fail);	
}
