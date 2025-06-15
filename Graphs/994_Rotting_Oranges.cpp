/*
LeetCode: 994. Rotting Oranges
Link: https://leetcode.com/problems/rotting-oranges/

Approach:
- Use BFS starting from all rotten oranges.
- For each minute, spread the rot to adjacent fresh oranges.
- Track time and count fresh oranges.
- If any fresh orange remains unrotted after BFS, return -1.

Time Complexity: O(n * m) — where n = number of rows, m = number of columns  
Space Complexity: O(n * m) — for queue and visited grid
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(rows, vector<int>(cols));
        int fresh = 0;

        // Initialize queue with all rotten oranges and count fresh oranges
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } 
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1) fresh++;
            }
        }

        int dirRow[4] = {-1, 0, 1, 0};
        int dirCol[4] = {0, 1, 0, -1};
        int maxTime = 0;

        // BFS traversal
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            maxTime = max(maxTime, time);
            q.pop();

            for(int i = 0; i < 4; i++){
                int nRow = row + dirRow[i];
                int nCol = col + dirCol[i];
                if(nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols 
                && grid[nRow][nCol] == 1 && vis[nRow][nCol] == 0){
                    vis[nRow][nCol] = 2;
                    fresh--;
                    q.push({{nRow, nCol}, time + 1});
                }
            }
        }
        if(fresh > 0)   return -1;
        return maxTime;
    }
};