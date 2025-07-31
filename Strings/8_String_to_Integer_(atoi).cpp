/*
LeetCode: 8. String to Integer (atoi)  
Link: https://leetcode.com/problems/string-to-integer-atoi/

Problem:  
Implement the `atoi` function which converts a string to a 32-bit signed integer.  
- Ignore leading whitespaces.
- Consider an optional '+' or '-' sign.
- Read digits until a non-digit character is found.
- Clamp result within the range [-2^31, 2^31 - 1].

Approach:
1. Skip leading whitespaces.
2. Determine the sign if present.
3. Parse digits and build the result while checking for overflow.
4. Return the final value with sign applied.

Time Complexity: O(n) — single pass through the string.  
Space Complexity: O(1) — constant extra space.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, i = 0, n = s.length();
        long result = 0;

        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // 2. Check for optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            // Overflow check before updating result
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        // 4. Return result with sign
        return (int)(result * sign);
    }
};