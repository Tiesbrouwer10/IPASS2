#ifndef SERVO_HPP
#define SERVO_HPP

#include "hwlib.hpp"

class Servo{
private:
    hwlib::target::pin_out & pin_place;
public:
    Servo(hwlib::target::pin_out & pin_place):
       pin_place(pin_place)
       {}
       
    void turn_to_0();
    void turn_to_90();
    void turn_to_180();
    void full_Head_Turn();
};

Servo create_Servo();
    


#endif