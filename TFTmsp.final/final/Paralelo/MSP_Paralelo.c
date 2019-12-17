#include <msp430.h>
#include "MSP_Paralelo.h"


void init_paralelo(void)
{
    P8DIR |= BIT1 | BIT2;
    P1DIR |= BIT2 | BIT3 | BIT4 | BIT5;
    P6DIR |= BIT0 | BIT1 | BIT2 | BIT3;
}

void imagen_send(int img)
{
    P1OUT = 0x00;
    switch(img) {
        case 0 :
        P1OUT = 0x00;
        break;

        case 1 :
        P1OUT |= BIT5;
        break;

        case 2 :
        P1OUT |= BIT4;
        break;

        case 3 :
        P1OUT |= BIT4 | BIT5;
        break;

        case 4 :
        P1OUT |= BIT3;
        break;

        case 5 :
        P1OUT |= BIT3 | BIT5;
        break;

        case 6 :
        P1OUT |= BIT3 | BIT4;
        break;

        case 7 :
        P1OUT |= BIT3 | BIT4 | BIT5;
        break;

        case 8 :
        P1OUT |= BIT2;
        break;

        case 9 :
        P1OUT |= BIT2 | BIT5;
        break;

        case 10 :
        P1OUT |= BIT2 | BIT4;
        break;

        case 11 :
        P1OUT |= BIT2 | BIT4 | BIT5;
        break;

        case 12 :
        P1OUT |= BIT2 | BIT3;
        break;

        case 13 :
        P1OUT |= BIT2 | BIT3 | BIT5;
        break;

        case 14 :
        P1OUT |= BIT2 | BIT3 | BIT4;
        break;

        case 15 :
        P1OUT |= BIT2 | BIT3 | BIT4 | BIT5;
        break;
    }
}

void cuadrante_send(int cuad)
{
    P6OUT = 0x00;
    switch(cuad) {
        case 0 :
        P6OUT = 0x00;
        break;

        case 1 :
        P6OUT |= BIT3;
        break;

        case 2 :
        P6OUT |= BIT2;
        break;

        case 3 :
        P6OUT |= BIT2 | BIT3;
        break;

        case 4 :
        P6OUT |= BIT1;
        break;

        case 5 :
        P6OUT |= BIT1 | BIT3;
        break;

        case 6 :
        P6OUT |= BIT1 | BIT2;
        break;

        case 7 :
        P6OUT |= BIT1 | BIT2 | BIT3;
        break;

        case 8 :
        P6OUT |= BIT0;
        break;

        case 9 :
        P6OUT |= BIT0 | BIT3;
        break;

        case 10 :
        P6OUT |= BIT0 | BIT2;
        break;

        case 11 :
        P6OUT |= BIT0 | BIT2 | BIT3;
        break;

        case 12 :
        P6OUT |= BIT0 | BIT1;
        break;

        case 13 :
        P6OUT |= BIT0 | BIT1 | BIT3;
        break;

        case 14 :
        P6OUT |= BIT0 | BIT1 | BIT2;
        break;

        case 15 :
        P6OUT |= BIT0 | BIT1 | BIT2 | BIT3;
        break;
    }

}

void send(int img, int cuad, int err)
{
    if (err == 1)
    {
        P8OUT |= BIT2;
        P8OUT ^= BIT1;
        return;
    } else {
        P8OUT &= ~BIT2;
        imagen_send(img);
        cuadrante_send(cuad);
        P8OUT ^= BIT1;
        return;
    }

}

