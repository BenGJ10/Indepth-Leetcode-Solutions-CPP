/*
LeetCode: 127. Word Ladder
Link: https://leetcode.com/problems/word-ladder/

Approach:
- Model the words as nodes in a graph.
- Two nodes are connected if their words differ by exactly one letter.
- Perform BFS starting from beginWord to find the shortest path to endWord.

Key Points:
- Use a queue to do level-order traversal (BFS).
- Use an unordered_set to keep track of unvisited words for O(1) lookup.
- At each step, generate all possible one-letter mutations of the current word.
- If the mutated word is in the set, push it into the queue and remove it from the set.

Time Complexity: O(N * L * 26)
    - N = number of words
    - L = length of each word
Space Complexity: O(N * L)
*/

#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0; // endWord must be in the wordList

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);  // avoid revisiting

        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();

            if (word == endWord) return level;  

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];    
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;   
                    if (st.find(word) != st.end()) {
                        q.push({word, level + 1});
                        st.erase(word); // avoid revisiting
                    }
                }
                word[i] = original; // revert the change
            }
        }

        return 0;
    }
};