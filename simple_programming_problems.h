

#pragma once

/* Tidbits I've forgotten:
https://stackoverflow.com/questions/19415521/cannot-open-include-file-with-visual-studio
*/

#include <iostream>
#include <ctime> //for generating random numbers
#include <list>
#include <string>

//list of common helper functions frequently used throughout the exercises from https://adriann.github.io/programming_problems.html


enum NumeralSystem
{
	BINARY = 2,
	TERNARY = 3,
	QUATERNARY = 4,
	QUINARY = 5,
	SENARY = 6,
	SEPTENARY = 7,
	OCTAL = 8,
	NONARY = 9,
	DECIMAL = 10,
	UNDECIMAL = 11,
	DUODECIMAL = 12,
	TRIDECIMAL = 13,
	TETRADECIMAL = 14,
	PENTADECIMAL = 15,
	HEXADECIMAL = 16
};



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

////returns true of the inputted string is a valid number of the inputted base
bool isValidNumber(std::string str, NumeralSystem base)
{
	switch (base)
	{
		//base 2
	case BINARY:
		return str.find_first_not_of("01") == std::string::npos;
		break;

		//base 3
	case TERNARY:
		return str.find_first_not_of("012") == std::string::npos;
		break;

		//base 4
	case QUATERNARY:
		return str.find_first_not_of("0123") == std::string::npos;
		break;

		//base 5
	case QUINARY:
		return str.find_first_not_of("01234") == std::string::npos;
		break;

		//base 6
	case SENARY:
		return str.find_first_not_of("012345") == std::string::npos;
		break;

		//base 7
	case SEPTENARY:
		return str.find_first_not_of("0123456") == std::string::npos;
		break;

		//base 8
	case OCTAL:
		return str.find_first_not_of("01234567") == std::string::npos;
		break;

		//base 9
	case NONARY:
		return str.find_first_not_of("012345678") == std::string::npos;
		break;

		//base 10
	case DECIMAL:
		return str.find_first_not_of("0123456789") == std::string::npos;
		break;

		//base 11
	case UNDECIMAL:
		return str.find_first_not_of("0123456789aA") == std::string::npos;
		break;

		//base 12
	case DUODECIMAL:
		return str.find_first_not_of("0123456789aAbB") == std::string::npos;
		break;

		//base 13
	case TRIDECIMAL:
		return str.find_first_not_of("0123456789aAbBcC") == std::string::npos;
		break;

		//base 14
	case TETRADECIMAL:
		return str.find_first_not_of("0123456789aAbBcCdD") == std::string::npos;
		break;

		//base 15
	case PENTADECIMAL:
		return str.find_first_not_of("0123456789aAbBcCdDeE") == std::string::npos;
		break;

		//base 16
	case HEXADECIMAL:
		return str.find_first_not_of("0123456789aAbBcCdDeEfF") == std::string::npos;
		break;
	default:
		std::cout << "\nThe input base is invalid.\n";
		return false;
	}
}

////Gets a string from the user that must be valid number for the base/radix entered as a parameter
// formatting code indentations https://msdn.microsoft.com/en-us/library/999b219z(v=vs.71).aspx
std::string getBaseString(NumeralSystem base)
{
	bool isValid = false;
	
	std::string userStr;
	
	while (!isValid)
	{
		std::getline(std::cin, userStr);

		if (isValidNumber(userStr, base))
		{
			isValid = true;
		}
		else
		{
			std::string values;
			switch (base)
			{
				//base 2
			case BINARY:
				values = "01";
				break;

				//base 3
			case TERNARY:
				values = "012";
				break;

				//base 4
			case QUATERNARY:
				values = "0123";
				break;

				//base 5
			case QUINARY:
				values = "01234";
				break;

				//base 6
			case SENARY:
				values = "012345";
				break;

				//base 7
			case SEPTENARY:
				values = "0123456";
				break;

				//base 8
			case OCTAL:
				values = "01234567";
				break;

				//base 9
			case NONARY:
				values = "012345678";
				break;

				//base 10
			case DECIMAL:
				values = "0123456789";
				break;

				//base 11
			case UNDECIMAL:
				values = "0123456789A";
				break;

				//base 12
			case DUODECIMAL:
				values = "0123456789AB";
				break;

				//base 13
			case TRIDECIMAL:
				values = "0123456789ABC";
				break;

				//base 14
			case TETRADECIMAL:
				values = "0123456789ABCD";
				break;

				//base 15
			case PENTADECIMAL:
				values = "0123456789ABCDE";
				break;

				//base 16
			case HEXADECIMAL:
				values = "0123456789ABCDEF";
				break;
			default:
				values = "01";
			}
			std::cout << "\n\nNumber entered is invalid. Valid values are " << values << ". Try Again.\n";
		}
	}
	
	return userStr;
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

////Converts a string to a list of characters
std::list<char> convertToList(std::string baseString)
{

}

////Converts a list of chars to a string
std::string convertToString(std::list<char> baseList)
{

}

////Takes in a string and what base it is, then converts that number string to the target base and returns it as a string
std::string convertToBase(std::string baseNum, NumeralSystem start, NumeralSystem target)
{

}

