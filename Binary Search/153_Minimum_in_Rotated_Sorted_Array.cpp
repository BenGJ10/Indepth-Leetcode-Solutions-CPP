/*
LeetCode: 153. Find Minimum in Rotated Sorted Array
Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Problem:
Given a rotated sorted array with no duplicates, find the minimum element.

Approach:
- Use binary search.
- If the subarray is already sorted (nums[low] <= nums[high]), return nums[low].
- Else:
  - If left half is sorted, minimum must be in right half → move low = mid + 1
  - If right half is unsorted, minimum is in left half → move high = mid

Time Complexity: O(log n)  
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            if(nums[low] <= nums[high])  return nums[low];
            
            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid]) {
                // Minimum is in the right half
                low = mid + 1;
            } 
            else {
                // Minimum could be mid or to the left
                high = mid;
            }
        }

        return nums[low];  // low == high is the minimum index
    }
};
