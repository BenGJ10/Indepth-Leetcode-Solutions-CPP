/*
206. Reverse Linked List
Link: https://leetcode.com/problems/reverse-linked-list/

------------------------------------------------------
Problem Summary:
Given the head of a singly linked list, reverse the list and return the new head.

Brute Force Approach (Using Stack or Array):
- Traverse the list and push all node values into a stack (or array).
- Recreate the linked list by popping values in reverse order.
- Time: O(n)
- Space: O(n) (extra storage used).

------------------------------------------------------
Optimal Approach (Iterative Reversal):
- Use three pointers: prev, curr (temp), and front.
Steps:
1. Initialize prev = nullptr, temp = head.
2. For each node:
   - Store the next node: `front = temp->next`.
   - Reverse the link: `temp->next = prev`.
   - Move prev and temp forward.
3. When finished, prev points to the new head.
- Time: O(n)
- Space: O(1)

Alternative (Recursive Approach):
- Base case: if head is nullptr or only one node → return head.
- Otherwise, reverse the rest recursively and fix pointers.
- Simpler to read, but uses O(n) recursion stack.

------------------------------------------------------
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp != nullptr) {
            ListNode* front = temp->next; // store next
            temp->next = prev;            // reverse pointer
            prev = temp;                  // move prev
            temp = front;                 // move curr
        }
        return prev; // new head
    }
};

