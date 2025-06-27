/*
LeetCode: 695. Max Area of Island
Link: https://leetcode.com/problems/max-area-of-island/

Problem:
Given a 2D binary grid where 1 represents land and 0 represents water,
return the size of the largest island (connected 1s horizontally or vertically).

Approach: DFS
- Traverse the grid.
- For every unvisited land cell (1), perform DFS to calculate island area.
- Mark visited cells as 0 to avoid revisiting.

Time Complexity: O(n * m) — every cell is visited once.
Space Complexity: O(n * m) — in worst case due to recursion stack.
*/

#include <vector>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size(), m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;  // Mark as visited
        return 1 +
            dfs(grid, i + 1, j) +
            dfs(grid, i - 1, j) +
            dfs(grid, i, j + 1) +
            dfs(grid, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};
