#include "IR_Sensor.hpp"
#include "hwlib.hpp"

//0 = 17738455;
//1 = 16724175;
//2 = 16718055;
//3 = 16743045;
//4 = 16716015;
//5 = 16726215;
//6 = 16734885;
//7 = 16728765;
//8 = 16730805;
//9 = 16732845;



IR_Sensor::IR_Sensor(hwlib::target::pin_in &IR_sen):
    IR_sen(IR_sen)
{}

bool IR_Sensor::signal(){
    return(IR_sen.get());
}

int IR_Sensor::knopIngedrukt(uint32_t code){
    while(true){
        if(code == 16738455){
            return 10;
        }
        if(code == 16724175){
            return 1;
        }
        if(code == 16718055){
            return 2;
        }
        if(code == 16743045){
            return 3;
        }
        if(code == 16716015){
            return 4;
        }
        if(code == 16726215){
            return 5;
        }
        if(code == 16734885){
            return 6;
        }
        if(code == 16728765){
            return 7;
        }
        if(code == 16730805){
            return 8;
        }
        if(code == 16732845){
            return 9;
        }
        else{
            return 0;
        
    }
    }
}


int IR_Sensor::output(){
    long long nu;
    long long dan;
    long long begin0;
    uint32_t code = 0;
    
    nu = (hwlib::now_us());
    while(!IR_sen.get()){
    hwlib::wait_us(2);
    }
    dan = (hwlib::now_us());            
    begin0 = dan-nu;
    if(begin0 > 8000 && begin0 <10000){
        nu = hwlib::now_us();
        while(IR_sen.get()){
        hwlib::wait_us(2);
        }
        dan = (hwlib::now_us());
        if((dan-nu)>4000){
            for(unsigned int i=0; i<32; i++){
                while(!IR_sen.get()){
                    hwlib::wait_us(2);
                }
                nu = hwlib::now_us();
                while(IR_sen.get()){
                    hwlib::wait_us(2);
                }
                dan = hwlib::now_us();
                if(dan-nu < 1000){
                    code = (code<<1);
                    code = (code|0);
                }
                if(dan-nu > 1000){
                    code = (code<<1);
                    code = (code|1);                        
                }
            }
        }
    }
    return knopIngedrukt(code);
}

IR_Sensor create_IR_sensor(){
    auto IR = hwlib::target::pin_in(hwlib::target::pins::d2);
    IR_Sensor infra0(IR);
    return infra0;
}
