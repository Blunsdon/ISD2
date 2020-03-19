

#include <stdint.h>
#include <pru_cfg.h>
#include "resource_table_empty.h"

// Register 30 for GPIO output
volatile register uint32_t __R30;

void main (void){
    	// variables declared here
	volatile uint32_t wave_out;
	
	// Use first place in shared memory
	volatile uint32_t * R28 = (unsigned int *) 0x00010000;
    
	//  Pin address given here (P2_24 (pru0) r30.14=> 4000)
	wave_out = 0x4000;
    
	// Clear SYSCFG[STANDBY_INIT] to enable OCP master port
	CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;
    
	// loop
    
	while(1){
		// check if shared memory is 1 or 0
		if(R28[0]){
			// Set pin
			__R30 |= wave_out;
		}else{
			// Clear pin
			__R30 &= ~wave_out;
		}
	}    
}

