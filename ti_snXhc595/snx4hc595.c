
#include <avr/io.h> 
#include <util/delay.h>  
#include "snx4hc595.h"

void main (void){ 
   
  DDRD|=IOREGS ; 

  clrall() ; 

  //!binary counter 
  u8_t count = 0 ; 
  while(~0) 
  {
    if(count == 0xf0)
      count=0 ; 
   
    shiftout(++count) ;
    _delay_ms(1000) ; 

    
  }
}
