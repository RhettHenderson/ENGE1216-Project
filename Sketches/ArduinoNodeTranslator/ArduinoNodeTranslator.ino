#define INPUT_PIN 35
int force = 0;
int previousForce = 0;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  
  force = analogRead(INPUT_PIN);
  if (force != previousForce)
  {
    Serial.println(force);
    previousForce = force;
  }
  delay(200);
  
}
