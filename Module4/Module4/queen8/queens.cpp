/*
student   : Jose Alfredo Martinez
instructor: Dave Harden
class     : CS 10C
date      : Jan 27, 2022
file name : queens.cpp
description: Solve the 8 queen problem described in the book
              Data Abstraction & Problem Solving with c++
              from Section 5.3.2
*/
#include <iostream>
#include <vector>
using namespace std;

class Queen;
class Board {
public:
    static const int BOARD_SIZE = 8;
    Board();
    void doQueens();
    void display() const;
    /// <summary>
    /// is the nowRow, testCol inside the board
    /// </summary>
    /// <param name="nowtRow"></param>
    /// <param name="testCol"></param>
    /// <returns></returns>
    static bool isInside(int nowRow, int nowCol);
private:
    /// <summary>
    /// pre: row < BOARD_SIZE && col < BOARD_SIZE
    /// post : places a queen in each column of the calling object, beginning with the column "col", and
    ///    considering rows in that column beginning with row "row", in such a way that none of them are
    ///    under attack by any others.Returns true if successful, false if no such configuration can be
    ///    found
    /// </summary>
    /// <param name="row"></param>
    /// <param name="col"></param>
    /// <returns></returns>
    bool placeQueens(int row, int col);

    /// <summary>
    /// randomly select next row based on previous rows added
    /// </summary>
    /// <param name="addedRows"></param>
    /// <param name="row"></param>
    /// <param name="col"></param>
    /// <returns></returns>
    bool findNextSafeSquare( vector<int> addedRows, int& row, int col);

    bool isUnderAttack(int row, int col);
    /// <summary>
    /// Does a queen exist at testRow, testCol
    /// </summary>
    /// <param name="testRow"></param>
    /// <param name="testCol"></param>
    /// <returns></returns>
    bool doesQueenExist(int testRow, int testCol) const;
    vector<Queen> queens;
};

class Queen {
public:
    void setRow(int inRow);
    int getRow() const;
    void setCol(int inCol);
    int getCol() const;
    bool getAlive() const;
    void setAlive(bool alive);
    /*
    * is the queen attacking testRow,testCol position given it's current positon
    * post: @return true if testRow,testCol is under attack.
    */    
    bool isAttacking(int testRow, int testCol );
private:
    /// <summary>
    /// generate strikeRow, strikeCol that queen will hit with diagnal mode.
    /// </summary>
    /// <param name="rowDirection"> row increment </param>
    /// <param name="colDirection"> col increment </param>
    /// <param name="testRow">row we are testing for attack from queen</param>
    /// <param name="testCol">col we are testing for attack from queen</param>
    /// <param name="striketRow"> row to increment for next diagnol strike position</param>
    /// <param name="strikeCol"> col to increment for next diagnol strike position</param>
    /// <returns></returns>
    bool diagnolStrike( int rowDirection, 
                        int colDirection,
                        int testRow,
                        int testCol,
                        int & strikeRow,
                        int & strikeCol);
    
    int row;
    int col;
    bool alive;
};

bool Queen::isAttacking( int testRow, int testCol ) {
   
    if ( !Board::isInside( testRow, testCol ) ) return false;
    // horizontal and vertical trikes
    if (testRow == getRow() ||
        testCol == getCol()) {
        return true;
    }
  
    // negative direction of positive slope strike
    int rowDirection = -1;
    int colDirection = -1;
    int startRow = getRow();
    int startCol = getCol();
    if ( diagnolStrike(rowDirection, colDirection, testRow, testCol, startRow, startCol) ) {
        return true;
    }

    // positive direction of positive slope strike
    rowDirection = 1;
    colDirection = 1;    
    startRow = getRow();
    startCol = getCol();
    if ( diagnolStrike(rowDirection, colDirection, testRow, testCol, startRow, startCol) ) {
        return true;
    }

    // negative direction of negative slope strike
    rowDirection = 1;
    colDirection = -1;
    startRow = getRow();
    startCol = getCol();
    if ( diagnolStrike(rowDirection, colDirection, testRow, testCol, startRow, startCol) ) {
        return true;
    }

    // positive direction of negative slope strike
    rowDirection = -1;
    colDirection = 1;
    startRow = getRow();
    startCol = getCol();
    if ( diagnolStrike(rowDirection, colDirection, testRow, testCol, startRow, startCol) ) {
        return true;
    }

    return false;
}

bool Queen::diagnolStrike(  int rowDirection,
                            int colDirection,
                            int testRow,
                            int testCol,
                            int & striketRow,
                            int & strikeCol) {
    if( !Board::isInside(striketRow, strikeCol ) ) {
        return false;
    }
    if ( testRow == striketRow && testCol == strikeCol) {
        return true;
    }

    // determine next strike
    striketRow = striketRow + rowDirection;
    strikeCol = strikeCol + colDirection;
    return diagnolStrike( rowDirection, colDirection, testRow, testCol, striketRow, strikeCol );

}

int Queen::getRow() const {
    return row;
}

void Queen::setRow(int inRow) {
    row = inRow;
}

int Queen::getCol() const {
    return col;
}

