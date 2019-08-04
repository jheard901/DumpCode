#include <iostream>

bool isLeap(int);

int main() 
{
    int currentYear = 2019;
    int possibleYear = currentYear;
    int printedYears = 0;
    
	std::cout << "The next 20 leap years starting after " << currentYear << " is as follows:\n\n";
	
	while(printedYears < 20)
	{
	    if(isLeap(possibleYear))
	    {
	        std::cout << possibleYear << std::endl;
	        printedYears++;
	    }
	    else
	    {
	        
	    }
	    
	    possibleYear++;
	}
	
	
	return 0;
}

bool isLeap(int year)
{
    if(year % 4 != 0)
    {
        return false;
    }
    if(year % 100 == 0)
    {
        //do additional check under this condition
        if(year % 400 != 0)
        {
            return false;
        }
    }
    
    return true;
}
