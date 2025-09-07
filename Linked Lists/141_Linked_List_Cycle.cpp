/*
141. Linked List Cycle
Link: https://leetcode.com/problems/linked-list-cycle/

------------------------------------------------------
Problem Summary:
Given the head of a singly linked list, determine if the linked list has a cycle.  
A cycle exists if a node can be reached again by continuously following the next pointer.

------------------------------------------------------
Brute Force Approach:
1. Use a hash set to track visited nodes.
2. Traverse the list, if a node repeats, cycle exists.
- Time Complexity: O(n)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (Floyd's Cycle Detection – Tortoise & Hare):
1. Use two pointers, `slow` (1 step at a time) and `fast` (2 steps at a time).
2. If they meet, a cycle exists.
3. If `fast` reaches `nullptr`, no cycle exists.

- Time Complexity: O(n)
- Space Complexity: O(1)

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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // move 1 step
            fast = fast->next->next;    // move 2 steps

            if (slow == fast) {         // cycle detected
                return true;
            }
        }
        return false; // no cycle
    }
};
