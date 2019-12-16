/*
 * lcd_lib.h
 *
 *  Created on: 15-12-2019
 *      Author: Guido
 */

#ifndef LCD_LIB_H_
#define LCD_LIB_H_


void lcd_reset(void);

void lcd_cmd (char cmd);

void lcd_init(void);

void lcd_data(unsigned char dat);

void display_line(char *line);

void limpiar_pantalla(void);

#endif /* LCD_LIB_H_ */
