void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}

int ldr_value;

void loop() 
{
  // put your main code here, to run repeatedly:
  ldr_value = analogRead(A0);
  Serial.println(ldr_value);
  if (ldr_value <=30)
    digitalWrite(7, HIGH);
  else digitalWrite(7, LOW);
  delay(10);
}
