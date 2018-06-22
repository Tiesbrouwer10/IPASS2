#include "hwlib.hpp"
#include "Servo.hpp"    
#include "Game.hpp"
#include "IR_Sensor.hpp"
#include "Afst_Sensor.hpp"
#include "catch.hpp"
/// @file
/// \brief
/// Main codefile
/// \details
/// Deze file killed eerst de watchdog en roept daarna de functie voor de game aan die de rest van de library een functie geeft.
int main(){
    WDT->WDT_MR = WDT_MR_WDDIS;
    //servo op d9
    //afstand sensor op trigger: d6 en echo: d7
    //IR sensor op d2
    //leds op d5
    runGame();
    

}


    
    
    
    
    
    
    
    
    
    
    
    
 
    
 
 
    
