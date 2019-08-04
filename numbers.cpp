#include <iostream>
#include <string>

int main() {
	
	int totalsum = 0;
	int num = 0;
	bool goodNum = false;
	
	do
	{
	    std::cout << "Enter a number greater than 1\n";
	    std::cin >> num;
	    num = 14;
	    
	    if(num <= 1)
	    {
	        goodNum = false;
	        std::cout << "Please enter a valid number.\n";
	    }
	    else if (num > 1)
	    {
	        goodNum = true;
	    }
	    
	} while (!goodNum);
	
	for(int x = 0; x <= num; x++)
	{
	    int y = 0;
	    
	    if(x % 3 == 0)
	    {
	        y = x;
	    }
	    else if (x % 5 == 0)
	    {
	        y = x;
	    }
	    else
	    {
	        y = 0;
	    }
	    
	    totalsum += y;
	}
	
	std::cout << "The value of the numbers 1 to " << num << " including only multiples of 3 and 5 is equal to " << totalsum << ".";
	
	
	/*
	//string related stuff
	std::string name;
	
	std::cout << "What is your name?\n\n";
	std::cin >> name;
	name = "Alice";
	if(name == "Alice" || name == "Bob")
	{
	    std::cout << std::endl << "You said your name is " << name << "."; 
	}
	else
	{
	    std::cout << std::endl << "Hello.";
	}
	*/
	
	return 0;
}
