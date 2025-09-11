/*
414. Third Maximum Number
Link: https://leetcode.com/problems/third-maximum-number/

------------------------------------------------------
Problem Summary:
Given an integer array nums, return the **third distinct maximum** number.
If the third maximum does not exist, return the maximum number.

------------------------------------------------------
Optimal Approach (Single Pass, O(n) time / O(1) space):

Idea:
• We need the top 3 **distinct** numbers.
• Track them in three variables: max1 > max2 > max3.
• Skip duplicates so that repeated numbers don't count as distinct.

Steps:
1. Initialize max1, max2, max3 to very small values (LLONG_MIN to handle negatives).
2. Iterate through nums:
   - Skip the number if it's equal to any of the current maxima.
   - If it's larger than max1 → shift down (max3 = max2, max2 = max1, max1 = num).
   - Else if it's larger than max2 → shift down (max3 = max2, max2 = num).
   - Else if it's larger than max3 → set max3 = num.
3. After loop:
   - If max3 is still LLONG_MIN, it means fewer than 3 distinct numbers → return max1.
   - Otherwise return max3.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1 = LLONG_MIN, max2 = LLONG_MIN, max3 = LLONG_MIN;

        for (int num : nums) {
            if (num == max1 || num == max2 || num == max3) continue; // skip duplicates

            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num > max2) {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3) {
                max3 = num;
            }
        }

        return max3 == LLONG_MIN ? static_cast<int>(max1) : static_cast<int>(max3);
    }
};
