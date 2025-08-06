/*
GFG: Immediate Smaller Element to the Left  
Link: https://www.geeksforgeeks.org/problems/immediate-smaller-element-to-the-left/1

Problem:  
For each element in an array, find the **nearest smaller element to its left**.  
If no such element exists, return `-1`.

## Brute Force Approach:
- For each element, iterate backward to find the first smaller element.
- Time Complexity: O(n²) (nested loop for each element)
- Space Complexity: O(1)

## Optimal Approach: Monotonic Stack
- Traverse from left to right.
- Maintain a stack to keep track of potential smaller elements.
- For each element:
    1. Pop elements from the stack that are **greater or equal** to the current element.
    2. If stack is not empty, top is the nearest smaller element.
    3. Push current element onto the stack.

- Time Complexity: O(n) (each element pushed/popped once)
- Space Complexity: O(n) (stack storage)
*/

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> leftSmaller(vector<int> arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            int curr = arr[i];

            // Remove elements not smaller than current
            while (!st.empty() && curr <= st.top()) {
                st.pop();
            }

            // Top of stack is the nearest smaller
            if (!st.empty()) {
                result[i] = st.top();
            }

            st.push(curr); 
        }
        return result;
    }
};