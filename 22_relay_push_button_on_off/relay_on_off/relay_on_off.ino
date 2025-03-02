// Define the GPIO pin connected to the relay module
const int relayPin = 2; // Change this to the actual GPIO pin you're using

// Define the GPIO pin connected to the switch
const int switchPin = 3; // Change this to the actual GPIO pin you're using

// Variable to store the state of the LED (controlled by the relay)
int ledState = LOW; // Initially off

// Variable to store the current reading of the switch
int currentSwitchState;

void setup() {
  // Initialize the relay pin as an output
  pinMode(relayPin, OUTPUT);

  // Initialize the switch pin as an input with internal pull-up resistor
  pinMode(switchPin, INPUT_PULLUP);  // Important: Use INPUT_PULLUP

  // Start serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Read the current state of the switch
  currentSwitchState = digitalRead(switchPin);

  // Check if the switch is pressed (LOW because of INPUT_PULLUP)
  if (currentSwitchState == LOW) {
    // Debounce: Wait a short time to avoid multiple toggles from a single press
    delay(50); // Adjust delay as needed

    // Re-read the switch state after the delay (debouncing)
    currentSwitchState = digitalRead(switchPin);

    // Only toggle if the switch is still pressed after the debounce
    if (currentSwitchState == LOW) {
      // Toggle the LED state
      ledState = !ledState;

      // Control the relay based on the LED state
      digitalWrite(relayPin, ledState);

      // Print the LED state to the serial monitor (optional)
      Serial.print("LED is now: ");
      Serial.println(ledState == HIGH ? "ON" : "OFF");

      // Wait for the switch to be released to prevent repeated toggles
      while (digitalRead(switchPin) == LOW); 
    }
  }
}