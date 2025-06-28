/*
LeetCode: 1020. Number of Enclaves
Link: https://leetcode.com/problems/number-of-enclaves/

Problem:
Given a grid of 0s (water) and 1s (land), return the number of land cells 
that cannot reach the boundary (i.e., are fully enclosed).

Approach: BFS
- Enqueue all land cells (`1`) on the boundary and mark them visited.
- Perform BFS to mark all connected land cells as visited.
- Finally, count all unvisited land cells (these are enclaves).

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>>vis(rows, vector<int>(cols, 0));
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(i == 0 || j == 0 || i == (rows - 1) || j == (cols - 1)){
                    if(grid[i][j] == 1){
                        vis[i][j] = 1;
                        q.push({i, j});
                    }
                }                    
            }
        }

        int dirs[5] = {0, 1, 0, -1, 0}; 
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nRow = row + dirs[i];
                int nCol = col + dirs[i + 1];
                if(nRow >= 0 && nCol >= 0 && nRow < rows && nCol < cols && grid[nRow][nCol] == 1 && vis[nRow][nCol] == 0){
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                }
            }    
        }
        
        int count = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    count++;
                }
            }
        }
        return count;
    }
};