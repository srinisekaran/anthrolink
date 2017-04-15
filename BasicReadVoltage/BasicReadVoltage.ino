
/*  Reading voltages (*** MSP 430G2 ***)
 *  Anthrolink
 *  Srinivaas Sekaran
 *  
 *  Modified routine to accomodate transition from Teensy LC to
 *  TI Launchpad MSP 430G2
 */

#define VOLTAGE_MAX 1.5
#define VOLTAGE_MIN 1.3
#define ANPIN A7 // Analog read pin

// GREEN_LED or RED_LED
const int ledPin = GREEN_LED; 
void voltage_check(float);

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

  voltage_check(voltage);

}

void voltage_check(float voltage_in) {

  // Turn on LED for 50 ms if voltage is within a defined range
  if ((voltage_in > VOLTAGE_MIN) && (voltage_in < VOLTAGE_MAX )) {
      digitalWrite(ledPin, HIGH);
  }

  delay(50);
  
  // Turn off LED if voltage is below threshold
  digitalWrite(ledPin, LOW);
  
}



