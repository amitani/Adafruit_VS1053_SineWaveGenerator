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
#ifndef ADAFRUIT_VS1053_FP_H
#define ADAFRUIT_VS1053_FP_H
#include <Adafruit_VS1053.h>
#include <SD.h>

#define VS1053_FILEPLAYER_TIMER0_INT 255 // allows useInterrupt to accept pins 0 to 254
#define VS1053_FILEPLAYER_PIN_INT 5


class Adafruit_VS1053_FilePlayer : public Adafruit_VS1053 {
 public:
  Adafruit_VS1053_FilePlayer (int8_t mosi, int8_t miso, int8_t clk, 
			      int8_t rst, int8_t cs, int8_t dcs, int8_t dreq,
			      int8_t cardCS);
  Adafruit_VS1053_FilePlayer (int8_t rst, int8_t cs, int8_t dcs, int8_t dreq,
			      int8_t cardCS);
  Adafruit_VS1053_FilePlayer (int8_t cs, int8_t dcs, int8_t dreq,
			      int8_t cardCS);

  boolean begin(void);
  boolean useInterrupt(uint8_t type);
  File currentTrack;
  volatile boolean playingMusic;
  void feedBuffer(void);
  boolean startPlayingFile(const char *trackname);
  boolean playFullFile(const char *trackname);
  void stopPlaying(void);
  boolean paused(void);
  boolean stopped(void);
  void pausePlaying(boolean pause);

 private:
  uint8_t _cardCS;
};

#endif // ADAFRUIT_VS1053_H
