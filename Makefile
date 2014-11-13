CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
AR=arm-none-eabi-ar


CFLAGS=-MD -O0 -ggdb --specs=nosys.specs -mthumb -mcpu=cortex-m4 -I. -I.. -Isdk -Isdk/inc -Isdk/driverlib
LDFLAGS= -T cc3200.ld

LIBM:=${shell ${CC} ${CFLAGS} -print-file-name=libm.a}
LIBC:=${shell ${CC} ${CFLAGS} -print-file-name=libc.a}
LIBGCC:=${shell ${CC} -mthumb ${CFLAGS} -print-libgcc-file-name}
LIBADD=$(LIBM) $(LIBC) $(LIBGCC) sdk/libdriverlib.a 

OBJS =  startup.o main.o gpio_if.o

(%.o): %.c
	$(CC) $(CFLAGS) -c -o $@ $<

main.elf: $(OBJS)
	$(CC) -nostartfiles --entry=ResetISR $(CFLAGS) $(LDFLAGS) -o main.elf $(OBJS) sdk/libdriverlib.a -lm
