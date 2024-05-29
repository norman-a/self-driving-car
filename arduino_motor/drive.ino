// Bluetooth portion commented out
//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(0, 1); // RX | TX
int command;

void setup() {
    Serial.begin(9600);
    //mySerial.begin(9600);

    pinMode(13, OUTPUT); // left motors forward
    pinMode(12, OUTPUT); // left motors reverse
    pinMode(11, OUTPUT); // right motors forward
    pinMode(10, OUTPUT); // right motors reverse
}

void loop() {
    command = mySerial.read();
    handleCommand(command);
    delay(30);
}

void handleCommand(int command) {
    switch (command) {
        case 'F':
            moveForward();
            break;
        case 'B':
            moveReverse();
            break;
        case 'L':
            turnLeft();
            break;
        case 'R':
            turnRight();
            break;
        case 'S':
            stopCar();
            break;
        default:
            Serial.println("Unknown command");
            break;
    }
}

void moveForward() {
    Serial.println("Forward");
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
}

void moveReverse() {
    Serial.println("Reverse");
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
}

void turnLeft() {
    Serial.println("Left");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
}

void turnRight() {
    Serial.println("Right");
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
}

void stopCar() {
    Serial.println("Stop");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
}