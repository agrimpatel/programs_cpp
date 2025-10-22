#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Wi-Fi credentials
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

// Blynk authentication token
char auth[] = "YourBlynkAuthToken";

// Motor pins
int lf = 23, lb = 16, rf = 13, rb = 14;
int enl = 12, enr = 17;

void setup()
{
    Serial.begin(115200);

    // Setup motor pins
    pinMode(lf, OUTPUT);
    pinMode(lb, OUTPUT);
    pinMode(rf, OUTPUT);
    pinMode(rb, OUTPUT);
    pinMode(enl, OUTPUT);
    pinMode(enr, OUTPUT);

    // Connect to Wi-Fi and Blynk
    Blynk.begin(auth, ssid, pass);
}

// Main loop
void loop()
{
    Blynk.run();
}

// Move Forward
BLYNK_WRITE(V1)
{
    int value = param.asInt();
    if (value == 1)
    {
        digitalWrite(lf, HIGH);
        digitalWrite(lb, LOW);
        digitalWrite(rf, HIGH);
        digitalWrite(rb, LOW);
        analogWrite(enl, 200);
        analogWrite(enr, 200);
    }
    else
    {
        stopMotors();
    }
}

// Move Backward
BLYNK_WRITE(V2)
{
    int value = param.asInt();
    if (value == 1)
    {
        digitalWrite(lf, LOW);
        digitalWrite(lb, HIGH);
        digitalWrite(rf, LOW);
        digitalWrite(rb, HIGH);
        analogWrite(enl, 200);
        analogWrite(enr, 200);
    }
    else
    {
        stopMotors();
    }
}

// Move Left
BLYNK_WRITE(V3)
{
    int value = param.asInt();
    if (value == 1)
    {
        digitalWrite(lf, LOW);
        digitalWrite(lb, HIGH);
        digitalWrite(rf, HIGH);
        digitalWrite(rb, LOW);
        analogWrite(enl, 200);
        analogWrite(enr, 200);
    }
    else
    {
        stopMotors();
    }
}

// Move Right
BLYNK_WRITE(V4)
{
    int value = param.asInt();
    if (value == 1)
    {
        digitalWrite(lf, HIGH);
        digitalWrite(lb, LOW);
        digitalWrite(rf, LOW);
        digitalWrite(rb, HIGH);
        analogWrite(enl, 200);
        analogWrite(enr, 200);
    }
    else
    {
        stopMotors();
    }
}

// Function to stop all motors
void stopMotors()
{
    digitalWrite(lf, LOW);
    digitalWrite(lb, LOW);
    digitalWrite(rf, LOW);
    digitalWrite(rb, LOW);
    analogWrite(enl, 0);
    analogWrite(enr, 0);
}
