# Sudoku-Solver

A Sudoku solver is a program or algorithm that solves Sudoku puzzles. Sudoku is a logic-based puzzle that involves filling a 9x9 grid with digits from 1 to 9. The grid is divided into nine 3x3 subgrids, and the goal is to fill in the digits so that each column, each row, and each 3x3 subgrid contains all of the digits from 1 to 9 without repetition.


**How code is Working?**

The safe function determines if it is safe to enter a value into a certain Sudoku grid cell. It accepts as arguments the row, column, Sudoku grid, and the value to be verified. It checks three requirements to guarantee that the value is not duplicated in the same row, column, or 3x3 subgrid. If any of these requirements are not met, the function returns false, indicating that the value should not be placed. If not, it returns true.
To solve the Sudoku problem, the solution function use the backtracking method. The Sudoku grid is used as a parameter. It iterates through each cell in the grid using a nested loop. If a cell is empty (represented by 0), it attempts to insert values from 1 to 9 in that cell and uses the safe function to see whether this is safe. If the value is safe, it is placed in the cell, and the solution function is used recursively to solve the remaining empty cells. If the recursive call returns true, the riddle has been solved, and the function has returned true. If the recursive function returns false, it indicates that the value entered into the current cell is invalid, and retracing happens by assigning 0 to the cell and trying the next value. If no valid value for the current cell is discovered, the method returns false.
