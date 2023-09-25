constexpr auto PERIOD = 1000;
void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(PERIOD);
    digitalWrite(LED_BUILTIN, LOW);
    delay(PERIOD);
}