void Queen::setCol(int inCol) {
    col = inCol;
}


bool Queen::getAlive() const {
    return alive;
}

void Queen::setAlive(bool isAlive) {
    alive = isAlive;
}

bool Board::isInside( int testRow, int testCol ) {
    if (testRow < 0) {
        //std::cout << "nowtRow is negative" << endl;
        return false;
    }
    if (testRow >= BOARD_SIZE) {
        //std::cout << "nowtRow is outside boardSize" << endl;
        return false;
    }

    if (testCol < 0) {
        //std::cout << "testCol is negative" << endl;
        return false;
    }
    if (testCol >= BOARD_SIZE) {
        //std::cout << "testCol is outside boardSize" << endl;
        return false;
    }
    return true;
}

Board::Board() {
    queens.resize(BOARD_SIZE);
}

void Board::doQueens() {
    for (size_t i = 0; i < BOARD_SIZE; i++) {
        cout << "configuration " << i << endl;
        if (placeQueens(i, 0)) {
            display();
        }
        else {
            cout << "No solution found." << endl;
        }
        cout << endl;

        // remove queens from board
        for (size_t j = 0; j < queens.size(); j++) {
            queens[j].setAlive(false);
        }
    }
}

/// <summary>
/// randomly select a number between 0 and BOARD_SIZE-1
/// </summary>
/// <returns></returns>
int getRandomRow() {
    
    return std::rand()% Board::BOARD_SIZE;
}

/// <summary>
/// does the array rowsAdded contain row
/// </summary>
/// <param name="rowsAdded"></param>
/// <param name="row"></param>
/// <returns></returns>
bool vectorContains(const vector<int>& rowsAdded, int row) {
    for (size_t i = 0; i < rowsAdded.size(); i++) {
        if (rowsAdded[i] == row) return true;
    }
    return false;
}

/// <summary>
/// select next row randomly excluding already selected rowsAdded
/// </summary>
/// <param name="rowsAdded"></param>
/// <returns></returns>
int getNextRow(const vector<int>& rowsAdded) {
    if (rowsAdded.size() >= Board::BOARD_SIZE) {
        return Board::BOARD_SIZE;
    }
    int randomRow = getRandomRow();
    if ( vectorContains(rowsAdded, randomRow) ) {
        return getNextRow( rowsAdded );
    }
    return randomRow;
}

bool Board::placeQueens(int row, int col) {
    // store list of tryed rows in the stack for each col iteration
    vector<int> rowsAdded;
    bool safePlace = findNextSafeSquare(rowsAdded,row, col);
    while (safePlace) {
        //Set the location of the Queen to row,col
        queens[col].setAlive(true);
        queens[col].setRow(row);
        queens[col].setCol(col);
        rowsAdded.push_back(row);

        if (col == (BOARD_SIZE - 1)          // last queen placed
            || placeQueens( getRandomRow(), col + 1      // place in new col, row 0
            )) {
            return true;
        }
        else {
            // remove last entry
            queens[col].setAlive(false);

            // because current row produce failure I will try next
            //rowsPass.back() = false;
            row = getNextRow(rowsAdded);
            //row++;
        }
        safePlace = findNextSafeSquare(rowsAdded,row, col);
    }

    // exited the while loop, which means that all rows in this column have been considered.
    return false;
}

bool Board::isUnderAttack(int testRow, int testCol) {
    for (size_t i = 0; i < queens.size(); i++) {
        if (!queens[i].getAlive()) continue;
        if ( queens[i].isAttacking( testRow, testCol ) ) {
            return true;
        }
    }
    return false;
}

bool Board::doesQueenExist( int testRow, int testCol) const {
    for (size_t i = 0; i < queens.size(); i++) {
        if (!queens[i].getAlive()) {
            continue;
        }
        if ( queens[i].getRow() == testRow && queens[i].getCol() == testCol ) {
            return true;
        }
    }
    return false;
}

// Sets "row" to the row of the next safe square in column col.  Important note:
// Starts with the given row and col.  In other words, the given row and col may
// be the "next safe square". 
// returns true if a safe square is found, false if no safe square is found.  If 
// return value is false, row is undefined.
bool Board::findNextSafeSquare( vector<int> addedRows,int& row, int col) {
    if ( addedRows.size() >= BOARD_SIZE ) {
        return false;
    }

    if ( !isUnderAttack( row, col ) ) {
        return true;
    }                  
    // exclude the row that is under attack
    addedRows.push_back(row);

    // row = row + 1;
    row = getNextRow(addedRows);
    return findNextSafeSquare( addedRows, row, col );
}

// Displays a visual representation of the current state of the board.  For each position
// on the board, displays "X " if a queen is located at that position, otherwise displays
// "_ " (underscore).
void Board::display() const {
    for (int _row = 0; _row < BOARD_SIZE; _row++) {
        for (int _col = 0; _col < BOARD_SIZE; _col++) {
            if ( doesQueenExist( _row, _col) ) {
                cout << "X ";
            }
            else {
                cout << "_ ";
            }
        }
        cout << endl;
    }

}

int main() {
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    Board board;
    board.doQueens();
}