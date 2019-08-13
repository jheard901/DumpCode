
#include <iostream>
#include <list>
#include <ctime> //for generating random numbers


std::list<int> concatenateLists(std::list<int>, std::list<int>);
std::list<int> altConcatenateLists(std::list<int>, std::list<int>);


///the main function
int main()
{
	//seeds generator with current time
	srand((unsigned)time(NULL));

	//create a randomly generated list of ints
	std::list<int> randListA;
	for (int x = 0; x < 4; x++)
	{
		randListA.push_back((rand() % 100) + 1);
	}
	std::list<int> randListB;
	for (int x = 0; x < 4; x++)
	{
		randListB.push_back((rand() % 100) + 1);
	}


	std::list<int>::iterator it;
	std::cout << "The current order of the lists:\n";
	for (std::list<int>::iterator tempIT = randListA.begin(); tempIT != randListA.end(); ++tempIT)
	{
		std::cout << " " << *tempIT;
	}
	std::cout << std::endl;
	for (std::list<int>::iterator tempIT = randListB.begin(); tempIT != randListB.end(); ++tempIT)
	{
		std::cout << " " << *tempIT;
	}

	std::list<int> combinedList = altConcatenateLists(randListA, randListB);
	std::cout << "\n\nThe order of the lists combined is:\n";
	for (std::list<int>::iterator tempIT = combinedList.begin(); tempIT != combinedList.end(); ++tempIT)
	{
		std::cout << " " << *tempIT;
	}


	//pause at end of program
	std::cout << std::endl << std::endl;
	system("pause");

	return 0;
}


std::list<int> concatenateLists(std::list<int> listA, std::list<int> listB)
{

	for (std::list<int>::iterator tempIT = listB.begin(); tempIT != listB.end(); ++tempIT)
	{
		listA.push_back(*tempIT);
	}

	return listA;
}

//should of called this funciton "mixLists"
std::list<int> altConcatenateLists(std::list<int> listA, std::list<int> listB)
{
	std::list<int> newList;
	std::list<int>::iterator itA, itB;

	itA = listA.begin();
	itB = listB.begin();

	while (itA != listA.end() || itB != listB.end())
	{
		if (itA != listA.end())
		{
			newList.push_back(*itA);
			++itA;
		}
		if (itB != listB.end())
		{
			newList.push_back(*itB);
			++itB;
		}
	}

	return newList;
}


