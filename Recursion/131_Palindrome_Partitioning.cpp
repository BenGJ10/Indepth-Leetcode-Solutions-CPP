/*
LeetCode: 131. Palindrome Partitioning
Link: https://leetcode.com/problems/palindrome-partitioning/

Problem:
Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s.

-------------------------------------------------------
Approach / Insight:
Brute Force:
- Generate all possible partitions of the string.
- For each partition, check if every substring is a palindrome.
- Very inefficient because it explores many invalid partitions.

Optimal Approach: Backtracking
- At each index, try all possible substrings that start at that index.
- If the substring is a palindrome, add it to the current partition and recurse further.
- Once we reach the end of the string, we add the current partition to the result.
- Checking palindromes is done with a helper function.
- This avoids exploring partitions that contain non-palindromic substrings.

Time Complexity: O(2^n * n) 
- There are 2^n ways to partition a string, and palindrome checking takes O(n).
Space Complexity: O(n) 
- Recursion stack depth proportional to string length, plus storage for partitions.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;

    vector<vector<string>> partition(string s) {
        vector<string> ans;
        backtrack(0, s, ans);
        return result;
    }

    void backtrack(int index, string s, vector<string> &ans) {
        if (index == s.length()) {
            result.push_back(ans);
            return;
        }

        for (int i = index; i < s.length(); i++) {
            if (isPalindrome(s, index, i)) {
                ans.push_back(s.substr(index, i - index + 1));
                backtrack(i + 1, s, ans);
                ans.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};
