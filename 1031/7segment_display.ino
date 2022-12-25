#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int DB[36] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111, // 9
    0b01110111, // A
    0b01111100, // b
    0b00111001, // C
    0b01011110, // d
    0b01111001, // E
    0b01110001, // F
    0b00111101, // G
    0b01110110, // H
    0b00110000, // I
    0b00011110, // J
    0b10000000, // K ERR
    0b00111000, // L
    0b10000000, // M ERR
    0b01010100, // n
    0b01011100, // o
    0b01110011, // P
    0b01100111, // q
    0b10000000, // R ERR
    0b10000000, // S ERR
    0b10000000, // T ERR
    0b00111110, // U
    0b10000000, // V ERR
    0b10000000, // W ERR
    0b10000000, // X ERR
    0b01101110, // Y
    0b10000000, // Z ERR
};

const int PIN[8] = {8, 9, 12, 13, 11, 7, 6, 10};

LiquidCrystal_I2C lcd(0x27, 16, 2);

void show(char chr)
{
    lcd.clear();
    lcd.print(chr);
    if (chr >= '0' && chr <= '9')
        chr -= 48;
    else if (chr >= 'A' && chr <= 'Z')
        chr -= 55;
    else if (chr >= 'a' && chr <= 'z')
        chr -= 87;
    else // error
    {
        lcd.setCursor(0, 1);
        lcd.print("ERROR!!");
        return;
    }
    int code = DB[chr];
    if ((code >> 7) & 1)
    {
        lcd.setCursor(0, 1);
        for (auto c : "(CANNOT DISPLAY)")
            lcd.print(c);
    }

    for (int i = 0; i < 8; i++, code >>= 1)
        digitalWrite(PIN[i], code & 1);
    delay(1000);
    for (int i = 0; i < 8; i++)
        digitalWrite(PIN[i], LOW);
}

void setup()
{
    Serial.begin(230400);
    for (int i = 0; i < 8; i++)
        pinMode(PIN[i], OUTPUT);
    lcd.init();
    lcd.backlight();
}

void loop()
{
    int d = 250;

    // String str = "Hello";
    // for (char chr : str)
    // {
    //     show(chr);
    //     delay(d);
    // }

    char chr;
    for (chr = '0'; chr <= '9'; chr++)
        show(chr);
    for (chr = 'A'; chr <= 'Z'; chr++)
        show(chr);
}