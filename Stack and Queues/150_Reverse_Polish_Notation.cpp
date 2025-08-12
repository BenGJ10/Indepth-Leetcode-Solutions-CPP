/*
LeetCode: 150. Evaluate Reverse Polish Notation
Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/

Problem:
Evaluate the value of an arithmetic expression in Reverse Polish Notation (RPN).
Valid operators are +, -, *, /.
Each operand may be an integer or another expression.

-------------------------------------------------------
Brute Force Approach:
- Recursively parse tokens and evaluate expressions.
- Complex and inefficient.

-------------------------------------------------------
Optimal Approach: Stack
- Use a stack to store operands.
- For each token:
    - If operand, push to stack.
    - If operator, pop two operands, apply operator, push result.
- Result is top of stack after processing all tokens.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();

                int result = 0;
                if (token == "+")      result = num1 + num2;
                else if (token == "-") result = num1 - num2;
                else if (token == "*") result = num1 * num2;
                else if (token == "/") result = num1 / num2;

                st.push(result);
            } else {
                st.push(stoi(token)); // Convert string to integer
            }
        }
        return st.top();
    }
};
