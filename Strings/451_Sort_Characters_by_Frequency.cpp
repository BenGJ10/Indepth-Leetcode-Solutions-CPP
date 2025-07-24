/*
LeetCode: 451. Sort Characters By Frequency  
Link: https://leetcode.com/problems/sort-characters-by-frequency/

Problem:  
Given a string `s`, sort its characters by frequency in descending order.

Approach:  
- Count frequency of each character using a hash map.
- Use a bucket sort approach: group characters by frequency into buckets.
- Traverse buckets from high to low frequency, appending characters accordingly.

Time Complexity: O(N), where N = length of the string  
Space Complexity: O(N), for the map and buckets
*/
#include <iostream>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char ch: s){
            freq[ch]++;
        }

        int n = s.length();
        vector<vector<char>> buckets(n + 1); // A character in s can appear at most n times

        for(auto &[ch, f]: freq){
            buckets[f].push_back(ch);
        }
        
        string result = "";
        for(int i = n; i > 0; i--){
            for(char ch: buckets[i]){
                result += string(i, ch);
            }
        }
        return result;
    }
};