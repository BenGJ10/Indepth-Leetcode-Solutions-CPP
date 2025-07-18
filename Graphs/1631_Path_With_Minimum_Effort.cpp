/*
LeetCode: 1631. Path With Minimum Effort  
Link: https://leetcode.com/problems/path-with-minimum-effort/

Problem:
You are given a 2D grid of heights. Find a path from top-left to bottom-right such that the maximum **absolute difference** in heights between consecutive cells along the path is minimized.

Approach: Dijkstra's Algorithm (Modified)
- Treat each cell as a node in a graph.
- Instead of minimizing sum of weights, we minimize the **maximum difference** in height.
- Use a min-heap (priority_queue with greater) to greedily choose the path with the minimum current effort.

Steps:
1. Initialize a distance matrix with `INT_MAX`.
2. Push `{0,0}` into the priority queue with 0 effort.
3. For each neighbor, calculate `nextEffort = max(currentEffort, abs(heightDiff))`.
4. If `nextEffort` is better, update and push it to the queue.
5. Stop when the destination cell is popped.

Time Complexity: O(M * N * log(M * N))  
Space Complexity: O(M * N)
*/

#include <iostream>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<
        pair<pair<int, int>, int>,
        vector<pair<pair<int, int>, int>>,
        greater<pair<pair<int, int>, int>>>pq;

        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));
        dist[0][0] = 0;
        pq.push({{0, 0}, 0});

        int dirs[5] = {-1, 0, 1, 0, -1};
        while(!pq.empty()){
            int row = pq.top().first.first;
            int col = pq.top().first.second;
            int currDiff = pq.top().second;
            pq.pop();

            if(row == rows - 1 && col == cols - 1)  return currDiff;
            for(int i = 0; i < 4; i++){
                int nRow = row + dirs[i];
                int nCol = col + dirs[i + 1];
                if(nRow >= 0 && nCol >= 0 && nRow < rows && nCol < cols){
                    int nextEffort = max(abs(heights[nRow][nCol] - heights[row][col]), currDiff);
                    if(nextEffort < dist[nRow][nCol]){
                        dist[nRow][nCol] = nextEffort;
                        pq.push({{nRow, nCol}, nextEffort});
                    }
                }
            }
        }
        return 0;
    }
};