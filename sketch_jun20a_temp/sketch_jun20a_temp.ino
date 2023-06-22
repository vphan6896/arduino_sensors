#include <LiquidCrystal_I2C.h>
#include <dht.h>

// Create an instance of the DHT11 class and set the digital I/O pin.
//Digital 2 pin
dht DHT;
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
  pinMode(2, INPUT);
}

void loop()
{
    int readData = DHT.read11(2);

	float t = DHT.temperature;        // Read temperature
	float h = DHT.humidity;           // Read humidity

	Serial.print("Temperature = ");
	Serial.print(t);
	Serial.print("°C | ");
	Serial.print((t*9.0)/5.0+32.0);        // Convert celsius to fahrenheit
	Serial.println("°F ");
	Serial.print("Humidity = ");
	Serial.print(h);
	Serial.println("% ");
	Serial.println("");

	delay(2000); // wait two seconds
}