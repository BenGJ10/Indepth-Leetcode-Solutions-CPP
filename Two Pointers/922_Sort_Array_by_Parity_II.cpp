/*
922. Sort Array By Parity II
Link: https://leetcode.com/problems/sort-array-by-parity-ii/

------------------------------------------------------
Problem Summary:
Given an array of even length n where:
    - Exactly n/2 elements are even
    - Exactly n/2 elements are odd
We need to rearrange the array so that:
    - Even indices contain even numbers
    - Odd indices contain odd numbers

------------------------------------------------------
Brute Force Approach:
- Collect all even numbers and all odd numbers into two separate arrays.
- Place evens at even indices and odds at odd indices.
- Works fine but requires extra space.
- Time Complexity: O(n)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (In-place, Two Pointers):
1. Maintain two pointers:
   - `even` → points to even indices (0, 2, 4, …)
   - `odd` → points to odd indices (1, 3, 5, …)
2. Traverse until both are within bounds:
   - If nums[even] is even → move `even` forward by 2.
   - If nums[odd] is odd → move `odd` forward by 2.
   - If mismatch (nums[even] is odd & nums[odd] is even) → swap them.
3. Continue until the array is arranged.

- Time Complexity: O(n) → single pass with constant-time operations.
- Space Complexity: O(1) → done in-place.

------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int odd = 1, even = 0;

        while (odd < n && even < n) {
            if (nums[even] % 2 == 0) {
                even += 2; // correct placement, move ahead
            } 
            else if (nums[odd] % 2 != 0) {
                odd += 2; // correct placement, move ahead
            } 
            else {
                swap(nums[even], nums[odd]); // mismatch → fix by swapping
            }
        }
        return nums;
    }
};
