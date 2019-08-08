
#include <iostream>
#include <string>


bool isPalindrome(std::string);

///the main function
int main()
{
	std::string userString;
	std::cout << "\n\nEnter a word and it will be checked if it is a Palindrome i.e. spelled the same forwards and backwords.\n";
	std::cin >> userString;

	if (isPalindrome(userString))
	{
		std::cout << "\n\n" << userString << " is a Palindrome!\n";
	}
	else
	{
		std::cout << "\n\n" << userString << " is not a Palindrome.\n";
	}

	//pause at end of program
	std::cout << std::endl << std::endl;
	system("pause");

	return 0;
}

//can be improved by making an exception for case-sensitivity e.g. Elle is a palindrome but program does not recognize it as one due to difference of 'E' and 'e'
bool isPalindrome(std::string inString)
{
	//dynamic array declaration https://stackoverflow.com/questions/2029651/how-do-you-initialise-a-dynamic-array-in-c
	char* copiedString = new char[inString.size()];
	for(int x = 0; x < (signed)inString.size(); x++)
	{
		//iterate through a string https://www.techiedelight.com/iterate-over-characters-string-cpp/
		copiedString[x] = inString[x];
	}
	
	//need to add this to declare where the end of the array is https://stackoverflow.com/questions/2736062/how-to-determine-the-end-of-an-integer-array-when-manipulating-with-integer-poin
	copiedString[inString.size()] = NULL;
	int y = 0;

	for (int x = inString.size() - 1; x > 0; x--)
	{
		//compare the end of the copied string to its beginning
		if (copiedString[x] != inString[y])
		{
			return false;
		}
		y++;
	}
	return true;
}


