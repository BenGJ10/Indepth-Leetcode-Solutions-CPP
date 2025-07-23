/*
LeetCode: 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance  
Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

Problem:  
Given `n` cities and a list of `edges` with distances between pairs of cities,  
find the city with the **smallest number of neighbors** reachable within `distanceThreshold`.  
If multiple cities have the same minimum count, return the **city with the largest number**.

Approach: Floyd-Warshall Algorithm
- Use Floyd-Warshall to compute shortest distances between all pairs of cities.
- For each city, count how many other cities are reachable within `distanceThreshold`.
- Track the city with the minimum reachable count. On ties, prefer the higher index.

Time Complexity: O(n^3)  
Space Complexity: O(n^2)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for (int i = 0; i < n; ++i) dist[i][i] = 0;

        for (int via = 0; via < n; ++via) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][via] == INT_MAX || dist[via][j] == INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        int resultCity = -1, minReachable = n;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) ++count;
            }
            if (count <= minReachable) {
                minReachable = count;
                resultCity = i;
            }
        }

        return resultCity;
    }
};
