/*
GeeksforGeeks: Floyd Warshall  
Link: https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

Problem:
You are given an adjacency matrix `dist[][]` of a graph with `n` vertices.  
The task is to **update it to show shortest distances between all pairs of vertices**  
using the **Floyd-Warshall Algorithm**.

Approach:
- For each vertex `via`, try to update all pairs (i, j) with:  
  `dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j])`
- Handle `1e8` (infinity) values correctly to avoid overflow.

Time Complexity: O(N³)  
Space Complexity: O(1) (in-place updates)

Note:
- If `dist[i][j] == 1e8`, it means there's no path from i to j.
- This algorithm is used for Multi-Source shortest path finding.
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();

        for (int via = 0; via < n; ++via) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][via] == 1e8 || dist[via][j] == 1e8) continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }
};