#ifndef SAVE_MELODY_H
#define SAVE_MELODY_H

#include "mbed.h"
#include <vector>

class SaveMelody
{
public:
	void addNote(int key);
	bool getArrayNote(int* arrayNote,int size);
	int getNote(int index);
	int sizeNote();
	uint8_t getSizeColumn(int);
	uint8_t getSizeRow();
	void clear();
	bool isEmpty();

private:
	vector<int> keyNote;
};

#endif
