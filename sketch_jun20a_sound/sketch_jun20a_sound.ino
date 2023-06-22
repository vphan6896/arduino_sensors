#include <LiquidCrystal_I2C.h>


//Define variables 
#define I2C_ADDR          0x27        //Define I2C Address where the PCF8574A is
// Pin connected to the DHT11 data pin
#define SOUND_PIN 1
#define THRESHOLD 3


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
//Global vars
int sound0 = 0;
int sound1 = 0;
int sound2 = 0;
int time = 0;
unsigned long lastEvent = 0;

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
  pinMode(A1, INPUT);

}
void loop() {
// Read Sound sensor
	int sensorData = analogRead(A1);
  Serial.println(sensorData);
  if (time == 0 ){
    Serial.println("Setting sound0");
    sound0 = sensorData;
  } else if (time == 1) {
    Serial.println("Setting sound1");
    sound1 = sensorData;
  } else if (time == 2) {
    Serial.println("Setting sound2");
    sound2 = sensorData;
  }
  int avg = (sound0 + sound1 + sound2) / 3;
  Serial.print("Average is ");
  Serial.println(avg);
  if(sensorData > avg + THRESHOLD){
    Serial.println("You're NOISY");
  }

  
  delay(1000);
  time = time + 1;
  if (time > 4) {
    time = 0;
  }
  

}