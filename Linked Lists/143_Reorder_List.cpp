/*
143. Reorder List
Link: https://leetcode.com/problems/reorder-list/

------------------------------------------------------
Problem Summary:
You are given the head of a singly linked list.  
Reorder the list so that the nodes are arranged as:  
    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …  

You must do this reordering in-place without altering the node values.

------------------------------------------------------
Brute Force Approach:
1. Copy all nodes into a vector for random access.
2. Use two pointers (`i=0`, `j=n-1`) to rebuild the list in required order.
3. Reconnect nodes accordingly.
- Time Complexity: O(n)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (Three Steps):
1. **Find the middle of the list**  
   - Use slow & fast pointer to reach middle.
2. **Reverse the second half**  
   - Standard linked list reversal on the middle's next.
3. **Merge the two halves**  
   - Alternately link nodes from first half and reversed second half.

- Time Complexity: O(n) → single pass for each step.
- Space Complexity: O(1) → in-place reordering.

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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* temp = slow->next;
        while (temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        slow->next = nullptr; // split the list

        // Step 3: Merge two halves
        ListNode* node1 = head;
        ListNode* node2 = prev;
        while (node2 != nullptr) {
            ListNode* temp1 = node1->next;
            ListNode* temp2 = node2->next;

            node1->next = node2;
            node2->next = temp1;

            node1 = temp1;
            node2 = temp2;
        }
    }
};