void mapa_tft(double lati, double longi)
{

    //Enviar las imagenes mapa segun su coordenada
    //Imagen 0, cuad 0
    if ((7036.384114>=longi) && (longi>=7036.32184) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(0,0,0);
    }
    //Imagen 0, cuad 1
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(0,1,0);
    }
    //Imagen 0, cuad 2
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(0,2,0);
    }
    //Imagen 0, cuad 3
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(0,3,0);
    }
    //Imagen 0, cuad 4
    else if ((7036.384114>=longi) && (longi>=7036.32184) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(0,4,0);
    }
    //Imagen 0, cuad 5
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(0,5,0);
    }
    //Imagen 0, cuad 6
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(0,6,0);
    }
    //Imagen 0, cuad 7
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(0,7,0);
    }
    //Imagen 0, cuad 8
    else if ((7036.384114>=longi) && (longi>=7036.32184) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(0,8,0);
    }
    //Imagen 0, cuad 9
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(0,9,0);
    }
    //Imagen 0, cuad 10
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(0,10,0);
    }
    //Imagen 0, cuad 11
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(0,11,0);
    }
    //Imagen 0, cuad 12
    else if ((7036.384114>=longi) && (longi>=7036.32184) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(0,12,0);
    }
    //Imagen 0, cuad 13
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(0,13,0);
    }
    //Imagen 0, cuad 14
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(0,14,0);
    }
    //Imagen 0, cuad 15
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(0,15,0);
    }



    //Imagen 1, cuad 0
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(1,0,0);
    }
    //Imagen 1, cuad 1
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(1,1,0);
    }
    //Imagen 1, cuad 2
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(1,2,0);
    }
    //Imagen 1, cuad 3
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(1,3,0);
    }
    //Imagen 1, cuad 4
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(1,4,0);
    }
    //Imagen 1, cuad 5
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(1,5,0);
    }
    //Imagen 1, cuad 6
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(1,6,0);
    }
    //Imagen 1, cuad 7
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(1,7,0);
    }
    //Imagen 1, cuad 8
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(1,8,0);
    }
    //Imagen 1, cuad 9
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(1,9,0);
    }
    //Imagen 1, cuad 10
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(1,10,0);
    }
    //Imagen 1, cuad 11
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(1,11,0);
    }
    //Imagen 1, cuad 12
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(1,12,0);
    }
    //Imagen 1, cuad 13
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(1,13,0);
    }
    //Imagen 1, cuad 14
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(1,14,0);
    }
    //Imagen 1, cuad 15
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(1,15,0);
    }





    //Imagen 2, cuad 0
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(2,0,0);
    }
    //Imagen 2, cuad 1
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(2,1,0);
    }
    //Imagen 2, cuad 2
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(2,2,0);
    }
    //Imagen 2, cuad 3
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(2,3,0);
    }
    //Imagen 2, cuad 4
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(2,4,0);
    }
    //Imagen 2, cuad 5
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(2,5,0);
    }
    //Imagen 2, cuad 6
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(2,6,0);
    }
    //Imagen 2, cuad 7
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(2,7,0);
    }
    //Imagen 2, cuad 8
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(2,8,0);
    }
    //Imagen 2, cuad 9
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(2,9,0);
    }
    //Imagen 2, cuad 10
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(2,10,0);
    }
    //Imagen 2, cuad 11
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(2,11,0);
    }
    //Imagen 2, cuad 12
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(2,12,0);
    }
    //Imagen 2, cuad 13
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(2,13,0);
    }
    //Imagen 2, cuad 14
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(2,14,0);
    }
    //Imagen 2, cuad 15
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(2,15,0);
    }



    //Imagen 3, cuad 0
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(3,0,0);
    }
    //Imagen 3, cuad 1
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(3,1,0);
    }
    //Imagen 3, cuad 2
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(3,2,0);
    }
    //Imagen 2, cuad 3
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3325.256044<=lati) && (lati<=3325.279264))
    {
        send(3,3,0);
    }
    //Imagen 3, cuad 4
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(3,4,0);
    }
    //Imagen 3, cuad 5
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(3,5,0);
    }
    //Imagen 3, cuad 6
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(3,6,0);
    }
    //Imagen 3, cuad 7
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3325.279264<=lati) && (lati<=3325.302514))
    {
        send(3,7,0);
    }
    //Imagen 3, cuad 8
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(3,8,0);
    }
    //Imagen 3, cuad 9
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(3,9,0);
    }
    //Imagen 3, cuad 10
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(3,10,0);
    }
    //Imagen 3, cuad 11
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3325.302514<=lati) && (lati<=3325.325734))
    {
        send(3,11,0);
    }
    //Imagen 3, cuad 12
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(3,12,0);
    }
    //Imagen 3, cuad 13
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(3,13,0);
    }
    //Imagen 3, cuad 14
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(3,14,0);
    }
    //Imagen 3, cuad 15
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3325.325734<=lati) && (lati<=3325.34899))
    {
        send(3,15,0);
    }




    //Imagen 4, cuad 0
    else if ((7036.384114>=longi) && (longi>=7036.32184) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(4,0,0);
    }
    //Imagen 4, cuad 1
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(4,1,0);
    }
    //Imagen 4, cuad 2
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(4,2,0);
    }
    //Imagen 4, cuad 3
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(4,3,0);
    }
    //Imagen 4, cuad 4
    else if ((7036.384114>=longi) && (longi>=7036.32184) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(4,4,0);
    }
    //Imagen 4, cuad 5
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(4,5,0);
    }
    //Imagen 4, cuad 6
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(4,6,0);
    }
    //Imagen 4, cuad 7
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(4,7,0);
    }
    //Imagen 4, cuad 8
    else if ((7036.384114>=longi) && (longi>=7036.32184) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(4,8,0);
    }
    //Imagen 4, cuad 9
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(4,9,0);
    }
    //Imagen 4, cuad 10
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(4,10,0);
    }
    //Imagen 4, cuad 11
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(4,11,0);
    }
    //Imagen 4, cuad 12
    else if ((7036.384114>=longi) && (longi>=7036.32184) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(4,12,0);
    }
    //Imagen 4, cuad 13
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(4,13,0);
    }
    //Imagen 4, cuad 14
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(4,14,0);
    }
    //Imagen 4, cuad 15
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(4,15,0);
    }



    //Imagen 5, cuad 0
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(5,0,0);
    }
    //Imagen 5, cuad 1
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(5,1,0);
    }
    //Imagen 5, cuad 2
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(5,2,0);
    }
    //Imagen 5, cuad 3
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(5,3,0);
    }
    //Imagen 5, cuad 4
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(5,4,0);
    }
    //Imagen 5, cuad 5
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(5,5,0);
    }
    //Imagen 5, cuad 6
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(5,6,0);
    }
    //Imagen 5, cuad 7
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(5,7,0);
    }
    //Imagen 5, cuad 8
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(5,8,0);
    }
    //Imagen 5, cuad 9
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(5,9,0);
    }
    //Imagen 5, cuad 10
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(5,10,0);
    }
    //Imagen 5, cuad 11
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(5,11,0);
    }
    //Imagen 5, cuad 12
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(5,12,0);
    }
    //Imagen 5, cuad 13
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(5,13,0);
    }
    //Imagen 5, cuad 14
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(5,14,0);
    }
    //Imagen 5, cuad 15
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(5,15,0);
    }




    //Imagen 6, cuad 0
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(6,0,0);
    }
    //Imagen 6, cuad 1
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(6,1,0);
    }
    //Imagen 6, cuad 2
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(6,2,0);
    }
    //Imagen 6, cuad 3
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(6,3,0);
    }
    //Imagen 6, cuad 4
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(6,4,0);
    }
    //Imagen 6, cuad 5
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(6,5,0);
    }
    //Imagen 6, cuad 6
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(6,6,0);
    }
    //Imagen 6, cuad 7
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(6,7,0);
    }
    //Imagen 6, cuad 8
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(6,8,0);
    }
    //Imagen 6, cuad 9
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(6,9,0);
    }
    //Imagen 6, cuad 10
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(6,10,0);
    }
    //Imagen 6, cuad 11
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(6,11,0);
    }
    //Imagen 6, cuad 12
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(6,12,0);
    }
    //Imagen 6, cuad 13
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(6,13,0);
    }
    //Imagen 6, cuad 14
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(6,14,0);
    }
    //Imagen 6, cuad 15
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(6,15,0);
    }



    //Imagen 7, cuad 0
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(7,0,0);
    }
    //Imagen 7, cuad 1
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(7,1,0);
    }
    //Imagen 7, cuad 2
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(7,2,0);
    }
    //Imagen 7, cuad 3
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3325.34899<=lati) && (lati<=3325.37221))
    {
        send(7,3,0);
    }
    //Imagen 7, cuad 4
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(7,4,0);
    }
    //Imagen 7, cuad 5
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(7,5,0);
    }
    //Imagen 7, cuad 6
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(7,6,0);
    }
    //Imagen 7, cuad 7
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3325.37221<=lati) && (lati<=3325.395472))
    {
        send(7,7,0);
    }
    //Imagen 7, cuad 8
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(7,8,0);
    }
    //Imagen 7, cuad 9
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(7,9,0);
    }
    //Imagen 7, cuad 10
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(7,10,0);
    }
    //Imagen 7, cuad 11
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3325.395472<=lati) && (lati<=3325.418692))
    {
        send(7,11,0);
    }
    //Imagen 7, cuad 12
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(7,12,0);
    }
    //Imagen 7, cuad 13
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(7,13,0);
    }
    //Imagen 7, cuad 14
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(7,14,0);
    }
    //Imagen 7, cuad 15
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3325.418692<=lati) && (lati<=3325.441906))
    {
        send(7,15,0);
    }




    //Imagen 8, cuad 0
    else if ((7036.384114>=longi) && (longi>=7036.32184) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(8,0,0);
    }
    //Imagen 8, cuad 1
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(8,1,0);
    }
    //Imagen 8, cuad 2
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(8,2,0);
    }
    //Imagen 8, cuad 3
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(8,3,0);
    }
    //Imagen 8, cuad 4
    else if ((7036.384114>=longi) && (longi>=7036.32184) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(8,4,0);
    }
    //Imagen 8, cuad 5
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(8,5,0);
    }
    //Imagen 8, cuad 6
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(8,6,0);
    }
    //Imagen 8, cuad 7
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(8,7,0);
    }
    //Imagen 8, cuad 8
    else if ((7036.384114>=longi) && (longi>=7036.32184) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(8,8,0);
    }
    //Imagen 8, cuad 9
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(8,9,0);
    }
    //Imagen 8, cuad 10
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(8,10,0);
    }
    //Imagen 8, cuad 11
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(8,11,0);
    }
    //Imagen 8, cuad 12
    else if ((7036.384114>=longi) && (longi>=7036.32184) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(8,12,0);
    }
    //Imagen 8, cuad 13
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(8,13,0);
    }
    //Imagen 8, cuad 14
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(8,14,0);
    }
    //Imagen 8, cuad 15
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(8,15,0);
    }



    //Imagen 9, cuad 0
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(9,0,0);
    }
    //Imagen 9, cuad 1
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(9,1,0);
    }
    //Imagen 9, cuad 2
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(9,2,0);
    }
    //Imagen 9, cuad 3
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(9,3,0);
    }
    //Imagen 9, cuad 4
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(9,4,0);
    }
    //Imagen 9, cuad 5
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(9,5,0);
    }
    //Imagen 9, cuad 6
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(9,6,0);
    }
    //Imagen 9, cuad 7
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(9,7,0);
    }
    //Imagen 9, cuad 8
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(9,8,0);
    }
    //Imagen 9, cuad 9
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(9,9,0);
    }
    //Imagen 9, cuad 10
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(9,10,0);
    }
    //Imagen 9, cuad 11
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(9,11,0);
    }
    //Imagen 9, cuad 12
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(9,12,0);
    }
    //Imagen 9, cuad 13
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(9,13,0);
    }
    //Imagen 9, cuad 14
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(9,14,0);
    }
    //Imagen 9, cuad 15
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(9,15,0);
    }


    //Imagen 10, cuad 0
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(10,0,0);
    }
    //Imagen 10, cuad 1
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(10,1,0);
    }
    //Imagen 10, cuad 2
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(10,2,0);
    }
    //Imagen 10, cuad 3
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(10,3,0);
    }
    //Imagen 10, cuad 4
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(10,4,0);
    }
    //Imagen 10, cuad 5
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(10,5,0);
    }
    //Imagen 10, cuad 6
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(10,6,0);
    }
    //Imagen 10, cuad 7
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(10,7,0);
    }
    //Imagen 10, cuad 8
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(10,8,0);
    }
    //Imagen 10, cuad 9
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(10,9,0);
    }
    //Imagen 10, cuad 10
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(10,10,0);
    }
    //Imagen 10, cuad 11
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(10,11,0);
    }
    //Imagen 10, cuad 12
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(10,12,0);
    }
    //Imagen 10, cuad 13
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(10,13,0);
    }
    //Imagen 10, cuad 14
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(10,14,0);
    }
    //Imagen 10, cuad 15
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(10,15,0);
    }



    //Imagen 11, cuad 0
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(11,0,0);
    }
    //Imagen 11, cuad 1
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(11,1,0);
    }
    //Imagen 11, cuad 2
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(11,2,0);
    }
    //Imagen 11, cuad 3
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3325.441906<=lati) && (lati<=3325.465168))
    {
        send(11,3,0);
    }
    //Imagen 11, cuad 4
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(11,4,0);
    }
    //Imagen 11, cuad 5
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(11,5,0);
    }
    //Imagen 11, cuad 6
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(11,6,0);
    }
    //Imagen 11, cuad 7
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3325.465168<=lati) && (lati<=3325.488388))
    {
        send(11,7,0);
    }
    //Imagen 11, cuad 8
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(11,8,0);
    }
    //Imagen 11, cuad 9
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(11,9,0);
    }
    //Imagen 11, cuad 10
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(11,10,0);
    }
    //Imagen 11, cuad 11
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3325.488388<=lati) && (lati<=3325.511638))
    {
        send(11,11,0);
    }
    //Imagen 11, cuad 12
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(11,12,0);
    }
    //Imagen 11, cuad 13
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(11,13,0);
    }
    //Imagen 11, cuad 14
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(11,14,0);
    }
    //Imagen 11, cuad 15
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3325.511638<=lati) && (lati<=3325.534864))
    {
        send(11,15,0);
    }



    //Imagen 12, cuad 0
    else if ((7036.384114>=longi) && (longi>=7036.32184) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(12,0,0);
    }
    //Imagen 12, cuad 1
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(12,1,0);
    }
    //Imagen 12, cuad 2
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(12,2,0);
    }
    //Imagen 12, cuad 3
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(12,3,0);
    }
    //Imagen 12, cuad 4
    else if ((7036.384114>=longi) && (longi>=7036.32184) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(12,4,0);
    }
    //Imagen 12, cuad 5
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(12,5,0);
    }
    //Imagen 12, cuad 6
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(12,6,0);
    }
    //Imagen 12, cuad 7
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(12,7,0);
    }
    //Imagen 12, cuad 8
    else if ((7036.384114>=longi) && (longi>=7036.32184) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(12,8,0);
    }
    //Imagen 12, cuad 9
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(12,9,0);
    }
    //Imagen 12, cuad 10
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(12,10,0);
    }
    //Imagen 12, cuad 11
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(12,11,0);
    }
    //Imagen 12, cuad 12
    else if ((7036.384114>=longi) && (longi>=7036.32184) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(12,12,0);
    }
    //Imagen 12, cuad 13
    else if ((7036.32184>=longi) && (longi>=7036.259554) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(12,13,0);
    }
    //Imagen 12, cuad 14
    else if ((7036.259554>=longi) && (longi>=7036.19728) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(12,14,0);
    }
    //Imagen 12, cuad 15
    else if ((7036.19728>=longi) && (longi>=7036.135) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(12,15,0);
    }


    //Imagen 13, cuad 0
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(13,0,0);
    }
    //Imagen 13, cuad 1
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(13,1,0);
    }
    //Imagen 13, cuad 2
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(13,2,0);
    }
    //Imagen 13, cuad 3
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(13,3,0);
    }
    //Imagen 13, cuad 4
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(13,4,0);
    }
    //Imagen 13, cuad 5
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(13,5,0);
    }
    //Imagen 13, cuad 6
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(13,6,0);
    }
    //Imagen 13, cuad 7
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(13,7,0);
    }
    //Imagen 13, cuad 8
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(13,8,0);
    }
    //Imagen 13, cuad 9
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(13,9,0);
    }
    //Imagen 13, cuad 10
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(13,10,0);
    }
    //Imagen 13, cuad 11
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(13,11,0);
    }
    //Imagen 13, cuad 12
    else if ((7036.135>=longi) && (longi>=7036.072714) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(13,12,0);
    }
    //Imagen 13, cuad 13
    else if ((7036.072714>=longi) && (longi>=7036.01044) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(13,13,0);
    }
    //Imagen 13, cuad 14
    else if ((7036.01044>=longi) && (longi>=7035.54816) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(13,14,0);
    }
    //Imagen 13, cuad 15
    else if ((7035.54816>=longi) && (longi>=7035.485874) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(13,15,0);
    }



    //Imagen 14, cuad 0
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(14,0,0);
    }
    //Imagen 14, cuad 1
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(14,1,0);
    }
    //Imagen 14, cuad 2
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(14,2,0);
    }
    //Imagen 14, cuad 3
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(14,3,0);
    }
    //Imagen 14, cuad 4
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(14,4,0);
    }
    //Imagen 14, cuad 5
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(14,5,0);
    }
    //Imagen 14, cuad 6
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(14,6,0);
    }
    //Imagen 14, cuad 7
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(14,7,0);
    }
    //Imagen 14, cuad 8
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(14,8,0);
    }
    //Imagen 14, cuad 9
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(14,9,0);
    }
    //Imagen 14, cuad 10
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(14,10,0);
    }
    //Imagen 14, cuad 11
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(14,11,0);
    }
    //Imagen 14, cuad 12
    else if ((7035.485874>=longi) && (longi>=7035.4236) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(10,12,0);
    }
    //Imagen 14, cuad 13
    else if ((7035.4236>=longi) && (longi>=7035.361314) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(14,13,0);
    }
    //Imagen 14, cuad 14
    else if ((7035.361314>=longi) && (longi>=7035.299034) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(14,14,0);
    }
    //Imagen 14, cuad 15
    else if ((7035.299034>=longi) && (longi>=7035.23676) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(14,15,0);
    }


    //Imagen 15, cuad 0
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(15,0,0);
    }
    //Imagen 15, cuad 1
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(15,1,0);
    }
    //Imagen 15, cuad 2
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(15,2,0);
    }
    //Imagen 15, cuad 3
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3325.534864<=lati) && (lati<=3325.558114))
    {
        send(15,3,0);
    }
    //Imagen 15, cuad 4
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(15,4,0);
    }
    //Imagen 15, cuad 5
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(15,5,0);
    }
    //Imagen 15, cuad 6
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(15,6,0);
    }
    //Imagen 15, cuad 7
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3325.558114<=lati) && (lati<=3325.581334))
    {
        send(15,7,0);
    }
    //Imagen 15, cuad 8
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(15,8,0);
    }
    //Imagen 15, cuad 9
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(15,9,0);
    }
    //Imagen 15, cuad 10
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(15,10,0);
    }
    //Imagen 15, cuad 11
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3325.581334<=lati) && (lati<=3326.004596))
    {
        send(15,11,0);
    }
    //Imagen 15, cuad 12
    else if ((7035.23676>=longi) && (longi>=7035.174474) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(15,12,0);
    }
    //Imagen 15, cuad 13
    else if ((7035.174474>=longi) && (longi>=7035.112194) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(15,13,0);
    }
    //Imagen 15, cuad 14
    else if ((7035.112194>=longi) && (longi>=7035.04992) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(15,14,0);
    }
    //Imagen 15, cuad 15
    else if ((7035.04992>=longi) && (longi>=7034.587634) && (3326.004596<=lati) && (lati<=3326.02781))
    {
        send(15,15,0);
    }

    //Else
    else {
        send(0,0,1);
    }

}


