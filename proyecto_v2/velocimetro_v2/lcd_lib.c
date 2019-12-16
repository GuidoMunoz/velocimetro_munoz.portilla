/*
 * lcd_lib.c
 *
 *  Created on: 15-12-2019
 *      Author: Guido
 */
#include <msp430.h>

/* uC and LCD Connections
    TP1 - Vcc (+5v)
    TP3 - Vss (Gnd)
    P3.0 - D4
    P3.1 - D5
    P3.2 - D6
    P3.3 - D7
    P3.4 - EN
    P3.5 - RS
    Gnd  - RW
    Gnd  - Vee through 1K Resistor  - this value determines contrast - i.e. direct connection to Gnd means all dots displayed
    Gnd  - K (LED-)
    Vcc  - A (LED+) +5V
    Clock: 1MHz             */
// uC Port definitions
#define lcd_port        P4OUT
#define lcd_port_dir    P4DIR

//port definitions for other commands

#define com_port        P2OUT
#define com_port_dir    P2DIR

// LCD Registers masks based on pin to which it is connected
#define LCD_EN      BIT3
#define LCD_RS      BIT4

void lcd_en(void){
    com_port |= LCD_EN;
    com_port &= ~LCD_EN;
}

void lcd_reset()
{
    lcd_port_dir = 0xff;    // output mode
    com_port_dir = 0xff; //Output mode for port 2
    lcd_port = 0xff;
    __delay_cycles(20000);
    lcd_port = 0x03;
    lcd_en();
    lcd_port = 0x03;
    __delay_cycles(10000);
    lcd_port = 0x03;
    lcd_en();
    lcd_port = 0x03;
    __delay_cycles(1000);
    lcd_port = 0x03;
    lcd_en();
    lcd_port = 0x03;
    __delay_cycles(1000);
    lcd_port = 0x02;
    lcd_en();
    lcd_port = 0x02;
    __delay_cycles(1000);
}

void lcd_cmd (char cmd)
{
    // Send upper nibble
    lcd_port = ((cmd >> 4) & 0x0F);
    com_port &= ~LCD_RS;
    lcd_en();
    //lcd_port = ((cmd >> 4) & 0x0F);

    // Send lower nibble
    lcd_port = (cmd & 0x0F);
    com_port &= ~LCD_RS;
    lcd_en();
    //lcd_port = (cmd & 0x0F);

    __delay_cycles(4000);
}

void lcd_init ()
{
    lcd_reset();         // Call LCD reset
    lcd_cmd(0x28);       // 4-bit mode - 2 line - 5x7 font.
    lcd_cmd(0x0C);       // Display no cursor - no blink.
    lcd_cmd(0x06);       // Automatic Increment - No Display shift.
    lcd_cmd(0x80);       // Address DDRAM with 0 offset 80h.
    lcd_cmd(0x01);       // Clear screen
}


void lcd_data (unsigned char dat)
{
    // Send upper nibble
    lcd_port = ((dat >> 4) & 0x0F);
    com_port |= LCD_RS;
    lcd_en();
    //7com_port |= LCD_RS;
    //lcd_port = ((dat >> 4) & 0x0F);

    // Send lower nibble
    lcd_port = (dat & 0x0F);
    com_port |= LCD_RS;
    lcd_en();
    //com_port |= LCD_RS;
    //lcd_port = (dat & 0x0F);

    __delay_cycles(4000); // a small delay may result in missing char display
}

void display_line(char *line)
{
    while (*line)
        lcd_data(*line++);
}

void limpiar_pantalla(void){
    lcd_cmd(0x80); // select 1st line (0x80 + addr) - here addr = 0x00
    display_line("                ");
    lcd_cmd(0xc0);
    display_line("                ");
}
