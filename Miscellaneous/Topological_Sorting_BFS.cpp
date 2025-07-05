/**
 * Problem: Topological Sorting using Kahn’s Algorithm (BFS approach)
 * 
 * Given a Directed Acyclic Graph (DAG) with V vertices and an adjacency list, 
 * perform topological sorting using Kahn’s Algorithm.
 *
 * Topological sorting is a linear ordering of vertices such that 
 * for every directed edge u -> v, u comes before v in the ordering.
 *
 * This approach uses:
 * - Indegree array to track incoming edges
 * - A queue to process all nodes with indegree 0 (BFS)
 *
 * Input:
 * - V: Number of vertices
 * - adj: Adjacency list representing directed edges
 *
 * Output:
 * - A vector<int> containing a valid topological order of the graph
 *
 * Constraints:
 * - The input graph must be a Directed Acyclic Graph (DAG)
 *
 * Time Complexity: O(V + E)
 *    - V: number of vertices
 *    - E: number of edges
 *
 * Space Complexity: O(V)
 *    - For indegree array and result storage
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		int indegree[V];
        for(int i = 0; i < V; i++){
            indegree[i] = 0;
        }
        // Calculate indegree of all nodes
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
        // Push all nodes with indegree 0 into the queue   
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
            // Reduce indegree of neighbors
			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}
};
