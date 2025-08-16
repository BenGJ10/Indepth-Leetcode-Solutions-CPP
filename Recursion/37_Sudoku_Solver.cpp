/*
LeetCode: 37. Sudoku Solver
Link: https://leetcode.com/problems/sudoku-solver/

Problem:
Write a program to solve a Sudoku puzzle by filling the empty cells.
A Sudoku solution must satisfy all the following rules:
- Each of the digits 1-9 must occur exactly once in each row.
- Each of the digits 1-9 must occur exactly once in each column.
- Each of the digits 1-9 must occur exactly once in each of the 9 sub-boxes of the grid.
The '.' character indicates empty cells.

-------------------------------------------------------
Approach / Insight:
Brute Force:
- Try placing each number from 1 to 9 in every empty cell and check validity.
- Backtrack if the placement violates Sudoku rules.
- Extremely inefficient without pruning.

Optimal Approach: Backtracking with Validity Check
- Traverse the board cell by cell.
- If an empty cell is found, attempt to place digits '1' to '9'.
- Use a helper function `isValid` to check if placing the digit respects Sudoku constraints:
  - Row check
  - Column check
  - 3x3 sub-grid check
- If valid, place the digit and recurse further.
- If at any point no digit can be placed, backtrack and reset the cell.
- Continue until the board is completely filled.

Time Complexity: O(9^(m)) where m = number of empty cells.
Space Complexity: O(m) recursion stack depth.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);        
    }

    bool solve(vector<vector<char>> &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch) return false;
            if (board[row][i] == ch) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) return false;
        }
        return true;
    }
};
