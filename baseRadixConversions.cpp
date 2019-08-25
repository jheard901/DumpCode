


#include <simple_programming_problems.h>
#include <sstream> //for converting int to string | to_string <- C++ 11 feature




int addNumsAtDigit(int, int, int);
int subtractNumsAtDigit(int, int, int);
int multiplyNumsAtDigit(int, int, int);
int highestDigitInCommon(int, int);


///the main function

//referencing: https://en.wikipedia.org/wiki/Radix | https://en.wikipedia.org/wiki/List_of_numeral_systems

int main()
{
	

	bool isActive = true;

	while (isActive)
	{
		//int to enum: https://stackoverflow.com/questions/11452920/how-to-cast-int-to-enum-in-c
		std::cout << "\n\nValid bases to use for this program range from Binary (2) - Hexadecimal (16)";
		std::cout << "\n\nEnter a starting base/radix to use:\n";
		NumeralSystem startBase = static_cast<NumeralSystem>(getUserNumber(2, 16));

		std::cout << "\n\nEnter a target base/radix to convert to:\n";
		NumeralSystem targetBase = static_cast<NumeralSystem>(getUserNumber(2, 16));

		std::cout << "\n\nEnter a number to convert from base " << startBase << " to base " << targetBase << ":\n";
		std::string userNumber = getBaseString(startBase);
		std::string baseNumber = convertToBase(userNumber, startBase, targetBase);
		
		std::cout << "\n\nThe number " << userNumber << " in base " << startBase << " converted to base " << targetBase << " becomes " << baseNumber << ".\n";
		std::cout << "\n\nPress enter to continue.\n";
		getwchar();

		std::cout << "\n\nStart Again?\n0 = Start Over\n1 = Exit Program\n";
		int userDecision = getUserNumber(1);

		if (userDecision == 0)
		{

		}
		else
		{
			isActive = false;
		}
	}

	//pause at end of program
	std::cout << std::endl << std::endl;
	system("pause");

	return 0;
}

int addNumsAtDigit(int first, int second, int digit)
{
	if (digit == 1)
	{
		return first + second;
	}
	else if (digit > 1)
	{
		int firstLength = std::to_string(first).length();
		int secondLength = std::to_string(second).length();
		int firstValue = 0;
		int secondValue = 0;
		int base = toPower(10, digit - 1);
		std::string strFirst;
		std::string strSecond;

		//stores the numbers from 'digit' extending to the leftmost char of string
		for (int i = 0; i <= firstLength - digit; i++)
		{
			std::string sTemp = std::to_string(first);
			int nTemp = sTemp[firstLength - digit - i] - '0';
			strFirst.insert(0, std::to_string(nTemp));
		}
		for (int i = 0; i <= secondLength - digit; i++)
		{
			std::string sTemp = std::to_string(second);
			int nTemp = sTemp[secondLength - digit - i] - '0';
			strSecond.insert(0, std::to_string(nTemp));
		}

		firstValue = std::stoi(strFirst);
		secondValue = std::stoi(strSecond);

		return (firstValue * base) + (secondValue * base);
	}
	else
	{
		//this just means there is an error if digit is less than 1
		return -9999;
	}
}


int subtractNumsAtDigit(int first, int second, int digit)
{
	if (digit == 1)
	{
		return first - second;
	}
	else if (digit > 1)
	{
		int firstLength = std::to_string(first).length();
		int secondLength = std::to_string(second).length();
		int firstValue = 0;
		int secondValue = 0;
		int base = toPower(10, digit - 1);
		std::string strFirst;
		std::string strSecond;

		//stores the numbers from 'digit' extending to the leftmost char of string
		for (int i = 0; i <= firstLength - digit; i++)
		{
			std::string sTemp = std::to_string(first);
			int nTemp = sTemp[firstLength - digit - i] - '0';
			strFirst.insert(0, std::to_string(nTemp));
		}
		for (int i = 0; i <= secondLength - digit; i++)
		{
			std::string sTemp = std::to_string(second);
			int nTemp = sTemp[secondLength - digit - i] - '0';
			strSecond.insert(0, std::to_string(nTemp));
		}

		firstValue = std::stoi(strFirst);
		secondValue = std::stoi(strSecond);

		return (firstValue * base) - (secondValue * base);
	}
	else
	{
		//this just means there is an error if digit is less than 1
		return -8999;
	}
}

int multiplyNumsAtDigit(int first, int second, int digit)
{
	if (digit == 1)
	{
		return first * second;
	}
	else if (digit > 1)
	{
		int firstLength = std::to_string(first).length();
		int secondLength = std::to_string(second).length();
		int firstValue = 0;
		int secondValue = 0;
		int base = toPower(10, digit - 1);
		std::string strFirst;
		std::string strSecond;

		//stores the numbers from 'digit' extending to the leftmost char of string
		for (int i = 0; i <= firstLength - digit; i++)
		{
			std::string sTemp = std::to_string(first);
			int nTemp = sTemp[firstLength - digit - i] - '0';
			strFirst.insert(0, std::to_string(nTemp));
		}
		for (int i = 0; i <= secondLength - digit; i++)
		{
			std::string sTemp = std::to_string(second);
			int nTemp = sTemp[secondLength - digit - i] - '0';
			strSecond.insert(0, std::to_string(nTemp));
		}

		firstValue = std::stoi(strFirst);
		secondValue = std::stoi(strSecond);

		return (firstValue * base) * (secondValue * base);
	}
	else
	{
		//this just means there is an error if digit is less than 1
		return -7999;
	}
}

int highestDigitInCommon(int first, int second)
{
	std::string str1 = std::to_string(first);
	std::string str2 = std::to_string(second);

	if (str1.length() > str2.length())
	{
		return (signed)str2.length();
	}
	else if (str1.length() < str2.length())
	{
		return (signed)str1.length();
	}
	else
	{
		//they are the same length
		return (signed)str1.length();
	}
}


