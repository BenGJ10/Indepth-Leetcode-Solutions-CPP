/*
LeetCode: 1922. Count Good Numbers
Link: https://leetcode.com/problems/count-good-numbers/

Problem:
Given a non-negative integer n, a good number is defined as:
- Even indices (0-based) contain an even digit (0, 2, 4, 6, 8) → 5 choices.
- Odd indices contain a prime digit (2, 3, 5, 7) → 4 choices.
Return the total count of good numbers of length n, modulo 1e9 + 7.

-------------------------------------------------------
Mathematical Insight:
- For `n` digits:
    - Even positions = ceil(n / 2) → each has 5 choices.
    - Odd positions = floor(n / 2) → each has 4 choices.
- Total combinations = (5 ^ evenPositions) * (4 ^ oddPositions).

-------------------------------------------------------
Optimal Approach: Modular Exponentiation
- Use binary exponentiation to compute large powers modulo 1e9+7.
- This avoids overflow and reduces complexity from O(n) to O(log n).

Time Complexity: O(log n)
Space Complexity: O(log n) due to recursion stack
*/

#include <cmath>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;

    // Fast modular exponentiation
    long long power(long long x, long long n) {
        if (n == 0) return 1;

        long long result = power(x, n / 2);
        result = (result * result) % MOD;

        if (n % 2 == 0) {
            return result;
        } else {
            return (result * x) % MOD;
        }
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; // number of even index positions
        long long odd = n / 2;       // number of odd index positions

        long long evenDigits = power(5, even);
        long long oddDigits = power(4, odd);

        return (evenDigits * oddDigits) % MOD;
    }
};
