/*
LeetCode: 907. Sum of Subarray Minimums  
Link: https://leetcode.com/problems/sum-of-subarray-minimums/

Problem:  
Given an array of integers `arr`, find the sum of the **minimum value of every subarray**. Return the answer modulo 10^9+7.

## Brute Force Approach:
- Generate all subarrays, find the minimum of each, and sum them up.
- Time Complexity: O(n³) (generate subarrays + min computation) or O(n²) if optimized using pre-computed minimums.
- Space Complexity: O(1).

## Optimal Approach: Monotonic Stack (Previous & Next Smaller)
- For each element:
    - Find **`left[i]`**: Distance to the previous smaller element.
    - Find **`right[i]`**: Distance to the next smaller element.
- Each element contributes `arr[i] * left[i] * right[i]` to the final sum.
- Use stacks to compute `left[]` and `right[]` efficiently.

### Key Insight:
- For each element, count in how many subarrays it will be the minimum.
- Multiply its value by that count.

- Time Complexity: O(n) (each element pushed/popped once).
- Space Complexity: O(n) (stack + auxiliary arrays).
*/

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    // Helper: Find distance to previous smaller elements
    vector<int> previousSmaller(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        return left;
    }

    // Helper: Find distance to next smaller elements
    vector<int> nextSmaller(vector<int> &arr) {
        int n = arr.size();
        vector<int> right(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        return right;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left = previousSmaller(arr);
        vector<int> right = nextSmaller(arr);
        long result = 0;

        for (int i = 0; i < n; i++) {
            result = (result + (long)arr[i] * left[i] * right[i]) % mod;
        }
        return result;
    }
};