/*
LeetCode: 2461. Maximum Sum of Distinct Subarrays With Length K  
Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

Problem:  
Given an integer array `nums` and an integer `k`, find the maximum sum of a subarray of length `k` where all elements are distinct. Return 0 if no such subarray exists.

Approach: Sliding Window + HashMap  
- Maintain a sliding window of size `k` using two pointers (`left` and `right`).
- Use a hashmap to track frequency of elements in the window.
- For every window of size `k`:
  - If all elements are distinct (`mpp.size() == k`), update `maxSum`.
  - Slide the window forward by removing the leftmost element.

Time Complexity: O(n)  
Space Complexity: O(k)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        long long currSum = 0, maxSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            currSum += nums[right];
            mpp[nums[right]]++;

            if (right - left + 1 > k) { 
                currSum -= nums[left];
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }

            if (mpp.size() == k && right - left + 1 == k) {
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};
