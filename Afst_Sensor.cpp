#include "Afst_Sensor.hpp"
#include "hwlib.hpp"
/// @file

/// \brief
/// Afstands sensor constructor
/// \details
/// Deze functie vormt van de output van alle functies een werkende beveiligins robot.
/// De robot zal rond blijven kijken tot er een object binnen 500 meter te vinden is.
/// Zodra dit gebeurt roept de functie de intruderFound() functie aan.
Afst_Sensor::Afst_Sensor(hwlib::target::pin_out &trigger, hwlib::target::pin_in &echo):
    trigger(trigger),
    echo(echo)
{}

 
int Afst_Sensor::getDist(){
    long long nu;
    long long dan;
    while(true){
        hwlib::wait_ms(50);
        trigger.set(0);
        hwlib::wait_us(2);
        trigger.set(1);
        hwlib::wait_us(10);
        trigger.set(0);
        hwlib::wait_ms(1);
        while(!echo.get()){
            hwlib::wait_us(2);
        }
        if(echo.get()){
            nu = (hwlib::now_us());
            while(echo.get()){
                hwlib::wait_us(0.4);
            }
            dan = (hwlib::now_us());
        }
        return (int)(dan-nu) /10;
    }
}

void Afst_Sensor::intruderFound(hwlib::target::pin_out &seenLed, IR_Sensor &infra0, int distance){
    int code;
    int secret;
    hwlib::cout<< "Person seen"<< hwlib::endl;;
    hwlib::wait_ms(20);
    seenLed.set(1);
    hwlib::wait_ms(2000);
    seenLed.set(0);
    secret = ((distance %10) + 1);
    hwlib::cout<<secret<<hwlib::endl;
    hwlib::wait_ms(2000);
    for(int j = 0; j < secret ; j++){
        hwlib::wait_ms(20);
        seenLed.set(1);
        hwlib::wait_ms(500);
        seenLed.set(0);
        hwlib::wait_ms(500);
        hwlib::cout<<"hoi" << j << hwlib::endl;
    }
    hwlib::wait_ms(20);
    code = 0;
    code = infra0.output();
    while(code != secret){
        hwlib::wait_us(20);
        code = infra0.output();
    }   
    hwlib::cout<<code<<hwlib::endl;
    hwlib::wait_ms(200);

}


Afst_Sensor create_Afst_Sensor(){
    auto trigger = hwlib::target::pin_out(hwlib::target::pins::d6);
    auto echo = hwlib::target::pin_in(hwlib::target::pins::d7);
    Afst_Sensor afstSensor0(trigger, echo);
    return afstSensor0;
}


