/*

To manage BH1750 Light Sensor Functions

========================================================================*/ 
#ifndef LightSensor_h
#define LightSensor_h

//#include <BH1750.h>
// ------------------------- Class ---------------------------------

class LightSensorClass
{
    public:
    void BHInit();
    float BHReadings(); 
        // as funct(parameter)  
        // char* a == char a[]
        // other context
        // char* a == pointer, char a[] == array ?? hmmm https://www.quora.com/What-is-the-difference-between-char*-and-char

    void BHReadingstoCharArr(char* a);
    void BHPayloadReadings(char* a);
    void Read5();

};

extern LightSensorClass LightSensor;

#endif

// ------------------------- End ---------------------------------