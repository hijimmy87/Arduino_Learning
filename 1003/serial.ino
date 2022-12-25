void setup()
{
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    Serial.begin(230400);
}

void loop()
{
    int x = map(analogRead(A2), 0, 0x3ff, -100, 100),
        y = map(analogRead(A1), 0, 0x3ff, -100, 100);
    Serial.print('(');
    Serial.print(x);
    Serial.print(", ");
    Serial.print(y);
    Serial.println(')');
    delay(100);
}