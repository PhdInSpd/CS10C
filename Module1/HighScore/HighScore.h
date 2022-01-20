/*student: Jose Alfredo Martinez
instructor : Dave Harden
class : CS 10C
    file name : HighScore.h
date: Jan 20, 2022

what the program does and how the code works :
    Declares Highscore field to store name and score.
Declares input operatotion from user and sort data and print data operations.
expected user input : 
    N/A
program output :
    N/A
*/
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
/// <param name="size"> output is store in size</param>
void getVectorSize(int& size);
/// <summary>
/// read name and score into array of HighScore 
/// preconditions:
///     scores has at least one entry. 
///     scores has been initialize to specify number of entries
/// postcondition:
///     scores will stored entred results
/// </summary>
/// <param name="highScores"></param>
void readData(vector<Highscore>& scores);
/// <summary>
/// sort  array of HighScore from largest to smallest score
/// preconditions:
///     scores has at least one entry.
/// postcoditions:
///     scores will stored sorted results
/// </summary>
/// <param name="scores"></param>
void sortData(vector<Highscore>& scores);
/// <summary>
/// find the largest score entry from startingLocation to endingLocation
/// precondition:
///     startingLocation and endingLocation are not null
/// postcondition:
///     the iterator pointer to the largest score ranging from startingLocation to endingLocation
/// </summary>
/// <param name="startingLocation"></param>
/// <param name="endingLocation"></param>
/// <returns></returns>
vector<Highscore>::iterator findLocationOfLargest(
    const vector<Highscore>::iterator startingLocation,
    const vector<Highscore>::iterator endingLocation);
/// <summary>
/// display name of score of all HighScores in input vector
/// precondition:
///     scores has at least one entry
/// </summary>
/// <param name="scores"></param>
void displayData(const vector<Highscore>& scores);
/// <summary>
/// input a size greater than zero
/// postconditions:
///     a size that is creater than 0
/// </summary>
/// <param name="size"> size must be greater than zero</param>
void getValidVectorSize(int& size);