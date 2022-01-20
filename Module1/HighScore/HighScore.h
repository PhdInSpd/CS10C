#pragma once
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

const int MAX_NAME_SIZE = 64;

struct Highscore {
    char name[MAX_NAME_SIZE] = {};
    int score;
};

/// <summary>
/// enter any size number
/// </summary>
/// <param name="size"></param>
void getVectorSize(int& size);
/// <summary>
/// read name and score into array of HighScore 
/// </summary>
/// <param name="highScores"></param>
void readData(vector<Highscore>& scores);
/// <summary>
/// sort  array of HighScore from largest to smallest score
/// </summary>
/// <param name="scores"></param>
void sortData(vector<Highscore>& scores);
/// <summary>
/// find the largest score entry from startingLocation to endingLocation
/// </summary>
/// <param name="startingLocation"></param>
/// <param name="endingLocation"></param>
/// <returns></returns>
vector<Highscore>::iterator findLocationOfLargest(
    const vector<Highscore>::iterator startingLocation,
    const vector<Highscore>::iterator endingLocation);
/// <summary>
/// display name of score of all HighScores in input vector
/// </summary>
/// <param name="scores"></param>
void displayData(const vector<Highscore>& scores);
/// <summary>
/// input a size greater than zero
/// </summary>
/// <param name="size"> size must be greater than zero</param>
void getValidVectorSize(int& size);