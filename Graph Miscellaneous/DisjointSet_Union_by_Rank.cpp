/*
Disjoint Set (Union-Find) with Union by Rank and Path Compression

Problem:
Implement a Disjoint Set (Union-Find) data structure that supports:
1. **findParent(x):** Finds the ultimate parent of a node `x` with path compression.
2. **unionByRank(x, y):** Unites two nodes based on their ranks to keep tree height minimal.

Approach:
- **Parent Array:** Tracks each node's parent.
- **Rank Array:** Tracks the rank (approximate height) of each disjoint set.
- **Path Compression:** During `findParent`, directly link nodes to their ultimate parent.
- **Union by Rank:** Always attach the tree with smaller rank to the larger rank tree.

Time Complexity:
- **findParent:** O(α(N)) (Inverse Ackermann Function, nearly constant).
- **unionByRank:** O(α(N)).

Space Complexity: O(N) (Parent and Rank arrays).
*/

#include <iostream>
using namespace std;

class DisjointSet{
private:
    vector<int> rank, parent;
public:
    DisjointSet(int nodes){
        rank.resize(nodes + 1, 0); // Initialize rank to 0 for all nodes
        parent.resize(nodes + 1);  // Initialize parent vector
        for(int i = 0; i <= nodes; i++){ // Set each node as its own parent initially
            parent[i] = i;
        }
    }

    int findParent(int node){ 
        if(node == parent[node]){ // If node is its own parent, return it
            return node;
        }
        return parent[node] = findParent(parent[node]); // Path compression
    }

    void unionByRank(int u, int v){
        int ultimateParent_u = findParent(u); // Find ultimate parent of u
        int ultimateParent_v = findParent(v); // Find ultimate parent of v

        if(ultimateParent_u == ultimateParent_v)    return; // If they are already in the same set, do nothing

        if(rank[ultimateParent_u] < rank[ultimateParent_v]){ // If u's rank is less than v's rank
            parent[ultimateParent_u] = ultimateParent_v;  // Make v the parent of u
        }
        else if(rank[ultimateParent_v] < rank[ultimateParent_u]){ // If v's rank is less than u's rank
            parent[ultimateParent_v] = ultimateParent_u; // Make u the parent of v
        }
        else{ // If ranks are equal
            parent[ultimateParent_u] = ultimateParent_v; // Make v the parent of u
            rank[ultimateParent_v]++; // Increase the rank of v's tree
        }
    }
};

int main(){
    DisjointSet ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if(ds.findParent(3)  == ds.findParent(7)){
        cout << "Same Parent\n";
    }
    else cout << "Not same Parent\n";
    ds.unionByRank(3, 7);
    if(ds.findParent(3)  == ds.findParent(7)){
        cout << "Same Parent\n";
    }
    else cout << "Not same Parent\n";
    return 0;
}