/*
129. Sum Root to Leaf Numbers
Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/

------------------------------------------------------
Problem Summary:
Each root-to-leaf path in a binary tree represents a number formed by 
concatenating the node values along that path.  
Return the total sum of all such numbers.

------------------------------------------------------
Optimal Approach (DFS with Running Sum):
1. Perform a DFS traversal of the tree.
2. Keep a running integer `sum` representing the number formed so far.
   - At each node: `sum = sum * 10 + node->val`.
3. When a leaf is reached, return the current `sum`.
4. Otherwise, return the sum of left and right subtree results.

- Time Complexity:  O(n)  
  Each node is visited exactly once.
- Space Complexity: O(h)  
  h = height of the tree (recursion stack).

------------------------------------------------------
*/

#include <iostream>
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
    int calculateSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;

        sum = sum * 10 + root->val;

        // If leaf, return the number formed
        if (root->left == nullptr && root->right == nullptr) return sum;

        // Sum from left and right subtrees
        return calculateSum(root->left, sum) + calculateSum(root->right, sum);
    }

    int sumNumbers(TreeNode* root) {
        return calculateSum(root, 0);
    }
};
