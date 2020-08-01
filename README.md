# atmega328p-asm-blink

pre-requirements :
gcc-avr - compiler
avr-libc - standard AVR C library
avrdude - burner

sudo apt-get install gcc-avr avr-libc avrdude

Note : No need FTDI driver for linux

installation :

avr-gcc -g -Os -mmcu=atmega328p -c leds.c

avr-gcc -g -mmcu=atmega328p -o leds.elf leds.o

avr-objcopy -j .text -j .data -O ihex leds.elf leds.hex

avrdude -p atmega328p -c arduino -P /dev/ttyUSB0 -U flash:w:leds.hex
