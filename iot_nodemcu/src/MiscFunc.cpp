
/*  C++ file

To manage Misc String formatting functions

========================================================================*/ 

#include<Arduino.h>
#include<LightSensor.h>
#include <MiscFunc.h>

// ------------------------- global Declaraions -------------------------
MiscFuncClass MiscFunc;

const int green   = D5;
const int yellow  = D6;
const int red     = D7;


// ------------------------- Functions ---------------------------------
void MiscFuncClass::testFunc(){
     Serial.print("Something Header File");
}

void MiscFuncClass::concatCharArr(char a[], char b[]){ //concat b to a
    int x = 0;
    int y = 0;


    while(a[x] != '\0'){
        x++;
    } 
    while(b[y] != '\0'){
        a[x] = b[y];
        x++; y++;
    }   
    a[x] = '\0';
}

void MiscFuncClass::LEDInit(){ //init led pins
    pinMode(green,OUTPUT);
    pinMode(yellow,OUTPUT);
    pinMode(red,OUTPUT); 
}

void MiscFuncClass::LEDLoading(int time){ 
    digitalWrite(red,0);
    digitalWrite(green,1); 
    delay(time);
    digitalWrite(green,0);  
    digitalWrite(yellow,1); 
    delay(time);
    digitalWrite(yellow,0);   
    digitalWrite(red,1); 
    delay(time);
}


// could pass the OBJ as a param instead of importing the Light Lib
void MiscFuncClass::LEDonRange() // led on if value is 
{
      if(LightSensor.BHReadings() > 250){
      digitalWrite(red,0);
      digitalWrite(yellow,0);
      digitalWrite(green,1);
    } else if(LightSensor.BHReadings() > 100 && LightSensor.BHReadings() < 250){
      digitalWrite(red,0);
      digitalWrite(yellow,1);
      digitalWrite(green,0);
    } else{
      digitalWrite(red,1);
      digitalWrite(yellow,0);
      digitalWrite(green,0);
    }

    Serial.print("Light testing ");
    Serial.println(LightSensor.BHReadings());
}



// ------------------------- End ---------------------------------