

#include <avr/io.h> 
#include <util/delay.h> 
#include "../../snx4hc595.h" 




void main (void)
{
  DDRD|=IOREGS ; 
  
  clrall() ; 
  u8_t t = 0 ,i=0 ;

  while(~0) 
  { 
     shiftout((1<<i)) ; 
     if(!t) i++; 

     _delay_ms(50) ; 

     if(i == 8) t^=1 ; 
     if(i == 0) t^=1 ; 

     if(t) i--;  

  }
}
