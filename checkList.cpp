

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

	//ask user for an integer to search for | this check does not work, it just defaults to 0 if the entered value is not an integer and the program immediately exits ignoring the getchar at the end
	int userInt;
	bool isValid = false;
	while (!isValid)
	{
		std::cout << "\n\nWhat integer would you like to check for in list?\n";
		std::cin >> userInt;
		if (userInt != (int)userInt)
		{
			std::cout << "\n\nPlease enter a valid integer.\n";
		}
		else
		{
			isValid = true;
		}
	}
	
	//search for user's integer
	bool isFound = false;
	for (std::list<int>::iterator tempIT = myRandList.begin(); tempIT != myRandList.end(); ++tempIT)
	{
		if (userInt == *tempIT)
		{
			isFound = true;
			break;
		}
	}

	//feedback depending on if integer was found
	if (isFound)
	{
		std::cout << "\n\nFound user integer " << userInt << " in the list!\n";
	}
	else
	{
		std::cout << "\n\nDid not find user integer " << userInt << " in list.\n";
	}

	//pause at end of program
	std::cout << std::endl << std::endl;
	system("pause");

	return 0;
}
