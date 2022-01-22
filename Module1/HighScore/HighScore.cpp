/*
student: Jose Alfredo Martinez
instructor : Dave Harden
class : CS 10C
    file name : HighScore.cpp 
date: Jan 20, 2022

what the program does and how the code works :
Implement functions declared in HighScore.h
*/
#include "HighScore.h"
/// <summary>
/// enter any size number
/// </summary>
/// <param name="size"></param>
void getVectorSize(int& size) {
    cout << " How many scores will you enter?: ";
    cin >> size;
    cin.ignore();
}






/// <summary>
/// input a size greater than zero
/// </summary>
/// <param name="size"> size must be greater than zero</param>
void getValidVectorSize(int& size) {
    while (size <= 0) {
        if (size <= 0) {
            cout << "Atlease one score is required." << endl;
        }
        getVectorSize(size);
    }
}






/// <summary>
/// read name and score into array of HighScore 
/// </summary>
/// <param name="highScores"></param>
void readData(vector<Highscore>& highScores) {
    for (int index = 0; index < highScores.size(); index++) {
        cout << "Enter the name for score #" << (index + 1) << ": ";
        cin.getline(highScores[index].name, MAX_NAME_SIZE, '\n');

        cout << "Enter the score for score #" << (index + 1) << ": ";
        cin >> highScores[index].score;
        cin.ignore();
    }
    cout << endl;
}






/// <summary>
/// sort  array of HighScore from largest to smallest score
/// </summary>
/// <param name="scores"></param>
void sortData(vector<Highscore>& scores) {
    int numItems = scores.size();
    for (vector<Highscore>::iterator start = scores.begin(); start < scores.end(); start++) {
        swap(*findLocationOfLargest(start, scores.end()),
            *start);

    }
}






/// <summary>
/// find the largest score entry from startingLocation to endingLocation
/// </summary>
/// <param name="startingLocation"></param>
/// <param name="endingLocation"></param>
/// <returns></returns>
vector<Highscore>::iterator findLocationOfLargest(const vector<Highscore>::iterator startingLocation,
    const vector<Highscore>::iterator endingLocation) {

    vector<Highscore>::iterator largest = startingLocation;

    for (vector<Highscore>::iterator count = startingLocation + 1; count < endingLocation; count++) {
        if (count->score > largest->score) {
            largest = count;
        }
    }
    return largest;
}






/// <summary>
/// display name of score of all HighScores in input vector
/// </summary>
/// <param name="scores"></param>
void displayData(const vector<Highscore>& scores) {
    cout << "Top Scorers: " << endl;
    for (vector<Highscore>::const_iterator iterator = scores.begin(); iterator != scores.end(); iterator++) {
        cout << iterator->name << ": " << iterator->score << endl;
    }
}