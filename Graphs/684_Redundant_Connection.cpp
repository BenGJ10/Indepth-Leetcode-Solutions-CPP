/*
LeetCode: 684. Redundant Connection  
Link: https://leetcode.com/problems/redundant-connection/

Problem:  
Given a tree with one extra edge added (making it a graph with exactly one cycle),  
find and return the edge that can be removed to restore it to a tree.

Approach: Disjoint Set (Union by Rank)
- Initialize DSU with all nodes as their own parent.
- For every edge:
    - If both nodes belong to the same parent, it forms a cycle → return this edge.
    - Else, union them.
- The redundant edge is the one that introduces a cycle.

Time Complexity: O(N * α(N))  (α(N) ≈ constant for DSU)  
Space Complexity: O(N) (Parent and Rank arrays)
*/

#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> parent, rank;
    
    int findParent(int node){
        if(node == parent[node])    return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        } else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        } else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        rank.resize(V + 1, 0);
        parent.resize(V + 1);
        for(int i = 0; i <= V; i++){
            parent[i] = i;
        }

        vector<int> redundantEdge;
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            if(findParent(u) == findParent(v)){
                redundantEdge = edge; 
            } else{
                unionByRank(u, v);
            }
        }
        return redundantEdge;
    }
};

