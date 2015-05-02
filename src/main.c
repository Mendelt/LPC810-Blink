/*
First go at programming an LPC810. 

Quick and very dirty blink based on the tutorials at:
http://homepages.rpi.edu/home/43/dongr2/public_html/tutorials/2014/11/27/LPC810-T01.html

*/

typedef unsigned int volatile * vp;

void init(void) {
  *(vp) 0x4000C1C0 = 0xFFFFFFBFUL; /* PINENABLE0 register */
  *(vp) 0xA0002000 |= 1 << 2; /* DIR0, set PIO0_2 to output */
}

int main (void) {
  init();

  for(;;) {
    *(vp) 0xA0002300 |= 1 << 2; /* Toggle the LED */
    
    volatile long wait = 240000; /* Wait */
    while (wait > 0) --wait;
  }
}

