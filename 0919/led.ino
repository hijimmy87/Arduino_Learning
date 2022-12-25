#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int INTERVAL = 250;
const int PIN = 5;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    pinMode(PIN, OUTPUT);
    lcd.init();
    lcd.backlight();
}

void loop()
{
    String str = "HELLOWORLD";
    morse(str);
}

void sleep(float ratio)
{
    delay((int)(INTERVAL * ratio));
}

void oneMorse(char chr)
{
    lcd.print(chr);
    // To Upper Case
    if (chr >= 'a' && chr <= 'z')
        chr -= 32;
    // Encode
    String morse = "";
    switch (chr)
    {
    case 'A':
        morse = "01";
        break;
    case 'B':
        morse = "1000";
        break;
    case 'C':
        morse = "1010";
        break;
    case 'D':
        morse = "100";
        break;
    case 'E':
        morse = "0";
        break;
    case 'F':
        morse = "0010";
        break;
    case 'G':
        morse = "110";
        break;
    case 'H':
        morse = "0000";
        break;
    case 'I':
        morse = "00";
        break;
    case 'J':
        morse = "0111";
        break;
    case 'K':
        morse = "101";
        break;
    case 'L':
        morse = "0100";
        break;
    case 'M':
        morse = "11";
        break;
    case 'N':
        morse = "10";
        break;
    case 'O':
        morse = "111";
        break;
    case 'P':
        morse = "0110";
        break;
    case 'Q':
        morse = "1101";
        break;
    case 'R':
        morse = "010";
        break;
    case 'S':
        morse = "000";
        break;
    case 'T':
        morse = "1";
        break;
    case 'U':
        morse = "001";
        break;
    case 'V':
        morse = "0001";
        break;
    case 'W':
        morse = "011";
        break;
    case 'X':
        morse = "1001";
        break;
    case 'Y':
        morse = "1011";
        break;
    case 'Z':
        morse = "1100";
        break;
    case '1':
        morse = "01111";
        break;
    case '2':
        morse = "00111";
        break;
    case '3':
        morse = "00011";
        break;
    case '4':
        morse = "00001";
        break;
    case '5':
        morse = "00000";
        break;
    case '6':
        morse = "10000";
        break;
    case '7':
        morse = "11000";
        break;
    case '8':
        morse = "1110";
        break;
    case '9':
        morse = "11110";
        break;
    case '0':
        morse = "11111";
        break;
    case '.':
        morse = "010101";
        break;
    case ':':
        morse = "111000";
        break;
    case ',':
        morse = "110011";
        break;
    case ';':
        morse = "101010";
        break;
    case '?':
        morse = "001100";
        break;
    case '=':
        morse = "10001";
        break;
    case '\'':
        morse = "011110";
        break;
    case '/':
        morse = "10010";
        break;
    case '!':
        morse = "101011";
        break;
    case '-':
        morse = "100001";
        break;
    case '_':
        morse = "001101";
        break;
    case '"':
        morse = "010010";
        break;
    case '(':
        morse = "10110";
        break;
    case ')':
        morse = "101101";
        break;
    case '$':
        morse = "0001001";
        break;
    case '&':
        morse = "01000";
        break;
    case '@':
        morse = "011010";
        break;
    case '+':
        morse = "01010";
        break;
    default:
        // space
        sleep(4);
        break;
    }
    for (int i = 0; i < morse.length(); i++)
    {
        digitalWrite(PIN, HIGH);
        // '0' -> 1; '1' -> 3
        sleep((morse[i] - 48) * 2 + 1);
        digitalWrite(PIN, LOW);
        sleep(1);
    }
    sleep(3);
}

void morse(String str)
{
    for (int i = 0; i < str.length(); i++)
        oneMorse(str[i]);
    sleep(10);
}
