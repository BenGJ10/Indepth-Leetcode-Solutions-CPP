/* 
LeetCode: 84. Largest Rectangle in Histogram  
Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

Problem:  
Given an array of integers `heights` representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

## Brute Force Approach:
- For each bar, expand left and right while height is >= current.
- Compute area for each bar.
- Time Complexity: O(n²)
- Space Complexity: O(1)

## Optimal Approach: Monotonic Stack
- Use a stack to store increasing heights' indices.
- When a smaller height is found:
    - Pop from stack, calculate area using height of popped bar.
    - Width = distance between current index and index of new stack top (after pop).
- Do a final pass over stack to calculate area for remaining bars.

### Key Insight:
- Each bar acts as the smallest height in a potential rectangle.
- By finding previous and next smaller elements, compute width.
- Time Complexity: O(n)
- Space Complexity: O(n)
*/

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top();
                st.pop();
                int prevSmallElem = st.empty() ? -1 : st.top();
                int nextSmallElem = i;
                int area = heights[element] * (nextSmallElem - prevSmallElem - 1);
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }

        while(!st.empty()){
            int element = st.top();
            st.pop();
            int prevSmallElem = st.empty() ? -1 : st.top();
            int nextSmallElem = n;
            int area = heights[element] * (nextSmallElem - prevSmallElem - 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
