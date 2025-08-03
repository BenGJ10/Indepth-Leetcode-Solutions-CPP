/*
LeetCode: 304. Range Sum Query 2D - Immutable  
Link: https://leetcode.com/problems/range-sum-query-2d-immutable/

Problem:  
Given a 2D matrix, handle multiple queries of the form `sumRegion(row1, col1, row2, col2)`,  
returning the sum of elements in that submatrix.

Approach: 2D Prefix Sum  
- Precompute a prefix sum matrix `prefixSum` where `prefixSum[i][j]` stores the sum of the submatrix from (0,0) to (i-1,j-1).  
- Use the inclusion-exclusion principle to compute submatrix sums in O(1) per query:
    sumRegion = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1]

Time Complexity:  
- Preprocessing: O(n * m)  
- Query: O(1) per sumRegion  

Space Complexity: O(n * m)
*/

#include <iostream>
using namespace std;
class NumMatrix {
private:
    vector<vector<int>> prefixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefixSum = vector<vector<int>>(n + 1, vector<int> (m + 1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                prefixSum[i][j] = matrix[i - 1][j - 1] + 
                               prefixSum[i - 1][j] + 
                               prefixSum[i][j - 1] - 
                               prefixSum[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixSum[row2 + 1][col2 + 1] -
               prefixSum[row1][col2 + 1] - 
               prefixSum[row2 + 1][col1] + 
               prefixSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */