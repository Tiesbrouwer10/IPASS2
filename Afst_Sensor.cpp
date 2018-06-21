#include "Afst_Sensor.hpp"
#include "hwlib.hpp"


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

void Afst_Sensor::checkPerson(hwlib::target::pin_out &seenLed, IR_Sensor &infra0){
    int distance;
    uint32_t code;
    distance = getDist();
    if(distance <= 500){
        hwlib::wait_ms(20);
        seenLed.set(1);
        hwlib::wait_ms(1000);
        hwlib::cout<< "Person seen"<< hwlib::endl;
        seenLed.set(0);
        while(infra0.signal()){
            hwlib::wait_us(2);
        }
        code = infra0.output();
        
        hwlib::cout<<code<<hwlib::endl;
            }
    }




Afst_Sensor create_Afst_Sensor(){
    auto trigger = hwlib::target::pin_out(hwlib::target::pins::d6);
    auto echo = hwlib::target::pin_in(hwlib::target::pins::d7);
    Afst_Sensor afstSensor0(trigger, echo);
    return afstSensor0;
}


