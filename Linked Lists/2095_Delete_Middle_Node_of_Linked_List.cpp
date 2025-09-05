/*
2095. Delete the Middle Node of a Linked List
Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

------------------------------------------------------
Problem Summary:
Given the head of a singly linked list, delete the middle node and return the modified list.  

Rules:
- If the list has only one node, return `nullptr` (empty list).
- If the list has `n` nodes, delete the ⌊n/2⌋-th node (0-indexed).

------------------------------------------------------
Brute Force Approach:
1. Traverse the linked list to count the total number of nodes (n).
2. Traverse again until (n/2)-th node and delete it by adjusting pointers.
- Time Complexity: O(n) + O(n) = O(n)
- Space Complexity: O(1)

------------------------------------------------------
Optimal Approach (Two Pointers: Slow & Fast):
- Use two pointers:
  - `slow` moves one step at a time.
  - `fast` moves two steps at a time.
- Maintain a `prev` pointer to track the node before `slow`.
- When `fast` reaches the end, `slow` will be at the middle node.
- Delete `slow` by linking `prev->next = slow->next`.

- Time Complexity: O(n)
- Space Complexity: O(1)

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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) 
            return nullptr; // only one node, return empty list

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // delete middle node
        prev->next = slow->next;
        delete slow;

        return head;
    }
};
