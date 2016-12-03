#include "SaveMelody.h"

void SaveMelody::addNote(int keyNote){
	keyNote.push_back(keyNote);
}

bool SaveMelody::getArayNote(int* arrayNote,int size){
	if(size <= sizeNote){
		for(int i = 0;i < sizeNote();i++){
			arrayNote++ = getNote(i);
		}
		return true;
	}
	return false;
}

int SaveMelody::getNote(int index){
	return keyNote.get(index);
}

uint8_t SaveMelody::getSizeRow(){
	return (uint8_t)(sizeNote()-1/8) + 1;
}

uint8_t SaveMelody::getSizeColom(uint8_t currentRow){
	if(currentRow == 0||currentRow>getSizeRow)
		return 0
	if(currentRow < getSizeRow()){
		return 8;
	}else if(currentRow == getSizeRow()){
		return sizeNote()-((getSizeRow()-1)*8);
	}
}

bool SaveMelody::isEmpty(){
	return keyNote.empty();
}

void SaveMelody::clear(){
	keyNote.clear();
}

int SaveMelody::sizeNote(){
	return keyNote.size();
}
