#ifndef IR_SENSOR_HPP
#define IR_SENSOR_HPP
#include "hwlib.hpp"
class IR_Sensor{
private:
    hwlib::target::pin_in IR_sen;
    
public:
    IR_Sensor(hwlib::target::pin_in &IR_sen);
    bool signal();
    int output();
    int knopIngedrukt(uint32_t code);

};

IR_Sensor create_IR_sensor();

#endif // IR_SENSOR_HPP
