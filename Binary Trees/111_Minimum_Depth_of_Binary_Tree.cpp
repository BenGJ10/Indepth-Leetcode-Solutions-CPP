/*
111. Minimum Depth of Binary Tree
Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/

------------------------------------------------------
Problem Summary:
Return the minimum depth of a binary tree.
- The minimum depth is the number of nodes along the shortest path
  from the root node down to the nearest leaf node.
- A leaf node is a node with no children.

------------------------------------------------------
Approach (BFS – Level Order):
- Perform a level-order traversal using a queue of pairs (node, depth).
- As soon as we find the first leaf node, return its depth.
  (Because BFS explores level by level, the first leaf encountered
   is guaranteed to be at the minimum depth.)

Steps:
1. If root is null, return 0.
2. Push (root,1) into queue.
3. While queue not empty:
   - Pop the front.
   - If current node is a leaf, return its depth.
   - Otherwise, push children with depth+1.

- Time Complexity:  O(n)   // visit each node at most once
- Space Complexity: O(n)   // queue can store up to n nodes in worst case

------------------------------------------------------
*/

#include <iostream>
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            // If leaf node, we've found the minimum depth
            if (node->left == nullptr && node->right == nullptr)
                return depth;

            if (node->left)  q.push({node->left,  depth + 1});
            if (node->right) q.push({node->right, depth + 1});
        }

        return 0; // should never reach here if root is not null
    }
};
