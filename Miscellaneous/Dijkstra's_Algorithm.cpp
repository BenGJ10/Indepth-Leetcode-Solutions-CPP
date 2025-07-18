/**
 * Dijkstra’s Shortest Path Algorithm using Min-Heap (Priority Queue)
 * 
 * Given a weighted, undirected graph with `V` vertices and `E` edges,
 * find the shortest distance from a source vertex `src` to all other vertices.
 * 
 * Approach:
 * 1. Convert edge list to adjacency list `adj[u] = vector of {v, weight}`
 * 2. Initialize:
 *    - Distance array: `dist[i] = INT_MAX`, except `dist[src] = 0`
 *    - Min-heap priority queue: stores pairs of `{distance, node}`
 * 3. While priority queue is not empty:
 *    a. Pop the node with the smallest known distance
 *    b. For each neighbor:
 *       - If the path through current node is shorter, update the distance
 *       - Push the updated distance into the queue
 * 4. Return the `dist` array
 * 
 * Time Complexity:
 * - O((V + E) * log V), using a min-heap for efficiency
 * 
 * Space Complexity:
 * - O(V + E) for adjacency list and heap storage
 */
#include <iostream>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dist[src] = 0;
        pq.push({src, 0});
        
        while(!pq.empty()){
            int node = pq.top().first;
            int currDist = pq.top().second;
            pq.pop();
            
            for(auto &neighbor: adj[node]){
                int adjNode = neighbor.first;
                int adjDist = neighbor.second;
                
                if(adjDist + currDist < dist[adjNode]){
                    dist[adjNode] = adjDist + currDist;
                    pq.push({adjNode, dist[adjNode]});
                }
            }
        }
        return dist;
    }
};