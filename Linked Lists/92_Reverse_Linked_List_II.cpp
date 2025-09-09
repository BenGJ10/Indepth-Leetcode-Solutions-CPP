/*
92. Reverse Linked List II
Link: https://leetcode.com/problems/reverse-linked-list-ii/

------------------------------------------------------
Problem Summary:
Given the head of a singly linked list and two integers left and right where 1 ≤ left ≤ right ≤ n,  
reverse the nodes of the list from position left to position right, and return the modified list.

Brute Force Approach:
1. Traverse the list, copy nodes into an array.
2. Reverse the subarray from `left-1` to `right-1`.
3. Rebuild the list.
- Time Complexity: O(n)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (In-Place Reversal):
1. Use a dummy node pointing to head for easier edge cases (like reversing from the first node).
2. Traverse until the node before `left` (call it `prev`).
3. Perform in-place reversal of the sublist between `left` and `right`:
   - Iteratively take the node after `curr` and insert it right after `prev`.
4. Return `dummy->next`.

- Time Complexity: O(n) → single pass with in-place reversal.  
- Space Complexity: O(1).  

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Step 1: Reach node before left
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        // Step 2: Start reversal
        ListNode* curr = prev->next;
        ListNode* front = curr->next;

        for (int i = 0; i < right - left; i++) {
            curr->next = front->next;
            front->next = prev->next;
            prev->next = front;
            front = curr->next;
        }

        return dummy->next;
    }
};

