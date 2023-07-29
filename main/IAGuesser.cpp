#include "iaguesser.h"
#include <iostream>
using namespace std;
IAGuesser::IAGuesser() {
    min_num = 1;
    max_num = 100;
    num = rand() % 100 + 1;
    tries = 0;
}

void IAGuesser::iaguessplus() {
    min_num = num + 1;
    num = rand() % (max_num - min_num + 1) + min_num;
}

void IAGuesser::iaguessminus() {
    max_num = num - 1;
    num = rand() % (max_num - min_num + 1) + min_num;
}

void IAGuesser::guessNumber() {
    char guess;
    do {
        cout << "\nEs tu numero el " << num << "?\n";
        cin >> guess;
        tries++;

        if (guess == '+') {
            iaguessplus();
        }
        else if (guess == '-') {
            iaguessminus();
        }
        else if (isCorrectGuess(guess)) {
            cout << "\nWOW le atine, lo logre en " << tries << " intentos!\n";
            break;
        }
        else {
            cout << "\nRespuesta inválida. Debes ingresar '+', '-' o 'G'.\n";
        }

    } while (true);
}

void IAGuesser::updateNumber(char guess) {
    if (guess == '+') {
        iaguessplus();
    }
    else if (guess == '-') {
        iaguessminus();
    }
}

bool IAGuesser::isCorrectGuess(char guess) {
    return (guess == 'G' || guess == 'g');
}

int IAGuesser::getNumTries() {
    return tries;
}