#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3); // RX, TX

char data;
int relayPin = 8;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

  BT.begin(9600);
}

void loop() {
  if (BT.available()) {
    data = BT.read();

    if (data == '1') {
      digitalWrite(relayPin, HIGH);
    }
    else if (data == '0') {
      digitalWrite(relayPin, LOW);
    }
  }
}
