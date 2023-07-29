#pragma once
#ifndef IAGUESSER_H
#define IAGUESSER_H

#include <cstdlib>
#include <ctime>

class IAGuesser {
private:
    int min_num;
    int max_num;
    int num;
    int tries;

public:
    IAGuesser();

    void guessNumber();
    void updateNumber(char guess);
    bool isCorrectGuess(char guess);
    int getNumTries();

private:
    void iaguessplus();
    void iaguessminus();
};

#endif