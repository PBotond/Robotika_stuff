// A kód.
#define EN_A_PIN 6
#define EN_B_PIN 5
#define EN_C_PIN 10
#define EN_D_PIN 9

#define IN_A1_PIN 14
#define IN_A2_PIN 4
#define IN_B1_PIN 3
#define IN_B2_PIN 2
#define IN_C1_PIN 8
#define IN_C2_PIN 7
#define IN_D1_PIN 11
#define IN_D2_PIN 12

typedef enum motor{A,B,C,D} motornev;
motornev motor;

/* Setup függvény
            feladatai:
        */

void setup()
{
    pinMode(EN_A_PIN, OUTPUT);
    pinMode(EN_B_PIN, OUTPUT);
    pinMode(EN_C_PIN, OUTPUT);
    pinMode(EN_D_PIN, OUTPUT);

    pinMode(IN_A1_PIN, OUTPUT);
    pinMode(IN_A2_PIN, OUTPUT);
    pinMode(IN_B1_PIN, OUTPUT);
    pinMode(IN_B2_PIN, OUTPUT);
    pinMode(IN_C1_PIN, OUTPUT);
    pinMode(IN_C2_PIN, OUTPUT);
    pinMode(IN_D1_PIN, OUTPUT);
    pinMode(IN_D2_PIN, OUTPUT);
}

/* Loop függvény
            feladatai:
        */

void loop()
{

}