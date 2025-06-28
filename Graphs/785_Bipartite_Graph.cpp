/*
LeetCode: 785. Is Graph Bipartite?
Link: https://leetcode.com/problems/is-graph-bipartite/

Problem:
A graph is bipartite if you can split its nodes into two groups such that:
- No two adjacent nodes share the same group (or color).

Approach: DFS + 2-coloring
- Use DFS to try coloring the graph using two colors (0 and 1).
- If any adjacent nodes have the same color, return false.

Time Complexity: O(V + E)
Space Complexity: O(V) for color array and recursion stack
*/

#include <vector>
using namespace std;
class Solution {
private:
    bool dfs(vector<vector<int>> &graph, vector<int> &colors, int node, int col){
        colors[node] = col;

        for(auto neighbor : graph[node]){
            if(colors[neighbor] == -1){
                if(dfs(graph, colors, neighbor, !col) == false) return false;
            }
            else if(colors[neighbor] == col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);

        for(int i = 0; i < n; i++){
            if(colors[i] == -1){
                if(dfs(graph, colors, i, 0) == false)   return false;
            }
        }
        return true;
    }
};

/*
Approach: BFS (Iterative 2-coloring)

- Use BFS to color each connected component with 0 and 1.
- If any neighbor has the same color as the current node, return false.

Time Complexity: O(V + E)
Space Complexity: O(V)
*/

#include <vector>
#include <queue>
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);

        for (int i = 0; i < n; ++i) {
            if (colors[i] == -1) {
                queue<int> q;
                q.push(i);
                colors[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if (colors[neighbor] == -1) {
                            colors[neighbor] = 1 - colors[node];
                            q.push(neighbor);
                        } 
                        else if (colors[neighbor] == colors[node]) {
                            return false; 
                        }
                    }
                }
            }
        }
        return true;
    }
};