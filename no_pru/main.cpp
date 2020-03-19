 /*
 * Name		: main
 * Author	: Marc David Jensen Blunsdon
 * Version	: 1.0
 * Copyright	: Free for all
 * Description	: Takes value from input pin and sends the value til output pin
 */


#include<iostream>

#include"GPIO.h"

using namespace std;

using namespace exploringBB;

int main(void){
	// use pin p2.19(27) as input and pin p2.17(65) as output 
	GPIO outGPIO(65), inGPIO(27);

	// Setup pins for output and input
	outGPIO.setDirection(OUTPUT);
	inGPIO.setDirection(INPUT);

	while(1){
		if(inGPIO.getValue()){
			outGPIO.setValue(HIGH);
		} else{
			outGPIO.setValue(LOW);
		}
	}
	return 0;
}
