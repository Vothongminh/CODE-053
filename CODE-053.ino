//VTM https://www.youtube.com/c/VTMVlogVoThongMinh
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int rainSensor = 6; // Chân tín hiệu cảm biến mưa ở chân digital 6 (arduino)

void setup() {
  pinMode(rainSensor, INPUT); // Đặt chân cảm biến mưa là INPUT, vì tín hiệu sẽ được truyền đến cho Arduino
  Serial.begin(9600);// Khởi động Serial ở baudrate 9600
  Serial.println("Da khoi dong xong");
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Cam Bien Mua");
}

void loop() {
  int value = digitalRead(rainSensor);//Đọc tín hiệu cảm biến mưa
  if (value == HIGH) { // Cảm biến đang không mưa
    Serial.println("Đang không mưa");
    lcd.setCursor(0, 1);
    lcd.print("No rain");
  } else {
    Serial.println("Đang mưa");
    lcd.setCursor(0, 1);
    lcd.print("Raining");
  }
  delay(1000);
}
