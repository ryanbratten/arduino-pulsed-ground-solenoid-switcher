const int inputPin = A0;
const int outputPinA = 3;
const int outputPinB = 4;

unsigned long previousMillis = 0;
const long interval = 1000 / 60;
bool solenoidState = false;

void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(outputPinA, OUTPUT);
  pinMode(outputPinB, OUTPUT);

  digitalWrite(outputPinA, LOW);
  digitalWrite(outputPinB, LOW);
}

void loop() {
  Serial.println("Sensor reading from input pin:");
  Serial.println(inputPin);

  int inputState = digitalRead(inputPin);
  Serial.println("Current input state of:");
  Serial.println(inputState);

  if (inputState == HIGH) {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      solenoidState = !solenoidState;
      Serial.println("Current solenoid state of:");
      Serial.println(solenoidState);

      if (solenoidState) {
        Serial.println("Switching on output pin:");
        Serial.println(outputPinA);
        digitalWrite(outputPinA, HIGH);

        Serial.println("Switching off output pin:");
        Serial.println(outputPinB);
        digitalWrite(outputPinB, LOW);
      } else {
        Serial.println("Switching off output pin:");
        Serial.println(outputPinA);
        digitalWrite(outputPinA, LOW);

        Serial.println("Switching on output pin:");
        Serial.println(outputPinB);
        digitalWrite(outputPinB, HIGH);
      }
    }
  } else {
    Serial.println("Input is off, switching off both output pins");
    digitalWrite(outputPinA, LOW);
    digitalWrite(outputPinB, LOW);
  }
}