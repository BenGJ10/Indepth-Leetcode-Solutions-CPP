/*
LeetCode: 268. Missing Number
Link: https://leetcode.com/problems/missing-number/

Problem:
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.

-------------------------------------------------------
Approach / Insight:
Brute Force:
- Use an auxiliary array of size n+1 to mark presence of numbers.
- Traverse nums and mark elements.
- Finally, the index that remains unmarked is the missing number.
- This approach works but uses extra O(n) space.

Optimal Approaches:
1. Mathematical Formula:
   - The sum of numbers from 0 to n is n*(n+1)/2.
   - Subtract the sum of nums from this value to find the missing number.
   - Time: O(n), Space: O(1).
   
2. XOR Trick:
   - XOR all numbers from 0 to n and also XOR all numbers in nums.
   - The result is the missing number because duplicates cancel out.
   - Time: O(n), Space: O(1).

Time Complexity: O(n)  
Space Complexity: O(1) (for XOR/Math method)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2;
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return total - sum;
    }
};
