/*
LeetCode: 205. Isomorphic Strings  
Link: https://leetcode.com/problems/isomorphic-strings/

Approach:
- Two strings `s` and `t` are isomorphic if characters in `s` can be replaced to get `t`.
- We must ensure a **one-to-one character mapping** from `s` to `t` and also from `t` to `s`.
- Use two hash maps:
  1. `st` to map characters from `s` → `t`
  2. `ts` to map characters from `t` → `s`
- While iterating through the strings:
  - If a mapping exists, ensure it matches the expected character.
  - If not, add the new mapping.
- If any inconsistency is found, return false.

Time Complexity: O(n) — one pass through both strings.  
Space Complexity: O(1) — at most 256 unique characters (ASCII), so constant space.
*/

#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> st;
        unordered_map<char, char> ts;

        for(int i = 0; i < s.length(); i++){
            char c1 = s[i];
            char c2 = t[i];

            // Check mapping from s -> t
            if(st.count(c1)){
                if(st[c1] != c2) return false;
            } 
            else {
                st[c1] = c2;
            }

            // Check mapping from t -> s
            if(ts.count(c2)){
                if(ts[c2] != c1) return false;
            } 
            else {
                ts[c2] = c1;
            }
        }
        return true;
    }
};