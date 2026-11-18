// Maze Solving Robot
// Controller: Arduino UNO
// Sensors: 3 x HC-SR04 Ultrasonic Sensors
// Motor Driver: L298N

// Distance thresholds (in cm)
#define FTHOLD 12
#define RTHOLD 20
#define LTHOLD 20

// Motor driver pins
const int motor1A = 10;
const int motor1B = 11;
const int motor2A = 12;
const int motor2B = 13;

const int ena = 7;
const int enb = 4;

// Front ultrasonic sensor
const int trigPinf = 9;
const int echoPinf = 8;

// Right ultrasonic sensor
const int trigPinr = 3;
const int echoPinr = 2;

// Left ultrasonic sensor
const int trigPinl = 5;
const int echoPinl = 6;

// Measure distance using ultrasonic sensor
float measureDistance(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH, 30000);

    if (duration == 0) {
        return 400;
    }

    return duration * 0.0344 / 2;
}

// Move robot forward
void goForward() {
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);

    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);
}

// Stop robot
void stopBot() {
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, LOW);

    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, LOW);
}

// Turn right
void turnRight() {
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);

    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, HIGH);

    delay(500);
    stopBot();
}

// Turn left
void turnLeft() {
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, HIGH);

    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);

    delay(500);
    stopBot();
}

// Arduino initialization
void setup() {
    // Motor pins
    pinMode(motor1A, OUTPUT);
    pinMode(motor1B, OUTPUT);
    pinMode(motor2A, OUTPUT);
    pinMode(motor2B, OUTPUT);

    pinMode(ena, OUTPUT);
    pinMode(enb, OUTPUT);

    digitalWrite(ena, HIGH);
    digitalWrite(enb, HIGH);

    // Ultrasonic sensor pins
    pinMode(trigPinf, OUTPUT);
    pinMode(echoPinf, INPUT);

    pinMode(trigPinr, OUTPUT);
    pinMode(echoPinr, INPUT);

    pinMode(trigPinl, OUTPUT);
    pinMode(echoPinl, INPUT);

    Serial.begin(9600);

    stopBot();
}

// Main robot operation
void loop() {
    float frontDist = measureDistance(trigPinf, echoPinf);

    Serial.print("Front: ");
    Serial.println(frontDist);

    if (frontDist > FTHOLD) {
        goForward();
    }
    else {
        stopBot();
        delay(300);

        float rightDist = measureDistance(trigPinr, echoPinr);
        float leftDist = measureDistance(trigPinl, echoPinl);

        Serial.print("Right: ");
        Serial.println(rightDist);

        Serial.print("Left: ");
        Serial.println(leftDist);

        if (rightDist > leftDist) {
            turnRight();
        }
        else {
            turnLeft();
        }
    }

    delay(100);
}
