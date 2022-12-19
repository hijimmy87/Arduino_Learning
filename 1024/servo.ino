#include <Servo.h>

Servo servo;

void setup()
{
    servo.attach(3);
    Serial.begin(230400);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
}

void loop()
{
    int tmp = map(analogRead(A1), 0, 1023, -50, 50),
        val = map(abs(tmp), 0, 50, 0, 255),
        deg = map(tmp, -50, 50, 180, 0);
    bool pos = tmp >= 0;
    Serial.print(tmp);
    Serial.println("°C");
    analogWrite(5 + !pos, val);
    analogWrite(5 + pos, 0);
    servo.write(deg);
    delay(500);
}