/***************************************************
This is a library for the Adafruit VS1053 Codec Breakout

Designed specifically to work with the Adafruit VS1053 Codec Breakout
----> https://www.adafruit.com/products/1381

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries.
BSD license, all text above must be included in any redistribution
****************************************************/


#include <Adafruit_VS1053_SineWaveGenerator.h>

Adafruit_VS1053_SineWaveGenerator::Adafruit_VS1053_SineWaveGenerator(
	int8_t rst, int8_t cs, int8_t dcs, int8_t dreq)
	: Adafruit_VS1053(rst, cs, dcs, dreq) {

}

Adafruit_VS1053_SineWaveGenerator::Adafruit_VS1053_SineWaveGenerator(
	int8_t mosi, int8_t miso, int8_t clk,
	int8_t rst, int8_t cs, int8_t dcs, int8_t dreq)
	: Adafruit_VS1053(mosi, miso, clk, rst, cs, dcs, dreq) {

}

void Adafruit_VS1053_SineWaveGenerator::init(){

	reset();
	setVolume(volume[0], volume[1]);
	uint16_t mode = sciRead(VS1053_REG_MODE);
	mode |= 0x0020;
	sciWrite(VS1053_REG_MODE, mode);
}



void Adafruit_VS1053_SineWaveGenerator::startSineTest(uint8_t n) {
	while (!digitalRead(_dreq));
	//  delay(10);

#ifdef SPI_HAS_TRANSACTION
	if (useHardwareSPI) SPI.beginTransaction(VS1053_DATA_SPI_SETTING);
#endif
	digitalWrite(_dcs, LOW);
	spiwrite(0x53);
	spiwrite(0xEF);
	spiwrite(0x6E);
	spiwrite(n);
	spiwrite(0x00);
	spiwrite(0x00);
	spiwrite(0x00);
	spiwrite(0x00);
	digitalWrite(_dcs, HIGH);
#ifdef SPI_HAS_TRANSACTION
	if (useHardwareSPI) SPI.endTransaction();
#endif

}



void Adafruit_VS1053_SineWaveGenerator::stopSineTest() {
#ifdef SPI_HAS_TRANSACTION
	if (useHardwareSPI) SPI.beginTransaction(VS1053_DATA_SPI_SETTING);
#endif
	digitalWrite(_dcs, LOW);
	spiwrite(0x45);
	spiwrite(0x78);
	spiwrite(0x69);
	spiwrite(0x74);
	spiwrite(0x00);
	spiwrite(0x00);
	spiwrite(0x00);
	spiwrite(0x00);
	digitalWrite(_dcs, HIGH);
#ifdef SPI_HAS_TRANSACTION
	if (useHardwareSPI) SPI.endTransaction();
#endif
	init();
}
