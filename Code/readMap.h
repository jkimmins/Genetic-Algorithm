//Checks to see if this header has been defined yet
#ifndef READ_MAP_H
#define READ_MAP_H

//fstream library used to read the map file
#include <fstream>

//Creates a function which returns a pointer to a char and takes a pointer as a parameter
char* readMapFile(char* _tempArray)
{

	//Variables are declared/initialised
	char c;
	int i = 0;

	//Creates the file reader and opens the map file
	std::ifstream fileReader;
	fileReader.open("map.txt");

	//Checks to make sure the map file has been opened
	if (!fileReader.is_open())
	{
		std::cout << "Could not open file!" << '\n';
	}

	//While loop runs until the map file has been completely read
	while (!fileReader.eof())
	{
		//The current character is placed into a variable
		fileReader >> c;

		//If statement to check that the current character is a number, if it's not a number the character is ignored
		if (c >= '0' && c <= '9')
		{
			//If the character is a number it's placed into the array
			_tempArray[i] = c;
			i++;
		}
	}

	return _tempArray;

}

#endif
