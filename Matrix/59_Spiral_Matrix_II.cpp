/*
LeetCode: 59. Spiral Matrix II
Link: https://leetcode.com/problems/spiral-matrix-ii/

Problem:
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n^2 in spiral order.

-------------------------------------------------------
Approach:
- Use four boundary pointers: left, right, top, bottom.
- Start filling numbers from 1 to n^2 while spiraling:
  1. Fill top row left → right.
  2. Fill right column top → bottom.
  3. Fill bottom row right → left.
  4. Fill left column bottom → top.
- After each step, move the corresponding boundary inward.
- Continue until all numbers are filled.

Time Complexity: O(n^2)  
- Every cell is filled exactly once.  
Space Complexity: O(1) extra (apart from result matrix).
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int num = 1;

        while (left <= right && top <= bottom) {
            // Fill top row
            for (int i = left; i <= right; i++) {
                matrix[top][i] = num++;
            }
            top++;

            // Fill right column
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num++;
            }
            right--;

            // Fill bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = num++;
                }
                bottom--;
            }

            // Fill left column
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num++;
                }
                left++;
            }
        }

        return matrix;
    }
};
