#include "mbed"
#include "Connect.h"

#define MODE_1 1
#define MODE_2 2

Serial serial(D8,D2); //txrx

Connect connect;
Timer timer;
void onDataRecieve(uint8_t topic, int data){

}

int main(){
	connect.begin(&serial);
	connect.setCallBack(onDataRecieve);
	while(1){
		connect.writeCommand(MODE_1,500);
		connect.checkRecieveEvent();
	}
}