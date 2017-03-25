
#include "Particle.h"
#include "TCA9548A-RK.h"


TCA9548A::TCA9548A(TwoWire &wire, int addr) :
	wire(wire), addr(addr) {
}

TCA9548A::~TCA9548A() {
}

void TCA9548A::begin() {
	wire.begin();
}

void TCA9548A::setChannel(uint8_t channel) {
	writeControl(1 << channel);
}

void TCA9548A::setNoChannel() {
	writeControl(0);
}

bool TCA9548A::writeControl(uint8_t value) {
	wire.beginTransmission(addr | DEVICE_ADDR);
	wire.write(value);

	int stat = wire.endTransmission(true);

	// Serial.printlnf("writeControl addr=0x%x value=0x%x stat=%d", addr | DEVICE_ADDR, value, stat);

	return (stat == 0);
}
