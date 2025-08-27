/*
LeetCode: 48. Rotate Image
Link: https://leetcode.com/problems/rotate-image/

Problem:
You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).

-------------------------------------------------------
Approach: Transpose + Reverse Rows
1. Transpose the matrix (convert rows to columns).
   - Swap matrix[i][j] with matrix[j][i] for all i < j.
2. Reverse each row.
   - This ensures the matrix is rotated by 90° clockwise.

Time Complexity: O(n^2)  
- Each element is visited at most twice (swap + reverse).  
Space Complexity: O(1)  
- In-place rotation without extra space.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step 1: Transpose the matrix
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
