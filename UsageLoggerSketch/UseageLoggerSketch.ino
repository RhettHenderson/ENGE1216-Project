/*

@author Rhett Henderson, Tan Tran
@version 04.13.24:1647

Disclaimer: Significant portions of this code were taken from either the 
Adafruit 1306 OLED example code, RandomNerdTutorials.com, and esp32io.com

https://esp32io.com/tutorials/esp32-force-sensor
https://randomnerdtutorials.com/esp32-ssd1306-oled-display-arduino-ide/

*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>

//Dimensions, in pixels
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define FORCE_SENSOR_PIN 35 // ESP32 pin GIOP35 (ADC1): 
//FSR goes from 0-4093, 2000 is our threshold for detecting use
#define THRESHOLD 2000

#define OLED_RESET -1
//The I2C address
#define SCREEN_ADDRESS 0x3C
//Initialize the display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//Two variable for detecting uses, so it's not detected multiple times for one use
int numUses = 0;
bool inUse = false;

void setup() {
  // put your setup code here, to run once:
  //Checks to ensure the display initialized properly
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); //Loop forever
  }
  //Display splash screen, delay, then clear it and set initial properties
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  //Read our FSR input from GPIO35
  int analogReading = analogRead(FORCE_SENSOR_PIN);

  //Toggling the bool is how we avoid multi-detection
  if (analogReading > THRESHOLD && !inUse)
  {
    inUse = true;
    numUses++;
    drawForce();

    //Delay is to prevent multiple detections for the same use
    delay(5000);
  }
  else if ( analogReading < THRESHOLD)
  {
    inUse = false;
  }
}

//Easier to separate the draw logic into a separate method
//Initialize, set properties, then just display the number of uses
void drawForce()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(16, 32);
  display.print(numUses);
  display.print(" uses");
  display.display();
}
