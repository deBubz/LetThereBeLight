/*

To manage BH1750 Light Sensor Functions and Data Generation

========================================================================*/ 

#include <Wire.h>
#include <LightSensor.h>
#include <BH1750.h>
#include <HardwareSerial.h>


// ------------------------- Global ---------------------------------

BH1750 BHSensor;
LightSensorClass LightSensor;

// ------------------------- Functions ---------------------------------

void LightSensorClass::BHInit(){
    Wire.begin();
    BHSensor.begin();
}

float LightSensorClass::BHReadings(){
    return  (BHSensor.readLightLevel());
    // dtostrf(data, 3,0, a);
    // return a;
}

void LightSensorClass::BHReadingstoCharArr(char* a){
    float data =  (BHSensor.readLightLevel());
    if(data > 1000){
        dtostrf(999, 3,0, a);
    }
    else{
        dtostrf(data, 3,0, a);
    }
    //return a;
}

void LightSensorClass::BHPayloadReadings(char* a){ 
    //float readings[5]; // .5 sec
    float PLTotal = 0;
    float PLAverage;
    
    for(int i = 0; i < 6; i++){
        PLTotal += BHReadings();
        // nice one 
        // theres betterways to do this
        Serial.print(BHReadings());
        Serial.print(" added in = ");
        Serial.println(PLTotal);
        delay(100); // .1 sec
    }

    PLAverage = round(PLTotal/5);
    dtostrf(PLAverage, 3,0, a);
    //return a;
    //return 0;
}

void LightSensorClass::Read5(){
    Serial.print(BHReadings());
    delay(100);
    Serial.print(BHReadings());
    delay(100);
    Serial.print(BHReadings());
    delay(100);
    Serial.print(BHReadings());
    delay(100);
    Serial.print(BHReadings());
    delay(100);

}
// ------------------------- End ---------------------------------
