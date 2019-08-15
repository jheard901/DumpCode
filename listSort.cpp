

#include <iostream>
#include <list>
#include <ctime> //for generating random numbers


std::list<int> concatenateLists(std::list<int>, std::list<int>);
std::list<int> altConcatenateLists(std::list<int>, std::list<int>);
void myBubbleSort(std::list<int> &, int);
void swap(std::list<int>::iterator &, std::list<int>::iterator &);
std::list<int>::iterator GetListElement(std::list<int>, int);


///the main function
int main()
{
	//seeds generator with current time
	srand((unsigned)time(NULL));

	//create a randomly generated list of ints
	std::list<int> randListA;
	for (int x = 0; x < 6; x++)
	{
		randListA.push_back((rand() % 100) + 1);
	}
	std::list<int> randListB;
	for (int x = 0; x < 6; x++)
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

	myBubbleSort(randListA, randListA.size());
	myBubbleSort(randListB, randListB.size());

	std::cout << "\n\nThe order of the lists when sorted is:\n";
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
	myBubbleSort(combinedList, combinedList.size());
	std::cout << "\n\nThe order of the lists combined and sorted is:\n";
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

//should of called this function "mixLists"
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

//using https://thispointer.com/c-how-to-get-element-by-index-in-list/ | https://www.geeksforgeeks.org/bubble-sort/
void myBubbleSort(std::list<int> &theList, int theListSize)
{
	int i, j;
	std::list<int> newList;
	std::list<int>::iterator mitL, mitR;
	for (i = 0; i < theListSize - 1; ++i)
	{
		for (j = 0; j < theListSize - i - 1; ++j)
		{
			mitL = std::next(theList.begin(), j);
			mitR = std::next(theList.begin(), j + 1);
			if (*mitL > *mitR)
			{
				//swap(mitL, mitR);
				//mitL = GetListElement(theList, j);
				//mitR = GetListElement(theList, j + 1);

				//this is the solution below for swapping values in a stl list

				theList.insert(mitL, *mitR);
				theList.insert(mitR, *mitL);
				theList.erase(mitL);
				theList.erase(mitR);

				//bottom line, using list instead of vector is a bad idea, because my swap() function does work with list the way you want it to

				/*
				swap(mitL, mitR);
				theList.insert(mitL, *mitL);
				mitL++;
				theList.erase(mitL);
				theList.insert(mitR, *mitR);
				mitR++;
				theList.erase(mitR);
				std::next(theList.begin(), j) = mitL;
				std::next(theList.begin(), j + 1) = mitR;
				*/
			}
		}
	}
}

//swaps the left and right values in a list
void swap(std::list<int>::iterator &itL, std::list<int>::iterator &itR)
{
	std::list<int>::iterator temp = itL;
	itL = itR;
	itR = temp;
}

//because you cannot access an individual element of a stl list directly like an array can be done using []
std::list<int>::iterator GetListElement(std::list<int> theList, int elementPosition)
{
	std::list<int>::iterator it = theList.begin();
	for (int x = 0; x < elementPosition; x++)
	{
		++it;
	}
	return it;
}
