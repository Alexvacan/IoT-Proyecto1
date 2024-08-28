#include "UltraSonicSensor.h"
#include "Led.h"
#define ECHO_PIN 4
#define TRIG_PIN 2
#define REDLED_PIN 33
#define GREENLED_PIN 32
#define YELLOWLED_PIN 26

const int DISTANCE_THRESHOLD_SHORT = 10;
const int DISTANCE_THRESHOLD_MEDIUM = 20;
const int DISTANCE_THRESHOLD_LONG = 30;


UltrasonicSensor sensor(TRIG_PIN, ECHO_PIN);
LEDController ledController(REDLED_PIN, GREENLED_PIN, YELLOWLED_PIN);

void setup() {
  Serial.begin(115200);
}

void loop() {
  sensor.measureDistance();
  sensor.displayDistance();
  long distance = sensor.getDistance();

  ledController.controlLEDs(distance);

  delay(500);
}