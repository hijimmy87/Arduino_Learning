#include <math.h>

const String notes[] = {"C4", "D4", "E4", "F4", "G4"};
const int START = 15, BUZZ = 7;

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
    for (int i = 0; i < 6; i++)
        pinMode(START + i, INPUT);
    pinMode(BUZZ, OUTPUT);
}

void loop()
{
    for (int i = 0; i < 6; i++)
        if (digitalRead(START + i) == HIGH)
            tone(BUZZ, note2freq(notes[i]), 50);
}