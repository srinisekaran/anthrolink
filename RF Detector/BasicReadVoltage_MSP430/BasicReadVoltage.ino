
/*  Reading voltages (***MSP 430G2***)
 *  Anthrolink
 *  
 *  Modified routine to accomodate switch from Teensy LC to
 *  TI Launchpad MSP 430G2
 */

#define THRESH 1.3 // Define threshold (in Volts)
#define ANPIN A3 // Analog read pin

// GREEN_LED or RED_LED
const int ledPin = GREEN_LED; 

void setup() {
  // Initialize serial communication at 9600 bps
  Serial.begin(9600);   
  pinMode(ledPin, OUTPUT);

}

void loop() {
  
  int sensorData = analogRead(ANPIN);
  delay(3);
  float voltage = sensorData * (3.0 / 1023.0);  
  Serial.println(voltage); 
  
  if (voltage > THRESH) {
    digitalWrite(ledPin, HIGH);
  }

  // Turn off LED if voltage is below threshold
  delay(50);
  digitalWrite(ledPin, LOW);
 
}



