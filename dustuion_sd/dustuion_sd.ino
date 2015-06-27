
#include <SPI.h>
#include <SD.h>
// On the Ethernet Shield, CS is pin 4. Note that even if it's not
// used as the CS pin, the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD library
// functions will not work.
//
// change this to match your SD shield or module;
//     Arduino Ethernet shield: pin 4
//     Adafruit SD shields and modules: pin 10
//     Sparkfun SD shield: pin 8
const int chipSelect = 4;

File logFile;

long actualLogIndex = 0;

void setup() {
  Serial.begin(9600);
   // wait for serial port to connect. Needed for Leonardo only
//    while (!Serial);
    Serial.println("----------- FUN BEGINS -----------");
  // put your setup code here, to run once:
  initSDCard();
}

void loop() {
  // put your main code here, to run repeatedly:

}



