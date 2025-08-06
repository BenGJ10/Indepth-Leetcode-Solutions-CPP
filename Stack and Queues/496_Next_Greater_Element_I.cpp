/*
LeetCode: 496. Next Greater Element I  
Link: https://leetcode.com/problems/next-greater-element-i/

Problem:  
You are given two arrays `nums1` and `nums2`, where `nums1` is a subset of `nums2`.  
For each element in `nums1`, find its **next greater element** in `nums2`.

## Brute Force Approach:
- For each element in `nums1`, search its index in `nums2` and then scan forward to find the next greater element.
- Time Complexity: O(n1 * n2) (nested loops)
- Space Complexity: O(1)

## Optimal Approach: Monotonic Stack
- Traverse `nums2` from left to right:
    - Use a stack to keep track of decreasing elements.
    - If the current element is greater than the stack’s top, it is the "next greater" for stack’s top.
    - Store the mapping in a hash map.
- Finally, for each element in `nums1`, fetch its next greater from the hash map.

- Time Complexity: O(n1 + n2) (linear traversal and lookups)
- Space Complexity: O(n2) (stack + hashmap)

*/

#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> result(nums1.size(), -1);
        unordered_map<int, int> nextGreater;

        // Build next greater map for nums2
        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && nums2[i] > st.top()) {
                nextGreater[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        // Fill result using the map
        for (int i = 0; i < nums1.size(); i++) {
            int curr = nums1[i];
            if (nextGreater.find(curr) != nextGreater.end()) {
                result[i] = nextGreater[curr];
            }
        }
        return result;
    }
};
