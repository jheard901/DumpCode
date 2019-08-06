

#include <iostream>
#include <list>
#include <ctime> //for generating random numbers

bool isOdd(const int);

///the main function
int main()
{
	//seeds generator with current time
	srand((unsigned)time(NULL));

	//create a randomly generated list of ints
	std::list<int> myRandList;
	for (int x = 0; x < 8; x++)
	{
		myRandList.push_back((rand() % 100) + 1);
	}

	std::list<int>::iterator it;

	std::cout << "The current order of the list:\n";
	for (std::list<int>::iterator tempIT = myRandList.begin(); tempIT != myRandList.end(); ++tempIT)
	{
		std::cout << " " << *tempIT;
	}

	std::cout << "\n\nAll elements with an odd position in the list are:\n";
	int listPosition = 1;
	for (std::list<int>::iterator tempIT = myRandList.begin(); tempIT != myRandList.end(); ++tempIT)
	{
		if (isOdd(listPosition))
		{
			std::cout << " " << *tempIT;
		}
		listPosition++;
	}


	//pause at end of program
	std::cout << std::endl << std::endl;
	system("pause");

	return 0;
}


bool isOdd(const int NUM)
{
	if (NUM % 2 == 0)
	{
		return false;
	}
	else if (NUM == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
