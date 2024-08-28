#include <arduino.h>
class LED {
  private:
    int pin;

  public:
    LED(int p) {
      pin = p;
      pinMode(pin, OUTPUT);
    }

    void turnOn() {
      digitalWrite(pin, HIGH);
    }

    void turnOff() {
      digitalWrite(pin, LOW);
    }
};
