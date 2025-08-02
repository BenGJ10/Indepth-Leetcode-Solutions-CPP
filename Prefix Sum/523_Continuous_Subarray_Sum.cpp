/*
LeetCode: 523. Continuous Subarray Sum  
Link: https://leetcode.com/problems/continuous-subarray-sum/

Problem:  
Given an integer array `nums` and an integer `k`, return true if there exists a subarray 
of length ≥ 2 whose sum is a multiple of `k`. Otherwise, return false.

Approach: Prefix Sum + Modulo  
- Maintain a prefix sum and track its modulo `k` in a hash map.
- If the same modulo appears twice (at indices `i` and `j` with `j - i >= 2`), 
  the sum of elements between them is divisible by `k`.
- Initialize `remainder[0] = -1` to handle subarrays starting from index 0.

Time Complexity: O(n)  
Space Complexity: O(n)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;

        unordered_map<int, int> remainder;
        remainder[0] = -1; // handles subarrays starting at index 0
        int prefixSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int mod = prefixSum % k;
            if (remainder.find(mod) != remainder.end()) {
                if (i - remainder[mod] >= 2) return true;
            } else {
                remainder[mod] = i;
            }
        }
        return false;
    }
};