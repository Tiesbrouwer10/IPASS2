#include "hwlib.hpp"
#include "Servo.hpp"    
#include "Game.hpp"
#include "IR_Sensor.hpp"
#include "Afst_Sensor.hpp"

int main(){
    WDT->WDT_MR = WDT_MR_WDDIS;
    namespace target = hwlib::target;
    IR_Sensor infra0 = create_IR_sensor();
    uint32_t code = 0;
    runGame();
    
    while(true){
        if(!infra0.signal()){
            code = infra0.output();
            if(code != 10 && code!=0){
                hwlib::wait_ms(100);
                hwlib::cout<< code << hwlib::endl;
            }
        }
    }
    Afst_Sensor afstSensor0 = create_Afst_Sensor();
    
    
    while(true){
        int n = afstSensor0.getDist();
        hwlib::cout << n << hwlib::endl;
    }
}


    
    
    
    
    
    
    
    
    
    
    
    
 
    
 
 
    