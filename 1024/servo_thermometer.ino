#include <Servo.h>

Servo servo;

void setup()
{
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(A5, INPUT);
    Serial.begin(230400);
    servo.attach(3);
}

void loop()
{
    int temp = map(analogRead(A5), 0, 1023, -50, 50),
        val = map(abs(temp), 0, 50, 0, 255),
        deg = map(analogRead(A5), 0, 1023, 180, 0);
    bool pos = temp >= 0;
    Serial.print(temp);
    Serial.println('C');
    analogWrite(5 + !pos, val);
    analogWrite(5 + pos, 0);
    servo.write(deg);
    delay(100);
}