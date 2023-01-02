#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

void setup()
{
    pinMode(3, OUTPUT);
    servo.attach(3);
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
        int t = Serial.parseInt(), d, l;
        char outputs[16] = {};
        if (t < -40)
        {
            String s = "TOO SMALL!";
            l = s.length(), d = 180;
            for (int i = 0; i < l; i++)
                outputs[i] = s[i];
        }
        else if (t > 40)
        {
            String s = "TOO LARGE!";
            l = s.length(), d = 0;
            for (int i = 0; i < l; i++)
                outputs[i] = s[i];
        }
        else
        {
            d = map(t, -40, 40, 180, 0), t = round(t * 9.0 / 5) + 32;
            l = 2 + (t > 9 || t < 0) + (t > 99 || t < -9);
            itoa(t, outputs, 10);
            outputs[l - 1] = 'F';
        }
        int start = (16 - l) / 2;
        servo.write(d);
        lcd.setCursor(0, 1);
        int i;
        for (i = 0; i < start; i++)
            lcd.print(' ');
        for (i = 0; i < l; i++)
        {
            Serial.print(outputs[i]);
            lcd.print(outputs[i]);
        }
        Serial.println("");
        for (i = start + l; i < 16; i++)
            lcd.print(' ');
    }
    delay(500);
}