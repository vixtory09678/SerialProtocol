#include "SaveMelody.h"

void SaveMelody::addNote(int key){
	keyNote.push_back(key);
}

bool SaveMelody::getArrayNote(int* arrayNote,int size){
	if(size <= sizeNote()){
		for(int i = 0;i < size;i++){
			arrayNote[i] = getNote(i);
		}
		return true;
	}
	return false;
}

int SaveMelody::getNote(int index){
	return keyNote.at(index);
}

uint8_t SaveMelody::getSizeRow(){
	return (uint8_t)((sizeNote()-1)/8) + 1;
}

uint8_t SaveMelody::getSizeColumn(int currentRow){
	if(currentRow == 0||currentRow > getSizeRow()){
		return 0;
	}
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

vector<int> SaveMelody::getInstance(){
	return keyNote;
}

void SaveMelody::copy(vector<int> instance){
	keyNote.swap(instance);
}

