#include <LiquidCrystal_I2C.h>

// Create an instance of the DHT11 class and set the digital I/O pin.
//Digital 2 pin
#define RAIN_SENSOR_PIN 8
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Hello Primates!");
  lcd.setCursor(2,1);
  Serial.begin(9600);
  pinMode(RAIN_SENSOR_PIN, INPUT);
}

void loop()
{
 // Read the digital value from the rain sensor
  int rainValue = digitalRead(RAIN_SENSOR_PIN);

  // Check if it's raining
  if (rainValue == LOW) {
    Serial.println("It's raining!");
  } else {
    Serial.println("No rain detected.");
  }

  // Delay between readings
  delay(1000);
}

