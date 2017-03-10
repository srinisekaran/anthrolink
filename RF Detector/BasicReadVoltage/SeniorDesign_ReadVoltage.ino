
/*  Reading voltages and Responding
 *  Anthrolink
 */

#define THRESH 1.2
#define ANPIN A0 // Analog read pin

int ledPin = 13;

void setup() {
  // Initialize serial communication at 9600 bps
  Serial.begin(9600);   
  analogReadAveraging(16);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  
  int sensorData = analogRead(ANPIN);
  delay(3);
  float voltage = sensorData * (5.0 / 1024.0);
  float offsetvoltage = voltage - 1.0;
  Serial.println(offsetvoltage); 
  
  if (offsetvoltage > THRESH) {
    digitalWrite(ledPin, HIGH);
  }

  // Turn off LED if voltage is below threshold
  delay(50);
  digitalWrite(ledPin, LOW);
 
}



