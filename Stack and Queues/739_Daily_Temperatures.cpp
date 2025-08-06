/*
LeetCode: 739. Daily Temperatures  
Link: https://leetcode.com/problems/daily-temperatures/

Problem:  
Given a list of daily temperatures `temperatures`, return a list `wait` such that `wait[i]` is the number of days you have to wait after the `i`th day to get a warmer temperature. If no future day is warmer, set `wait[i] = 0`.

---

## Brute Force Approach:
- For each day, iterate forward to find the next day with a higher temperature.
- Time Complexity: O(n²) (nested loops for each day comparison).
- Space Complexity: O(1).

---

## Optimal Approach: Monotonic Stack
- Use a stack to store indices of days in **decreasing temperature order**.
- For each temperature:
    1. While the current temperature is greater than the temperature at the top index in the stack:
       - Pop from the stack and calculate wait days (`i - popped index`).
    2. Push the current day's index onto the stack.
- The stack helps efficiently track the "next warmer day".

- Time Complexity: O(n) (each index pushed/popped once).
- Space Complexity: O(n) (stack for indices).
*/

#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> wait(n, 0);
        stack<int> st; 

        for (int i = 0; i < n; i++) {
            // Pop all indices with lower temperature than current
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                wait[st.top()] = i - st.top(); // Days to wait for a warmer temperature
                st.pop();
            }
            st.push(i); 
        }
        return wait;
    }
};
