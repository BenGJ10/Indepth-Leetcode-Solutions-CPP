/*
LeetCode: 3. Longest Substring Without Repeating Characters
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

Approach:
- Use a sliding window defined by two pointers [left, right].
- Use an unordered_map to store the last index where each character was seen.
- If the character is repeated and its last seen position is within the current window,
  move `left` to exclude the previous occurrence.
- Update the longest substring length during the process.

Time Complexity: O(N)
Space Complexity: O(128) = O(1) since character set is limited (ASCII)

*/

#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];

            // If character was seen and is in the current window
            if (lastSeen.count(ch) && lastSeen[ch] >= left) {
                left = lastSeen[ch] + 1;
            }

            lastSeen[ch] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
