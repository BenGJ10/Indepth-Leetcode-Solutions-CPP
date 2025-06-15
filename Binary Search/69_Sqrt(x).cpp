/*
LeetCode: 69. Sqrt(x)
Link: https://leetcode.com/problems/sqrtx/

Approach:
- Use Binary Search between 1 and x to find the integer square root.
- For a mid value, check if 'mid * mid <= x'.
- Use `x / mid` instead of 'mid * mid' to avoid integer overflow.

Time Complexity: O(log x)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int left = 1, right = x, ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            // Use division instead of multiplication to prevent integer overflow
            if (mid <= x / mid) {
                ans = mid;        
                left = mid + 1;
            } else {
                right = mid - 1;  
            }
        }

        return ans;
    }
};