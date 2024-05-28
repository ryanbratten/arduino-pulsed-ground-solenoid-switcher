const int inputPin = A0;
const int outputPinA = 0;
const int outputPinB = 1;
const int threshold = 65;

int currentOutputPin = outputPinA;
int currentMode = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(outputPinA, OUTPUT);
  pinMode(outputPinB, OUTPUT);
}

void loop() {
  Serial.println("Sensor reading from input pin:");
  Serial.println(inputPin);

  int sensorReading = digitalRead(inputPin);
  Serial.println("Sensor reading:");
  Serial.println(sensorReading);

  if (sensorReading >= threshold) {
    Serial.println("Sensor reading has reached a threshold of:");
    Serial.println(threshold);
    Serial.println("Switching to output pin:");

    if (currentOutputPin == outputPinA) {
      Serial.println(outputPinB);
      currentOutputPin = outputPinB;
    } else {
      Serial.println(outputPinA);
      currentOutputPin = outputPinA;
    }

    int currentOutputPinValue = digitalRead(currentOutputPin);
    if (currentOutputPinValue == LOW) {
      digitalWrite(currentOutputPin, HIGH);
    } else {
      digitalWrite(currentOutputPin, LOW);
    }

 
  }
  delay(1000);
}