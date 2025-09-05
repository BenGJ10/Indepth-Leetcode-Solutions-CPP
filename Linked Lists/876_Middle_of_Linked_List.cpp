/*
876. Middle of the Linked List
Link: https://leetcode.com/problems/middle-of-the-linked-list/

------------------------------------------------------
Problem Summary:
Given the head of a singly linked list, return the middle node of the linked list.  
If there are two middle nodes, return the second middle node.

Brute Force Approach:
1. Traverse the linked list to count the total number of nodes (n).
2. Traverse again to the node at index n/2 and return it.
- Time Complexity: O(n) + O(n) = O(n)
- Space Complexity: O(1)

------------------------------------------------------
Optimal Approach (Two Pointers: Slow & Fast):
- Use two pointers:
  - `slow` moves one step at a time.
  - `fast` moves two steps at a time.
- When `fast` reaches the end, `slow` will be at the middle.
- Automatically returns the second middle in case of even length.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
