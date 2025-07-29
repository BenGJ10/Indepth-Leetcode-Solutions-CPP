/*
LeetCode: 947. Most Stones Removed with Same Row or Column  
Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

Problem:  
You are given `n` stones placed on a 2D plane at coordinates (x, y).  
A stone can be removed if there exists another stone in the **same row** or **same column**.  
Return the maximum number of stones that can be removed.

Approach: Disjoint Set (Union by Rank)
- Treat rows and columns as separate nodes in a DSU (offset columns by maxRow+1).
- Union the row node and column node for every stone.
- Count the number of connected components among all nodes that have stones.
- The answer = total stones - number of connected components.

Time Complexity: O(N * α(N)) (almost linear due to DSU operations)  
Space Complexity: O(N)
*/

#include <iostream>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int nodes) {
        rank.resize(nodes + 1, 0);
        parent.resize(nodes + 1);
        for (int i = 0; i <= nodes; i++) parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pv] < rank[pu]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;

        // Find max row and column index
        for (auto &stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;

        // Union row node and column node for each stone
        for (auto &stone : stones) {
            int nodeRow = stone[0];
            int nodeCol = stone[1] + maxRow + 1; // Offset columns
            ds.unionByRank(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        // Count connected components
        int components = 0;
        for (auto &stoneNode : stoneNodes) {
            if (ds.findParent(stoneNode.first) == stoneNode.first) {
                components++;
            }
        }

        return n - components; // Stones that can be removed
    }
};
