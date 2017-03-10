#define THRESH 1.5
#define ANPIN A0 // Analog read pin

int ledPin = 13;

const int numReadings = 20;     // tradeoff between responsiveness and smoothness

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;

void setup() {
  // initialize serial communication with computer:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  total = total - readings[readIndex];
  readings[readIndex] = analogRead(ANPIN);

  total = total + readings[readIndex];
  readIndex = readIndex + 1;

  if (readIndex >= numReadings) {
    readIndex = 0;
  }

  average = total / numReadings;
  float voltage = (average * (5.0 / 1024.0)) - 1.0;
  
  Serial.println(voltage);
  delay(1);        // delay in between reads for stability

  if (voltage > THRESH) {
    digitalWrite(ledPin, HIGH);
  }

  // Turn off LED if voltage is below threshold
  delay(50);
  digitalWrite(ledPin, LOW);
}
