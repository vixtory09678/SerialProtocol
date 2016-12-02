#ifndef CONNECT_H
#define CONNECT_H

#include "mbed.h"

#define DEBUG(message) printf(message)
#define DATA_LENGTH 4
#define CALL_BACK_RECIEVE void (*callback) (uint8_t topic ,int data)

class Connect
{
public:
	void begin(Serial *serialCall);
	void setCallBack(CALL_BACK_RECIEVE);
	void checkRecieveEvent();
	void writeCommand(uint8_t topic , uint8_t *data , uint8_t length);

private:
	CALL_BACK_RECIEVE;
	Serial *call;
	uint8_t buff[DATA_LENGTH];
};


#endif