

#pragma once

/* Tidbits I've forgotten:
https://stackoverflow.com/questions/19415521/cannot-open-include-file-with-visual-studio
*/

#include <iostream>
#include <ctime> //for generating random numbers
#include <list>
#include <string>

//list of common helper functions frequently used throughout the exercises from https://adriann.github.io/programming_problems.html

////seeds random number generator with current time
void seedGenerator()
{
	srand((unsigned)time(NULL));
}

////generate a list of random numeric elements of type T ranging from '0 - 100'
template <class T>
std::list<T> generateRandomList(int numElements)
{
	std::list<T> gList;
	for (int x = 0; x < numElements; x++)
	{
		gList.push_back((rand() % 100) + 1);
	}
	return gList;
}

////generate a list of random numeric elements of type T; random numbers are from '0 - range'
template <class T>
std::list<T> generateRandomList(int numElements, int range)
{
	std::list<T> gList;
	for (int x = 0; x < numElements; x++)
	{
		gList.push_back((rand() % range) + 1);
	}
	return gList;
}

////prints the order of a list assuming it is a valid type that can be printed
template <class T>
void printListOrder(std::list<T> l)
{
	for (std::list<T>::iterator it = l.begin(); it != l.end(); ++it)
	{
		std::cout << " " << *it;
	}
}

////returns true if the input is all numbers 0 - 9
bool isNumber(std::string input)
{
	return input.find_first_not_of("0123456789") == std::string::npos;
}

////Gets a number from the user that must be an int | input driver for an int
int getUserNumber()
{
	bool isNum = false;
	std::string userInput;

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


	return std::stoi(userInput);
}

////gets a number from the user that must be within '0 - range'
int getUserNumber(int range)
{
	bool isNum = false;
	std::string userInput;

	while (!isNum)
	{
		std::cout << "\n\nEnter a number:\n";
		std::getline(std::cin, userInput);
		if (isNumber(userInput))
		{
			int num = std::stoi(userInput);
			if (num > range || num < 0)
			{
				std::cout << "\n\nThat number is not within the range. It must be between 0 - " << range << ". Try again.\n";
			}
			else
			{
				isNum = true;
			}
		}
		else
		{
			std::cout << "\n\nThat is not a valid number. Try again.\n";
		}
	}


	return std::stoi(userInput);
}

////gets a number from the user that must be within 'minRange - maxRange'
int getUserNumber(int minRange, int maxRange)
{
	bool isNum = false;
	std::string userInput;

	while (!isNum)
	{
		std::cout << "\n\nEnter a number:\n";
		std::getline(std::cin, userInput);
		if (isNumber(userInput))
		{
			int num = std::stoi(userInput);
			if (num < minRange || num > maxRange)
			{
				std::cout << "\n\nThat number is not within the range. It must be between " << minRange << " - " << maxRange << ". Try again.\n";
			}
			else
			{
				isNum = true;
			}
		}
		else
		{
			std::cout << "\n\nThat is not a valid number. Try again.\n";
		}
	}


	return std::stoi(userInput);
}

////Gets a string from the user that must be all numbers | input driver for string of numbers
std::string getNumberString()
{
	bool isNum = false;
	std::string userInput;

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


	return userInput;
}

////returns a number to the 'nth' power | assumes whole numbers are used for exponent
template <class T>
T toPower(T base, T exponent)
{
	int originalBase = base;

	if (exponent == 1)
	{
		return base;
	}
	else
	{
		for (int i = 1; i < exponent; i++)
		{
			base *= originalBase;
		}
		return base;
	}
}


