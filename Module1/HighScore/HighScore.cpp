#pragma once
#include <iostream>
#include <vector>

using namespace std;

const int MAX_NAME_SIZE = 24;

struct Highscore {
    char name[MAX_NAME_SIZE];
    int score;
};

void getVectorSize(int& size);
void readData(vector<Highscore>& scores);
void sortData(vector<Highscore>& scores);
vector<Highscore>::iterator findLocationOfLargest(
    const vector<Highscore>::iterator startingLocation,
    const vector<Highscore>::iterator endingLocation);
void displayData(const vector<Highscore>& scores);

int main() {
    vector<Highscore> highScores;
    int size;

    getArraySize(size);


    readData(highScores);
    sortData(highScores);
    displayData(highScores);
    
}

void getArraySize(int& size) {
    cout << "How many scores will you enter?: ";
    cin >> size;
    cin.ignore();
}

void readData(Highscore highScores[], int size)
{
    for (int index = 0; index < size; index++)
    {
        cout << "Enter the name for score #" << (index + 1) << ": ";
        cin.getline(highScores[index].name, MAX_NAME_SIZE, '\n');

        cout << "Enter the score for score #" << (index + 1) << ": ";
        cin >> highScores[index].score;
        cin.ignore();
    }
    cout << endl;
}





void sortData(Highscore highScores[], int numItems) {
    for (int count = 0; count < numItems - 1; count++) {
        swap(highScores[findIndexOfLargest(highScores, count, numItems)],
            highScores[count]);

    }
}





vector<Highscore>::iterator findLocationOfLargest(
    const vector<Highscore>::iterator startingLocation,
    const vector<Highscore>::iterator endingLocation) {
    int indexOfLargest = startingIndex;

    for (int count = startingIndex + 1; count < numItems; count++) {
        if (highScores[count].score > highScores[indexOfLargest].score) {
            indexOfLargest = count;
        }
    }
    return indexOfLargest;
}










void displayData(const Highscore highScores[], int size)
{
    cout << "Top Scorers: " << endl;
    for (int index = 0; index < size; index++)
    {
        cout << highScores[index].name << ": " << highScores[index].score << endl;
    }
}

