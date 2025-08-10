/*
LeetCode: 224. Basic Calculator
Link: https://leetcode.com/problems/basic-calculator/

Problem:
Implement a basic calculator to evaluate a simple expression string.
The expression may contain:
- Non-negative integers
- '+', '-' operators
- Parentheses '(' and ')'
- Spaces

-------------------------------------------------------
Brute Force Approach:
- Recursively evaluate expressions within parentheses.
- Time Complexity: O(n²) in worst case due to repeated string slicing.
- Space Complexity: O(n) due to recursion stack.

-------------------------------------------------------
Optimal Approach: Stack-based Evaluation
1. Traverse the string character by character.
2. Maintain:
   - `result`: current evaluation result
   - `sign`: +1 or -1 based on current operation
   - A stack to store `(previous result, previous sign)` when encountering '('
3. Steps:
   - When seeing a number: accumulate it and update `result` using `sign`.
   - When seeing '+' or '-': update `sign`.
   - When seeing '(':
       - Push `result` and `sign` onto the stack.
       - Reset `result` to 0 and `sign` to 1.
   - When seeing ')':
       - Pop `sign` and previous result from stack.
       - Combine them with current `result`.
4. Ignore spaces.

Time Complexity: O(n) — each character processed once.
Space Complexity: O(n) — stack for storing states.
*/

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1;
        stack<int> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                int num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                result += (sign * num);
            }
            else if (ch == '+') {
                sign = 1;
            }
            else if (ch == '-') {
                sign = -1;
            }
            else if (ch == ' ') {
                continue;
            }
            else if (ch == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if (ch == ')') {
                int prevSign = st.top(); st.pop();
                int prevResult = st.top(); st.pop();
                result = (result * prevSign) + prevResult;
            }
        }
        return result;
    }
};
