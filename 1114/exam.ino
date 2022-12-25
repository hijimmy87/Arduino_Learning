#include <math.h>

const int PINS[] = {3, 5, 6, 9, 10, 11};

const double T = M_PI / 6;

// const double M_PI_6 = 0.52359877559829887308;

// int v[] = {0, 40, 80, 120, 160, 200, 240};
// int d[] = {5, 5, 5, 5, 5, 5};

void setup()
{
    for (auto p : PINS)
        pinMode(p, OUTPUT);
}

// void loop()
// {
//   for (int i = 0; i < 6; i++)
//   {
//     int p = PINS[i];
//     analogWrite(p, v[i]);
//     v[i] += d[i];
//     if (v[i] <= 0 || v[i] >= 255)
//       d[i] = -d[i];
//   }

//   int s = analogRead(A1);
//   delay(map(s, 0, 1023, 5, 100));
// }

int value(int i, int crest)
{
    double val = cos((i - crest) * T);
    val = val * 128 + 127;
    return round(val);
}

void loop()
{
    int crest = analogRead(A1);
    crest = map(crest, 0, 1023, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        int p = PINS[i];
        int v = value(i, crest);
        analogWrite(p, v);
    }
    delay(10);
}