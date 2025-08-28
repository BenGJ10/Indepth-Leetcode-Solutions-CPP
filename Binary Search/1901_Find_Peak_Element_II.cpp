/*
LeetCode: 1901. Find a Peak Element II
Link: https://leetcode.com/problems/find-a-peak-element-ii/

Problem:
A peak element in a 2D grid is an element that is strictly greater 
than all of its (up to) 4 neighbors (top, bottom, left, right).

You are given an m x n matrix `mat`. Return any peak position [row, col].

-------------------------------------------------------
Approach: Binary Search on Columns
1. Pick the middle column `mid`.
2. Find the maximum element in that column → row index `maxIndex`.
3. Compare it with its left and right neighbors:
   - If greater than both → peak found.
   - If smaller than right neighbor → search right half.
   - Else → search left half.
4. Continue until a peak is found.

Time Complexity: O(n * log m)  
- For each of log m columns, we scan n rows.  
Space Complexity: O(1)  
- No extra space used.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Find row index of maximum element in column `mid`
    int findMaximum(vector<vector<int>> &mat, int mid) {
        int n = mat.size();
        int index = 0;
        for (int i = 1; i < n; i++) {
            if (mat[i][mid] > mat[index][mid]) {
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int left = 0, right = m - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int maxIndex = findMaximum(mat, mid);

            int leftVal = (mid - 1 >= 0) ? mat[maxIndex][mid - 1] : -1;
            int rightVal = (mid + 1 < m) ? mat[maxIndex][mid + 1] : -1;

            if (mat[maxIndex][mid] > leftVal && mat[maxIndex][mid] > rightVal) {
                return {maxIndex, mid}; 
            } 
            else if (mat[maxIndex][mid] < rightVal) {
                left = mid + 1; 
            } 
            else {
                right = mid - 1; 
            }
        }
        return {-1, -1}; 
    }
};
