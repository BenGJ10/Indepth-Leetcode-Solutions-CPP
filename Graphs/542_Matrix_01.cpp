/*
LeetCode: 542. 01 Matrix
Link: https://leetcode.com/problems/01-matrix/

Problem:
Given an m x n binary matrix `mat`, return the distance of the nearest 0 for each cell.

Approach: Multi-source BFS
- Start BFS from all 0s simultaneously.
- Initialize a distance matrix `dist` with -1.
- Set distance of 0s to 0 and push their positions into a queue.
- For each 0, update neighboring 1s with distance +1.

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();

        vector<vector<int>> dist(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dirs[5] = {0, 1, 0, -1, 0};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int nRow = row + dirs[d];
                int nCol = col + dirs[d + 1];
            
                if (nRow >= 0 && nCol >= 0 && nRow < rows && nCol < cols && dist[nRow][nCol] == -1) {
                    dist[nRow][nCol] = dist[row][col] + 1;
                    q.push({nRow, nCol});
                }
            }
        }
        return dist;
    }
};