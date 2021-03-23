/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/

#include <Arduino.h>
#include "RailRoadCorssing.h"

void RailRoadCorssing::initRailRoadCorssingSensors(int totalSensor) {
  if (totalSensor > 0) {
    if (totalSensor > 0)
      _totalSensor = totalSensor;
    this->_irSensorCrossing = new IrSensor[_totalSensor];
    for (int i = 0; i < _totalSensor; i++) {
      this->_irSensorCrossing[i].setStartAndEndBlockSensorPin(0, 0);
    }
  } else {
    Serial.println("Invalid Crossing Count");
  }
}

void RailRoadCorssing::setRailRoadCorssingSensorPins(int blockNo, int startBlockSensorPin, int endBlockSensorPin) {
  if (blockNo > -1 && blockNo <= _totalSensor ) {
    if (startBlockSensorPin > -1 && endBlockSensorPin > -1) {
      pinMode(startBlockSensorPin, INPUT);
      pinMode(endBlockSensorPin, INPUT);
      _irSensorCrossing[blockNo - 1].setStartAndEndBlockSensorPin(startBlockSensorPin, endBlockSensorPin);
    } else {
      Serial.println("Invalid Crossing Sensor Pin No.");
    }
  } else {
    Serial.println("Invalid Crossing Sensor Input No.");
  }
}

bool RailRoadCorssing::isTrainArriving(int blockNo) {
  if (blockNo > -1 && blockNo <= _totalSensor) {
    return _irSensorCrossing[blockNo - 1].isBlockOccupied();
  } else {
    Serial.println("Invalid Crossing Sensor No");
    return false;
  }
}
