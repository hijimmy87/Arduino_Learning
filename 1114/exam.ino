#include <math.h>

const int PINS[] = {3, 5, 6, 9, 10, 11};

const double T = M_PI / 6;

void setup()
{
    pinMode(A1, INPUT);
    for (auto p : PINS)
        pinMode(p, OUTPUT);
}

int value(int i, int crest)
{
    return round(cos((i - crest) * T) * 128 + 127);
}

void loop()
{
    int crest = map(analogRead(A1), 0, 1023, 0, 5);
    for (int i = 0; i < 6; i++)
        analogWrite(PINS[i], value(i, crest));
    delay(10);
}