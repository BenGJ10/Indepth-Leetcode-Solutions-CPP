/*
LeetCode: 1319. Number of Operations to Make Network Connected  
Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

Problem:  
You are given `n` computers and a list of connections. A connection is a direct cable between two computers.  
Return the minimum number of operations to connect all computers, or -1 if impossible.  
An operation is moving an extra cable to connect two disconnected components.

Approach: Disjoint Set (Union by Rank)
- Use DSU to find connected components.
- Count extra cables (edges that connect already connected nodes).
- To connect all components, we need at least (components - 1) cables.
- If extra cables ≥ components - 1, return components - 1, else return -1.

Time Complexity: O(N + E * α(N)) (almost linear)  
Space Complexity: O(N)
*/

#include <iostream>
using namespace std;
class DisjointSet{
public:
    vector<int> parent, rank;
    DisjointSet(int nodes){
        rank.resize(nodes + 1);
        parent.resize(nodes + 1);
        for(int i = 0; i <= nodes; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(parent[node] == node)    return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ultPar_u = findParent(u);
        int ultPar_v = findParent(v);

        if(ultPar_u == ultPar_v) return;
        if(rank[ultPar_u] < rank[ultPar_v]){
            parent[ultPar_u] = ultPar_v;
        } else if(rank[ultPar_v] < rank[ultPar_u]){
            parent[ultPar_v] = ultPar_u;
        } else{
            parent[ultPar_v] = ultPar_u;
            rank[ultPar_u]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int countExtraNodes = 0;

        for(auto &connection: connections){
            int u = connection[0], v = connection[1];
            if(ds.findParent(u) == ds.findParent(v)){
                countExtraNodes++;
            }
            else{
                ds.unionByRank(u, v);
            }
        }

        int connectedComponents = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i) connectedComponents++;
        }

        if(countExtraNodes >= connectedComponents - 1){
            return connectedComponents - 1;
        }
        return -1;
    }
};