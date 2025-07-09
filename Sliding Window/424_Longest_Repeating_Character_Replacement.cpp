/*
LeetCode: 424. Longest Repeating Character Replacement
Link: https://leetcode.com/problems/longest-repeating-character-replacement/

Approach:
- Use sliding window with two pointers: `left` and `right`.
- Maintain the frequency of each character in the current window.
- Track the count of the most frequent character (maxFreq).
- If (window size - maxFreq > k), we shrink the window from the left.
- Otherwise, update the max length.

Time Complexity: O(26 * N) => O(N)
Space Complexity: O(26) => O(1)
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, maxLen = 0, maxFreq = 0;
        vector<int> freq(26, 0);  // Frequency of A-Z

        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // If we need to replace more than k characters, shrink window
            if((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
