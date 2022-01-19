#pragma once
#include <iostream>
using namespace std;

const int MAX_NAME_SIZE = 24;

struct Highscore {
    char name[MAX_NAME_SIZE];
    int score;
};

void getArraySize(int& size);
void readData(Highscore highScores[], int size);
void sortData(Highscore highScores[], int size);
int findIndexOfLargest(const Highscore highScores[], int startingIndex, int size);
void displayData(const Highscore highScores[], int size);

int main()
{

    Highscore* highScores;
    int size;

    getArraySize(size);

    highScores = new Highscore[size];

    readData(highScores, size);
    sortData(highScores, size);
    displayData(highScores, size);

    delete[] highScores;
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





int findIndexOfLargest(const Highscore highScores[], int startingIndex, int numItems) {
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

