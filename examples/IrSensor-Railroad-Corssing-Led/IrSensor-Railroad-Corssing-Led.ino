
#include "RailRoadCorssing.h"

#define NO_OF_CROSSING 3
#define BLOCK_1_LED 7
#define BLOCK_2_LED 6
#define BLOCK_3_LED 5

bool toogleFlag = false;


RailRoadCorssing railRoadCorssing;
void setup() {
  Serial.begin(9600);
  railRoadCorssing.initRailRoadCorssingSensors(NO_OF_CROSSING);
  railRoadCorssing.setRailRoadCorssingSensorPins(1, 13, 12);
  railRoadCorssing.setRailRoadCorssingSensorPins(2, 11, 10);
  railRoadCorssing.setRailRoadCorssingSensorPins(3, 9, 8);
  pinMode(BLOCK_1_LED, OUTPUT);
  pinMode(BLOCK_2_LED, OUTPUT);
  pinMode(BLOCK_3_LED, OUTPUT);
}

void loop() {
  delay(500);
  bool trainOnCorssing = railRoadCorssing.isTrainArriving(1);
  if (trainOnCorssing) {
    digitalWrite(BLOCK_1_LED, HIGH);
    delay(500);
    digitalWrite(BLOCK_1_LED, LOW);
  } else {
    digitalWrite(BLOCK_1_LED, LOW);
  }
  trainOnCorssing = railRoadCorssing.isTrainArriving(2);
  if (trainOnCorssing) {
    digitalWrite(BLOCK_2_LED, HIGH);
    delay(500);
    digitalWrite(BLOCK_2_LED, LOW);
  } else {
    digitalWrite(BLOCK_2_LED, LOW);
  }
  trainOnCorssing = railRoadCorssing.isTrainArriving(3);
  if (trainOnCorssing) {
    digitalWrite(BLOCK_3_LED, HIGH);
    delay(500);
    digitalWrite(BLOCK_3_LED, LOW);
  } else {
    digitalWrite(BLOCK_3_LED, LOW);
  }

}
