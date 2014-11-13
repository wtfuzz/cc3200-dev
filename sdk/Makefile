CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
AR=arm-none-eabi-ar

CFLAGS=-Dgcc -O0 -ggdb -MD -mthumb -mcpu=cortex-m4 -I. -I.. -I./inc -I../inc

OBJS =  driverlib/adc.o \
	driverlib/prcm.o \
	driverlib/utils.o \
	driverlib/aes.o \
	driverlib/camera.o \
	driverlib/cpu.o \
	driverlib/crc.o \
	driverlib/des.o \
	driverlib/flash.o \
	driverlib/gpio.o \
	driverlib/hwspinlock.o \
	driverlib/i2c.o \
	driverlib/i2s.o \
	driverlib/interrupt.o \
	driverlib/pin.o \
	driverlib/sdhost.o \
	driverlib/shamd5.o \
	driverlib/spi.o \
	driverlib/systick.o \
	driverlib/timer.o \
	driverlib/uart.o \
	driverlib/udma.o \
	driverlib/wdt.o

(%.o): %.c
	$(CC) $(CFLAGS) -c -o $@ $<

libdriverlib.a: $(OBJS)
	$(AR) -cr $@ $(OBJS)
