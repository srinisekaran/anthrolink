// External LED on pin 23

int analogPin = 23;
void flash(int num); 

void setup() {
  pinMode(analogPin, OUTPUT);
}

void loop() {
  // Run through brightness spectrum
  for(int j=0; j<=150; j+=1) {
    flash(1, j);
  } 
}

// Drive LED for defined time and brightness
void flash(int waitTime, int ledBrightness) {
  analogWrite(analogPin, ledBrightness);   
  delay(waitTime); 
}

