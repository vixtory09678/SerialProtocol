#ifndef SAVE_MELODY_H
#define SAVE_MELODY_H

#include "mbed.h"
#include <vector>

class SaveMelody
{
public:
	void addNote(int keyNote);
	int* getArrayNote(int* arrayNote);
	int getNode(int index);
	int sizeNote();
	uint8_t getSizeColum();
	uint8_t getSizeRow();
	void clear();
	bool isEmpty();

private:
	std::vector<int> keyNote;
};

#endif
