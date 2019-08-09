#include <iostream>
#include <list>
#include <ctime> //for generating random numbers


void on_all(std::list<int>);
bool isPerfectSquare(int);

///the main function
int main()
{
	//seeds generator with current time
	srand((unsigned)time(NULL));

	//create a randomly generated list of ints
	std::list<int> myRandList;
	for (int x = 0; x < 128; x++)
	{
		myRandList.push_back((rand() % 100) + 1);
	}

	//create a sequential list
	std::list<int> myStepList;
	for (int x = 0; x < 1000; x++)
	{
		myStepList.push_back(x);
	}

	/*
	std::list<int>::iterator it;
	std::cout << "The current order of the list:\n";
	for (std::list<int>::iterator tempIT = myRandList.begin(); tempIT != myRandList.end(); ++tempIT)
	{
		std::cout << " " << *tempIT;
	}
	*/

	std::cout << "\n\nFinding perfect squares in random list.\n";
	on_all(myRandList);

	std::cout << "\n\nFinding perfect squares in sequential list.\n";
	on_all(myStepList);

	//pause at end of program
	std::cout << std::endl << std::endl;
	system("pause");

	return 0;
}

void on_all(std::list<int> inList)
{
	int squareCount = 0;
	for (std::list<int>::iterator it = inList.begin(); it != inList.end(); ++it)
	{
		if (isPerfectSquare(*it))
		{
			std::cout << "\nThe number " << *it << " is a perfect square!\n";
			squareCount++;
		}
		if (squareCount == 20)
		{
			std::cout << "\n\n Found the first 20 perfect squares in this list. Exiting...\n";
			return;
		}
	}
	return;
}

bool isPerfectSquare(int num)
{
	int x = 0;
	int y = x * x;
	while (y <= num)
	{
		if (y == num)
		{
			//num is a perfect square
			return true;
		}
		x++;
		y = x * x;
	}
	//did not find a perfect square if x square is > num
	return false;
}


