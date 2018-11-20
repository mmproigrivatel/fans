import serial

port = 'COM3' # Порт Arduino
speed = 9600 # Скорость подключения, Бод

with serial.Serial(port, speed, timeout=0) as ser:
    while True:
        fan = int(input('Выберите вентилятор (1...3):'))
        fan_speed = int(input('Выберите скорость (0...255):'))
        if not (1 <= fan <= 3 and 0 <= fan_speed <= 255):
            print('Введено неправильное значение!')
            continue
        s = 256*(fan-1) + fan_speed # Расчет значения, передаваемого в порт
        ser.write(bytes(str(s), encoding='ascii'))
