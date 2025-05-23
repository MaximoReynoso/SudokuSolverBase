#include <iostream>
#define SIZE_M 9

using namespace std;

bool valid(int matrix[][SIZE_M], int row, int column, int num);
bool Sudoku(int matrix[][SIZE_M], int row, int column);

int main(){


    return 0;
}

bool Sudoku(int matrix[][SIZE_M], int row, int column){
    if (row == SIZE_M) {
        return true;
    }

    if (column == SIZE_M){
        row++;
        column = 0;
    }

    for (int i = 0; i < SIZE_M-1; i++){
        if (valid(matrix, row, column, i)){
            matrix[row][column] = i;
            if (Sudoku(matrix, row, column++))
                return true;
            matrix[row][column] = 0;
        }
    }
    return false;
}


bool valid(int matrix[][SIZE_M], int row, int column, int num){
    for (int i = 0; i < SIZE_M-1; i++){
        if (matrix[row][i] == num)
            return false;
    }

    for (int j = 0; j < SIZE_M-1; j++){
        if (matrix[j][column] == num)
            return false;
    }

    int posI = row - (row%3);
    int posJ = column - (column%3);

    for (int indexI = 0; indexI < 3; indexI++)
        for (int indexJ = 0; indexJ < 3; indexJ++)
            if (matrix[posI+indexI][posJ+indexJ] == num)
                return false;
    return true;
}
