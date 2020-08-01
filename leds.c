#define F_CPU 1000000UL

#include <avr/io.h>


int main (void)
{
    DDRB |= _BV(DDB0); 

   asm  (
     "jmp start \n"

     "wait: \n"                 // 1 sec wait
    "    ldi  r18, 41	\n"
    "    ldi  r19, 150	\n"
    "    ldi  r20, 128	\n"
    "1:  dec  r20	\n"
    "    brne 1b	\n"
    "    dec  r19	\n"
    "    brne 1b	\n"
    "    dec  r18	\n"
    "    brne 1b	\n"
    "    ret \n"
     
     "start: \n"
     "ldi r21, 0b00000001 \n" 
   );
    
    while(1)  {
       asm  (
     "in r22, 0x3 \n"          
     "eor r22, r21 \n"         
     "out 0x5, r22 \n"         
     "call wait \n"
   );
    }
}

