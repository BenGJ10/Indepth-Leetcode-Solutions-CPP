/* 
LeetCode: 402. Remove K Digits  
Link: https://leetcode.com/problems/remove-k-digits/

Problem:  
Given a string `num` representing a non-negative integer and an integer `k`, remove `k` digits from the number so that the new number is the smallest possible.

## Brute Force Approach:
- Generate all combinations of digits after removing `k` digits and pick the smallest.
- Time Complexity: O(C(n, k)) → exponential.
- Space Complexity: High due to recursion or all combinations.

## Optimal Approach: Monotonic Stack
- Maintain a stack of digits (in increasing order).
- For each digit:
    - Remove previous larger digits if `k > 0`.
- After traversal, if `k > 0`, remove from the end.
- Finally, remove leading zeroes and return result.

### Key Insight:
- Greedily remove digits that are bigger than the current digit to form the smallest number.
- Time Complexity: O(n)
- Space Complexity: O(n)
*/

#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> st;
        if(k == n)  return "0"; 

        for(int i = 0; i < n; i++){
            // Remove digits from the stack if the current digit is smaller and we still have digits to remove
            while(!st.empty() && st.top() - '0' > num[i] - '0' && k > 0){
                st.pop();
                k -= 1;
            }
            st.push(num[i]); 
        }

        // If still digits left to remove, remove from the end
        while(k > 0){
            st.pop();
            k -= 1;
        }
        if(st.empty()) return "0";

        string result = "";
        // Construct result from stack (will be in reverse order)
        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        // Remove trailing zeroes (which are leading zeroes after reversing)
        while(result.size() != 0 && result.back() == '0'){
            result.pop_back();
        }

        reverse(result.begin(), result.end()); // Final result

    
        if(result.empty()) return "0";
        return result;
    }
};
