const int PIN_RGB[] = {6, 5, 3};

void setup()
{
    pinMode(A1, INPUT);
    for (int i = 0; i < 3; i++)
        pinMode(PIN_RGB[i], OUTPUT);
}

void loop()
{
    float h = analogRead(A1) * 45.0 / 128.0;
    int hi = h / 60,
        p = round((h / 60.0 - hi) * 255),
        q = 255 - p;
    int rgb[3] = {};
    switch (hi)
    {
    case 0:
        rgb[0] = 255, rgb[1] = p;
        break;
    case 1:
        rgb[0] = q, rgb[1] = 255;
        break;
    case 2:
        rgb[1] = 255, rgb[2] = p;
        break;
    case 3:
        rgb[1] = q, rgb[2] = 255;
        break;
    case 4:
        rgb[0] = p, rgb[2] = 255;
        break;
    case 5:
        rgb[0] = 255, rgb[2] = q;
        break;

    default:
        break;
    }
    for (int i = 0; i < 3; i++)
        analogWrite(PIN_RGB[i], rgb[i]);
    delay(10);
}