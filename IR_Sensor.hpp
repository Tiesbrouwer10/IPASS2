#ifndef IR_SENSOR_HPP
#define IR_SENSOR_HPP
#include "hwlib.hpp"
///@file

class IR_Sensor{
private:
    hwlib::target::pin_in IR_sen;
    
public:
    /// \brief
    /// IR_Sensor constructor
    /// \details
    /// This function functions as the constructor for when an IR_Sensor object is created.
    IR_Sensor(hwlib::target::pin_in &IR_sen);
    
    /// \brief
    /// IR_Sensor Signal detector
    /// \details
    /// This function will return a 0 if the IR_Sensor has no input signal, and a 1 if the IR_Sensor does have an input signal.
    bool signal();
    
    /// \brief
    /// IR_Sensor output
    /// \details
    /// This function follows the standard NEC Infrared Transmission Protocol.
    /// It will return the value of the 32 bits send after the first 9ms activation bit.
    int output();
    
    /// \brief
    /// Button press function (CR2025)
    /// \details
    /// This function is only to be used for the CR2025.
    /// This function asks for an uint32_t parameter. it will use this to determine which digit button was pressed on the remote.
    int button_Pressed(uint32_t code);

};
    /// \brief
    /// Create IR_Sensor Object
    /// \details
    /// When called, this function will create an IR_Sensor with the data pin in D2.
IR_Sensor create_IR_sensor();

#endif // IR_SENSOR_HPP
