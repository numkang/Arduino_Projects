int dataIn = 11;
int clockIn = 12;
int clock = 1;
int lastClock = 1;
int out = 0;
int i = 0;
int bin_data[24];
float val = 0;
int aaa = 0;

void setup() {
  pinMode(dataIn, INPUT);     
  pinMode(clockIn, INPUT);  
  Serial.begin(115200);
}


void loop(){

  lastClock = clock;
  clock = digitalRead(clockIn);
  if(i == 24){
    i = 0;
    val = bin_to_dec(bin_data);
    Serial.println(val);
  }

  if (lastClock == 1 && clock == 0){
    // Tripple sampling to remove glitches
    out = digitalRead(dataIn) + digitalRead(dataIn) + digitalRead(dataIn);
    if (out > 1){
      bin_data[i] = 0;
    }
    else{
      bin_data[i] = 1;
    }      
    i++;
  }
}

float bin_to_dec(int bin[]){
  float value = 0;
  for(int k = 15; k >= 0; k--){
    value = value + bin[k]*pow(2,k);
  }
  return value/100.0;
}

