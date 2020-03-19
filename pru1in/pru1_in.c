

#include <stdint.h>
#include <pru_cfg.h>
#include "resource_table_empty.h"

// Register 31 for GPIO input
volatile register uint32_t __R31;

void main (void){
	// variables declared here
	volatile uint32_t wave_in;
	// Use the first place in shared memory (register 28)
	volatile uint32_t * R28 = (unsigned int *) 0x00010000;
	// addresses given here
	wave_in = 0x0800; // P1_04 (pru1) r31.11=> 800
	// Clear SYSCFG[STANDBY_INIT] to enable OCP master port
	CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;	
	// loop
	while(1){
		// Get input and sent to shared data
		R28[0] = __R31 & wave_in;
	}
}

