/*
LeetCode: 74. Search a 2D Matrix
Link: https://leetcode.com/problems/search-a-2d-matrix/

Problem:
You are given an m x n integer matrix matrix with the following properties:
1. Each row is sorted in non-decreasing order.
2. The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

-------------------------------------------------------
Approach: Binary Search on Flattened Matrix
1. Treat the 2D matrix as a 1D sorted array of length (n * m).
2. Perform standard binary search:
   - mid / m → row index
   - mid % m → column index
3. Compare matrix[row][col] with target and adjust search boundaries.

Time Complexity: O(log(n * m))  
- Standard binary search over n*m elements.  
Space Complexity: O(1)  
- No extra space used.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();         
        int m = matrix[0].size();      
        int left = 0, right = n * m - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int row = mid / m;         
            int col = mid % m;         

            if (matrix[row][col] == target) {
                return true;
            } 
            else if (matrix[row][col] > target) {
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }
        return false;
    }
};
