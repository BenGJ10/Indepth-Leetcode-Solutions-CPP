/*
19. Remove Nth Node From End of List
Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

------------------------------------------------------
Problem Summary:
Given the head of a linked list, remove the nth node from the end of the list and return its head.

------------------------------------------------------
Brute Force Approach:
1. Traverse the linked list to calculate its length (say `len`).
2. The node to remove is at position `(len - n)` from the start.
3. Traverse again to that node, adjust pointers, and delete it.
- Time Complexity: O(n + n) = O(n)
- Space Complexity: O(1)

------------------------------------------------------
Optimal Approach (Two Pointers):
1. Use two pointers `fast` and `slow` starting at head.
2. Move `fast` forward by `n` steps.
3. If `fast` becomes NULL, it means we need to remove the head → return `head->next`.
4. Otherwise, move both `fast` and `slow` until `fast->next == NULL`.
   - Now `slow` is at the node just before the one to remove.
5. Remove `slow->next` safely.

- Time Complexity: O(n) → single traversal.
- Space Complexity: O(1)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast ahead by n steps
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast is NULL, we need to remove the head
        if (fast == nullptr) return head->next;

        // Move both pointers until fast reaches the last node
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the target node
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }
};

