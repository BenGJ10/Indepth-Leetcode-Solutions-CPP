/*
LeetCode: 743. Network Delay Time  
Link: https://leetcode.com/problems/network-delay-time/

Problem:
You are given a list of travel times `times`, where each entry `[u, v, w]` represents a directed edge
from node `u` to `v` with a time cost `w`. There are `n` nodes labeled from `1` to `n`. 
You are also given a starting node `k`. Return the time it takes for all nodes to receive the signal.
If it is impossible, return -1.

Approach: Dijkstra’s Algorithm (Single Source Shortest Path)
- We create an adjacency list of the graph.
- Use a min-heap (priority queue) to greedily pick the next node with the smallest accumulated time.
- Maintain a `dist` array to store the minimum time to reach each node.
- At the end, if any node is unreachable, return -1.
- Otherwise, return the maximum time in the `dist` array.

Time Complexity: O(E log V)  
Space Complexity: O(N + E)
*/

#include <iostream>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto &time: times){
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({w, v});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            int adjTime = pq.top().first;
            int adjNode = pq.top().second;
            pq.pop();

            for(auto &neighbor: adj[adjNode]){
                int nextTime = neighbor.first;
                int nextNode = neighbor.second;
                if(nextTime + adjTime < dist[nextNode]){
                    dist[nextNode] = nextTime + adjTime;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        int minTime = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX)  return -1;
            minTime = max(minTime, dist[i]);
        }
        return minTime;
    }
};