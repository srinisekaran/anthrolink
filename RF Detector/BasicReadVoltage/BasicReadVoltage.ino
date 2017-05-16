  
/*  Reading voltages (*** MSP 430G2 ***)
 *  Anthrolink
 *  Srinivaas Sekaran
 *  
 *  Modified routine to accommodate transition from Teensy LC to
 *  TI Launchpad MSP 430G2
 */

#define VOLTAGE_MAX 1.85
#define VOLTAGE_MIN 1.70
#define ANPIN A7 // Analog read pin


void voltage_check(float);

void setup() {
  
  // Initialize serial communication at 9600 bps
  Serial.begin(9600);  
  pinMode(GREEN_LED, OUTPUT);

}

void loop() {

  int total = 0;
  for (int i = 0; i <= 30; i++) {
     int sensorData = analogRead(ANPIN);
     delay(3);
     total = (total + sensorData);
  }
  
  
  float voltage = ((total / 30) * (3.0 / 1023.0) + 0.23);  
  Serial.println(voltage); 

  voltage_check(voltage);

}

void voltage_check(float voltage_in) {

  // Turn on LED for 50 ms if voltage is within a defined range
  if ((voltage_in > VOLTAGE_MIN) && (voltage_in < VOLTAGE_MAX )) {
      digitalWrite(GREEN_LED, HIGH);
  }

  delay(50);
  
  // Turn off LED if voltage is below threshold
  digitalWrite(GREEN_LED, LOW);

  
}



