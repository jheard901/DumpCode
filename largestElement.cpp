#include <iostream>
#include <list>

int main() 
{
    std::list<int> myIntList;
    for(int x = 1; x < 99; x += 9)
    {
        myIntList.push_back(x);
    }
    
    
    
    int largestElement = 0;
    
    for(std::list<int>::iterator it = myIntList.begin(); it != myIntList.end(); it++)
    {
        if(*it > largestElement)
        {
            largestElement = *it;
        }
    }
    
    std::cout << "\nThe largest element in the list is " << largestElement << ".";
    
	return 0;
}
