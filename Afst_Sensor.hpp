#ifndef AFST_SENSOR_HPP
#define AFST_SENSOR_HPP
#include "hwlib.hpp"
#include "IR_Sensor.hpp"

class Afst_Sensor{
    hwlib::target::pin_out trigger;
    hwlib::target::pin_in echo;
public:
    Afst_Sensor(hwlib::target::pin_out &trigger, hwlib::target::pin_in &echo);

    int getDist();
    void intruderFound(hwlib::target::pin_out &seenLed, IR_Sensor &infra0, int distance);
};
    Afst_Sensor create_Afst_Sensor();

#endif // AFST_SENSOR_HPP
