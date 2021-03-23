/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/
#ifndef RailRoadCorssing_h
#define RailRoadCorssing_h

#include "IrSensor.h"


class RailRoadCorssing {

  private:
    int _totalSensor;
    IrSensor * _irSensorCrossing;

  public:
    RailRoadCorssing() {
    }

    void initRailRoadCorssingSensors(int totalSensor);
    void setRailRoadCorssingSensorPins(int blockNo, int startBlockSensorPin, int endBlockSensorPin);
    bool isTrainArriving(int blockNo);

    ~RailRoadCorssing() {
      for (int i = 0; i < _totalSensor; i++) {
        delete &_irSensorCrossing[i];
      }
      delete[] _irSensorCrossing;
    }
};


#endif
