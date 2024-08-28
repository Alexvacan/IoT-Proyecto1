#include <arduino.h>
#include "OtherLed.h"

class LEDController {
  private:
    LED redLED;
    LED greenLED;
    LED yellowLED;

  public:
    LEDController(int redPin, int greenPin, int yellowPin) 
      : redLED(redPin), greenLED(greenPin), yellowLED(yellowPin) {}

    void controlLEDs(long distance) {
      if (distance >= 0 && distance <= 400) {
        if (distance < DISTANCE_THRESHOLD_SHORT) {
          redLED.turnOn();
          greenLED.turnOn();
          yellowLED.turnOn();
        } else if (distance < DISTANCE_THRESHOLD_MEDIUM) {
          redLED.turnOn();
          greenLED.turnOn();
        } else if (distance < DISTANCE_THRESHOLD_LONG) {
          redLED.turnOn();
        } else {
          turnOffAll();
        }
      } else {
        Serial.println("Invalid Distance Reading.");
      }
    }

    void turnOffAll() {
      redLED.turnOff();
      greenLED.turnOff();
      yellowLED.turnOff();
    }
};