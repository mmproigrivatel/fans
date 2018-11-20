// Пины вентиляторов
#define FAN1_PIN 9
#define FAN2_PIN 10
#define FAN3_PIN 11

// Переменная для получения значений с порта
int ser;

void setup() {
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
