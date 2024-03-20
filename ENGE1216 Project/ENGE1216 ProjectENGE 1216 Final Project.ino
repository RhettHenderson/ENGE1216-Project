/*
 Name:		ENGE_1216_Final_Project.ino
 Created:	3/20/2024 1:11:30 PM
 Author:	rhett
*/
#include <SPI.h>
#include<Wire.h>
#include<Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_HEIGHT, SCREEN_HEIGHT);

#define NUMFLAKES 10

#define LOGO_HEIGHT 16
#define LOGO_WIDTH 16

static const unsigned char PROGMEM logo_bmp[] =
{
  B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000
}

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(115200);

	if (!display.begin(SSD1306_SWITCHAPVCC, 0x3C)) {
		Serial.println(F("SSD1306 allocation failed"));
		for (;;);
	}

	display.display();
	delay(2000);

	display.clearDisplay();

	display.drawPixel(10, 10, WHITE);

	display.display();
	delay(2000);
}
}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
