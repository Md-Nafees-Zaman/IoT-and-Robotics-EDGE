#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD address, 16 chars, and 2 lines
const int lm35Pin = A0;            // LM35 sensor connected to analog pin A0
String scrollMessage = " Asif,Insana,Badhon,Nafees,Shovon";
int scrollIndex = 0;

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight(); // Make sure backlight is on
  
  lcd.setCursor(2, 0); // Initial position for "Hello world!"
  lcd.print("Temp: ");
}

void loop() {
  // Read temperature from LM35
  int sensorValue = analogRead(lm35Pin);
  float voltage = sensorValue * (5.0 / 1023.0); // Convert ADC value to voltage
  float temperature = voltage * 100.0;         // Convert voltage to Celsius
  
  // Display temperature on the first row
  lcd.setCursor(7, 0);       // Set cursor to display temperature value
  lcd.print(temperature, 1); // Print temperature with 1 decimal point
  lcd.print((char)223);      // Degree symbol
  lcd.print("C  ");          // Celsius unit (space to overwrite old characters)
  
  // Scrolling message on the second row
  lcd.setCursor(0, 1); // Set cursor to the beginning of the second row
  String displayScroll = scrollMessage.substring(scrollIndex, scrollIndex + 16);
  lcd.print(displayScroll); // Print a 16-character segment of the message
  
  // Update scrolling index
  scrollIndex++;
  if (scrollIndex + 16 > scrollMessage.length()) {
    scrollIndex = 0; // Reset the index for continuous scrolling
  }

  delay(300); // Delay for smooth scrolling
}