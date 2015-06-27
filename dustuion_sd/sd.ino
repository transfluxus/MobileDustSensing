
const char indexFileName[] = "index.txt";

void initSDCard() {

  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(SS, OUTPUT);

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");

  Serial.println("Getting Index...");
  // read the index to use
  File indexFile = SD.open(indexFileName);
  if (indexFile) {
    // read from the file until there's nothing else in it:
    // read the number (into a string...)
    String num = "";
    while (indexFile.available()) {
      char c = indexFile.read();
      num += c;
    }
    //Serial.println(num);
    char charAr[num.length()];
    for (int i = 0; i < num.length(); i++)
      charAr[i] = num.charAt(i);
    actualLogIndex = atol(charAr);
    Serial.print("Index: ");
    Serial.println(actualLogIndex);
    // close the file:
    indexFile.close();
  } else {
    Serial.print("error opening ");
    Serial.println(indexFileName);
  }
  
  // change index number and make it a string
  Serial.println("Updating Index...");
  long index = actualLogIndex + 1;
  String writeIndex = String(index);

  // delete the file
  SD.remove("index.txt");
  // write the new number
  indexFile = SD.open("index.txt", FILE_WRITE);
  if (indexFile) {
    indexFile.println(writeIndex);
    indexFile.close();
  } else {
    Serial.print("error writing ");
    Serial.println(indexFileName);
  }
  
  Serial.println("Indexing done");
}

void initLogging() {

  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(SS, OUTPUT);

  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  //  myFile = SD.open("test.txt", FILE_WRITE);

}
