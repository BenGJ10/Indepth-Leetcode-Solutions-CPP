/*
LeetCode: 14. Longest Common Prefix  
Link: https://leetcode.com/problems/longest-common-prefix/

Problem:
Write a function to find the longest common prefix string among an array of strings.
If there is no common prefix, return an empty string "".

Approach:
- Initialize the prefix as the first string.
- Iterate through the remaining strings one by one.
- For each string, compare characters with the current `prefix`.
- Truncate the prefix to the matched portion using `substr(0, j)`.
- If at any point the prefix becomes empty, return "" early.

Time Complexity: O(N * M), where N is number of strings, M is length of the smallest string.
Space Complexity: O(1), ignoring the result string.
*/

#include <iostream>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        string prefix = strs[0];
        for(int i = 1; i < strs.size(); i++){
            int j = 0;
            while(j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]){
                j++;
            }
            prefix = prefix.substr(0, j);
            if(prefix.empty()) return "";
        }
        return prefix;
    }
};