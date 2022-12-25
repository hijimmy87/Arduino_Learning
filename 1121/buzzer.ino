#include <math.h>

const int BPM = 120;
const float BEAT = 60.0 * 500 / BPM;

const String melody[] = {
    "0", "0", "D5", "F5",
    "G5", "G5", "A5", "A5", "A5",
    "C6", "D6", "G5", "F4", "A4"};

const float durations[] = {
    2, 1, 0.5, 0.5,
    0.75, 0.75, 0.5, 1.5, 0.5,
    0.5, 0.5, 0.5, 0.5, 1};

const int notes = sizeof(durations) / sizeof(float);

const int PIN = 8;

int note2freq(String note)
{
    if (note == "0")
        return 0;
    bool bors = note.length() == 3;
    double p = note[0] - 56 - 11 * (note[0] >= 'C' && note[0] <= 'G');
    if (bors)
        p += note[1] == 'b' ? 1 : -1;
    p += 12 * (note[1 + bors] - 52);
    return round(440 * pow(2, (p - 9) / 12.0));
}

void setup()
{
    Serial.begin(230400);
    for (int i = 0; i < notes; i++)
    {
        int d = durations[i] * BEAT;
        Serial.print(melody[i]);
        Serial.print(' ');
        Serial.print(durations[i]);
        Serial.print(' ');
        Serial.println(d);
        tone(PIN, note2freq(melody[i]), d);
        delay(d * 1.375);
        noTone(PIN);
    }
}

void loop()
{

    note2freq("A4"); // 440
}