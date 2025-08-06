/*
LeetCode: 155. Min Stack  
Link: https://leetcode.com/problems/min-stack/

Problem:  
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

## Brute Force Approach:
- Use a single stack to store elements.
- For `getMin()`, iterate through the stack to find the minimum each time.
- Time Complexity: O(n) for `getMin()` (linear scan)
- Space Complexity: O(n) (stack to store elements)

## Optimal Approach: Stack with Auxiliary Min Stack
- Maintain two stacks:
  1. `st`: Main stack for all values.
  2. `minSt`: Stack to store the current minimum at each state.
- Push: Add value to `st` and update `minSt` if value is <= current minimum.
- Pop: Remove from `st` and if popped value equals `minSt.top()`, pop from `minSt`.
- `getMin()`: Always return `minSt.top()` in O(1).

- Time Complexity: O(1) for all operations (push, pop, top, getMin)
- Space Complexity: O(n) (storing stack and auxiliary min stack)

*/

#include <stack>
using namespace std;

class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (minSt.empty() || minSt.top() >= val) {
            minSt.push(val);
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};
