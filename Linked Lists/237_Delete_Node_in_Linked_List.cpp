/*
237. Delete Node in a Linked List
Link: https://leetcode.com/problems/delete-node-in-a-linked-list/

------------------------------------------------------
Problem Summary:
Write a function to delete a node (except the tail) in a singly linked list, 
given only access to that node.

Important:
- You are NOT given the head of the list.
- You cannot access the previous node.
- The node to be deleted will not be the tail node.

Intuition:
Since we don’t have access to the *previous* node, 
we can’t just do "prev->next = node->next".  
Instead:
1. Copy the value of the **next node** into the current node.
2. Delete the **next node**.
This makes the current node look like it has been removed.

Time Complexity: O(1)
Space Complexity: O(1)

------------------------------------------------------
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;
        node->val = nextNode->val;     // Copy next node's value
        node->next = nextNode->next;   // Bypass next node
        delete nextNode;               // Free memory
    }
};
