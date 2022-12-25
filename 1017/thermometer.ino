void setup()
{
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(A5, INPUT);
    Serial.begin(230400);
}

void loop()
{
    int temp = map(analogRead(A5), 0, 1023, -50, 50),
        val = map(abs(temp), 0, 50, 0, 255);
    bool pos = temp >= 0;
    Serial.print(temp);
    Serial.println('C');
    analogWrite(5 + !pos, val);
    analogWrite(5 + pos, 0);
    delay(100);
}