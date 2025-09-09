/*
142. Linked List Cycle II
Link: https://leetcode.com/problems/linked-list-cycle-ii/

------------------------------------------------------
Brute Force Approach:
- Use a hash set to store visited nodes.
- If a node repeats, that is the start of the cycle.
- If traversal reaches null, there is no cycle.
- Time Complexity: O(n)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (Floyd’s Tortoise & Hare):
1. Use two pointers: `slow` and `fast`.
   - `slow` moves one step, `fast` moves two steps.
2. If they meet, a cycle exists.
3. To find the cycle's start:
   - Reset one pointer (`head`) and move both one step at a time.
   - The node where they meet again is the start of the cycle.

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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) break;
        }

        // No cycle
        if (fast == nullptr || fast->next == nullptr) return nullptr;

        // Step 2: Find cycle start
        while (slow != head) {
            head = head->next;
            slow = slow->next;
        }

        return head; // start of cycle
    }
};

