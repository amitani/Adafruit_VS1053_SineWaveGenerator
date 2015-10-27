/*************************************************** 
  This is an example for the Adafruit VS1053 Codec Breakout

  Designed specifically to work with the Adafruit VS1053 Codec Breakout 
  ----> https://www.adafruit.com/products/1381

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

// include SPI, MP3 and SD libraries
#include <SPI.h>
#include <Adafruit_VS1053_SineWaveGenerator.h>
#include <SD.h>

Adafruit_VS1053_SineWaveGenerator sineWaveGenerator = 
  // create shield-example object!
  Adafruit_VS1053_SineWaveGenerator();
  
void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit VS1053 Simple Test");

  if (! sineWaveGenerator.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  }
  Serial.println(F("VS1053 found"));
  
  // Set volume for left, right channels. lower numbers == louder volume!
  sineWaveGenerator.volume[0]=40;
  sineWaveGenerator.volume[1]=40;
  
  sineWaveGenerator.init();
  
  Serial.println(F("track 001"));
  sineWaveGenerator.startSineTest(10);
  delay(1000);
  Serial.println(F("End"));
  sineWaveGenerator.stopSineTest();
  delay(1000);
  
  Serial.println(F("track 002"));
  sineWaveGenerator.startSineTest(5);
  delay(1000);
  //sineWaveGenerator.stopSineTest();
  Serial.println(F("Switch"));
  sineWaveGenerator.stopSineTest();
  sineWaveGenerator.startSineTest(10);
  delay(1000);
  Serial.println(F("End"));
  sineWaveGenerator.stopSineTest();
}

void loop() {
  
}