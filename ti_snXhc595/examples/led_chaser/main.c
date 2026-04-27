
#include <avr/io.h> 
#include <util/delay.h>  
#include "../../snx4hc595.h"


void main (void){ 
   
  DDRD|=IOREGS ; 

  clrall() ; 
  u8_t current_led = 0 ;  
  
  while(~0) 
  {  
    if(current_led == 8) 
      current_led=0 ; 

     shiftout((1 <<  current_led)) ;
     _delay_ms(100) ; 
     current_led++;        

  }
}


