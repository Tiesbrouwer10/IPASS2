#include "Game.hpp"
#include "Servo.hpp"
#include "hwlib.hpp"
#include "IR_Sensor.hpp"
#include "Afst_Sensor.hpp"
/// @file


/// \brief
/// Servo beweging swtich
/// \details
/// Deze functie geeft de mogelijkheid om met de aanroep een case mee te geven.
/// Deze case roeps vervolgends een functie aan die de meegegeven servo naar een vast punt verplaatst.
void inswitch( int i, Servo servo0){
    switch(i){
        case 0 : servo0.turn_to_0();
        break;
        case 1 : servo0.turn_to_90();
        break;
        case 2 : servo0.turn_to_180();
        break;
        case 3: servo0.turn_to_90();
        break; 
    }
} 


/// \brief
/// Game functie
/// \details
/// Deze functie vormt van de output van alle functies een werkende beveiligins robot.
/// De robot zal rond blijven kijken tot er een object binnen 500 meter te vinden is.
/// Zodra dit gebeurt roept de functie de intruderFound() functie aan.
void runGame(){
    namespace target = hwlib::target;
    IR_Sensor infra0 = create_IR_sensor();
    auto pin_Servo = hwlib::target::pin_out(hwlib::target::pins::d9);
    Servo servo0(pin_Servo);
    Afst_Sensor afstSensor0 = create_Afst_Sensor();
    auto seenLed = hwlib::target::pin_out(hwlib::target::pins::d5);
    int distance;
    


    while(true){
        for(unsigned int i =0; i<4; i++){
            hwlib::wait_ms(1000);
            inswitch(i ,servo0);
            hwlib::wait_ms(50);
            distance = afstSensor0.getDist();
            hwlib::cout<<distance<<hwlib::endl;
            hwlib::cout<< "Checking for person"<< hwlib::endl;
            if(distance <= 500 && distance >=0){
                afstSensor0.intruderFound(seenLed, infra0, distance);
            }
        }
    }
}



