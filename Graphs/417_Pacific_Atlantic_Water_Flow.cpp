/*
LeetCode: 417. Pacific Atlantic Water Flow
Link: https://leetcode.com/problems/pacific-atlantic-water-flow/

Problem:
Given an m x n matrix of non-negative integers representing the height of each cell,
return a list of coordinates where water can flow to both the Pacific and Atlantic oceans.

Approach:
- Perform DFS from the cells adjacent to the Pacific (top/left) and Atlantic (bottom/right) edges.
- Water can flow from a cell to neighboring cells with height ≤ current cell.
- Mark reachable cells for both oceans and find intersection.

Time Complexity: O(m * n)
Space Complexity: O(m * n) — for visited arrays
*/

#include <vector>
using namespace std;
class Solution {
public:
    
    
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &vis, int i, int j, int prevHeight){
        int rows = heights.size();
        int cols = heights[0].size();
        
        if(i < 0 || j < 0 || i >= rows || j >= cols || vis[i][j] == true || 
            heights[i][j] < prevHeight){
                return;
            }

        vis[i][j] = true;
        dfs(heights, vis, i + 1, j, heights[i][j]);
        dfs(heights, vis, i - 1, j, heights[i][j]);
        dfs(heights, vis, i, j + 1, heights[i][j]);
        dfs(heights, vis, i, j - 1, heights[i][j]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        vector<vector<int>> result;

        for(int i = 0; i < rows; i++){
            dfs(heights, pacific, i, 0, heights[i][0]);
            dfs(heights, atlantic, i, cols - 1, heights[i][cols - 1]);
        }

        for(int j = 0; j < cols; j++){
            dfs(heights, pacific, 0, j, heights[0][j]);
            dfs(heights, atlantic, rows - 1, j, heights[rows - 1][j]);
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};