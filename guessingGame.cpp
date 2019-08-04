#include <iostream>
#include <ctime>

const int MAX_NUMBER = 5;

int main() {
    
    //the setup
    bool isGuessed = false;
    int userGuess;
    int lastGuess;
    int userAttempts = 0;
    
    //testing tool variable for the online IDE
    int x = 1;
    
    //seed random number generator
    srand((unsigned)time(NULL));
    
    //select a secret number between 1 to MAX_NUMBER
    int secretNUM = rand() % MAX_NUMBER + 1;
    
    //title
    std::cout << "The Guessing Game!\n\n";
    
    //the guessing game
    while (isGuessed == false)
    {
        std::cout << "Guess what number I have picked between 1 and " << MAX_NUMBER << ".\n";
        std::cin >> userGuess;
        
        //this app really will not be able to be tested unless I use a real compiler for it
        //testing tool for online IDE
        userGuess = x;
            
        //guessed the number correctly
        if(userGuess == secretNUM)
        {
            std::cout << "\nYou guessed the number correctly!\n";
            isGuessed = true;
                
            if(userGuess == lastGuess)
            {
                //don't increment user attempts
            }
            else
            {
                userAttempts++;
            }
            lastGuess = userGuess;
        }
        //guessed too high
        else if (userGuess > secretNUM)
        {
            std::cout << "\nYou guessed too high. Try again.\n";
                
            if(userGuess == lastGuess)
            {
                //don't increment user attempts
            }
            else
            {
                userAttempts++;
            }
            lastGuess = userGuess;
        }
        //guessed too low
        else
        {
            std::cout << "\nYou guessed too low. Try again.\n";
                
            if(userGuess == lastGuess)
            {
                //don't increment user attempts
            }
            else
            {
                userAttempts++;
            }
            lastGuess = userGuess;
        }
        
        //testing tool for online IDE
        x++;
    }
    
    std::cout << "\nThe number of tries it took you was " << userAttempts << ".\n";
    
	return 0;
}

