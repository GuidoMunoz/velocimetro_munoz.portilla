#include <msp430.h> 

#include <stdio.h>
#include <stdlib.h>
#include <gps.h>
#include <lcd_lib.h>

#include <math.h>

#define PI 3.14159265

void find_course(double old_x, double old_y, double curr_x, double curr_y, char dir[]){
    char EW; //Este ->0, Oeste ->1
    char NS; //Norte -> 0, Sur ->1
    char aux;
    aux = atan((old_y - curr_y)/(old_x - curr_x));
}

int main(void) {
    // Open
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    gps_init();
    int lat;
    int log;
    P1DIR |= (0x01);
    loc_t data;

    lcd_init();

    limpiar_pantalla();

    while (1) {
        gps_location(&data);
        if(data.speed != 0){
            P1OUT ^= 0x01;

            int tmp = data.speed*10*1.852;
            int tmpa = data.course;
            char arr[3];
            char arra[3];
            int x,y,z;

            x = tmp/100;
            tmp -= x*100;
            y = tmp/10;
            tmp -= y*10;
            z = tmp;

            arr[0] = (char)(x+48);
            arr[1] = (char)(y+48);
            arr[2] = (char)(z+48);

            x = tmpa/100;
            tmpa -= x*100;
            y = tmpa/10;
            tmpa -= y*10;
            z = tmpa;

            arra[0] = (char)(x+48);
            arra[1] = (char)(y+48);
            arra[2] = (char)(z+48);

            limpiar_pantalla();

            lcd_cmd(0x80); // select 1st line (0x80 + addr) - here addr = 0x00
            display_line(arra);
            lcd_cmd(0xc0);
            display_line(arr);


        }

    }

    return EXIT_SUCCESS;
}

