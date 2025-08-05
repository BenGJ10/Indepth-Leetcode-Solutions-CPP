/*
LeetCode: 20. Valid Parentheses  
Link: https://leetcode.com/problems/valid-parentheses/

Problem:  
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['`, and `']'`, determine if the input string is valid.  
A string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

## Approach: Stack
- Use a stack to keep track of opening brackets.
- For each character:
    1. If it’s an opening bracket, push it to the stack.
    2. If it’s a closing bracket:
        - Check if the stack is empty (invalid if true).
        - Check if the top of the stack matches the correct opening bracket.
        - If not, return false; else, pop the top element.
- At the end, the stack must be empty for the string to be valid.

- Time Complexity: O(n) (single pass over the string)
- Space Complexity: O(n) (stack stores unmatched opening brackets)
*/

#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
           
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            else { 
               
                if (st.empty() || 
                   (ch == ')' && st.top() != '(') ||
                   (ch == '}' && st.top() != '{') ||
                   (ch == ']' && st.top() != '[')) {
                    return false;
                }
                st.pop(); 
            }
        }
        return st.empty(); // Stack should be empty if all brackets matched
    }
};
