#include <Arduino.h>

// Motor pins
int lf = 23, lb = 16, rf = 13, rb = 14;
int enl = 12, enr = 17;

// IR sensor pins (digital)
const int irLeft = 34;
const int irRight = 35;

void setup()
{
    // Initialize motor pins
    pinMode(lf, OUTPUT);
    pinMode(lb, OUTPUT);
    pinMode(rf, OUTPUT);
    pinMode(rb, OUTPUT);
    pinMode(enl, OUTPUT);
    pinMode(enr, OUTPUT);

    analogWrite(enl, 0);
    analogWrite(enr, 0);

    // Initialize IR sensors
    pinMode(irLeft, INPUT);
    pinMode(irRight, INPUT);

    // Initialize Serial for debugging
    Serial.begin(115200);
    delay(1000);
    Serial.println("Line Follow Mode Initialized");
}

void loop()
{
    // Read IR sensors (LOW means line detected)
    int leftValue = digitalRead(irLeft);
    int rightValue = digitalRead(irRight);

    Serial.print("Left IR: ");
    Serial.print(leftValue);
    Serial.print("  Right IR: ");
    Serial.println(rightValue);

    if (leftValue == LOW && rightValue == LOW)
    {
        // Both sensors on line: move forward
        Forward();
    }
    else if (leftValue == LOW && rightValue == HIGH)
    {
        // Left sensor on line, right sensor off line: turn left
        Left();
    }
    else if (leftValue == HIGH && rightValue == LOW)
    {
        // Right sensor on line, left sensor off line: turn right
        Right();
    }
    else
    {
        // Both sensors off line: stop or search
        Stop();
    }

    delay(50); // Small delay for sensor reading stability
}

void setMotors(bool lfState, bool lbState, bool rfState, bool rbState, int speedLeft, int speedRight)
{
    digitalWrite(lf, lfState ? HIGH : LOW);
    digitalWrite(lb, lbState ? HIGH : LOW);
    digitalWrite(rf, rfState ? HIGH : LOW);
    digitalWrite(rb, rbState ? HIGH : LOW);
    analogWrite(enl, speedLeft);
    analogWrite(enr, speedRight);
}

void Forward()
{
    Serial.println("Moving Forward");
    setMotors(true, false, true, false, 200, 200);
}

void Backward()
{
    Serial.println("Moving Backward");
    setMotors(false, true, false, true, 200, 200);
}

void Left()
{
    Serial.println("Turning Left");
    setMotors(false, true, true, false, 200, 200);
}

void Right()
{
    Serial.println("Turning Right");
    setMotors(true, false, false, true, 200, 200);
}

void Stop()
{
    Serial.println("Stopping");
    setMotors(false, false, false, false, 0, 0);
}
