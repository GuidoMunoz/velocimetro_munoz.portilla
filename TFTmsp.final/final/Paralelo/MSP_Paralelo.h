/*
 * MSP_Paralelo.h
 *
 *  Created on: Dec 17, 2019
 *      Author: Manuel
 */

#ifndef PARALELO_MSP_PARALELO_H_
#define PARALELO_MSP_PARALELO_H_

#include <msp430.h>


void init_paralelo(void);
void imagen_send(int img);
void cuadrante_send(int cuad);
void send(int img, int cuad, int err);
void mapa_tft(double lati, double longi);

#endif /* PARALELO_MSP_PARALELO_H_ */
