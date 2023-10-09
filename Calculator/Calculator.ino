// See also: https://www.arduino.cc/reference/en/language/functions/communication/serial/

void setup()
{
    Serial.begin(9600);
    Serial.println("Enter a calculation:");
}

void loop()
{
    if (Serial.available())
    {
        long a = getNumber();
        char op = getOperator();
        long b = getNumber();

        long result = calculate(a, b, op);

        Serial.print("Result: ");
        Serial.println(result);
    }
}

long getNumber()
{
    while (!Serial.available())
        ;
    return Serial.parseInt();
}

int getOperator()
{
    while (!Serial.available())
        ;
    return Serial.read();
}

long calculate(long a, long b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}
