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