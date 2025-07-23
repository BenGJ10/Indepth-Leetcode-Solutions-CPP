/*
LeetCode: 399. Evaluate Division  
Link: https://leetcode.com/problems/evaluate-division/

Problem:  
You are given equations like `A / B = k`, and some queries like `X / Y = ?`.  
Return the result of each query. If it cannot be determined, return `-1.0`.

Approach: Graph + BFS  
- Build a directed weighted graph: for A / B = k, add edge A→B with weight k and B→A with 1/k.
- For each query X / Y, perform a BFS from X to Y while multiplying edge weights along the path.
- If no path exists, return -1.0.

Time Complexity: O(N + Q * E), where N = #equations, Q = #queries, E = avg. edges per node  
Space Complexity: O(N)
*/
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adjMatrix;

        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0], v = equations[i][1];
            double value = values[i];
            adjMatrix[u].push_back({v, value});
            adjMatrix[v].push_back({u, 1.0 / value});
        }

        vector<double> results;
        for (auto &query : queries) {
            string start = query[0], end = query[1];

            if (!adjMatrix.count(start) || !adjMatrix.count(end)) {
                results.push_back(-1.0);
                continue;
            }
            if (start == end) {
                results.push_back(1.0);
                continue;
            }

            unordered_set<string> vis;
            queue<pair<string, double>> q;
            q.push({start, 1.0});
            vis.insert(start);
            double ans = -1.0;

            while (!q.empty()) {
                auto [curr, product] = q.front(); q.pop();

                if (curr == end) {
                    ans = product;
                    break;
                }

                for (auto &[neighbor, weight] : adjMatrix[curr]) {
                    if (!vis.count(neighbor)) {
                        vis.insert(neighbor);
                        q.push({neighbor, product * weight});
                    }
                }
            }

            results.push_back(ans);
        }

        return results;
    }
};