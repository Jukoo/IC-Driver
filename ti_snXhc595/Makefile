#- Generic Makefile 
#- Author Umar BA <jUmarB@protonmail.com>  @OpenWire Studio

-include  config.mk 

all: $(platform_target)   


$(platform_target):  
	$(info  Building for  $@)
	@$(MAKE) -C $(target_build)    


.PHONY: all clean mproper  hex flash 

hex:  
	@$(MAKE) -C $(target_build)  $@  

flash: hex
	@$(MAKE) -C $(target_build) $@ 

clean: 
	@$(MAKE) -C $(target_build)  $@

mproper: clean 
	@$(MAKE) -C $(target_build)  $@ 

