/*
144. Binary Tree Preorder Traversal
Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

------------------------------------------------------
Problem Summary:
Return the preorder traversal of a binary tree's node values.  
Preorder traversal order is: **Root → Left → Right**.

------------------------------------------------------
Brute Force / Recursive Approach:
1. Use a helper function:
   - Visit the current node (push its value).
   - Recur on the left subtree.
   - Recur on the right subtree.

- Time Complexity: O(n)  (visit each node once)  
- Space Complexity: O(h) recursion stack, where h = tree height.

------------------------------------------------------
Iterative Approach (Using Stack):
1. Use an explicit stack:
   - Push the root.
   - While stack not empty:
     - Pop node, record value.
     - Push right child, then left child (so left is processed first).
2. Return the collected list.

- Time Complexity: O(n)  
- Space Complexity: O(n) in worst case (skewed tree).

------------------------------------------------------
*/

#include <iostream>
#include <vector>
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
    // Recursive helper for preorder
    void preorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};
