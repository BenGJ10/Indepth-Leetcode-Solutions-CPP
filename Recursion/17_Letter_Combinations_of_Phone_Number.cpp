/*
LeetCode: 17. Letter Combinations of a Phone Number
Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Problem:
Given a string containing digits from 2-9 inclusive, return all possible letter combinations 
that the number could represent. Return the answer in any order.
The mapping of digits to letters is the same as on telephone buttons.

-------------------------------------------------------
Approach / Insight:
Brute Force:
- For each digit, append all possible characters to every combination generated so far.
- This can be done iteratively, but it’s cumbersome to manage partial combinations.

Optimal Approach: Backtracking
- Maintain a path string representing the current combination.
- Recursively try adding each letter corresponding to the current digit.
- When we have processed all digits, add the path to the result.
- This approach is clean and avoids redundant work.

Time Complexity: O(4^n) // Each digit maps to at most 4 letters, and we process n digits.
Space Complexity: O(n)  // Recursion depth equal to the number of digits.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        
        string path;
        vector<string> map = {
            "", "", "abc", "def", "ghi", 
            "jkl", "mno", "pqrs",
            "tuv", "wxyz"
        };

        backtrack(0, digits, map, path, result);
        return result;
    }

    void backtrack(int index, string &digits, vector<string> &map, string &path, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }

        string letters = map[digits[index] - '0'];
        for (char ch : letters) {
            path.push_back(ch);
            backtrack(index + 1, digits, map, path, result);
            path.pop_back();
        }
    }
};
