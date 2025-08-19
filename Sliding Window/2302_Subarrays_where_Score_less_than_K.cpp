/*
LeetCode: 2302. Count Subarrays Where the Score Is Less Than k
Link: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

Problem:
The score of an array is defined as the sum of its elements multiplied by its length.  
Given an integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

-------------------------------------------------------
Approach / Insight:
Brute Force:
- Generate all possible subarrays, compute sum and score for each.
- Count those with score < k.
- This takes O(n^2) time for subarray generation and O(n^3) if recomputing sums each time.

Optimal Approach: Sliding Window (Two Pointers)
- Maintain a sliding window [left, right].
- Expand right and keep adding nums[right] to the current sum.
- While score (sum * length) >= k, shrink the window from the left.
- For each position of right, the number of valid subarrays ending at right is (right - left + 1).
- Add this count to the result.
- This ensures every subarray is counted exactly once in O(n) time.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int left = 0, right = 0;
        long long sum = 0, count = 0;

        while (right < (int)nums.size()) {
            sum += nums[right];
            while (left <= right && sum * (right - left + 1LL) >= k) {
                sum -= nums[left++];
            }
            count += (right - left + 1LL);
            right++;
        }
        return count;
    }
};
