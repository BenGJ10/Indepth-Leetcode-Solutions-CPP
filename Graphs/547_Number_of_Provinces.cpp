/*
LeetCode: 547. Number of Provinces  
Link: https://leetcode.com/problems/number-of-provinces/

Problem:  
You are given an `n x n` matrix `isConnected` where `isConnected[i][j] = 1` if city `i` and city `j` are directly connected.  
Return the number of **provinces** (connected components in an undirected graph).

Approach: Disjoint Set (Union by Rank)
- Treat each city as a node in a graph.
- Use Disjoint Set to merge connected cities into the same component.
- Finally, count how many nodes are their own parent (representing distinct provinces).

Time Complexity: O(N² * α(N))  (α(N) ≈ constant for DSU)  
Space Complexity: O(N) (Parent and Rank arrays)
*/
#include <iostream>
using namespace std;
class DisjointSet{
public:
    vector<int> parent, rank;
    DisjointSet(int nodes){
        rank.resize(nodes + 1, 0);
        parent.resize(nodes + 1);
        for(int i = 0; i <= nodes; i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(node == parent[node])    return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int v, int u){
        int ultPar_u = findParent(u);
        int ultPar_v = findParent(v);

        if(ultPar_u == ultPar_v)    return;

        if(rank[ultPar_u] < rank[ultPar_v]){
            parent[ultPar_u] = ultPar_v;
        } else if(rank[ultPar_v] < rank[ultPar_u]){
            parent[ultPar_v] = ultPar_u;
        } else {
            parent[ultPar_v] = ultPar_u;
            rank[ultPar_v]++;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        DisjointSet ds(V);

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1){
                    ds.unionByRank(i, j);
                }
            }
        }

        int count = 0;
        for(int i = 0; i < V; i++){
            if(ds.parent[i] == i)   count++;
        }
        return count;
    }
};