/*
LeetCode: 12. Integer to Roman  
Link: https://leetcode.com/problems/integer-to-roman/

Problem:  
Convert an integer to its Roman numeral representation.

Approach:  
- Use a greedy approach with a predefined value-symbol mapping.
- Subtract the largest possible value and append its Roman numeral repeatedly.

Time Complexity: O(1) — because max input is 3999 (constant length loop)  
Space Complexity: O(1)
*/
#include <iostream>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int>> hashMap = {
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
            {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
            {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
        };

        string result = "";
        for (auto &[roman, value] : hashMap) {
            while (num >= value) {
                result += roman;
                num -= value;
            }
        }
        return result;
    }
};