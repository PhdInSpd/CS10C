/*
student: Jose Alfredo Martinez
instructor : Dave Harden
class : CS 10C
    file name : a1_1.cpp 
                client file to test HighScore.h
date: Jan 20, 2022

what the program does and how the code works :
    Query number of HighScore entries from user.

expected user input :
    User will then input the name and score for each entry.

program output :
    The data will be sorted by decreasing score and printed.
*/
#include "HighScore.h"

int main() {
    // the number of entries of HighScore datamodel
    int size = int();
    getValidVectorSize(size);

    // initialize vector of HighScore
    vector<Highscore> highScores(size);

    readData(highScores);
    sortData(highScores);
    displayData(highScores);
    return 0;
}
