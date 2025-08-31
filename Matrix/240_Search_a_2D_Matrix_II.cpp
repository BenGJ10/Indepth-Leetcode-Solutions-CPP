/*
74. Search a 2D Matrix
Link: https://leetcode.com/problems/search-a-2d-matrix/

Problem Summary:
You are given a 2D matrix where:
- Each row is sorted in ascending order.
- The first integer of each row is greater than the last integer of the previous row.
Check if a given target exists in the matrix.

Brute Force Intuition:
- Traverse all rows and columns, compare each element with the target.
- Time complexity: O(n * m).

Optimal Approach Intuition (Staircase Search):
- Start from the top-right corner:
  - If element == target → found.
  - If element < target → move down (increase row).
  - If element > target → move left (decrease column).
- This works because rows are sorted left→right and columns top→bottom.

Complexity:
- Time: O(n + m) since we either move down or left at each step.
- Space: O(1), no extra storage used.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0, col = m - 1;
        while(row < n && col >= 0){
            if(matrix[row][col] == target)  
                return true;
            else if(matrix[row][col] < target)  
                row++;
            else  
                col--;
        }
        return false;
    }
};
