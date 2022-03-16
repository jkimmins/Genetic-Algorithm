#ifndef FIND_COST_H
#define FIND_COST_H

#include "node.h"

//function takes the current node and the goal node
int findCost(Node _current, Node _goal)
{
	//variables initialised and declared
	int xDifGoal, yDifGoal;
	int cost = 0;

	//Used to find which node has the highest x value to make calculations simpler
	if (_current.x > _goal.x)
	{
		xDifGoal = _current.x - _goal.x;
	}
	else
	{
		xDifGoal = _goal.x - _current.x;
	}

	//Used to find which node has the highest y value to make calculations simpler
	if (_current.y > _goal.y)
	{
		yDifGoal = _current.y - _goal.y;
	}
	else
	{
		yDifGoal = _goal.y - _current.y;
	}

	//The following statements are used to measure the cost of 8 directional movement
	if (xDifGoal > yDifGoal)
	{
		while (yDifGoal > 0)
		{
			xDifGoal -= 1;
			yDifGoal -= 1;
			cost += 1;
		}
		cost += xDifGoal;
	}
	else if (yDifGoal > xDifGoal)
	{
		while (xDifGoal > 0)
		{
			xDifGoal -= 1;
			yDifGoal -= 1;
			cost += 1;
		}
		cost += yDifGoal;
	}
	else
	{
		cost += xDifGoal;
	}
	return cost;
}

#endif
