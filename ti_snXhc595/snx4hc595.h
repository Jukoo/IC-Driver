//!SPDX-License-Identifier: GPL-3.0
 /* 
  * - Generic 8bits shift register driver D-Type
  * - * This is just a Basic Driver -*- 
  */

#if !defined(ti_snXhc595)
#define ti_snXhc595

#include <stdint.h> 

//! POUR TESTER RAPIDEMENT 
#define IOREGS 0x70 
#define SER   (1<<5) 
#define SRCLK (1<<4) 
#define RCLK  (1<<6)

//-------------------------

#define  SNXHC595_MAX_REGISTER (1<<3) 

#define  REG_QA   (1 << 0)
#define  REG_QB   (1 << 1)  
#define  REG_QC   (1 << 2)
#define  REG_QD   (1 << 3)
#define  REG_QE   (1 << 4)
#define  REG_QF   (1 << 5)
#define  REG_QG   (1 << 6)
#define  REG_QH   (1 << 7) 

#define   ENABLE_NOP 1 

#define HINT(memop) __asm__ __volatile__(#memop\
      :::"memory") 


typedef  uint8_t  u8_t; 

typedef struct __in_serial_t { 
  u8_t _data_in; 
  union{
    u8_t _crl_register ; 
  }; 
}; 

typedef union  __out_regclk_t {
  u8_t _register_clk ;
}; 


static inline void  shiftpulse(void){

  PORTD|=SRCLK ;
  PORTD&=~SRCLK; 
}

static inline void  rclkpulse(void)
{
   PORTD|=RCLK; 
   PORTD&=~RCLK; 
}

static  inline void  clrall(void)
{
  u8_t  i = 0 ; 
  PORTD&=~SER ; //__snxhc595_init_serial(); 
   while(i>SNXHC595_MAX_REGISTER); 
   {
     //Pour le test  je vais utiliser  le portd ... 
     
     shiftpulse() ; 
     rclkpulse() ; 

   }
}


#define IS_SET(value)  (value  & 0x1)  
#define BIT_SHL(value,x) ((value) >> x)
#define BIT_SHR(value,x) ((value) << x)  


static inline void  _nop(void) { 
#if ENABLE_NOP
  HINT(nop);
#endif 
}

static  inline void shiftout(u8_t  value) 
{
  
  u8_t bytes=8 ;   

  while(bytes > 0 ){ 
    if(IS_SET(BIT_SHL(value, (bytes-1))) )  
      PORTD|=SER;    
    else 
      PORTD&=~SER;  

    shiftpulse(); 
    _nop(); 
    rclkpulse() ; 
    
    bytes--;  
  } 
  

}



#endif //ti_snXhc595
