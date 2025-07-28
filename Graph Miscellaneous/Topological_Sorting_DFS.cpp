/**
 * Problem: Topological Sorting of a Directed Acyclic Graph (DAG)
 * 
 * Given a Directed Acyclic Graph (DAG) with V vertices and a list of edges,
 * perform a topological sort and return the ordering of vertices.
 *
 * Topological sorting of a graph is a linear ordering of its vertices 
 * such that for every directed edge u -> v, vertex u comes before v in the ordering.
 *
 * This solution uses Depth-First Search (DFS) and a stack to record the order.
 *
 * Input:
 * - V: Number of vertices (0-indexed)
 * - edges: Adjacency list representing the directed edges
 *
 * Output:
 * - A vector<int> containing the topological sort of the graph
 *
 * Constraints:
 * - The graph must be a DAG (no cycles)
 *
 * Time Complexity: O(V + E)
 *    - V: number of vertices
 *    - E: number of edges
 *
 * Space Complexity: O(V)
 *    - For the visited array and the recursion stack
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    void dfs(int node, int vis[], stack<int> &st, vector<vector<int>> &edges) {
        vis[node] = 1;
        for (auto elem : edges[node]) {
            if (!vis[elem]) {
                dfs(elem, vis, st, edges);
            }
        }
        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        stack<int> st;
        int vis[V];
        for(int i = 0; i < V; i++){
            vis[i] = 0;
        }
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, st, edges);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
