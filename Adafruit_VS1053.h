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
#ifndef ADAFRUIT_VS1053_H
#define ADAFRUIT_VS1053_H

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

#include "pins_arduino.h"
#include "wiring_private.h"
#include <SPI.h> 

#ifdef __SAM3X8E__
typedef volatile RwReg PortReg;
typedef uint32_t PortMask;
#else
typedef volatile uint8_t PortReg;
typedef uint8_t PortMask;
#endif

#define VS1053_SCI_READ 0x03
#define VS1053_SCI_WRITE 0x02

#define VS1053_REG_MODE  0x00
#define VS1053_REG_STATUS 0x01
#define VS1053_REG_BASS 0x02
#define VS1053_REG_CLOCKF 0x03
#define VS1053_REG_DECODETIME 0x04
#define VS1053_REG_AUDATA 0x05
#define VS1053_REG_WRAM 0x06
#define VS1053_REG_WRAMADDR 0x07
#define VS1053_REG_HDAT0 0x08
#define VS1053_REG_HDAT1 0x09
#define VS1053_REG_VOLUME 0x0B

#define VS1053_GPIO_DDR 0xC017
#define VS1053_GPIO_IDATA 0xC018
#define VS1053_GPIO_ODATA 0xC019

#define VS1053_INT_ENABLE  0xC01A

#define VS1053_MODE_SM_DIFF 0x0001
#define VS1053_MODE_SM_LAYER12 0x0002
#define VS1053_MODE_SM_RESET 0x0004
#define VS1053_MODE_SM_CANCEL 0x0008
#define VS1053_MODE_SM_EARSPKLO 0x0010
#define VS1053_MODE_SM_TESTS 0x0020
#define VS1053_MODE_SM_STREAM 0x0040
#define VS1053_MODE_SM_SDINEW 0x0800
#define VS1053_MODE_SM_ADPCM 0x1000
#define VS1053_MODE_SM_LINE1 0x4000
#define VS1053_MODE_SM_CLKRANGE 0x8000


#define VS1053_SCI_AIADDR 0x0A
#define VS1053_SCI_AICTRL0 0x0C
#define VS1053_SCI_AICTRL1 0x0D
#define VS1053_SCI_AICTRL2 0x0E
#define VS1053_SCI_AICTRL3 0x0F

#define VS1053_DATABUFFERLEN 32


#define VS1053_CONTROL_SPI_SETTING  SPISettings(250000,  MSBFIRST, SPI_MODE0)
#define VS1053_DATA_SPI_SETTING     SPISettings(8000000, MSBFIRST, SPI_MODE0)

#ifndef _BV
#define _BV(x) (1<<(x))
#endif

// These are the pins used for the breakout example
#define BREAKOUT_RESET  9      // VS1053 reset pin (output)
#define BREAKOUT_CS     10     // VS1053 chip select pin (output)
#define BREAKOUT_DCS    8      // VS1053 Data/command select pin (output)
// These are the pins used for the music maker shield
#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)

// These are common pins between breakout and shield
#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin


class Adafruit_VS1053 {
 public:
  Adafruit_VS1053(int8_t mosi, int8_t miso, int8_t clk, 
		  int8_t rst, int8_t cs, int8_t dcs, int8_t dreq);
  Adafruit_VS1053(int8_t rst, int8_t cs, int8_t dcs, int8_t dreq);
  uint8_t begin(void);
  void reset(void);
  void softReset(void);
  uint16_t sciRead(uint8_t addr);
  void sciWrite(uint8_t addr, uint16_t data);
  void sineTest(uint8_t n, uint16_t ms);
  void spiwrite(uint8_t d);
  uint8_t spiread(void);

  uint16_t decodeTime(void);
  void setVolume(uint8_t left, uint8_t right);
  void dumpRegs(void);

  void playData(uint8_t *buffer, uint8_t buffsiz);
  boolean readyForData(void);
  void applyPatch(const uint16_t *patch, uint16_t patchsize);
  uint16_t loadPlugin(char *fn);

  void GPIO_digitalWrite(uint8_t i, uint8_t val);
  void GPIO_digitalWrite(uint8_t i);
  uint16_t GPIO_digitalRead(void);
  boolean GPIO_digitalRead(uint8_t i);
  void GPIO_pinMode(uint8_t i, uint8_t dir);
 
  boolean prepareRecordOgg(char *plugin);
  void startRecordOgg(boolean mic);
  void stopRecordOgg(void);
  uint16_t recordedWordsWaiting(void);
  uint16_t recordedReadWord(void);

  uint8_t mp3buffer[VS1053_DATABUFFERLEN];

 protected:
  uint8_t  _dreq;
 //private:
  int8_t _mosi, _miso, _clk, _reset, _cs, _dcs;
  boolean useHardwareSPI;
};

#endif // ADAFRUIT_VS1053_H
