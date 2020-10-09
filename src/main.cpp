#include <Arduino.h>
#include "../lib/FlexCAN_T4/FlexCAN_T4.h"

FlexCAN_T4<CAN0, RX_SIZE_256, TX_SIZE_16> Can0;
CAN_message_t msg;

const int ledPin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  Can0.begin();
  Can0.setBaudRate(1000000);
  msg.id = 20;
  for (uint8_t i = 0; i < 8; i++) {
    msg.buf[i] = i;
  }
}

void loop() {
  Can0.write(msg);
  digitalWrite(ledPin, !digitalRead(ledPin));

  delay(100);
}