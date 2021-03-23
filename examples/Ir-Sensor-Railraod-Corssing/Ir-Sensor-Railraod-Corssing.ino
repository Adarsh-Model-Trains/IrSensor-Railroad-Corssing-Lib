
#include "RailRoadCorssing.h"

#define NO_OF_CROSSING 3

RailRoadCorssing railRoadCorssing;
void setup() {
  Serial.begin(9600);
  railRoadCorssing.initRailRoadCorssingSensors(NO_OF_BLOCKS);
  railRoadCorssing.setRailRoadCorssingSensorPins(1, 13, 12);
  railRoadCorssing.setRailRoadCorssingSensorPins(2, 11, 10);
  railRoadCorssing.setRailRoadCorssingSensorPins(3, 9, 8);
}

void loop() {
  delay(1000);
  for (int i = 1; i <= NO_OF_CROSSING; i++) {
    bool trainOnCorssing = railRoadCorssing.isTrainArriving(i);
    Serial.print("Corssing no  ");
    Serial.print(i);
    Serial.print("  isTrainOnCrossing  ");
    Serial.println(trainOnCorssing);
  }

}
