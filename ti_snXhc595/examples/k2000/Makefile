
CC=avr-gcc 
CFLAGS = -Wall -Wextra -O0 -mmcu=atmega328  -DF_CPU=16000000UL -H -I inc 
SRC:=$(wildcard *.c)

elfile:=k2k.elf 

all: $(elfile) 


$(elfile) : $(SRC)
	@$(CC) $^  -o $@ $(CFLAGS)


.PHONY: hex flash  clean mproper  


hex: $(elfile)  
	@avr-objcopy -O ihex -R -eeprom  $^ $(elfile:.elf=.ihex) 

flash: hex 
	@avrdude -FV -c arduino -P /dev/ttyUSB0 -p atmega328 -b 57600 -U flash:w:$(elfile:.elf=.ihex)  
	

clean : 
	@rm *.ihex 

mproper: clean 
	rm *.elf 
