/*
94. Binary Tree Inorder Traversal
Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

------------------------------------------------------
Problem Summary:
Return the inorder traversal of a binary tree's node values.  
Inorder traversal order is: **Left → Root → Right**.

------------------------------------------------------
Brute Force / Recursive Approach:
1. Use a helper function:
   - Recur on the left subtree.
   - Visit the current node (push its value).
   - Recur on the right subtree.

- Time Complexity: O(n)  (visit each node once)  
- Space Complexity: O(h) recursion stack, where h = tree height.

------------------------------------------------------
Iterative Approach (Using Stack):
1. Maintain an explicit stack and pointer `curr`:
   - While `curr` or stack not empty:
     - Go left as far as possible, pushing nodes.
     - Pop from stack, record value, move to right child.

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
    // Recursive helper for inorder
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
