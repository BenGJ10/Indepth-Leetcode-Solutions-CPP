/*
LeetCode: 802. Find Eventual Safe States
Link: https://leetcode.com/problems/find-eventual-safe-states/

Approach:
- Terminal nodes have no outgoing edges.
- Instead of marking unsafe nodes directly, reverse the graph.
- Then apply Kahn's Algorithm (Topological Sort) to identify nodes that eventually lead to terminal nodes.

Steps:
1. Reverse the graph: For each edge u → v, store it as v → u in reverseGraph.
2. Track indegree of each node in the original graph.
3. Start with all terminal nodes (indegree 0 in reversed graph).
4. BFS: For each node, reduce indegree of connected nodes.
5. Nodes whose indegree drops to 0 are safe.
6. Sort the result before returning.

Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> indegree(n, 0);

        // Step 1: Reverse the edges and calculate indegrees
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                reverseGraph[v].push_back(u); // reverse edge u → v as v → u
                indegree[u]++;
            }
        }

        // Step 2: Start with nodes that had no outgoing edges originally (indegree 0 now)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> safeNodes;

        // Step 3: Standard BFS (Kahn’s Topological Sort)
        while (!q.empty()) {
            int node = q.front(); q.pop();
            safeNodes.push_back(node);

            for (int neighbor : reverseGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
