/*
 * File:   Main.c
 * Author: HO
 *
 */


#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "Configuracion.h"
#include "ADC_lib.h"
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*
Asginacion de variables
*/
signal = [100];
valor = 0;
voltaje = 0;
ADC_Init();
ADC_ON();
ADC_AQ();
ADCON0bits.GO_DONE = 1;
/////////////////////////////////////////////////////////
/*
Asginacion de Funciones
*/
void config(void){
  TRISBbits.RB0 = 1;
}  
//////////////////////////////////////////////////////////

void main(void){
 while(ADCON0bits.GO_DONE == 1){
    valor = ADRES;
    voltaje = (5.0*valor)/1023;
  } 
}


