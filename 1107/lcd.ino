#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define ANIMATE
// #define SERIAL
#define SHOW_UNIT

LiquidCrystal_I2C lcd(0x27, 16, 2);

int c = 0, dc = 1;

void hs(int c)
{
    for (int i = 0; i < c; i++)
    {
        lcd.setCursor(i, 0);
        lcd.print(' ');
    }
    lcd.setCursor(c, 0);
    lcd.print("HS_30623");
    for (int i = 8 + c; i < 16; i++)
    {
        lcd.setCursor(i, 0);
        lcd.print(' ');
    }
}

void showTemp(int t)
{
    t = t * 9 / 5 + 32;
    // value
    Serial.println(t);
    lcd.setCursor(0, 1);
    lcd.print(t);

#ifdef SHOW_UNIT
    lcd.setCursor(4, 1);
    lcd.print("oF");
#endif
}

void setup()
{
    Serial.begin(230400);
    lcd.init();
    lcd.backlight();
    hs(0);
}

void loop()
{
#ifdef ANIMATE
    hs(c);
    c += dc;
    if (c == 0 || c == 8)
        dc = -dc;
#endif

#ifdef SERIAL
    if (Serial.available())
    {
        int t = Serial.parseInt();
        showTemp(t);
    }
#else
    showTemp(23);
#endif

    delay(500);
}