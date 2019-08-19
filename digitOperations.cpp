

#include <simple_programming_problems.h>
#include <sstream> //for converting int to string | to_string <- C++ 11 feature



int addNumsAtDigit(int, int, int);
int highestDigitInCommon(int, int);


///the main function


int main()
{
	bool isActive = true;

	while (isActive)
	{
		std::cout << "\n\nWhich operation would you like to perform.\n0 = Addition\n1 = Subtraction\n2 = Multiplication\n3 = Exit Program";
		int userChoice = getUserNumber(3);

		//need to declare these outside of switch statement | https://stackoverflow.com/questions/20177495/error-c2360-initialization-of-hdc-is-skipped-by-case-label
		int firstNum, secondNum, digitToUse, result;

		switch (userChoice)
		{
		//Addition
		case 0:
			std::cout << "\n\nEnter the first number.\n";
			firstNum = getUserNumber();
			std::cout << "\n\nEnter the second number.\n";
			secondNum = getUserNumber();
			std::cout << "\n\nWhich digit would you like to use for carrying out the operation?.\n";
			std::cout << "\nBe mindful both numbers must have that same digit placement in common";
			std::cout << "\ne.g. using 12733 and 9212 the valid digits are 1-4 since the highest digit both have in common is 4.";
			std::cout << "\nUsing 4 would calculate as 12000 + 9000 in this example.";
			std::cout << std::endl;
			digitToUse = getUserNumber(1, highestDigitInCommon(firstNum, secondNum));
			result = addNumsAtDigit(firstNum, secondNum, digitToUse);
			std::cout << "\nThe resulting sum of " << firstNum << " and " << secondNum << " at the " << digitToUse << " digit of each number is " << result;

			std::cout << "\n\nPress enter to continue.\n";
			getwchar();
			break;
		//Subtraction
		case 1:
			break;
		//Multiplication
		case 2:
			break;
		//Exit Program
		case 3:
			isActive = false;
			break;
		default:
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