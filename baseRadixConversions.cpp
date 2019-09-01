


#include <simple_programming_problems.h>
#include <sstream> //for converting int to string | to_string <- C++ 11 feature


///the main function

//referencing: https://en.wikipedia.org/wiki/Radix | https://en.wikipedia.org/wiki/List_of_numeral_systems

int main()
{
	

	bool isActive = true;

	while (isActive)
	{
		//int to enum: https://stackoverflow.com/questions/11452920/how-to-cast-int-to-enum-in-c
		//my current solution for this problem feels like it would of been better implemented as its own class rather than putting it in the general header file
		std::cout << "\n\nValid bases to use for this program range from Binary (2) - Hexadecimal (16)";
		std::cout << "\n\nEnter a starting base to use:\n";
		NumeralSystem startBase = static_cast<NumeralSystem>(getUserNumber(2, 16));

		std::cout << "\n\nEnter a target base to convert to:\n";
		NumeralSystem targetBase = static_cast<NumeralSystem>(getUserNumber(2, 16));

		std::cout << "Would you prefer to enter the base number in " << startBase << " or DECIMAL format?\n0 = " << startBase << "\n1 = DECIMAL\n";
		int userFormatChoice = getUserNumber(1);
		if (userFormatChoice == 0)
		{
			std::cout << "\n\nEnter a number to convert from " << startBase << " to " << targetBase << ":\n";
			std::string userNumber = getBaseString(startBase);
			std::string baseNumber = convertToBase(userNumber, startBase, targetBase);

			std::cout << "\n\nThe number " << userNumber << " in " << startBase << " converted to " << targetBase << " becomes " << baseNumber << ".\n";
		}
		else
		{
			std::cout << "\n\nEnter a number in decimal format to convert from " << startBase << " to " << targetBase << ":\n";
			std::string userDecimalNumber = getBaseString(DECIMAL);
			std::string userNumber = convertToBase(userDecimalNumber, DECIMAL, startBase);
			std::string baseNumber = convertToBase(userNumber, startBase, targetBase);

			std::cout << "\n\nThe number " << userDecimalNumber << " in " << startBase << " is " << userNumber << " and converted to " << targetBase << " becomes " << baseNumber << ".\n";
		}

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

