#ifndef __TCA9548A_RK_H
#define __TCA9548A_RK_H


class TCA9548A {
public:
	/**
	 * You typically create one of these objects on the stack.
	 *
	 * The first argument is typically Wire (pins D0 and D1). On the Electron it can also be Wire1 (pins C4 and C5)
	 *
	 * The addr argument is the address 0-7 based on the setting of A0, A1 and A2.
	 */
	TCA9548A(TwoWire &wire, int addr = 0);
	virtual ~TCA9548A();

	/**
	 * Typically called during setup() to start the Wire interface.
	 */
	void begin();

	/**
	 * Sets the I2C channel 0-7 to use
	 */
	void setChannel(uint8_t channel);

	/**
	 * Deselect all channels, so none is selected
	 */
	void setNoChannel();


	bool writeControl(uint8_t value);

	static const uint8_t DEVICE_ADDR = 0x70; // 1110 in the fixed bits + 3 adjustable bits

protected:
	TwoWire &wire;
	int addr; // This is just 0-7, the (0x70 of the 7-bit address is ORed in later)

};

#endif /* __TCA9548A_RK_H */
