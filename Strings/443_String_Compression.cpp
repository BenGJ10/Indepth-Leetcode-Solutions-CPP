/*
LeetCode: 443. String Compression  
Link: https://leetcode.com/problems/string-compression/

Problem:  
Given an array of characters, compress it in-place.  
- Repeated characters are replaced with the character followed by the count.
- Single characters remain unchanged.
- Return the new length of the compressed array.

Approach: Two-Pointer Technique  
1. Use `right` to scan the array and `left` to write the compressed result.
2. For each group of repeating characters:
   - Write the character at `left`.
   - If count > 1, write the digits of the count individually.
3. Return `left` as the new compressed length.

Time Complexity: O(n) — single traversal of the array.  
Space Complexity: O(1) — in-place compression.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int left = 0, right = 0;
        
        while (right < n) {
            char original = chars[right];
            int count = 0;
            
            // Count occurrences of the current character
            while (right < n && chars[right] == original) {
                right++;
                count++;
            }

            chars[left++] = original;
           
            if (count > 1) {
                for (char ch : to_string(count)) {
                    chars[left++] = ch;
                }
            }
        }
        return left; 
    }
};
