/*
2487. Remove Nodes From Linked List
Link: https://leetcode.com/problems/remove-nodes-from-linked-list/

------------------------------------------------------
Problem Summary:
Given the head of a linked list, remove every node that has a node with a **strictly greater value** somewhere to its right.  
Return the modified list’s head.

------------------------------------------------------
Brute Force Approach:
1. For each node, traverse all nodes to its right to check if a greater value exists.  
2. If such a node exists, delete the current node.  

- Time Complexity: O(n²) (for each node we scan the remainder).  
- Space Complexity: O(1).

------------------------------------------------------
Optimal Approach (Reverse & Track Maximum):
1. **Reverse the list** so we can scan from the original right to left.  
2. Maintain a variable `maxSoFar` to keep track of the greatest value seen so far.  
3. Traverse the reversed list:
   - If current node’s value < `maxSoFar`, remove it.
   - Else, update `maxSoFar` and keep it.
4. **Reverse the list again** to restore the original order.

- Time Complexity: O(n) (two reversals + single traversal).  
- Space Complexity: O(1).

------------------------------------------------------
*/

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Helper to reverse a linked list
    ListNode* reverseNodes(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while (temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        // Step 1: Reverse the list
        ListNode* newHead = reverseNodes(head);

        // Step 2: Traverse and remove nodes smaller than maxSoFar
        int maxSoFar = newHead->val;
        ListNode* prev = newHead;
        ListNode* temp = newHead->next;

        while (temp != nullptr) {
            if (temp->val < maxSoFar) {
                prev->next = temp->next; // delete node
            } else {
                maxSoFar = temp->val;
                prev = temp;
            }
            temp = temp->next;
        }

        // Step 3: Reverse again to restore order
        return reverseNodes(newHead);
    }
};
