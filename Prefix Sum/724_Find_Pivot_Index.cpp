/*
LeetCode: 724. Find Pivot Index  
Link: https://leetcode.com/problems/find-pivot-index/

Problem:  
Given an array `nums`, return the **pivot index** where the sum of all elements to the left equals 
the sum of all elements to the right. If no such index exists, return -1.

Approach: Prefix Sum  
- First, compute the total sum of the array.
- Iterate through each index `i`:
  - If `prefixSum == totalSum - prefixSum - nums[i]`, `i` is the pivot index.
  - Otherwise, keep adding `nums[i]` to `prefixSum`.
- If no pivot is found, return -1.

Time Complexity: O(n) — single pass to compute sum + single pass to find pivot.  
Space Complexity: O(1) — constant extra space.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (prefixSum == (totalSum - prefixSum - nums[i])) {
                return i;
            }
            prefixSum += nums[i];
        }
        return -1;
    }
};
