const int PIN_R = 6;
const int PIN_G = 5;
const int PIN_B = 3;

void setup()
{
    pinMode(PIN_R, OUTPUT);
    pinMode(PIN_G, OUTPUT);
    pinMode(PIN_B, OUTPUT);
}

void loop()
{
    int num = analogRead(A1),
        r = map(num, 0, 0x3ff, 0, 0xff),
        g = map(num, 0, 0x3ff, 0, 0x8f),
        b = map(num, 0, 0x3ff, 0xff, 0);
    analogWrite(PIN_R, r);
    analogWrite(PIN_G, g);
    analogWrite(PIN_B, b);
    delay(10);
}