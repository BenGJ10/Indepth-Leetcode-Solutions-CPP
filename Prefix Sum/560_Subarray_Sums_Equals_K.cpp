/*
LeetCode: 560. Subarray Sum Equals K  
Link: https://leetcode.com/problems/subarray-sum-equals-k/

Problem:  
Given an integer array `nums` and an integer `k`, return the total number of subarrays 
whose sum equals `k`.

Approach: Prefix Sum + Hash Map  
- Maintain a running prefix sum and a hash map to store prefix sum frequencies.
- For each element, check if `(prefixSum - k)` exists in the map:
    - If yes, it contributes to the count of valid subarrays.
- Increment the frequency of the current prefix sum in the map.
- Initialize `mpp[0] = 1` to handle subarrays starting from index 0.

Time Complexity: O(n) — single pass over the array.  
Space Complexity: O(n) — hash map to store prefix sums.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0, count = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1; 
        
        for (int num : nums) {
            prefixSum += num;

            if (mpp.find(prefixSum - k) != mpp.end()) {
                count += mpp[prefixSum - k];
            }
            
            mpp[prefixSum]++;
        }
        return count;
    }
};
