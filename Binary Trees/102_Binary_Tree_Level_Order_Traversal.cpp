/*
102. Binary Tree Level Order Traversal
Link: https://leetcode.com/problems/binary-tree-level-order-traversal/

------------------------------------------------------
Problem Summary:
Return the level order traversal of a binary tree’s nodes’ values.
Level order = Breadth-First Search (BFS):
Visit all nodes of depth 0, then depth 1, and so on.

------------------------------------------------------
Approach (BFS using Queue):
1. Push the root node into a queue.
2. While queue is not empty:
   - Determine current queue size (all nodes at this level).
   - Pop those nodes, collect their values, and enqueue their children.
3. Append each level’s values to the result vector.

- Time Complexity:  O(n)   // each node visited exactly once
- Space Complexity: O(n)   // queue can hold up to n/2 nodes in the last level

------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
        }
        return result;
    }
};
