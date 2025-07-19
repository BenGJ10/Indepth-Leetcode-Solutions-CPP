/*
LeetCode: 787. Cheapest Flights Within K Stops  
Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/

Problem:
Given a list of flights as edges [u, v, w], find the cheapest price from src to dst with at most k stops.
Return the minimum cost to travel from `src` to `dst` with at most `k` stops.
If such a route doesn't exist, return -1.

Approach: Modified BFS (Bellman-Ford inspired)
- Build an adjacency list of the graph.
- Use a queue to perform level-based BFS traversal, keeping track of (city, cost so far, stops so far).
- Each level of BFS corresponds to one stop.
- Maintain a `minCost[]` array to store the cheapest cost to reach each city.
- Push to queue only if the new cost is cheaper and the number of stops <= k.
- If the destination is reached with minimal cost within k stops, return the cost.
- If no such path exists, return -1.

Time Complexity: O(k * E)  
Space Complexity: O(N + E)
*/

#include <iostream>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &flight: flights){
            int f = flight[0], t = flight[1], p = flight[2];
            adj[f].push_back({t, p}); // {dest, price}
        }
        queue<tuple<int, int, int>> q;  // {current_node, cost_so_far, stops_so_far}
        vector<int> minCost(n, INT_MAX);
        q.push({src, 0, 0});
        minCost[src] = 0;

        while(!q.empty()){
            auto [node, cost, stops] = q.front();
            q.pop();
            if(stops > k)   break;
            for(auto &neighbor: adj[node]){
                auto [adjNode, adjPrice] = neighbor;
                int newCost = cost + adjPrice;
                if(newCost < minCost[adjNode]){
                    minCost[adjNode] = cost + adjPrice;
                    q.push({adjNode, newCost, stops + 1});
                }
            }
        }
        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
