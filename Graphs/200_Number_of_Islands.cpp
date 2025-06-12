/*
LeetCode: 200. Number of Islands
Link: https://leetcode.com/problems/number-of-islands/

Approach:
- Traverse the grid using DFS.
- When a '1' is found, it's the start of a new island.
- Flood-fill all connected land ('1') to '0' to mark as visited.

Time Complexity: O(m * n) - We visit every cell once at most
Space Complexity: O(m * n) - in the worst case due to recursion stack 
*/

#include <iostream>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j){
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0){
            return; 
        }
        if(grid[i][j] == '0')   return; 

        grid[i][j] = '0'; // Mark this as visited 
        
        // Visit all four adjacent directions
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())    return 0;

        int n = grid.size();
        int m = grid[0].size();
        int islandCount = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    islandCount++;
                    dfs(grid, i, j);
                }
            }
        }
        return islandCount;
    }
};


