/*
543. Diameter of Binary Tree
Link: https://leetcode.com/problems/diameter-of-binary-tree/

------------------------------------------------------
Problem Summary:
Find the diameter of a binary tree.
- The diameter is the length of the longest path
  between any two nodes (number of edges on that path).

------------------------------------------------------
Optimal Approach (DFS + Height Calculation):
1. Perform a post-order DFS to compute the height of each subtree.
2. For every node:
   - Height = 1 + max(height of left, height of right).
   - Update global `diameter` as max(diameter, leftHeight + rightHeight).
     (leftHeight + rightHeight = number of edges on the longest path through this node).

- Time Complexity:  O(n)  
  Each node is visited once.
- Space Complexity: O(h)  
  h = height of tree (recursion stack).

------------------------------------------------------
*/

#include <iostream>
#include <algorithm>
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
    int findHeight(TreeNode* root, int &diameter) {
        if (root == nullptr) return 0;

        int left  = findHeight(root->left, diameter);
        int right = findHeight(root->right, diameter);

        // Update diameter if path through current node is longer
        diameter = max(diameter, left + right);

        // Return height of current node
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findHeight(root, diameter);
        return diameter;
    }
};
