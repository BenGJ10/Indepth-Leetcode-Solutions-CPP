/*
LeetCode: 752. Open the Lock  
Link: https://leetcode.com/problems/open-the-lock/

Approach:
- Treat each 4-digit lock state as a node in an implicit graph.
- Each move (rotating one wheel up/down) leads to 8 neighboring nodes.
- Use Breadth-First Search (BFS) to explore the shortest path from "0000" to the target.
- Skip over deadend states and already visited ones.
- At each level, generate all valid next moves by rotating one digit forward or backward.

Steps:
1. Store all deadends in a hash set for O(1) lookup.
2. If the start "0000" is a deadend, return -1 immediately.
3. Use a queue to perform BFS, starting from "0000".
4. For each state, generate 8 possible rotations (up and down for each digit).
5. If a generated state is the target, return the number of moves taken.
6. Use a visited set to avoid revisiting states.

Time Complexity: O(10^4) = O(1), since there are only 10000 possible lock combinations.
Space Complexity: O(10^4) for visited and queue.
*/


#include <unordered_set>
#include <iostream>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());
        unordered_set<string> vis;
        string start = "0000";
        if(st.count(start)) return -1;

        queue<string>q;
        q.push(start);
        vis.insert(start);
        int moves = 0;

        while(!q.empty()){
            int currLevel = q.size();
            for(int i = 0; i < currLevel; i++){
                string currStr = q.front();
                q.pop();

                if(currStr == target)   return moves;

                for(int i = 0; i < 4; i++){
                    string up = currStr;
                    string down = currStr;

                    up[i] = (((up[i] - '0') + 1) % 10) + '0';
                    down[i] = (((down[i] - '0') - 1 + 10) % 10) + '0';

                    if(!st.count(up) && !vis.count(up)){
                        q.push(up);
                        vis.insert(up);
                    }
                    if(!st.count(down) && !vis.count(down)){
                        q.push(down);
                        vis.insert(down);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};