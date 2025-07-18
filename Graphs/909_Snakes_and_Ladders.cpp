/*
LeetCode: 909. Snakes and Ladders  
Link: https://leetcode.com/problems/snakes-and-ladders/

Problem:
You are given an n x n board representing a Snakes and Ladders game.
- Starting from cell 1, you roll a 6-sided dice and move forward.
- If you land on a cell with a snake or ladder, move to its destination.
Return the minimum number of moves to reach the final cell `n * n`, or -1 if unreachable.

Approach:
1. Flatten the 2D board into a 1D array (zig-zag row order).
2. Perform **BFS** starting from cell 1.
3. For each step, try all dice rolls from 1 to 6.
   - If the destination has a ladder/snake (`flatten[next] != -1`), follow it.
   - Skip already visited cells to avoid cycles.

Time Complexity: O(N^2) — We might visit all cells once.
Space Complexity: O(N^2) — For flattened board and visited array.
*/

#include <iostream>
using namespace std;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flatten(n * n + 1, -1);
        int index = 1;
        bool leftToRight = true;

        for(int row = n - 1; row >= 0; row--){
            if(leftToRight){
                for(int col = 0; col < n; col++){
                    flatten[index++] = board[row][col];
                }
            }
            else{
                for(int col = n - 1; col >= 0; col--){
                    flatten[index++] = board[row][col];
                }
            }
            leftToRight = !leftToRight;
        }

        queue<pair<int, int>> q;
        vector<bool> vis(n * n + 1, false);
        q.push({1, 0});
        vis[1] = true;
        
        while(!q.empty()){
            int cell = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(cell == n * n)   return steps;
            
            for(int dice = 1; dice <= 6; dice++){
                int next = cell + dice;
                if(next > n * n)    continue;
                if(flatten[next] != -1){
                    next = flatten[next];
                }
                if(!vis[next]){
                    vis[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }
        return -1;
    }
};