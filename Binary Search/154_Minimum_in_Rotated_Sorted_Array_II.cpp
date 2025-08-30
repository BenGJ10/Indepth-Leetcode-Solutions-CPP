/*
154. Find Minimum in Rotated Sorted Array II
Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

Problem Summary:
Given a rotated sorted array that may contain duplicates, find the minimum element.
You must achieve better than O(n) if possible, though duplicates may require O(n) in the worst case.

Brute Force Intuition:
- Simply scan the entire array and return the minimum.
- Time complexity: O(n).

Optimal Approach Intuition (Binary Search with Duplicates Handling):
- Observation: The minimum lies in the "unsorted" half of the rotated array.
- Steps:
  - If array is already sorted (first < last), return first element.
  - Use binary search:
    - If nums[mid] > nums[right], the minimum lies in the right half.
    - Else if nums[mid] < nums[right], the minimum lies in the left half (including mid).
    - Else (nums[mid] == nums[right]), decrement right to skip duplicates.
- Eventually, left will point to the minimum element.

Complexity:
- Time: O(log n) on average, O(n) in worst case due to duplicates.
- Space: O(1).
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        
        int left = 0, right = n - 1;
        if(nums[left] < nums[right])    return nums[left];

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else if(nums[mid] < nums[right]){
                right = mid;
            }
            else{
                right--;
            }
        }
        return nums[left];
    }
};
