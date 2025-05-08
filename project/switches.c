#include <msp430.h>

#include "switches.h"

#include "libTimer.h"

#include "led.h"

#include "states.h"



unsigned int secondCount;
unsigned int limit;

void

switch_init()

{

  P2REN |= SWITCHES;

  P2IE |= SWITCHES;

  P2OUT |= SWITCHES;

  P2DIR &= ~SWITCHES;

}


void switch_interrupt_handler()
{

  char p2val = P2IN;

  char sw_1 = (p2val & S1) ? 0 : S1;

  char sw_2 = (p2val & S2) ? 0 : S2;

  char sw_3 = (p2val & S3) ? 0 : S3;

  char sw_4 = (p2val & S4) ? 0 : S4;

  if(sw_1){

    states(1);
    
  }

  else if(sw_2){

    states(2);
    
  }

  else if(sw_3){

    states(3);
    
  }

  else if(sw_4){

    states(4);
    
  }

}

void wdt_init(){

  configureClocks();

  enableWDTInterrupts();
}
