const int DP[8] = {8, 9, 12, 13, 11, 7, 6, 10}; // A, B, C, D, E, F, G, DP
const int RGB[3] = {4, 3, 2};
const int DS[10] = {63, 6, 91, 79, 102, 109, 124, 7, 127, 111}; // 0 - 9

void setup()
{
    for (int i = 0; i < 8; i++)
        pinMode(DP[i], OUTPUT);
    for (int i = 0; i < 3; i++)
        pinMode(RGB[i], OUTPUT);
}

void loop()
{
    light('G', 9);
    light('Y', 5);
    light('R', 3);
}

void light(char color, int second)
{
    if (color != 'G') // R, Y
        digitalWrite(RGB[0], HIGH);
    if (color != 'R') // G, Y
        digitalWrite(RGB[1], HIGH);
    do
    {
        showdigit(second);
    } while (second--);
    digitalWrite(RGB[0], LOW);
    digitalWrite(RGB[1], LOW);
}

void showdigit(int digit)
{
    int d = DS[digit];
    for (int i = 0; i < 8; i++, d >>= 1)
        digitalWrite(DP[i], d & 1);
    delay(1000);
    for (int i = 0; i < 8; i++)
        digitalWrite(DP[i], LOW);
}