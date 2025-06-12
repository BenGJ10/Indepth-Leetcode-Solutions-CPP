/*
LeetCode: 133. Clone Graph
Link: https://leetcode.com/problems/clone-graph/

Approach:
- Use DFS and a hash map to clone the graph.
- For each node:
  - If it's already cloned, return the clone.
  - Otherwise, create a new node, store the mapping, and recursively clone its neighbors.

Why Hash Map?
- Prevents infinite loops due to cycles in the graph.
- Keeps track of already created (cloned) nodes.

Time Complexity: O(N) — where N is the number of nodes.
Space Complexity: O(N) — for the hash map and recursion stack.
*/

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors(vector<Node*>()) {}
    Node(int _val) : val(_val), neighbors(vector<Node*>()) {}
}

#include <iostream>
using namespace std;
class Solution {
public:
    unordered_map<Node*, Node*> cloneMap;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        // If this node was already cloned, return the clone
        if(cloneMap.find(node) != cloneMap.end()){
            return cloneMap[node];
        }

        // Create the clone node with the same value
        Node* clone = new Node(node->val); 
        // Store this clone in the map
        cloneMap[node] = clone;

        // Recursively clone all neighbors
        for(Node* neighbor: node->neighbors){
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};