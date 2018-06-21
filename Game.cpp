#include "Game.hpp"
#include "Servo.hpp"
#include "hwlib.hpp"
#include "IR_Sensor.hpp"
#include "Afst_Sensor.hpp"

void intruderProgram(){
    
}


void inswitch( int i, Servo servo0){
    switch(i){
        case 0 : servo0.turn_to_0();
        break;
        case 1 : servo0.turn_to_90();
        break;
        case 2 : servo0.turn_to_180();
        break;
    }
} 



void runGame(){
    namespace target = hwlib::target;
    IR_Sensor infra0 = create_IR_sensor();
    auto pin_Servo = hwlib::target::pin_out(hwlib::target::pins::d9);
    Servo servo0(pin_Servo);
    Afst_Sensor afstSensor0 = create_Afst_Sensor();
    auto seenLed = hwlib::target::pin_out(hwlib::target::pins::d5);
    int distance;



    while(true){
        for(unsigned int i =0; i<3; i++){
            hwlib::wait_ms(1000);
            inswitch(i ,servo0);
            hwlib::wait_ms(50);
            distance = afstSensor0.getDist();
            hwlib::cout<<distance<<hwlib::endl;
            hwlib::cout<< "Checking for person"<< hwlib::endl;
            afstSensor0.checkPerson(seenLed, infra0);
        }
    }
}


