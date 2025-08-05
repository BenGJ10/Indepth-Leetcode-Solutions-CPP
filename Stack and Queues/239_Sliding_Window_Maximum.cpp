/*
LeetCode: 239. Sliding Window Maximum  
Link: https://leetcode.com/problems/sliding-window-maximum/

Problem:  
Given an integer array `nums` and an integer `k`, return the maximum value in every sliding window of size `k`.

## Brute Force Approach:
- For each window of size `k`, iterate through its elements to find the maximum.
- Time Complexity: O(n * k) (nested loops for each window)
- Space Complexity: O(1)

## Optimal Approach: Deque (Monotonic Queue)
- Use a deque to store indices of elements in `decreasing order of values`.
- For each index:
    1. Remove elements out of the window** from the front.
    2. Maintain decreasing order: Pop elements from the back if they're smaller than the current element.
    3. Push the current element’s index.
    4. The element at the front of deque is the maximum of the current window.

- Time Complexity: O(n) (each element is pushed/popped at most once)
- Space Complexity: O(k) (deque stores indices in current window)

*/

#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maximums;
        deque<int> dq;  

        // Process first 'k' elements to initialize deque
        for (int i = 0; i < k; i++) {
            // Remove smaller elements from the back (they can't be max anymore)
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // Process the rest of the elements
        for (int i = k; i < nums.size(); i++) {
            maximums.push_back(nums[dq.front()]); // Front of deque is the max in the current window

            // Remove elements that are out of this window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Maintain decreasing order in deque for current element
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);  // Push current element index
        }

        // Push max of the last window
        maximums.push_back(nums[dq.front()]);
        return maximums;
    }
};
