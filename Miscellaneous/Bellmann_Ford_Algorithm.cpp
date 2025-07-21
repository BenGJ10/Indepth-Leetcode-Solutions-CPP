/*
GeeksforGeeks: Bellman Ford Algorithm  
Link: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

Problem:  
You are given a directed weighted graph with `V` vertices and `E` edges.  
Find the shortest distances from source `src` to all vertices using the **Bellman-Ford algorithm**.  
If a negative weight cycle exists, return {-1}.

Approach:
- Initialize distance of source to 0 and others to INF (1e8).
- Relax all edges `V-1` times.
- Do one more iteration to detect **negative weight cycle**.

Time Complexity: O(V * E)  
Space Complexity: O(V)
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto &edge : edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative weight cycles
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                return {-1};
            }
        }

        return dist;
    }
};