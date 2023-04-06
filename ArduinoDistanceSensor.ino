#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

void setup()
{
  pinMode(2, OUTPUT); // pin D2 is defined as the output of the distance sensor (it sends a digital signal TO Arduino, the time it takes for the sound to return, in microseonds)
  pinMode(4, INPUT);  // pin D4 is defined as the input of the distance sensor (it receives a digital singal FROM Arduino)
  lcd.init();         // initialize the LCD
  lcd.backlight();    // start the LCD backlight
}

void loop()
{
  digitalWrite(2, HIGH);                      // the pulse is sent
  delayMicroseconds(10);                      // it keeps going for 10 microseconds
  digitalWrite(2, LOW);                       // then it is turned off

  long returnTimeMS = pulseIn(4, HIGH);       //input pulse and save it veriable
  long distanceCM = returnTimeMS * 0.01715 ;


  lcd.clear();                         // the text which was previously displayed is deleted     
  lcd.setCursor(0, 0);                 // we set our cursor at the beginning of the first row
  lcd.print(returnTimeMS/ 1000000.0);  // the time gets converted to seconds (as a floating-point value)
  lcd.print(" seconds");               
  lcd.setCursor(0, 1);                 // we set our cursor at the beginning of the second row
  lcd.print(distanceCM);               // we display our distance in centimeters
  lcd.print(" cm away");
  
  delay(1000);                         // wait for one second
}
