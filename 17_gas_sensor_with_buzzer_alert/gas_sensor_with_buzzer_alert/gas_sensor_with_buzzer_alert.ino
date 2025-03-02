int sensorPin=A0;
int sensorData;
void setup()
{  
  Serial.begin(115200);   
  pinMode(sensorPin,INPUT);           
  pinMode(4, OUTPUT);              
 }
void loop()
{
  sensorData = analogRead(sensorPin);       
  Serial.print("Sensor Data:");
  Serial.println(sensorData);
  if(sensorData < 130) 
  digitalWrite(4, HIGH);
  else  
  digitalWrite(4, LOW);

  delay(100);                                   
}