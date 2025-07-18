/*
LeetCode: 76. Minimum Window Substring
Link: https://leetcode.com/problems/minimum-window-substring/

Problem:
Given two strings `s` and `t`, return the minimum window in `s` 
which contains all the characters in `t`. If no such window exists, return "".

Approach:
- Use the sliding window technique with two pointers: `left` and `right`.
- Maintain a frequency map `target` of characters in `t`.
- Expand the `right` pointer and track character frequencies using `current`.
- Use two counters:
  - `have`: how many characters match the required frequency in the window.
  - `need`: total unique characters needed.
- When `have == need`, we try to shrink the window from the left to find the minimum.
- Update the answer when a smaller valid window is found.

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        unordered_map<char, int> target;
        for(char ch: t) target[ch]++;

        unordered_map<char, int> current;
        int left = 0, right = 0, minLen = INT_MAX;
        int have = 0, need = target.size(), startIndex = 0;

        while(right < n){
            char ch = s[right];
            current[ch]++;

            if(target.count(ch) && target[ch] == current[ch]){
                have++;
            }

            while(have == need){
                if((right - left + 1) < minLen){
                    minLen = (right - left + 1);
                    startIndex = left;
                }
                current[s[left]]--;
                
                if(target.count(s[left]) && current[s[left]] < target[s[left]])  have--;
                
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};