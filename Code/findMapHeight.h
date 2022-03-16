#ifndef FIND_MAP_HEIGHT
#define FIND_MAP_HEIGHT

//A function which takes an array and reads the second character, subtracts 48 from the ascii value and returns the number
const int findMapHeight(char* _tempArray)
{
	int height = _tempArray[1] - 48;
	return height;
}

#endif
