//Basic arduino calculator

void setup()
{
    Serial.begin(9600);
    Serial.println("Enter a calculation:");
}

void loop()
{
    if (Serial.available())
    {
        long a = Serial.parseInt();
        char op = Serial.read();
        long b = Serial.parseInt();

        long result;
        if(op == '+')
            result = a + b;
        if(op == '-')
            result = a - b;
        if(op == '*')
            result = a * b;
        if(op == '/')
            result = a / b;
        
        Serial.print("Result: ");
        Serial.println(result);
    }
}