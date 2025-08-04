/*
LeetCode: 53. Maximum Subarray  
Link: https://leetcode.com/problems/maximum-subarray/

Problem:  
Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Approach: Kadane’s Algorithm  
- Maintain a running sum (`sum`), adding each element sequentially.
- Update `maxSum` whenever `sum` exceeds it.
- If `sum` becomes negative, reset it to 0 (as starting a new subarray is better).

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if (sum < 0) sum = 0; // Reset when sum becomes negative
        }
        return maxSum;
    }
};