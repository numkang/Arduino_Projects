//Control the LED with a Photo Resistor 

int photoPin = 0;
int ledPin = 9;
int lightLevel, high = 0, low = 1023;

  
void setup()
{
  Serial.println(57600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  lightLevel = analogRead(photoPin);
  brightness();
  analogWrite(ledPin, lightLevel);
}

void brightness()
{  
  if (lightLevel < low)
  {
    low = lightLevel;
  }
  
  if (lightLevel > high)
  {
    high = lightLevel;
  }
  
  lightLevel = map(lightLevel, low+30, high-30, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
}
