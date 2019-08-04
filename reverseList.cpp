// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

	std::list<int> myTempList;
	std::list<int>::iterator it;

	std::cout << "The current order of the list:\n";
	for (std::list<int>::iterator tempIT = myRandList.begin(); tempIT != myRandList.end(); ++tempIT)
	{
		std::cout << " " << *tempIT;
	}

	std::cout << std::endl;

	//require use of prev() here since list::end refers to the past-the-end element in the container
	it = std::prev(myRandList.end());


	for (int x = 0; x < (signed)myRandList.size(); x++)
	{
		myTempList.push_back(*it);
		//need to exit the loop early because once copying the last element then the prev of myRandList.begin() is an invalid value and will throw an exception if you don't
		if (x != 7)
		{
			it = std::prev(it);
		}
		else
		{
			break;
		}
	}

	myRandList.clear();
	myRandList.assign(myTempList.begin(), myTempList.end());

	std::cout << "The new order of the list:\n";
	for (std::list<int>::iterator tempIT = myRandList.begin(); tempIT != myRandList.end(); ++tempIT)
	{
		std::cout << " " << *tempIT;
	}
	
	std::cout << "\n\nPress Enter to exit.";
	getchar();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
