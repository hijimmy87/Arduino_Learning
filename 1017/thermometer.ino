void setup()
{
    Serial.begin(230400);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
}

void loop()
{
    int tmp = map(analogRead(A1), 0, 1023, -50, 50),
        val = map(abs(tmp), 0, 50, 0, 255);
    bool pos = tmp >= 0;
    Serial.print(tmp);
    Serial.println("°C");
    analogWrite(5 + !pos, val);
    analogWrite(5 + pos, 0);
    delay(500);
}