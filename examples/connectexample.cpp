#include "mbed.h"
#include "Connect.h"

#define MODE_1 0
#define MODE_2 1

#define SENSOR_1 0
#define SENSOR_2 1

Serial serial(D8,D2); //txrx

Connect connect;
Timer timer;
void onDataRecieve(uint8_t topic, int data){

}

uint8_t* splitInt(uint16_t data){
    uint8_t buff[2];
    buff[0] = (data >> 8) & 0xFF;
    buff[1] = (data & 0xFF);
    return buff;   
}

int main(){
    connect.begin(&serial);
    connect.setCallBack(onDataRecieve);
    while(1){
        connect.writeCommand(connect.setMode(MODE_1,SENSOR_1);,splitInt(500),sizeof(uint16_t));
        connect.checkRecieveEvent();
    }
}
