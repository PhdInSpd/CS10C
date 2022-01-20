#include "HighScore.h"

int main() {
   
    int size = int();
    getValidVectorSize(size);

    // initialize vector of HighScore
    vector<Highscore> highScores(size);

    readData(highScores);
    sortData(highScores);
    displayData(highScores);
    return 0;
}
