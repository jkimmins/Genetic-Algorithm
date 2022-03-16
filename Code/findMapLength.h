#ifndef FIND_MAP_LENGTH_H
#define FIND_MAP_LENGTH_H

//A function which takes an array and reads the first character, subtracts 48 from the ascii value and returns the number
const int findMapLength(char* _tempArray)
{
	int length = _tempArray[0] - 48;
	return length;
}

#endif
