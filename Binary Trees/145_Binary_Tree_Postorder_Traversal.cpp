/*
145. Binary Tree Postorder Traversal
Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

------------------------------------------------------
Problem Summary:
Return the postorder traversal of a binary tree's node values.  
Postorder order is: **Left → Right → Root**.

------------------------------------------------------
Recursive Approach:
1. Visit left subtree.
2. Visit right subtree.
3. Process current node (push its value).

- Time Complexity: O(n)  (every node visited once)
- Space Complexity: O(h) recursion stack, where h = tree height.

------------------------------------------------------
Iterative Approach (Using Stack):
1. Use two stacks or a single stack with reversed preorder logic.
   - Traverse like Root → Right → Left, then reverse the result.

- Time Complexity: O(n)
- Space Complexity: O(n) in worst case.

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
    // Recursive helper for postorder
    void postOrder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
};
