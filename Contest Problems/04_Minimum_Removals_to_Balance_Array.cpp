/*
Biweekly Contest 162: Minimum Removals to Balance Array

Problem:  
You are given an integer array `nums` and an integer `k`.
An array is considered balanced if max(nums) ≤ min(nums) * k.
You may remove any number of elements (but not all).
Return the minimum number of elements to remove so that the remaining array is balanced.

Approach: Two-Pointer / Sliding Window after Sorting
- Sort the array.
- Use two pointers (left, right) to maintain the largest balanced subarray:
  - While nums[right] > nums[left] * k, move left forward (shrink window).
  - Track the maximum window size where balance condition holds.
- Result = total elements - size of the largest balanced window.

Time Complexity: O(n log n) (sorting + O(n) sliding window)  
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int minimumRemovals(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, maxBalanced = 0;

        for (int right = 0; right < n; right++) {
            while (nums[right] > 1LL * nums[left] * k) {
                left++; 
            }
            maxBalanced = max(maxBalanced, right - left + 1);
        }

        return n - maxBalanced;
    }
};