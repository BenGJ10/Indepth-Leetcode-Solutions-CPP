/*
1448. Count Good Nodes in Binary Tree
Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/

------------------------------------------------------
Problem Summary:
A node X in a binary tree is called *good* if the path from the root to X 
does not contain a node with a value greater than X.  
Return the total number of good nodes.

------------------------------------------------------
Optimal Approach (DFS with Max-So-Far):
1. Perform a DFS starting from the root.
2. Carry along the maximum value (`maxElem`) encountered so far on the path.
3. At each node:
   - If `node->val >= maxElem`, it is a good node. Increment count.
   - Update `maxElem` as max(maxElem, node->val) for children calls.
4. Sum counts from left and right subtrees.

- Time Complexity:  O(n)  
  Each node is visited exactly once.
- Space Complexity: O(h)  
  h = height of the tree (recursion stack).

------------------------------------------------------
*/

#include <iostream>
#include <climits>
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
    int findGoodNodes(TreeNode* root, int maxElem) {
        if (root == nullptr) return 0;

        int count = 0;
        if (root->val >= maxElem) {
            count++;
            maxElem = root->val;
        }

        count += findGoodNodes(root->left,  maxElem);
        count += findGoodNodes(root->right, maxElem);
        return count;
    }

    int goodNodes(TreeNode* root) {
        return findGoodNodes(root, INT_MIN);
    }
};
