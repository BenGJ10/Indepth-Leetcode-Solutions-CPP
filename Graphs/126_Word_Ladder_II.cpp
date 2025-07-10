/*
LeetCode 126. Word Ladder II
https://leetcode.com/problems/word-ladder-ii/

Goal:
Find all shortest transformation sequences from beginWord to endWord,
where each transformation changes exactly one character and the new word 
must exist in the given wordList.

Approach:

1. BFS Phase (Shortest Path Discovery):
   - Perform a breadth-first traversal starting from `beginWord`.
   - For each word at the current level, generate all possible words 
     by changing one character at a time.
   - If the new word exists in the wordList (stored in a set for O(1) lookup), 
     it's a valid transformation and should be added to the queue.
   - Track the number of steps (levels) taken to reach each word using a hashmap `mpp`.
   - Once we reach the `endWord`, we stop expanding further levels to ensure shortest paths.

2. DFS Phase (Path Backtracking):
   - Starting from `endWord`, recursively backtrack using DFS.
   - At each step, generate all possible one-character transformations of the current word.
   - Only consider the transformations that:
       a) Exist in the `mpp` map.
       b) Have a level exactly one less than the current word’s level.
     This ensures we're following only valid paths from `endWord` to `beginWord`.
   - Use a temporary sequence vector to build paths in reverse (end to start), 
     then reverse the vector before adding it to the final answer.

Time Complexity:
- BFS: O(N * L^2) where N = number of words, L = word length
- DFS: Exponential in worst-case for generating all paths

Space Complexity: O(N * L) for map, queue, recursion
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;
class Solution {
    unordered_map<string, int> mpp;  // word -> level
    vector<vector<string>> ans;
    string beginW;

private:
    void dfs(string word, vector<string> &seq) {
        if (word == beginW) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mpp[word];
        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        beginW = beginWord;
        mpp[beginWord] = 1;
        q.push(beginWord);
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if (word == endWord) break;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        mpp[word] = steps + 1;
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq = {endWord};
            dfs(endWord, seq);
        }

        return ans;
    }
};