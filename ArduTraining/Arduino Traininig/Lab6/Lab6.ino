//Checking Temperature with Thermistor 

int thermistorPin = 0;
float voltage, degreesC, degreesF;

void setup(){
  Serial.begin(57600);
}

void loop(){
  int thermistorReading = analogRead(thermistorPin); 
  //voltage = thermistorReading * 0.004882814;
  
  voltage = log(((10240000/thermistorReading) - 10000));
  voltage = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * voltage * voltage ))* voltage );
  
  degreesC = voltage - 273.15;
  
  //degreesC = (voltage - 0.5) * 100.0;
  degreesF = degreesC * (9.0/5.0) + 32.0;
  
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print(",  deg F: ");
  Serial.println(degreesF);
  
  delay(250); //just here to slow down the output for easier reading
}
