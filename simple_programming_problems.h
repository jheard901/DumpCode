

#pragma once

#include <iostream>
#include <ctime> //for generating random numbers
#include <list>
#include <string>

//list of common helper functions frequently used throughout the exercises from https://adriann.github.io/programming_problems.html


/* Tidbits I've forgotten:
https://stackoverflow.com/questions/19415521/cannot-open-include-file-with-visual-studio
*/


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

//to print enum value as text using operator overloading: https://stackoverflow.com/questions/3342726/c-print-out-enum-value-as-text
std::ostream& operator<<(std::ostream& out, const NumeralSystem value)
{
	const char* c = 0;

#define CASE_VALUE(n) case(n): c = #n; break;
	switch (value)
	{
		CASE_VALUE(BINARY);
		CASE_VALUE(TERNARY);
		CASE_VALUE(QUATERNARY);
		CASE_VALUE(QUINARY);
		CASE_VALUE(SENARY);
		CASE_VALUE(SEPTENARY);
		CASE_VALUE(OCTAL);
		CASE_VALUE(NONARY);
		CASE_VALUE(DECIMAL);
		CASE_VALUE(UNDECIMAL);
		CASE_VALUE(DUODECIMAL);
		CASE_VALUE(TRIDECIMAL);
		CASE_VALUE(TETRADECIMAL);
		CASE_VALUE(PENTADECIMAL);
		CASE_VALUE(HEXADECIMAL);
	}
#undef CASE_VALUE

	return out << c;
}

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
// formatting code indentations https://msdn.microsoft.com/en-us/library/999b219z(v=vs.71).aspx || Ctrl+K, Ctrl+F
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
	if (exponent == 0)
	{
		return 1;
	}
	else if (exponent == 1)
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

////returns the int value of a char from a string of base 2 - 16
int GetIntValue(char value)
{
	if (value == '0')
	{
		return 0;
	}
	else if (value == '1')
	{
		return 1;
	}
	else if (value == '2')
	{
		return 2;
	}
	else if (value == '3')
	{
		return 3;
	}
	else if (value == '4')
	{
		return 4;
	}
	else if (value == '5')
	{
		return 5;
	}
	else if (value == '6')
	{
		return 6;
	}
	else if (value == '7')
	{
		return 7;
	}
	else if (value == '8')
	{
		return 8;
	}
	else if (value == '9')
	{
		return 9;
	}
	else if (value == 'A')
	{
		return 10;
	}
	else if (value == 'B')
	{
		return 11;
	}
	else if (value == 'C')
	{
		return 12;
	}
	else if (value == 'D')
	{
		return 13;
	}
	else if (value == 'E')
	{
		return 14;
	}
	else if (value == 'F')
	{
		return 15;
	}
	else
	{
		return 0;
	}
}

////returns the string value equivalent of an int up to base 16
std::string GetStringValue(int value)
{
	switch (value)
	{
	case 0:
		return "0";
		break;
	case 1:
		return "1";
		break;
	case 2:
		return "2";
		break;
	case 3:
		return "3";
		break;
	case 4:
		return "4";
		break;
	case 5:
		return "5";
		break;
	case 6:
		return "6";
		break;
	case 7:
		return "7";
		break;
	case 8:
		return "8";
		break;
	case 9:
		return "9";
		break;
	case 10:
		return "A";
		break;
	case 11:
		return "B";
		break;
	case 12:
		return "C";
		break;
	case 13:
		return "D";
		break;
	case 14:
		return "E";
		break;
	case 15:
		return "F";
		break;
	default:
		return "0";
	}
}

