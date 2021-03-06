//Control the RGB LED with a Soft Potentiometer 

int RED_LED_PIN = 9;    // Red LED Pin
int GREEN_LED_PIN = 10; // Green LED Pin
int BLUE_LED_PIN = 11;  // Blue LED Pin

int softPotentiometerPIN = 0; 

int redValue, greenValue, blueValue;

void setup()
{
  Serial.begin(57600);
}

void loop()
{
  int softPotentiometerValue;
  
  softPotentiometerValue = analogRead(softPotentiometerPIN);
 
  setRGB(softPotentiometerValue);
}

void setRGB(int RGBposition)
{  
  redValue = constrain(map(RGBposition, 0, 341, 255, 0), 0, 255)
             + constrain(map(RGBposition, 682, 1023, 0,255), 0, 255);
  
  greenValue = constrain(map(RGBposition, 0, 341, 0, 255), 0, 255)
             - constrain(map(RGBposition, 341, 682, 0,255), 0, 255);
              
  blueValue = constrain(map(RGBposition, 341, 682, 0, 255), 0, 255)
            - constrain(map(RGBposition, 682, 1023, 0, 255), 0, 255);

  analogWrite(RED_LED_PIN, redValue);
  analogWrite(GREEN_LED_PIN, greenValue);
  analogWrite(BLUE_LED_PIN, blueValue);
}
