#include "Particle.h"
#include "TCA9548A-RK.h"


TCA9548A mux(Wire, 0);


void setup() {
	Serial.begin(9600);
	mux.begin();
	mux.setChannel(0);
}

void loop() {
}

