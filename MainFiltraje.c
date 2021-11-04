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

ADC_Init();
ADC_ON();
ADC_AQ();
ADCON0bits.GO_DONE = 1;