//be mindful the only valid numbers are 0 to (base - 1); so in base 3 the numbers 0, 1, and 2 are the only valid numbers for example.
////returns true if the int can be incremented for a specified base
bool canIncrement(NumeralSystem base, int value)
{
	if (value < base - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

////takes a number and the type of base it is then converts it to its decimal equivalent
int toDecimal(NumeralSystem base, std::string number)
{
	//obtain the value increment of a column for its base, this number is equal to base^x where base is the base and ^x is the column location starting from the right and migrating to the left where the first column is 0 and increments by 1 until reaching last column on the left
	int* colValueIncrement = new int[number.length()];
	int column = 0;
	for (int i = number.length() - 1; i >= 0; i--)
	{
		colValueIncrement[i] = toPower(static_cast<int>(base), column);
		column++;
	}

	//Each value in a column gets multipled by its columnValueIncrement e.g. 202 for base 3 is calculated as (2 * 3^2) + (0 * 3^1) + (2 * 3^0) | recall any number to power 0 equals 1 so the result here is 20 in decimal form (base 10)
	int decimalValue = 0;
	for (int i = number.length() - 1; i >= 0; i--)
	{
		decimalValue += GetIntValue(number[i]) * colValueIncrement[i];
	}

	//Add the result of each column to get the decimal form
	delete[] colValueIncrement;
	return decimalValue;
}

////Takes a number in decimal value and converts it to the target base
std::string toBase(int decimal, NumeralSystem target)
{
	std::string targetNumString;
	bool bReady = false;
	int column = 0; //the column currently in use
	int targetNumCols = 0; //number of columns required to represent the decimal number in the specified base
	int cumulativeColumnValue = 0; //the value of all preceding columns combined

	//Add columns until the value of the first column on the left is greater than or equals the number in decimal form, and the next column
	//(i.e. 2nd from the left) is less than the number in decimal form || NOTE: if the 1st column is greater than number, then we do not
	//include it in the number string, but if it equals then we do include it in the number string
	while (!bReady)
	{
		cumulativeColumnValue += (target - 1) * toPower(static_cast<int>(target), column);

		if (cumulativeColumnValue >= decimal) //I did a version of this column check using max column value on paper || will stick with the cumulative value solution for now
		{
			bReady = true;
			column++;
			targetNumCols = column;
		}
		else
		{
			column++;
		}
	}

	//create the default string of value 0 for target string
	for (int i = 0; i < targetNumCols; i++)
	{
		targetNumString.insert(0, "0");
	}
	
	//Starting with the highest value column increment by 1: check its decimal equivalent each time to see if it exceeds or is equal to the
	//value of the number from its prior base. If it exceeds before reaching the last valid number in a column, then decrement by 1, and move
	//to the next column; repeat this process until equal to the number. NOTE: if we hit the highest value in a column and do not exceed number,
	//then retain that value in the column and move to the next column continuing with the process.
	bReady = false;
	column = 0;
	int testValue = 0;
	const int ONE_UNIT = 1;
	while (!bReady)
	{
		targetNumString.replace(column, ONE_UNIT, GetStringValue(testValue));
		int tempDecimal = toDecimal(target, targetNumString);

		if (tempDecimal > decimal)
		{
			//if over the target value, decrement value in current column by one then move on to next column
			testValue--;
			targetNumString.replace(column, ONE_UNIT, GetStringValue(testValue));
			column++;
			testValue = 0;
		}
		else if (tempDecimal == decimal)
		{
			bReady = true;
		}
		else
		{
			if (canIncrement(target, testValue))
			{
				testValue++;
			}
			else
			{
				column++;
				testValue = 0;

				//this should never be true, but should catch errors if they occur
				if (column >= (signed)targetNumString.length())
				{
					std::cout << "\nAn error occurred in converting to the base number.\n";
					return targetNumString;
				}
			}
		}
	}
	return targetNumString;
}

////Takes in a string and what base it is, then converts that number string to the target base and returns it as a string
std::string convertToBase(std::string baseNum, NumeralSystem start, NumeralSystem target)
{
	//first check to see if the start and target base are the same
	if (start == target)
	{
		return baseNum;
	}

	//first change the starting base to decimal form
	int decimalBaseNum = toDecimal(start, baseNum);

	//convert the decimal form of number to the target base
	std::string targetBaseNum = toBase(decimalBaseNum, target);
	
	return targetBaseNum;
}
