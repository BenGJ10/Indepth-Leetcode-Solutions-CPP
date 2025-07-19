/*
LeetCode: 433. Minimum Genetic Mutation  
Link: https://leetcode.com/problems/minimum-genetic-mutation/

Problem:  
Given a start gene, end gene, and a bank of valid gene strings, find the minimum number of single-character mutations needed to convert start to end. Each mutation must be in the bank. Return -1 if not possible.

Approach: BFS (Unweighted shortest path)
- Treat each gene as a node, mutations as edges.
- Use BFS to find the minimum number of steps to reach `endGene` from `startGene`.
- At each step, try all valid one-letter mutations that exist in the bank.
- Use a queue for BFS and a set to avoid revisiting.

Time Complexity: O(N * 8 * 4)  
Space Complexity: O(N)
*/

#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        if (!st.count(endGene)) return -1;

        queue<pair<string, int>> q;
        q.push({startGene, 0});
        vector<char> genes = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            auto [word, mutations] = q.front();
            q.pop();

            if (word == endGene) return mutations;

            for (int i = 0; i < 8; i++) {
                char original = word[i];
                for (char gene : genes) {
                    if (gene == original) continue;

                    word[i] = gene;
                    if (st.count(word)) {
                        q.push({word, mutations + 1});
                        st.erase(word); // avoid revisiting
                    }
                }
                word[i] = original; 
            }
        }

        return -1;
    }
};