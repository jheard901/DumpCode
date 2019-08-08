
#include <iostream>
#include <list>
#include <ctime> //for generating random numbers


int listSumForLoop(std::list<int>);
int listSumWhileLoop(std::list<int>);
int listSumRecursion(std::list<int>, int newSum);

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

	std::cout << "\n\nThe sum of all elements in list using 3 different functions is:\n";
	//for loop sum
	std::cout << " " << listSumForLoop(myRandList) << std::endl;
	//while loop sum
	std::cout << " " << listSumWhileLoop(myRandList) << std::endl;
	//recursive sum
	int listSum = 0;
	std::cout << " " << listSumRecursion(myRandList, listSum) << std::endl;


	//pause at end of program
	std::cout << std::endl << std::endl;
	system("pause");

	return 0;
}



int listSumForLoop(std::list<int> inList)
{
	int sum = 0;

	for (std::list<int>::iterator it = inList.begin(); it != inList.end(); ++it)
	{
		sum += *it;
	}
	return sum;
}

int listSumWhileLoop(std::list<int> inList)
{
	std::list<int>::iterator it = inList.begin();
	bool isDone = false;
	int sum = 0;
	while (!isDone)
	{
		if (it == inList.end())
		{
			isDone = true;
		}
		else
		{
			sum += *it;
			++it;
		}
	}
	return sum;
}

//note, recursion does not affect the original list because it is not being passed by reference with &, but rather as a copy
int listSumRecursion(std::list<int> inList, int newSum)
{
	if (inList.size() > 0)
	{
		std::list<int>::iterator it = inList.begin();
		newSum += *it;
		inList.pop_front();
		return listSumRecursion(inList, newSum);
	}
	else
	{
		return newSum;
	}
}
