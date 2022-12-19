// const int A = 8, B = 9, C = 12, D = 13, E = 11, F = 7, G = 6, DP = 10;
const int DP[8] = {8, 9, 12, 13, 11, 7, 6, 10};
const int RGB[3] = {2, 3, 4};

void setup()
{
    for (int i = 0; i < 3; i++)
    {
        pinMode(RGB[i], OUTPUT);
    }

    Serial.begin(230400);
}

void loop()
{
    // showdigit(1);
    light('G', 9);
    delay(100);
    light('Y', 5);
    delay(100);
    light('R', 3);
    delay(100);
}

void light(char color, int second)
{
    if (color == 'R')
        digitalWrite(RGB[0], HIGH);
    else if (color == 'G')
        digitalWrite(RGB[1], HIGH);
    else
    {
        digitalWrite(RGB[0], HIGH);
        digitalWrite(RGB[1], HIGH);
    }

    do
    {
        showdigit(second);
    } while (second--);

    if (color == 'R')
        digitalWrite(RGB[0], LOW);
    else if (color == 'G')
        digitalWrite(RGB[1], LOW);
    else
    {
        digitalWrite(RGB[0], LOW);
        digitalWrite(RGB[1], LOW);
    }
}

void showdigit(int digit)
{
    switch (digit)
    {
    case 0:
        digitalWrite(DP[0], HIGH);
        digitalWrite(DP[1], HIGH);
        digitalWrite(DP[2], HIGH);
        digitalWrite(DP[3], HIGH);
        digitalWrite(DP[4], HIGH);
        digitalWrite(DP[5], HIGH);
        break;

    case 1:
        digitalWrite(DP[1], HIGH);
        digitalWrite(DP[2], HIGH);
        break;

    case 2:
        digitalWrite(DP[0], HIGH);
        digitalWrite(DP[1], HIGH);
        digitalWrite(DP[3], HIGH);
        digitalWrite(DP[4], HIGH);
        digitalWrite(DP[6], HIGH);
        break;
    case 3:
        digitalWrite(DP[0], HIGH);
        digitalWrite(DP[1], HIGH);
        digitalWrite(DP[2], HIGH);
        digitalWrite(DP[3], HIGH);
        digitalWrite(DP[6], HIGH);
        break;
    case 4:
        digitalWrite(DP[1], HIGH);
        digitalWrite(DP[2], HIGH);
        digitalWrite(DP[5], HIGH);
        digitalWrite(DP[6], HIGH);
        break;
    case 5:
        digitalWrite(DP[0], HIGH);
        digitalWrite(DP[2], HIGH);
        digitalWrite(DP[3], HIGH);
        digitalWrite(DP[5], HIGH);
        digitalWrite(DP[6], HIGH);
        break;
    case 6:
        digitalWrite(DP[2], HIGH);
        digitalWrite(DP[3], HIGH);
        digitalWrite(DP[4], HIGH);
        digitalWrite(DP[5], HIGH);
        digitalWrite(DP[6], HIGH);
        break;
    case 7:
        digitalWrite(DP[0], HIGH);
        digitalWrite(DP[1], HIGH);
        digitalWrite(DP[2], HIGH);
        break;
    case 8:
        digitalWrite(DP[0], HIGH);
        digitalWrite(DP[1], HIGH);
        digitalWrite(DP[2], HIGH);
        digitalWrite(DP[3], HIGH);
        digitalWrite(DP[4], HIGH);
        digitalWrite(DP[5], HIGH);
        digitalWrite(DP[6], HIGH);
        break;
    case 9:
        digitalWrite(DP[0], HIGH);
        digitalWrite(DP[1], HIGH);
        digitalWrite(DP[2], HIGH);
        digitalWrite(DP[3], HIGH);
        digitalWrite(DP[5], HIGH);
        digitalWrite(DP[6], HIGH);
        break;
    default:
        break;
    }
    delay(1000);
    for (int i = 0; i < 8; i++)
        digitalWrite(DP[i], LOW);
}