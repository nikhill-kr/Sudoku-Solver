#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool safe(int row, int col, vector<vector<int> > &sudoku, int value)
{
    int n = sudoku.size();
    for (int i = 0; i < n; i++)
    {
        // row check:that value should be unique in that entire row
        if (sudoku[row][i] == value)
        {
            return false;
        }
        // column check:that value should be unique in that entire column
        if (sudoku[i][col] == value)
        {
            return false;
        }
        // small 3*3 grid check:in that grid all numbers must be unique
        if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int> > &sudoku)
{
    int n = sudoku.size(); // for number of rows and columns;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (sudoku[row][col] == 0) // if cell is empty or not
            {
                for (int value = 1; value <= 9; value++)
                {
                    if (safe(row, col, sudoku, value)) // To check if we can put that value in that empty cell or not
                    {
                        sudoku[row][col] = value; // if we can put that value then fill that empty cell with that value
                        // recurcise call
                        bool nxtSol = solve(sudoku);
                        if (nxtSol)
                        {
                            return true;
                        }
                        else
                        {
                            // backtrack
                            sudoku[row][col] = 0; // if value is not possible then we will again empty that cell and assign it 0
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int> > sudoku(9);
    for (int i = 0; i < 9; i++)
    {

        for (int j = 0; j < 9; j++)
        {
            int temp;
            cin >> temp;
            sudoku[i].push_back(temp);
        }
    }
    solve(sudoku);
    cout<<endl;
    //printing the solved sudoku
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<sudoku[i][j]<<' ';
        }
        cout<<endl;
    }


    return 0;
}