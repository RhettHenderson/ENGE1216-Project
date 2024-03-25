#include <I2CScanner.h>
#include <Wire.h>

//This is the first way of scanning, using a library. Go to Library Manager --> and search for "I2CScanner", by Luis
// If it doesn't work for some reaosn, un-comment the code below for the second method
//The supposedly default address for our OLED display is either 0x3C or 0x3D, but when I run this code I get a bunch of unrecognized ASCII characters, like blocks
I2CScanner scanner;

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    //Loop infinitely
  }
  scanner.Init();
}

void loop()
{
  scanner.Scan();
  delay(5000);
}






//Secondary method
/*
void setup()
{
  Serial.begin(9600);
  Wire.begin();
}
void loop()
{
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
      { Serial.print("0"); }
      Serial.print(address,HEX);
      Serial.println("  !");
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address<16)
      { Serial.print("0"); }
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
  { Serial.println("No I2C devices found\n"); }
  else
  { Serial.println("done\n"); }
  delay(5000);           // wait 5 seconds for next scan
}
*/
//End of secondary method
