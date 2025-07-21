/*
Biweekly Contest 162: Count Islands with Sum Divisible by K

Problem:  
Given a 2D grid of positive integers, count the number of islands (connected components of non-zero values)  
where the sum of values in the island is divisible by `k`.

Approach: DFS + Visited Matrix  
- Traverse the grid using DFS to find connected components.
- For each island, compute the sum of values using DFS.
- If the sum is divisible by `k`, increment the count.

Time Complexity: O(n * m)  
Space Complexity: O(n * m) (visited matrix + DFS stack)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    long long dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (i < 0 || j < 0 || i >= rows || j >= cols || vis[i][j] || grid[i][j] == 0)
            return 0;

        vis[i][j] = 1;

        long long sum = grid[i][j];
        sum += dfs(grid, vis, i + 1, j);
        sum += dfs(grid, vis, i - 1, j);
        sum += dfs(grid, vis, i, j + 1);
        sum += dfs(grid, vis, i, j - 1);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int count = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    long long total = dfs(grid, vis, i, j);
                    if (total % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};