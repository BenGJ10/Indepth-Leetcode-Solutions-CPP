/*
4. Median of Two Sorted Arrays
Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

------------------------------------------------------
Problem Summary:
You are given two sorted arrays nums1 and nums2 of size n and m respectively.  
Return the median of the two sorted arrays.  
The overall run time complexity should be O(log(min(n, m))).

------------------------------------------------------
Brute Force Approach (Merge & Find Median):
1. Merge both arrays into a single sorted array.
2. If total length is odd → return the middle element.
3. If even → return average of the two middle elements.

- Time Complexity: O(n + m) → merging both arrays.
- Space Complexity: O(n + m) → extra space for merged array.

------------------------------------------------------
Optimal Approach (Binary Search Partition – O(log(min(n, m)))):
1. Use binary search on the smaller array to partition both arrays.
2. Ensure elements on the left of the partition are ≤ elements on the right.
3. Median will come from the max of left side and min of right side:
   - Odd length → median is max(left_part).
   - Even length → median is average of max(left_part) and min(right_part).
   
- Time Complexity: O(log(min(n, m)))
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        vector<int> merged;

        // Merge the two sorted arrays
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i++]);
            } else {
                merged.push_back(nums2[j++]);
            }
        }
        while (i < n) merged.push_back(nums1[i++]);
        while (j < m) merged.push_back(nums2[j++]);

        // Find the median
        int totalSize = merged.size();
        if (totalSize % 2 == 1) {
            return static_cast<double>(merged[totalSize / 2]);
        } else {
            int mid1 = merged[(totalSize / 2) - 1];
            int mid2 = merged[(totalSize / 2)];
            return (static_cast<double>(mid1) + static_cast<double>(mid2)) / 2.0;
        }
    }
};

