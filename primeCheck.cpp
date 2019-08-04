#include <iostream>
#include <string>

bool isPrime(const int NUM);
const int BASELINE = 1;

int main() {
	
	int testNum = 6;
	
	std::string primeString;
	
	if(isPrime(testNum))
	{
	    primeString = "Prime.";
	}
	else
	{
	    primeString = "Not Prime.";
	}
	std::cout << "Your number " << testNum << " is " << primeString;
	
	return 0;
}


bool isPrime(const int NUM)
{
    bool primeCheck = false;
    
    for(int x = 1; x <= NUM; x++)
    {
        for(int y = 1; y <= NUM; y++)
        {
            if((x * y) == NUM)
            {
                if(x == BASELINE && y == NUM)
                {
                    primeCheck = true;
                }
                else if(x != BASELINE && x != NUM)
                {
                    primeCheck = false;
                    return primeCheck;
                }
            }
        }
    }
    
}
