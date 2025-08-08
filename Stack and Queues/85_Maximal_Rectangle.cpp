/* 
LeetCode: 85. Maximal Rectangle  
Link: https://leetcode.com/problems/maximal-rectangle/

Problem:  
Given a 2D binary matrix filled with '0's and '1's, find the largest rectangle containing only 1's and return its area.

## Brute Force Approach:
- For every cell, expand down and right to find the maximal rectangle.
- Time Complexity: O(n³)
- Space Complexity: O(1)

## Optimal Approach: Histogram + Largest Rectangle in Histogram
- Treat each row as the base of a histogram.
- For each row, maintain a height array (`colsArea`) counting consecutive 1's vertically.
- For each updated row, calculate the largest rectangle using monotonic stack (like in histogram problem).

### Key Insight:
- Convert the 2D matrix problem to a series of 1D histogram problems.
- Apply monotonic stack strategy for each row.
- Time Complexity: O(n * m)
- Space Complexity: O(m)
*/

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &nums){
        int n = nums.size();
        int maxArea = 0;
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                int element = st.top();
                st.pop();
                int prevSmallElem = st.empty() ? -1 : st.top();
                int nextSmallElem = i;
                int area = nums[element] * (nextSmallElem - prevSmallElem - 1);
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int element = st.top();
            st.pop();
            int prevSmallElem = st.empty() ? -1 : st.top();
            int nextSmallElem = n;
            int area = nums[element] * (nextSmallElem - prevSmallElem - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxArea = 0;
        vector<int> colsArea(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    colsArea[j]++;
                }
                else{
                    colsArea[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(colsArea));
        }

        return maxArea;
    }
};
