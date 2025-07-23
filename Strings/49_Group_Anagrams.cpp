/*
LeetCode: 49. Group Anagrams  
Link: https://leetcode.com/problems/group-anagrams/

Problem:  
Group strings that are anagrams of each other.

Approach:  
- Use a hashmap where key is the sorted version of the string.
- Push original strings into the corresponding group.

Time Complexity: O(N * K log K), where N = number of strings, K = average string length  
Space Complexity: O(N * K)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagrams;

        for(auto &str: strs){
            string temp = str;
            sort(temp.begin(), temp.end()); // Sort characters to get the key
            anagrams[temp].push_back(str);  // Group anagrams
        }

        for(auto &anagram: anagrams){
            result.push_back(anagram.second);
        }

        return result;
    }
};
