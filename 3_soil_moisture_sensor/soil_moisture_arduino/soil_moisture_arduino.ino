
int sensorValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(A0);
  Serial.println(1023-sensorValue);
  delay(100);
}
