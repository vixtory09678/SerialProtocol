#include "button.h"

Button::Button(){
	buttonOne = new DigitalInput(BT1);
	buttonTwo = new DigitalInput(BT2);
	buttonThree = new DigitalInput(BT3);

	checkBtnOne = false;
	checkBtnTwo = false;
	checkBtnThree = false;

	timeBtnOne.start();
	timeBtnTwo.start();
	timeBtnThree.start();
}

void Button::setOnClick(CALLBACK_ONCLICK){
	this->call_onClick = call_onClick;
}

void Button::setOnLongClick(CALLBACK_ONLONGCLICK){
	this->call_onLongClick = call_onLongClick;
}

void Button::checkButtonEvent(){
	if(buttonOne == 1){
		if(!checkBtnOne){
			timeBtnOne.reset();
			checkBtnOne = true;
		}
		if(timeBtnOne.read_ms() > LONG_CLICK){
			//onLongClick
			if(call_onLongClick != NULL){
				call_onLongClick(1);
			}
			checkBtnOne = false;
		}
	}else{
		if(timeBtnOne.read_ms() < LONG_CLICK){
			if(checkBtnOne){
				//onClick
				if(call_onClick != NULL){
					call_onClick(1);
				}
				checkBtnOne = false;
			}
		}
	}

	if(buttonTwo == 1){
		if(!checkBtnTwo){
			timeBtnTwo.reset();
			checkBtnTwo = true;
		}
		if(timeBtnTwo.read_ms() > LONG_CLICK){
			//onLongClick
			checkBtnTwo = false;
		}
	}else{
		if(timeBtnTwo.read_ms() < LONG_CLICK){
			if(checkBtnTwo){
				//onClick
				if(call_onClick != NULL){
					call_onClick(2);
				}
				checkBtnTwo = false;
			}
		}
	}

	if(buttonThree == 1){
		if(!checkBtnThree){
			timeBtnThree.reset();
			checkBtnThree = true;
		}
		if(timeBtnThree.read_ms() > LONG_CLICK){
			//onLongClick
			checkBtnThree = false;
		}
	}else{
		if(timeBtnThree.read_ms() < LONG_CLICK){
			if(checkBtnThree){
				//onClick
				if(call_onClick != NULL){
					call_onClick(3);
				}
				checkBtnThree = false;
			}
		}
	}


}
