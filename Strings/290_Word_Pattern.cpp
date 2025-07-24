/*
LeetCode: 290. Word Pattern  
Link: https://leetcode.com/problems/word-pattern/

Problem:  
Check if a string `s` follows the same pattern as given in `pattern`, where each character maps to a unique word.

Approach:  
- Tokenize the input string into words.
- Maintain two maps: one from word → character and another from character → word.
- Validate the mapping in both directions.

Time Complexity: O(N), where N is the number of characters in `s`  
Space Complexity: O(W), where W is the number of words in `s`
*/

#include <iostream>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            while(i < n && s[i] == ' ') i++;

            string word = "";
            while(i < n && s[i] != ' '){
                word += s[i++];
            }
            if(!word.empty())   words.push_back(word);
        }

        if(words.size() != pattern.length())    return false;
        
        unordered_map<string, char> wordToChar;
        unordered_map<char, string> charToWord;
        
        for(int i = 0; i < pattern.length(); i++){
            char ch = pattern[i];
            string word = words[i];

            if(wordToChar.count(word)){
                if(wordToChar[word] != ch)  return false;
            } else{
                wordToChar[word] = ch;
            }

            if(charToWord.count(ch)){
                if(charToWord[ch] != word)  return false;
            } else{
                charToWord[ch] = word;
            }
        }
        return true;
    }
};