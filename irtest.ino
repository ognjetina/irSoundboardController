#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

uint16_t RECV_PIN = 4;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn();
  while (!Serial)
    delay(50);
}

void loop() {

  if (irrecv.decode(&results)) {
    if (uint64ToString(results.value).equals("33441975")) {
      MIDImessage(1, 1, 100);
    }
    if (uint64ToString(results.value).equals("33446055")) {
      MIDImessage(2, 1, 100);
    }
    if (uint64ToString(results.value).equals("33454215")) {
      MIDImessage(3, 1, 100);
    }
    if (uint64ToString(results.value).equals("33456255")) {
      MIDImessage(4, 1, 100);
    }
    if (uint64ToString(results.value).equals("33439935")) {
      MIDImessage(5, 1, 100);
    }
    if (uint64ToString(results.value).equals("33472575")) {
      MIDImessage(6, 1, 100);
    }
    if (uint64ToString(results.value).equals("33431775")) {
      MIDImessage(7, 1, 100);
    }
    if (uint64ToString(results.value).equals("33464415")) {
      MIDImessage(8, 1, 100);
    }
    if (uint64ToString(results.value).equals("33448095")) {
      MIDImessage(9, 1, 100);
    }
    irrecv.resume();  // Receive the next value
  }
  delay(100);
}

void MIDImessage(int command, int MIDInote, int MIDIvelocity) {
  Serial.write(command);//send note on or note off command
  Serial.write(MIDInote);//send pitch data
  Serial.write(MIDIvelocity);//send velocity data
}
