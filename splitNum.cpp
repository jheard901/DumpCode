

#include <iostream>
#include <list>
#include <string>

bool isNumber(std::string);


///the main function
//using https://stackoverflow.com/questions/42606414/how-to-check-for-integer-range | https://stackoverflow.com/questions/8888748/how-to-check-if-given-c-string-or-char-contains-only-digits
// https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c

int main()
{
	bool isNum = false;
	std::string userInput;
	std::list<int> numList;

	//this could be made into an input driver to be used whenever you want to get user input
	while (!isNum)
	{
		std::cout << "\n\nEnter a number:\n";
		std::getline(std::cin, userInput);
		if (isNumber(userInput)) 
		{
			isNum = true; 
		}
		else 
		{ 
			std::cout << "\n\nThat is not a valid number. Try again.\n"; 
		}
	}
	
	//this could be a function 'splitNum' that returns a std::list<int>
	for (int i = 0; i < (signed)userInput.length(); i++)
	{
		numList.push_back((int)userInput[i]-'0');
	}
	
	std::cout << "\n\nThe numbers generated into a list from user input are:\n";
	for (std::list<int>::iterator tempIT = numList.begin(); tempIT != numList.end(); ++tempIT)
	{
		std::cout << " " << *tempIT;
	}

	//pause at end of program
	std::cout << std::endl << std::endl;
	system("pause");

	return 0;
}

bool isNumber(std::string input)
{
	return input.find_first_not_of("0123456789") == std::string::npos;
}

