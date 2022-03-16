#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "findCost.h"
#include "findMapHeight.h"
#include "findMapLength.h"
#include "node.h"
#include "readMap.h"

float path(Node _startNode, Node _goalNode, std::vector<int> chromosome, int _length, int _maxX, int _maxY, std::vector<std::vector<int> > &_map);
bool valid1(int _x, int _y, int _maxX, int _maxY, std::vector<std::vector<int> > &_map);
bool valid2(int _x, int _y, int _maxX, int _maxY, std::vector<std::vector<int> > &_map);

int main()
{
	//Starts timer
	auto start = std::chrono::high_resolution_clock::now();

	//Creates a temporary array for the map to be placed in before it can become a 2D array
	char tempArray[100];

	//Places the map file into the previously created array
	char *tempArrayPointer = readMapFile(tempArray);

	//variables declared and initialised
	int length = findMapLength(tempArray);
	int height = findMapHeight(tempArray);
	int maxX = length - 1;
	int maxY = height - 1;
	int holder = 2;
	int roll;
	bool goal = false;
	bool f1s, f2s, f3s, f4s, f5s, f6s, f7s, f8s;
	int generation = 1;
	char exit;

	//Nodes declared
	Node startNode;
	Node goalNode;
	Node currentNode;

	//Map 2d vector delcared
	std::vector<std::vector<int> > map(height, std::vector<int>(length));

	//Place map into 2d vector
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < length; x++)
		{
			map[y][x] = tempArray[holder] - 48;

			if (map[y][x] == 2)
			{
				startNode.x = x;
				startNode.y = y;
			}

			if (map[y][x] == 3)
			{
				goalNode.x = x;
				goalNode.y = y;
			}
			std::cout << map[y][x];
			holder++;
		}
		std::cout << '\n';
	}

	//Find max moves required
	int cLength = maxX * maxY;

	//Chromosome and parent vectors created
	std::vector<int> chromosome1;
	std::vector<int> chromosome2;
	std::vector<int> chromosome3;
	std::vector<int> chromosome4;
	std::vector<int> chromosome5;
	std::vector<int> chromosome6;
	std::vector<int> chromosome7;
	std::vector<int> chromosome8;

	std::vector<std::vector<int> > parents;
	std::vector<std::vector<int> > parents2;
	std::vector<int> tempVec1;
	std::vector<int> tempVec2;
	std::vector<int> tempVec3;
	std::vector<int> tempVec4;

	float fit1, fit2, fit3, fit4, fit5, fit6, fit7, fit8;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	static std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(0, 7);

	//For loop populates the 1st generation chromosomes 
	for (int k = 0; k < cLength; k++)
	{
		roll = distribution(generator);
		chromosome1.push_back(roll);

		roll = distribution(generator);
		chromosome2.push_back(roll);

		roll = distribution(generator);
		chromosome3.push_back(roll);

		roll = distribution(generator);
		chromosome4.push_back(roll);

		roll = distribution(generator);
		chromosome5.push_back(roll);

		roll = distribution(generator);
		chromosome6.push_back(roll);

		roll = distribution(generator);
		chromosome7.push_back(roll);

		roll = distribution(generator); 
		chromosome8.push_back(roll);
	}

	//Runs until the goal has been found
	while (goal != true)
	{
		//Runs the path function and checks to see if the goal has been found, is repeated for every chromosome
		fit1 = path(startNode, goalNode, chromosome1, cLength, maxX, maxY, map) * 100;
		if (fit1 == 100)
		{
			goal = true;
		}
		f1s = false;
		fit2 = path(startNode, goalNode, chromosome2, cLength, maxX, maxY, map) * 100;
		if (fit2 == 100)
		{
			goal = true;
		}
		f2s = false;
		fit3 = path(startNode, goalNode, chromosome3, cLength, maxX, maxY, map) * 100;
		if (fit3 == 100)
		{
			goal = true;
		}
		f3s = false;
		fit4 = path(startNode, goalNode, chromosome4, cLength, maxX, maxY, map) * 100;
		if (fit4 == 100)
		{
			goal = true;
		}
		f4s = false;
		fit5 = path(startNode, goalNode, chromosome5, cLength, maxX, maxY, map) * 100;
		if (fit5 == 100)
		{
			goal = true;
		}
		f5s = false;
		fit6 = path(startNode, goalNode, chromosome6, cLength, maxX, maxY, map) * 100;
		if (fit6 == 100)
		{
			goal = true;
		}
		f6s = false;
		fit7 = path(startNode, goalNode, chromosome7, cLength, maxX, maxY, map) * 100;
		if (fit7 == 100)
		{
			goal = true;
		}
		f7s = false;
		fit8 = path(startNode, goalNode, chromosome1, cLength, maxX, maxY, map) * 100;
		if (fit8 == 100)
		{
			goal = true;
		}
		f8s = false;

		
		int i = 0;
		//While loop is used to select parents (chromosomes with higher fitness have higher chance of being chosen)
		while (i != 4)
		{
			unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
			static std::default_random_engine generator(seed);
			std::uniform_int_distribution<int> distribution(0, fit1 + fit2 + fit3 + fit4 + fit5 + fit6 + fit7 + fit8);
			roll = distribution(generator);
			if (roll < fit1)
			{
				if (f1s == false)
				{
					parents.push_back(chromosome1);
					f1s = true;
					i++;
				}
			}
			if (roll >= fit1 && roll < (fit1 + fit2))
			{
				if (f2s == false)
				{
					parents.push_back(chromosome2);
					f2s = true;
					i++;
				}
			}
			if (roll >= (fit1 + fit2) && roll < (fit1 + fit2 + fit3))
			{
				if (f3s == false)
				{
					parents.push_back(chromosome3);
					f3s = true;
					i++;
				}
			}
			if (roll >= (fit1 + fit2 + fit3) && roll < (fit1 + fit2 + fit3 + fit4))
			{
				if (f4s == false)
				{
					parents.push_back(chromosome4);
					f4s = true;
					i++;
				}
			}
			if (roll >= (fit1 + fit2 + fit3 + fit4) && roll < (fit1 + fit2 + fit3 + fit4 + fit5))
			{
				if (f5s == false)
				{
					parents.push_back(chromosome5);
					f5s = true;
					i++;
				}
			}
			if (roll >= (fit1 + fit2 + fit3 + fit4 + fit5) && roll < (fit1 + fit2 + fit3 + fit4 + fit5 + fit6))
			{
				if (f6s == false)
				{
					parents.push_back(chromosome6);
					f6s = true;
					i++;
				}
			}
			if (roll >= (fit1 + fit2 + fit3 + fit4 + fit5 + fit6) && roll < (fit1 + fit2 + fit3 + fit4 + fit5 + fit6 + fit7))
			{
				if (f7s == false)
				{
					parents.push_back(chromosome7);
					f7s = true;
					i++;
				}
			}
			if (roll >= (fit1 + fit2 + fit3 + fit4 + fit5 + fit6 + fit7) && roll < (fit1 + fit2 + fit3 + fit4 + fit5 + fit6 + fit7 + fit8))
			{
				if (f8s == false)
				{
					parents.push_back(chromosome8);
					f8s = true;
					i++;
				}
			}
		}

		parents2 = parents;

		//If the goal has not been found the parents 'breed'
		if (goal != true)
		{
			tempVec1.clear();
			tempVec2.clear();
			tempVec3.clear();
			tempVec4.clear();

			//Numbers are oushed into temporary vectors
			for (int i = 4; i < 8; i++)
			{
				tempVec1.push_back(parents[0][i]);
				tempVec2.push_back(parents[1][i]);
				tempVec3.push_back(parents[2][i]);
				tempVec4.push_back(parents[3][i]);
			}
			//Same number are popped from the parents
			for (int i = 0; i < 4; i++)
			{
				parents[0].pop_back();
				parents[1].pop_back();
				parents[2].pop_back();
				parents[3].pop_back();
			}
			//Number are placed into new parents
			for (int i = 0; i < 4; i++)
			{
				parents[0].push_back(tempVec2[i]);
				parents[1].push_back(tempVec1[i]);
				parents[2].push_back(tempVec4[i]);
				parents[3].push_back(tempVec3[i]);
			}

			//Temp vectors are cleared to be used again
			tempVec1.clear();
			tempVec2.clear();
			tempVec3.clear();
			tempVec4.clear();

			//Previous process is repeated for second set of parents
			for (int i = 4; i < 8; i++)
			{
				tempVec1.push_back(parents2[0][i]);
				tempVec2.push_back(parents2[1][i]);
				tempVec3.push_back(parents2[2][i]);
				tempVec4.push_back(parents2[3][i]);
			}
			for (int i = 0; i < 4; i++)
			{
				parents2[0].pop_back();
				parents2[1].pop_back();
				parents2[2].pop_back();
				parents2[3].pop_back();
			}
			for (int i = 0; i < 4; i++)
			{
				parents2[0].push_back(tempVec3[i]);
				parents2[1].push_back(tempVec4[i]);
				parents2[2].push_back(tempVec1[i]);
				parents2[3].push_back(tempVec2[i]);
			}
			//Numbers are placed randomly to create new chromosomes
			std::uniform_int_distribution<int> distribution(0, 7);
			for (int i = 0; i < parents[0].size(); i++)
			{
				chromosome1[distribution(generator)] = parents[0][i];
				chromosome2[distribution(generator)] = parents[1][i];
				chromosome3[distribution(generator)] = parents[2][i];
				chromosome4[distribution(generator)] = parents[3][i];
				chromosome5[distribution(generator)] = parents2[0][i];
				chromosome6[distribution(generator)] = parents2[1][i];
				chromosome7[distribution(generator)] = parents2[2][i];
				chromosome8[distribution(generator)] = parents2[3][i];
			}
			//Parent vectors cleared for next loop
			parents.clear();
			parents2.clear();
		}
		generation += 1;
	}	

	std::cout << "Generation: " << generation << '\n';
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Time taken (microseconds): " << duration.count() << '\n';
	std::cout << "Press any key to exit: ";
	std::cin.get() >> exit;
	return 0;
}

