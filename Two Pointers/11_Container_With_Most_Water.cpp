/*
LeetCode: 11. Container With Most Water
Link: https://leetcode.com/problems/container-with-most-water/

Given `n` vertical lines represented by an array of integers, where each line's height is given, 
find two lines that together with the x-axis form a container such that the container holds the most water.

Approach: Two-Pointer Technique
- Start with two pointers at the extremes.
- Calculate area at each step: min(height[left], height[right]) * (right - left).
- Move the pointer pointing to the shorter line inward to try for a taller line and possibly a larger area.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &heights) {
        int left = 0, right = heights.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int width = right - left;
            int height = min(heights[left], heights[right]);
            int area = width * height;
            maxArea = max(maxArea, area);

            heights[left] <= heights[right] ? left++ : right--;
        }

        return maxArea;
    }
};