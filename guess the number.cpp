#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int num=0, guess=0, tries=0;
	num = rand() % 100 + 1; 
	cout << "\nGuess the number uwu\n";

	do
	{
		cout << "\nQue numero estoy pensando?\n";
		cin >> guess;
		tries++;

		if (guess > num)
			cout << "\nTe pasaste!\n";
		else if (guess < num)
			cout << "\nTe falta!\n";
		else
			cout << "\nAhuevo! le atinaste en " << tries << " intentos!\n";
	} while (guess != num);

	return 0;
}