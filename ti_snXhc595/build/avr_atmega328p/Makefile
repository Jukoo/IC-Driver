#SPDX-License-Identifier: GPL-3.0 
#+ This file is for avr atmega328p 
#+ As Know As Arduino Platform 


CC:=avr-gcc 
CFLAGS:= -Wall -Wextra -O0 -mmcu=atmega328  -DF_CPU=16000000UL -H -I inc 

SRC:=$(wildcard  ../../*.c)

elfile:=8bsr.elf 
all: $(elfile) 


$(elfile) : $(SRC)
	@$(CC) $^  -o $@ $(CFLAGS)


.PHONY: hex flash  clean mproper  


hex: $(elfile)  
	@avr-objcopy -O ihex -R -eeprom  $^ $(elfile:.elf=.ihex) 

flash: hex 
	@avrdude -FV -c arduino -P /dev/ttyUSB0 -p atmega328 -b 57600 -U flash:w:$(elfile:.elf=.ihex)  
	

clean : 
	@rm *.elf
	@rm *.ihex 

mproper: clean 
	rm *.elf 
