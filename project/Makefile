COMMON_OBJECTS	=



CPU		= msp430g2553



CFLAGS		= -mmcu=${CPU} -I../h



LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/







CC		= msp430-elf-gcc



AS		= msp430-elf-as







all: project.elf







project.elf: ${COMMON_OBJECTS} main.o states.o led.o wdt_interupt.o p2_interrupt_handler.o switches.o buzzer.o delay.o  ../lib/libTimer.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lLcd





load: project.elf

	msp430loader.sh project.elf





clean:

	rm -f *.o *.elf *.c~ *.h~
delay.o: delay.s
