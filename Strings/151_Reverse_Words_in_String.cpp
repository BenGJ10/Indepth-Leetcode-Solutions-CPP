/*
LeetCode: 151. Reverse Words in a String  
Link: https://leetcode.com/problems/reverse-words-in-a-string/

Problem:  
Reverse the words in a string. Remove leading/trailing spaces and reduce multiple spaces to a single space.

Approach:  
- Use a loop to extract words, ignoring extra spaces.
- Store the words in a vector.
- Reverse the vector and join with a single space.

Time Complexity: O(N)  
Space Complexity: O(N)
*/

#include <iostream>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        vector<string> words;
        
        for(int i = 0; i < n; i++){
            while(i < n && s[i] == ' ') i++; // Increment if space encountered

            string word = "";
            while(i < n && s[i] != ' '){
                word += s[i++];
            }
            if (!word.empty()) words.push_back(word);
        }

        reverse(words.begin(), words.end()); // Reverse the words 
        string result = "";
        for(int j = 0; j < words.size(); j++){
            result += words[j];
            if(j != words.size() - 1) result += " "; // Space in between words except the last word
        }
        
        return result;
    }
};