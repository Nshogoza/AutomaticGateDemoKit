#include <Servo.h>

// Pin definitions
const int trigPin = 9;
const int echoPin = 10;
const int redLEDPin = 2;
const int blueLEDPin = 3;
const int buzzerPin = 4;
const int servoPin = 5;

const int distanceThreshold = 15; // in centimeters

Servo gateServo;

long readDistanceCM() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2; // Convert to cm

  return distance;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  gateServo.attach(servoPin);
  gateServo.write(0); // Start with gate closed

  digitalWrite(redLEDPin, HIGH); // Red ON (closed)
  digitalWrite(blueLEDPin, LOW);
  digitalWrite(buzzerPin, LOW);

  Serial.begin(9600);
}

void loop() {
  long distance = readDistanceCM();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 0 && distance < distanceThreshold) {
    // Open gate
    gateServo.write(90);
    digitalWrite(redLEDPin, LOW);
    digitalWrite(blueLEDPin, HIGH);

    // Buzzer on continuously
    digitalWrite(buzzerPin, HIGH);

    delay(5000); // Wait 5 seconds before closing

    // Close gate
    gateServo.write(0);
    digitalWrite(redLEDPin, HIGH);
    digitalWrite(blueLEDPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(200); // Small delay to avoid sensor bouncing
}
