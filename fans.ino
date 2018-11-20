// Для 1602
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Пины вентиляторов
#define FAN1_PIN 9
#define FAN2_PIN 10
#define FAN3_PIN 11

// Переменная для получения значений с порта
int ser;

// Подключаем 1602
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  // Подключаем 1602
  lcd.begin();

  // Подключаемся к ПК
  Serial.begin(9600);

  // Настраиваем пины вентиляторов на выход
  pinMode(FAN1_PIN, OUTPUT);
  pinMode(FAN2_PIN, OUTPUT);
  pinMode(FAN3_PIN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) { // Если что-то пришло в порт
    ser = Serial.readString().toInt(); // Считываем число с порта

    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print(ser); // Выводим его на экран

    // И управляем вентиляторами
    if (ser < 256) {
      analogWrite(FAN1_PIN, (ser%256));
    }
    else if (255 < ser and ser < 512) {
      analogWrite(FAN2_PIN, (ser%256));
    }
    else if (511 < ser) {
      analogWrite(FAN3_PIN, (ser%256));
    }
  }
}
