
#include <iostream>
#include <list>
#include <ctime> //for generating random numbers



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

	std::cout << "\n\nThe total of all elements in list is:\n";
	int listSum = 0;
	for (std::list<int>::iterator tempIT = myRandList.begin(); tempIT != myRandList.end(); ++tempIT)
	{
		listSum += *tempIT;
	}

	std::cout << " " << listSum;

	//pause at end of program
	std::cout << std::endl << std::endl;
	system("pause");

	return 0;
}



