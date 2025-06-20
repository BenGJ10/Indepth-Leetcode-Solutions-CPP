/*
LeetCode: 34. Find First and Last Position of Element in Sorted Array
Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Problem:
Given a sorted array `nums` and a target value, return the indices of the first and last occurrence of the target.
If not found, return [-1, -1].

Approach:
- Use binary search twice:
  1. First to find the **first** occurrence (move `high = mid - 1` when found).
  2. Second to find the **last** occurrence (move `low = mid + 1` when found).

Time Complexity: O(log n)  
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        if (first == -1) return {-1, -1};
        int last = findLast(nums, target);
        return {first, last};
    }

private:
    int findFirst(const vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int pos = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                pos = mid;
                high = mid - 1;  
            } 
            else if (nums[mid] < target) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return pos;
    }

    int findLast(const vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int pos = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                pos = mid;
                low = mid + 1;  
            } 
            else if (nums[mid] < target) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return pos;
    }
};
