/*
LeetCode: 1976. Number of Ways to Arrive at Destination  
Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

Problem:  
You are given a weighted graph with `n` nodes and edges in `roads`. Each road connects two cities with a travel time.  
Find the number of **shortest paths** from city `0` to city `n - 1`. Return the count modulo 1e9+7.

Approach: Dijkstra's Algorithm + Path Counting
- Use a priority queue to implement Dijkstra’s algorithm for shortest path from node 0.
- Maintain a `ways[]` array to count number of shortest paths to each node.
- For every neighbor:
    - If a **shorter path** is found, update the distance and reset ways.
    - If an **equal path** is found, increment the ways count.

Time Complexity: O((N + E) * log N)  
Space Complexity: O(N + E)
*/
#include <iostream>
using namespace std;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> adj(n);
        for(auto &road: roads){
            long long u = road[0], v = road[1], t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        priority_queue<pair<long long, int>,
        vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX), ways(n, 0);
        pq.push({0, 0});
        dist[0] = 0, ways[0] = 1;
        int mod = (int)1e9 + 7;

        while(!pq.empty()){
            long long currDist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto &neighbor: adj[currNode]){
                long long newDist = currDist + neighbor.second;
                int newNode = neighbor.first;
                if(newDist < dist[newNode]){
                    dist[newNode] = newDist;
                    ways[newNode] = ways[currNode];
                    pq.push({newDist, newNode});
                }
                else if(newDist == dist[newNode]){
                    ways[newNode] = (ways[newNode] + ways[currNode]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};