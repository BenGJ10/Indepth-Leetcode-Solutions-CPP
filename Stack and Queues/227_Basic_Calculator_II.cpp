/*
LeetCode: 227. Basic Calculator II
Link: https://leetcode.com/problems/basic-calculator-ii/

Problem:
Evaluate a simple expression string containing:
- Non-negative integers
- '+', '-', '*', '/' operators
- Spaces

-------------------------------------------------------
Brute Force Approach:
- Directly parse and evaluate expression respecting operator precedence using multiple passes.
- Time Complexity: O(n²) if repeatedly scanning for '*' and '/'.
- Space Complexity: O(n) to store intermediate results.

-------------------------------------------------------
Optimal Approach: Single Pass + Stack
1. Maintain:
   - `num` for current number being built.
   - `sign` for the last operator encountered.
   - Stack to hold intermediate results.
2. Traverse the string:
   - Build numbers digit-by-digit.
   - On encountering an operator (or end of string):
       - If '+' → push `num` onto stack.
       - If '-' → push `-num` onto stack.
       - If '*' → pop top, multiply by `num`, push result.
       - If '/' → pop top, divide by `num`, push result.
       - Update `sign` to current operator and reset `num`.
3. Sum up all values in the stack for final result.

Time Complexity: O(n) — each character processed once.
Space Complexity: O(n) — stack stores at most one entry per number in expression.
*/

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int result = 0;
        char sign = '+';
        stack<int> st;
        int num = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {      
                num = num * 10 + (ch - '0');
            }

            // Process when encountering an operator or end of string
            if ((!isdigit(ch) && ch != ' ') || i == s.length() - 1) {
                if (sign == '+') {
                    st.push(num);
                }
                else if (sign == '-') {
                    st.push(-num);
                }
                else if (sign == '*') {
                    int prev = st.top(); st.pop();
                    st.push(prev * num);
                }
                else if (sign == '/') {
                    int prev = st.top(); st.pop();
                    st.push(prev / num);                    
                }
                sign = ch;
                num = 0;
            }
        }

        // Sum all intermediate results
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
