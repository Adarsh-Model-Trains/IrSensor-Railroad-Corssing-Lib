# IrSensor-Railroad-Corssing-Lib

---

# <a href="https://github.com/adarshkumarsingh83/IrSensor-Block-Detection-Lib/archive/production.zip"> Library download link </a>

## About the Lib
```
IrSensor-Railroad-Corssing-Lib is for supporing multiple Ir-Sensor bases railway crossing together 
in chain with less complexcity of the programming 

max we can connect any number of block till the arduino has input pins 2 pins per block 
this api support a simple interface where we can controll 1-N blocks for their occupancy and unoccupancy 

NOTE: block number will start from 1 to the nax number configured 

```


## Connections

![img](/images/connection.JPG)
```
+5v and gnd from arduino to the breadboard +ve and -ve common lines 
then supply the smae from breadboard of block 2 and block 3 till block N breadboard common +ve and -ve lines 

pin 13 to the out pin of Sensor start of the block1
pin 12 to the out pin of Sensor end of the block1

pin 11 to the out pin of Sensor start of the block2
pin 10 to the out pin of Sensor end of the block2

pin 9 to the out pin of Sensor start of the block3
pin 8 to the out pin of Sensor end of the block3

repeate the same till the blockN 

connect the jumper from +5v to the vcc of the all the IR sensors of block 1 block 2 and block 3 till block N 
connect the jumper from gnd to the gnd of the all the IR sensors of block 1 block 2 and block 3 till block N

```


## steps for using lib

## include the header file
```

#include "RailRoadCorssing.h"
```

## define the object for the RailRoadCorssing
```

RailRoadCorssing railRoadCorssing;

```

## define the number of the crossing we want 
```
#define NO_OF_CROSSING 3
```


## initialize the object with in setup method
*   railRoadCorssing.initRailRoadCorssingSensors(NO_OF_BLOCKS);
*   this will set the number os ir sensor corssing we cant to configure 
```
initRailRoadCorssingSensors() will take total nuber of signal crossing we want to configure 

void setup() {
  
   .....

  railRoadCorssing.initRailRoadCorssingSensors(NO_OF_BLOCKS);

  .......

}
```

## set the railway corssing starting ir sensor pin and end pins 
*    railRoadCorssing.setRailRoadCorssingSensorPins(RAILWAY_CROSSING_NO, RAILWAY_CROSSING_START_IR_SENSOR_PIN, RAILWAY_CROSSING_END_IR_SENSOR);
*    it will set the railway crossing starting ir sensor pin and crossing ending ir sensor  pin for particular crossing number 
```
setRailRoadCorssingSensorPins() will take crossing number followed by ir sensor pin which is at start of block and ir sensor pin which is at end of block 
void setup() {
  
   .....

  railRoadCorssing.setRailRoadCorssingSensorPins(1, 13, 12);
  railRoadCorssing.setRailRoadCorssingSensorPins(2, 11, 10);
  railRoadCorssing.setRailRoadCorssingSensorPins(3, 9, 8);

  .......

}
```

## for debug messages a initialize Serial in setup
```
void setup() {
  
  Serial.begin(xxxx); // xxx can be any valid supported number 

  .........
}

```

## use lib method for know the block state
* bool trainOnCorssing = railRoadCorssing.isTrainArriving(corssing_number);
* will return the if crossing is having train other wise false in all other cases 
```
void loop() {
  
  .......
  
   bool trainOnCorssing = railRoadCorssing.isTrainArriving(corssing_number);
  ..........
}
```

### Complete Example
```

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

```
