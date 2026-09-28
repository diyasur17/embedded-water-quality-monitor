// Interactive Wowki Simulation: https://wokwi.com/projects/476451282620908545
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int sensor_val = analogRead(A0);
  int ppb = map(sensor_val, 0, 1023, 0, 15);
  Serial.println(ppb);
  delay(100);
  if (ppb >= 10) {
    lcd.setCursor(0,0);
    lcd.print("WARNING: LEAD  ");
  } 
  else {
    lcd.setCursor(0,0);
    lcd.print("SAFE TO CONSUME");
  }
}
