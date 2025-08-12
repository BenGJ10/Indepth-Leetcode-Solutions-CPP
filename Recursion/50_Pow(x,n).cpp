/*
LeetCode: 50. Pow(x, n)
Link: https://leetcode.com/problems/powx-n/

Problem:
Implement the function `myPow(x, n)` that calculates x raised to the power n (xⁿ).

-------------------------------------------------------
Brute Force Approach:
- Multiply `x` by itself `n` times.
- Time Complexity: O(|n|)
- Space Complexity: O(1)
- Too slow for large |n|.

-------------------------------------------------------
Optimal Approach: Fast Exponentiation (Binary Exponentiation)
1. Recursively divide the problem into halves:
   - xⁿ = (x^(n/2))² if n is even
   - xⁿ = (x^(n/2))² * x if n is odd
2. Base Case: x⁰ = 1.
3. Handle negative exponents by computing (1/x)⁻ⁿ.
4. Works in O(log |n|) time.

Time Complexity: O(log |n|)
Space Complexity: O(log |n|) due to recursion stack
*/

#include <cmath>
using namespace std;

class Solution {
public:
    // Recursive function to compute power using fast exponentiation
    double power(double x, long long n) {
        if (n == 0) return 1;

        double result = power(x, n / 2);

        if (n % 2 == 0) {
            return result * result;
        } else {
            return result * result * x;
        }
    }

    double myPow(double x, int n) {
        if (x == 0) return 0;

        long long N = n; // Use long long to handle INT_MIN
        if (N < 0) {
            return power(1.0 / x, -N);
        } else {
            return power(x, N);
        }
    }
};
