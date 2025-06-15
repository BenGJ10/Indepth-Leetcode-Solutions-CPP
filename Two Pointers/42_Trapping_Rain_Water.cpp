/*
LeetCode: 42. Trapping Rain Water
Link: https://leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

Approach: Two Pointers with Constant Space
- Move two pointers inward from both ends.
- Maintain leftMax and rightMax values.
- Water is trapped if the current height is less than the min(leftMax, rightMax).
- Add water trapped at each position as you move.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] < leftMax) {
                    totalWater += leftMax - height[left];
                } else {
                    leftMax = height[left];
                }
                left++;
            } 
            else {
                if (height[right] < rightMax) {
                    totalWater += rightMax - height[right];
                } else {
                    rightMax = height[right];
                }
                right--;
            }
        }

        return totalWater;
    }
};