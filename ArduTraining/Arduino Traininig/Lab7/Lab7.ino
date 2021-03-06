//Control the LED with a Flex Sensor

 int flexpin = 0;
int ledPin = 9;
int lightLevel, high = 0, low = 1023;

void setup(){
  Serial.begin(57600);
}

void loop(){
  int lightLevel = analogRead(flexpin);
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
