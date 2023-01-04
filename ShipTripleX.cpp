#include <iostream> //preprocessor directive
#include <ctime> //computer time
//using namespace std;

void PrintIntroduction(int Difficulty) //allows us to pass values in the function
{
    // Halo Triple X intro
    std::cout << "You are a Space Soldier breaking into the Enemy's BattleShip with level " << Difficulty << " status \n" << std::endl;
    std::cout << "In order to get the secret codes from them regarding their cannon, you need to enter 3 exact codes to continue \n" << std::endl;
    std::cout << "Your AI companion QWERTY cannot help, so you will need to find the codes on your own \n" << std::endl;
    
}
bool PlayGame(int Difficulty) // function must return boolean
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty; // const allows variables' values to never be changed
    const int CodeB = rand() % Difficulty + Difficulty; // rand is random numbers; + difficulty is to offset the range of numbers to generate
    const int CodeC = rand() % Difficulty + Difficulty; // modulus is limiting numbers from 0-3 in this case

    std::cout << "There are three lines in the code \n" << std::endl;
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "The numbers add up to: " << CodeSum << std::endl;
    std::cout << "The product multiplies up to: " << CodeProduct << std::endl;

    //stores the player guess
    int GuessA, GuessB, GuessC;

    std::cout << " \nEnter any 3 numbers here and it will print on the screen:  \n";
    std::cin >> GuessA >> GuessB >> GuessC;
    //std::cout << "You entered the numbers: " << GuessA << GuessB << GuessC << std::endl;

    //stores the player guess sum and product
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    std::cout << "Sum is equal to: " << GuessSum << std::endl;
    std::cout << "Product is equal to: " << GuessProduct << "\n\n" << std::endl;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You did it, sir! Let's move into the next ship! \n" << std::endl;
        return true; //if player completed the code successfully
    }
    else
    {
        std::cout << "That ain't it, Chief.. try again \n" << std::endl;
        return false; //if player completed the code unsuccessfully
    }
}
int main()
{
    srand(time(NULL)); // creates new random sequence based on the time of day
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // loop game until levels are done
    {
        bool bLevelComplete = PlayGame(LevelDifficulty); // lets cpu know whether player has completed the game
        std::cin.clear(); //clears any errors
        std::cin.ignore(); //discards the buffer

        if (bLevelComplete)
        {
            //increase level difficulty
            ++LevelDifficulty;
        }
        
    }
    std::cout << "Well done! You were able to have QWERTY extract all the data! Now get outta there! \n";
    return 0;
}
