/*
25. Reverse Nodes in k-Group
Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

------------------------------------------------------
Problem Summary:
Given the head of a linked list, reverse the nodes of the list **k** at a time and return its modified list.  
If the number of nodes is not a multiple of k, the remaining nodes at the end should stay in the same order.

------------------------------------------------------
Brute Force Approach:
1. For each group of size k:
   - Push nodes' values into a stack.
   - Pop from the stack to rewrite node values in reverse.
2. Continue until fewer than k nodes remain.

- Time Complexity: O(n)  
- Space Complexity: O(k) for the stack

------------------------------------------------------
Optimal Approach (In-place Reversal):
1. Use helper functions:
   - `findKthNode(head, k)`: returns the k-th node from current position or nullptr if fewer than k remain.
   - `reverseNodes(head)`: reverses a linked list segment and returns its new head.
2. Traverse the list:
   - For each k-group, find its k-th node.
   - Temporarily disconnect after the k-th node.
   - Reverse the k nodes.
   - Connect the previous part to the new head of this reversed group.
   - Move to the next segment.
3. If fewer than k nodes remain, link the rest as-is.

- Time Complexity: O(n)  (each node is visited and reversed once)  
- Space Complexity: O(1)  (in-place reversal)

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
    // Reverse an entire linked list segment
    ListNode* reverseNodes(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* front = head->next;
            head->next = prev;
            prev = head;
            head = front;
        }
        return prev;
    }

    // Return k-th node from current position (1-indexed)
    ListNode* findKthNode(ListNode* head, int k) {
        k -= 1;
        while (k > 0 && head != nullptr) {
            head = head->next;
            k--;
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;

        while (temp != nullptr) {
            ListNode* kthNode = findKthNode(temp, k);
            if (kthNode == nullptr) {
                if (prevNode) prevNode->next = temp; // attach remaining nodes
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = nullptr;                // detach k-group
            reverseNodes(temp);                     // reverse this group

            if (temp == head) {
                head = kthNode;                     // new head after first group
            } else {
                prevNode->next = kthNode;           // connect previous group
            }
            prevNode = temp;                        // temp is tail after reversal
            temp = nextNode;                        // move to next group
        }
        return head;
    }
};
