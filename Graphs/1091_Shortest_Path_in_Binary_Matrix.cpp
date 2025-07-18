/*
LeetCode: 1091. Shortest Path in Binary Matrix  
Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/

Problem:
Given an `n x n` binary matrix `grid`, return the length of the shortest clear path 
from top-left (0,0) to bottom-right (n-1,n-1).  
- A clear path consists only of cells with value 0.
- You may move in 8 directions (horizontal, vertical, diagonal).
- Return -1 if there is no such path.

Approach: BFS (Breadth-First Search)
1. If the start or end cell is blocked, return -1.
2. Use BFS with a queue to explore all directions level by level.
3. Use a visited matrix to avoid revisiting cells.
4. Return the path length once we reach the bottom-right cell.

Time Complexity: O(N²) — Visit each cell once at most.  
Space Complexity: O(N²) — Visited matrix + queue storage.
*/

#include <iostream>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q; // {{row, col}, pathLength}
        q.push({{0, 0}, 1});
        vis[0][0] = 1;

        int dirR[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dirC[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while(!q.empty()) {
            auto [cell, path] = q.front(); q.pop();
            int row = cell.first, col = cell.second;

            if(row == n - 1 && col == n - 1) return path;

            for(int i = 0; i < 8; i++) {
                int nRow = row + dirR[i], nCol = col + dirC[i];
                if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < n &&
                   grid[nRow][nCol] == 0 && vis[nRow][nCol] == 0) {
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, path + 1});
                }
            }
        }
        return -1; // Destination unreachable
    }
};