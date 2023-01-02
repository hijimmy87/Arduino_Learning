#include <math.h>

const int PIN = 2;
const double BEAT = 250;

const int pitchs[] = {64, 67, 72, 67, 69, 67, 0, 60, 64, 67, 72, 71, 69, 67, 69, 69, 69, 69, 69, 72, 71, 69, 67, 0, 69, 67, 69, 67, 62, 64, 60, 0, 68, 68, 68, 68, 67, 67, 67, 67, 65, 65, 65, 62, 64, 60, 60, 72, 72, 71, 67, 69, 0, 69, 71, 72, 74, 72, 71, 69, 67, 0, 72, 71, 72, 67, 64, 72, 71, 67, 67, 69, 0, 71, 0, 72, 60, 60, 60, 60};
const double durations[] = {1, 1, 2, 1, 1, 2, 0.75, 0.25, 0.75, 0.25, 1, 0.75, 0.25, 4, 0.75, 0.25, 0.75, 0.25, 0.75, 0.25, 0.75, 0.25, 3, 1, 0.75, 0.25, 0.75, 0.25, 1, 1, 3, 1, 0.75, 0.25, 0.75, 2.25, 0.75, 0.25, 0.75, 2.25, 1.5, 0.5, 1, 1, 4, 0.75, 0.25, 0.75, 0.25, 1, 1, 2, 0.75, 0.25, 0.75, 0.25, 1, 1, 1, 1, 3, 1, 0.75, 0.25, 0.75, 0.25, 1, 1, 3, 0.75, 0.25, 1, 1, 1, 1, 1, 0.33, 0.33, 0.33, 2};
const int notes = sizeof(durations) / sizeof(double);

int note2freq(int note)
{
    if (note == 0)
        return 0;
    return round(440.0 * pow(2.0, (note - 69) / 12.0));
}

void setup()
{
    Serial.begin(230400);
    Serial.println("HELLO WORLD!");
}

void loop()
{
    for (int i = 0; i < notes; i++)
    {
        int p = pitchs[i], d = durations[i] * BEAT;
        Serial.print(p);
        Serial.print(' ');
        Serial.println(d);
        if (p == 0)
            delay(d * 2.375);
        else
        {
            tone(PIN, note2freq(p), d);
            delay(d * 1.375);
            noTone(PIN);
        }
    }
    delay(5000);
}