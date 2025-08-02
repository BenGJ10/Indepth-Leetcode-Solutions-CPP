/*
LeetCode: 525. Contiguous Array  
Link: https://leetcode.com/problems/contiguous-array/

Problem:  
Given a binary array `nums`, return the length of the longest contiguous subarray 
with an equal number of 0s and 1s.

Approach: Prefix Sum + Hash Map  
- Convert 0 to -1 and treat the problem as finding the longest subarray with a sum of 0.
- Maintain a `prefixSum` and store its first occurrence index in a hash map.
- If the same prefix sum appears again, it means the subarray between these indices has equal 0s and 1s.

Time Complexity: O(n)  
Space Complexity: O(n)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int prefixSum = 0, maxLen = 0;
        mpp[0] = -1;  // Handle case when prefix itself forms a valid subarray

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += (nums[i] == 1 ? 1 : -1);
            if (mpp.find(prefixSum) != mpp.end()) {
                maxLen = max(maxLen, i - mpp[prefixSum]);
            } else {
                mpp[prefixSum] = i;
            }
        }
        return maxLen;
    }
};