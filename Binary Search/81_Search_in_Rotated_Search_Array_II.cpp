/*
LeetCode: 81. Search in Rotated Sorted Array II
Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

Problem:
You are given an integer array `nums` that may contain duplicates and was originally sorted in ascending order,
but was rotated at an unknown pivot. Determine if a given target exists in the array.

Approach:
- Modified Binary Search.
- If duplicates block clarity of sorted half, shrink boundaries: `low++` and `high--`.
- Otherwise, use standard rotated array logic to determine which half to search.

Time Complexity: O(log n) average, O(n) worst-case (all duplicates)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return true;

            // Handle duplicates at low, mid, high
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            // Checking if Left half is sorted
            else if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Checking if Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};

// nums = [1, 1, 1, 1, 2, 1, 1], target = 2, example of a condition when low, mid and high are same.