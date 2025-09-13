/*
124. Binary Tree Maximum Path Sum
Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

------------------------------------------------------
Problem Summary:
Find the maximum path sum in a binary tree.
- A path can start and end at any nodes (not necessarily the root).
- Each node can be used at most once.

------------------------------------------------------
Optimal Approach (DFS with Global Max):
1. Use post-order DFS to compute the maximum path sum for each node.
2. For each node:
   - Recursively find the max sum from its left and right subtrees.
   - If a subtree contributes a negative sum, ignore it (use max(0, ...)).
   - Update global `maxSum` as:
         maxSum = max(maxSum, left + right + node->val)
     (this considers the best path that passes through the current node).
   - Return to parent the best downward path:
         node->val + max(left, right)
     (only one side is chosen to continue upward).

- Time Complexity:  O(n)  
  Visit each node once.
- Space Complexity: O(h)  
  h = height of tree (recursion stack).

------------------------------------------------------
*/

#include <iostream>
#include <algorithm>
#include <climits>
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
    int pathSum(TreeNode* root, int &maxSum) {
        if (root == nullptr) return 0;

        // Only consider positive contributions
        int left  = max(0, pathSum(root->left,  maxSum));
        int right = max(0, pathSum(root->right, maxSum));

        // Update global maximum: path through current node
        maxSum = max(maxSum, left + right + root->val);

        // Return max one-side path to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        pathSum(root, maxSum);
        return maxSum;
    }
};
