#include "BluetoothSerial.h"
BluetoothSerial BT;

char ch = -1;   // Mode selection

// Motor pins
int lf = 23, lb = 16, rf = 13, rb = 14;
int enl = 12, enr = 17;

void setup() {
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(enl, OUTPUT);
  pinMode(enr, OUTPUT);

  analogWrite(enl, 0);
  analogWrite(enr, 0);

  Serial.begin(115200);
  BT.begin("My_Car");

  // Wait for valid mode selection via Bluetooth
  while (true) {
    Serial.println("Select Mode: 1. Bluetooth  2. Automatic  3. Line_Follow  4. Global");
    BT.println("Select Mode: 1. Bluetooth  2. Automatic  3. Line_Follow  4. Global");

    if (BT.available()) {
      char received = BT.read();
      if (received == '1' || received == '2' || received == '3' || received == '4') {
        ch = received;
        Serial.print("Mode Selected: ");
        Serial.println(ch);
        BT.print("Mode Selected: ");
        BT.println(ch);
        break; // Exit loop once valid input is received
      } else {
        Serial.println("Invalid input. Please send 1, 2, 3, or 4.");
        BT.println("Invalid input. Please send 1, 2, 3, or 4.");
      }
    } else {
      Serial.println("Waiting for Bluetooth input...");
    }
    delay(1000);
  }
}


void loop() {
  if (ch == -1) {
    Serial.println("Select Mode:\n1. Bluetooth\n2. Automatic\n3. Line_Follow\n4. Global");
    BT.println("Select Mode:\n1. Bluetooth\n2. Automatic\n3. Line_Follow\n4. Global");
    delay(2000);

    if (BT.available()) {
      ch = (char)BT.read();
      Serial.print("Selected Mode: ");
      Serial.println(ch);
    }
    return;
  }

  switch (ch) {
    case '1':  Bluetooth();  break;
    case '2':  Automatic();  break;
    case '3':  LineFollow(); break;
    case '4':  Global();     break;
    default:   Stop();       break;
  }
}

// ===== Motor Functions =====
void Forward() {
  Serial.println("Forward");
  digitalWrite(lf, HIGH);
  digitalWrite(rf, HIGH);
  digitalWrite(lb, LOW);
  digitalWrite(rb, LOW);
  analogWrite(enr, 200);
  analogWrite(enl, 200);
}

void Backward() {
  Serial.println("Backward");
  digitalWrite(lb, HIGH);
  digitalWrite(rb, HIGH);
  digitalWrite(lf, LOW);
  digitalWrite(rf, LOW);
  analogWrite(enr, 200);
  analogWrite(enl, 200);
}

void Left() {
  Serial.println("Left");
  digitalWrite(lb, HIGH);
  digitalWrite(rb, LOW);
  digitalWrite(lf, LOW);
  digitalWrite(rf, HIGH);
  analogWrite(enr, 200);
  analogWrite(enl, 200);
}

void Right() {
  Serial.println("Right");
  digitalWrite(lf, HIGH);
  digitalWrite(rf, LOW);
  digitalWrite(rb, HIGH);
  digitalWrite(lb, LOW);
  analogWrite(enr, 200);
  analogWrite(enl, 200);
}

void Stop() {
  Serial.println("Stop");
  digitalWrite(lb, LOW);
  digitalWrite(lf, LOW);
  digitalWrite(rf, LOW);
  digitalWrite(rb, LOW);
  analogWrite(enr, 0);
  analogWrite(enl, 0);
}

// ===== Mode Functions =====
void Global() {
  Serial.println("Global Mode Running...");
}

void Bluetooth() {
  static bool first = true;
  if (first) {
    Serial.println("Bluetooth Mode Started");
    BT.println("Bluetooth Mode Started");
    first = false;
  }

  if (BT.available()) {
    char cmd = (char)BT.read();
    Serial.print("Command: ");
    Serial.println(cmd);

    switch (cmd) {
      case 'F': Forward(); break;
      case 'B': Backward(); break;
      case 'L': Left(); break;
      case 'R': Right(); break;
      case 'S': Stop(); break;
      default: Stop(); break;
    }
  }
}

void Automatic() {
  Serial.println("Automatic Mode Running...");
  // Add autonomous logic here
}

void LineFollow() {
  Serial.println("Line Follow Mode Running...");
  // Add line-following sensor logic here
}
