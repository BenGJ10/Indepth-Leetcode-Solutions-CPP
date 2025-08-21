/*
LeetCode: 73. Set Matrix Zeroes
Link: https://leetcode.com/problems/set-matrix-zeroes/

Problem:
Given an m x n integer matrix, if an element is 0, set its entire row and column to 0’s.
You must do it in place.

-------------------------------------------------------
Brute Force Approach:
- Traverse the matrix.
- Whenever a cell with 0 is found, mark all elements in that row and column with a placeholder (say -1) except the already 0 elements.
- After traversal, replace all placeholders with 0.
Time Complexity: O((m*n) * (m+n)) ≈ O(m^2 * n + m * n^2)
Space Complexity: O(1) extra (but modifies in multiple passes).

-------------------------------------------------------
Optimal Approach: Using First Row & First Column as Markers
- Use matrix’s first row and column as storage to mark which rows/columns need to be zeroed.
- Additionally, use a variable col0 to handle the first column separately.
- Steps:
  1. Traverse the matrix, mark row[i]=0 and col[j]=0 if matrix[i][j]==0.
  2. Traverse again (excluding first row/col) and set matrix[i][j]=0 if its row/col is marked.
  3. Finally handle first row and first column separately.
Time Complexity: O(m * n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        int n = matrix.size();
        int m = matrix[0].size();

        // Step 1: Mark the rows and columns
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j != 0) {
                        matrix[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }

        // Step 2: Zero out cells based on markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] != 0) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // Step 3: Handle first row
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle first column
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
