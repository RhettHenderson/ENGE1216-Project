/*
   This ESP32 code is created by esp32io.com
   This ESP32 code is released in the public domain
   For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-force-sensor
*/

#define FORCE_SENSOR_PIN 35 // ESP32 pin GIOP35 (ADC1): 
#define LIGHT_THRESHOLD 1000
#define MEDIUM_THRESHOLD 2000
#define HEAVY_THRESHOLD 3000


void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogReading = analogRead(FORCE_SENSOR_PIN);

  Serial.print("The force sensor value = ");
  Serial.print(analogReading); // print the raw analog reading

  if (analogReading < LIGHT_THRESHOLD)       // from 0 to 9
    Serial.println(" -> no pressure");
  else if (analogReading < MEDIUM_THRESHOLD) // from 10 to 199
    Serial.println(" -> light squeeze");
  else if (analogReading < HEAVY_THRESHOLD) // from 500 to 799
    Serial.println(" -> medium squeeze");
  else // from 800 to 1023
    Serial.println(" -> big squeeze");

  delay(1000);
}