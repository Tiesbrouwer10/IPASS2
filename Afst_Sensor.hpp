#ifndef AFST_SENSOR_HPP
#define AFST_SENSOR_HPP
#include "hwlib.hpp"
#include "IR_Sensor.hpp"
///@file
class Afst_Sensor{
    hwlib::target::pin_out trigger;
    hwlib::target::pin_in echo;
public:
    /// \brief
    /// Distance sensor constructor
    /// \details
    /// This function functions as the contructor for when an Afst_Sensor object is created.
    /// Once an Afst_Sensor object is created, it will construct a Afst_Sensor with a trigger and an echo pin.
    Afst_Sensor(hwlib::target::pin_out &trigger, hwlib::target::pin_in &echo);

    /// \brief
    /// Distance return function
    /// \details
    /// This function returns its found distance in cm, when called for by a Afst_Sensor.
    int getDist();
    
    /// \brief
    /// Intruder Programm
    /// \details
    /// This function returns its found distance in cm, when called for by a Afst_Sensor.
    void intruderFound(hwlib::target::pin_out &seenLed, IR_Sensor &infra0, int distance);
};
    /// \brief
    /// Create Afst_Sensor Object
    /// \details
    /// This function will fabricate an Afst_Sensor on the pins (trigger : d6) and (echo : d7).
    Afst_Sensor create_Afst_Sensor();

#endif // AFST_SENSOR_HPP
