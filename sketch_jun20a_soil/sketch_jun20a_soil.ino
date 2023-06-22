#include <LiquidCrystal_I2C.h>


//Define variables 
#define I2C_ADDR          0x27        //Define I2C Address where the PCF8574A is
// Pin connected to the DHT11 data pin
#define SOIL_PIN 2


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display


void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Hello Primates!");
  lcd.setCursor(2,1);
  lcd.print("UWU Nicholas!");
  delay(1000);
  lcd.clear();

  Serial.begin(9600);
  pinMode(SOIL_PIN, INPUT);

}
void loop() {
// Read the analog value from the soil moisture sensor
  int moistureValue = analogRead(SOIL_PIN);

  // Print the moisture value
  Serial.print("Moisture Level: ");
  //Subtracting from 1024 because dry air shows as 1024.
  Serial.println(1024 - moistureValue);

  // Delay between readings
  delay(1000);
}