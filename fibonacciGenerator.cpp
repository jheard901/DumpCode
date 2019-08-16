

#include <iostream>
#include <list>
#include <limits>



std::list<int> fibonacciListGenerator(int fibonacciTerm);

///the main function
int main()
{
	int terms = 100;
	std::list<int> myFibList = fibonacciListGenerator(terms);

	std::cout << "The first " << terms << " numbers in the fibonacci sequence are:\n";
	for (std::list<int>::iterator tempIT = myFibList.begin(); tempIT != myFibList.end(); ++tempIT)
	{
		std::cout << "\n " << *tempIT;
	}

	//pause at end of program
	std::cout << std::endl << std::endl;
	system("pause");

	return 0;
}

//generates a list of fibonacci numbers up to x e.g. 100th term, etc...
//using https://stackoverflow.com/questions/42606414/how-to-check-for-integer-range | https://stackoverflow.com/questions/199333/how-do-i-detect-unsigned-integer-multiply-overflow
std::list<int> fibonacciListGenerator(int fibonacciTerm)
{
	//the first two fibonacci numbers will be 1 and 1
	std::list<int> fibonacciList;

	if (fibonacciTerm <= 0)
	{
		return fibonacciList;
	}
	else if (fibonacciTerm == 1)
	{
		fibonacciList.push_back(1);
		return fibonacciList;
	}
	else if (fibonacciTerm == 2)
	{
		fibonacciList.push_back(1);
		fibonacciList.push_back(1);
		return fibonacciList;
	}
	else
	{
		fibonacciList.push_back(1);
		fibonacciList.push_back(1);
		for (int x = 0; x < fibonacciTerm - 2; x++)
		{
			std::list<int>::iterator itA, itB;
			itA = --fibonacciList.end();
			itB = std::prev(itA);
			int nextFibonacciNum = *itA + *itB;
			//caps fibonacci sequence at INT_MAX value
			if ((*itA > 0) && (*itB > std::numeric_limits<int>::max() - *itA))
			{
				nextFibonacciNum = INT_MAX;
			}
			fibonacciList.push_back(nextFibonacciNum);
		}
		return fibonacciList;
	}
	
	
}

