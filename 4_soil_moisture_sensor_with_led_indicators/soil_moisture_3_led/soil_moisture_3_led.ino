
#define GREEN_LED 5    // Green LED connected to digital pin 2
#define YELLOW_LED 6   // Yellow LED connected to digital pin 3
#define RED_LED 7      // Red LED connected to digital pin 4
#define SENSOR_PIN A0  // Soil moisture sensor connected to analog pin A5
// Defining soil moisture readings thresholds
// From 0 to 500 - extremely wet
// From 501 to 800 - wet
// From 801 - dry
#define DRY_THRESHOLD 700
#define WET_THRESHOLD 400

int sensorValue;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  Serial.begin(9600);
}

void loop() {

  sensorValue = analogRead(SENSOR_PIN);
  sensorValue = map(sensorValue, 1023, 300, 0, 1000);

  // Print the sensor reading values
  Serial.print("Soil moisture sensor value: ");
  Serial.println(sensorValue);

  if (sensorValue > 0 && sensorValue <= DRY_THRESHOLD) {
    // Extremely wet (green LED)
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
  } else if (sensorValue > DRY_THRESHOLD && sensorValue <= WET_THRESHOLD) {
    // Wet (yellow LED)
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  } else {
    // Extremely dry (red LED)
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }
}