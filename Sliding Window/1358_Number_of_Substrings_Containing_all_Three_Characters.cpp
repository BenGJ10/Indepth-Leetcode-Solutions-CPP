/*
LeetCode: 1358. Number of Substrings Containing All Three Characters  
Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

Problem:
Given a string `s` consisting only of letters 'a', 'b', and 'c', 
return the number of substrings containing **at least one** of each character.

Approach:
- Maintain the **last seen index** for each of the characters 'a', 'b', and 'c'.
- At each index `i`, once all three characters have been seen at least once,
  the number of valid substrings ending at `i` is:
  `(1 + minimum last seen index among a, b, and c)`.
- This works because we can pair this suffix with any prefix up to that min index.

Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);
        int occ = 0;
        for(int i = 0; i < s.length(); i++){
            lastSeen[s[i] - 'a'] = i;
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                occ += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }
        return occ;
    }
};
