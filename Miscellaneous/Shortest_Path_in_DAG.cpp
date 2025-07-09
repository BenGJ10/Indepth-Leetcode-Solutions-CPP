// Shortest Path in Directed Acyclic Graph using Topological Sort
/*
  Finding the shortest path to a vertex is easy if you already know the shortest paths to all the vertices that can precede it.
  Processing the vertices in topological order ensures that by the time you get to a vertex, you've already processed all the 
  vertices that can precede it which reduces the computation time significantly.

  Dijkstra's algorithm is necessary for graphs that can contain cycles because they can't be topologically sorted. In other cases, 
  the topological sort would work fine as we start from the first node, and then move on to the others in a directed manner.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
    void topoSortDFS(int node, vector<int> &vis, stack<int> &st, vector<vector<pair<int, int>>> &adj){
        vis[node] = 1;
        for(auto &neighbor: adj[node]){
            int v = neighbor.first;
            if(!vis[v]){
                topoSortDFS(v, vis, st, adj);
            }
        }
        st.push(node);
    }
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges){
        // Creating adjacency list
        vector<vector<pair<int, int>>> adj(N);
        for(int i = 0; i < N; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
        }

        // Topological Sort
        vector<int> vis(N, 0);
        stack<int> st;
        for(int i = 0; i < N; i++){
            if(!vis[i]){
                topoSortDFS(i, vis, st, adj);
            }
        }

        // Shortest Path Calculation
        vector<int> dist(N, INT_MAX);
        dist[0] = 0; // setting the distance of the source node to 0

        // Here we process nodes in reverse topological order because we want to ensure that when we process a node, 
        // all its predecessors have already been processed.
        while(!st.empty()){
            int node = st.top();
            st.pop();
            // If the node is reachable, update its neighbors
            if(dist[node] != INT_MAX){
                for(auto &it : adj[node]){
                    int v = it.first;
                    int wt = it.second;

                    if(dist[node] + wt < dist[v]){
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // Replace INT_MAX with -1 for unreachable nodes
        for(int i = 0; i < N; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        return dist;
    }       
};