/*
LeetCode: 503. Next Greater Element II  
Link: https://leetcode.com/problems/next-greater-element-ii/

Problem:  
Given a circular array `nums`, return the **Next Greater Element** for every element.  
If no greater element exists, return `-1` for that position.

## Brute Force Approach:
- For each element, scan the array forward (wrapping around circularly) to find the next greater element.
- Time Complexity: O(n²) (for each element, we may scan the whole array)
- Space Complexity: O(1)

## Optimal Approach: Monotonic Stack (Circular Array Trick)
- Traverse the array **twice** to simulate circular behavior.
- Use a stack to store indices of elements in decreasing order.
- For each element:
    1. While stack top is smaller than current element, assign current as next greater.
    2. Push index only during the first pass (i < n) to avoid duplicates.
- Result array is initialized with `-1`.

- Time Complexity: O(n) (each element is pushed and popped at most once)
- Space Complexity: O(n) (stack + result array)
*/

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;

        for (int i = 0; i < 2 * n; i++) {  // Loop twice to simulate circular behavior
            int curr = nums[i % n];

            while (!st.empty() && curr > nums[st.top()]) {
                result[st.top()] = curr;
                st.pop();
            }
            
            if (i < n) st.push(i);  // Push index only in the first pass
        }
        return result;
    }
};
