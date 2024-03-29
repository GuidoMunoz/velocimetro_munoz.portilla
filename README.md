# velocimetro_munoz.portilla
Proyecto de sep 2019-2

Recepcion lista. La recepcion funciona de la siguiente forma:

Se reciben caracteres a través de UART indefinidamente. Esto se hace por interrupciones, lo que quiere decir que
se agregan caracteres a un buffer lineal siempre que estos esten disponibles.

Se define que el envio de datos por parte del GPS fue completado a través de un timer. El timer revisa y muestrea el estado del UART
3 veces, 1 vez por milisegundo (Se estima que se envian datos cada 16 ms). 
Si determina que en esas tres muestras el UART **NO** esta siendo ocupado, entonces se determina que 
la recepción fue completada, levantando un flag que indica que se pueden hacer otras cosas (En este caso mandar los datos
al terminal serial para verlo en el PC).

En el caso ideal los datos se ven así. Notar que la linea $GPGGA contiene info acerca de la ubicación y la hora

![imagen](https://imgur.com/YvvCeB1.png)

A veces los datos pueden venir con "basura" en ellos. Otras veces puede recoger datos totalmente erroneos. Esto implica
una función capaz de manejar estos datos y ser capaz de ocuparlos de la manera mas genérica posible

![imagen](https://imgur.com/IQH3zyu.png)

# Cambios en V2

1. Ya no se recibe por interrupciones. La recepcion es lo suficientemente rapida para evitarlas (Ojala, tal vez esto sea falso y el programa se caera, no estoy seguro)

2. Se ocupa la libreria libgps

3. Se incorpora parsing y display LCD

# Links utiles

https://randomnerdtutorials.com/guide-to-neo-6m-gps-module-with-arduino/ - Recepcion ocupando arduino

https://github.com/wdalmut/libgps - Repositorio libpgs
