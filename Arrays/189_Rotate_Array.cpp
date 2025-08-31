/*
189. Rotate Array
Link: https://leetcode.com/problems/rotate-array/

Problem Summary:
Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

Example:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

------------------------------------------------------
Brute Force Intuition:
- Rotate the array one step at a time, k times.
- Each rotation moves the last element to the front and shifts the rest.
- Time Complexity: O(n * k) (too slow for large k).
- Space Complexity: O(1).

Better Approach:
- Use an extra array:
  - Place each element at its new rotated position: new_index = (i + k) % n.
- Copy back to original array.
- Time: O(n), Space: O(n).

Optimal Approach (Reversal Algorithm):
- Key idea: Reversing portions of the array can simulate rotation efficiently.
Steps:
1. Reverse the entire array.
2. Reverse the first k elements.
3. Reverse the remaining n-k elements.
- Time: O(n)
- Space: O(1)

------------------------------------------------------
Dry Run (nums = [1,2,3,4,5,6,7], k = 3):
Step 1: Reverse entire array → [7,6,5,4,3,2,1]
Step 2: Reverse first 3 → [5,6,7,4,3,2,1]
Step 3: Reverse last 4 → [5,6,7,1,2,3,4]
Final Answer = [5,6,7,1,2,3,4]
------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());           // Step 1
        reverse(nums.begin(), nums.begin() + k);     // Step 2
        reverse(nums.begin() + k, nums.end());       // Step 3
    }
};
