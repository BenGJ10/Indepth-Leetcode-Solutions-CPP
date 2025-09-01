/*
75. Sort Colors
Link: https://leetcode.com/problems/sort-colors/

Problem Summary:
Given an array `nums` with n objects colored red (0), white (1), or blue (2),
sort them in-place so that objects of the same color are adjacent, with colors
in the order red → white → blue.

------------------------------------------------------
Brute Force Intuition:
- Just sort the array using any sorting algorithm like QuickSort / MergeSort.
- Or use built-in sort.
- Time Complexity: O(n log n)
- Space Complexity: O(1) (if in-place sort is used).

Better Approach (Counting Sort):
- Count the number of 0s, 1s, and 2s.
- Overwrite the array with that many 0s, then 1s, then 2s.
- Time Complexity: O(n)
- Space Complexity: O(1)

Optimal Approach (Dutch National Flag Algorithm):
- Use three pointers: low, mid, high.
- Maintain the invariant:
    - nums[0..low-1] = 0
    - nums[low..mid-1] = 1
    - nums[high+1..n-1] = 2
- Traverse with mid pointer:
    - If nums[mid] == 0 → swap with low, increment both.
    - If nums[mid] == 1 → just increment mid.
    - If nums[mid] == 2 → swap with high, decrement high.
- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++; mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{ // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

