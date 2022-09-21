/*
 * 讓 Arduino 板上的 LED 閃爍
 * 改寫自範本 `01.Basics\Blink`
 */

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    digitalWrite(4, HIGH);
    delay(250);
    digitalWrite(4, LOW);
    delay(750);
}