/*
110. Balanced Binary Tree
Link: https://leetcode.com/problems/balanced-binary-tree/

------------------------------------------------------
Problem Summary:
Determine if a binary tree is height-balanced.
- A binary tree is height-balanced if for every node,
  the difference in height between its left and right
  subtrees is at most 1.

------------------------------------------------------
Optimal Approach (Bottom-Up DFS):
1. Recursively compute the height of each subtree.
2. For each node:
   - If the left or right subtree is unbalanced, propagate -1 upward.
   - If the height difference between left and right > 1, return -1.
   - Otherwise, return 1 + max(leftHeight, rightHeight).

3. The tree is balanced if the helper function does not return -1.

- Time Complexity:  O(n)  
  Each node's height is calculated once.
- Space Complexity: O(h)  
  h = height of tree (stack space for recursion).

------------------------------------------------------
*/

#include <iostream>
#include <cmath>
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
    int height(TreeNode* root) {
        if (root == nullptr) return 0;

        int left  = height(root->left);
        if (left == -1) return -1;   // left subtree unbalanced

        int right = height(root->right);
        if (right == -1) return -1;  // right subtree unbalanced

        if (abs(left - right) > 1) return -1;  // current node unbalanced

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
