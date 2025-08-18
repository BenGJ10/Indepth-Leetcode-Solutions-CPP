/*
LeetCode: 287. Find the Duplicate Number
Link: https://leetcode.com/problems/find-the-duplicate-number/

Problem:
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive,
there is only one repeated number in nums. Return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.

-------------------------------------------------------
Approach / Insight:
Brute Force:
- Use a hash set to track seen numbers.
- If a number is already seen, return it.
- Time O(n), Space O(n).

Better Approach:
- Sort the array and check adjacent elements.
- Time O(n log n), Space O(1) if sorting in-place, but it modifies the array.

Optimal Approach: Floyd’s Cycle Detection (Tortoise and Hare)
- Treat the array as a linked list where the value at each index points to the next node.
- Because there’s a duplicate, a cycle must exist.
- Use slow and fast pointers to detect the cycle.
- Reset one pointer to the start, then move both one step at a time until they meet → that meeting point is the duplicate.
- Time O(n), Space O(1).

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        // Phase 1: Detect cycle
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // Phase 2: Find entry point of cycle
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
