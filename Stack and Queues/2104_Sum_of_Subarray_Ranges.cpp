/* 
LeetCode: 2104. Sum of Subarray Ranges
Link: https://leetcode.com/problems/sum-of-subarray-ranges/

Problem:
Given an integer array `nums`, the **range** of a subarray is the difference between the largest and smallest element in the subarray. Return the sum of all subarray ranges.

## Brute Force Approach:
- Iterate over all subarrays, for each subarray find min and max and compute (max - min).
- Time Complexity: O(n²) to O(n³).
- Space Complexity: O(1).

## Optimal Approach: Monotonic Stack (Similar to Sum of Subarray Minimums/Maximums)
- Observation: Range = max - min
- Compute:
    - **Sum of all subarray maximums**
    - **Sum of all subarray minimums**
    - Final answer = sum of maximums - sum of minimums

### How to compute max/min contribution?
- For each element:
    - Count how many subarrays it is the maximum/minimum using:
        - Previous Smaller/Larger
        - Next Smaller/Larger
    - Add value * count to the total sum.

### Time & Space:
- Time Complexity: O(n)
- Space Complexity: O(n)
*/

#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> previousSmaller(vector<int> &nums){
        int n = nums.size();
        vector<int> prev(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            prev[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        return prev;
    }

    vector<int> nextSmaller(vector<int> &nums){
        int n = nums.size();
        vector<int> next(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            next[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        return next;
    }

    long long subArrayMinimums(vector<int> &nums){
        vector<int> prev = previousSmaller(nums);
        vector<int> next = nextSmaller(nums);
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = (sum + (long long)nums[i] * prev[i] * next[i]);
        }
        return sum;
    }

    vector<int> previousLarger(vector<int> &nums){
        int n = nums.size();
        vector<int> prev(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }
            prev[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        return prev;
    }

    vector<int> nextLarger(vector<int> &nums){
        int n = nums.size();
        vector<int> next(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[i] > nums[st.top()]){
                st.pop();
            }
            next[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        return next;
    }

    long long subArrayMaximums(vector<int> &nums){
        vector<int> prev = previousLarger(nums);
        vector<int> next = nextLarger(nums);
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = (sum + (long long)nums[i] * prev[i] * next[i]);
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long minimums = subArrayMinimums(nums);
        long long maximums = subArrayMaximums(nums);
        return maximums - minimums;
    }
};
