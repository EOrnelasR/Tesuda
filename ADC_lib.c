/*
 * File:   ADC_lib.c
 * Author: HO
 *
 */
#include <stdint.h>
#include <xc.h>
#include "Configuracion.h"
#include <stdio.h>
//1.- Configure the A/D module:
//      *Configure analog pins, voltge reference and digital I/O (ADCON1)
//      *Select A/D input channel (ADCON0)
//      *Select A/D acquisition time (ADCON2)
//      *Select A/D conversion clock (ADCON2)
//      *Tur on A/D module (ADCON 0)
//      *Turn on A/D module (ADCON0).
//2.- COnfigure A/D interrupt (if desired).
//      *Clear ADIF bit
//      *Set ADIE bit
//      *Set GIE bit
//3.- Wait the requiered acquisition time (if required).
//4.- Start Conversion: 
//      *Set GO/DONE bit (ADCON0 register)
//5.- Wait for A/D conversion to complete, by either:
//      *Polling for the GO/DONE bit cleared
//OR
//      *Waiting for the A/D interrupt
//6.- Read A/D result registers (ADRESH:ADRESL)
//7.- For next conversion, go to step 1 or step 2, as required. The A/D converison time
// per bit is defined as TAD. A minimum wait of 3 TAD is required for acquisition starts.

void ADC_ON(void){
    ADCON0bits.ADON = 1;
}

void ADC_AQ(void){
    __delay_us(2.5);
}

void ADC_Init(void){
//1.- Configure the A/D module:
//      *Configure analog pins, voltge reference and digital I/O (ADCON1)
    TRISA = 1; //Puertos como Inputs
    ADCON1bits.VCFG = 0; // VSS = 0V
    ADCON1bits.VCFG0 = 0; // VDD = 5V
    ADCON1bits.PCFG0 = 0;  //entrada analógica en AN0 
    ADCON1bits.PCFG1 = 1;
    ADCON1bits.PCFG2 = 1;
    ADCON1bits.PCFG3 = 1;
//      *Select A/D input channel (ADCON0)
    ADCON0bits.CHS = 0;
//      *Select A/D acquisition time (ADCON2)
    //Maximum Fosc = 20Mhz -> 16 TOSC = 101
    ADCON2bits.ACQT = 3;
//      *Select A/D conversion clock (ADCON2)
    ADCON2bits.ADCS = 5;
    ADCON2bits.ADFM = 1; //left justified 
    //      *Turn on A/D module (ADCON0).
//2.- COnfigure A/D interrupt (if desired).
//      *Clear ADIF bit
    PIR1bits.ADIF = 0;  //A/D Converter Interrupt Flag Bit
//      *Set ADIE bit
    PIE1bits.ADIE = 1;  //A/D Converter Interrupt Enable Bit.
//      *Set GIE bit
    INTCONbits.GIE = 1;
//3.- Wait the requiered acquisition time (if required).
    
//4.- Start Conversion: 
//      *Set GO/DONE bit (ADCON0 register)
//5.- Wait for A/D conversion to complete, by either:
//      *Polling for the GO/DONE bit cleared
//OR
//      *Waiting for the A/D interrupt
//6.- Read A/D result registers (ADRESH:ADRESL)
//7.- For next conversion, go to step 1 or step 2, as required. The A/D converison time
// per bit is defined as TAD. A minimum wait of 3 TAD is required for acquisition starts.
}
