#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <LiquidCrystal_I2C.h>

const float seaLevelPressure = 1013.25; //hPa
const int delayTime = 1000;
Adafruit_BME280 bme;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.print("Weather Monitor");
  boolean status = bme.begin();
  lcd.setCursor(0,1);
  if (!status) {
    lcd.print("No Sensor!");
    while (1);
  }else{
    lcd.print("Sensor Ready");
  }
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.print(bme.readTemperature());
  lcd.print("*C ");
  lcd.print(bme.readHumidity());
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print(bme.readPressure() / 100.0F);
  lcd.print(" hPa");
  delay(delayTime);
}
