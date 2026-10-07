// Interactive Wowki Simulation: https://wokwi.com/projects/476451282620908545
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2);

int readings[8];
int index = 0; 

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int raw = analogRead(A0) + random(-8, 9);
  int sensor_val = constrain(raw, 0, 1023);
  readings[index] = sensor_val;
  index = (index + 1) % 8;
  int sum = 0;
  for (int i = 0; i < 8; i++) {
    sum+= readings[i];
  }
  double avg = sum / 8.0;
  int ppb = map((int)avg, 0, 1023, 0, 15);
  Serial.print(sensor_val);
  Serial.print(", ");
  Serial.print(avg);
  Serial.print(", ");
  Serial.println(ppb);
  delay(100);
  if (ppb >= 10) {
    lcd.setCursor(0,0);
    lcd.print("ABOVE ACTION LVL");
  } 
  else {
    lcd.setCursor(0,0);
    lcd.print("BELOW LVL       ");
  }
}
