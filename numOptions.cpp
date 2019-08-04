#include <iostream>
#include <string>

int main() {
	
	int totalsum = 0;
	int num = 0;
	bool goodNum = false;
	
	//enter a num
	do
	{
	    std::cout << "Enter a number greater than 1\n";
	    std::cin >> num;
	    num = 4;
	    
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
	
	//user chooses to get sum (0) or product (1)
	int val = 2;
	
	while (val != 0 && val != 1)
	{
    	std::cout << "\nWould you like to compute the sum or product of 1 to the number " << num << "?\n";
    	std::cout << "Enter 0 for sum, or enter 1 for product: ";
    	std::cin >> val;
    	//manual programmer choice number on online ide
    	val = 1;
    	
    	if(val != 0 && val != 1)
    	{
    	    std::cout << "\n\nInvalid number. Please enter 0 or 1.";
    	}
	}
	
	//to get the sum
	if(val == 0)
	{
	    for(int x = 1; x <= num; x++)
	    {
	        totalsum += x;
	    }
	    std::cout << "\n\nThe sum of the numbers 1 to " << num << " is equal to " << totalsum << ".";
	}
	//to get the product
	else
	{
	    //set totalsum to 1 since we don't want to multiply by 0
	    totalsum = 1;
	    for(int x = 1; x <= num; x++)
	    {
	        totalsum *= x;
	    }
	    std::cout << "\n\nThe product of the numbers 1 to " << num << " is equal to " << totalsum << ".";
	}
	
	/*
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
	*/
	
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
