#ifndef BUTTON_FINAL_H
#define BUTTON_FINAL_H

#include "mbed.h"

#define BT1 PH_0
#define BT2 PH_1
#define BT3 PC_15

#define LONG_CLICK 3000

#define CALLBACK_ONCLICK void (*call_onClick)(uint8_t)
#define CALLBACK_ONLONGCLICK void (*call_onLongClick)(uint8_t)

class Button
{
public:
	Button();
	void setOnClick(CALLBACK_ONCLICK);
	void setOnLongClick(CALLBACK_ONLONGCLICK)
	void checkButtonEvent();

private:
	CALLBACK_ONCLICK;
	CALLBACK_ONLONGCLICK;

	DigitalInput *buttonOne;
	DigitalInput *buttonTwo;
	DigitalInput *buttonThree;

	bool checkBtnOne;
	bool checkBtnTwo;
	bool checkBtnThree;

	Timer timeBtnOne;
	Timer timeBtnTwo;
	Timer timeBtnThree;
};


#endif
