#include <msp430.h> 

#include "Paralelo/MSP_Paralelo.h"


int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
        volatile unsigned int i;
        volatile unsigned int j;
        init_paralelo();

        while (1){
        mapa_tft(3305.5160,7035.1141);
        for(i = 10000; i>0; i--){
            for(j = 100; j>0; j--);
        }
        mapa_tft(3325.3160,7035.1141);
        for(i = 10000; i>0; i--){
            for(j = 100; j>0; j--);
        }
        mapa_tft(3325.5160,7035.4141);
        for(i = 10000; i>0; i--){
            for(j = 100; j>0; j--);
        }
        mapa_tft(3326.5160,7031.1141);
        for(i = 10000; i>0; i--){
            for(j = 100; j>0; j--);
        }
        mapa_tft(3326.0160,7035.0141);
        for(i = 10000; i>0; i--){
            for(j = 100; j>0; j--);
        }

        }

}
