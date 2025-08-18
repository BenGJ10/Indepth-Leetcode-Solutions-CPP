/*
LeetCode: 1752. Check if Array Is Sorted and Rotated
Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

Problem:
Given an array nums, return true if the array was originally sorted in non-decreasing order, 
then rotated some number of positions (including zero). Otherwise, return false.

-------------------------------------------------------
Approach / Insight:
Brute Force:
- Try all rotations of the array and check if any of them is sorted.
- This takes O(n^2) time.

Optimal Approach:
- Count the number of "drops" (where nums[i] > nums[i+1]).
- For a sorted and rotated array, there can be at most one drop.
- If there are more than one, return false.
- Alternatively, simulate rotation by iterating over indices modulo n and checking sortedness.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        int count = 1;
        for (int i = 1; i < 2 * n; i++) {
            if (nums[i % n] >= nums[(i - 1) % n]) {
                count++;
            } else {
                count = 1;
            }
            if (count == n) return true;
        }
        return false;
    }
};
