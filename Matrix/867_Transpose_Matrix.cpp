/*
LeetCode: 867. Transpose Matrix
Link: https://leetcode.com/problems/transpose-matrix/

Problem:
Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is obtained by flipping it over its main diagonal,
switching the matrix's row and column indices.

-------------------------------------------------------
Approach:
1. Create a result matrix of size m x n (rows become columns).
2. For each cell in the original matrix at (i, j), 
   assign result[j][i] = matrix[i][j].

Time Complexity: O(n * m)  
- Each element is visited once.  
Space Complexity: O(n * m)  
- A new matrix is created to store the transpose.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();       // number of rows
        int m = matrix[0].size();    // number of columns
        
        // Initialize result matrix with swapped dimensions
        vector<vector<int>> result(m, vector<int>(n));
        
        // Fill result with transposed values
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }
};