float path(Node _startNode, Node _goalNode, std::vector<int> _chromosome, int _length, int _maxX, int _maxY, std::vector<std::vector<int> > &_map)
{
	//Nodes and variables declared and initialised
	Node currentNode = _startNode;
	int fitMod = 0;
	float fit;

	//For loop runs through the chromosome
	for (int i = 0; i < _length; i++)
	{
		//Chromosome instruction is followed and if it's valid the algorithm moves to that space, if the instruction leads to an obstacle or outside the map the chromosome is penalised through the fitMod variable
		if (_chromosome[i] == 0)
		{
			//Up-Left -1 -1
			if (valid1(currentNode.x - 1, currentNode.y - 1, _maxX, _maxY, _map) == false)
			{
				fitMod += 1;
			}
			else
			{
				if (valid2(currentNode.x - 1, currentNode.y - 1, _maxX, _maxY, _map) == true)
				{
					currentNode.x -= 1;
					currentNode.y -= 1;
				}
				else
				{
					fitMod += 1;
				}
			}
		}

		if (_chromosome[i] == 1)
		{
			//Up 0 -1
			if (valid1(currentNode.x, currentNode.y - 1, _maxX, _maxY, _map) == false)
			{
				fitMod += 1;
			}
			else
			{
				if (valid2(currentNode.x, currentNode.y - 1, _maxX, _maxY, _map) == true)
				{
					currentNode.y -= 1;
				}
				else
				{
					fitMod += 1;
				}
			}
		}

		if (_chromosome[i] == 2)
		{
			//Up-Right +1 -1

			if (valid1(currentNode.x + 1, currentNode.y - 1, _maxX, _maxY, _map) == false)
			{
				fitMod += 1;
			}
			else
			{
				if (valid2(currentNode.x + 1, currentNode.y - 1, _maxX, _maxY, _map) == true)
				{
					currentNode.x += 1;
					currentNode.y -= 1;
				}
				else
				{
					fitMod += 1;
				}
			}
		}

		if (_chromosome[i] == 3)
		{
			//Left -1 0
			if (valid1(currentNode.x - 1, currentNode.y, _maxX, _maxY, _map) == false)
			{
				fitMod += 1;
			}
			else
			{
				if (valid2(currentNode.x - 1, currentNode.y, _maxX, _maxY, _map) == true)
				{
					currentNode.x -= 1;
				}
				else
				{
					fitMod += 1;
				}
			}
		}

		if (_chromosome[i] == 4)
		{
			//Right +1
			if (valid1(currentNode.x + 1, currentNode.y, _maxX, _maxY, _map) == false)
			{
				fitMod += 1;
			}
			else
			{
				if (valid2(currentNode.x + 1, currentNode.y, _maxX, _maxY, _map) == true)
				{
					currentNode.x += 1;
				}
				else
				{
					fitMod += 1;
				}
			}
		}

		if (_chromosome[i] == 5)
		{
			//Bottom-Left
			if (valid1(currentNode.x - 1, currentNode.y + 1, _maxX, _maxY, _map) == false)
			{
				fitMod += 1;
			}
			else
			{
				if (valid2(currentNode.x - 1, currentNode.y + 1, _maxX, _maxY, _map) == true)
				{
					currentNode.x -= 1;
					currentNode.y += 1;
				}
				else
				{
					fitMod += 1;
				}
			}
		}

		if (_chromosome[i] == 6)
		{
			//Bottom 0 +1
			if (valid1(currentNode.x, currentNode.y + 1, _maxX, _maxY, _map) == false)
			{
				fitMod += 1;
			}
			else
			{
				if (valid2(currentNode.x, currentNode.y + 1, _maxX, _maxY, _map) == true)
				{
					currentNode.y += 1;
				}
				else
				{
					fitMod += 1;
				}
			}
		}

		if (_chromosome[i] == 7)
		{
			//Bottom-Right +1 +1
			if (valid1(currentNode.x + 1, currentNode.y + 1, _maxX, _maxY, _map) == false)
			{
				fitMod += 1;
			}
			else
			{
				if (valid2(currentNode.x + 1, currentNode.y + 1, _maxX, _maxY, _map) == true)
				{
					currentNode.x += 1;
					currentNode.y += 1;
				}
				else
				{
					fitMod += 1;
				}
			}
		}

		//Checks to see if the goal node has been found and makes sure that the path hasn't hit any obstacles or taken too long
		if (currentNode.x == _goalNode.x && currentNode.y == _goalNode.y && fitMod == 0 && i+1 > findCost(_startNode, _goalNode))
		{
			//Following code prints out the directions the chromosome took to reach the goal
			std::cout << "Goal Found!" << '\n';
			fit = 1;
			std::cout << "From the starting point (2) move:" << '\n';
			for (int k = 0; k <= i; k++)
			{
				if (_chromosome[k] == 0)
				{
					std::cout << "Up and Left" << '\n';
				}
				if (_chromosome[k] == 1)
				{
					std::cout << "Up" << '\n';
				}
				if (_chromosome[k] == 2)
				{
					std::cout << "Up and Right" << '\n';
				}
				if (_chromosome[k] == 3)
				{
					std::cout << "Left" << '\n';
				}
				if (_chromosome[k] == 4)
				{
					std::cout << "Right" << '\n';
				}
				if (_chromosome[k] == 5)
				{
					std::cout << "Down and Left" << '\n';
				}
				if (_chromosome[k] == 6)
				{
					std::cout << "Down" << '\n';
				}
				if (_chromosome[k] == 7)
				{
					std::cout << "Down and Right" << '\n';
				}
			}
			std::cout << '\n';
			return fit;
		}
	}
	//Following code works out the fitness of the chromosome and returns it
	currentNode.cost = findCost(currentNode, _goalNode);
	fit = 1.0 / ((float)currentNode.cost + (float)fitMod + 1.0);
	fit = roundf(fit * 100) / 100;
		
	return fit;
}

bool valid1(int _x, int _y, int _maxX, int _maxY, std::vector<std::vector<int> > &_map)
{
	//Checks to see if the chromosome moves out of bounds
	if (_x < 0 || _x > _maxX || _y < 0 || _y >> _maxY)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool valid2(int _x, int _y, int _maxX, int _maxY, std::vector<std::vector<int> > &_map)
{
	//Checks to see if the chromosome moves into an obstacle
	if (_x < 0 || _x > _maxX || _y < 0 || _y > _maxY)
	{
		return false;
	}
	else
	{
		if (_map[_y][_x] == 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}



}