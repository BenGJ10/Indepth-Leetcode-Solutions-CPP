/*
LeetCode: 54. Spiral Matrix
Link: https://leetcode.com/problems/spiral-matrix/

Problem:
Given an m x n matrix, return all elements of the matrix in spiral order.

-------------------------------------------------------
Approach:
- Use four boundaries: top, bottom, left, right.
- Traverse the matrix layer by layer in 4 steps:
    1. Traverse the top row from left → right
    2. Traverse the right column from top → bottom
    3. Traverse the bottom row from right → left (if still valid)
    4. Traverse the left column from bottom → top (if still valid)
- After each step, shrink the respective boundary.
- Continue until all elements are traversed.

Time Complexity: O(m * n)  
- Each element is visited once.  
Space Complexity: O(1) (excluding output vector).
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();       
        int m = matrix[0].size();    

        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;

        while (left <= right && top <= bottom) {
            // 1. Traverse top row (left → right)
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;

            // 2. Traverse right column (top → bottom)
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // 3. Traverse bottom row (right → left), if valid
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // 4. Traverse left column (bottom → top), if valid
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
