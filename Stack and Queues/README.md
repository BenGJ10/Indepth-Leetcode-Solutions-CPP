# Stacks & Queues – Complete Patterns 

Stacks and Queues are fundamental **linear data structures** that form the backbone of many algorithms.
They are used to manage data in a specific order, allowing for efficient access and manipulation.

- **Stack:** Follows **LIFO** (Last In, First Out) principle.
  - Think of it as a stack of plates – the last plate you put on top is the first one you take off.
  - Commonly used in: **function calls, undo/redo, parsing expressions, backtracking**.
  
- **Queue:** Follows **FIFO** (First In, First Out) principle.
  - Think of it as a line at a ticket counter – the first person in line is served first.
  - Commonly used in: **BFS, task scheduling, caches**.

---

## Patterns in Stacks & Queues

### 1. Monotonic Stack (Next/Previous Greater or Smaller)

A **monotonic stack** is a stack that maintains its elements in a sorted order (either increasing or decreasing). It is useful for problems where you need to find the next or previous greater or smaller element in an array.

#### Idea and Approach
- Iterate through elements while keeping a stack of indices.

- Maintain monotonic order in the stack.

- Pop until the order breaks, process the popped elements.

- Achieves O(n) complexity instead of O(n²).

#### Algorithm
1. Traverse the array from right-to-left for Next Greater Element (NGE), left-to-right for Previous Greater Element (PGE).

2. While stack is not empty and top does not satisfy the condition, pop it.

3. Store result and push current index to stack.

#### C++ Example: Next Greater Element
```cpp
vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;
        for (int i = 0; i < 2 * n; i++) {  
            int curr = nums[i % n];

            while (!st.empty() && curr > nums[st.top()]) {
                result[st.top()] = curr;
                st.pop();
            }
            if (i < n) st.push(i);  
        }
        return result;
    }
```

#### Important Problems

[496. Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)

[503. Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)

[739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)

[84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)

[739. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) 

---

### 2. Expression Evaluation (Infix/Postfix/Prefix)

Expression evaluation involves parsing and calculating the value of mathematical expressions written in different notations: infix, postfix (Reverse Polish Notation), and prefix (Polish Notation).

#### Idea and Approach
- Use two stacks: one for operands and one for operators.

- Handle precedence and parentheses carefully.

- For postfix/prefix, use a single operand stack.

#### Algorithm (Infix Evaluation)
1. Scan from left to right.

2. If number → push to operand stack.

3. If operator → pop while top of operator stack has greater or equal precedence.

4. If '(' → push to operator stack.

5. If ')' → pop until '('.

6. Apply operations and push result back.

#### C++ Example: Basic Calculator II
```cpp
int calculate(string s) {
    stack<int> st;
    char sign = '+';
    long num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) num = num * 10 + (s[i] - '0');
        if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
            if (sign == '+') st.push(num);
            else if (sign == '-') st.push(-num);
            else if (sign == '*') { int t = st.top(); st.pop(); st.push(t * num); }
            else if (sign == '/') { int t = st.top(); st.pop(); st.push(t / num); }
            sign = s[i];
            num = 0;
        }
    }
    int res = 0;
    while (!st.empty()) { res += st.top(); st.pop(); }
    return res;
}
```

#### Important Problems

[224. Basic Calculator](https://leetcode.com/problems/basic-calculator/)

[227. Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/)

[150. Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

[71. Simplify Path](https://leetcode.com/problems/simplify-path/)

[20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

--- 

### 3. Sliding Window Maximum

The Sliding Window Maximum problem involves finding the maximum value in a sliding window of size k across an array. This is a common problem that can be efficiently solved using a deque (double-ended queue) or a monotonic stack.

#### Idea and Approach
- Keep indices of potential max elements in deque.

- Remove elements outside the current window.

- Remove smaller elements from the back before adding the new one.

#### Flowchart
```
Incoming element → Remove smaller from back → 
Push → Pop front if out of window → Max = front
```

#### C++ Example
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
}
```

#### Important Problems

[239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)

[1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

---

### 4. Min/Max Stack

A Min/Max Stack is a stack that supports retrieving the minimum or maximum element in constant time. It is useful for problems where you need to keep track of the minimum or maximum value while performing standard stack operations.

#### Idea and Approach
- Use two stacks: one for the main elements and another for tracking min/max.

- Push to the min/max stack only if the new element is less than or equal to the current min/max.

- Pop from both stacks simultaneously.

#### C++ Example: Min Stack
```cpp
class MinStack {
    stack<int> st, minSt;
public:
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) minSt.push(val);
    }
    void pop() {
        if (st.top() == minSt.top()) minSt.pop();
        st.pop();
    }
    int top() { return st.top(); }
    int getMin() { return minSt.top(); }
};
```

#### Important Problems

[155. Min Stack](https://leetcode.com/problems/min-stack/)

[716. Max Stack](https://leetcode.com/problems/max-stack/)

---

