 /*
 * Name		: pru1_in
 * Author	: Marc David Jensen Blunsdon
 * Version	: 1.0
 * Copyright	: Free for all
 * Description	: Takes value from input and stores it in the shared memory
 */

#include <stdint.h>
#include <pru_cfg.h>
#include "resource_table_empty.h"

// Register 31 for GPIO input
volatile register uint32_t __R31;

void main (void){
	// variables declared here
	volatile uint32_t wave_in;
	// Use the first place in shared memory
	volatile uint32_t * shared_mem = (unsigned int *) 0x00010000;
	// Pin mask
	wave_in = 0x0800; // P1_04 (pru1) r31.11=> 800	
	// loop
	while(1){
		// Get input and sent to shared data
		shared_mem[0] = __R31 & wave_in;
	}
}

