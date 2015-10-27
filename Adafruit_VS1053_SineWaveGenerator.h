#ifndef ADAFRUIT_VS1053_SWG
#define ADAFRUIT_VS1053_SWG

#include "Adafruit_VS1053.h"

#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)

// These are common pins between breakout and shield
#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin

class Adafruit_VS1053_SineWaveGenerator : public Adafruit_VS1053 {
public:
	Adafruit_VS1053_SineWaveGenerator(int8_t mosi, int8_t miso, int8_t clk,
		int8_t rst, int8_t cs, int8_t dcs, int8_t dreq);
	Adafruit_VS1053_SineWaveGenerator(int8_t rst = SHIELD_RESET, int8_t cs = SHIELD_CS, int8_t dcs = SHIELD_DCS, int8_t dreq = DREQ);
	void init();
	void startSineTest(uint8_t n);
	void stopSineTest(void);
	uint8_t volume[2] = {40, 40};
private:

};

#endif //ADAFRUIT_VS1053_SWG