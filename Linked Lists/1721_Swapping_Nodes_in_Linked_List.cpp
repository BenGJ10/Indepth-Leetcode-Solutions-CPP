/*
1721. Swapping Nodes in a Linked List
Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

------------------------------------------------------

Brute Force Approach:
1. Traverse the linked list to find its length `n`.
2. Traverse again to reach:
   - The k-th node from the start.
   - The (n - k + 1)-th node from the start (i.e., k-th from the end).
3. Swap their values.
- Time Complexity: O(n) + O(n) = O(n)
- Space Complexity: O(1)

------------------------------------------------------
Optimal Approach (One Pass with Two Pointers):
1. Traverse once to get the k-th node from the start (`first`).
2. Keep a second pointer (`second`) at head.
3. Start another pointer (`curr`) from `first` and move both `curr` and `second` till `curr` reaches the end.
   - At this point, `second` will be the k-th node from the end.
4. Swap their values.

- Time Complexity: O(n) → single pass  
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 0;
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        // k-th from start
        ListNode* first = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        // k-th from end
        ListNode* second = head;
        for (int i = 1; i < (n - k + 1); i++) {
            second = second->next;
        }

        // Swap values
        swap(first->val, second->val);
        return head;
    }
};
