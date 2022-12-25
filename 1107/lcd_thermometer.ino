#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    Serial.begin(230400);
    lcd.init();
    lcd.backlight();

    // HS
    String str = "HS_30623";
    lcd.setCursor((16 - str.length()) / 2, 0);
    for (int i = 0; i < str.length(); i++, delay(250))
        lcd.print(str[i]);
}

void loop()
{
    if (Serial.available())
    {
        int t = Serial.parseInt();
        t = (t * 9 / 5) + 32;
        Serial.print(t);
        Serial.println('F');

        int len = 2 + (t > 9 || t < 0) + (t > 99 || t < -9),
            start = (16 - len) / 2;
        // LCD
        lcd.setCursor(0, 1);
        int i;
        for (i = 0; i < start; i++)
            lcd.print(' ');
        if (t < 0)
            lcd.print('-');
        t = abs(t);
        if (t > 99)
            lcd.print(t / 100);
        if (t > 9)
            lcd.print(t % 100 / 10);
        lcd.print(t % 10);
        lcd.print("F");
        for (i += len; i < 16; i++)
            lcd.print(' ');
    }
    delay(500);
}