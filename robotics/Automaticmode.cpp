// Motor pins
int lf = 23, lb = 16, rf = 13, rb = 14;
int enl = 12, enr = 17;

// Ultrasonic sensor pins
const int trigPin = 5;
const int echoPin = 18;

// Distance threshold in centimeters
const int obstacleDistance = 20;

void setup()
{
    // Initialize motor pins as outputs
    pinMode(lf, OUTPUT);
    pinMode(lb, OUTPUT);
    pinMode(rf, OUTPUT);
    pinMode(rb, OUTPUT);
    pinMode(enl, OUTPUT);
    pinMode(enr, OUTPUT);

    analogWrite(enl, 0);
    analogWrite(enr, 0);

    // Initialize ultrasonic sensor pins
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    // Initialize serial communication for debugging
    Serial.begin(115200);
    delay(1000);

    Serial.println("Automatic Mode Initialized");
}

void loop()
{
    int distance = readDistance();

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance > 0 && distance < obstacleDistance)
    {
        Serial.println("Obstacle detected! Turning...");
        Stop();
        delay(500);

        // Turn right to avoid obstacle
        Right();
        delay(500);

        Stop();
        delay(500);
    }
    else
    {
        Serial.println("Path is clear. Moving forward.");
        Forward();
    }

    delay(100); // Delay for sensor stability
}

// Function to measure distance using ultrasonic sensor
int readDistance()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034 / 2; // Convert time to cm
    return distance;
}

// Move forward
void Forward()
{
    Serial.println("Moving Forward");
    digitalWrite(lf, HIGH);
    digitalWrite(rf, HIGH);
    digitalWrite(lb, LOW);
    digitalWrite(rb, LOW);
    analogWrite(enl, 200);
    analogWrite(enr, 200);
}

// Move backward
void Backward()
{
    Serial.println("Moving Backward");
    digitalWrite(lb, HIGH);
    digitalWrite(rb, HIGH);
    digitalWrite(lf, LOW);
    digitalWrite(rf, LOW);
    analogWrite(enl, 200);
    analogWrite(enr, 200);
}

// Turn left
void Left()
{
    Serial.println("Turning Left");
    digitalWrite(lb, HIGH);
    digitalWrite(rb, LOW);
    digitalWrite(lf, LOW);
    digitalWrite(rf, HIGH);
    analogWrite(enl, 200);
    analogWrite(enr, 200);
}

// Turn right
void Right()
{
    Serial.println("Turning Right");
    digitalWrite(lf, HIGH);
    digitalWrite(rf, LOW);
    digitalWrite(lb, LOW);
    digitalWrite(rb, HIGH);
    analogWrite(enl, 200);
    analogWrite(enr, 200);
}

// Stop the robot
void Stop()
{
    Serial.println("Stopping");
    digitalWrite(lf, LOW);
    digitalWrite(lb, LOW);
    digitalWrite(rf, LOW);
    digitalWrite(rb, LOW);
    analogWrite(enl, 0);
    analogWrite(enr, 0);
}
