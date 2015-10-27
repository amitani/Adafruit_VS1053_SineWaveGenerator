#ifndef ADAFRUIT_VS1053_SWG
#define ADAFRUIT_VS1053_SWG

#include "Adafruit_VS1053.h"

class Adafruit_VS1053_SineWaveGenerator : public Adafruit_VS1053 {
public:
	Adafruit_VS1053_SineWaveGenerator(int8_t mosi, int8_t miso, int8_t clk,
		int8_t rst, int8_t cs, int8_t dcs, int8_t dreq);
	Adafruit_VS1053_SineWaveGenerator(int8_t rst, int8_t cs, int8_t dcs, int8_t dreq);
	void init();
	void startSineTest(uint8_t n);
	void stopSineTest(void);
	uint8_t volume[2] = {40, 40};
private:

};

#endif //ADAFRUIT_VS1053_SWG