#ifndef switches_included

#define switches_included

#define S1 BIT0

#define S2 BIT1

#define S3 BIT2

#define S4 BIT3

#define SWITCHES (S1 | S2 | S3 | S4)


extern unsigned int limit;

extern unsigned int secondCount;

void switch_init();

void switch_interrupt_handler();

void wdt_init();


#endif //included
