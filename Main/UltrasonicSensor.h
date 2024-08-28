#include <arduino.h>
class UltrasonicSensor {
  private:
    int trigPin;
    int echoPin;
    long duration;
    long distance;

  public:
    UltrasonicSensor(int trig, int echo) {
      trigPin = trig;
      echoPin = echo;
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
    }

    void measureDistance() {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(4);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      duration = pulseIn(echoPin, HIGH);
      duration = duration / 2;
      distance = duration / 29.2;
    }

    long getDistance() {
      return distance;
    }

    void displayDistance() {
      Serial.print("Distance in Cm: ");
      Serial.println(distance);
    }
};
