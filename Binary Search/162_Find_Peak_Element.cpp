/*
LeetCode: 162. Find Peak Element
Link: https://leetcode.com/problems/find-peak-element/

Problem:
A peak element is one that is strictly greater than its neighbors.
Given an array `nums`, return the index of **any one peak**.
Assume nums[-1] = nums[n] = -∞ (virtual bounds).

Approach: Binary Search
- If mid element is less than its next element, peak lies to the right.
- If mid is greater than its next, the peak lies on the left or is mid itself.
- Handles single-element and edge cases explicitly.

Time Complexity: O(log n)  
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int>& nums) {
        int n = nums.size();

        // Handle single-element or edge peaks
        if (n == 1 || nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int left = 1, right = n - 2; // interior range only as we have already checked the egdes

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid; 
            }
            else if (nums[mid] < nums[mid + 1]) {
                left = mid + 1; 
            } 
            else {
                right = mid - 1;
            }
        }

        return -1;
    }
};
