#include <iostream>
#include "IAGuesser.h"
using namespace std;
int main()
{
    IAGuesser guesser;

    std::cout << "\nGuess YOUR number\n";

    guesser.guessNumber();

    return 0;
}