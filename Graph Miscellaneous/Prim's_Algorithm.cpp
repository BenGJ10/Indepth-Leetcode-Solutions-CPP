/*
GFG: Minimum Spanning Tree (Prim's Algorithm)  
Link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

Problem:
Given a connected, undirected, weighted graph with V vertices and adjacency list `edges`, 
find the sum of weights of edges in its Minimum Spanning Tree (MST).

Approach: Prim’s Algorithm (Greedy)
- Use a min-heap (priority queue) to always pick the edge with the smallest weight.
- Start from any node (here node 0).
- Maintain a `visited[]` array to track included nodes.
- For each node added, push all its unvisited neighbors into the min-heap.
- Continue until all vertices are visited, summing selected edge weights.

Time Complexity: O(E log V)  
Space Complexity: O(V + E)
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> edges[]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);

        pq.push({0, 0}); // {weight, node}
        int sum = 0;

        while(!pq.empty()){
            auto [currWeight, currNode] = pq.top();
            pq.pop();

            if(vis[currNode]) continue;
            vis[currNode] = 1;
            sum += currWeight;

            for(auto &neighbor: edges[currNode]){
                int adjNode = neighbor[0];
                int adjWeight = neighbor[1];
                if(!vis[adjNode]){
                    pq.push({adjWeight, adjNode});
                }
            }
        }
        return sum;
    }
};