/*
LeetCode: 392. Is Subsequence  
Link: https://leetcode.com/problems/is-subsequence/

Problem:  
Check if string `s` is a subsequence of string `t`.  
A subsequence means characters of `s` appear in order within `t`, possibly with characters in between.

Approach:  
- Use two pointers to scan both strings.
- Move `s` pointer only when characters match.
- If all characters of `s` are matched in order, return true.

Time Complexity: O(N), where N is the length of `t`  
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sPointer = 0, tPointer = 0;
        
        while (sPointer < s.length() && tPointer < t.length()) {
            if (s[sPointer] == t[tPointer]) {
                sPointer++;
            }
            tPointer++;
        }

        return (sPointer == s.length());
    }
};
