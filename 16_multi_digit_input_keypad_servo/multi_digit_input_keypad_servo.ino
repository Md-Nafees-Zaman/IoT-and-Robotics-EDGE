#include <Keypad.h>
#include <Servo.h> // Include the Servo library

// Keypad setup
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; // Connect to the column pinouts of the keypad

// Create an object for the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Servo setup
Servo myServo; // Create a servo object

String inputString = "";  // Store the input digits as a string
int repeatCount = 0;      // Store the number of movements to make

void setup() {
  myServo.attach(10); // Attach the servo to pin 10
  Serial.begin(9600); // Start serial communication
  Serial.println("Enter a number, then press # to confirm.");
}

void loop() {
  char key = keypad.getKey(); // Read the key from the keypad

  if (key) { // If a key is pressed
    Serial.print("Key Pressed: ");
    Serial.println(key);

    // If the key is numeric, add it to the input string
    if (key >= '0' && key <= '9') {
      inputString += key;  // Add the key to the input string
      Serial.print("Current Input: ");
      Serial.println(inputString);
    }
    
    // If '#' is pressed, process the input and start the movement
    else if (key == '#') {
      if (inputString.length() > 0) {
        repeatCount = inputString.toInt(); // Convert input string to an integer
        Serial.print("Movement count set to: ");
        Serial.println(repeatCount);
        inputString = ""; // Clear the input string after processing
        moveServo(repeatCount); // Call function to move the servo
      }
    }
  }
}

// Function to move the servo
void moveServo(int count) {
  for (int i = 0; i < count; i++) {
    Serial.print("Movement #");
    Serial.println(i + 1);

    // Move the servo to 0°
    myServo.write(0);
    delay(500); // Wait for 500ms

    // Move the servo to 90°
    myServo.write(90);
    delay(500); // Wait for 500ms

    // Move the servo to 180°
    myServo.write(180);
    delay(500); // Wait for 500ms
  }
  Serial.println("Movement completed.");
}