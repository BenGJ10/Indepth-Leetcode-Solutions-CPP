/*
LeetCode: 540. Single Element in a Sorted Array
Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

Problem:
You are given a sorted array where every element appears exactly twice, except for one element which appears only once.
Return that single element in O(log n) time and O(1) space.

Approach: Binary Search
- Use the property that pairs start at even indices:
  - If `mid` is even and nums[mid] == nums[mid+1], the unique element is on the right.
  - If `mid` is odd and nums[mid] == nums[mid-1]`, the unique element is on the right.
  - Else, it’s on the left.

Time Complexity: O(log n)  
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(const vector<int>& nums) {
        int n = nums.size();

        // Edge cases: first or last element
        if (n == 1 || nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // Decide search direction based on pair alignment
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1; 
    }
};
