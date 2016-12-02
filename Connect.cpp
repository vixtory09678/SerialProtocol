#include "Connect.h"

void Connect::setCallBack(CALL_BACK_RECIEVE){
	this->callback = callback;
}

void Connect::checkRecieveEvent(){
	int count = 0;
	while(call->readable()){
		call->read(buff,DATA_LENGTH,NULL);
		uint8_t checksum = 0;
		for(int i = 0; i < (DATA_LENGTH-1); i++){
			checksum += buff[i];
		}
		checksum = ~checksum;
		if(buff[DATA_LENGTH-1] == (checksum & 0xFF)){
			uint8_t topic = buff[0];
			int data = (buff[1] << 8) | (buff[2] & 0xFF);
			if(callback != NULL)
				callback(topic,data);
			else
				printf("error : callback function is NULL\n");
		}
			
	}
}

void Connect::begin(Serial *serialCall){
	this->call = serialCall;
}

void Connect::writeCommand(uint8_t topic,uint8_t *data,uint8_t length){
	uint8_t size = length+1+1; //length+topic+checksum
	uint8_t buff[size];
	buff[0] = topic;
	uint8_t checksum = topic;
	for (int i = 1; i <= length; i++){
		buff[i] = data[i-1];
		checksum+=buff[i];
	}
	checksum = (~checksum) & 0xFF;
	buff[sizeof(buff)-1] = checksum;
	call->write(buff,size,NULL);
	wait_ms(50);
}