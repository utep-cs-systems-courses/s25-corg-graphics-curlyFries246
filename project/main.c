#include <msp430.h>
#include "libTimer.h"

#include "led.h"

#include "switches.h"

#include "buzzer.h"
#include "lcdutils.h"

#include "lcddraw.h"
void main(void)

{


  buzzer_init();
  wdt_init();
  switch_init();
  led_init();
  lcd_init();
  configureClocks();
  enableWDTInterrupts();
  
  or_sr(0x18);  // CPU off, GIE
} 
